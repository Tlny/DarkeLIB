#include <move.h>
#include <std.h>

inherit "/std/armour";
inherit AUTOLOAD;
  
void create() {
    ::create();
    set("id", ({ "cross", "necklace" }));
    set_name("cross");
    set("short", "The Cross of the Clerics");
    set("long",
"This is an ornate cross necklace worn for protection against evil.");
    set_limbs(({"head", "torso"}));
    set_weight(25);
    set_ac(75);
    set_ac(60, "disruption");
    set_wear((: call_other,this_object(), "make_me_gm" :));
    set_enh_critical(-3);
    set_value(50);
   return;
}

int query_always_keep() { return 1; }

int make_me_gm() {
object ob;

   if(this_player()->is_player() && (int)this_player()->query_level() < 16) {
     write("%^BOLD%^Only Clerics of level 16 or higher may use this item.");
    return 0;
}

   if((string)this_player()->query_class() != "cleric") {
      write("%^BOLD%^Only Clerics may use this item.");
    return 0;
  }


  seteuid(getuid());
  ob= new("d/damned/guilds/cleric/cleric_obj");
  ob->make_me_master(this_player());
  return 1;
}
