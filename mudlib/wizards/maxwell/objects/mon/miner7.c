//           Maxwell's Underground Mud Library
//                    Dirty Dwarf Miner 


#include "/adm/include/std.h"
#include "under.h"
inherit MONSTER;
inherit UNEQP;

object money;
create() {
    ::create();
   set_name("Miner");
   set_id( ({ "Miner","dwarf","miner" }) );
   set_short("A soaking wet Miner");
   set_level(20);
   set_max_hp(2500);
   set_hp(2500);
   set("long", "This Miner is totally drenched! He looks like he jumped "
       "in a river or something.");
   set_gender("male");
   set("race", "dwarf");
   set_exp(400000);
   set_alignment(0);
   set_wielding_limbs( ({"right hand","left hand"}) );
   set_body_type("human");
   set_overall_ac(75);
    set_property("enhance criticals",-2);
   set_emotes(5,
     ({ "The Miner wipes his hands on his pants.",
     "The Miner mutters under his breath.",
     "The Miner wrings his belonging out",}),0 );
    set_achats(50,
    ({ "The Miner slips and loses his balance.",
     "The Miner grunts.",
     "The Miner smiles wickedly.",}) );
// Spell Code
    set_combat_chance(80);
    add_spell("heal","$(ME)"); 
    set_spell_level("heal",6);
    add_spell("harm","$A");
    set_spell_level("harm",3);
//    add_spell("internal flame","$A");
//    set_spell_level("internal flame",2); 
// Skills For Spells and Combat
    add_skill("conjuration",95);
    add_skill("prayer",95);
    set_skill("resist stun",115);
    set_skill("two handed blunt",115);
    set_skill("two handed polearm",115);
    set_skill("two handed flail",115);
    set_skill("two handed blade",115);
    set_skill("parry",115);
    set_skill("defense",115);
    set_skill("dodge",120);  
// Money Code
    money=new("std/obj/coins");
    money->set_money("gold",(random(50)+200));
    money->move(this_object());
//Equipment Code
    mob = this_object();
    wield_hand = "left hand";
//Misc
    set_moving(1); 
    set_speed(60);	 
    set("aggressive",(: call_other,this_object(), "no_other_monsters" :) );
}
int no_other_monsters(object who) {
  if(who->is_player() || who->is_pet()) return 1;
    else return 0;
}
void die(object who) {
int current;
 if(query_property("master_room") != 0){
  current = ( (query_property("master_room"))->query_property("dead"));
  (query_property("master_room"))->set_property("dead",(current+1));
 }
  ::die(who);
  return;

}




