//      Wizard:  Myrddin
//      village_97.c
//      June 97

#include "../defs.h"

inherit "std/room";

void reset(){
  ::reset();
  if(!present("insectoid_g02")) {
         new(HIV_MON+"insectoid_g02")->move(this_object());
         new(HIV_MON+"insectoid_g02")->move(this_object());
         new(HIV_MON+"insectoid_g02")->move(this_object());
  }  
}  

void create() {
    ::create();
    set_property("indoors", 0);
    set_property("light", 2);
    set("short", "Hill Top");
    set("long",
	"You have reached the top of the hill.  The view is quite "
              "impressive, though not as good as you had hoped.  You "
              "can see the village from here, but not all that clearly.  You "
              "also find yourself surrounded by the insectoids.  You can "
              "see them moving through the rocks and underbrush all "
              "around you.  You do note with worry, however, that they "
              "cant remain here for long, and the village might make a "
              "ready source of food for them.\n" );
    set("night long",
             "In the dark, one part of the hill looks much like another.  "
             "Shadows broken by jutting rocks, blending with thick "
             "brush, and the rustle of nearby insectoids.  You must, "
             "however, be higher up on the hill since you can see a glow "
             "over the forest, marking the position of the village.\n");
    set_smell("default", "The forest smells fresh and clean.");
    set_listen("default", "You hear subtle scratchings and quiet "
              "movement coming from all over the hill.  The sounds of "
              "normal wildlife are noticeably absent.");
    set_items(([
     ({ "forest" }) :
        "At this height, you can look out over the forest.  It waves in the "
        "wind like a sea of green.  In the distance, you can make out the "
        "position of the village, easily marked by the smoke rising "
        "above it.",
     ({ "village" }) :
        "You can't see it clearly at this distance, it is all you can do to "
        "locate its position.",
     ({ "glow" }) :
        "It is coming from the villages bonfire.  You can't see it clearly "
        "at all at this distance, and in the dark, but the fire clearly "
        "marks its position.",
     ({ "trees" }) :
        "Their are still trees desperately trying to grow on the hill.  "
        "They look small and scrawny compared to their brethren on "
        "the fertile soil below the hill.",
    ({ "rock", "rocks" }) :
        "They are all over the hill, and come in various sizes.  Some "
        "seem small enough to throw, others could easily be used as "
        "material for building a castle.",
     ({ "hill" }) :
        "The hill rises above the rest of the forest like an island in an "
        "ocean.  It would be interesting to learn how this hill came to be "
        "when there are no others in the area.  It certainly would make "
        "an ideal defensive point for the entire region.",
     ({ "groundcover", "undergrowth"  }) :
        "There is still a lot of brush growing on the hill, as it is better "
        "able to adapt to the thin soil of the hillside.  It, with the "
        "pervasive rocks, tends to block your view of the surrounding "
        "terrain.",
]));
    set_exits((["west":HIV_ROOMS+"village_96.c",
                     "east":HIV_ROOMS+"village_98.c",
                     "south":HIV_ROOMS+"village_94.c",
                     "northeast":HIV_ROOMS+"village_92.c",
                     "southeast":HIV_ROOMS+"village_87.c",
                     "northwest":HIV_ROOMS+"village_93.c",
                     "southwest":HIV_ROOMS+"village_86.c",
                     "north":HIV_ROOMS+"village_99.c"])); 
}
