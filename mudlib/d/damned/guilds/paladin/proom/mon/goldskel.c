/* Monster coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit MONSTER;

 

void create() {
   object ob;
   ::create();



   set_name("gold skeleton");
   set("id", ({"skeleton", "gold skeleton"}) );
   set_level(18);
   set("short", "[18]gold skeleton");
   set("long",
   "Before you stands a human skeleton whose bones appear to be coated "
   "with gold.  Its metal frame shines in the faint torchlight.  The "
   "monster has large golden fangs that look rather sharp!"
   );
   set("race", "undead");
   set_gender("neuter");
   //set_skill("back stab", 50);
    
    set("aggressive", (: call_other, this_object(), "no_other_monsters" :));
    set("gang bang", 1);

   set_money("silver", random(500)+500);
   set_body_type("human");
/*
   set_emotes(5, ({
                   "The gold skeleton turns its head and stares at you.",
                   "The gold skeleton's jaw slowly opens and closes.",
                   }), 0);
   set_achats(30, ({
               "Sparks fly as the gold skeleton thrashes about.",
               "The gold skeleton lunges toward its attacker.",
               "The gold skeleton thrashes about very violently.",
                    }) );
*/
   //ob = new(WEAP_PATH+"bonedggr");
   //ob->move(this_object());
   //ob->add_poisoning(50);
   //force_me("wield dagger in right hand");
}
 
void catch_tell(string str) {
   string a;
   object ob1;
   if(sscanf(str, "%s enters.", a) == 1) {
      a = lower_case(a);
      ob1 = present(a, environment(this_object()));
      if(ob1) 
         if (random(10) == 0)
            force_me("use back stab at " + a); 
   }
}


void init()
{
    ::init();
    add_action("no","west");
    add_action("no","east");
}

int no()
{
   if(archp(this_player())) return 0;
   if(this_player()->query_ghost()) return 0;
    message("blocking",
      "The skeleton jumps in front of you blocking your path.\n",
      this_player());
    message("blocking",
      "The skeleton blocks "+capitalize(this_player()->query_name())+"'s path.\n",
      all_inventory(this_object()),
      this_player());
    return 1;
}

int no_other_monsters(object who) {
  if(who->is_player()) {
    if(who->query_invis()) { return 0; }
    if(who->query_hiding() >= 70)  { return 0; }
    if(who->query_stealth() >= 80) { return 0; }
   this_object()->kill_ob(who,0);
    return 1;
  }
  else return 0;
}
 
