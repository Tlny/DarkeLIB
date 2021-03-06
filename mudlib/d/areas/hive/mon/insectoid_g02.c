//  Wizard:   Myrddin
//  Monster: Good Insectoid Guard
//  File:        insectoid_g02.c
//  June 97

inherit "/std/monster";

create() {
  int    zlevel,zskill;
  ::create();
    set_name("insectoid guard");
    set_id( ({ "insectoid guard", "insectoid", "guard" }) );
    zlevel=random(2)+4;
    zskill=zlevel*10;
    set_level(zlevel);
    set_short("insectoid guard");
    set_long("The insectoid guard stands watching, guarding against "
                   "any threats to the hive.  It looks like a cross between an "
                   "ant and a preying mantis, that is also 4 feet tall and "
                   "6 feet long.  Its exoskeleton is quite dark.");
    set("race", "insectoid");
    set_gender("neuter");
    set_body_type("thranx");
    set_wielding_limbs( ({ "first hand", "second hand", "third hand",
                                        "fourth hand" }) );
    set_property("melee damage", ([ "crushing" : (zskill+40)]));
    set_overall_ac(30);
    set_skill("melee", (zskill+30));
    set_skill("dodge", zskill);
    set_skill("parry", zskill);
    set_skill("attack", (zskill+30));
    set_skill("combo",35);
    set_skill("offhand training",200);
    set_skill("dual attack",100);
    set_skill("perception",75);
    set_stats("dexterity", zskill);
    set_stats("intelligence", 50);
    set_stats("strength", (zskill+30));
    set("aggressive", 1);
    set_wimpy(0);
    set_alignment(100);
    set_emotes(5, ({
  "The insectoid fights in complete silence.",
}),1);
}



