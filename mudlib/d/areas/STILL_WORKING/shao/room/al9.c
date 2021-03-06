#include <std.h>
#include <shao.h>

inherit ROOM;
void init(){
    ::init();
    add_action("kick_wall", "kick");
}

void create() {
    ::create();
    set_property("light", 1);
    set_property("night light", 0);
    set("short", "alley");
    set("long", "%^BOLD%^Garbage and old crates clutter "
      "the narrow alley, and make passage between the two solid "
      "stone walls to the north and south dificult.\n"
      "The alley continues west into darkness and east back to the "
      "street\n");
    add_exit("al7", "west");
add_exit("1st10", "street");

    set_smell("default", "The smell of piss and garbage is overwhelming.\n");
}
