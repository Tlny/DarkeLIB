//      /cmds/mortal/_party.c
//      handles all party commands
//     created 111192 by Descartes of Borg
//     Edited by Helios 050799

#include <std.h>
#include <party.h>

inherit DAEMON;

int form(string str);
int leave();
int join_party(string str);
int add_member(string str);
int sub(string str);
int leader(string str);
int list();
int party_line(string str);
int party_lineemote(string str);
void help();

int cmd_party(string str) {
    string com, extra;

    if(wizardp(this_player()) && !archp(this_player())) return 0;
    if(!str) {
        help();
        return 1;
    }
    if(sscanf(str, "%s %s", com, extra) == 2) {
        switch(com) {
            case "form": return form(extra); break;
            case "leave": return leave(); break;
	    case "join": return join_party(extra); break;
            case "add": return add_member(extra); break;
            case "remove": return sub(extra); break;
            case "leader": return leader(extra); break;
            case "list": return list(); break;
            case "line": return party_line(extra); break;
              case "lineemote": return party_lineemote(extra); break;
            default: help(); return 1; break;
        }
    }
    else {
        if(str == "leave") return leave();
        else if(str == "list") return list();
        else {
            help();
            return 1;
        }
    }
}

int form(string str) {
    string *tmp;
    int x;

    tmp = (string *)PARTY_OB->query_parties();
    if(!tmp) tmp = ({});
    if(member_array(str, tmp) != -1) {
        notify_fail("A party by that name already exists.\n");
        return 0;
    }
    x = (int)PARTY_OB->add_member(this_player(), str);
    if(x==ALREADY_MEMBER) {
        notify_fail("You are already a member of another party.\n");
        return 0;
    }
    write("You form the party "+str+".\nYou are the leader.\n");
    return 1;
}

int leave() {
    int x;

    x = (int)PARTY_OB->remove_member(this_player());
    if(x==NOT_MEMBER) {
        notify_fail("You are not a member of any party!\n");
        return 0;
    }
    write("You leave your party.\n");
    return 1;
}

int add_member(string str) {
    object ob;
    string party;
    int x;

    ob = find_player(str);
    if(!ob) {
        notify_fail("No player by that name on the mud.\n");
        return 0;
    }
    if(wizardp(ob)) { 
        notify_fail("Immortals may not join.\n");
        return 0;
    }
    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You must be the leader of a party to add any members!\n");
        return 0;
    }
    if(this_player() != (object)PARTY_OB->query_leader(party)) {
        notify_fail("You must be the leader of your party to add any members!\n");
        return 0;
    }
    PARTY_OB->add_invited(ob, party);
    PARTY_OB->notify_party(party, (string)ob->query_cap_name()+" has been invited to join the party.");
    tell_object(ob, this_player()->query_cap_name()+" invites you to join the party \""+party+"\".\nYou have 60 seconds to type <party join "+party+">.\n");
    return 1;
}

int sub(string str) {
    object ob;
    string party;
    int i;

    ob = find_player(str);
    if(!ob) {
        notify_fail("That player is not on the mud.\n");
        return 0;
    }
    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You must be the leader of a party to remove a member.\n");
        return 0;
    }
    if(this_player() != (object)PARTY_OB->query_leader(party)) {
        notify_fail("You must be the leader of the party to remove a member.\n");
        return 0;
    }
    i = (int)PARTY_OB->remove_member(ob);
    if(i==NOT_MEMBER) {
        notify_fail(ob->query_cap_name()+" is not a member of your group.\n");
        return 0;
    }
    PARTY_OB->notify_party(party, (string)ob->query_cap_name()+" is no longer in the group.");
    return 1;
}

int leader(string str) {
    object ob;
    string party;
    int x;

    ob = find_player(str);
    if(!ob) {
        notify_fail("That player is not on line.\n");
        return 0;
    }
    if(ob == this_player()) {
        notify_fail("You are already the leader!\n");
        return 0;
    }
    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You must lead a group before you may change its leader.\n");
        return 0;
    }
    if(this_player() != (object)PARTY_OB->query_leader(party)) {
        notify_fail("You must be the leader of a group in order to change the leadership.\n");
        return 0;
    }
    if((string)ob->query_party() != party) {
        notify_fail(ob->query_cap_name()+" is not in your party!\n");
        return 0;
    }
    x = (int)PARTY_OB->change_leader(ob);
    if(x != OK) {
        notify_fail("Leadership change failed.\n");
        return 0;
    }
    write("You are no longer the leader.\n");
    PARTY_OB->notify_party(party, (string)ob->query_cap_name()+" is now the party leader.");
    return 1;
}

int filter_env(object who, object tp){
    if(environment(tp) == environment(who))
        return 1;
    else
        return 0;
}

int list() {
    object *who, *who2;
    int i, tot_exp;
    string party, tmp, *items;

    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You are not a member of any party.\n");
        return 0;
    }
    who = (object *)PARTY_OB->query_party_members(party);
    who2 = filter_array(who, "filter_env", this_object(), this_player());
    if(!sizeof(who)) {
        notify_fail("You are no longer in a party.\n");
        return 0;
    }
        items = allocate(sizeof(who));
    tot_exp = 0;
    for(i=0;i<sizeof(who);i++) {
      items[i] = sprintf("%1s %-13s (lvl:%3d) %8d exp  %%^BOLD%%^hp:%%^RESET%%^ %s%d%%^RESET%%^ (%d)  %%^BOLD%%^mp:%%^RESET%%^ %d (%d)",
           (!i)?"*":" ",
          capitalize((string)who[i]->query_name()), (int)who[i]->query_level(),
          (int)PARTY_OB->query_party_exp(who[i]), ((int)who[i]->query_hp() < (int)who[i]->query_max_hp()/5)?"%^RED%^%^BOLD%^":"",
          (int)who[i]->query_hp(),
          (int)who[i]->query_max_hp(),
          (int)who[i]->query_mp(), (int)who[i]->query_max_mp());
      tot_exp += (int)PARTY_OB->query_party_exp(who[i]);
    }
    tmp =
    "%^BOLD%^Party:%^RESET%^ %^CYAN%^%^BOLD%^"+party+"%^RESET%^ "+sprintf("(%d exp)\n", tot_exp) +
    sprintf("%%^CYAN%%^%%^BOLD%%^Current EXP bonus: %%^RESET%%^%%^BOLD%%^%d%%\n",
      (int)PARTY_OB->perc_exp_bonus(map_array(who2, (: call_other :), "query_level")))+
    "%^BOLD%^-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-%^RESET%^\n\n";
    tmp += implode(items, "\n");
    tmp += "\n%";
    this_player()->more(explode(tmp, "\n"));
    return 1;
}

int join_party(string str) {
    int x;

    if(!str) return 0;
    if(!PARTY_OB->invited_now(this_player(), str)) {
	notify_fail("You must be invited into a party in order to join.\n");
	return 0;
    }
    x = (int)PARTY_OB->add_member(this_player(), str);
    if(x==ALREADY_MEMBER) {
	notify_fail("You are already in another party!\n");
	return 0;
    }
    PARTY_OB->notify_party(str, (string)this_player()->query_cap_name()+" has joined the party.\n");
    return 1;
}

void help() {
    write("Command: party\n"+
        "Syntax: <party form [name]>\n"+
        "        <party add [player]>\n"+
	"        <party join [name]>\n"+
        "        <party remove [player]>\n"+
        "        <party leave>\n"+
        "        <party list>\n"+
        "        <party line [message]>\n"+
        "        <party leader [player]>\n\n"+
        "This command accesses the various party enabling functions.\n"+
        "The person who forms any party is automatically the leader of\n"+
        "the party.  Only that player may add or remove players.  That\n"+
        "player may also designate another player as the party leader.\n"+
        "Any party member may leave the party at any time through the\n"+
        "\"leave\" function.  A list of all current party members is\n"+
        "given by the \"list\" function.  Experience is awareded based\n"+
	"on the individual's level with respect to the rest of the party.\n"+
	"Once you have been invited to join the party, you must type\n"+
 "<party join [name]> (where name is the name of the party).\n"
 "See also: follow, kill\n"
  );
}

int party_line(string str) {
    string party, pl_name;

    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You are not a member of a party.\n");
        return 0;
    }
    pl_name = capitalize((string)this_player()->query_name());
    PARTY_OB->party_line(party, str, pl_name);
    return 1;
}

int party_lineemote(string str) {
    string party, pl_name;

    party = (string)this_player()->query_party();
    if(!party) {
        notify_fail("You are not a member of a party.\n");
        return 0;
    }
    pl_name = capitalize((string)this_player()->query_name());
    PARTY_OB->party_lineemote(party, str, pl_name);
    return 1;
}
