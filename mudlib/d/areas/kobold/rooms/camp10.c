/* Room coded by Duridian for DarkeMud. */
 
#include "std.h"
inherit ROOM;
 
void create() {
   ::create();
   set_property("light", 3);
   set_property("indoors", 0);
   set("short", "Kobold Campgrounds");
   set("day long",
   "Dozens and dozens of small tents lie before you, which house the "
   "many kobold families that inhabit these hills.  Children run from "
   "place to place, and an occasional guard brushes past you, no doubt "
   "on urgent business.  Heavy foliage prevents you from going in any "
   "direction but west.  Looking at your feet, you realize that you have "
   "stepped into some deep mud."
   );
   set("night long",
   "In the faint moonlight you are able to see the dozens and dozens of "
   "small tents that house the many kobold families that inhabit these "
   "hills.  Children sometimes run past you, no doubt on their way home "
   "to eat dinner.  Guards pass by once in a while, checking for invaders "
   "and ensuring that all is in order.  Heavy foliage prevents you from "
   "going in any direction but west."
   );
   set_smell("default", "The scent of cooking flesh fills your nostrils.");
   set_listen("default", "You hear children laughing nearby.");
   set_items( ([
                "tents":
     "There are dozens of tents that provide shelter for the kobold families.",
                ({"children", "kids"}):
     "Little kobold children run from place to place.",
                ({"guards", "guard"}):
     "Kobold guards ensure the peace here at the kobold campgrounds.",
                "hills":
     "The kobolds call these hills home.",
                "mud":
     "The mud is all over your shoes!",
                ]) );
   set_exits( ([
                "west": PATH+"camp04",
                ]) );
}
 
void reset() {
   if(!present("kobold woman"))
      new(MON_PATH+"woman")->move(this_object());
      new(MON_PATH+"woman")->move(this_object());
   if(!present("kobold boy"))
      new(MON_PATH+"boy")->move(this_object());
      new(MON_PATH+"boy")->move(this_object());
      new(MON_PATH+"boy")->move(this_object());
   if(!present("kobold girl"))
      new(MON_PATH+"girl")->move(this_object());
      new(MON_PATH+"girl")->move(this_object());
      new(MON_PATH+"girl")->move(this_object());
}
