#include <move.h>
#include <std.h>

inherit "/std/armour";
inherit AUTOLOAD;
  
create() {
    ::create();
    set("id", ({ "plate", "breastplate" }));
    set("short", "The Divine Breastplate of Light");
    set("long",
"This is a radiant, white breastplate that gives off an aura of power. "
"The paladin who wears this is named Guildmaster of the Paladins.");
    set_limbs(({"torso"}));
   set_weight(400);
    set_ac(40);
    set_wear((: call_other,this_object(), "make_me_gm" :));
    set_ac(50, "disruption");
    set_enh_critical(-1);
    set_value(100000);
   return;
}

int query_always_keep() { return 1; }
int make_me_gm() {
object ob;

   if(this_player()->is_player() && (int)this_player()->query_level() < 16) {
     write("%^BOLD%^Only Paladins of level 16 or higher may use this item.");
    return 0;
}

   if((string)this_player()->query_class() != "paladin") {
      write("%^BOLD%^Only Paladins may use this item.");
    return 0;
  }

  seteuid(getuid());
  ob= new("d/damned/guilds/paladin/paladin_obj");
  ob->make_me_master(this_player());
  return 1;
}


