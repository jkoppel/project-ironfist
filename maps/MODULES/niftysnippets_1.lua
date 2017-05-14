local niftysnippets = {}

function niftysnippets.CloneHeroSkills(from, to)
	SetPrimarySkill(to, PRIMARY_SKILL_ATTACK, GetPrimarySkill(from, PRIMARY_SKILL_ATTACK));
	SetPrimarySkill(to, PRIMARY_SKILL_DEFENSE, GetPrimarySkill(from, PRIMARY_SKILL_DEFENSE));
	SetPrimarySkill(to, PRIMARY_SKILL_SPELLPOWER, GetPrimarySkill(from, PRIMARY_SKILL_SPELLPOWER));
	SetPrimarySkill(to, PRIMARY_SKILL_KNOWLEDGE, GetPrimarySkill(from, PRIMARY_SKILL_KNOWLEDGE));
	SetSecondarySkill(to, SECONDARY_SKILL_ARCHERY, GetSecondarySkill(from, SECONDARY_SKILL_ARCHERY));
	SetSecondarySkill(to, SECONDARY_SKILL_LEADERSHIP, GetSecondarySkill(from, SECONDARY_SKILL_LEADERSHIP));
	SetSecondarySkill(to, SECONDARY_SKILL_WISDOM, GetSecondarySkill(from, SECONDARY_SKILL_WISDOM));
	SetSecondarySkill(to, SECONDARY_SKILL_LUCK, GetSecondarySkill(from, SECONDARY_SKILL_LUCK));
	SetSpellpoints(to, GetSpellpoints(from));
end

return niftysnippets