#include "/adm/include/std.h"

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 1);
	set("short", "A secret passage");
	set("long", "A deeper secret passage in the goblin settlement, there seems something strange with the room, maybe in the walls or floor.");
	add_exit("room1", "up");
	add_exit("cave4", "east");
	add_exit("grom", "north");
	add_exit("room3", "down");
	add_invis_exit("down");
	set_items( ([ "floor" : "The floor seems somehow magically enchanted, it almost feels like you can go down.",
])
);
	add_exit("goblin3", "south");

new("/wizards/blial/monsters/pinkrabbit.c")->move(this_object());
}

