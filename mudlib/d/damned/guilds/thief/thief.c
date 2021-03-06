//Maxwell's Underground mudlib
//Thief Guild

#include <std.h>
#include <under.h>
inherit ROOM;

void create() {
  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set("short", "You are standing on a cold steel ladder.\n");
  set("long", "You are standing on a cold steel ladder. Thick clouds of "
      "mist and steam rise from below you, blocking your view of "
      "what is further down the ladder.\n"
      "Above you is a large steel plate, covering the entrance to the "
      "ladder.\n");
  set_exits( ({ UNTHIEF+"thief1","/d/daybreak/room/db_slum" }),
             ({ "down","up" }) );
  set_items( ([
    "walls" : "The cold stone walls are wet with running water.",
    "ladder" : "The thick rungs of the steel ladder are wet and rusty.",
    "mist" : "The thick mist rises from below you.",
    "plate" : "The large plate covers the entrance to the ladder.",
  ]) );
  set_smell("default", "You can smell something foul below you.");
  set_listen("default","The only sound you can here is the beat of your "
    "heart and the occasional footsteps of passing adventurers above you.");
}


