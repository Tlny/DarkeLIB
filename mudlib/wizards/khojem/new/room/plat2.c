//      Wizard:  Khojem
//      plat2
//      plat2.c

#include <std.h>

inherit ROOM;

void reset(){
  ::reset();
  if(!present("guard") && random(2))
    new("/wizards/khojem/new/mon/elf_guard")->move(this_object());
}  

void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 0);
    set("short", "A wooded platform");
    set("long", "High-up in a tree a wooden platform is lashed together.  "+
      "Small huts are east and west from here. The forest floor is "+
      "far below."
    );
    add_exit("hut1","west");
    add_exit("hut2","east");
    add_exit("walk3","north");
    add_exit("walk2","south");
    set_items(([
     ({ "tree","trees", "woods", "branches" }) :
        "The trees are large, healthy trees filled with foliage.",
     ({ "hut", "huts" }) :
        "The small hut is made of wood and has a thatched roof.",
        "platform" : "A sturdy wooden platform is lashed into the "+
          "crotch of a nearby tree.",
     ({ "leaf","leaves" }) :
        "The leaves sway in the breeze, but still allow much light by them.",
     ({ "forest floor","floor" }) :
        "The ground is far below.  The few leaves down there would do "+
        "little to cushion your landing from a fall from here."
     ]));
    set_smell("default", "The smell of growth and decaying wood is everywhere.");
    set_listen("default", "You hear the occasional sound of birds singing.");
}
