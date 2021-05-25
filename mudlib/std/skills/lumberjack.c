//TLNY2020 fully remade
#include "/adm/include/clock.h"

#define WOOD ({  "abachi", "aspen", "birch", "buckeye", \
"coachwood", "dogwood", "elm", "gum", "ironwood", \
"limba", "mahogany", "maple", "oak", "walnut", "willow", "pine" \
 })


inherit "/std/skills/skill.c";

string type;

void create() {
    ::create();
    set_stat("strength");
    set_dev_cost(10);
    set_fast_dev_cost(27);
    set_property("no target", 1);
}

void info() {
message("help",
"This skill is used to obtain wood from trees (natch).  It must be used "
"in the forest, and you must be wielding some sort of axe or polearm.  "
"Yes, you can chop down a tree with a halberd if that's all you have.\n"
"Usage: use lumberjack at <wood type>\n\n"
"see help wood for different types of wood. It is highly advised that you get the prospecting skill as well to find wood out in the wild.",
	this_player());
}


void skill_func(object from, object at, string arg) {
  object *weap;
  int i, flag;



 if(!arg) {
    message("info", "You must use this skill at a wood type. Example: use lumberjack at pine", from);
    remove();
    return;
  }


 arg = lower_case(arg);
if(member_array(arg, WOOD) >= 0) {


  if((time() - (int)from->query_last_use("lumberjack")) / MINUTE < 1)
    {
    message("info", "You may only use this skill once every 1 mud minutes.", from);
    remove();
    return;
  }

  if(!environment(from)->query_terrain() ||
    lower_case((string)(environment(from)->query_terrain())) != "f") {
    message("info", "You must use this skill in the forest.", from);
    remove();
    return;
  }
/*
  i = sizeof(weap = (object *)from->query_wielded());
  flag = 0;
  while(i--) if((string)weap[i]->query_type() == "axe" ||
      (string)weap[i]->query_type() == "two handed polearm") flag = 1;
  if(!flag) {
    message("info", "You must wield an axe or polearm to use this skill.", from);
    remove();
    return;
  }
*/
  from->set_last_use("lumberjack");
  message("info", "%^CYAN%^%^BOLD%^You start chopping.", from);
  message("info", "%^CYAN%^"+(string)from->query_cap_name() +
      " starts chopping down a tree.", environment(from),
      ({ from }));
  call_out("chop_down", 15, from, environment(from));
type = sprintf("%s", arg);
  return;
}
if(!member_array(arg, WOOD) >= 0) {
    message("info", "You must use this skill at a specific wood type see help wood", from);
    remove();
   return;
}

}


void chop_down(object from, object env) {
  int z, chance, num;
  object ob;

  
  if(env != environment(from)) {
    message("info", "You have moved while attempting to cut down a tree.  "+
          "Your skill fails.", from);
    remove();
    return;
  }
  message("info", "%^CYAN%^"+(string)from->query_cap_name() +
      " finishes chopping down a tree.", from);
  if(random(100) >= props["skill level"]) {
    message("info", "The tree you chop down fails to yield any weapon-quality wood.", from);
from->add_exp2(5 * props["skill level"]+(this_player()->query_level()*100));
    remove(); 
    return;
  }

  //ADD
  env = environment(from);
  z = sizeof(WOOD); 
  while(z--) {
  num = 0;
   chance = (int)env->query_mineral(type);
   while(chance - 100 > 0) {
        if(random(100) < 70) num++;
        chance -= 100;
      }
        if(random(100) < chance) { 
        num = 1;
        }
    if(num == 0) {
    message("info", "You search and search and are not able to find a sutable tree of "+type, from);
from->add_exp2(5 * props["skill level"]);
    remove();

    return;
    }
      //room->add_mineral(WOOD[z], num); 
  //END 
  message("info", "You select a board of "+type+" which will fashion a fine weapon.", from);
  seteuid(getuid());
  ob = new("/wizards/excelsior/tinker/board");
  ob->set_wood(props["skill level"]/10);
  ob->move(from);
  if(random(100) < (props["skill level"] / 12 + 1))
    message("info", "Upon inspection, you see that this board is cut "
      "from a rare "+type+" tree.", from);
  ob->set_material("wood/"+type);
from->add_exp2(25 * props["skill level"]+(this_player()->query_level()*100));
  return;
  }
}

          

