extern "C" {

	void hero::AddSpell(hero * this, int  spell, int  knowledge);
	char hero::Stats(hero * this, PRIMARY_SKILL  skill);
	signed int hero::HasArtifact(hero * this, ARTIFACT  artifact);
}
