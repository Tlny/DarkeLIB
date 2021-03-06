#include <std.h>
#include "../walled_city.h"
inherit MONSTER;

create() {
int zlevel,xskill,roll,xchange,xname;

        ::create();
        set_name("woman");
        set_id(({"woman", "women", "female", "dwarf woman", "dwarf"}));
        set_gender("female");
	    roll=random(10);
        switch(roll){
        case 0:zlevel=8;break;
        case 1:zlevel=9;break;
        case 2:zlevel=10;break;
        case 3:zlevel=11;break;
        case 4:zlevel=12;break;
        case 5:zlevel=13;break;
        case 6:zlevel=14;break;
        case 7:zlevel=15;break;
        case 8:zlevel=16;break;
        case 9:zlevel=17;break;
}

	
	xname=random(6);
	switch(xname) {
	case 0:xname="["+zlevel+"]female dwarf";break;
	case 1:xname="["+zlevel+"]woman dwarf";break;
	case 2:xname="["+zlevel+"]forest dwarf";break;
	case 3:xname="["+zlevel+"]camp dwarf";break;
	case 4:xname="["+zlevel+"]protective woman dwarf";break;
	case 5:xname="["+zlevel+"]wondering dwarf";break;
	
}
	set_short(xname);
	set_long("One of the many dwarves that inhabit the walled city. She has gnarled hair and looks to be unwashed. The smell is disgusting! She looks to be carrying a package she may have picked up at the general store.");
	set_body_type("dwarf");
        set("race", "dwarf");
	add_money("silver", random(150)+150);
	add_money("gold", random(5)+10);
	set_level(zlevel);
        xskill=13*zlevel;
        set_skill("dodge", xskill);
        set_skill("melee", xskill);
        set_skill("attack", xskill);

	set_languages( ({"common"}) );
	force_me("speak common");

	set_property("handedness", "right hand");
	set_skill("blunt", xskill);
	new(WEAP+"stick.c")->move(this_object());
	force_me("wield stick in right hand");
        new(OBJ+"rations.c")->move(this_object());
//	set_achats(30,
//	({
//	"The woman screams 'Guards help me! I'm being attacked!'",
//	}) );

}

void catch_tell(string str) {
   string a, b, c;
   object ob1;
   if(sscanf(str, "%s attacks %s", c, b) == 2) {
      a = lower_case(c);
	b = lower_case(b);
      ob1 = present(a, environment(this_object()));
      if(ob1) {
         if(interact("woman", b)) {
           tell_room(environment(this_object()),
             "Dwarf woman shouts, 'Guards! Guards! Help me, I am being attacked!  "+
             "'Guards, kill "+c+"!\n",
               ({ this_object() }));
            force_me("kill "+a);
            return;
			}
		}
	}
}
