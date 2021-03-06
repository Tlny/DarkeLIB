//Town square,  created by Excelsior.  New Faeriedust
// found at/d/nfd/rooms/square

inherit "std/room";

void reset() {
   ::reset();
	if(!present("mother"))
   new("/d/nfd/mon/mother")->move(this_object());
   remove_item("mothers");
   add_item("mothers","One of the mothers seems to be trying to get your attention.");
}

void init() {
   ::init() ;
   if (!present("mother")) {
      remove_item("mothers");
      add_item("mothers", "Right now, not one of the mothers is "+
         "paying attention to you.  Try again later.");
   }
   else
      {
      remove_item("mothers");
      add_item("mothers","One of the mothers seems to be trying "+
         "to get your attention.");
   }
}

void create() {
   ::create();
   set_property("indoors",0);
   set_property("light",1);
   set("short","Town square");
   set("long", "This is the sad, dirty town square of New Faerie Dust. "+
      "It is no longer much of a square.  Squatters have set up camp "+
      "here,  and turned it into more of a lopsided pentagon. Such "+
      "is New Faerie Dust,  a over populated pool of disease and "+
      "filth.  Many mothers are here caring for their many children, "+
      "while the fathers are off working as virtual slaves.  That is, "+
      "the ones that work. To your north is the fabled Excelsior Emporium. Take a look inside.");
   set_items( ([ "square": "It's no longer much of a square.",
	"children":"Many of them look undernourished and in poor health.",
            "squatters":"They are all over the place.", "mothers":"One of the "+
            "mothers seems to be trying to get your attention.","fathers":
            "They are at work, dummy!  There is nothing to look at!" ]) );
   set_exits( (["northeast" : "/d/nfd/rooms/faeriedust",
"north":"/d/nfd/rooms/emporium/foyer",
            "east":"/d/nfd/rooms/inter1","west":
            "/d/nfd/rooms/street1","northwest": 
            "/d/nfd/rooms/street2" ]) );
}
