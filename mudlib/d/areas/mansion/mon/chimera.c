// chimera

#include "mansion.h"
inherit MONSTER;

void create() {
   string var;
   ::create();
    set_money("gold", 1+random(16));
   set_name("a chimera");
   set("id", ({"chimera"}) );
   set_level(16);
   set("short", "[16]animated stuffed chimera");
   set("long",
   "You see a large stuffed chimera that seems to have broken "+
   "free from it's display somehow.  It doesn't look very happy "+
   "about being brought back to life."
   );
   set("race", "chimera");
   set_gender("male");
   set_body_type("quadruped");
   set("aggressive", 1);
}
