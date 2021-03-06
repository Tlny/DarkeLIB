#include <std.h>

inherit WEAPON;
inherit AUTOLOAD;

create() {
    ::create();
    set_ac(30);
    set_name("staff");
    set("id", ({ "staff", "Robed Staff", "Staff", "robed staff" }));
set("short", "The Lifeless Robed Staff");
set("long", "As though this Staff pears to be like one you never seen before, you hear the screams of undead soldiers from the relm.  It appears to be glowing, the glow of darkness.");
    set_type("two handed staff");
    set_quality(6);
    set_property("no add quality",1);
    set_property("no decay", 1);
    set_wc(15,"crushing");
    set_wc(27, "impact");
    set_verb("smash");
    set_parry_bonus(-10);
    set_property("hit bonus", 15);
    set_wield( (: call_other, this_object(), "make_me_gm" :) ); 
    set_property("hit bonus", 25);
    set_property("enchantment",27);
    set_enh_critical(1);
    set_material("metal/mithril");
    set_weight(45);
    set_value(982);
    return;
}

int query_always_keep() { return 1; }
int query_poisoning() { return 35; }

int make_me_gm() {
  object ob;

   if(this_player()->is_player() && (int)this_player()->query_level() < 16) {
     write("%^BOLD%^Only nethermancers of level 16 or higher may use this item.");
    return 0;
}

   if((string)this_player()->query_class() != "nethermancer") {
      write("%^BOLD%^Only nethermancers may use this item.");
    return 0;
  }

  //  the function below will handle all necessary checking, etc.
  seteuid(getuid());
  ob = new("/d/damned/guilds/nethermancer/nethermancer_obj");
  ob->make_me_master(this_player());
  return 1;
}
