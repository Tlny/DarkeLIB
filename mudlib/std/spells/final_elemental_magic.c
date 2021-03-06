inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "final elemental magic");
    set_property("skill", "elemental magic");
    set_property("casting time", 100);
    set_property("dev cost", 5280);
    set_property("fast dev cost", 16250);
    set_property("spell level", 60);
    set_property("moon", "warzau");
    set_property("caster message", "%^B_RED%^%^BOLD%^%^BLACK%^You call forth the sacred elemental apocalypse!%^RESET%^");
    set_property("target message", "");
    set_property("observer message", "%^B_RED%^%^BOLD%^%^BLACK%^$C calls forth the sacred elemental apocalypse.%^RESET%^");
    set_property("damage multiplier", this_player()->query_level() );
    set_property("spell type", ({ "area damage", "area damage", "area damage", "area damage", "area damage", "area damage" }));
    set_property("must be present", 1);
    set_property("no target", 1);
    return;
}

void info() {
    message("help", "Energy mass units required for spell: 5000\n\nThis is the most powerful offensive spell available to a player. It draws pure elemental energy from the largest and most powerful of energy masses to launch a successive wrath of six extreme elemental bursts, inflicting tremendously lethal elemental damage upon ALL targets present in a room while avoiding the caster's energy mass. To cast this truly devastating magic however, a highly power bonused ultimate level mass is required, and the casting time is excessively high. This spell requires energy units drawn from a mass to cast, not mp. The element(s) this spell will contain is determined by the element(s) present in the mass. When casting this spell, no target need be supplied.\n\nSyntax: 'cast *6 final elemental magic'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {
    object *inv;
    object obmass;
    mapping dmg;
    string lorename1, lorename2, lorename3, lorename4;
    int loreskill1, loreskill2, loreskill3, loreskill4;
    int i;

    inv = all_inventory(environment(caster));

    inv = filter_array(inv, "filter_fun");
    for(i = 0;i < (sizeof(inv));i++) {
	if(inv[i]->query_property("owner name") == (string)caster->query_name()) {
	    if(inv[i]->query_property("energy units") >= 5000) {
		inv[i]->set_property("energy units", ((inv[i]->query_property("energy units")) - 5000));
		lorename1 = (string)inv[i]->query_property("lore name");
		loreskill1 = (int)inv[i]->query_property("lore power");
		lorename2 = (string)inv[i]->query_property("lore name two");
		loreskill2 = (int)inv[i]->query_property("lore power two");
		lorename3 = (string)inv[i]->query_property("lore name three");
		loreskill3 = (int)inv[i]->query_property("lore power three");
		lorename4 = (string)inv[i]->query_property("lore name four");
		loreskill4 = (int)inv[i]->query_property("lore power four");
		if(loreskill1 > 300) {
		    loreskill1 = 200;
		    loreskill1 = 300;
		}
		if(loreskill2 > 300) {
		    loreskill2 = 300;
		}
		if(loreskill3 > 300) {
		    loreskill3 = 300;
		}
		if(loreskill4 > 300) {
		    loreskill4 = 300;
		}
		if(inv[i]->query_property("lore name")) {
		    dmg = ([ ""+lorename1+"" : loreskill1/2 ]);
		    set_property("damage types", ([ ""+lorename1+"" : loreskill1/2 ]));
		    if(inv[i]->query_property("lore name two") != 0) {
			dmg = ([ ""+lorename1+"" : loreskill1/2, ""+lorename2+"" : loreskill2/2 ]);
			set_property("damage types", ([ ""+lorename1+"" : loreskill1/2, ""+lorename2+"" : loreskill2/2 ]));
			if(inv[i]->query_property("lore name three") != 0) {
			    dmg = ([ ""+lorename1+"" : loreskill1/2, ""+lorename2+"" : loreskill2/2, ""+lorename3+"" : loreskill3/2 ]);
			    set_property("damage types", ([ ""+lorename1+"" : loreskill1/2, ""+lorename2+"" : loreskill2/2, ""+lorename3+"" : loreskill3/2 ]));
			    if(inv[i]->query_property("lore name four") != 0) {
				dmg = ([ ""+lorename1+"" : loreskill1/2, ""+lorename2+"" : loreskill2/2, ""+lorename3+"" : loreskill3/2, ""+lorename4+"" : loreskill4/2 ]);
				set_property("damage types", ([ ""+lorename1+"" : loreskill1/2, ""+lorename2+"" : loreskill2/2, ""+lorename3+"" : loreskill3/2, ""+lorename4+"" : loreskill4/2 ]));
			    }
			}
		    }
		}
		message("info", "%^RED%^You expend %^RESET%^5000 %^RED%^energy units to cast the spell.%^RESET%^", caster);
		obmass = inv[i];
		obmass->move("/d/damned/arena/trashroom");
		::spell_func(caster, at, power, args, flag);
		obmass->move(environment(caster));
		obmass->force_me("use stalk at  "+ caster->query_cap_name());
		remove();
		return;
	    }
	    if(inv[i]->query_property("energy units") < 5000) {
		message("info", "There is not enough power left in your energy mass to cast this spell.", caster);
		remove();
		return;
	    }
	}
    }
    message("info", "There is no energy mass present owned by you that you can draw power from.", caster);
    remove();
    return;
}

int filter_fun(object ob) {
    if(ob->query_name() == "energy mass") return 1;
    else return 0;
}
