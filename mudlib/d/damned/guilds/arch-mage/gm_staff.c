
#include <std.h>

inherit "/std/weapon";
inherit AUTOLOAD;

create() {
    ::create();
    set_ac(10);
    set("id", ({ "sceptre", "guildmaster sceptre", "staff" }));
    set_name("sceptre");
    set("short", "The Sceptre of Dranaxar");
    set("long", "This is a long and slender sceptre inscribed with many arcane runes"
	" and glows with an inner fire.  Who knows what powers"
	" can unlocked with a simple invocation.  This sceptre "
	"was made by Dranaxar, the first arch-mage and possibly "
	"contains some of his power.\n ");
	
    set_type("two handed staff");
    set_quality(5);
    set_property("no decay",1);
    set_property("no add quality",1);
    set_wc(20, "crushing");
    set_wc(20, "impact");
    set_verb("bludgeon");
    set_parry_bonus(15);
    set_property("enchantment",15);
    set_material("metal/mcgrail");
    set_wield( (: call_other, this_object(), "gm_item" :) );
    set_enh_critical(1);
    set_weight(100);
    set_value(200000);
    return;
}



int query_always_keep() { return 1; }


int gm_item() {
object ob;


   if(this_player()->is_player() && (int)this_player()->query_level() < 16) {
     write("%^BOLD%^Only arch-mages of level 16 or higher may use this item.");
    return 0;
}

   if((string)this_player()->query_class() != "arch-mage") {
      write("%^BOLD%^Only arch-mages may use this item.");
    return 0;
  }


  seteuid(getuid());
  ob= new("d/damned/guilds/arch-mage/arch-mage_obj");
  ob->make_me_master(this_player());
  return 1;
}
