#include <std.h>

inherit ROOM;

void create() {
	::create();
	set_property("indoors", 2);
	set_property("light", 3);
	set_short("Crystal Garden");
	set_long("This is perhaps one of the most beautiful sights that you have ever seen in your life.  Crystals of every color and shade populate the area with their irrdescent glow and faceted suface, they create a magnificent light show.");
	set_items(([
	"color" : "The colors seem to point in a western direction.",
	"crystal" : "These crystals are beautiful yet amazingly strong.",
	"light" : "The lights illuminate the cavern with its beauty.",
	]));
	set_listen("default", "You can hear the melodic sounds of wind passing through the varied crystals.");
	set_smell("default", "The air smells sweet.");
	set_exits( ({
	"/wizards/blial/under/rooms/i_4.c",
	"/wizards/blial/under/rooms/j_3.c",
	"/wizards/blial/under/rooms/j_4.c",
	}),({
	"north", "east", "south",
	}));
	add_exit("h_3", "west");
	add_invis_exit("west");
}


