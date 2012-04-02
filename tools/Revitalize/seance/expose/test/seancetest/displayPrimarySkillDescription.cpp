GUIWindow *__stdcall displayPrimarySkillDescription(int skill, unsigned int a2)
{
  return display_message_window(primary_skill_descriptions[skill], a2 < 1 ? 1 : 4, -1, -1, -1, 0, -1, 0, -1, 0);
}
