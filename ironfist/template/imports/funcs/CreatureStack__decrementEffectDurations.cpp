{
  CreatureStack *thisa; // [sp+Ch] [bp-8h]@1
  STACK_MODIFYING_EFFECT effect; // [sp+10h] [bp-4h]@1

  thisa = this;
  for ( effect = 0; (signed int)effect < 15; ++effect )
  {
    if ( thisa->effectStrengths[effect] )
    {
      if ( thisa->effectStrengths[effect] == 1 )
        CreatureStack::removeEffect(thisa, effect);
      else
        --thisa->effectStrengths[effect];
    }
  }
  if ( thisa->lifespan > 0 )
    --thisa->lifespan;
}
