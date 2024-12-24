#include <std.h>
#include <dirs.h>
#include "../a1.h"
inherit MONSTER;

void create() {
int zlevel;
   object money;
   ::create();
    zlevel = (2+random(5));
   set_level(zlevel);
   set_short("["+zlevel+"]Bat");
   set_overall_ac(zlevel+8);
    set_name("bat");
    set_id( ({ "bat","bat" , "bat", "bat", "Bat"}) );
    set("long", "This bat is all black with sharp fine hairs.");
    set_gender("male");
    set("race", "bat");
    set_alignment(0);
    //set_skill("two handed polearm", 210);
    //set_skill("two handed blunt", 210);
    set_wielding_limbs( ({"right hand","left hand"}) );
    set_body_type("human");
	
	set_melee_damage( (["crushing" : zlevel, "fire" : zlevel ]) );
    set_skill("melee", 8*zlevel);
    set_skill("attack", 6*zlevel);
    set_skill("defense", 6*zlevel);
    set_skill("dodge", 6*zlevel);
	
	 set_max_hp(200);
    set_hp(200);
    set_max_mp(170);
    set_mp(170);
	
/*   
   switch(random(5)){
case 0:new(OBJ+"pick-axe.c")->move(this_object());
      force_me("wield pick in right hand and left hand");
      break;
case 1:new(OBJ+"pick.c")->move(this_object());
      force_me("wield pick in right hand and left hand");
      break;
case 2:new("/d/damned/virtual/war-hammer_6.weapon")->move(this_object());
      force_me("wield hammer in right hand and left hand");
      break;
case 3:new("/d/damned/virtual/great-axe_6.weapon")->move(this_object());
      force_me("wield axe in right hand and left hand");
      break;
case 4:new("/d/damned/virtual/battle-axe_6.weapon")->move(this_object());
      force_me("wield axe in right hand");
      break;
}
*/
    money=new("std/obj/coins");
    money->set_money("gold",(random(100)+50));
    money->move(this_object());
}
