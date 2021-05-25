inherit "/std/spells/spell";

void create() {
    ::create();
    set_property("name", "lesser mass immersion");
    set_property("skill", "elemental magic");
    set_property("casting time", 15);
    set_property("base mp cost", 25);
    set_property("dev cost", 18);
    set_property("fast dev cost", 71);
    set_property("spell level", 3);
    set_property("moon", "luna");
    set_property("caster message", "You utter a magical incantation.");
    set_property("target message", "");
    set_property("observer message", "$C utters a magical incantation.");
    set_property("spell type", ({ "protection" }));
    set_property("must be present", 1);
    set_property("self cast", 1);
    set_property("ele protection", 4);
    set_property("duration", 300);
    return;
}

void info() {
    message("help", "This spell gives an Elemental Mage the power to immerse a lesser energy mass with his body, giving him/her very slight protection against all elements and not just the one present within the mass as is the case with directly binding it. This spell is only effective is used on an energy mass owned by the caster, and is non stackable. Power of this magic affects only the duration, and the energy remaining within the mass plays no part in the final defensive values. This spell is self-cast, meaning that it will not initiate casting if the target is anything but the caster,\n\nSyntax: 'cast *6 lesser mass immersion at andora'", this_player());
}

void spell_func(object caster, object at, int power, string args, int flag) {

    object *inv;
    string lorename;
    int i;

    inv = all_inventory(environment(caster));
    inv = filter_array(inv, "filter_fun");

    for(i = 0;i < (sizeof(inv));i++) {
	if(inv[i]->query_property("owner name") == (string)caster->query_name()) {
	    if(flag) {
		message("info", "You inadvertently destroy the energy mass!", caster);
		inv[i]->remove();
		remove();
		return;
	    }
	    if((int)caster->query("mass bind") >= 1) {
		message("info", "You cannot have more than one mass joined with your body at a given time.", caster);
		caster->add_mp(props["mp cost"]);
		remove();
		return;
	    }
	    if((int)inv[i]->query_level() != 10) {
		message("info", "Your energy mass is not a lesser energy mass. You cannot immerse it using this particular spell.", caster);
		caster->add_mp(props["mp cost"]);
		remove();
		return;
	    }
	    lorename = (string)inv[i]->query_property("lore name");
	    props["protection types"] = ([ "royal" : props["ele protection"], "time" : props["ele protection"], "reflection" : props["ele protection"], "infernal" : props["ele protection"], "strike" : props["ele protection"], "stress" : props["ele protection"], "aether" : props["ele protection"], "darkness" : props["ele protection"], "holy" : props["ele protection"], "disruption" : props["ele protection"], "cold" : props["ele protection"], "vacuum" : props["ele protection"], "radiation" : props["ele protection"], "sonic" : props["ele protection"], "plasma" : props["ele protection"], "acid" : props["ele protection"], "electricity" : props["ele protection"], "impact" : props["ele protection"], "fire" : props["ele protection"], "impaling" : props["ele protection"], "cutting" : props["ele protection"], "crushing" : props["ele protection"] ]);
	message("info", "%^BLUE%^The mass immerses itself with "+ (string)caster->query_cap_name() +"!%^RESET%^", environment(caster));
	inv[i]->remove();
	caster->set("mass bind", 1);
	call_out("remove_spell", props["duration"], power, at, flag);
	::spell_func(caster, at, power, args, flag);
	remove();
	return;
    }
}
message("info", "There is no energy mass present owned by you that you can immerse.", caster);
caster->add_mp(props["mp cost"]);
remove();
return;
}

void remove_spell(int power, object caster, int flag) {
    message("info", "%^BLUE%^The mass can no longer stay immersed with your body. It quickly dissipates.%^RESET%^", caster);
    caster->set("mass bind", 0);
    remove();
    return;
}

int filter_fun(object ob) {
    if(ob->query_name() == "energy mass") return 1;
    else return 0;
}
