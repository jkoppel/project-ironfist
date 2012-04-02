int __thiscall sub_4D31F0(int this)
{
  int v1; // ST0C_4@1
  int v2; // ST10_4@1
  int v3; // ST10_4@1
  int v4; // ST10_4@1

  v1 = this;
  v2 = ((unsigned __int8)sub_4D31C0(this) << 24) | 0;
  v3 = ((unsigned __int8)sub_4D31C0(v1) << 16) | v2;
  v4 = ((unsigned __int8)sub_4D31C0(v1) << 8) | v3;
  return (unsigned __int8)sub_4D31C0(v1) | v4;
}
