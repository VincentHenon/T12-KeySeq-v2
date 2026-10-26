/* Reconstructed pseudo-C from Doboz T12 v20 UF2.
 * Names/types are inferred; this is not the original source.
 */

/* entry at 100001e2 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void entry(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *piVar6;
  
  if (_DAT_d0000000 != 0) {
    _DAT_e000ed08 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      setMainStackPointer(uRam00000000);
    }
                    /* WARNING: Could not recover jumptable at 0x100001e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*pcRam00000004)(8,uRam00000000);
    return;
  }
  piVar5 = &DAT_10000224;
  uVar2 = 0;
  while( true ) {
    iVar3 = *piVar5;
    piVar6 = piVar5 + 1;
    piVar5 = piVar5 + 3;
    if (iVar3 == 0) break;
    uVar2 = FUN_1000021e(uVar2,iVar3,*piVar6);
  }
  for (puVar4 = (undefined4 *)&DAT_20002738; puVar4 != (undefined4 *)0x20002bc0; puVar4 = puVar4 + 1
      ) {
    *puVar4 = 0;
  }
  (*(code *)&SUB_2000228c)();
  (*(code *)&SUB_200001a4)();
  (*(code *)&SUB_20000318)();
  do {
    software_bkpt(0);
  } while( true );
}



/* FUN_1000021e at 1000021e */

void FUN_1000021e(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  for (; param_3 < param_4; param_3 = param_3 + 1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_3 = uVar1;
  }
  return;
}



/* FUN_100007c0 at 100007c0 */

bool FUN_100007c0(int *param_1,int *param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if (*param_1 != *param_2) {
    if ((param_1[1] != param_2[1]) && (*param_1 != param_2[1])) {
      bVar1 = *param_2 != param_1[1];
    }
  }
  return bVar1;
}



/* FUN_100007e2 at 100007e2 */

int FUN_100007e2(int param_1)

{
  return ((uint)((param_1 << 0x16) >> 0x16 == -1) + param_1 & 0x3ff) + 4;
}



/* FUN_10000814 at 10000814 */

int FUN_10000814(int param_1,uint *param_2,uint param_3,uint param_4,uint param_5,int param_6,
                uint param_7)

{
  uint uVar1;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if ((*(uint *)(*(int *)(param_1 + 0x68) + 0x1c) < param_5 + param_7) ||
     ((*(uint *)(param_1 + 0x6c) != 0 && (*(uint *)(param_1 + 0x6c) <= param_4)))) {
    return -0x54;
  }
  do {
    if (param_7 == 0) {
      return 0;
    }
    while( true ) {
      uVar6 = param_7;
      if (param_4 == *param_2) {
        uVar1 = param_2[1];
        if (param_5 < uVar1 + param_2[2]) {
          if (uVar1 <= param_5) {
            uVar3 = (uVar1 + param_2[2]) - param_5;
            if (param_7 < uVar3) {
              uVar3 = param_7;
            }
            FUN_1000243c(param_6,param_2[3] + (param_5 - uVar1),uVar3);
            iVar4 = -uVar3;
            goto LAB_1000087a;
          }
          uVar6 = uVar1 - param_5;
          if (param_7 < uVar1 - param_5) {
            uVar6 = param_7;
          }
        }
      }
      iVar4 = *(int *)(param_1 + 0x68);
      uVar1 = *(uint *)(iVar4 + 0x14);
      FUN_100022bc(param_5,uVar1);
      pcVar2 = *(code **)(iVar4 + 4);
      if (((param_3 <= param_7) && (extraout_r1 == 0)) && (uVar1 <= param_7)) break;
      *param_2 = param_4;
      param_2[1] = param_5 - extraout_r1;
      iVar5 = (param_3 - 1) + uVar1 + param_5;
      FUN_100022bc(iVar5,uVar1);
      uVar6 = iVar5 - extraout_r1_01;
      if (*(uint *)(iVar4 + 0x1c) < uVar6) {
        uVar6 = *(uint *)(iVar4 + 0x1c);
      }
      uVar6 = uVar6 + (extraout_r1 - param_5);
      if (*(uint *)(iVar4 + 0x28) < uVar6) {
        uVar6 = *(uint *)(iVar4 + 0x28);
      }
      param_2[2] = uVar6;
      iVar4 = (*pcVar2)(iVar4,param_4,param_5 - extraout_r1,param_2[3],uVar6);
      if (iVar4 != 0) {
        return iVar4;
      }
    }
    FUN_100022bc(uVar6,uVar1);
    uVar3 = uVar6 - extraout_r1_00;
    iVar4 = (*pcVar2)(iVar4,param_4,param_5,param_6,uVar3);
    if (iVar4 != 0) {
      return iVar4;
    }
    iVar4 = extraout_r1_00 - uVar6;
LAB_1000087a:
    param_6 = param_6 + uVar3;
    param_7 = param_7 + iVar4;
    param_5 = param_5 + uVar3;
  } while( true );
}



/* FUN_1000093e at 1000093e */

int FUN_1000093e(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint local_34;
  undefined1 auStack_20 [12];
  
  uVar4 = *param_1;
  param_2 = param_2 & 0x3ff;
  uVar2 = param_1[2];
  if (param_2 < (uint)param_1[2]) {
    uVar2 = param_2;
  }
  uVar8 = 0;
  uVar5 = *param_3;
  iVar6 = param_3[1];
  iVar7 = param_1[1];
  do {
    if (uVar2 <= uVar8) {
      iVar6 = 0;
      if (param_1[2] != param_2) {
        uVar2 = (uint)(param_2 <= (uint)param_1[2]);
LAB_100009b0:
        iVar6 = uVar2 + 1;
      }
      return iVar6;
    }
    uVar3 = uVar2 - uVar8;
    local_34 = uVar3;
    if (8 < uVar3) {
      local_34 = 8;
    }
    iVar1 = FUN_10000814(uVar4,uVar4,uVar3,uVar5,iVar6 + uVar8,auStack_20,local_34);
    if (iVar1 != 0) {
      return iVar1;
    }
    uVar3 = FUN_10002530(auStack_20,iVar7 + uVar8,local_34);
    if (uVar3 != 0) {
      uVar2 = ~uVar3 >> 0x1f;
      goto LAB_100009b0;
    }
    uVar8 = uVar8 + local_34;
  } while( true );
}



/* FUN_100009bc at 100009bc */

int FUN_100009bc(int param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = *param_2;
  uVar4 = *(int *)(param_1 + 0x1c) - 8;
  iVar1 = 0;
  if (uVar4 <= uVar3) {
    iVar1 = FUN_100022bc(uVar3,uVar4,param_3,param_4,param_4);
    iVar1 = FUN_100022b0(iVar1 + -1);
    iVar1 = FUN_100022bc(uVar3 + (iVar1 + 2) * -4,uVar4);
    iVar2 = FUN_100022b0();
    *param_2 = (uVar3 + iVar2 * -4) - iVar1 * uVar4;
  }
  return iVar1;
}



/* FUN_10000a9c at 10000a9c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_10000a9c(int param_1,uint *param_2,uint *param_3,uint param_4,uint param_5,ushort *param_6,
                 code *param_7,undefined4 param_8)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int extraout_r1;
  uint uVar5;
  ushort uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  uint local_7c;
  uint local_78;
  int local_74;
  uint local_70;
  uint local_6c;
  uint local_68;
  int local_54;
  uint local_50;
  uint local_40;
  uint local_3c;
  uint local_38 [4];
  uint local_28;
  int local_24;
  uint local_20;
  int local_1c;
  
  uVar5 = *(uint *)(param_1 + 0x6c);
  if ((uVar5 == 0) || ((*param_3 < uVar5 && (param_3[1] < uVar5)))) {
    local_38[0] = 0;
    local_38[1] = 0;
    uVar5 = FUN_10000814(param_1,param_1,4,*param_3,0,local_38,4);
    if ((uVar5 != 0) && (uVar5 != 0xffffffac)) {
      return uVar5;
    }
    uVar9 = 0;
    uVar5 = FUN_10000814(param_1,param_1,4,param_3[1],0,local_38 + 1,4);
    if (uVar5 == 0) {
      uVar9 = ((int)(local_38[1] - local_38[0]) >> 0x1f) - (local_38[1] - local_38[0]) >> 0x1f;
    }
    else if (uVar5 != 0xffffffac) {
      return uVar5;
    }
    *param_2 = param_3[uVar9];
    param_2[1] = param_3[uVar9 ^ 1];
    param_2[2] = local_38[uVar9];
    param_2[3] = 0;
    local_54 = 2;
    local_7c = 0xffffffff;
    do {
      local_38[2] = _DAT_20002590;
      local_38[3] = _DAT_20002594;
      local_40 = FUN_100017b8(0xffffffff,param_2 + 2,4,0x20002598);
      bVar1 = false;
      local_50 = 0;
      local_6c = 0;
      local_70 = 0xffffffff;
      local_74 = 0;
      uVar5 = local_7c;
      while( true ) {
        iVar7 = FUN_100007e2(local_70);
        local_74 = local_74 + iVar7;
        uVar2 = FUN_10000814(param_1,param_1,*(undefined4 *)(*(int *)(param_1 + 0x68) + 0x1c),
                             *param_2,local_74,&local_3c,4);
        if (uVar2 != 0) break;
        local_40 = FUN_100017b8(local_40,&local_3c,4);
        local_78 = local_70 ^
                   (local_3c << 0x18 | (local_3c >> 8 & 0xff) << 0x10 |
                    (local_3c >> 0x10 & 0xff) << 8 | local_3c >> 0x18);
        local_3c = local_78;
        if ((int)local_78 < 0) {
          bVar11 = (local_70 >> 0x14 & 0x780) == 0x500;
          goto LAB_10000bcc;
        }
        iVar7 = FUN_100007e2(local_78);
        uVar10 = *(uint *)(*(int *)(param_1 + 0x68) + 0x1c);
        if (uVar10 < (uint)(iVar7 + local_74)) goto LAB_10000e0a;
        uVar4 = *param_2;
        iVar8 = local_74 + 4;
        if ((local_78 >> 0x14 & 0x780) == 0x500) {
          uVar2 = FUN_10000814(param_1,param_1,uVar10,uVar4,iVar8,&local_20,4);
          if (uVar2 != 0) break;
          if (local_20 != local_40) goto LAB_10000e0a;
          local_78 = local_78 ^ (local_3c >> 0x14) << 0x1f;
          uVar3 = FUN_100017b8(*(undefined4 *)(param_1 + 0x2c),&local_40,4);
          *(undefined4 *)(param_1 + 0x2c) = uVar3;
          iVar7 = FUN_100007e2(local_3c);
          param_2[3] = iVar7 + local_74;
          param_2[4] = local_78;
          *(short *)(param_2 + 5) = (short)local_6c;
          param_2[6] = local_38[2];
          param_2[7] = local_38[3];
          *(char *)((int)param_2 + 0x17) = (char)local_50;
          local_40 = 0xffffffff;
          local_7c = uVar5;
        }
        else {
          for (local_70 = 0; local_70 < iVar7 - 4U; local_70 = local_70 + local_68) {
            local_68 = (iVar7 - 4U) - local_70;
            if (8 < local_68) {
              local_68 = 8;
            }
            uVar2 = FUN_10000814(param_1,param_1,uVar10 - local_70,uVar4,local_70 + iVar8,&local_20,
                                 local_68);
            if (uVar2 != 0) goto LAB_10000b86;
            local_40 = FUN_100017b8(local_40,&local_20,local_68);
          }
          uVar2 = local_3c >> 0x14;
          if ((uVar2 & 0x700) == 0) {
            uVar2 = (local_3c & 0xfffff) >> 10;
            if (local_6c <= uVar2) {
              local_6c = uVar2 + 1;
            }
          }
          else if ((uVar2 & 0x700) == 0x400) {
            local_6c = local_6c + (int)(char)uVar2 & 0xffff;
            if (local_3c == (uVar5 & 0xffc00 | 0x4ff00000)) {
              uVar5 = uVar5 | 0x80000000;
            }
            else if ((uVar5 != 0xffffffff) &&
                    ((local_3c & 0xfffff) >> 10 <= (uVar5 & 0xfffff) >> 10)) {
              uVar5 = (char)uVar2 * 0x400 + uVar5;
            }
          }
          else if ((uVar2 & 0x700) == 0x600) {
            local_50 = uVar2 & 1;
            uVar2 = FUN_10000814(param_1,param_1,*(undefined4 *)(*(int *)(param_1 + 0x68) + 0x1c),
                                 *param_2,iVar8,local_38 + 2,8);
            if (uVar2 != 0) break;
          }
          else if ((uVar2 & 0x7ff) == 0x5ff) {
            iVar7 = FUN_10000814(param_1,param_1,*(undefined4 *)(*(int *)(param_1 + 0x68) + 0x1c),
                                 *param_2,iVar8,&local_28,8);
            if (iVar7 == -0x54) goto LAB_10000e0a;
            bVar1 = true;
          }
          if ((param_4 & (param_5 ^ local_3c)) == 0) {
            local_20 = *param_2;
            local_1c = iVar8;
            uVar2 = (*param_7)(param_8);
            if ((int)uVar2 < 0) break;
            if (uVar2 == 0) {
              uVar5 = local_3c;
            }
            else if (((uVar5 ^ local_3c) & 0x7ffffc00) == 0) {
              uVar5 = 0xffffffff;
            }
            else if ((uVar2 == 2) && ((local_3c & 0xfffff) >> 10 <= (uVar5 & 0xfffff) >> 10)) {
              uVar5 = local_3c | 0x80000000;
            }
          }
        }
        local_70 = local_78;
      }
LAB_10000b86:
      if (uVar2 != 0xffffffac) {
        return uVar2;
      }
LAB_10000e0a:
      bVar11 = false;
LAB_10000bcc:
      uVar5 = param_2[3];
      if (uVar5 != 0) {
        *(undefined1 *)((int)param_2 + 0x16) = 0;
        if (!bVar11) goto LAB_10000e96;
        iVar7 = *(int *)(param_1 + 0x68);
        FUN_100022bc(uVar5,*(undefined4 *)(iVar7 + 0x18));
        if ((extraout_r1 != 0) || (!bVar1)) goto LAB_10000e96;
        iVar7 = *(int *)(iVar7 + 0x1c);
        uVar2 = *param_2;
        local_74 = -1;
        uVar9 = 0;
        goto LAB_10000e56;
      }
      uVar5 = param_2[1];
      param_2[1] = *param_2;
      *param_2 = uVar5;
      param_2[2] = local_38[uVar9 ^ 1];
      if (local_54 == 1) break;
      local_54 = 1;
    } while( true );
  }
  iVar7 = 0x54;
  goto LAB_10000ab6;
LAB_10000e56:
  if (local_28 <= uVar9) goto LAB_10000e8a;
  uVar10 = local_28 - uVar9;
  if (8 < uVar10) {
    uVar10 = 8;
  }
  uVar4 = FUN_10000814(param_1,param_1,iVar7 - uVar9,uVar2,uVar5 + uVar9,&local_20,uVar10);
  if (uVar4 != 0) {
    if (uVar4 != 0xffffffac) {
      return uVar4;
    }
    goto LAB_10000e8a;
  }
  local_74 = FUN_100017b8(local_74,&local_20,uVar10);
  uVar9 = uVar9 + uVar10;
  goto LAB_10000e56;
LAB_10000e8a:
  *(bool *)((int)param_2 + 0x16) = local_24 == local_74;
LAB_10000e96:
  uVar5 = *(uint *)(param_1 + 0x3c);
  if (((uVar5 >> 0x14 & 0x700) == 0) || (iVar7 = FUN_100007c0(param_1 + 0x40,param_2), iVar7 != 0))
  {
LAB_10000ef4:
    if (param_6 != (ushort *)0x0) goto LAB_10000efa;
LAB_10000f0c:
    if (-1 < (int)local_7c) {
      return local_7c;
    }
  }
  else {
    uVar9 = (uVar5 & 0xfffff) >> 10;
    uVar5 = (local_7c & 0xfffff) >> 10;
    if (uVar5 == uVar9) {
      local_7c = local_7c | 0x80000000;
    }
    else if (local_7c != 0xffffffff) {
      if (uVar9 < uVar5) {
        local_7c = local_7c - 0x400;
      }
      goto LAB_10000ef4;
    }
    if (param_6 != (ushort *)0x0) {
LAB_10000efa:
      uVar5 = (local_7c & 0xfffff) >> 10;
      uVar6 = (ushort)uVar5;
      if ((ushort)param_2[5] < uVar5) {
        uVar6 = (ushort)param_2[5];
      }
      *param_6 = uVar6;
      goto LAB_10000f0c;
    }
  }
  if ((uint)(ushort)param_2[5] <= (local_7c & 0xfffff) >> 10) {
    return 0;
  }
  iVar7 = 2;
LAB_10000ab6:
  return -iVar7;
}



/* FUN_10000f34 at 10000f34 */

int FUN_10000f34(int param_1,undefined4 *param_2,uint param_3,uint param_4,int param_5,int param_6,
                uint param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_2c;
  uint local_1c [2];
  
  uVar4 = *(uint *)(param_1 + 0x3c);
  local_2c = param_2[3];
  uVar2 = uVar4 >> 0x14;
  uVar5 = param_2[4];
  uVar3 = uVar2 & 0x700;
  local_1c[0] = uVar5;
  if ((uVar2 & 0x700) != 0) {
    iVar1 = FUN_100007c0(param_1 + 0x40);
    if (iVar1 == 0) {
      uVar3 = (param_3 & 0xfffff) >> 10;
      if (uVar3 != 0) {
        uVar3 = (uVar4 & 0xfffff) >> 10;
        uVar2 = (param_4 & 0xfffff) >> 10;
        if (uVar3 == uVar2) {
          return -2;
        }
        uVar3 = -(uint)(uVar3 < uVar2) & 0xfffffc00;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  while( true ) {
    iVar1 = FUN_100007e2(uVar5);
    if (local_2c < iVar1 + 4U) {
      return -2;
    }
    local_2c = local_2c - iVar1;
    iVar1 = FUN_10000814(param_1,param_1,4,*param_2,local_2c,local_1c,4);
    if (iVar1 != 0) {
      return iVar1;
    }
    local_1c[0] = ((local_1c[0] << 0x18 | (local_1c[0] >> 8 & 0xff) << 0x10 |
                    (local_1c[0] >> 0x10 & 0xff) << 8 | local_1c[0] >> 0x18) ^ uVar5) & 0x7fffffff;
    if ((((param_3 & 0xfffff) >> 10 != 0) && ((uVar5 >> 0x14 & 0x700) == 0x400)) &&
       ((uVar5 & 0xfffff) >> 10 <= (param_4 - uVar3 & 0xfffff) >> 10)) {
      if (uVar5 == (param_4 - uVar3 & 0xffc00 | 0x40100000)) {
        return -2;
      }
      uVar3 = (char)(uVar5 >> 0x14) * 0x400 + uVar3;
    }
    if ((param_3 & (param_4 - uVar3 ^ uVar5)) == 0) break;
    uVar5 = local_1c[0];
  }
  if ((int)(uVar5 << 0x16) >> 0x16 == -1) {
    return -2;
  }
  uVar2 = uVar5 & 0x3ff;
  if (param_7 < (uVar5 & 0x3ff)) {
    uVar2 = param_7;
  }
  iVar1 = FUN_10000814(param_1,param_1,uVar2,*param_2,param_5 + 4 + local_2c,param_6,uVar2);
  if (iVar1 == 0) {
    FUN_10002430(param_6 + uVar2,0,param_7 - uVar2);
    return uVar5 + uVar3;
  }
  return iVar1;
}



/* FUN_10001068 at 10001068 */

void FUN_10001068(void)

{
  FUN_10000f34();
  return;
}



/* FUN_10001080 at 10001080 */

uint FUN_10001080(int param_1,int param_2,undefined4 *param_3,undefined2 *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  char *local_48;
  int local_44;
  int local_24;
  char *local_20;
  int local_1c;
  
  local_48 = (char *)*param_3;
  if (param_4 != (undefined2 *)0x0) {
    *param_4 = 0x3ff;
  }
  uVar4 = 0x2ffc00;
  *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(param_1 + 0x24);
LAB_100010aa:
  do {
    iVar1 = FUN_100025c0(local_48,&DAT_20002580);
    pcVar5 = local_48 + iVar1;
    iVar1 = FUN_10002578(pcVar5,&DAT_20002580);
    if (iVar1 == 1) {
      if (*pcVar5 != '.') goto LAB_100010e8;
LAB_100010cc:
      local_48 = pcVar5 + iVar1;
      goto LAB_100010aa;
    }
    if ((iVar1 == 2) && (iVar2 = FUN_10002530(pcVar5,0x20002582,2), iVar2 == 0)) goto LAB_100010cc;
LAB_100010e8:
    local_48 = pcVar5 + iVar1;
    local_44 = 1;
    pcVar6 = local_48;
    while( true ) {
      iVar2 = FUN_100025c0(pcVar6,&DAT_20002580);
      pcVar6 = pcVar6 + iVar2;
      iVar2 = FUN_10002578(pcVar6,&DAT_20002580);
      if (iVar2 == 0) break;
      if ((iVar2 == 2) && (iVar3 = FUN_10002530(pcVar6,0x20002582,2), iVar3 == 0)) {
        local_44 = local_44 + -1;
        if (local_44 == 0) {
          local_48 = pcVar6 + 2;
          goto LAB_100010aa;
        }
      }
      else {
        local_44 = local_44 + 1;
      }
      pcVar6 = pcVar6 + iVar2;
    }
    if (*pcVar5 == '\0') {
      return uVar4;
    }
    *param_3 = pcVar5;
    if ((uVar4 & 0x7fffffff) >> 0x14 != 2) {
      return 0xffffffec;
    }
    uVar4 = (uVar4 & 0xfffff) >> 10;
    if ((uVar4 != 0x3ff) &&
       (uVar4 = FUN_10001068(param_1,param_2,0x700ffc00,uVar4 << 10 | 0x20000008,param_2 + 0x18),
       (int)uVar4 < 0)) {
      return uVar4;
    }
    while( true ) {
      iVar2 = FUN_1000246c(pcVar5,0x2f);
      local_24 = param_1;
      local_20 = pcVar5;
      local_1c = iVar1;
      uVar4 = FUN_10000a9c(param_1,param_2,param_2 + 0x18,0x78000000,iVar1,
                           -(uint)(iVar2 == 0) & (uint)param_4,0x20000783,&local_24);
      if ((int)uVar4 < 0) {
        return uVar4;
      }
      if (uVar4 != 0) break;
      if (*(char *)(param_2 + 0x17) == '\0') {
        return 0xfffffffe;
      }
    }
  } while( true );
}



/* FUN_100017b8 at 100017b8 */

void FUN_100017b8(undefined4 param_1,int param_2,int param_3)

{
  param_3 = param_2 + param_3;
  for (; param_2 != param_3; param_2 = param_2 + 1) {
  }
  return;
}



/* FUN_100022b0 at 100022b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100022b0(void)

{
                    /* WARNING: Could not recover jumptable at 0x100022b4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_200026d0)();
  return;
}



/* FUN_100022bc at 100022bc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_100022bc(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int extraout_r2;
  ulonglong uVar6;
  
  uVar3 = _DAT_d0000074;
  uVar2 = _DAT_d0000070;
  uVar1 = _DAT_d0000064;
  uVar4 = _DAT_d0000060;
  if ((_DAT_d0000078 >> 1 & 1) != 0) {
    uVar6 = FUN_100022c4();
    *(undefined4 *)(extraout_r2 + 0x60) = uVar4;
    *(undefined4 *)(extraout_r2 + 100) = uVar1;
    *(undefined4 *)(extraout_r2 + 0x74) = uVar3;
    *(undefined4 *)(extraout_r2 + 0x70) = uVar2;
    return uVar6;
  }
  _DAT_d0000060 = param_1;
  _DAT_d0000064 = param_2;
  if (param_2 != 0) {
    return CONCAT44(_DAT_d0000074,_DAT_d0000070);
  }
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = 0xffffffff;
  }
  uVar5 = FUN_10002468(uVar4);
  return (ulonglong)uVar5;
}



/* FUN_100022c4 at 100022c4 */

ulonglong FUN_100022c4(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  *(int *)(param_3 + 0x60) = param_1;
  *(int *)(param_3 + 100) = param_2;
  if (param_2 != 0) {
    return *(ulonglong *)(param_3 + 0x70);
  }
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = 0xffffffff;
  }
  uVar2 = FUN_10002468(uVar1);
  return (ulonglong)uVar2;
}



/* FUN_10002430 at 10002430 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10002430(void)

{
                    /* WARNING: Could not recover jumptable at 0x10002434. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_200026e0)();
  return;
}



/* FUN_1000243c at 1000243c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000243c(void)

{
                    /* WARNING: Could not recover jumptable at 0x10002440. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_200026e4)();
  return;
}



/* FUN_10002468 at 10002468 */

void FUN_10002468(void)

{
  return;
}



/* FUN_1000246c at 1000246c */

uint * FUN_1000246c(uint *param_1,byte param_2)

{
  uint *puVar1;
  byte *pbVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = (uint)param_1 & 3;
  if (param_2 == 0) {
    while (uVar4 != 0) {
      if ((byte)*param_1 == 0) {
        return param_1;
      }
      param_1 = (uint *)((int)param_1 + 1);
      uVar4 = (uint)param_1 & 3;
    }
    uVar4 = *param_1 + 0xfefefeff & ~*param_1;
    while ((uVar4 & 0x80808080) == 0) {
      puVar1 = param_1 + 1;
      param_1 = param_1 + 1;
      uVar4 = *puVar1 + 0xfefefeff & ~*puVar1;
    }
    bVar3 = (byte)*param_1;
    while (bVar3 != 0) {
      pbVar2 = (byte *)((int)param_1 + 1);
      param_1 = (uint *)((int)param_1 + 1);
      bVar3 = *pbVar2;
    }
  }
  else {
    while (uVar4 != 0) {
      if ((byte)*param_1 == 0) {
        return (uint *)0x0;
      }
      if ((byte)*param_1 == param_2) {
        return param_1;
      }
      param_1 = (uint *)((int)param_1 + 1);
      uVar4 = (uint)param_1 & 3;
    }
    uVar4 = *param_1;
    uVar5 = (uint)param_2 * 0x1010101 ^ uVar4;
    if (((uVar4 + 0xfefefeff & ~uVar4 | uVar5 + 0xfefefeff & ~uVar5) & 0x80808080) != 0)
    goto LAB_100024c6;
    do {
      uVar4 = param_1[1];
      uVar5 = uVar4 ^ (uint)param_2 * 0x1010101;
      param_1 = param_1 + 1;
    } while (((uVar4 + 0xfefefeff & ~uVar4 | uVar5 + 0xfefefeff & ~uVar5) & 0x80808080) == 0);
    bVar3 = (byte)*param_1;
    while (bVar3 != 0) {
      if (param_2 == bVar3) {
        return param_1;
      }
      param_1 = (uint *)((int)param_1 + 1);
LAB_100024c6:
      bVar3 = (byte)*param_1;
    }
    param_1 = (uint *)0x0;
  }
  return param_1;
}



/* FUN_10002530 at 10002530 */

int FUN_10002530(int *param_1,int *param_2,uint param_3)

{
  int iVar1;
  
  if (3 < param_3) {
    if ((((uint)param_2 | (uint)param_1) & 3) != 0) goto LAB_10002556;
    do {
      if (*param_1 != *param_2) goto LAB_10002556;
      param_3 = param_3 - 4;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (3 < param_3);
  }
  if (param_3 == 0) {
    return 0;
  }
LAB_10002556:
  iVar1 = 0;
  while( true ) {
    if ((uint)*(byte *)((int)param_1 + iVar1) != (uint)*(byte *)((int)param_2 + iVar1)) {
      return (uint)*(byte *)((int)param_1 + iVar1) - (uint)*(byte *)((int)param_2 + iVar1);
    }
    if (param_3 - 1 == iVar1) break;
    iVar1 = iVar1 + 1;
  }
  return 0;
}



/* FUN_10002578 at 10002578 */

int FUN_10002578(char *param_1,char *param_2)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char cVar4;
  char cVar5;
  char *pcVar6;
  
  cVar5 = *param_1;
  if (cVar5 == '\0') {
    iVar2 = 0;
  }
  else {
    pcVar6 = param_1;
    pcVar3 = param_1;
    if (*param_2 == '\0') {
      do {
        pcVar6 = pcVar3 + 1;
        if (pcVar3[1] == '\0') break;
        pcVar1 = pcVar3 + 2;
        pcVar6 = pcVar3 + 2;
        pcVar3 = pcVar6;
      } while (*pcVar1 != '\0');
    }
    else {
      do {
        pcVar3 = param_2;
        cVar4 = *param_2;
        do {
          if (cVar5 == cVar4) goto LAB_1000259a;
          cVar4 = pcVar3[1];
          pcVar3 = pcVar3 + 1;
        } while (cVar4 != '\0');
        cVar5 = pcVar6[1];
        pcVar6 = pcVar6 + 1;
      } while (cVar5 != '\0');
    }
LAB_1000259a:
    iVar2 = (int)pcVar6 - (int)param_1;
  }
  return iVar2;
}



/* FUN_100025c0 at 100025c0 */

int FUN_100025c0(char *param_1,char *param_2)

{
  int iVar1;
  char *pcVar2;
  char *pcVar3;
  char cVar4;
  char cVar5;
  
  cVar5 = *param_1;
  if (cVar5 == '\0') {
    iVar1 = 0;
  }
  else {
    iVar1 = 0;
    if (*param_2 != '\0') {
      pcVar2 = param_1;
      do {
        pcVar3 = param_2;
        cVar4 = *param_2;
        while (cVar5 != cVar4) {
          cVar4 = pcVar3[1];
          pcVar3 = pcVar3 + 1;
          if (cVar4 == '\0') goto LAB_100025f0;
        }
        cVar5 = pcVar2[1];
        pcVar2 = pcVar2 + 1;
      } while (cVar5 != '\0');
LAB_100025f0:
      iVar1 = (int)pcVar2 - (int)param_1;
    }
  }
  return iVar1;
}



/* FUN_100025f8 at 100025f8 */

void FUN_100025f8(void)

{
  undefined4 *puVar1;
  
  if (DAT_20002bbd == '\0') {
    puVar1 = &_binary__private_tmp_t12_doboz_v20_bin_start;
    do {
      puVar1[0x4000a23] = *puVar1;
      puVar1 = puVar1 + 1;
    } while (puVar1 != (undefined4 *)&UNK_10000100);
    DAT_20002bbd = '\x01';
  }
  return;
}



/* FUN_100025fc at 100025fc */

void FUN_100025fc(void)

{
  undefined4 *puVar1;
  
  if (DAT_20002bbd == '\0') {
    puVar1 = &_binary__private_tmp_t12_doboz_v20_bin_start;
    do {
      puVar1[0x4000a23] = *puVar1;
      puVar1 = puVar1 + 1;
    } while (puVar1 != (undefined4 *)&UNK_10000100);
    DAT_20002bbd = '\x01';
  }
  return;
}



/* FUN_1000262c at 1000262c */

void FUN_1000262c(void)

{
  (*(code *)&SUB_2000288c)();
  return;
}



/* FUN_1000311e at 1000311e */

void FUN_1000311e(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  for (; param_3 < param_4; param_3 = param_3 + 1) {
    uVar1 = *param_2;
    param_2 = param_2 + 1;
    *param_3 = uVar1;
  }
  return;
}



/* FUN_10003174 at 10003174 */

/* WARNING: Removing unreachable block (ram,0x1000317e) */
/* WARNING: Removing unreachable block (ram,0x10003184) */

void FUN_10003174(void)

{
  return;
}



/* FUN_10003194 at 10003194 */

/* WARNING: Removing unreachable block (ram,0x100031a6) */
/* WARNING: Removing unreachable block (ram,0x100031ac) */

void FUN_10003194(void)

{
  return;
}



/* FUN_100031bc at 100031bc */

/* WARNING: Removing unreachable block (ram,0x100031d0) */

undefined4 FUN_100031bc(undefined4 param_1)

{
  if (DAT_20001350 == '\0') {
    param_1 = FUN_10003174();
    DAT_20001350 = '\x01';
  }
  return param_1;
}



/* FUN_100031e8 at 100031e8 */

/* WARNING: Removing unreachable block (ram,0x100031f0) */

void FUN_100031e8(undefined4 param_1,undefined4 param_2)

{
  FUN_10003194(param_1,param_2);
  return;
}



/* pwm_irq at 10003228 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void pwm_irq(void)

{
  byte bVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  
  _DAT_400500a4 = 4;
  iVar3 = (uint)DAT_2000403c * 8;
  uVar4 = (uint)(DAT_2000403d >> 1);
  _DAT_40051034 =
       ((uint)*(ushort *)((iVar3 + uVar4) * 2 + 0x200031e8) << 0x10 ^ _DAT_40050034) & 0xffff0000;
  if (*(char *)(iVar3 + 0x20003f9f + uVar4) == '\0') {
    _DAT_d0000014 = 0x80;
  }
  else {
    _DAT_d0000018 = 0x80;
  }
  *(short *)((iVar3 + uVar4) * 2 + 0x2000313e) = (short)_DAT_4004c00c;
  iVar3 = FUN_1001c8f4(3);
  *(char *)((uint)DAT_2000403c * 8 + 0x20003f6d + uVar4) =
       ((char)(iVar3 + -1) - ((char)iVar3 + -2)) - (iVar3 + -1 == 0);
  iVar3 = FUN_1001c8f4(6);
  bVar1 = DAT_2000403c;
  *(char *)((uint)DAT_2000403c * 8 + 0x20004103 + uVar4) = '\x01' - (iVar3 == 1);
  DAT_2000403d = DAT_2000403d + 1;
  if (0xf < DAT_2000403d) {
    DAT_2000403d = 0;
    DAT_2000403c = 1 - bVar1;
    puVar2 = &DAT_20004102;
    if (DAT_20004102 != '\0') {
      puVar2 = &DAT_20003308;
    }
    *puVar2 = 1;
  }
  return;
}



/* FUN_1000330c at 1000330c */

void FUN_1000330c(undefined4 *param_1)

{
  (**(code **)*param_1)();
  return;
}



/* FUN_10003316 at 10003316 */

void FUN_10003316(undefined4 *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = param_2 + 8U & 0xff;
  if ((uVar1 < 8) && ((int)((0xddU >> uVar1) << 0x1f) < 0)) {
    FUN_1000330c(*param_1);
  }
  return;
}



/* FUN_10003332 at 10003332 */

uint FUN_10003332(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = (param_2 >> 0x18) * 2;
  uVar2 = (uint)*(ushort *)(param_1 + iVar1);
  return uVar2 + ((*(ushort *)(param_1 + iVar1 + 2) - uVar2) * (param_2 >> 8 & 0xffff) >> 0x10) &
         0xffff;
}



/* FUN_1000334c at 1000334c */

void FUN_1000334c(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint local_28;
  uint local_24;
  undefined4 local_20;
  uint local_1c;
  
  local_28 = 0x10000;
  local_1c = 0x40000000;
  local_24 = ((param_3 + 4) * 0x1000 | param_3 << 7) & 0x9fffffffU | 0x40000000;
  local_20 = 0x40000;
  FUN_1001da84(5);
  uVar3 = FUN_1001f324();
  uVar3 = FUN_1001f276(uVar3,0x49742400);
  uVar3 = FUN_1001f29e(uVar3,0x3fa00000);
  uVar3 = FUN_1001f276(uVar3,0x40400000);
  uVar3 = FUN_1001f270(uVar3,0x3b000000);
  uVar2 = FUN_1001f3d8();
  uVar4 = 0;
  if (uVar2 != 0) {
    uVar5 = FUN_1001f324(uVar2);
    uVar3 = FUN_1001f26a(uVar3,uVar5);
    FUN_1001f29e(uVar3,0x43800000);
    bVar1 = FUN_1001f3d8();
    uVar4 = (uint)bVar1;
  }
  local_28 = uVar4 << 8 | (uint)uVar2 << 0x10;
  local_1c = local_1c & 0xfc0f83e0 | param_4 & 0x1f | (param_4 & 0x1f) << 10 | 0x100000;
  FUN_1001ce74(param_4,(param_1 + 0xafe00000U >> 0x14) + 6 & 0xff);
  FUN_1001e1a0(param_1,param_2,param_4,1,1);
  FUN_1001e240(param_1,param_2,param_3,&local_28);
  return;
}



/* FUN_1000343c at 1000343c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000343c(void)

{
  _DAT_50000040 = 0x20002c2c;
  _DAT_50000044 = _DAT_20000874 + 0x10;
  _DAT_50000048 = 0xc;
  _DAT_5000004c = _DAT_200013b8;
  return;
}



/* FUN_10003468 at 10003468 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10003468(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001e16c(_DAT_20000874,&DAT_1002955c);
  FUN_1000334c(_DAT_20000874,0,uVar1,2);
  _DAT_200013b8 = 0x819;
  *_DAT_20000874 = *_DAT_20000874 | 1;
  return;
}



/* FUN_100034a4 at 100034a4 */

void FUN_100034a4(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_c;
  undefined1 local_b;
  undefined2 uStack_a;
  
  uStack_a = (undefined2)((uint)param_4 >> 0x10);
  _local_c = CONCAT11((char)param_2,param_1);
  FUN_1001dfc0(&DAT_200009b0,0x5a,&local_c,2,0,param_2,param_3);
  return;
}



/* FUN_100034c4 at 100034c4 */

undefined1 FUN_100034c4(undefined1 param_1)

{
  undefined1 local_19 [5];
  undefined1 local_14 [4];
  
  local_19[0] = param_1;
  FUN_1001dfc0(&DAT_200009b0,0x5a,local_19,1,1);
  FUN_1001dfd8(&DAT_200009b0,0x5a,local_14,1,0);
  return local_14[0];
}



/* FUN_100034fc at 100034fc */

undefined8 FUN_100034fc(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = FUN_1001f330(param_1 >> 0x10 & 0xff);
  FUN_1001f29e(uVar1,param_2);
  uVar2 = FUN_1001f374();
  if ((int)uVar2 < 0x100) {
    uVar2 = uVar2 & (int)~uVar2 >> 0x1f;
  }
  else {
    uVar2 = 0xff;
  }
  uVar1 = FUN_1001f330(param_1 >> 8 & 0xff);
  FUN_1001f29e(uVar1,param_3);
  uVar3 = FUN_1001f374();
  if ((int)uVar3 < 0x100) {
    uVar3 = uVar3 & (int)~uVar3 >> 0x1f;
  }
  else {
    uVar3 = 0xff;
  }
  uVar1 = FUN_1001f330(param_1 & 0xff);
  FUN_1001f29e(uVar1,param_4);
  uVar4 = FUN_1001f374();
  if ((int)uVar4 < 0x100) {
    uVar4 = uVar4 & (int)~uVar4 >> 0x1f;
  }
  else {
    uVar4 = 0xff;
  }
  return CONCAT44(param_1,uVar4 | uVar3 << 8 | uVar2 << 0x10);
}



/* FUN_10003574 at 10003574 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10003574(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (DAT_200041f1 == '\0') {
    _DAT_20000868 = 0x655b5f;
    _DAT_2000086c = 0x7677ff;
  }
  else {
    _DAT_20000868 = 0x4b32c8;
    _DAT_2000086c = 0x4b32ff;
    if (DAT_200041f1 == '\x02') {
      _DAT_20000868 = FUN_100034fc(0x4b32c8,0x3f333333,0x3f333333,0x3f99999a);
      uVar2 = 0x3f99999a;
      uVar1 = 0x3f333333;
    }
    else {
      if (DAT_200041f1 != '\x03') {
        _DAT_20000868 = 0x4b32c8;
        _DAT_2000086c = 0x4b32ff;
        return;
      }
      _DAT_20000868 = FUN_100034fc(0x4b32c8,0x3f000000,0x3f000000,0x3fb33333);
      uVar2 = 0x3fb33333;
      uVar1 = 0x3f000000;
    }
    _DAT_2000086c = FUN_100034fc(0x4b32ff,uVar1,uVar1,uVar2);
    _DAT_2000085c = _DAT_2000085c | 0x6400;
  }
  return;
}



/* FUN_100035fc at 100035fc */

void FUN_100035fc(uint param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  
  if (0xb < param_1) {
    param_1 = 0xb;
  }
  param_1 = param_1 & 0xff;
  uVar1 = (uint)*(byte *)(param_1 + 0x20003ffd);
  *(char *)(param_1 + 0x20004009) = (char)(uVar1 * param_2 >> 8);
  (&DAT_20003ff1)[param_1] = (char)(uVar1 * param_3 >> 8);
  (&DAT_20003fe4)[param_1] = (char)(param_4 * uVar1 >> 8);
  return;
}



/* FUN_1000364a at 1000364a */

undefined8 FUN_1000364a(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = 0;
  uVar2 = param_3;
  do {
    if ((param_1 >> (uVar1 & 0xff) & 1) != 0) {
      FUN_100035fc(uVar1 & 0xff,param_2,param_3,param_4,param_2,param_3,uVar2);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 != 0xc);
  return CONCAT44(param_3,param_2);
}



/* FUN_10003674 at 10003674 */

void FUN_10003674(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_2 * 4 + 0x20000844);
  FUN_100035fc(param_1,uVar1 >> 0x10 & 0xff,uVar1 >> 8 & 0xff,uVar1 & 0xff);
  return;
}



/* FUN_100036b2 at 100036b2 */

void FUN_100036b2(undefined4 param_1,int param_2)

{
  uint extraout_r1;
  uint uVar1;
  uint extraout_r1_00;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  undefined1 local_1c [8];
  
  uVar3 = param_2 * 6;
  FUN_1001f4c8(local_1c,0,3);
  FUN_1001e4d0(uVar3 + 0x400,0x600);
  iVar4 = 0;
  uVar1 = uVar3;
  do {
    uVar2 = 0xff;
    if (0xff < uVar1) {
      if (uVar1 < 0x200) {
        uVar1 = ~uVar1;
      }
      else {
        uVar2 = 0;
        if ((uVar1 < 0x400) || (uVar2 = 0xff, 0x4ff < uVar1)) goto LAB_10003704;
      }
      uVar2 = (undefined1)uVar1;
    }
LAB_10003704:
    local_1c[iVar4] = uVar2;
    iVar4 = iVar4 + 1;
    if (iVar4 == 3) {
      FUN_100035fc(param_1,local_1c[0],local_1c[1],local_1c[2]);
      return;
    }
    uVar1 = extraout_r1;
    if (iVar4 == 1) {
      FUN_1001e4d0(uVar3 + 0x200,0x600);
      uVar1 = extraout_r1_00;
    }
  } while( true );
}



/* FUN_10003732 at 10003732 */

void FUN_10003732(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 extraout_r2;
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = param_1 >> (uVar2 & 0xff);
    if ((uVar1 & 1) != 0) {
      FUN_100036b2(uVar2 & 0xff,param_2,param_3,uVar1,param_4);
      param_3 = extraout_r2;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 0xc);
  return;
}



/* FUN_10003774 at 10003774 */

void FUN_10003774(int param_1)

{
  DAT_20003ff0 = (&DAT_10028f34)[param_1];
  return;
}



/* FUN_10003788 at 10003788 */

void FUN_10003788(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = uVar2 & 0xff;
    *(undefined1 *)(uVar2 + 0x20003ffd) = 0xff;
    uVar2 = uVar2 + 1;
    FUN_100035fc(uVar1,0,0);
  } while (uVar2 != 0xc);
  return;
}



/* FUN_100037ac at 100037ac */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100037ac(uint param_1)

{
  _DAT_20002f8c = 1 << (param_1 & 0xff) | _DAT_20002f8c;
  return;
}



/* FUN_100037c0 at 100037c0 */

void FUN_100037c0(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  do {
    if ((param_1 >> (uVar1 & 0xff) & 1) != 0) {
      FUN_100037ac(uVar1 & 0xff);
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 != 0xc);
  return;
}



/* FUN_100037e0 at 100037e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100037e0(void)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  
  _DAT_20002f8c = 0;
  FUN_10003788();
  _DAT_20003300 = _DAT_20003300 + 1 & 0x1fff;
  uVar3 = (uint)_DAT_2000318a;
  uVar4 = uVar3 + 1 & 0x3fff;
  _DAT_2000318a = (short)uVar4;
  uVar2 = (ushort)(uVar4 >> 3);
  uVar1 = uVar2 & 0x1ff;
  if ((int)((uVar3 + 1) * 0x100000) < 0) {
    _DAT_20003188 = uVar1 - 0x100;
  }
  else {
    _DAT_20003188 = 0xff - uVar1;
  }
  _DAT_20003186 = ~uVar2 & 0xff;
  _DAT_20003184 = ~(ushort)(uVar4 << 3) & 0xff;
  return;
}



/* FUN_1000384c at 1000384c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000384c(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int *piVar13;
  uint *puVar14;
  int iVar15;
  uint local_30;
  int *local_2c;
  byte *local_28;
  byte *local_24;
  
  uVar3 = _DAT_20002f8c;
  uVar7 = (uint)DAT_20004015;
  puVar14 = (uint *)&DAT_20002cbc;
  piVar13 = (int *)&DAT_20002c8c;
  uVar8 = (uint)DAT_20003ff0;
  local_24 = &DAT_20003ff1;
  local_28 = &DAT_20003fe4;
  local_2c = (int *)&DAT_20002c5c;
  local_30 = 0;
  do {
    uVar4 = (uint)*(byte *)(local_30 + 0x20004009) * 0x10000;
    if ((uVar7 == 0) || (uVar9 = uVar3 >> (local_30 & 0xff), (uVar9 & 1) != 0)) {
      bVar1 = *local_28;
      *local_2c = (uint)bVar1 << 0x10;
      bVar2 = *local_24;
      *puVar14 = uVar4;
      iVar10 = (uint)bVar2 << 0x10;
      *piVar13 = iVar10;
      uVar9 = uVar4;
      iVar11 = (uint)bVar1 << 0x10;
    }
    else {
      uVar5 = *puVar14;
      if ((int)uVar5 < (int)uVar4) {
        uVar5 = uVar5 + *(int *)(&DAT_10028f1c + uVar7 * 4);
        uVar9 = uVar9 & 1;
        if ((-1 < (int)uVar5) && (uVar9 = uVar5, (int)uVar4 < (int)uVar5)) {
          uVar9 = uVar4;
        }
        *puVar14 = uVar9;
      }
      else {
        uVar9 = uVar5;
        if ((int)uVar4 < (int)uVar5) {
          uVar12 = uVar5 - *(int *)(&DAT_10028f1c + uVar7 * 4);
          uVar9 = uVar4;
          if (((int)uVar4 <= (int)uVar12) && (uVar9 = uVar5, (int)uVar12 < (int)uVar5)) {
            uVar9 = uVar12;
          }
          *puVar14 = uVar9;
        }
      }
      iVar11 = *piVar13;
      iVar6 = (uint)*local_24 * 0x10000;
      if (iVar11 < iVar6) {
        iVar11 = iVar11 + *(int *)(&DAT_10028f1c + uVar7 * 4);
        iVar10 = 0;
        if ((-1 < iVar11) && (iVar10 = iVar11, iVar6 < iVar11)) {
          iVar10 = iVar6;
        }
        *piVar13 = iVar10;
      }
      else {
        iVar10 = iVar11;
        if (iVar6 < iVar11) {
          iVar15 = iVar11 - *(int *)(&DAT_10028f1c + uVar7 * 4);
          iVar10 = iVar6;
          if ((iVar6 <= iVar15) && (iVar10 = iVar11, iVar15 < iVar11)) {
            iVar10 = iVar15;
          }
          *piVar13 = iVar10;
        }
      }
      iVar6 = (uint)*local_28 * 0x10000;
      iVar11 = *local_2c;
      if (iVar11 < iVar6) {
        iVar15 = iVar11 + *(int *)(&DAT_10028f1c + uVar7 * 4);
        iVar11 = 0;
        if ((-1 < iVar15) && (iVar11 = iVar15, iVar6 < iVar15)) {
          iVar11 = iVar6;
        }
        *local_2c = iVar11;
      }
      else if (iVar6 < iVar11) {
        iVar15 = iVar11 - *(int *)(&DAT_10028f1c + uVar7 * 4);
        if ((iVar6 <= iVar15) && (iVar6 = iVar11, iVar15 < iVar11)) {
          iVar6 = iVar15;
        }
        *local_2c = iVar6;
        iVar11 = iVar6;
      }
    }
    uVar4 = local_30 + 1;
    local_24 = local_24 + 1;
    local_28 = local_28 + 1;
    *(uint *)(local_30 * 4 + 0x20002c2c) =
         uVar8 * ((int)uVar9 >> 0x10) & 0xff00 | (int)(uVar8 * (iVar11 >> 0x10)) >> 8 & 0xffU |
         uVar8 * (iVar10 >> 0x10) * 0x100 & 0xff0000;
    local_2c = local_2c + 1;
    puVar14 = puVar14 + 1;
    piVar13 = piVar13 + 1;
    local_30 = uVar4;
  } while (uVar4 != 0xc);
  return;
}



/* FUN_10003a04 at 10003a04 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10003a04(void)

{
  DAT_20003ff0 = 0x43;
  FUN_10003788();
  DAT_20004015 = 0;
  _DAT_20002f8c = 0;
  FUN_1000384c();
  DAT_20003fe3 = 0;
  return;
}



/* FUN_10003a34 at 10003a34 */

void FUN_10003a34(void)

{
  while (DAT_200040ff == '\0') {
    FUN_1001c402(1);
  }
  return;
}



/* FUN_10003a4c at 10003a4c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10003a4c(void)

{
  FUN_100172e8(0x200014ec,"Doboz");
  FUN_100172ee(0x200014ec,&DAT_100277a6);
  FUN_100178ac(*_DAT_20001414);
  _DAT_20001418 = 1;
  DAT_2000141a = 0;
  _DAT_20001424 = 0;
  _DAT_20001420 = 0;
  _DAT_20001428 = 0xffff;
  _DAT_2000142c = 0xffff;
  _DAT_200014c0 = FUN_1001c428();
  DAT_200014b8 = 0;
  _DAT_200014bc = 0;
  _DAT_20001434 = 0;
  DAT_20003fdf = 0xff;
  DAT_20003fde = 1;
  DAT_20001430 = 0;
  DAT_20003fdd = 0xff;
  DAT_20004020 = 0;
  DAT_20004022 = 0;
  DAT_20004023 = 0;
  DAT_2000401f = 0;
  DAT_20004021 = 0;
  return;
}



/* FUN_10003af4 at 10003af4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10003af4(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  char cVar6;
  
  DAT_20003f80 = 0;
  bVar1 = *(byte *)(param_1 * 8 + 0x20003f6d + param_2);
  if (bVar1 != 0) {
    DAT_20003f7f = 1;
  }
  bVar2 = *(byte *)(param_1 * 8 + 0x20004103 + param_2);
  if (DAT_20003f7f == 0) {
    _DAT_20002c20 = _DAT_20002c1c + _DAT_20002c20;
    if ((_DAT_20002c1c <= _DAT_20002c20) || (DAT_20003f7d = DAT_20003f7d ^ 1, DAT_20003f7d == 0))
    goto LAB_10003c9e;
    DAT_20003f80 = 1;
    pcVar4 = &DAT_20003f6c;
    cVar6 = DAT_20003f6c + '\x01';
  }
  else {
    if (DAT_20003f7f == 1) {
      if (DAT_20004024 != '\0') {
        if ((DAT_20004020 != '\0') &&
           (DAT_2000401f = DAT_2000401f + 1, (byte)(&DAT_10028eea)[DAT_20004021] <= DAT_2000401f)) {
          DAT_2000401f = 0;
          DAT_20003f80 = DAT_20003f7f;
          DAT_20003f6c = DAT_20003f6c + '\x01';
        }
        if (DAT_20004022 != '\0') {
          DAT_2000401f = 0;
          DAT_2000401e = '\x01';
          DAT_20004023 = '\0';
        }
        cVar6 = '\0';
        DAT_20003f7d = DAT_20004023 == '\0' && DAT_2000401f < (byte)(&DAT_10028ee2)[DAT_20004021];
        pcVar4 = &DAT_20004022;
        DAT_20004020 = '\0';
        goto LAB_10003b4a;
      }
      uVar5 = (uint)DAT_20003f9b;
      if (uVar5 < 0xb) {
        _DAT_20002c20 = _DAT_20002c20 + 1;
        if ((_DAT_20002cfc <= _DAT_20002c20) &&
           (_DAT_20002c20 = 0, DAT_20003fbd < (byte)(&DAT_10028f04)[uVar5])) {
          DAT_20003fbd = DAT_20003fbd + 1;
          DAT_20003f7d = DAT_20003f7d ^ 1;
          if (uVar5 != 0) {
            DAT_20003f80 = DAT_20003f7d;
          }
          DAT_20003f6c = DAT_20003f6c + '\x01';
        }
        _DAT_2000280c = _DAT_2000280c + 1;
        if ((bVar1 == 0) || (DAT_20003fd8 != 0)) {
          if (uVar5 != 0) goto LAB_10003c9e;
        }
        else {
          DAT_20003f9c = DAT_20003f9c + 1;
          if ((byte)(&DAT_10028f0f)[uVar5] <= DAT_20003f9c) {
            uVar3 = _DAT_2000280c >> 1;
            if (uVar5 - 1 < 10) {
                    /* WARNING: Subroutine does not return */
              FUN_10027708(uVar5 - 1);
            }
            _DAT_20002c20 = 0;
            DAT_20003f9c = 0;
            DAT_20003f80 = 1;
            _DAT_2000280c = 0;
            DAT_20003f7d = 1;
            DAT_20003fbd = 0;
            DAT_20003f6c = DAT_20003f6c + '\x01';
            _DAT_20002cfc = uVar3;
          }
          if (uVar5 != 0) goto LAB_10003c9e;
          DAT_20003f80 = 1;
        }
        DAT_20003f7d = bVar1;
        goto LAB_10003c9e;
      }
    }
    uVar5 = _DAT_20002c20;
    if ((bVar2 != 0) && (DAT_20003fd8 != bVar1)) {
      uVar5 = _DAT_20002c20 + 1;
      if (uVar5 < 0x18) {
        if ((uVar5 != 0) &&
           (((*(uint *)(&DAT_10028ef4 + (DAT_20003f9b - 0xb) * 4) >> (uVar5 & 0xff) & 1) == 0 ||
            ((*(uint *)(&DAT_10028ef4 + (DAT_20003f9b - 0xb) * 4) >> (_DAT_20002c20 & 0xff) & 1) !=
             0)))) goto LAB_10003d0a;
      }
      else {
        _DAT_20002c20 = 0;
        uVar5 = _DAT_20002c20;
      }
      _DAT_20002c20 = uVar5;
      DAT_20003f80 = 1;
      uVar5 = _DAT_20002c20;
    }
LAB_10003d0a:
    _DAT_20002c20 = uVar5;
    DAT_20003f7d = (byte)(*(uint *)(&DAT_10028ef4 + (DAT_20003f9b - 0xb) * 4) >>
                         (_DAT_20002c20 & 0xff)) & bVar2 & 1;
    DAT_20003f7e = bVar2;
    if (DAT_20003f80 == 0) goto LAB_10003c9e;
    pcVar4 = &DAT_20003f6c;
    cVar6 = DAT_20003f6c + '\x01';
  }
LAB_10003b4a:
  *pcVar4 = cVar6;
LAB_10003c9e:
  if (((bVar2 != 0) && (DAT_20003fe2 == '\0')) || (DAT_2000401e != '\0')) {
    DAT_20003f7d = 1;
    DAT_20003f6c = '\0';
    DAT_20003f80 = 1;
    DAT_20003f9c = 0;
    DAT_20003fbd = 0;
    _DAT_20002c20 = 0;
    _DAT_2000280c = 0;
    DAT_2000401e = '\0';
    DAT_20003f84 = 1;
  }
  DAT_20003fe2 = bVar2;
  DAT_20003fd8 = bVar1;
  return;
}



/* FUN_10003dcc at 10003dcc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10003dcc(void)

{
  undefined8 uVar1;
  
  uVar1 = FUN_1001ea84();
  uVar1 = FUN_1001e96a((int)uVar1,(int)((ulonglong)uVar1 >> 0x20),0,0x4072c000);
  uVar1 = FUN_1001e96a(0xffeb074a,0x40ddcd64,(int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  FUN_1001e96a(0xffe00000,0x41efffff,(int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
  _DAT_20002c1c = FUN_1001eafc();
  DAT_20003f7f = 0;
  return;
}



/* FUN_10003e20 at 10003e20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10003e20(void)

{
  _DAT_200031a6 = 0x4b0;
  DAT_20003f9b = 0;
  DAT_20003f7f = 0;
  _DAT_20002c1c = 0x89705;
  DAT_20003f84 = 1;
  return;
}



/* FUN_10003e58 at 10003e58 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_10003e58(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  _DAT_20002f44 = _DAT_20002f44 + 1;
  if ((param_1 != 0) && (DAT_200041c9 == '\0')) {
    uVar1 = (uint)DAT_200041cb;
    DAT_200041cc = DAT_200041cb;
    if (DAT_20004025 == '\r') {
      iVar2 = (_DAT_20002cf4 >> 3) + uVar1;
      if (iVar2 < 0x20) {
        DAT_200041cc = (byte)iVar2 & (char)~(byte)((uint)iVar2 >> 0x18) >> 7;
      }
      else {
        DAT_200041cc = 0x1f;
      }
      uVar1 = (uint)DAT_200041cc;
    }
    if (DAT_20004026 == '\r') {
      iVar2 = (_DAT_20002cf8 >> 3) + uVar1;
      if (iVar2 < 0x20) {
        DAT_200041cc = (byte)iVar2 & (char)~(byte)((uint)iVar2 >> 0x18) >> 7;
      }
      else {
        DAT_200041cc = 0x1f;
      }
      uVar1 = (uint)DAT_200041cc;
    }
    uVar3 = _DAT_20002f44 >> 6;
    if (DAT_200041c8 != '\0') {
      iVar2 = FUN_1001c3c8();
      uVar1 = iVar2 + 1;
    }
    _DAT_20002f4c = uVar3 * uVar1;
    DAT_200041c7 = DAT_200041c7 + 1;
    _DAT_20002f44 = 0;
    if (DAT_200041ca < DAT_200041c7) {
      DAT_200041c7 = 0;
    }
    if (DAT_200041ca == DAT_200041c7) {
      _DAT_20002f48 = _DAT_20002f4c;
      _DAT_20002f50 = _DAT_20002f4c;
    }
    if (DAT_200041cd != '\0') {
      DAT_200041cd = '\0';
    }
  }
  if (((DAT_200041c7 == DAT_200041ca) && (DAT_200041cc != 0)) && (DAT_200041cd == '\0')) {
    if (_DAT_20002f50 != 0) {
      _DAT_20002f50 = _DAT_20002f50 + -1;
    }
    if ((param_1 == 0) && (_DAT_20002f48 != 0)) {
      _DAT_20002f48 = _DAT_20002f48 + -1;
    }
    DAT_200041ce = 1;
    if ((_DAT_20002f50 != 0) || (_DAT_20002f48 == 0)) {
      DAT_200041ce = 0;
    }
  }
  else {
    DAT_200041ce = (char)param_1;
  }
  DAT_200041c9 = (char)param_1;
  return CONCAT44(&DAT_200041c9,param_1);
}



/* FUN_10003f94 at 10003f94 */

void FUN_10003f94(void)

{
  DAT_200041c7 = 0;
  DAT_200041cd = 1;
  return;
}



/* FUN_10003fac at 10003fac */

void FUN_10003fac(void)

{
  DAT_200041cb = 0;
  DAT_200041ca = 1;
  DAT_200041c8 = 0;
  return;
}



/* FUN_10003fcc at 10003fcc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10003fcc(void)

{
  undefined2 uVar1;
  uint uVar2;
  undefined2 auStack_20 [10];
  
  FUN_1001f4d4(auStack_20,&DAT_1002a998,0x10);
  uVar2 = 0x3fff - _DAT_20002d08;
  if ((int)(uVar2 * 0x100000) < 0) {
    uVar1 = auStack_20[uVar2 >> 8 & 7];
    if (0x7fe < _DAT_20002d08) {
      uVar2 = (_DAT_20002d08 & 0x3fff) >> 7;
LAB_1000402c:
      FUN_10003732(uVar1,uVar2);
      goto LAB_10004004;
    }
  }
  else {
    uVar1 = auStack_20[~(uVar2 >> 8 & 0xffff) & 7];
    if (0x7fe < _DAT_20002d08) {
      uVar2 = ~(_DAT_20002d08 >> 7) & 0x7f;
      goto LAB_1000402c;
    }
  }
  FUN_1000364a(uVar1,0,0);
LAB_10004004:
  FUN_100037c0(uVar1);
  DAT_20004015 = 1;
  return;
}



/* FUN_10004128 at 10004128 */

undefined1 FUN_10004128(int param_1)

{
  undefined1 auStack_1c [16];
  
  FUN_1001f4d4(auStack_1c,&DAT_1002a9b4,0xc);
  return auStack_1c[param_1];
}



/* FUN_10004144 at 10004144 */

void FUN_10004144(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  do {
    uVar1 = FUN_10004128(uVar2 & 0xff);
    if (DAT_20003fc8 == uVar2) {
      FUN_10003674(uVar1,10);
      FUN_100037ac(uVar1);
    }
    else {
      FUN_10003674(uVar1,0);
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 0xc);
  DAT_20004015 = 2;
  return;
}



/* FUN_1000478c at 1000478c */

void FUN_1000478c(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 0;
  do {
    uVar3 = uVar2 & 0xff;
    uVar1 = FUN_10004128(uVar3);
    uVar2 = uVar2 + 1;
    FUN_10003674(uVar1,uVar3);
  } while (uVar2 != 0xc);
  DAT_20004015 = 2;
  return;
}



/* FUN_100047b0 at 100047b0 */

uint FUN_100047b0(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 < 0xb) {
    uVar1 = 0x54aU >> (param_1 & 0xff) & 1;
  }
  return uVar1;
}



/* FUN_100047c8 at 100047c8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100047c8(void)

{
  if (_DAT_20002d08 != 0) {
    _DAT_20002d08 = _DAT_20002d08 + -1;
  }
  return;
}



/* FUN_10004d00 at 10004d00 */

undefined4 FUN_10004d00(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((((2 < param_1) && (uVar1 = 1, 8 < param_1)) && (uVar1 = 2, 0x34 < param_1)) &&
      (((uVar1 = 3, 0x37 < param_1 && (uVar1 = 4, 0x39 < param_1)) &&
       ((uVar1 = 5, 0x3d < param_1 && ((uVar1 = 6, 0x3f < param_1 && (uVar1 = 7, 0x46 < param_1)))))
       ))) && ((uVar1 = 8, 0x4d < param_1 &&
               ((((uVar1 = 9, 0x50 < param_1 && (uVar1 = 10, 0x56 < param_1)) &&
                 (uVar1 = 0xb, param_1 != 0x59)) && (uVar1 = 0xc, param_1 != 0x5a)))))) {
    uVar1 = 2;
  }
  return uVar1;
}



/* FUN_10004d54 at 10004d54 */

void FUN_10004d54(uint param_1)

{
  if (param_1 < 0xd) {
                    /* WARNING: Subroutine does not return */
    FUN_10027708();
  }
  return;
}



/* FUN_10004dc0 at 10004dc0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004dc0(void)

{
  FUN_1001c7f0(3,2);
  FUN_1001c7f0(6,2);
  FUN_1001c7f0(0x1a,0);
  FUN_1001cdcc();
  FUN_1001ce74(0x1a,0x1f);
  FUN_1001cea4(0x1a,0);
  FUN_1001cee8(0x1a,0);
  _DAT_4004d000 = _DAT_4004c000 & 0x7000;
  _DAT_4004d008 = (_DAT_4004c008 ^ 0x1000001) & 0xf00000f;
  _DAT_4004c010 = 0;
  _DAT_4004e000 = 8;
  FUN_1001c7f0(7,1);
  FUN_1001ce74(4);
  FUN_1001ce74(5,4);
  FUN_1001c7f0(0xb,2);
  FUN_1001c7f0(0xc,2);
  FUN_1001c7f0(10,2);
  FUN_1001c7f0(0x1b,2);
  FUN_1001c7f0(0x1c,2);
  FUN_1001c7f0(0x16,1);
  FUN_1001c7f0(0x15,1);
  return;
}



/* FUN_10004e90 at 10004e90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004e90(void)

{
  _DAT_4005002c = 0x10;
  _DAT_40050038 = 0xfff;
  _DAT_400520a8 = 4;
  FUN_1001cfc8(4,0x10003229);
  FUN_1001cf68(4,1);
  _DAT_40051028 = ~_DAT_40050028 & 1;
  return;
}



/* FUN_10004ed8 at 10004ed8 */

void FUN_10004ed8(void)

{
  DAT_20003f68 = 1;
  DAT_20003f69 = 1;
  DAT_200041c6 = 1;
  return;
}



/* FUN_10004ef0 at 10004ef0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10004ef0(void)

{
  _DAT_200031de = 0xf55;
  _DAT_2000317a = 0xf55;
  _DAT_200031e0 = 0xbaa;
  _DAT_2000317c = 0xbaa;
  _DAT_200031e2 = 0x7ff;
  _DAT_2000317e = 0x7ff;
  _DAT_200031e4 = 0x453;
  _DAT_20003180 = 0x453;
  _DAT_20003182 = 0xa7;
  _DAT_200031e6 = 0xa7;
  _DAT_2000315e = 0x800;
  _DAT_200032fe = 0x177;
  _DAT_2000322e = 0x140;
  _DAT_2000320a = 500;
  _DAT_20003208 = 0x2e4;
  DAT_20000879 = 2;
  DAT_200041f1 = 0;
  DAT_2000403a = 0;
  DAT_20003f87 = 0;
  DAT_20004024 = 0;
  DAT_20004147 = 0;
  DAT_20000878 = 0;
  return;
}



/* FUN_10004fa0 at 10004fa0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_10004fa0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  ushort *puVar3;
  ushort *puVar4;
  
  FUN_1001c258(&DAT_200013a8,0x1000);
  FUN_1001c2b0(&DAT_200013a8,0,(_DAT_2000315e >> 4 & 0xfff0 | (ushort)DAT_20003f87 << 3) & 0xff | 1,
               (ushort)DAT_20003f87 << 3,param_1,param_2,param_3);
  FUN_1001c2b0(&DAT_200013a8,1,DAT_2000315e);
  puVar4 = (ushort *)&DAT_200031de;
  puVar3 = (ushort *)&DAT_2000317a;
  iVar2 = 2;
  do {
    FUN_1001c2b0(&DAT_200013a8,iVar2,(char)*puVar4);
    FUN_1001c2b0(&DAT_200013a8,iVar2 + 1,(char)*puVar3);
    iVar1 = iVar2 + 2;
    iVar2 = iVar2 + 3;
    FUN_1001c2b0(&DAT_200013a8,iVar1,*puVar4 >> 8 & 0xf | *puVar3 >> 4 & 0xf0);
    puVar4 = puVar4 + 1;
    puVar3 = puVar3 + 1;
  } while (iVar2 != 0x11);
  FUN_1001c2b0(&DAT_200013a8,0x11,DAT_200032fe);
  FUN_1001c2b0(&DAT_200013a8,0x12,DAT_2000322e);
  FUN_1001c2b0(&DAT_200013a8,0x13,DAT_2000320a);
  puVar3 = (ushort *)&DAT_20003208;
  FUN_1001c2b0(&DAT_200013a8,0x14,DAT_20003208);
  FUN_1001c2b0(&DAT_200013a8,0x15,
               (_DAT_200032fe & 0x3ff) >> 8 | _DAT_2000322e >> 6 & 0xc | _DAT_2000320a >> 4 & 0x30 |
               *puVar3 >> 2 & 0xc0);
  FUN_1001c2b0(&DAT_200013a8,0x16,DAT_20000879 & 7 | DAT_2000403a << 5 | (DAT_200041f1 & 3) << 3);
  FUN_1001c2b0(&DAT_200013a8,0x17,DAT_20004147 << 1 | DAT_20004024);
  iVar2 = 0x18;
  do {
    iVar1 = iVar2 + 1;
    FUN_1001c2b0(&DAT_200013a8,iVar2,0);
    iVar2 = iVar1;
  } while (iVar1 != 0x1f);
  FUN_1001c2b0(&DAT_200013a8,0x31,DAT_20000878);
  FUN_1001c2d4(&DAT_200013a8);
  FUN_1001c388(&DAT_200013a8);
  DAT_20004122 = 0;
  return CONCAT44(puVar3,param_1);
}



/* FUN_10005124 at 10005124 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_10005124(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  
  puVar3 = (ushort *)&DAT_20003234;
  iVar6 = 0;
  _DAT_20003234 = _DAT_200031de;
  _DAT_20003264 = _DAT_200031e0;
  _DAT_20003294 = _DAT_200031e2;
  _DAT_200032c4 = _DAT_200031e4;
  _DAT_200032f4 = _DAT_200031e6;
  do {
    uVar7 = FUN_1001ea84((uint)*puVar3 - (uint)puVar3[0x18]);
    FUN_1001e96a((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),0,0x40380000,param_1,param_2,param_3);
    param_1 = FUN_1001eb84();
    iVar4 = 1;
    do {
      param_2 = FUN_1001f330(*puVar3);
      uVar2 = FUN_1001f330(iVar4);
      uVar2 = FUN_1001f29e(uVar2,param_1);
      FUN_1001f26a(param_2,uVar2);
      uVar1 = FUN_1001f3d8();
      iVar5 = iVar4 + 1;
      puVar3[iVar4] = uVar1;
      iVar4 = iVar5;
    } while (iVar5 != 0x18);
    iVar6 = iVar6 + 0x18;
    puVar3 = puVar3 + 0x18;
  } while (iVar6 != 0x60);
  return CONCAT44(param_2,param_1);
}



/* FUN_100051a8 at 100051a8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100051a8(void)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined *puVar9;
  undefined1 *puVar10;
  byte bVar11;
  byte bVar12;
  uint uVar13;
  uint local_24;
  
  uVar7 = _DAT_20003212 & 0xfff;
  bVar2 = false;
  DAT_2000402f = '\0';
  if (DAT_2000405c == '\x03') {
    if ((_DAT_20003212 & 0xfff) == 0) {
      DAT_20003fb9 = (byte)uVar7;
      goto LAB_100051d6;
    }
    uVar6 = (uint)DAT_20003fb9;
    bVar1 = false;
    uVar4 = 0;
    cVar3 = '\0';
    uVar5 = uVar6;
    do {
      if (((int)uVar7 >> (uVar4 & 0xff) & 1U) != 0) {
        cVar3 = cVar3 + '\x01';
        bVar2 = true;
        if (((int)~(uint)_DAT_200031a8 >> (uVar4 & 0xff) & 1U) != 0) {
          uVar8 = uVar5 + 1;
          if (0xd < uVar8) {
            uVar8 = 0xd;
          }
          uVar5 = uVar8 & 0xff;
          *(char *)(uVar8 + 0x20004042) = (char)uVar4;
          bVar2 = true;
          bVar1 = true;
        }
      }
      if ((((int)~uVar7 >> (uVar4 & 0xff) & 1U) != 0) &&
         (uVar8 = (int)(uint)_DAT_200031a8 >> (uVar4 & 0xff), uVar13 = uVar8 & 1, (uVar8 & 1) != 0))
      {
        local_24 = 0;
        for (; (int)uVar13 <= (int)uVar5; uVar13 = uVar13 + 1) {
          if (*(byte *)(uVar13 + 0x20004042) == uVar4) {
            local_24 = uVar13 & 0xff;
          }
        }
        puVar10 = (undefined1 *)(local_24 + 0x20004042);
        for (; (int)local_24 < 0xd; local_24 = local_24 + 1) {
          *puVar10 = puVar10[1];
          puVar10 = puVar10 + 1;
        }
        uVar5 = uVar5 - 1 & (int)-uVar5 >> 0x1f & 0xff;
        bVar1 = true;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 != 0xc);
    if (bVar2) {
      DAT_2000402f = cVar3;
    }
    if (bVar1) {
      DAT_20003fb9 = (byte)uVar5;
      uVar6 = uVar5;
    }
    if (uVar6 == 0) goto LAB_100051d6;
    uVar5 = (uint)*(byte *)(uVar6 + 0x20004042);
  }
  else {
    cVar3 = '\0';
    uVar5 = 0xff;
    bVar12 = 0;
    uVar6 = 0;
    do {
      if (((int)uVar7 >> (uVar6 & 0xff) & 1U) != 0) {
        cVar3 = cVar3 + '\x01';
        if (DAT_2000405c == '\x01') {
          puVar9 = &DAT_10028ed6;
LAB_1000533a:
          bVar2 = true;
          bVar11 = puVar9[uVar6];
          if ((byte)puVar9[uVar6] < bVar12) goto LAB_10005328;
        }
        else {
          if (DAT_2000405c == '\x02') {
            puVar9 = &DAT_10028eca;
            goto LAB_1000533a;
          }
          bVar2 = true;
          if ((DAT_2000405c != '\0') ||
             (bVar11 = bVar12, ((int)~(uint)_DAT_200031a8 >> (uVar6 & 0xff) & 1U) == 0))
          goto LAB_10005328;
        }
        uVar5 = uVar6 & 0xff;
        bVar2 = true;
        bVar12 = bVar11;
      }
LAB_10005328:
      uVar6 = uVar6 + 1;
    } while (uVar6 != 0xc);
    if (bVar2) {
      DAT_2000402f = cVar3;
    }
  }
  if (uVar5 != 0xff) {
    if ((DAT_20003fc8 != uVar5) && (DAT_20003fca == '\0')) {
      _DAT_20002c24 = 0x28;
    }
    DAT_20003fc8 = (byte)uVar5;
  }
LAB_100051d6:
  DAT_20003fcb = _DAT_20002c24 != 0;
  if (DAT_20003fcb) {
    _DAT_20002c24 = _DAT_20002c24 + -1;
  }
  if ((((int)uVar7 >> DAT_20003fc8 & 1U) == 0) ||
     ((DAT_20003fc9 = 1, DAT_20003fca == '\0' && (DAT_20003fcb)))) {
    DAT_20003fc9 = 0;
  }
  _DAT_200031a8 = (short)uVar7;
  return;
}



/* FUN_10005380 at 10005380 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10005380(void)

{
  uint uVar1;
  
  _DAT_200031a8 = 0;
  _DAT_20003212 = 0;
  DAT_2000402f = 0;
  uVar1 = (uint)DAT_20004128;
  FUN_1001f4c8(&DAT_20003214,0,0x18);
  *(undefined1 *)(uVar1 + 0x200040f3) = 0;
  return;
}



/* FUN_100053bc at 100053bc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100053bc(void)

{
  FUN_1001f4c8(0x20004050,0,0xc);
  FUN_1001f4c8(&DAT_2000405d,8,0xc);
  DAT_20000842 = 0x24;
  DAT_2000405c = 0;
  DAT_20003fca = 0;
  DAT_20003fc8 = 0;
  DAT_2000402f = 0;
  _DAT_200031a8 = 0;
  DAT_20003fc9 = 0;
  DAT_20003fcb = 0;
  _DAT_20002c24 = 0;
  return;
}



/* FUN_10005428 at 10005428 */

ushort FUN_10005428(int param_1,uint param_2)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  
  uVar2 = *(ushort *)(&DAT_20003234 + param_1 * 2);
  if (param_2 != 8) {
    if (param_2 < 8) {
      param_2 = param_2 + 8;
      uVar1 = (uint)*(ushort *)(&DAT_20003234 + (param_1 + -1) * 2);
      uVar3 = (uint)uVar2;
    }
    else {
      param_2 = param_2 - 8;
      uVar3 = (uint)*(ushort *)(&DAT_20003234 + (param_1 + 1) * 2);
      uVar1 = (uint)uVar2;
    }
    uVar2 = (ushort)((uVar3 * 0x100 + uVar1 * -0x100 >> 4) * (param_2 & 0xff) + uVar1 * 0x100 >> 8);
  }
  return uVar2;
}



/* FUN_10005468 at 10005468 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10005468(void)

{
  DAT_20004075 = 0;
  _DAT_20003166 = 0;
  DAT_20004154 = 1;
  DAT_20003fb8 = 0;
  return;
}



/* FUN_10005490 at 10005490 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10005490(uint param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  byte bVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int local_34;
  int local_30;
  uint local_2c;
  
  if (DAT_20003dde == '\0') {
    _DAT_20003190 = (ushort)param_1;
  }
  else {
    param_1 = (uint)_DAT_20003190;
  }
  bVar2 = false;
  DAT_20003c5b = 0;
  uVar6 = (uint)DAT_20003c51;
  bVar1 = (&DAT_20003c52)[uVar6];
  uVar7 = (uint)DAT_20003deb;
  iVar3 = 0;
  uVar8 = 0;
  do {
    if ((bVar1 & 0xfd) == 0) {
      if (((int)param_1 >> (uint)(byte)(&DAT_10028ed6)[iVar3] & 1U) != 0) {
        *(undefined1 *)(uVar8 + 0x20003c62) = (&DAT_10028ed6)[iVar3];
        *(byte *)(uVar8 + 0x20003df4) = bVar1 & 0xfd;
LAB_100054f8:
        uVar8 = uVar8 + 1 & 0xff;
        bVar2 = true;
      }
    }
    else if (bVar1 == 5) {
      if (iVar3 < (int)uVar7) {
        bVar4 = *(byte *)(iVar3 + 0x20003ddf);
        *(undefined1 *)(uVar8 + 0x20003df4) = 0;
        *(byte *)(uVar8 + 0x20003c62) = bVar4;
        bVar2 = true;
        uVar8 = uVar8 + 1 & 0xff;
        _DAT_20003190 = _DAT_20003190 | (ushort)(1 << (uint)bVar4);
      }
    }
    else if (((int)param_1 >> (uint)(byte)(&DAT_10028eca)[iVar3] & 1U) != 0) {
      *(undefined *)(uVar8 + 0x20003c62) = (&DAT_10028eca)[iVar3];
      *(undefined1 *)(uVar8 + 0x20003df4) = 0;
      goto LAB_100054f8;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 0xc);
  if (bVar2) {
    DAT_20003c5b = (byte)uVar8;
  }
  bVar4 = DAT_20003c5b;
  if (bVar1 - 2 < 2) {
    bVar2 = false;
    uVar8 = (uint)DAT_20003c5b;
    uVar7 = uVar8;
    for (iVar3 = uVar8 - 2; 0 < iVar3; iVar3 = iVar3 + -1) {
      *(undefined1 *)(uVar7 + 0x20003c62) = *(undefined1 *)(iVar3 + 0x20003c62);
      *(undefined1 *)(uVar7 + 0x20003df4) = 0;
      bVar2 = true;
      uVar7 = uVar7 + 1 & 0xff;
    }
    if (bVar2) {
      if (uVar8 < 2) {
        bVar4 = 2;
      }
      DAT_20003c5b = (char)(uVar8 - 2) + bVar4;
    }
  }
  bVar1 = DAT_20003c5b;
  uVar7 = (uint)(byte)(&DAT_20003c5c)[uVar6];
  if (uVar7 == 0) goto LAB_100055c0;
  uVar9 = (uint)DAT_20003c5b;
  cVar5 = (&DAT_20003df0)[uVar6];
  uVar8 = (uint)(byte)(&DAT_20003dec)[DAT_20004121];
  if (uVar8 - 2 < 2) {
    uVar7 = (uVar7 & 0x7f) << 1;
    if (uVar8 == 3) {
LAB_10005616:
      cVar5 = -(&DAT_20003df0)[uVar6];
    }
  }
  else if (uVar8 == 1) goto LAB_10005616;
  bVar2 = false;
  local_2c = uVar9;
  for (local_34 = 1; local_34 <= (int)uVar7; local_34 = local_34 + 1) {
    local_30 = 0;
    while( true ) {
      uVar6 = local_2c + local_30 & 0xff;
      if ((int)uVar9 <= local_30) break;
      *(undefined1 *)(uVar6 + 0x20003c62) = *(undefined1 *)(local_30 + 0x20003c62);
      *(char *)(uVar6 + 0x20003df4) = cVar5;
      local_30 = local_30 + 1;
      bVar2 = true;
    }
    if (uVar8 < 4) {
                    /* WARNING: Subroutine does not return */
      FUN_10027708();
    }
    local_2c = uVar9 + local_2c & 0xff;
  }
  if (bVar2) {
    DAT_20003c5b = bVar1 * ((char)uVar7 + '\x01');
  }
LAB_100055c0:
  if (param_2 != 0) {
    FUN_10005468();
    DAT_20003dde = '\0';
    DAT_200041f0 = 0;
  }
  _DAT_200031ba = 0;
  _DAT_200031bc = 0;
  return;
}



/* FUN_100056dc at 100056dc */

uint FUN_100056dc(int param_1,int param_2,uint param_3)

{
  return ((int)(*(uint *)(&DAT_10028a2c +
                         ((uint)*(ushort *)(&DAT_10028a0a + param_1 * 2) + param_2) * 4) & 0xffff)
          >> ((param_1 + 1) - param_3 & 0xff) |
         (*(uint *)(&DAT_10028a2c + ((uint)*(ushort *)(&DAT_10028a0a + param_1 * 2) + param_2) * 4)
         & 0xffff) << (param_3 & 0xff)) & 0xffff;
}



/* FUN_10005708 at 10005708 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10005708(void)

{
  _DAT_2000319a = _DAT_2000319a + 1;
  if ((byte)(&DAT_20003f97)[DAT_20004121] < _DAT_2000319a) {
    _DAT_2000319a = 0;
  }
  return;
}



/* FUN_10005730 at 10005730 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10005730(void)

{
  _DAT_2000319a = 0;
  FUN_10003f94();
  return;
}



/* FUN_10005744 at 10005744 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_10005744(void)

{
  return (int)(uint)_DAT_2000319c >> (_DAT_2000319a & 0xff) & 1;
}



/* FUN_1000575c at 1000575c */

void FUN_1000575c(int param_1)

{
  (&DAT_20003f97)[param_1] = 0xf;
  (&DAT_20003f8e)[param_1] = 0x10;
  (&DAT_20003f93)[param_1] = 0;
  return;
}



/* FUN_1000577c at 1000577c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000577c(void)

{
  uint uVar1;
  uint uVar2;
  undefined2 *puVar3;
  
  uVar2 = 0;
  puVar3 = (undefined2 *)&DAT_2000316a;
  DAT_2000403b = 1;
  DAT_20004121 = 0;
  DAT_20003c51 = 0;
  DAT_20004120 = 0;
  DAT_20003c50 = 0;
  DAT_20003deb = 0;
  _DAT_20003168 = 0;
  do {
    (&DAT_20003c57)[uVar2] = 1;
    (&DAT_20003c52)[uVar2] = 0;
    (&DAT_20003c5c)[uVar2] = 0;
    (&DAT_20003df0)[uVar2] = 5;
    (&DAT_20003dec)[uVar2] = 0;
    (&DAT_20003dd6)[uVar2] = 1;
    (&DAT_20003faf)[uVar2] = 0x3f;
    (&DAT_20003dd2)[uVar2] = 0;
    (&DAT_20003dda)[uVar2] = 0;
    FUN_1000575c(uVar2 & 0xff);
    *puVar3 = (short)(0x10 << (uVar2 & 0xff));
    uVar1 = uVar2 & 0xff;
    uVar2 = uVar2 + 1;
    puVar3[4] = (short)(0x100 << uVar1);
    puVar3 = puVar3 + 1;
  } while (uVar2 != 4);
  FUN_10005468();
  FUN_10005730();
  FUN_10003f94();
  return;
}



/* FUN_10005864 at 10005864 */

uint FUN_10005864(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = (param_1 & 0xfff) << (param_2 & 0xff);
  return (uVar1 | uVar1 >> 0xc) & 0xfff;
}



/* FUN_10005874 at 10005874 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_10005874(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  uint uVar2;
  ushort extraout_r1;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if (0x60 < param_1) {
    param_1 = 0x60;
  }
  if (param_2 != 0) {
    FUN_1001e4d0(param_1 & 0xffff,0xc,param_3,param_4,param_4);
    iVar5 = 1 << (extraout_r1 & 0xff);
    uVar2 = FUN_10005864(param_2,param_3);
    uVar4 = 0;
    do {
      uVar3 = iVar5 >> (uVar4 & 0xff);
      sVar1 = (short)uVar4;
      if ((uVar2 & uVar3) != 0) {
        sVar1 = -sVar1;
        _DAT_2000320e = (undefined2)uVar3;
LAB_100058ae:
        return (uint)(ushort)((short)param_1 + sVar1);
      }
      uVar3 = iVar5 << (uVar4 & 0xff);
      if ((uVar2 & uVar3) != 0) {
        _DAT_2000320e = (undefined2)uVar3;
        goto LAB_100058ae;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 != 0xc);
  }
  return param_1 & 0xffff;
}



/* FUN_100058d0 at 100058d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100058d0(void)

{
  DAT_20004125 = 3;
  DAT_2000411e = 0;
  DAT_2000402e = 1;
  _DAT_20000810 = 0xfff;
  return;
}



/* FUN_10005900 at 10005900 */

ulonglong FUN_10005900(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  
  uVar6 = (uint)DAT_2000411e;
  uVar1 = FUN_10005864(*(undefined2 *)((uint)DAT_20004125 * 2 + 0x2000080e),uVar6,
                       (uint)DAT_20004125 * 2,0x2000080e,param_1,param_2,param_3);
  if (uVar1 == 0) {
    uVar1 = 1;
  }
  uVar5 = 0;
  pbVar7 = &DAT_10028ed6;
LAB_1000592e:
  do {
    uVar2 = uVar6;
    do {
      uVar3 = uVar2 + 1;
      uVar8 = (int)(uVar1 & 0xffff) >> (uVar2 & 0xff);
      uVar6 = uVar8 & 1;
      if ((uVar8 & 1) != 0) {
        uVar6 = uVar3 & 0xffff;
        iVar4 = uVar5 * 0xc + uVar2;
        if (0x60 < iVar4) {
          iVar4 = 0x60;
        }
        *(char *)(*pbVar7 + 0x20004050) = (char)iVar4;
        if (0xb < uVar6) {
          uVar6 = 0;
          uVar5 = uVar5 + 1 & 0xffff;
        }
        pbVar7 = pbVar7 + 1;
        if (pbVar7 == &DAT_10028ee2) {
          return CONCAT44(&DAT_10028ee2,uVar1) & 0xffffffff0000ffff;
        }
        goto LAB_1000592e;
      }
      uVar2 = uVar3;
    } while ((uVar3 & 0xffff) < 0xc);
    uVar5 = uVar5 + 1 & 0xffff;
  } while( true );
}



/* FUN_10005990 at 10005990 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10005990(uint param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (uint)_DAT_200031a2;
  if (uVar3 != param_1) {
    uVar3 = param_1 & 0xffff;
    _DAT_200031a2 = (ushort)param_1;
    if (param_2 == 0) {
      _DAT_200031a0 = _DAT_200031a2;
    }
    else {
      uVar2 = uVar3;
      if (DAT_20003fb7 != 0) {
        uVar2 = (uint)_DAT_2000319e;
      }
      _DAT_20002814 = 0;
      _DAT_200031a0 = (ushort)uVar2;
    }
  }
  _DAT_20002814 = *(uint *)(&DAT_10029588 + (uint)DAT_20003fb7 * 4) + _DAT_20002814;
  if (_DAT_20002814 < *(uint *)(&DAT_10029588 + (uint)DAT_20003fb7 * 4)) {
    _DAT_200031a0 = (ushort)uVar3;
  }
  uVar1 = _DAT_200031a0;
  uVar4 = (uint)_DAT_200031a0;
  uVar2 = FUN_10003332(&LAB_1002a796);
  _DAT_2000319e = uVar1 + (short)((int)((uVar3 - uVar4) * (uVar2 >> 1 & 0xffff)) >> 0xf);
  return;
}



/* FUN_10005a08 at 10005a08 */

bool FUN_10005a08(void)

{
  int iVar1;
  
  iVar1 = FUN_1001c3c8(0x3f);
  return iVar1 < (int)(uint)DAT_20003fb4;
}



/* FUN_10005a24 at 10005a24 */

void FUN_10005a24(void)

{
  DAT_20003fb6 = 0;
  DAT_20003fb4 = 0x3f;
  DAT_20003fb5 = 0;
  return;
}



/* FUN_10005a44 at 10005a44 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort FUN_10005a44(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(int *)(&DAT_10029988 + (0xb4 - (uint)DAT_200041db) * 4) << 2;
  uVar4 = (uint)DAT_200041e0;
  uVar3 = uVar4 - 1 & 0xff;
  if (uVar3 < 0xfe) {
    uVar5 = *(int *)(&DAT_10029988 + (0xb4 - (uint)DAT_200041db) * 4) << 1;
  }
  _DAT_20002f7c = uVar5 + _DAT_20002f7c;
  if ((_DAT_20002f7c < uVar5) || (DAT_200041db == 0)) {
    DAT_200041dc = '\x01';
    _DAT_20002f7c = 0xffffffff;
  }
  if ((param_2 != 0) && (DAT_200041dd == '\0')) {
    DAT_200041dc = DAT_200041dd;
    _DAT_20002f7c = 0;
  }
  DAT_200041dd = (char)param_2;
  if (uVar4 == 0) {
    uVar5 = 0x7fffffff;
  }
  else {
    uVar5 = 0;
    if (uVar4 != 0xff) {
      uVar5 = *(int *)(&DAT_10029588 + (0xff - uVar4) * 4) + _DAT_20002f84;
    }
  }
  _DAT_20002f84 = uVar5;
  if ((int)uVar5 < 0) {
    iVar2 = ((uVar5 >> 0x10) - 0x7fff) * -2 + 0xffff;
  }
  else {
    iVar2 = (uVar5 >> 0x10) << 1;
  }
  _DAT_2000322c = (short)iVar2;
  if (uVar3 < 0xfe) {
    if (DAT_200041de == '\0') {
      uVar3 = _DAT_20002f7c >> 0x10;
    }
    else {
      uVar3 = (uint)*(ushort *)(&DAT_1002a392 + (uint)(_DAT_200032fc >> 8) * 2);
    }
  }
  else if (DAT_200041de == '\0') {
    uVar3 = 0xffff - (_DAT_20002f7c >> 0x10);
  }
  else {
    uVar3 = (uint)*(ushort *)(&DAT_1002a392 + (uint)(_DAT_200032fc >> 8) * 2);
  }
  param_1 = param_1 + ((int)((*(ushort *)(&DAT_1002a392 + (uint)DAT_200041da * 2) * uVar3 >> 0x10) *
                            (iVar2 + -0x7fff)) >> 0x16);
  if (param_1 < 0x1000) {
    uVar1 = (ushort)param_1 & (short)~(ushort)((uint)param_1 >> 0x10) >> 0xf;
  }
  else {
    uVar1 = 0xfff;
  }
  return uVar1;
}



/* FUN_10005b7c at 10005b7c */

void FUN_10005b7c(void)

{
  DAT_200041df = 0x54;
  DAT_200041d9 = 0;
  DAT_200041db = 0;
  DAT_200041de = 0;
  return;
}



/* FUN_10005ba4 at 10005ba4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10005ba4(void)

{
  int iVar1;
  
  DAT_2000411f = DAT_2000411e;
  if (DAT_20004025 == '\b') {
    iVar1 = (_DAT_20002cf4 >> 5) + (uint)DAT_2000411e;
    if (iVar1 < 0xc) {
      DAT_2000411f = (byte)iVar1 & (char)~(byte)((uint)iVar1 >> 0x18) >> 7;
    }
    else {
      DAT_2000411f = 0xb;
    }
  }
  if (DAT_20004026 == '\b') {
    iVar1 = (_DAT_20002cf8 >> 5) + (uint)DAT_2000411f;
    if (iVar1 < 0xc) {
      DAT_2000411f = (byte)iVar1 & (char)~(byte)((uint)iVar1 >> 0x18) >> 7;
    }
    else {
      DAT_2000411f = 0xb;
    }
  }
  _DAT_20003302 = 0;
  if (DAT_20004025 == '\t') {
    _DAT_20003302 = (short)(_DAT_20002cf4 >> 2);
  }
  if (DAT_20004026 == '\t') {
    _DAT_20003302 = (short)(_DAT_20002cf8 >> 2) + _DAT_20003302;
  }
  return;
}



/* FUN_1000640c at 1000640c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1000640c(void)

{
  DAT_20004029 = 0;
  DAT_20004025 = 0;
  _DAT_200031b6 = 0xff;
  DAT_2000402a = 1;
  _DAT_200031b8 = 0xff;
  return;
}



/* FUN_10006434 at 10006434 */

undefined8 FUN_10006434(int param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  cVar1 = DAT_20003fe1;
  iVar5 = param_1 * 4;
  uVar2 = (uint)(byte)(&DAT_20004029)[param_1];
  if (uVar2 < 5) {
                    /* WARNING: Subroutine does not return */
    FUN_10027708();
  }
  if (uVar2 < 0x7d) {
    uVar2 = *(int *)(&DAT_10029988 + (uVar2 + ((byte)(&DAT_20004029)[param_1] >> 1) + 0x28) * 4) +
            *(int *)(iVar5 + 0x20002cec);
    *(uint *)(iVar5 + 0x20002cec) = uVar2;
    if ((int)uVar2 < 0) {
      iVar3 = ((uVar2 >> 0x10) - 0x7fff) * -2 + 0xffff;
    }
    else {
      iVar3 = (uVar2 >> 0x10) << 1;
    }
    uVar2 = iVar3 + -0x7fff >> 7;
  }
  else {
    if (0xf4 < uVar2) goto LAB_10006468;
    if ((DAT_20003fe1 == '\0') || (*(char *)(param_1 + 0x20004027) != '\0')) {
      if ((*(char *)(param_1 + 0x2000402b) != '\0') &&
         (uVar2 = *(uint *)(&DAT_10029988 + ((uVar2 - 0x7d) * -2 + 0xf0) * 4),
         uVar4 = uVar2 + *(int *)(iVar5 + 0x20002cec), *(uint *)(iVar5 + 0x20002cec) = uVar4,
         uVar4 < uVar2)) {
        *(undefined1 *)(param_1 + 0x2000402b) = 0;
        *(undefined4 *)(iVar5 + 0x20002cec) = 0xffffffff;
      }
    }
    else {
      *(undefined1 *)(param_1 + 0x2000402b) = 1;
      *(undefined4 *)(iVar5 + 0x20002cec) = 0;
    }
    uVar2 = *(uint *)(iVar5 + 0x20002cec) >> 0x18;
  }
  *(uint *)(&DAT_20002cf4 + iVar5) = uVar2;
LAB_10006468:
  *(int *)(&DAT_20002cf4 + iVar5) =
       (int)((*(ushort *)(&DAT_200031b6 + param_1 * 2) - 0xff) * *(int *)(&DAT_20002cf4 + iVar5)) >>
       8;
  *(char *)(param_1 + 0x20004027) = cVar1;
  return CONCAT44(param_2,param_1);
}



/* FUN_10006588 at 10006588 */

undefined8 FUN_10006588(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  
  DAT_20003f65 = DAT_20003f64;
  DAT_20003f83 = DAT_20003f82;
  DAT_200041c5 = DAT_200041c4;
  DAT_20003fbb = DAT_20003fba;
  DAT_20004101 = DAT_20004100;
  DAT_20003f8b = DAT_20003f8a;
  DAT_200041ef = DAT_200041ee;
  DAT_200041e6 = DAT_200041e5;
  DAT_20003fb7 = DAT_20003fb6;
  DAT_200041e0 = DAT_200041df;
  DAT_200041da = DAT_200041d9;
  DAT_20003fb3 = (&DAT_20003faf)[DAT_20003c51];
  DAT_2000411c = DAT_2000411b;
  DAT_20003f92 = (&DAT_20003f8e)[DAT_20003c51];
  iVar1 = 0;
  do {
    FUN_10006434(iVar1,param_1,param_2);
    if ((byte)(&DAT_20004025)[iVar1] < 0x11) {
                    /* WARNING: Subroutine does not return */
      FUN_10027708();
    }
    bVar2 = iVar1 != 1;
    iVar1 = 1;
  } while (bVar2);
  return CONCAT44(param_2,param_1);
}



/* FUN_1000675c at 1000675c */

void FUN_1000675c(void)

{
  DAT_20003306 = 0;
  DAT_20003307 = 0;
  DAT_20003304 = 0;
  DAT_20003305 = 0;
  return;
}



/* FUN_10006780 at 10006780 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10006780(void)

{
  uint uVar1;
  uint uVar2;
  byte local_1c [16];
  
  FUN_1001f4d4(local_1c,&DAT_1002a9c0,0xc);
  uVar2 = 0;
  uVar1 = 0;
  do {
    if (*(char *)(local_1c[uVar2] + 0x200040f3) != '\0') {
      uVar1 = uVar1 | 1 << (uVar2 & 0xff) & 0xffffU;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 != 0xc);
  _DAT_20003212 = (short)uVar1;
  return;
}



/* FUN_100067c4 at 100067c4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_100067c4(void)

{
  char cVar1;
  uint uVar2;
  ushort uVar3;
  int iVar4;
  char cVar5;
  short local_1c [4];
  
  cVar5 = DAT_20003fbc;
  if (DAT_20003fbc == '\0') {
    if (*(int *)(_DAT_200009b0 + 0x74) != 0x10) {
      local_1c[0] = CONCAT11(local_1c[0]._1_1_,DAT_20004128 * '\x02' + '\x04');
      cVar1 = FUN_1001dfc0(&DAT_200009b0,0x5a,local_1c,1,1);
      if (cVar1 == '\x01') {
        DAT_20003fbc = '\x01';
      }
      else if (DAT_20003306 == '\0') {
        DAT_20003306 = -cVar1;
        DAT_20003307 = DAT_20004128 + 1;
      }
    }
    cVar1 = '\0';
  }
  else {
    cVar1 = FUN_1001dfd8(&DAT_200009b0,0x5a,local_1c,2,0);
    uVar2 = (uint)DAT_20004128;
    if (cVar1 == '\x02') {
      uVar3 = 0x3ff - local_1c[0];
      *(ushort *)(&DAT_20003214 + uVar2 * 2) = uVar3;
      if (_DAT_200032fe < uVar3) {
        *(undefined1 *)(uVar2 + 0x200040f3) = 1;
      }
      if (uVar3 < _DAT_2000322e) {
        *(undefined1 *)(uVar2 + 0x200040f3) = 0;
      }
      FUN_10006780();
      if (DAT_20004128 == 0) {
        iVar4 = (int)((uint)_DAT_200031a4 + (uint)_DAT_20003210) >> 1;
        _DAT_200031a4 = (ushort)iVar4;
        uVar2 = iVar4 - (uint)_DAT_2000320a;
        if ((int)uVar2 < 0x400) {
          uVar2 = uVar2 & (int)~uVar2 >> 0x1f;
        }
        else {
          uVar2 = 0x3ff;
        }
        iVar4 = _DAT_2000320c * uVar2;
        if (0xffff < iVar4) {
          iVar4 = 0xffff;
        }
        _DAT_20003230 = (undefined2)iVar4;
        _DAT_20003210 = _DAT_20003214;
        cVar1 = cVar5;
      }
      else {
        if ((uint)_DAT_20003210 < (uint)*(ushort *)(&DAT_20003214 + (uint)DAT_20004128 * 2)) {
          _DAT_20003210 = *(ushort *)(&DAT_20003214 + (uint)DAT_20004128 * 2);
        }
        cVar1 = '\0';
      }
    }
    else {
      if (DAT_20003304 == '\0') {
        DAT_20003304 = -cVar1;
        DAT_20003305 = DAT_20004128 + 1;
      }
      cVar1 = '\0';
      cVar5 = '\0';
    }
    DAT_20003fbc = '\0';
  }
  DAT_20004128 = cVar5 + DAT_20004128;
  if (0xb < DAT_20004128) {
    DAT_20004128 = 0;
  }
  return cVar1;
}



/* FUN_10006928 at 10006928 */

void FUN_10006928(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  
  FUN_1001c402(10);
  FUN_1001df6c(&DAT_200009b0,100000);
  FUN_1001ce74(0,3);
  FUN_1001ce74(1,3);
  FUN_1001cea4(0,1);
  FUN_1001cea4(1,1,0);
  FUN_100034a4(0x5e,0);
  FUN_100034a4(0x80,99);
  FUN_1001c402(2);
  FUN_100034a4(0x5c,0x10);
  FUN_100034a4(0x5d,0x20);
  FUN_100034a4(0x7d,0xc9);
  FUN_100034a4(0x7f,0xb5);
  FUN_100034a4(0x7e,0x83);
  FUN_100034a4(0x7b,0xb);
  FUN_100034a4(0x2b,1);
  FUN_100034a4(0x2f,1);
  FUN_100034a4(0x2c,1);
  FUN_100034a4(0x30,1);
  FUN_100034a4(0x33,1);
  FUN_100034a4(0x2d,0);
  FUN_100034a4(0x31,0xff);
  FUN_100034a4(0x34,0);
  FUN_100034a4(0x2e,0);
  FUN_100034a4(0x32,2);
  FUN_100034a4(0x35,0x7f);
  FUN_100034a4(0x5b,0);
  cVar4 = 'A';
  do {
    FUN_100034a4(cVar4,0xf);
    cVar1 = cVar4 + '\x01';
    cVar4 = cVar4 + '\x02';
    FUN_100034a4(cVar1,10);
  } while (cVar4 != 'Y');
  FUN_100034a4(0x5e,0x8c);
  iVar2 = FUN_100034c4(0x5e);
  if (iVar2 != 0) {
    FUN_100034a4(0x5e,0);
  }
  cVar4 = 'A';
  do {
    FUN_100034a4(cVar4,9);
    cVar1 = cVar4 + '\x01';
    cVar4 = cVar4 + '\x02';
    FUN_100034a4(cVar1,5);
  } while (cVar4 != 'Y');
  if (iVar2 != 0) {
    FUN_100034a4(0x5e,iVar2);
  }
  iVar2 = 10;
  DAT_20003fbc = 0;
  DAT_20004128 = 0;
  FUN_1000675c();
  do {
    do {
      iVar3 = FUN_100067c4();
    } while (iVar3 == 0);
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_10005380();
  return;
}



/* FUN_10006a94 at 10006a94 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10006a94(void)

{
  _DAT_2000320c = FUN_1001e480(0xffff,(uint)_DAT_20003208 - (uint)_DAT_2000320a);
  return;
}



/* FUN_10006abc at 10006abc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_10006abc(undefined4 param_1,undefined3 param_2,undefined4 param_3)

{
  undefined4 uStack_14;
  undefined4 uStack_10;
  
  uStack_14 = CONCAT13((char)param_1,param_2);
  _DAT_d0000018 = 0x10000;
  uStack_10 = param_3;
  FUN_100276b8(&DAT_4003c000,(int)&uStack_14 + 3,1);
  _DAT_d0000014 = 0x10000;
  return CONCAT44(uStack_14,param_1);
}



/* FUN_10006ae0 at 10006ae0 */

void FUN_10006ae0(void)

{
  DAT_20004038 = DAT_20004038 + 1 & 7;
  if ((DAT_20004038 == 0) && (DAT_20004039 != 0)) {
    DAT_20004037 = DAT_20000870;
    DAT_20004039 = DAT_20004038;
    FUN_1000343c();
  }
  FUN_10006abc(200);
  FUN_10006abc(2);
  FUN_10006abc(0x10);
  FUN_10006abc(DAT_20004038 | 0xb0);
  return;
}



/* FUN_10006b34 at 10006b34 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10006b34(void)

{
  DAT_20004038 = DAT_20004038 + 1 & 7;
  if ((DAT_20004038 == 0) && (DAT_20004039 != 0)) {
    DAT_20004037 = DAT_20000870;
    DAT_20004039 = DAT_20004038;
    FUN_1000343c();
  }
  DAT_20004036 = 1;
  _DAT_d0000018 = 0x10000;
  DAT_2000080b = DAT_20004038 | 0xb0;
  _DAT_50000000 = 0x20000808;
  _DAT_50000004 = 0x4003c008;
  _DAT_50000008 = 4;
  _DAT_5000000c = _DAT_200014d0;
  return;
}



/* FUN_10006bac at 10006bac */

void FUN_10006bac(void)

{
  FUN_100276b8(&DAT_4003c000,(uint)DAT_20004037 * 0x400 + (uint)DAT_20004038 * 0x80 + 0x20003309,
               0x80);
  return;
}



/* FUN_10006bdc at 10006bdc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10006bdc(void)

{
  _DAT_d0000014 = 0x10000;
  DAT_20004036 = 0;
  _DAT_50000000 = (uint)DAT_20004037 * 0x400 + (uint)DAT_20004038 * 0x80 + 0x20003309;
  _DAT_50000004 = 0x4003c008;
  _DAT_50000008 = 0x80;
  _DAT_5000000c = _DAT_200014d0;
  return;
}



/* FUN_10006c2c at 10006c2c */

void FUN_10006c2c(int param_1)

{
  FUN_1001f4c8(param_1 * 0x400 + 0x20003309,0,0x400);
  return;
}



/* FUN_10006c44 at 10006c44 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_10006c44(undefined4 param_1)

{
  int iVar1;
  
  DAT_20004037 = 0;
  FUN_10006c2c(0);
  DAT_20000870 = 1;
  FUN_10006c2c(1);
  DAT_20004039 = 0;
  DAT_20004038 = 0;
  FUN_1001c7f0(0x10,1);
  FUN_1001c7f0(0x14,1);
  _DAT_d0000018 = 0x100000;
  FUN_1001c402(5);
  _DAT_d0000014 = 0x100000;
  FUN_1001c402(5);
  FUN_1001e3f8(&DAT_4003c000,4000000);
  _DAT_4003f004 = 2;
  _DAT_4003e004 = _DAT_4003c004 & 2;
  _DAT_4003d000 = (_DAT_4003c000 ^ 7) & 0xcf;
  FUN_1001ce74(0x11,1);
  FUN_1001ce74(0x12,1);
  FUN_1001ce74(0x13,1);
  _DAT_200014d0 = 0x80011;
  FUN_10006abc(0xae);
  FUN_10006abc(0x32);
  FUN_10006abc(0x10);
  FUN_10006abc(0);
  FUN_10006abc(0x40);
  FUN_10006abc(0x81);
  FUN_10006abc(0xd2);
  FUN_10006abc(0xa1);
  FUN_10006abc(0xa4);
  FUN_10006abc(0xa6);
  FUN_10006abc(0xa8);
  FUN_10006abc(0x3f);
  FUN_10006abc(0xad);
  FUN_10006abc(0x8b);
  FUN_10006abc(0xb0);
  FUN_10006abc(200);
  FUN_10006abc(0xd3);
  FUN_10006abc(0);
  FUN_10006abc(0xd5);
  FUN_10006abc(0x80);
  FUN_10006abc(0xd9);
  FUN_10006abc(0xf1);
  FUN_10006abc(0xda);
  FUN_10006abc(0x12);
  FUN_10006abc(0xdb);
  FUN_10006abc(0x40);
  FUN_10006abc(0xaf);
  FUN_10006c2c(0);
  FUN_10006c2c(1);
  iVar1 = 8;
  DAT_20004038 = 7;
  do {
    iVar1 = iVar1 + -1;
    FUN_10006ae0();
    FUN_10006bac();
  } while (iVar1 != 0);
  _DAT_20002d04 = *(undefined4 *)(&DAT_10029570 + (uint)DAT_2000403a * 4);
  return CONCAT44(&DAT_20004038,param_1);
}



/* FUN_10006de0 at 10006de0 */

void FUN_10006de0(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  
  if (0x3f < param_2) {
    param_2 = 0x3f;
  }
  bVar1 = (byte)(1 << (param_2 & 7));
  if (0x7f < param_1) {
    param_1 = 0x7f;
  }
  uVar2 = (param_1 & 0xff) + (uint)DAT_20000870 * 0x400 + ((param_2 & 0xff) >> 3) * 0x80 & 0xffff;
  if (param_3 == 1) {
    bVar1 = *(byte *)(uVar2 + 0x20003309) & ~bVar1;
  }
  else {
    if (param_3 == 2) {
      *(byte *)(uVar2 + 0x20003309) = bVar1 ^ *(byte *)(uVar2 + 0x20003309);
      return;
    }
    if (param_3 != 0) {
      return;
    }
    bVar1 = *(byte *)(uVar2 + 0x20003309) | bVar1;
  }
  *(byte *)(uVar2 + 0x20003309) = bVar1;
  return;
}



/* FUN_10006ee0 at 10006ee0 */

void FUN_10006ee0(int param_1,int param_2,uint param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  
  uVar5 = 0;
  uVar6 = (1 << (param_3 & 0xff)) - 1;
  if (0x20 < param_3) {
    uVar5 = (1 << (param_3 - 0x20 & 0xff)) - 1;
  }
  if (param_2 != 0) {
    iVar7 = 1;
    do {
      iVar7 = iVar7 + 1;
      uVar5 = uVar5 << 1 | uVar6 >> 0x1f;
      uVar6 = uVar6 << 1;
    } while (iVar7 <= param_2);
  }
  if (param_4 == 3) {
    uVar3 = (param_2 << 0x1f) >> 0x1f ^ 0x55555555;
    uVar6 = uVar6 & uVar3;
    uVar5 = uVar5 & uVar3;
  }
  uVar4 = (uint)DAT_20000870;
  iVar7 = (-(uint)(uVar4 == 0) & 0xfffffc00) + 0x800;
  iVar8 = 4;
  uVar3 = param_1 + uVar4 * 0x400 & 0xffff;
  do {
    if (iVar7 <= (int)uVar3) {
      uVar3 = (uVar4 + 1) * 0x400 & 0xffff;
    }
    bVar2 = (byte)uVar6;
    bVar1 = *(byte *)(uVar3 + 0x20003309);
    bVar9 = bVar1 & ~bVar2;
    if ((param_4 != 1) && (bVar9 = bVar1 ^ bVar2, param_4 != 2)) {
      bVar9 = bVar1 | bVar2;
    }
    iVar8 = iVar8 + -1;
    *(byte *)(uVar3 + 0x20003309) = bVar9;
    uVar6 = uVar6 >> 8;
    uVar3 = uVar3 + 0x80 & 0xffff;
  } while (iVar8 != 0);
  iVar8 = 4;
  do {
    if (iVar7 <= (int)uVar3) {
      uVar3 = (uVar4 + 1) * 0x400 & 0xffff;
    }
    bVar1 = *(byte *)(uVar3 + 0x20003309);
    bVar2 = (byte)uVar5;
    bVar9 = bVar1 & ~bVar2;
    if ((param_4 != 1) && (bVar9 = bVar1 ^ bVar2, param_4 != 2)) {
      bVar9 = bVar1 | bVar2;
    }
    iVar8 = iVar8 + -1;
    *(byte *)(uVar3 + 0x20003309) = bVar9;
    uVar5 = uVar5 >> 8;
    uVar3 = uVar3 + 0x80 & 0xffff;
  } while (iVar8 != 0);
  return;
}



/* FUN_1000701c at 1000701c */

undefined8 FUN_1000701c(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = param_2 + 10U & 0xff;
  iVar3 = param_1;
  FUN_10006ee0(param_1,uVar2,2,param_3,param_1,param_2,param_3);
  FUN_10006ee0(param_1 + 1U & 0xff,uVar2,3,param_3);
  FUN_10006ee0(param_1 + 2U & 0xff,param_2 + 0xbU & 0xff,3,param_3);
  FUN_10006ee0(param_1 + 3U & 0xff,param_2 + 0xcU & 0xff,3,param_3);
  FUN_10006ee0(param_1 + 4U & 0xff,param_2 + 0xdU & 0xff,3,param_3);
  FUN_10006ee0(param_1 + 5U & 0xff,param_2,0x11,param_3);
  FUN_10006ee0(param_1 + 6U & 0xff,param_2,0x12,param_3);
  FUN_10006ee0(param_1 + 7U & 0xff,uVar2,8,param_3);
  uVar1 = param_2 + 5U & 0xff;
  FUN_10006ee0(param_1 + 8U & 0xff,uVar1,0xd,param_3);
  FUN_10006ee0(param_1 + 9U & 0xff,uVar1,0xd,param_3);
  FUN_10006ee0(param_1 + 10U & 0xff,uVar2,8,param_3);
  uVar1 = param_2 + 6U & 0xff;
  FUN_10006ee0(param_1 + 0xbU & 0xff,uVar1,0xc,param_3);
  FUN_10006ee0(param_1 + 0xcU & 0xff,uVar1,0xc,param_3);
  FUN_10006ee0(param_1 + 0xdU & 0xff,uVar2,8,param_3);
  uVar2 = param_2 + 7U & 0xff;
  FUN_10006ee0(param_1 + 0xeU & 0xff,uVar2,0xb,param_3);
  FUN_10006ee0(param_1 + 0xfU & 0xff,uVar2,10,param_3);
  return CONCAT44(uVar1,iVar3);
}



/* FUN_100071a8 at 100071a8 */

void FUN_100071a8(int param_1,int param_2)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte local_30 [12];
  undefined1 local_24 [16];
  
  FUN_1001f4d4(local_30,&DAT_1002a9cc,10);
  FUN_1001f4d4(local_24,&LAB_100277aa,10);
  uVar3 = 0;
  do {
    uVar4 = uVar3 & 0xff;
    uVar2 = param_2 + (uint)local_30[uVar3] & 0xff;
    uVar1 = local_24[uVar3];
    FUN_10006ee0(param_1 + uVar4 & 0xff,uVar2,uVar1,0);
    uVar3 = uVar3 + 1;
    FUN_10006ee0((param_1 + 0x14) - uVar4 & 0xff,uVar2,uVar1,0);
  } while (uVar3 != 10);
  FUN_10006ee0(param_1 + 10U & 0xff,param_2,0x15,0);
  return;
}



/* FUN_10007218 at 10007218 */

void FUN_10007218(uint param_1,uint param_2,uint param_3,uint param_4,undefined1 param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint local_24;
  char local_1c;
  
  local_24 = param_2 << 0xc;
  iVar1 = FUN_1001e480((param_4 - param_2) * 0x1000,param_3 - param_1);
  if (param_3 == param_1) {
    if (param_2 < param_4) {
      local_1c = (char)(param_4 - param_2);
      param_4 = param_2;
    }
    else {
      local_1c = (char)param_2 - (char)param_4;
    }
    FUN_10006ee0(param_3,param_4,local_1c,param_5);
  }
  for (; (int)param_1 <= (int)param_3; param_1 = param_1 + 1) {
    uVar5 = local_24 >> 0xc & 0xff;
    iVar4 = (local_24 >> 0xc & 0xff) - param_2;
    uVar2 = iVar4 >> 0x1f;
    if ((int)(iVar4 + uVar2 ^ uVar2) < 2) {
      FUN_10006de0(param_1 & 0xff,uVar5,param_5);
    }
    else {
      if (param_2 < uVar5) {
        uVar3 = uVar5 - param_2;
        uVar2 = param_2 + 1 & 0xff;
      }
      else {
        uVar3 = param_2 - uVar5;
        uVar2 = uVar5;
      }
      FUN_10006ee0(param_1 & 0xff,uVar2,uVar3 & 0xff,param_5);
    }
    local_24 = local_24 + iVar1;
    param_2 = uVar5;
  }
  return;
}



/* FUN_100072b4 at 100072b4 */

void FUN_100072b4(int param_1,int param_2,uint param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  byte bVar9;
  int local_28;
  
  uVar6 = 0;
  if (0x20 < param_3) {
    uVar6 = (1 << (param_3 - 0x20 & 0xff)) - 1;
  }
  uVar5 = (1 << (param_3 & 0xff)) - 1U & 0x33333333;
  uVar6 = uVar6 & 0x33333333;
  if (param_2 != 0) {
    iVar7 = 1;
    do {
      iVar7 = iVar7 + 1;
      uVar6 = uVar6 << 1 | uVar5 >> 0x1f;
      uVar5 = uVar5 << 1;
    } while (iVar7 <= param_2);
  }
  uVar8 = (uint)DAT_20000870;
  uVar3 = param_1 + uVar8 * 0x400;
  local_28 = 4;
  do {
    uVar4 = uVar3 & 0xffff;
    if ((int)((-(uint)(uVar8 == 0) & 0xfffffc00) + 0x800) <= (int)(uVar3 & 0xffff)) {
      uVar4 = (uVar8 + 1) * 0x400 & 0xffff;
    }
    bVar9 = (byte)uVar6;
    bVar1 = *(byte *)(uVar4 + 0x20003309);
    bVar2 = (byte)uVar5;
    if (param_4 == 1) {
      *(byte *)(uVar4 + 0x20003309) = bVar1 & ~bVar2;
      bVar9 = *(byte *)(uVar4 + 0x20003509) & ~bVar9;
    }
    else if (param_4 == 2) {
      *(byte *)(uVar4 + 0x20003309) = bVar2 ^ bVar1;
      bVar9 = bVar9 ^ *(byte *)(uVar4 + 0x20003509);
    }
    else {
      *(byte *)(uVar4 + 0x20003309) = bVar1 | bVar2;
      bVar9 = bVar9 | *(byte *)(uVar4 + 0x20003509);
    }
    uVar3 = uVar4 + 0x80;
    *(byte *)(uVar4 + 0x20003509) = bVar9;
    uVar5 = uVar5 >> 8;
    local_28 = local_28 + -1;
    uVar6 = uVar6 >> 8;
  } while (local_28 != 0);
  return;
}



/* FUN_10007380 at 10007380 */

void FUN_10007380(int param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  
  if (0x80 < (int)(param_1 + param_3)) {
    param_3 = -param_1 - 0x80U & 0xff;
  }
  uVar4 = (uint)DAT_20000870;
  iVar2 = 0;
  do {
    if ((int)param_3 <= iVar2) {
      return;
    }
    uVar5 = ((param_2 >> 3 & 7) * 0x80 + param_1 + uVar4 * 0x400 & 0xffff) + iVar2;
    uVar1 = (uVar4 + 1) * 0x400;
    if ((int)uVar5 < (int)((-(uint)(uVar4 == 0) & 0xfffffc00) + 0x800)) {
      uVar1 = uVar5;
    }
    uVar1 = uVar1 & 0xffff;
    bVar3 = (byte)(1 << (param_2 & 7));
    if (param_4 == 1) {
      *(byte *)(uVar1 + 0x20003309) = *(byte *)(uVar1 + 0x20003309) & ~bVar3;
    }
    else {
      if (param_4 == 2) {
        bVar3 = *(byte *)(uVar1 + 0x20003309) ^ bVar3;
      }
      else {
        if (param_4 != 0) goto LAB_1000740a;
        bVar3 = *(byte *)(uVar1 + 0x20003309) | bVar3;
      }
      *(byte *)(uVar1 + 0x20003309) = bVar3;
    }
LAB_1000740a:
    iVar2 = iVar2 + 1;
  } while( true );
}



/* FUN_1000764c at 1000764c */

undefined8 FUN_1000764c(int param_1,int param_2,int param_3,int param_4,undefined1 param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1;
  FUN_10006ee0(param_1,param_2,param_4,param_5,param_1,param_4,param_3);
  uVar2 = param_3 - 2U & 0xff;
  uVar1 = param_1 + 1U & 0xff;
  FUN_10006ee0(param_1 + param_3 + -1 & 0xff,param_2,param_4,param_5);
  FUN_10007380(uVar1,param_2,uVar2,param_5);
  FUN_10007380(uVar1,param_2 + param_4 + -1 & 0xff,uVar2,param_5);
  return CONCAT44(param_4,iVar3);
}



/* FUN_1000769a at 1000769a */

void FUN_1000769a(int param_1,undefined4 param_2,int param_3,undefined4 param_4,char param_5)

{
  if (param_5 == '\x01') {
    FUN_10007380();
  }
  else {
    FUN_10006de0(param_1,param_2,param_4,param_5,param_4);
    FUN_10006de0(param_1 + param_3 + -1 & 0xff,param_2,param_4);
  }
  return;
}



/* FUN_100076cc at 100076cc */

void FUN_100076cc(int param_1,uint param_2,uint param_3,int param_4)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  byte bVar4;
  
  if (0x80 < (int)(param_1 + param_3)) {
    param_3 = -param_1 - 0x80U & 0xff;
  }
  bVar1 = (byte)(1 << (param_2 & 7));
  pbVar2 = (byte *)(((param_2 >> 3 & 7) * 0x80 + param_1 + (uint)DAT_20000870 * 0x400 & 0xffff) +
                   0x20003309);
  uVar3 = 0;
  do {
    if ((int)param_3 <= (int)uVar3) {
      return;
    }
    if ((uVar3 & 2) == 0) {
      if (param_4 == 1) {
        bVar4 = *pbVar2 & ~bVar1;
      }
      else if (param_4 == 2) {
        bVar4 = *pbVar2 ^ bVar1;
      }
      else {
        if (param_4 != 0) goto LAB_10007722;
        bVar4 = *pbVar2 | bVar1;
      }
      *pbVar2 = bVar4;
    }
LAB_10007722:
    uVar3 = uVar3 + 1;
    pbVar2 = pbVar2 + 1;
  } while( true );
}



/* FUN_1000773c at 1000773c */

void FUN_1000773c(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined1 param_5,
                 char param_6)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_6 == '\0') {
    FUN_1000764c(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    for (; iVar1 < param_3; iVar1 = iVar1 + 1) {
      FUN_10006ee0(param_1 + iVar1 & 0xff,param_2,param_4,param_5);
    }
  }
  return;
}



/* FUN_1000777a at 1000777a */

void FUN_1000777a(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_2 + 2U & 0xff;
  FUN_10006ee0(param_1,uVar1,0x12,param_3);
  uVar2 = param_2 + 1U & 0xff;
  FUN_10006ee0(param_1 + 1U & 0xff,uVar2,4,param_3);
  FUN_1000773c(param_1 + 2U & 0xff,param_2,5,6,param_3,1);
  FUN_10006ee0(param_1 + 7U & 0xff,uVar2,4,param_3);
  FUN_10006ee0(param_1 + 8U & 0xff,uVar1,2,param_3);
  return;
}



/* FUN_100077da at 100077da */

undefined8 FUN_100077da(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar3 = param_1;
  uVar4 = param_3;
  FUN_10006de0(param_1 + 4U & 0xff,param_2 + 4U & 0xff);
  FUN_10006de0(param_1 + 5U & 0xff,param_2 + 3U & 0xff,param_3);
  uVar1 = param_2 + 2U & 0xff;
  FUN_10007380(param_1 + 6U & 0xff,uVar1,2,param_3,iVar3,uVar1,uVar4);
  uVar2 = param_2 + 1U & 0xff;
  FUN_10007380(param_1 + 8U & 0xff,uVar2,3,param_3);
  FUN_10007380(param_1 + 0xbU & 0xff,param_2,10,param_3);
  FUN_10007380(param_1 + 0x15U & 0xff,uVar2,3,param_3);
  FUN_10006de0(param_1 + 0x18U & 0xff,uVar1,param_3);
  FUN_1000777a(param_1,param_2 + 7U & 0xff,param_3);
  FUN_1000777a(param_1 + 0x14U & 0xff,param_2 + 5U & 0xff,param_3);
  return CONCAT44(uVar1,iVar3);
}



/* FUN_100078cc at 100078cc */

void FUN_100078cc(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  FUN_10006de0(param_1 + 9U & 0xff);
  uVar2 = param_2 + 9U & 0xff;
  uVar1 = 8;
  do {
    uVar3 = uVar1;
    uVar1 = uVar3 & 0xff;
    FUN_1000769a(param_1 + uVar1 & 0xff,uVar2 - uVar1 & 0xff,uVar1 * -2 + 0x13 & 0xff,param_3,
                 param_4);
    uVar1 = uVar3 - 1;
  } while (uVar3 - 1 != 0);
  FUN_10007380(param_1,uVar2,0x13,param_3);
  FUN_1000773c(param_1 + 6U & 0xff,param_2 + 10U & 0xff,7,0x13,param_3,uVar3);
  if (param_4 == 0) {
    FUN_1000773c(param_1 + 7U & 0xff,uVar2,5,0x13,2,uVar3);
  }
  return;
}



/* FUN_1000794c at 1000794c */

void FUN_1000794c(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 1;
  FUN_1000773c(param_1 + 6U & 0xff,param_2,7,0x13,param_3,1);
  uVar2 = param_2 + 0x13U & 0xff;
  FUN_10007380(param_1,uVar2,0x13,param_3);
  do {
    uVar1 = uVar3 & 0xff;
    uVar3 = uVar3 + 1;
    FUN_1000769a(uVar1 + param_1 & 0xff,uVar2 + uVar1 & 0xff,uVar1 * -2 + 0x13 & 0xff,param_3,
                 param_4);
  } while (uVar3 != 9);
  FUN_10006de0(param_1 + 9U & 0xff,param_2 + 0x1cU & 0xff,param_3);
  if (param_4 == 0) {
    FUN_1000773c(param_1 + 7U & 0xff,param_2 + 1U & 0xff,5,0x13,2,1);
  }
  return;
}



/* FUN_10007abc at 10007abc */

void FUN_10007abc(int param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = 1;
  FUN_1000773c(param_1,param_2,0xc,8,param_3,1);
  do {
    uVar3 = uVar2 & 0xff;
    uVar1 = uVar3 + param_2 + -1 & 0xff;
    FUN_10006de0(param_1 + uVar3 & 0xff,uVar1,2);
    uVar2 = uVar2 + 1;
    FUN_10006de0((param_1 + 0xb) - uVar3 & 0xff,uVar1,2);
  } while (uVar2 != 6);
  return;
}



/* FUN_10007b02 at 10007b02 */

void FUN_10007b02(int param_1,int param_2,int param_3,int param_4,byte param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  FUN_1000773c(param_1 + 7U & 0xff,(param_2 - (uint)param_5) + 0x3f & 0xff,3,param_5 + 1 & 0xff,0,1)
  ;
  FUN_1000764c(param_1 + 6U & 0xff,param_2,5,0x40,0);
  FUN_10007380(param_1 + 4U & 0xff,param_2 + (0x3f - param_4) & 0xff,9,0);
  iVar2 = -param_3 + 0x3d;
  uVar3 = iVar2 + param_2;
  if (0x3f < (int)uVar3) {
    uVar3 = 0x3f;
  }
  iVar5 = -param_3 + 0x3e;
  uVar4 = param_2 + iVar5;
  if (iVar2 < 0) {
    FUN_10006ee0(param_1,(int)~uVar3 >> 0x1f & uVar3 & 0xff,-param_3 + 0x42U & 0xff,0);
    if (iVar5 != 0) {
      bVar1 = 0x3f;
      uVar3 = -param_3 + 0x41U & 0xff;
      if ((int)uVar4 < 0x40) {
        bVar1 = (char)~(byte)(uVar4 >> 0x18) >> 7 & (byte)uVar4;
      }
      uVar4 = (uint)bVar1;
      goto LAB_10007bba;
    }
  }
  else {
    FUN_10006ee0(param_1,uVar3 & 0xff,5,0);
  }
  if (0x3f < (int)uVar4) {
    uVar4 = 0x3f;
  }
  uVar3 = 3;
  uVar4 = uVar4 & 0xff;
LAB_10007bba:
  FUN_10006ee0(param_1 + 1U & 0xff,uVar4,uVar3,0);
  FUN_10006de0(param_1 + 2U & 0xff,0x3fU - param_3 & 0xff,0);
  return;
}



/* FUN_10007cb4 at 10007cb4 */

void FUN_10007cb4(int param_1,int param_2,undefined4 param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_2 + 2U & 0xff;
  FUN_10006ee0(param_1,uVar4,3,param_3);
  FUN_10006ee0(param_1 + 6U & 0xff,uVar4,3,param_3);
  uVar4 = param_1 + 1U & 0xff;
  uVar1 = param_1 + 2U & 0xff;
  uVar2 = param_1 + 5U & 0xff;
  uVar5 = param_2 + 1U & 0xff;
  if (param_4 == 1) {
    FUN_10006ee0(uVar4,uVar5,5,param_3);
    FUN_1000773c(uVar1,param_2,3,7,param_3,1);
    FUN_10006ee0(uVar2,uVar5,5,param_3);
  }
  else {
    uVar3 = param_2 + 5U & 0xff;
    FUN_10006de0(uVar4,uVar5,param_3);
    FUN_10006de0(uVar4,uVar3,param_3);
    FUN_10007380(uVar1,param_2,3,param_3);
    FUN_10007380(uVar1,param_2 + 6U & 0xff,3,param_3);
    FUN_10006de0(uVar2,uVar5,param_3);
    FUN_10006de0(uVar2,uVar3,param_3);
  }
  return;
}



/* FUN_10007d6e at 10007d6e */

undefined8 FUN_10007d6e(int param_1,int param_2,int param_3,int param_4,byte param_5,byte param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = (uint)param_5;
  uVar1 = (uint)param_6;
  FUN_1000773c(param_1,param_2,param_3,param_4,uVar2,uVar1,param_3);
  FUN_10006de0(param_1,param_2,2);
  uVar3 = param_1 + param_3 + -1 & 0xff;
  uVar4 = param_2 + param_4 + -1 & 0xff;
  FUN_10006de0(uVar3,param_2,2);
  FUN_10006de0(param_1,uVar4,2);
  FUN_10006de0(uVar3,uVar4,2);
  return CONCAT44(uVar1,uVar2);
}



/* FUN_10007e00 at 10007e00 */

void FUN_10007e00(int param_1,int param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_1 + 2U & 0xff;
  FUN_10007380(uVar1,param_2,0xd,param_4);
  uVar2 = param_1 + 1U & 0xff;
  uVar4 = param_2 + 1U & 0xff;
  FUN_10006de0(uVar2,uVar4,param_4);
  uVar3 = param_1 + 0xfU & 0xff;
  uVar5 = param_2 + 2U & 0xff;
  FUN_10006de0(uVar3,uVar4,param_4);
  FUN_10006ee0(param_1,uVar5,6,param_4);
  FUN_10006ee0(param_1 + 0x10U & 0xff,uVar5,6,param_4);
  uVar4 = param_2 + 8U & 0xff;
  FUN_10006de0(uVar2,uVar4,param_4);
  FUN_10006de0(uVar3,uVar4,param_4);
  FUN_10007380(uVar1,param_2 + 9U & 0xff,0xd,param_4);
  if (param_3 != 0) {
    uVar1 = param_1 + 8U & 0xff;
  }
  FUN_10007d6e(uVar1,uVar5,7,6,param_4,1);
  return;
}



/* FUN_10007eba at 10007eba */

void FUN_10007eba(int param_1,int param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_1 + 2U & 0xff;
  FUN_10007380(uVar1,param_2,6,param_4);
  uVar2 = param_1 + 1U & 0xff;
  uVar4 = param_2 + 1U & 0xff;
  FUN_10006de0(uVar2,uVar4,param_4);
  uVar3 = param_1 + 8U & 0xff;
  uVar5 = param_2 + 2U & 0xff;
  FUN_10006de0(uVar3,uVar4,param_4);
  FUN_10006ee0(param_1,uVar5,0xc,param_4);
  uVar4 = param_2 + 0xeU & 0xff;
  FUN_10006ee0(param_1 + 9U & 0xff,uVar5,0xc,param_4);
  FUN_10006de0(uVar2,uVar4,param_4);
  FUN_10006de0(uVar3,uVar4,param_4);
  FUN_10007380(uVar1,param_2 + 0xfU & 0xff,6,param_4);
  if (param_3 == 0) {
    uVar5 = param_2 + 8U & 0xff;
  }
  FUN_10007d6e(uVar1,uVar5,6,6,param_4,1);
  return;
}



/* FUN_10007f70 at 10007f70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10007f70(uint param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  byte local_38 [8];
  byte local_30 [28];
  
  FUN_1001f4d4(local_38,&LAB_100277b4_1,5);
  FUN_1001f4d4(local_30,&DAT_1002a9d6,0x18);
  uVar4 = param_1;
  do {
    iVar1 = 0;
    uVar3 = uVar4 + 0xc & 0xff;
    FUN_1000773c(uVar4,param_2,0xb,0x2a,0,1);
    uVar4 = uVar3;
  } while (uVar3 != (param_1 + 0x54 & 0xff));
  do {
    pbVar5 = local_38 + iVar1;
    iVar1 = iVar1 + 1;
    FUN_1000773c(param_1 + *pbVar5 & 0xff,param_2,9,0x19,1,1);
  } while (iVar1 != 5);
  uVar4 = 0;
  pbVar5 = local_30;
  do {
    if ((param_3 >> (uVar4 & 0xff) & 1U) != 0) {
      uVar3 = param_1 + *pbVar5 & 0xff;
      uVar2 = param_2 + (uint)pbVar5[1] & 0xff;
      FUN_10007d6e(uVar3,uVar2,5,5,2,1);
      if ((((int)(uint)_DAT_2000320e >> (uVar4 & 0xff) & 1U) != 0) && (param_4 != 0)) {
        FUN_10007d6e(uVar3 + 1 & 0xff,uVar2 + 1 & 0xff,3,3,2,1);
      }
    }
    uVar4 = uVar4 + 1;
    pbVar5 = pbVar5 + 2;
  } while (uVar4 != 0xc);
  return;
}



/* FUN_10008048 at 10008048 */

void FUN_10008048(int param_1)

{
  byte bVar1;
  byte bVar2;
  char cVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  
  uVar9 = (uint)(DAT_20003f65 >> 3);
  bVar1 = DAT_20003f83 >> 3;
  uVar11 = param_1 - (uint)(DAT_200041c5 >> 3) & 0xff;
  uVar4 = 0x20 - (uVar9 + bVar1);
  if ((int)uVar4 < 0x10) {
    uVar4 = 0x10;
  }
  uVar5 = uVar4 & 0xff;
  bVar2 = DAT_20004101 >> 3;
  uVar6 = param_1 + 0x21U & 0xff;
  FUN_10007380(0,uVar6,0xf);
  iVar7 = uVar9 + 0xe;
  uVar8 = param_1 + 2U & 0xff;
  FUN_10007218(0xe,uVar6,iVar7,uVar8,0);
  if (DAT_2000403e == '@') {
    FUN_10007d6e(uVar9 + 0xc,param_1,5,5,0,1);
  }
  iVar10 = iVar7 + (uint)bVar1;
  uVar9 = uVar11 + 0x21 & 0xff;
  FUN_10007218(iVar7,uVar8,iVar10,uVar9,0);
  uVar11 = uVar11 + 0x1f & 0xff;
  if (DAT_2000403e == 'A') {
    FUN_10007d6e(iVar10 - 2U & 0xff,uVar11,5,5,0,1);
  }
  FUN_10007380(iVar10 + 1,uVar9,uVar5,0);
  if (DAT_2000403e == 'B') {
    cVar3 = (char)(uVar5 >> 1) + (char)iVar10 + -1;
  }
  else {
    if (DAT_2000403e != 'C') goto LAB_10008134;
    cVar3 = (char)uVar4 + (char)iVar10 + -1;
  }
  FUN_10007d6e(cVar3,uVar11,5,5,0,1);
LAB_10008134:
  uVar4 = uVar5 + iVar10 + 1 & 0xff;
  uVar11 = bVar2 + uVar4 & 0xff;
  FUN_10007218(uVar4,uVar9,uVar11,uVar6,0);
  if (DAT_2000403e == 'D') {
    FUN_10007d6e(uVar11 - 2 & 0xff,param_1 + 0x1fU & 0xff,5,5,0,1);
  }
  FUN_10007218(uVar11,uVar6,0x7f,uVar6,0);
  return;
}



/* FUN_100081fc at 100081fc */

void FUN_100081fc(short param_1,uint param_2,uint param_3,int param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  uint uVar8;
  byte bVar9;
  
  uVar8 = (uint)(ushort)(param_1 + (ushort)DAT_20000870 * 0x400);
  bVar1 = (byte)param_3;
  bVar5 = (byte)param_2;
  if (param_4 == 1) {
    param_3 = ~param_3;
    *(byte *)(uVar8 + 0x20003309) = *(byte *)(uVar8 + 0x20003309) & ~bVar1;
    *(byte *)(uVar8 + 0x20003389) = (byte)(param_3 >> 8) & *(byte *)(uVar8 + 0x20003389);
    *(byte *)(uVar8 + 0x20003409) = (byte)(param_3 >> 0x10) & *(byte *)(uVar8 + 0x20003409);
    *(byte *)(uVar8 + 0x20003489) = (byte)(param_3 >> 0x18) & *(byte *)(uVar8 + 0x20003489);
    param_2 = ~param_2;
    *(byte *)(uVar8 + 0x20003509) = *(byte *)(uVar8 + 0x20003509) & ~bVar5;
    *(byte *)(uVar8 + 0x20003589) = (byte)(param_2 >> 8) & *(byte *)(uVar8 + 0x20003589);
    *(byte *)(uVar8 + 0x20003609) = (byte)(param_2 >> 0x10) & *(byte *)(uVar8 + 0x20003609);
    bVar9 = (byte)(param_2 >> 0x18) & *(byte *)(uVar8 + 0x20003689);
  }
  else {
    bVar2 = (byte)(param_3 >> 8);
    bVar3 = (byte)(param_3 >> 0x10);
    bVar4 = (byte)(param_3 >> 0x18);
    bVar6 = (byte)(param_2 >> 8);
    bVar7 = (byte)(param_2 >> 0x10);
    bVar9 = (byte)(param_2 >> 0x18);
    if (param_4 != 2) {
      if (param_4 == 0) {
        *(byte *)(uVar8 + 0x20003309) = *(byte *)(uVar8 + 0x20003309) | bVar1;
        *(byte *)(uVar8 + 0x20003389) = *(byte *)(uVar8 + 0x20003389) | bVar2;
        *(byte *)(uVar8 + 0x20003409) = *(byte *)(uVar8 + 0x20003409) | bVar3;
        *(byte *)(uVar8 + 0x20003489) = *(byte *)(uVar8 + 0x20003489) | bVar4;
        *(byte *)(uVar8 + 0x20003509) = *(byte *)(uVar8 + 0x20003509) | bVar5;
        *(byte *)(uVar8 + 0x20003589) = *(byte *)(uVar8 + 0x20003589) | bVar6;
        *(byte *)(uVar8 + 0x20003609) = *(byte *)(uVar8 + 0x20003609) | bVar7;
        *(byte *)(uVar8 + 0x20003689) = *(byte *)(uVar8 + 0x20003689) | bVar9;
        return;
      }
      return;
    }
    *(byte *)(uVar8 + 0x20003309) = *(byte *)(uVar8 + 0x20003309) ^ bVar1;
    *(byte *)(uVar8 + 0x20003389) = *(byte *)(uVar8 + 0x20003389) ^ bVar2;
    *(byte *)(uVar8 + 0x20003409) = *(byte *)(uVar8 + 0x20003409) ^ bVar3;
    *(byte *)(uVar8 + 0x20003489) = bVar4 ^ *(byte *)(uVar8 + 0x20003489);
    *(byte *)(uVar8 + 0x20003509) = *(byte *)(uVar8 + 0x20003509) ^ bVar5;
    *(byte *)(uVar8 + 0x20003589) = *(byte *)(uVar8 + 0x20003589) ^ bVar6;
    *(byte *)(uVar8 + 0x20003609) = *(byte *)(uVar8 + 0x20003609) ^ bVar7;
    bVar9 = *(byte *)(uVar8 + 0x20003689) ^ bVar9;
  }
  *(byte *)(uVar8 + 0x20003689) = bVar9;
  return;
}



/* FUN_1000834c at 1000834c */

void FUN_1000834c(uint param_1,uint param_2,int param_3,int param_4,undefined1 param_5)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  
  iVar6 = 0;
  puVar7 = (uint *)(&DAT_10028478 + param_3 * 0x80);
  do {
    uVar5 = *puVar7;
    puVar1 = (uint *)((int)&DAT_10028878 + iVar6);
    puVar2 = (uint *)((int)&DAT_10028978 + iVar6);
    puVar3 = puVar7 + param_3 * -0x20 + param_4 * 0x20;
    puVar7 = puVar7 + 1;
    puVar4 = (uint *)((int)&DAT_100288f8 + iVar6);
    iVar6 = iVar6 + 4;
    uVar5 = *puVar4 & *puVar3 | *puVar1 & uVar5 | *puVar2;
    FUN_100081fc(param_1,uVar5 >> (0x20 - param_2 & 0xff),uVar5 << (param_2 & 0xff),param_5);
    param_1 = param_1 + 1 & 0xff;
  } while (iVar6 != 0x80);
  return;
}



/* FUN_100083cc at 100083cc */

void FUN_100083cc(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  byte bVar20;
  uint uVar21;
  uint local_50;
  int local_48;
  uint local_38;
  
  bVar10 = DAT_200041d2;
  bVar9 = DAT_200041d1;
  bVar8 = DAT_200041d0;
  cVar7 = DAT_200041cf;
  if (DAT_200041d0 < 4) {
                    /* WARNING: Subroutine does not return */
    FUN_10027708(DAT_200041d0);
  }
  uVar13 = (uint)DAT_200041d3;
  uVar14 = (uint)DAT_20000870;
  uVar15 = (uint)DAT_200041d1;
  local_38 = (uint)DAT_200041d2;
  local_48 = 0;
  do {
    if (-1 < local_48) {
      DAT_200041d2 = bVar9 + bVar10;
      return;
    }
    if (bVar8 < 4) {
                    /* WARNING: Subroutine does not return */
      FUN_10027708();
    }
    uVar21 = 0;
    local_50 = 0;
    uVar16 = 0;
    for (uVar17 = 0; (int)uVar17 < 0; uVar17 = uVar17 + 1) {
      uVar19 = 0 >> (uVar17 & 0xff) & 1;
      uVar12 = uVar15 + uVar16 & 0xff;
      for (; uVar12 != uVar16; uVar16 = uVar16 + 1 & 0xff) {
        if (uVar16 < 0x20) {
          uVar21 = uVar21 | uVar19 << uVar16;
        }
        else {
          local_50 = local_50 | uVar19 << (uVar16 - 0x20 & 0xff);
        }
      }
      uVar16 = uVar12;
    }
    for (iVar11 = 0; iVar11 < (int)uVar13; iVar11 = iVar11 + 1) {
      local_50 = uVar21 >> 0x1f | local_50 << 1;
      uVar21 = uVar21 << 1;
    }
    iVar11 = (uVar14 & 0x3f) * 0x400;
    uVar16 = uVar15 + local_38;
    uVar17 = ~uVar21;
    for (; local_38 != (uVar16 & 0xff); local_38 = local_38 + 1 & 0xff) {
      bVar4 = (byte)local_50;
      if (cVar7 == '\x01') {
        *(byte *)(local_38 + iVar11 + 0x20003309) =
             *(byte *)(local_38 + iVar11 + 0x20003309) & (byte)uVar17;
        iVar18 = local_38 + 0x80 + iVar11;
        *(byte *)(iVar18 + 0x20003309) = *(byte *)(iVar18 + 0x20003309) & (byte)(uVar17 >> 8);
        iVar18 = local_38 + 0x100 + iVar11;
        *(byte *)(iVar18 + 0x20003309) = (byte)(uVar17 >> 0x10) & *(byte *)(iVar18 + 0x20003309);
        iVar18 = local_38 + 0x180 + iVar11;
        *(byte *)(iVar18 + 0x20003309) = (byte)(uVar17 >> 0x18) & *(byte *)(iVar18 + 0x20003309);
        iVar18 = local_38 + 0x200 + iVar11;
        uVar12 = ~local_50;
        *(byte *)(iVar18 + 0x20003309) = *(byte *)(iVar18 + 0x20003309) & ~bVar4;
        iVar18 = local_38 + 0x280 + iVar11;
        *(byte *)(iVar18 + 0x20003309) = (byte)(uVar12 >> 8) & *(byte *)(iVar18 + 0x20003309);
        iVar18 = local_38 + 0x300 + iVar11;
        *(byte *)(iVar18 + 0x20003309) = (byte)(uVar12 >> 0x10) & *(byte *)(iVar18 + 0x20003309);
        iVar18 = local_38 + 0x380 + iVar11;
        *(byte *)(iVar18 + 0x20003309) = (byte)(uVar12 >> 0x18) & *(byte *)(iVar18 + 0x20003309);
      }
      else {
        bVar1 = (byte)(uVar21 >> 8);
        bVar2 = (byte)(uVar21 >> 0x10);
        bVar3 = (byte)(uVar21 >> 0x18);
        bVar5 = (byte)(local_50 >> 8);
        bVar6 = (byte)(local_50 >> 0x10);
        bVar20 = (byte)(local_50 >> 0x18);
        if (cVar7 == '\x02') {
          *(byte *)(local_38 + iVar11 + 0x20003309) =
               *(byte *)(local_38 + iVar11 + 0x20003309) ^ (byte)uVar21;
          iVar18 = local_38 + 0x80 + iVar11;
          *(byte *)(iVar18 + 0x20003309) = *(byte *)(iVar18 + 0x20003309) ^ bVar1;
          iVar18 = local_38 + 0x100 + iVar11;
          *(byte *)(iVar18 + 0x20003309) = *(byte *)(iVar18 + 0x20003309) ^ bVar2;
          iVar18 = local_38 + 0x180 + iVar11;
          *(byte *)(iVar18 + 0x20003309) = *(byte *)(iVar18 + 0x20003309) ^ bVar3;
          iVar18 = local_38 + 0x200 + iVar11;
          *(byte *)(iVar18 + 0x20003309) = *(byte *)(iVar18 + 0x20003309) ^ bVar4;
          iVar18 = local_38 + 0x280 + iVar11;
          *(byte *)(iVar18 + 0x20003309) = *(byte *)(iVar18 + 0x20003309) ^ bVar5;
          iVar18 = local_38 + 0x300 + iVar11;
          *(byte *)(iVar18 + 0x20003309) = *(byte *)(iVar18 + 0x20003309) ^ bVar6;
          iVar18 = local_38 + 0x380 + iVar11;
          bVar20 = *(byte *)(iVar18 + 0x20003309) ^ bVar20;
        }
        else {
          if (cVar7 != '\0') goto LAB_10008868;
          *(byte *)(local_38 + iVar11 + 0x20003309) =
               *(byte *)(local_38 + iVar11 + 0x20003309) | (byte)uVar21;
          iVar18 = local_38 + 0x80 + iVar11;
          *(byte *)(iVar18 + 0x20003309) = *(byte *)(iVar18 + 0x20003309) | bVar1;
          iVar18 = local_38 + 0x100 + iVar11;
          *(byte *)(iVar18 + 0x20003309) = *(byte *)(iVar18 + 0x20003309) | bVar2;
          iVar18 = local_38 + 0x180 + iVar11;
          *(byte *)(iVar18 + 0x20003309) = *(byte *)(iVar18 + 0x20003309) | bVar3;
          iVar18 = local_38 + 0x200 + iVar11;
          *(byte *)(iVar18 + 0x20003309) = *(byte *)(iVar18 + 0x20003309) | bVar4;
          iVar18 = local_38 + 0x280 + iVar11;
          *(byte *)(iVar18 + 0x20003309) = *(byte *)(iVar18 + 0x20003309) | bVar5;
          iVar18 = local_38 + 0x300 + iVar11;
          *(byte *)(iVar18 + 0x20003309) = *(byte *)(iVar18 + 0x20003309) | bVar6;
          iVar18 = local_38 + 0x380 + iVar11;
          bVar20 = *(byte *)(iVar18 + 0x20003309) | bVar20;
        }
        *(byte *)(iVar18 + 0x20003309) = bVar20;
      }
LAB_10008868:
    }
    local_48 = local_48 + 1;
  } while( true );
}



/* FUN_100088f8 at 100088f8 */

void FUN_100088f8(char *param_1)

{
  for (; *param_1 != '\0'; param_1 = param_1 + 1) {
    FUN_100083cc();
  }
  return;
}



/* FUN_1000890c at 1000890c */

void FUN_1000890c(undefined4 param_1)

{
  char *pcVar1;
  uint extraout_r1;
  uint uVar2;
  
  FUN_1001e4d0(param_1,0xc);
  uVar2 = extraout_r1 & 0xff;
  pcVar1 = "C";
  if ((((1 < uVar2) && (pcVar1 = "D", 3 < uVar2)) && (pcVar1 = "E", uVar2 != 4)) &&
     (((pcVar1 = "F", 6 < uVar2 && (pcVar1 = "G", 8 < uVar2)) && (pcVar1 = "A", uVar2 == 0xb)))) {
    pcVar1 = "H";
  }
                    /* WARNING: Subroutine does not return */
  FUN_100088f8(pcVar1);
}



/* FUN_10008960 at 10008960 */

void FUN_10008960(uint param_1)

{
  if (param_1 < 0x1a) {
                    /* WARNING: Subroutine does not return */
    FUN_10027708();
  }
  return;
}



/* FUN_10008b14 at 10008b14 */

void FUN_10008b14(undefined1 param_1,undefined1 param_2,char *param_3)

{
  DAT_200041d2 = param_1;
  DAT_200041d3 = param_2;
  for (; *param_3 != '\0'; param_3 = param_3 + 1) {
    FUN_100083cc();
  }
  return;
}



/* FUN_10008b38 at 10008b38 */

void FUN_10008b38(int param_1)

{
  bool bVar1;
  char cVar2;
  
  if (param_1 < 0) {
    FUN_100083cc(0x2d);
    param_1 = -param_1;
  }
  bVar1 = false;
  cVar2 = '\0';
  for (; 9999 < param_1; param_1 = param_1 + -10000) {
    cVar2 = cVar2 + '\x01';
    bVar1 = true;
  }
  if ((cVar2 != '\0') || (bVar1)) {
    FUN_100083cc(cVar2 + '0');
  }
  cVar2 = '\0';
  for (; 999 < param_1; param_1 = param_1 + -1000) {
    cVar2 = cVar2 + '\x01';
    bVar1 = true;
  }
  if ((cVar2 != '\0') || (bVar1)) {
    FUN_100083cc(cVar2 + '0');
  }
  cVar2 = '\0';
  for (; 99 < param_1; param_1 = param_1 + -100) {
    cVar2 = cVar2 + '\x01';
    bVar1 = true;
  }
  if ((cVar2 != '\0') || (bVar1)) {
    FUN_100083cc(cVar2 + '0');
  }
  cVar2 = '\0';
  for (; 9 < param_1; param_1 = param_1 + -10) {
    cVar2 = cVar2 + '\x01';
    bVar1 = true;
  }
  if ((cVar2 != '\0') || (bVar1)) {
    FUN_100083cc(cVar2 + '0');
  }
  FUN_100083cc(param_1 + 0x30U & 0xff);
  return;
}



/* FUN_10008bf0 at 10008bf0 */

void FUN_10008bf0(void)

{
  DAT_200041d2 = 6;
  DAT_200041d3 = 5;
  DAT_200041d0 = 0;
  DAT_200041d1 = 1;
  DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
  FUN_100088f8("EUCLIDEAN BEAT GENERATOR");
}



/* FUN_10008f28 at 10008f28 */

undefined8 FUN_10008f28(int param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  char cVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = 0;
  puVar4 = &DAT_10028fee + param_1 * 6;
  cVar2 = DAT_200041d2;
  do {
    DAT_200041d2 = cVar2;
    uVar1 = *(ushort *)(puVar4 + iVar6 * 2);
    uVar5 = (uint)DAT_200041d3;
    iVar3 = (uint)uVar1 << uVar5;
    if (uVar5 < 0x20) {
      uVar5 = (uint)(uVar1 >> (0x20 - uVar5 & 0xff));
    }
    else {
      uVar5 = (uint)uVar1 << (uVar5 - 0x20 & 0xff);
    }
    iVar7 = 3;
    cVar2 = DAT_200041d2;
    do {
      DAT_200041d2 = cVar2;
      FUN_100081fc(DAT_200041d2,uVar5,iVar3,DAT_200041cf,iVar3,puVar4,param_3);
      iVar7 = iVar7 + -1;
      cVar2 = DAT_200041d2 + '\x01';
    } while (iVar7 != 0);
    iVar6 = iVar6 + 1;
  } while (iVar6 != 3);
  DAT_200041d2 = DAT_200041d2 + '\x03';
  return CONCAT44(puVar4,iVar3);
}



/* FUN_10008f90 at 10008f90 */

void FUN_10008f90(uint param_1)

{
  undefined1 uVar1;
  uint extraout_r1;
  uint extraout_r1_00;
  
  if (99 < param_1) {
    uVar1 = FUN_1001e4d0(param_1,100);
    FUN_10008f28(uVar1);
    FUN_1001e4d0(param_1,100);
    param_1 = extraout_r1 & 0xff;
  }
  if (9 < param_1) {
    uVar1 = FUN_1001e4d0(param_1,10);
    FUN_10008f28(uVar1);
    FUN_1001e4d0(param_1,10);
    param_1 = extraout_r1_00 & 0xff;
  }
  FUN_10008f28(param_1);
  return;
}



/* FUN_10008fd4 at 10008fd4 */

void FUN_10008fd4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  cVar2 = DAT_200041d2;
  do {
    DAT_200041d2 = cVar2;
    uVar1 = *(ushort *)(&DAT_10028f3a + iVar5 * 2 + param_1 * 0x12);
    uVar4 = (uint)DAT_200041d3;
    if (uVar4 < 0x20) {
      uVar3 = (uint)(uVar1 >> (0x20 - uVar4 & 0xff));
    }
    else {
      uVar3 = (uint)uVar1 << (uVar4 - 0x20 & 0xff);
    }
    FUN_100081fc(DAT_200041d2,uVar3,(uint)uVar1 << uVar4,DAT_200041cf,param_4);
    iVar5 = iVar5 + 1;
    cVar2 = DAT_200041d2 + '\x01';
  } while (iVar5 != 9);
  DAT_200041d2 = DAT_200041d2 + '\x03';
  return;
}



/* FUN_1000902c at 1000902c */

void FUN_1000902c(uint param_1)

{
  undefined1 uVar1;
  uint extraout_r1;
  uint extraout_r1_00;
  
  if (99 < param_1) {
    uVar1 = FUN_1001e4d0(param_1,100);
    FUN_10008fd4(uVar1);
    FUN_1001e4d0(param_1,100);
    param_1 = extraout_r1 & 0xff;
  }
  if (9 < param_1) {
    uVar1 = FUN_1001e4d0(param_1,10);
    FUN_10008fd4(uVar1);
    FUN_1001e4d0(param_1,10);
    param_1 = extraout_r1_00 & 0xff;
  }
  FUN_10008fd4(param_1);
  return;
}



/* FUN_10009070 at 10009070 */

void FUN_10009070(void)

{
  byte bVar1;
  char cVar2;
  char cVar3;
  
  bVar1 = DAT_2000403e;
  cVar2 = DAT_20003f85;
  if (DAT_2000403e == 0) {
    cVar2 = '\x1b';
    do {
      cVar3 = cVar2 + '\x05';
      FUN_1000773c(cVar2,6,2,0x34,0,1);
      cVar2 = cVar3;
    } while (cVar3 != '9');
    if (DAT_20003f85 == '\0') {
      DAT_200041d3 = 9;
      DAT_200041d0 = 2;
      DAT_200041d1 = 1;
      DAT_200041d2 = 0x3d;
      DAT_200041cf = DAT_20003f85;
                    /* WARNING: Subroutine does not return */
      FUN_100088f8("NOTE");
    }
    DAT_200041d2 = 0x3d;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041d3 = 6;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8(&DAT_100279bc);
  }
  if (DAT_2000403e < 3) {
    DAT_200041d2 = 0x2c;
    DAT_200041d3 = 5;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("KEYBOARD");
  }
  if (DAT_2000403e < 6) {
    FUN_1000834c(4,0x10,DAT_20003f6c >> 3 & 7,DAT_20003f6c & 7,0);
    FUN_1000764c(0x26,0x1f,2,2,0);
    FUN_1000764c(0x2a,0x1f,2,2,0);
    FUN_1000764c(0x2e,0x1f,2,2,0);
    FUN_10007eba(0x32,0x18,'\x01' - DAT_20003f7f,0);
    DAT_200041d3 = 7;
    DAT_200041d2 = 0x35;
    DAT_200041d0 = 2;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8(&DAT_10027a18);
  }
  if (DAT_2000403e < 9) {
    DAT_200041d2 = 0x25;
    DAT_200041d3 = 5;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("CLOCK SWING");
  }
  if (DAT_2000403e == 9) {
    DAT_200041d3 = 0xc;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041d2 = 0x35;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("MODE OF");
  }
  if (DAT_2000403e == 10) {
    DAT_200041d1 = 1;
    DAT_200041d2 = 0x17;
    DAT_200041d3 = 5;
    DAT_200041d0 = 0;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("PRESET ARP EDITOR");
  }
  if (DAT_2000403e < 0xe) {
    DAT_200041d2 = 0x26;
    DAT_200041d3 = 5;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("ARPEGGIATOR");
  }
  if (DAT_2000403e < 0x11) {
    DAT_200041d2 = 0x22;
    DAT_200041d3 = 5;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("ARP VARIATION");
  }
  if (DAT_2000403e < 0x14) {
    FUN_10008bf0(DAT_20004121,DAT_2000403e - 0x11);
                    /* WARNING: Subroutine does not return */
    FUN_100090ec();
  }
  if (DAT_2000403e < 0x16) {
    DAT_200041d2 = 0x18;
    DAT_200041d3 = 5;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("MISC ARP SETTINGS");
  }
  if (DAT_2000403e < 0x18) {
    DAT_200041d2 = 0x18;
    DAT_200041d3 = 5;
    DAT_200041d1 = 1;
    DAT_200041d0 = 0;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("MISC ARP SETTINGS");
  }
  if (DAT_2000403e != 0x18) {
    FUN_1000b5cc();
  }
  if (cVar2 == '\0') {
    DAT_200041d3 = 0x13;
    DAT_200041d0 = 2;
    DAT_200041d1 = 1;
    DAT_200041cf = cVar2;
    DAT_200041d2 = bVar1;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("SEQUENCE");
  }
  if (DAT_200041c3 < 3) {
    DAT_200041d2 = 10;
    DAT_200041d0 = 2;
    DAT_200041d3 = 0xe;
    DAT_200041cf = 0;
    DAT_200041d1 = 1;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8(&DAT_10027b7b);
  }
  if (DAT_200041c3 < 5) {
    DAT_200041d2 = 4;
    DAT_200041d3 = 0xe;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
    DAT_200041d0 = 2;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8(&DAT_10027b7b);
  }
  if (DAT_200041c3 < 9) {
    DAT_200041d2 = 0x1b;
    DAT_200041d3 = 1;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("HOLD A STEP AND");
  }
                    /* WARNING: Subroutine does not return */
  FUN_100090ec();
}



/* FUN_100090ec at 100090ec */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100090ec(void)

{
  char cVar1;
  
  if (_DAT_20002d08 == 0) {
    FUN_10010fde();
  }
  cVar1 = DAT_2000403f;
  if (DAT_2000403f != '\0') {
    FUN_1001100a();
  }
  FUN_1001e4d0(DAT_20000842,0xc);
  FUN_1000773c(0x16,0xb,0x53,0x2b);
  FUN_1000764c(0x17,0xc,0x51,0x29);
  DAT_200041d2 = 0x21;
  DAT_200041d3 = 0x11;
  DAT_200041d0 = 2;
  DAT_200041d1 = 1;
  DAT_200041cf = cVar1;
                    /* WARNING: Subroutine does not return */
  FUN_100088f8("OCTAVE");
}



/* FUN_10009176 at 10009176 */

void FUN_10009176(void)

{
  undefined1 unaff_r4;
  undefined1 *unaff_r5;
  undefined1 *unaff_r6;
  undefined1 unaff_r7;
  
  FUN_10008b38();
  FUN_10010f18();
  *unaff_r6 = 0x3d;
  DAT_200041d0 = unaff_r4;
  DAT_200041d1 = unaff_r7;
  *unaff_r5 = 6;
  DAT_200041cf = unaff_r4;
                    /* WARNING: Subroutine does not return */
  FUN_100088f8(&DAT_100279bc);
}



/* FUN_1000b5cc at 1000b5cc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_1000b5cc(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  uint extraout_r1;
  char cVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  char cVar10;
  uint unaff_r4;
  byte *pbVar11;
  byte bVar12;
  int iVar13;
  char cVar14;
  int in_stack_0000000c;
  byte *pbStack00000010;
  char *in_stack_00000014;
  undefined1 uStack00000028;
  byte bStack00000034;
  undefined1 uStack00000035;
  
  if (unaff_r4 < 0x1c) {
    if (unaff_r4 == 0x19) {
      if (in_stack_0000000c != 0) {
        FUN_100071a8(0x15,0xb,0);
        DAT_200041d2 = 0x30;
        DAT_200041d3 = 10;
        DAT_200041d0 = 2;
        DAT_200041d1 = 1;
        DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
        FUN_100088f8("STEP ");
      }
    }
    else if ((unaff_r4 == 0x1a) && (in_stack_0000000c != 0)) {
      FUN_100071a8(0x14,0x15,0);
      DAT_200041d2 = 0x2c;
      DAT_200041d3 = 0x16;
      DAT_200041d0 = 2;
      DAT_200041d1 = 1;
      DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
      FUN_100088f8("LIVE REC");
    }
    DAT_200041d2 = 0x1f;
    DAT_200041d3 = 5;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("KEY SEQUENCER");
  }
  if (unaff_r4 < 0x1e) {
    DAT_200041d2 = 0x2a;
    DAT_200041d3 = 5;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("SEQUENCER");
  }
  if (unaff_r4 < 0x21) {
    DAT_200041d2 = 0x2a;
    DAT_200041d3 = 5;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("SEQUENCER");
  }
  if (unaff_r4 < 0x23) {
    DAT_200041d2 = 0x25;
    DAT_200041d3 = 5;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("RANDOM NOTE");
  }
  if (unaff_r4 == 0x23) {
    uVar9 = 0;
    FUN_100076cc(1,0x19,0x7e,0);
    DAT_200041d2 = '\0';
    DAT_200041d3 = 0;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
    pbStack00000010 = &DAT_20003fbe;
    cVar10 = '\x06';
    do {
      cVar6 = cVar10 + -2;
      FUN_1000764c(cVar6,8,8,0x23);
      bVar12 = *pbStack00000010;
      iVar13 = (uVar9 & 0xf) * 0x10;
      if (bVar12 < 0x11) {
        FUN_1000773c(cVar6,0x19,8,'\x12' - bVar12);
        uVar7 = 0x11 - *pbStack00000010;
        if ((int)uVar9 <= (int)(uint)DAT_2000412f) {
          uVar3 = 4;
          do {
            uVar8 = uVar3 & 0xff;
            uVar4 = uVar3 & 0x7f;
            uVar3 = uVar3 - 1;
            FUN_10007380((iVar13 + 8) - uVar8 & 0xff,0x35 - uVar8 & 0xff,uVar4 << 1,0);
          } while (uVar3 != 0);
        }
      }
      else {
        uVar3 = 1;
        FUN_1000773c(cVar6,'*' - bVar12,8,bVar12 - 0x10);
        uVar7 = *pbStack00000010 - 0x11;
        if ((int)uVar9 <= (int)(uint)DAT_2000412f) {
          do {
            uVar8 = uVar3 & 0xff;
            uVar4 = uVar3 & 0x7f;
            uVar3 = uVar3 + 1;
            FUN_10007380((iVar13 + 8) - uVar8 & 0xff,uVar8 + 0x30 & 0xff,uVar4 << 1,0);
          } while (uVar3 != 5);
        }
      }
      if ((int)(uint)DAT_2000412f < (int)uVar9) {
        DAT_200041d3 = 0x34;
        DAT_200041d2 = cVar10;
                    /* WARNING: Subroutine does not return */
        FUN_100088f8(&DAT_10027ca6);
      }
      DAT_200041d2 = cVar6;
      if (uVar7 < 10) {
        DAT_200041d2 = cVar10;
      }
      DAT_200041d3 = 0x38;
      FUN_10008b38(uVar7);
      uVar9 = uVar9 + 1;
      pbStack00000010 = pbStack00000010 + 1;
      cVar10 = cVar10 + '\x10';
    } while (uVar9 != 8);
    uVar9 = 0;
    do {
      uVar3 = uVar9 & 0xff;
      uVar9 = uVar9 + 1;
      FUN_10007380(uVar3 + (uint)DAT_20003fc6 * 0x10 + 4 & 0xff,uVar3 + 1 & 0xff,
                   uVar3 * -2 + 8 & 0xff,0);
      bVar12 = DAT_200041c3;
    } while (uVar9 != 4);
    if (DAT_20003f85 == '\0') {
                    /* WARNING: Subroutine does not return */
      FUN_100090ec();
    }
    uVar9 = (uint)DAT_200041c3;
    if (uVar9 == 1) {
      FUN_1000773c(0x14,0xd,0x58,0x1a);
      DAT_200041d2 = 0x2c;
      DAT_200041d3 = 0x11;
      DAT_200041d0 = 0;
      DAT_200041d1 = bVar12;
      DAT_200041cf = 2;
                    /* WARNING: Subroutine does not return */
      FUN_100088f8("NUMBER OF");
    }
    if ((uVar9 == 0) || (uVar9 == DAT_2000412f + 3)) {
      FUN_1000773c(10,0x13,0x6c,0xd);
      DAT_200041d2 = 0xe;
      DAT_200041d3 = 0x17;
      DAT_200041d0 = 0;
      DAT_200041d1 = 1;
      DAT_200041cf = 2;
                    /* WARNING: Subroutine does not return */
      FUN_100088f8("PRESS ENCODER TO EXIT");
    }
    uVar9 = uVar9 * 0x10 - 0x1f & 0xff;
    if (DAT_200041c2 == '\0') {
      FUN_10007d6e(uVar9,0x2e,0xe,0x12);
                    /* WARNING: Subroutine does not return */
      FUN_100090ec();
    }
    FUN_10007d6e(uVar9,0x2e,0xe,0x12);
                    /* WARNING: Subroutine does not return */
    FUN_100090ec();
  }
  if (unaff_r4 == 0x24) {
    DAT_200041d2 = 0x26;
    DAT_200041d3 = 10;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
    DAT_200041d0 = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("TOUCH ACTION");
  }
  if (unaff_r4 == 0x25) {
    if (2 < DAT_20004127) {
      DAT_200041d0 = 0;
      DAT_200041d2 = 0xd;
      DAT_200041d3 = 1;
      DAT_200041d1 = 1;
      DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
      FUN_100088f8("HOLD STEP TO EDIT VALUE");
    }
    DAT_200041d2 = 9;
    DAT_200041d1 = 1;
    DAT_200041d3 = DAT_20004127 * '\x14' + '\b';
    DAT_200041d0 = 1;
    DAT_200041cf = 0;
    FUN_100083cc(DAT_20004127 + 0x41);
    FUN_10007d6e(4,DAT_20004127 * '\x14' + '\x04',0xf);
    uVar9 = 0x14;
    do {
      uVar3 = uVar9;
      FUN_10006de0(uVar3 & 0xff,DAT_20004127 * '\x14' + '\v',0);
      uVar9 = uVar3 + 2;
    } while (uVar3 + 2 != 0x1c);
    uVar3 = uVar3 + 6;
    uVar9 = 0;
    do {
      uVar4 = uVar9;
      FUN_1000773c(uVar3 - 4 & 0xff,7,0xb,0x32);
      FUN_1000773c(uVar3 - 3 & 0xff,8,9,
                   *(char *)(uVar4 + 0x20004155 + (uint)DAT_20004127 * 4) * -2 + '0');
      if ((byte)(&DAT_20004141)[DAT_20004127] == uVar4) {
        FUN_10007380(uVar3 - 1 & 0xff,2,5,0);
        FUN_10007380(uVar3,3,3,0);
        FUN_10007380(uVar3 + 1 & 0xff,4,1,0);
      }
      if ((int)(uint)(byte)(&DAT_20004133)[DAT_20004127] < (int)uVar4) {
        uVar9 = uVar3 + 2 & 0xff;
        FUN_10006de0(uVar3,2,0);
        FUN_10006de0(uVar9,2,0);
        FUN_10006de0(uVar3 + 1 & 0xff,3,0);
        FUN_10006de0(uVar3,4,0);
        FUN_10006de0(uVar9,4,0);
      }
      uVar3 = uVar3 + 0xf & 0xff;
      uVar9 = uVar4 + 1;
    } while (uVar4 + 1 != 4);
    uVar9 = 0;
    do {
      uVar3 = uVar9 + (uVar4 + 0xc) * (DAT_20003f86 & 3) + 0x1c;
      uVar9 = uVar9 + 2 & 0xff;
      FUN_10006ee0(uVar3 & 0xff,0x3b,5,0);
    } while (uVar9 != 0xc);
    FUN_10006ee0(0x58,1,0x3d,0);
    DAT_200041d2 = 0x61;
    DAT_200041d3 = 0xd;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("PRESS");
  }
  if (unaff_r4 == 0x26) {
    FUN_10006ee0(0x58,1,0x3d,0);
    if (2 < DAT_20004127) {
      DAT_200041d2 = 100;
      DAT_200041d3 = 10;
      DAT_200041d0 = 0;
      DAT_200041d1 = 1;
      DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
      FUN_100088f8("HOLD");
    }
    uVar9 = 0;
    do {
      uVar3 = uVar9 * 0x14 & 0xff;
      FUN_10007380(0x5d,uVar3 + 9 & 0xff,6,0);
      FUN_10007380(0x5d,uVar3 + 0xd & 0xff,6,0);
      DAT_200041d3 = (char)(uVar9 * 0x14) + '\x04';
      DAT_200041d2 = 0x67;
      if (DAT_20004127 == uVar9) {
        FUN_10008f90();
      }
      else {
        FUN_1000902c((&DAT_20004133)[uVar9] + '\x01');
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 != 3);
    cVar10 = '\v';
    iVar13 = 0;
    do {
      DAT_200041d2 = 9;
      DAT_200041d3 = cVar10 + -3;
      DAT_200041d0 = 1;
      DAT_200041d1 = 1;
      DAT_200041cf = 0;
      FUN_100083cc(iVar13 + 0x41U & 0xff);
      FUN_10007d6e(4,cVar10 + -7,0xf);
      uVar9 = 0x14;
      do {
        uVar3 = uVar9 & 0xff;
        uVar9 = uVar9 + 2;
        FUN_10006de0(uVar3,cVar10,0);
      } while (uVar9 != 0x1c);
      FUN_10007380(0x1c,cVar10,0x38,0);
      FUN_10006ee0(0x53,cVar10 + -2,5,0);
      for (uVar9 = 0; (int)uVar9 <= (int)(uint)(byte)(&DAT_20004133)[iVar13]; uVar9 = uVar9 + 1) {
        uVar3 = uVar9 * 0xf & 0xff;
        FUN_1000773c(uVar3 + 0x1c & 0xff,cVar10 + -5,0xb);
        if ((byte)(&DAT_20004141)[iVar13] != uVar9) {
          FUN_1000773c(uVar3 + 0x1d & 0xff,cVar10 + -4,9);
        }
      }
      cVar10 = cVar10 + '\x14';
      iVar13 = iVar13 + 1;
    } while (iVar13 != 3);
                    /* WARNING: Subroutine does not return */
    FUN_100090ec();
  }
  if (unaff_r4 == 0x27) {
    FUN_10006ee0(0x58,1,0x3d,0);
    if (2 < DAT_20004127) {
      DAT_200041d2 = 99;
      DAT_200041d3 = 6;
      DAT_200041d0 = 0;
      DAT_200041d1 = 1;
      DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
      FUN_100088f8("HOLD");
    }
    cVar10 = '\x05';
    uVar9 = 0;
    do {
      FUN_10007d6e(0x5e,cVar10,4);
      FUN_10007380(0x5c,cVar10 + '\x06',8,0);
      FUN_10007d6e(0x5e,cVar10 + '\t',4);
      DAT_200041d2 = 0x67;
      DAT_200041d3 = cVar10 + -1;
      if (DAT_20004127 == uVar9) {
        FUN_10008f90();
      }
      else {
        FUN_1000902c((&DAT_2000412c)[uVar9] + '\x01');
      }
      cVar10 = cVar10 + '\x14';
      uVar9 = uVar9 + 1;
    } while (uVar9 != 3);
    iVar13 = 0;
    cVar10 = '\b';
    do {
      DAT_200041d2 = 9;
      DAT_200041d0 = 1;
      DAT_200041d1 = 1;
      DAT_200041cf = 0;
      DAT_200041d3 = cVar10;
      FUN_100083cc(iVar13 + 0x41U & 0xff);
      uVar9 = 0x14;
      FUN_10007d6e(4,cVar10 + -4,0xf);
      do {
        uVar3 = uVar9 & 0xff;
        uVar9 = uVar9 + 2;
        FUN_10006de0(uVar3,cVar10 + '\x03',0);
      } while (uVar9 != 0x1c);
      bVar12 = 0;
      cVar14 = '\0';
      cVar6 = '\x1c';
      do {
        FUN_10006ee0(cVar6,cVar14 + cVar10 + -2,6,0);
        bVar12 = bVar12 + 1;
        if ((byte)(&DAT_2000412c)[iVar13] < bVar12) {
          if (cVar14 == '\0') {
            cVar14 = '\x05';
            bVar12 = 0;
          }
          else {
            bVar12 = 0;
            cVar14 = '\0';
          }
        }
        cVar6 = cVar6 + '\x01';
      } while (cVar6 != 'T');
      iVar13 = iVar13 + 1;
      cVar10 = cVar10 + '\x14';
    } while (iVar13 != 3);
                    /* WARNING: Subroutine does not return */
    FUN_100090ec();
  }
  if (unaff_r4 == 0x28) {
    uVar9 = 0;
    do {
      uVar3 = (uVar9 & 0xff) * 0x14;
      DAT_200041d3 = (char)uVar3 + '\b';
      DAT_200041d2 = 9;
      DAT_200041d0 = 1;
      DAT_200041d1 = 1;
      DAT_200041cf = 0;
      if ((byte)(&DAT_20004136)[uVar9] < 4) {
                    /* WARNING: Subroutine does not return */
        FUN_10027708();
      }
      uVar9 = uVar9 + 1;
      FUN_10007d6e(4,(uVar3 & 0xff) + 4 & 0xff,0xf);
    } while (uVar9 != 3);
    FUN_10007380(0x13,0x1f,0xb,0);
    FUN_10006ee0(0x17,6,5,0);
    FUN_10007cb4(0x1e,2,0,DAT_20004016);
    FUN_10006ee0(0x21,0x18,4,0);
    FUN_10006ee0(0x21,0x23,4,0);
    FUN_10007380(0x13,0xb,4,0);
    FUN_10006ee0(0x17,6,5,0);
    FUN_10007380(0x18,5,6,0);
    FUN_10007cb4(0x1e,0x1c,0,DAT_20004017);
    FUN_10006ee0(0x21,9,4,0);
    FUN_10007380(0x13,0x33,4,0);
    FUN_10006ee0(0x17,0x34,5,0);
    FUN_10007380(0x18,0x39,6,0);
    FUN_10007cb4(0x1e,0x36,0,DAT_20004018);
    FUN_10006ee0(0x21,0x32,4,0);
    DAT_200041d0 = 0;
    if (DAT_20004139 < 6) {
                    /* WARNING: Subroutine does not return */
      FUN_10027708();
    }
    if (2 < DAT_20004139) {
      if (DAT_20004139 == 4) {
        FUN_10006ee0(0x20,0x10,3,0);
        uVar2 = 0x20;
      }
      else {
        FUN_10006ee0(0x1e,0x10,3,0);
        uVar2 = 0x1e;
      }
      FUN_10006de0(uVar2,0x14,0);
    }
    if (DAT_20004127 == 3) {
      FUN_1000773c(0x1b,0xd,0x16,0xb);
    }
    else {
      FUN_1000764c(0x1b,0xd,0x16,0xb);
    }
    FUN_10007380(0x31,0x12,7,0);
    FUN_10007cb4(0x38,0xf,0,DAT_20004019);
    FUN_10006ee0(0x3b,0x16,4,0);
    if (DAT_2000413a < 6) {
                    /* WARNING: Subroutine does not return */
      FUN_10027708();
    }
    if (2 < DAT_2000413a) {
      if (DAT_2000413a == 4) {
        FUN_10006ee0(0x20,0x2a,3,0);
        uVar2 = 0x20;
      }
      else {
        FUN_10006ee0(0x1e,0x2a,3,0);
        uVar2 = 0x1e;
      }
      FUN_10006de0(uVar2,0x2e,0);
    }
    if (DAT_20004127 == 4) {
      FUN_1000773c(0x1b,0x27,0x16,0xb);
    }
    else {
      FUN_1000764c(0x1b,0x27,0x16,0xb);
    }
    FUN_10007380(0x31,0x2c,7,0);
    FUN_10007cb4(0x38,0x29,0,DAT_2000401a);
    FUN_10006ee0(0x3b,0x25,4,0);
    if (DAT_2000413b < 6) {
                    /* WARNING: Subroutine does not return */
      FUN_10027708();
    }
    if (2 < DAT_2000413b) {
      if (DAT_2000413b == 4) {
        FUN_10006ee0(0x3a,0x1d,3,0);
        uVar2 = 0x3a;
      }
      else {
        FUN_10006ee0(0x38,0x1d,3,0);
        uVar2 = 0x38;
      }
      FUN_10006de0(uVar2,0x21,0);
    }
    if (DAT_20004127 == 5) {
      FUN_1000773c(0x35,0x1a,0x16,0xb);
    }
    else {
      FUN_1000764c(0x35,0x1a,0x16,0xb);
    }
    FUN_10007380(0x4b,0x1f,3,0);
    FUN_10007cb4(0x4e,0x1c,0,DAT_2000401b);
    FUN_10006ee0(0x58,1,0x3d,0);
    if (5 < DAT_20004127) {
      DAT_200041d3 = 0xb;
      DAT_200041d0 = 0;
      DAT_200041d2 = 99;
      DAT_200041d1 = 1;
      DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
      FUN_100088f8("HOLD");
    }
    if (DAT_20004127 < 3) {
      DAT_200041d2 = 0x5e;
      DAT_200041d3 = 0x11;
      DAT_200041d0 = 0;
      DAT_200041d1 = 1;
      DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
      FUN_100088f8("NORMAL");
    }
    uVar9 = 0;
    DAT_200041d0 = 1;
    do {
      uVar3 = uVar9 * 0xb & 0xff;
      cVar10 = (char)(uVar9 * 0xb) + '\x13';
      DAT_200041d2 = 0x5d;
      DAT_200041d3 = cVar10;
      FUN_10008b38((uVar9 & 3) >> 1);
      DAT_200041d2 = 0x6b;
      DAT_200041d3 = cVar10;
      FUN_10008b38(uVar9 & 1);
      FUN_10007380(0x72,uVar3 + 0x15 & 0xff,3,0);
      FUN_10007380(0x72,uVar3 + 0x17 & 0xff,3,0);
      if ((byte)(&DAT_20004136)[DAT_20004127] < 6) {
                    /* WARNING: Subroutine does not return */
        FUN_10027708();
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 != 4);
    if ((byte)(&DAT_20004136)[DAT_20004127] < 6) {
                    /* WARNING: Subroutine does not return */
      FUN_10027708();
    }
    FUN_1000773c(0x5e,4,0x1d,0xb);
                    /* WARNING: Subroutine does not return */
    FUN_100090ec();
  }
  if (unaff_r4 < 0x2b) {
    DAT_200041d2 = 0x2a;
    DAT_200041d3 = 5;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("SEQUENCER");
  }
  if (unaff_r4 < 0x2e) {
    DAT_200041d2 = 0x19;
    DAT_200041d3 = 4;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("BINARY SEQUENCER");
  }
  if (unaff_r4 == 0x2e) {
    DAT_200041d2 = 6;
    DAT_200041d3 = 0xe;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("L");
  }
  if (unaff_r4 < 0x32) {
    FUN_10008bf0(0,unaff_r4 - 0x2f & 0xff);
    cVar10 = DAT_20003f8e;
    if (DAT_20003f8e == '\0') {
      FUN_1000773c(0,0x37,0x80,8);
      DAT_200041d2 = 0xb;
      DAT_200041d3 = 0x37;
      DAT_200041d0 = cVar10;
      DAT_200041d1 = 1;
      DAT_200041cf = cVar10;
                    /* WARNING: Subroutine does not return */
      FUN_100088f8("MANUAL MASK IS ACTIVE!");
    }
                    /* WARNING: Subroutine does not return */
    FUN_100090ec();
  }
  if (unaff_r4 == 0x34) {
    DAT_200041d2 = 0xe;
    DAT_200041d3 = 4;
    DAT_200041d0 = 2;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("SAMPLE");
  }
  if (unaff_r4 < 0x37) {
    if ((in_stack_0000000c == 0) || (unaff_r4 != 0x35)) {
      DAT_200041d2 = 0x20;
      DAT_200041d3 = 4;
      DAT_200041d1 = 1;
      DAT_200041d0 = 0;
      DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
      FUN_100088f8("NOTE QUANTIZER");
    }
    uVar1 = FUN_10005864(*(undefined2 *)((uint)DAT_20004125 * 2 + 0x2000080e),DAT_2000411e);
    FUN_10007f70(0x16,7,uVar1,1);
    DAT_200041d2 = 0x16;
    DAT_200041d3 = 0x34;
    DAT_200041d1 = 1;
    DAT_200041d0 = 0;
    DAT_200041cf = 0;
    FUN_10008960(DAT_20004125);
                    /* WARNING: Subroutine does not return */
    FUN_100090ec();
  }
  if (unaff_r4 == 0x37) {
    pbVar11 = &bStack00000034;
    FUN_1001f4d4(pbVar11,&DAT_1002aa00,0x18);
    FUN_1001f4d4(&uStack00000028,&DAT_1002aa18,0xc);
    uVar1 = FUN_10005864(_DAT_20000810,DAT_2000411e);
    FUN_10007f70(0x29,0xb,uVar1,0);
    if (*in_stack_00000014 == '\0') {
      DAT_200041d3 = 0x11;
      DAT_200041d0 = 0;
      DAT_200041d1 = 1;
      DAT_200041d2 = 8;
      DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
      FUN_100088f8("PRESS");
    }
    uVar9 = (uint)DAT_200041c3;
    if ((uVar9 == 0) || (uVar9 == 0xe)) {
      DAT_200041d2 = 8;
      DAT_200041d3 = 0x15;
      DAT_200041d0 = 0;
      DAT_200041d1 = 1;
      DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
      FUN_100088f8("PRESS");
    }
    if (uVar9 == 0xd) {
      iVar13 = 0;
      do {
        uVar9 = 0;
        if ((&uStack00000028)[iVar13] == '\0') {
          do {
            uVar3 = uVar9 & 0xff;
            uVar9 = uVar9 + 1;
            FUN_10007380(uVar3 + *pbVar11 & 0xff,(pbVar11[1] + 3) - uVar3 & 0xff,
                         uVar3 * -2 + 7 & 0xff,0);
          } while (uVar9 != 4);
        }
        else {
          uVar9 = 0;
          do {
            uVar3 = uVar9 & 0xff;
            uVar9 = uVar9 + 1;
            FUN_10007380(uVar3 + *pbVar11 & 0xff,uVar3 + pbVar11[1] & 0xff,uVar3 * -2 + 7 & 0xff,0);
          } while (uVar9 != 4);
        }
        iVar13 = iVar13 + 1;
        pbVar11 = pbVar11 + 2;
      } while (iVar13 != 0xc);
      DAT_200041d2 = 10;
      DAT_200041d3 = 0x14;
      DAT_200041d0 = 2;
      DAT_200041d1 = 1;
      DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
      FUN_100088f8(&DAT_10027d59);
    }
    FUN_1001e480(DAT_2000411e + uVar9 + -1,0xc);
    uVar9 = extraout_r1 & 0xff;
    if ((&uStack00000028)[extraout_r1] == '\0') {
      uVar3 = 0;
      do {
        uVar4 = uVar3 & 0xff;
        uVar3 = uVar3 + 1;
        FUN_10007380(uVar4 + pbVar11[extraout_r1 * 2] & 0xff,
                     ((byte)(&uStack00000035)[extraout_r1 * 2] + 3) - uVar4 & 0xff,
                     uVar4 * -2 + 7 & 0xff,0);
      } while (uVar3 != 4);
    }
    else {
      uVar3 = 0;
      do {
        uVar4 = uVar3 & 0xff;
        uVar3 = uVar3 + 1;
        FUN_10007380(uVar4 + pbVar11[extraout_r1 * 2] & 0xff,
                     uVar4 + (byte)(&uStack00000035)[extraout_r1 * 2] & 0xff,uVar4 * -2 + 7 & 0xff,0
                    );
      } while (uVar3 != 4);
    }
    DAT_200041d1 = 2;
    DAT_200041d0 = 2;
    iVar13 = FUN_100047b0(uVar9);
    if (iVar13 == 0) {
      DAT_200041d2 = 0xe;
      DAT_200041d3 = 0xf;
      FUN_1000890c(uVar9);
      FUN_10007e00(0xc,0x27,(int)(uint)_DAT_20000810 >> (extraout_r1 & 0xff) & 1,0);
                    /* WARNING: Subroutine does not return */
      FUN_100090ec();
    }
    DAT_200041d2 = 8;
    DAT_200041d3 = 0xf;
    FUN_1000890c(uVar9);
    DAT_200041d0 = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8(&DAT_100279c0);
  }
  if (unaff_r4 < 0x3a) {
    DAT_200041d2 = 0x28;
    DAT_200041d3 = 3;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("PORTAMENTO");
  }
  if (unaff_r4 < 0x3e) {
    DAT_200041d2 = 0x2f;
    DAT_200041d3 = 5;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("VIBRATO");
  }
  if (unaff_r4 < 0x40) {
    DAT_200041d2 = 0x15;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041d3 = 2;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("TOUCH RESPONSE");
  }
  if (unaff_r4 < 0x45) {
    FUN_10008048(2);
    FUN_10007abc(0x72,2,0);
    DAT_200041d2 = 10;
    DAT_200041d3 = 0x2e;
    DAT_200041d0 = 2;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
    if (DAT_2000403e - 0x40 < 5) {
                    /* WARNING: Subroutine does not return */
      FUN_10027708();
    }
    DAT_200041d2 = 0x69;
    DAT_200041d3 = 0x2e;
    DAT_200041d0 = 3;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
    if (DAT_2000403e - 0x40 < 5) {
                    /* WARNING: Subroutine does not return */
      FUN_10027708();
    }
    FUN_1000764c(6,0x2a,0x75,0x12);
    FUN_10006ee0(0x65,0x2a,0x12,0);
    if (DAT_20003f85 != '\0') {
      FUN_1000773c(7,0x2b,0x5e,0x10);
    }
    FUN_10007380(0,0x3f,_DAT_20003198 >> 9);
                    /* WARNING: Subroutine does not return */
    FUN_100090ec();
  }
  if (unaff_r4 < 0x47) {
    DAT_200041d2 = 0x14;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041d3 = 4;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("ENVELOPE GENERATOR");
  }
  if (unaff_r4 < 0x4b) {
    DAT_200041d3 = 6;
    DAT_200041d0 = 0;
    DAT_200041d2 = 2;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8(&DAT_10027ca2);
  }
  if (unaff_r4 < 0x4e) {
    DAT_200041d2 = 0x23;
    DAT_200041d3 = 4;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("VOLTAGE BANK");
  }
  if (unaff_r4 < 0x51) {
    FUN_1000701c(7,10,0);
    DAT_200041d2 = 0xb;
    DAT_200041d3 = 0x20;
    DAT_200041d0 = 2;
    DAT_200041d1 = 2;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("T");
  }
  if (unaff_r4 < 0x57) {
    DAT_200041d2 = 4;
    pcVar5 = "A";
    DAT_200041d3 = 0x18;
    DAT_200041d0 = 0;
    DAT_200041d1 = 3;
    DAT_200041cf = 0;
    if (0x53 < unaff_r4) {
      pcVar5 = "B";
    }
                    /* WARNING: Subroutine does not return */
    FUN_100088f8(pcVar5);
  }
  if (unaff_r4 == 0x59) {
    DAT_200041d2 = 0x1d;
    DAT_200041d3 = 3;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("PRESET MANAGER");
  }
  if (unaff_r4 == 0x5a) {
    DAT_200041d2 = 0xe;
    DAT_200041d0 = 0;
    DAT_200041d3 = 0xb;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("SCREENSAVER");
  }
  if (unaff_r4 != 0x58) {
    FUN_10010782();
  }
  if (DAT_200041c3 < 3) {
    DAT_200041d2 = 0xc;
    DAT_200041d3 = 7;
    DAT_200041d1 = 1;
    DAT_200041d0 = 0;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("KEYBOARD");
  }
  if (DAT_200041c3 < 6) {
    DAT_200041d2 = 0xb;
    DAT_200041d3 = 0xf;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("NOTE");
  }
  if (DAT_200041c3 < 10) {
    DAT_200041d2 = 0x1a;
    DAT_200041d3 = 0xb;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("TOUCH");
  }
  if (DAT_200041c3 < 0xd) {
    DAT_200041d2 = 5;
    DAT_200041d3 = 5;
    DAT_200041d0 = 2;
    DAT_200041d1 = 2;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8(&DAT_10027efc);
  }
                    /* WARNING: Subroutine does not return */
  FUN_100090ec();
}



/* FUN_10010782 at 10010782 */

void FUN_10010782(void)

{
  char *pcVar1;
  int unaff_r4;
  
  if (unaff_r4 != 0x5b) {
                    /* WARNING: Subroutine does not return */
    FUN_100090ec();
  }
  if (DAT_200041c3 < 10) {
    DAT_200041d2 = 0x31;
    DAT_200041d3 = 0xb;
    DAT_200041d1 = 1;
    pcVar1 = "NOTE";
    DAT_200041d0 = 0;
    DAT_200041cf = 0;
    if (4 < DAT_200041c3) {
      pcVar1 = "AUXILIARY";
    }
                    /* WARNING: Subroutine does not return */
    FUN_100088f8(pcVar1);
  }
  if (DAT_200041c3 == 10) {
    DAT_200041d3 = 0xb;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041d2 = 6;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("CONNECT NOTE OR PRESSURE");
  }
  if (DAT_200041c3 < 0xf) {
    DAT_200041d2 = 10;
    DAT_200041d0 = 0;
    DAT_200041d3 = 3;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("TOUCH THRESHOLD");
  }
  if (DAT_200041c3 == 0xf) {
    DAT_200041d2 = 0x19;
    DAT_200041d3 = 0x11;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
    DAT_200041d0 = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("PRESS ENCODER TO");
  }
  if (DAT_200041c3 == 0x10) {
    DAT_200041d2 = 0x13;
    DAT_200041d3 = 9;
    DAT_200041d0 = 2;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("WHITE BALANCE");
  }
  if (DAT_200041c3 == 0x11) {
    DAT_200041d3 = DAT_200041c3;
    DAT_200041d2 = 0x19;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
    DAT_200041d0 = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("PRESS ENCODER TO");
  }
  if (DAT_200041c3 == 0x12) {
    DAT_200041d2 = 0x19;
    DAT_200041d3 = 0x11;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
    DAT_200041d0 = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("PRESS ENCODER TO");
  }
  if (DAT_200041c3 == 0x13) {
    DAT_200041d2 = 0x19;
    DAT_200041d3 = 0x11;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
    DAT_200041d0 = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("PRESS ENCODER TO");
  }
                    /* WARNING: Subroutine does not return */
  FUN_100090ec();
}



/* FUN_10010f18 at 10010f18 */

void FUN_10010f18(void)

{
  char unaff_r4;
  char cVar1;
  char cVar2;
  
  cVar1 = '\x1e';
  do {
    cVar2 = cVar1 + '\x01';
    FUN_10007380(unaff_r4 * '\n' + cVar1,cVar1,cVar1 * -2 + 'C',0);
    cVar1 = cVar2;
  } while (cVar2 != '\"');
  FUN_10007380(0x21,0x25,0x3d,0);
  cVar1 = '!';
  do {
    cVar2 = cVar1 + '\n';
    FUN_10006ee0(cVar1,0x26,2,0);
    cVar1 = cVar2;
  } while (cVar2 != 'g');
  cVar1 = '\x1f';
  do {
    FUN_10006ee0(cVar1,0x2b,5,0);
    cVar2 = cVar1 + '\x02';
    FUN_10006ee0(cVar1 + '<',0x2b,5,0);
    cVar1 = cVar2;
  } while (cVar2 != '%');
  FUN_10006ee0(0x2a,0x2b,5,0);
  FUN_10006ee0(0x52,0x2b,5,0);
  FUN_10006ee0(0x2c,0x2b,5,0);
  FUN_10006ee0(0x54,0x2b,5,0);
  FUN_10006ee0(0x35,0x2b,5,0);
  FUN_10006ee0(0x49,0x2b,5,0);
  FUN_10007d6e(0x3d,0x2b,5);
  if (DAT_20003308 != '\0') {
    FUN_1000773c(1,1,2,2);
    DAT_20003308 = '\0';
  }
  return;
}



/* FUN_10010fde at 10010fde */

void FUN_10010fde(void)

{
  undefined4 uStack00000000;
  undefined4 uStack00000004;
  
  if (DAT_20003308 != '\0') {
    uStack00000004 = 1;
    uStack00000000 = 2;
    FUN_1000773c(1,1,2,2);
    DAT_20003308 = '\0';
  }
  return;
}



/* FUN_1001100a at 1001100a */

void FUN_1001100a(void)

{
  int unaff_r7;
  
  if (unaff_r7 == 1) {
    FUN_1000773c(0,0,0x80,0x40);
    DAT_200041d2 = 0x28;
    DAT_200041d3 = 10;
    DAT_200041d0 = 2;
    DAT_200041d1 = 3;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("T");
  }
  if (unaff_r7 == 2) {
    FUN_1000773c(3,0x2e,0x7a,0x11);
    FUN_1000764c(4,0x2f,0x78,0xf);
    DAT_200041d2 = 0xc;
    DAT_200041d3 = 0x34;
    DAT_200041d0 = 0;
    DAT_200041d1 = 1;
    DAT_200041cf = 0;
                    /* WARNING: Subroutine does not return */
    FUN_100088f8("SCALE SET TO KEYBOARD!");
  }
  if (DAT_20003308 != '\0') {
    FUN_1000773c(1,1,2,2);
    DAT_20003308 = '\0';
  }
  return;
}



/* FUN_1001111c at 1001111c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001111c(int param_1)

{
  undefined1 *puVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  byte bVar9;
  byte *pbVar10;
  uint uVar11;
  undefined1 *local_28;
  
  FUN_1001c258(&DAT_200013a8,0x1000);
  iVar8 = param_1 * 0xa8;
  local_28 = &DAT_20004077 + param_1 * 5;
  uVar4 = iVar8 + 0x32U & 0xffff;
  do {
    FUN_1001c2b0(&DAT_200013a8,uVar4,*local_28);
    local_28 = local_28 + 1;
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 != (iVar8 + 0x37U & 0xffff));
  bVar9 = DAT_2000402d & 0xf;
  cVar2 = FUN_1001e4d0(DAT_20000842,0xc);
  FUN_1001c2b0(&DAT_200013a8,uVar4,bVar9 | cVar2 << 5 | DAT_2000403b << 4);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x38U & 0xffff,DAT_200031a6);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x39U & 0xffff,
               (_DAT_200031a6 & 0x3fff) >> 8 | (DAT_200041ca & 3) << 6);
  iVar5 = 0;
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x3aU & 0xffff,
               DAT_20003fca << 6 | DAT_200041c8 << 7 | DAT_20003f9b | (DAT_2000405c & 3) << 4);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x3bU & 0xffff,DAT_200041cb & 0x1f);
  do {
    pbVar10 = (byte *)(iVar5 + 0x20004050);
    uVar4 = iVar8 + 0x3c + iVar5;
    iVar5 = iVar5 + 1;
    FUN_1001c2b0(&DAT_200013a8,uVar4 & 0xffff,*pbVar10 & 0x7f);
  } while (iVar5 != 0xc);
  pbVar10 = &DAT_2000405d;
  uVar4 = iVar8 + 0x48U & 0xffff;
  do {
    FUN_1001c2b0(&DAT_200013a8,uVar4,*pbVar10 & 0xf | pbVar10[1] << 4);
    uVar4 = uVar4 + 1 & 0xffff;
    pbVar10 = pbVar10 + 2;
  } while (uVar4 != (iVar8 + 0x4eU & 0xffff));
  FUN_1001c2b0(&DAT_200013a8,uVar4,DAT_20004125);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x4fU & 0xffff,DAT_20000810);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x50U & 0xffff,
               _DAT_20000810 >> 8 & 0xf | (DAT_2000411e & 0xf) << 4);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x51U & 0xffff,DAT_20003fb6);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x52U & 0xffff,(DAT_20003fb4 & 0x3f) << 1 | DAT_20003fb5);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x53U & 0xffff,DAT_200041df);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x54U & 0xffff,DAT_200041d9);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x55U & 0xffff,DAT_200041db << 1 | DAT_200041de);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x56U & 0xffff,DAT_200041d5);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x57U & 0xffff,DAT_200041d4);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x58U & 0xffff,DAT_200040ef);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x59U & 0xffff,DAT_20003f64);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x5aU & 0xffff,DAT_20003f82);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x5bU & 0xffff,DAT_200041c4);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x5cU & 0xffff,DAT_20003fba);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x5dU & 0xffff,DAT_20004100);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x5eU & 0xffff,DAT_20003f8a);
  iVar5 = 0;
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x5fU & 0xffff,DAT_20003f8c & 3 | (DAT_20003f8d & 7) << 2);
  do {
    uVar4 = iVar8 + 0x60 + iVar5;
    puVar1 = (undefined1 *)(iVar5 + 0x20004069);
    iVar5 = iVar5 + 1;
    FUN_1001c2b0(&DAT_200013a8,uVar4 & 0xffff,*puVar1);
  } while (iVar5 != 0xc);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x6cU & 0xffff,DAT_200041ee);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x6dU & 0xffff,DAT_200041e5);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x6eU & 0xffff,
               DAT_200041eb & 0x3f | DAT_200041ea << 7 | DAT_200041e9 << 6);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x6fU & 0xffff,DAT_200041e2 & 3 | (DAT_200041ed & 0xf) << 2);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x70U & 0xffff,DAT_20004029);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x71U & 0xffff,DAT_200031b6);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x72U & 0xffff,
               _DAT_200031b6 >> 8 & 1 | (DAT_20004025 & 0x1f) << 1);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x73U & 0xffff,DAT_2000402a);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x74U & 0xffff,DAT_200031b8);
  FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x75U & 0xffff,
               _DAT_200031b8 >> 8 & 1 | (DAT_20004026 & 0x1f) << 1);
  uVar11 = iVar8 + 0x7dU & 0xffff;
  uVar4 = iVar8 + 0x76U & 0xffff;
  do {
    uVar7 = uVar4 + 1 & 0xffff;
    FUN_1001c2b0(&DAT_200013a8,uVar4,0);
    uVar4 = uVar7;
  } while (uVar7 != uVar11);
  if (DAT_2000402d - 2 < 3) {
    pbVar10 = &DAT_20003fbe;
    do {
      FUN_1001c2b0(&DAT_200013a8,uVar11,pbVar10[1] << 6 | *pbVar10 & 0x3f);
      FUN_1001c2b0(&DAT_200013a8,uVar11 + 1 & 0xffff,pbVar10[1] >> 2 & 0xf | pbVar10[2] << 4);
      FUN_1001c2b0(&DAT_200013a8,uVar11 + 2 & 0xffff,pbVar10[2] >> 4 & 3 | pbVar10[3] << 2);
      uVar11 = uVar11 + 3 & 0xffff;
      pbVar10 = pbVar10 + 4;
    } while (uVar11 != (iVar8 + 0x83U & 0xffff));
    FUN_1001c2b0(&DAT_200013a8,uVar11,DAT_20004130 & 3 | DAT_20004132 << 2);
    FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x84U & 0xffff,DAT_2000411b & 0x3f | DAT_2000411d << 6);
    FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x85U & 0xffff,
                 DAT_2000411d >> 2 & 0xf | (DAT_2000412f & 7) << 4);
    FUN_1001c2b0(&DAT_200013a8,iVar8 + 0x86U & 0xffff,DAT_20003faf & 0x3f);
  }
  if (DAT_2000402d - 1 < 7) {
    uVar4 = FUN_10027658();
    iVar5 = 0;
    iVar8 = 0x20004155;
    local_28 = (undefined1 *)uVar4;
    do {
      uVar11 = 0;
      do {
        uVar7 = uVar11 & 0xff;
        pbVar10 = (byte *)(iVar8 + uVar11);
        uVar3 = (int)local_28 + uVar11;
        uVar11 = uVar11 + 1;
        FUN_1001c2b0(&DAT_200013a8,uVar3 & 0xffff,
                     (int)(uint)*(byte *)(iVar8 + 7) >> uVar7 & 1U | (*pbVar10 & 0x7f) << 1);
      } while (uVar11 != 7);
      iVar5 = iVar5 + 8;
      local_28 = (undefined1 *)((int)local_28 + 7U & 0xffff);
      iVar8 = iVar8 + 8;
    } while (iVar5 != 0x40);
    uVar7 = 0;
    uVar11 = uVar4 + 0x38;
    do {
      uVar6 = uVar11 & 0xffff;
      uVar3 = uVar7 & 0xff;
      uVar11 = uVar6 + 1;
      uVar7 = uVar7 + 8;
      FUN_1001c2b0(&DAT_200013a8,uVar6,_DAT_20002f38 >> uVar3 & 0xff);
    } while (uVar7 != 0x20);
    uVar11 = 0;
    uVar4 = uVar4 + 0x3c;
    do {
      uVar3 = uVar4 & 0xffff;
      uVar7 = uVar11 & 0xff;
      uVar4 = uVar3 + 1;
      uVar11 = uVar11 + 8;
      FUN_1001c2b0(&DAT_200013a8,uVar3,_DAT_20002f3c >> uVar7 & 0xff);
    } while (uVar11 != 0x20);
  }
  FUN_1001c2d4(&DAT_200013a8);
  FUN_1001c388(&DAT_200013a8);
  DAT_20004124 = 0;
  DAT_20000878 = (char)param_1;
  DAT_20004123 = 1;
  return;
}



/* FUN_10011e3c at 10011e3c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10011e3c(uint param_1)

{
  undefined1 uVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  undefined1 *puVar6;
  byte *pbVar7;
  int iVar8;
  uint local_2c;
  uint local_28;
  
  local_28 = param_1;
  if (0x17 < param_1) {
    local_28 = 0;
  }
  FUN_1001c258(&DAT_200013a8,0x1000);
  iVar8 = local_28 * 0xa8;
  puVar6 = &DAT_20004077 + local_28 * 5;
  uVar4 = iVar8 + 0x32U & 0xffff;
  do {
    uVar1 = FUN_1001c298(&DAT_200013a8,uVar4);
    uVar4 = uVar4 + 1 & 0xffff;
    *puVar6 = uVar1;
    puVar6 = puVar6 + 1;
  } while (uVar4 != (iVar8 + 0x37U & 0xffff));
  uVar4 = FUN_1001c298(&DAT_200013a8,uVar4);
  DAT_2000402d = (byte)uVar4 & 0xf;
  DAT_2000403b = (byte)(uVar4 >> 4) & 1;
  DAT_20000842 = (char)(uVar4 >> 5) * '\f';
  DAT_20004030 = DAT_20000842;
  _DAT_200031a6 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x38U & 0xffff);
  uVar4 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x39U & 0xffff);
  _DAT_200031a6 = (ushort)((uVar4 & 0x3f) << 8) | _DAT_200031a6;
  DAT_200041ca = (undefined1)(uVar4 >> 6);
  uVar4 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x3aU & 0xffff);
  DAT_20003f9b = (byte)uVar4 & 0xf;
  DAT_2000405c = (undefined1)((uVar4 & 0x3f) >> 4);
  DAT_20003fca = (byte)(uVar4 >> 6) & 1;
  DAT_200041c8 = (undefined1)(uVar4 >> 7);
  bVar2 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x3bU & 0xffff);
  iVar5 = 0;
  DAT_200041cb = bVar2 & 0x1f;
  do {
    bVar2 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x3c + iVar5 & 0xffff);
    *(byte *)(iVar5 + 0x20004050) = bVar2 & 0x7f;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0xc);
  pbVar7 = &DAT_2000405d;
  uVar4 = iVar8 + 0x48U & 0xffff;
  do {
    uVar3 = FUN_1001c298(&DAT_200013a8,uVar4);
    *pbVar7 = (byte)uVar3 & 0xf;
    uVar4 = uVar4 + 1 & 0xffff;
    pbVar7[1] = (byte)(uVar3 >> 4);
    pbVar7 = pbVar7 + 2;
  } while (uVar4 != (iVar8 + 0x4eU & 0xffff));
  DAT_20004125 = FUN_1001c298(&DAT_200013a8,uVar4);
  _DAT_20000810 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x4fU & 0xffff);
  uVar4 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x50U & 0xffff);
  _DAT_20000810 = (ushort)((uVar4 & 0xf) << 8) | _DAT_20000810;
  DAT_2000411e = (undefined1)(uVar4 >> 4);
  DAT_20003fb6 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x51U & 0xffff);
  uVar4 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x52U & 0xffff);
  DAT_20003fb5 = (byte)uVar4 & 1;
  DAT_20003fb4 = (undefined1)((uVar4 & 0x7f) >> 1);
  DAT_200041df = FUN_1001c298(&DAT_200013a8,iVar8 + 0x53U & 0xffff);
  DAT_200041d9 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x54U & 0xffff);
  uVar4 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x55U & 0xffff);
  DAT_200041de = (byte)uVar4 & 1;
  DAT_200041db = (undefined1)(uVar4 >> 1);
  DAT_200041d5 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x56U & 0xffff);
  DAT_200041d4 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x57U & 0xffff);
  DAT_200040ef = FUN_1001c298(&DAT_200013a8,iVar8 + 0x58U & 0xffff);
  DAT_20003f64 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x59U & 0xffff);
  DAT_20003f82 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x5aU & 0xffff);
  DAT_200041c4 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x5bU & 0xffff);
  DAT_20003fba = FUN_1001c298(&DAT_200013a8,iVar8 + 0x5cU & 0xffff);
  DAT_20004100 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x5dU & 0xffff);
  DAT_20003f8a = FUN_1001c298(&DAT_200013a8,iVar8 + 0x5eU & 0xffff);
  uVar4 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x5fU & 0xffff);
  iVar5 = 0;
  DAT_20003f8c = (byte)uVar4 & 3;
  DAT_20003f8d = (undefined1)((uVar4 & 0x1f) >> 2);
  do {
    uVar1 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x60 + iVar5 & 0xffff);
    *(undefined1 *)(iVar5 + 0x20004069) = uVar1;
    iVar5 = iVar5 + 1;
  } while (iVar5 != 0xc);
  DAT_200041ee = FUN_1001c298(&DAT_200013a8,iVar8 + 0x6cU & 0xffff);
  DAT_200041e5 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x6dU & 0xffff);
  uVar4 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x6eU & 0xffff);
  DAT_200041eb = (byte)uVar4 & 0x3f;
  DAT_200041e9 = (undefined1)((uVar4 & 0x7f) >> 6);
  DAT_200041ea = (undefined1)(uVar4 >> 7);
  uVar4 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x6fU & 0xffff);
  DAT_200041e2 = (byte)uVar4 & 3;
  DAT_200041ed = (undefined1)((uVar4 & 0x3f) >> 2);
  DAT_20004029 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x70U & 0xffff);
  _DAT_200031b6 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x71U & 0xffff);
  uVar4 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x72U & 0xffff);
  _DAT_200031b6 = (ushort)((uVar4 & 1) << 8) | _DAT_200031b6;
  DAT_20004025 = (byte)(uVar4 >> 1) & 0x1f;
  DAT_2000402a = FUN_1001c298(&DAT_200013a8,iVar8 + 0x73U & 0xffff);
  _DAT_200031b8 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x74U & 0xffff);
  uVar4 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x75U & 0xffff);
  _DAT_200031b8 = (ushort)((uVar4 & 1) << 8) | _DAT_200031b8;
  DAT_20004026 = (byte)(uVar4 >> 1) & 0x1f;
  local_2c = iVar8 + 0x7dU & 0xffff;
  uVar4 = iVar8 + 0x76U & 0xffff;
  do {
    FUN_1001c298(&DAT_200013a8,uVar4);
    uVar4 = uVar4 + 1 & 0xffff;
  } while (uVar4 != local_2c);
  if (DAT_2000402d - 2 < 3) {
    pbVar7 = &DAT_20003fbe;
    do {
      uVar4 = FUN_1001c298(&DAT_200013a8,local_2c);
      *pbVar7 = (byte)uVar4 & 0x3f;
      uVar3 = local_2c + 2;
      pbVar7[1] = (byte)(uVar4 >> 6);
      uVar4 = FUN_1001c298(&DAT_200013a8,local_2c + 1 & 0xffff);
      pbVar7[1] = (byte)((uVar4 & 0xf) << 2) | pbVar7[1];
      pbVar7[2] = (byte)(uVar4 >> 4);
      local_2c = local_2c + 3 & 0xffff;
      uVar4 = FUN_1001c298(&DAT_200013a8,uVar3 & 0xffff);
      pbVar7[2] = (byte)((uVar4 & 3) << 4) | pbVar7[2];
      pbVar7[3] = (byte)(uVar4 >> 2);
      pbVar7 = pbVar7 + 4;
    } while (local_2c != (iVar8 + 0x83U & 0xffff));
    uVar4 = FUN_1001c298(&DAT_200013a8,local_2c);
    DAT_20004130 = (byte)uVar4 & 3;
    DAT_20004132 = (undefined1)(uVar4 >> 2);
    uVar4 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x84U & 0xffff);
    DAT_2000411b = (byte)uVar4 & 0x3f;
    DAT_2000411d = (byte)(uVar4 >> 6);
    uVar4 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x85U & 0xffff);
    DAT_2000411d = (byte)((uVar4 & 0xf) << 2) | DAT_2000411d;
    DAT_2000412f = (undefined1)((uVar4 & 0x7f) >> 4);
    local_2c = iVar8 + 0x87U & 0xffff;
    bVar2 = FUN_1001c298(&DAT_200013a8,iVar8 + 0x86U & 0xffff);
    DAT_20003faf = bVar2 & 0x3f;
  }
  if (DAT_2000402d - 1 < 7) {
    FUN_10027658();
    uVar4 = FUN_1001c298(&DAT_200013a8,local_2c);
    DAT_20003c57 = (byte)uVar4 & 1;
    DAT_20003dd6 = (byte)(uVar4 >> 1) & 1;
    DAT_20003c52 = (byte)(uVar4 >> 2) & 7;
    DAT_20003c5c = (undefined1)(uVar4 >> 5);
    uVar4 = FUN_1001c298(&DAT_200013a8,local_2c + 1 & 0xffff);
    DAT_20003dec = (byte)uVar4 & 7;
    DAT_20003f8e = (undefined1)(uVar4 >> 3);
    uVar4 = FUN_1001c298(&DAT_200013a8,local_2c + 2 & 0xffff);
    DAT_20003f97 = (byte)uVar4 & 0xf;
    DAT_20003f93 = (undefined1)(uVar4 >> 4);
    uVar4 = FUN_1001c298(&DAT_200013a8,local_2c + 3 & 0xffff);
    DAT_20003df0 = (byte)uVar4 & 0xf;
    DAT_20003faf = (byte)(uVar4 >> 4);
    uVar4 = FUN_1001c298(&DAT_200013a8,local_2c + 4 & 0xffff);
    DAT_20003faf = (byte)((uVar4 & 3) << 4) | DAT_20003faf;
    DAT_20003dd2 = (byte)(uVar4 >> 2) & 1;
    DAT_20003dda = FUN_1001c298(&DAT_200013a8,local_2c + 5 & 0xffff);
    bVar2 = FUN_1001c298(&DAT_200013a8,local_2c + 6 & 0xffff);
    DAT_20003dd2 = bVar2 & 1;
  }
  FUN_1001c388(&DAT_200013a8);
  if (DAT_20003f7f == '\0') {
    FUN_10003dcc(_DAT_200031a6);
  }
  DAT_20000878 = (char)local_28;
  DAT_20004123 = 1;
  return;
}



/* FUN_10012bb8 at 10012bb8 */

void FUN_10012bb8(undefined4 param_1)

{
  FUN_1001c258(&DAT_200013a8,0x1000);
  FUN_1001c2b0(&DAT_200013a8,0x31,param_1);
  FUN_1001c2d4(&DAT_200013a8);
  FUN_1001c388(&DAT_200013a8);
  DAT_20004123 = 0;
  return;
}



/* FUN_10012bf0 at 10012bf0 */

void FUN_10012bf0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  
  uVar2 = 0;
  FUN_1001c258(&DAT_200013a8,0x1000,param_3,param_4,param_4);
  puVar4 = &DAT_20004077;
  do {
    iVar3 = 0;
    do {
      uVar1 = FUN_1001c298(&DAT_200013a8,uVar2 + 0x32 + iVar3 & 0xffff);
      puVar4[iVar3] = uVar1;
      iVar3 = iVar3 + 1;
    } while (iVar3 != 5);
    uVar2 = uVar2 + 0xa8 & 0xffff;
    puVar4 = puVar4 + 5;
  } while (uVar2 != 0xfc0);
  FUN_1001c388(&DAT_200013a8);
  return;
}



/* FUN_10012c38 at 10012c38 */

void FUN_10012c38(void)

{
  DAT_20000878 = 0xff;
  DAT_20004126 = 0;
  FUN_10012bf0();
  DAT_20004124 = 0;
  DAT_20004123 = 0;
  return;
}



/* FUN_10012c64 at 10012c64 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10012c64(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = (uint)_DAT_20003230 * 0x4000;
  uVar2 = _DAT_20002c28 + (uint)_DAT_20003230 * -0x4000;
  if ((int)_DAT_20002c28 <= (int)uVar3) {
    if ((int)uVar3 <= (int)_DAT_20002c28) goto LAB_10012c8a;
    uVar2 = uVar3 - _DAT_20002c28;
  }
  if (uVar2 < 0xfa00001) {
    if (uVar2 < 0x7d00001) {
      if (uVar2 < 0x3e80001) {
        if (uVar2 < 0xc80001) {
          iVar4 = ((int)uVar3 >> 0xb) + _DAT_20002c28;
          iVar1 = (int)_DAT_20002c28 >> 0xb;
        }
        else {
          iVar4 = ((int)uVar3 >> 10) + _DAT_20002c28;
          iVar1 = (int)_DAT_20002c28 >> 10;
        }
      }
      else {
        iVar4 = ((int)uVar3 >> 8) + _DAT_20002c28;
        iVar1 = (int)_DAT_20002c28 >> 8;
      }
    }
    else {
      iVar4 = ((int)uVar3 >> 6) + _DAT_20002c28;
      iVar1 = (int)_DAT_20002c28 >> 6;
    }
  }
  else {
    iVar4 = ((int)uVar3 >> 4) + _DAT_20002c28;
    iVar1 = (int)_DAT_20002c28 >> 4;
  }
  uVar3 = iVar4 - iVar1;
LAB_10012c8a:
  if ((int)uVar3 < 0x40000000) {
    _DAT_20002c28 = uVar3 & (int)~uVar3 >> 0x1f;
  }
  else {
    _DAT_20002c28 = 0x3fffffff;
  }
  _DAT_200032fc = (short)((int)_DAT_20002c28 >> 0xe);
  if ((int)_DAT_20002c28 < (int)_DAT_20002d20) {
    uVar3 = _DAT_20002d20 - (*(uint *)(&DAT_10029d8c + (uint)DAT_200041d4 * 4) >> 2);
    uVar2 = _DAT_20002c28;
    if (((int)_DAT_20002c28 <= (int)uVar3) &&
       (uVar2 = _DAT_20002d20, (int)uVar3 < (int)_DAT_20002d20)) {
      uVar2 = uVar3;
    }
    _DAT_20002d20 = uVar2;
  }
  else if ((int)_DAT_20002d20 < (int)_DAT_20002c28) {
    uVar2 = (*(uint *)(&DAT_10029d8c + (uint)DAT_200041d5 * 4) >> 2) + _DAT_20002d20;
    if (((int)_DAT_20002d20 <= (int)uVar2) &&
       (_DAT_20002d20 = uVar2, (int)_DAT_20002c28 < (int)uVar2)) {
      _DAT_20002d20 = _DAT_20002c28;
    }
  }
  _DAT_200032fa = (short)((int)_DAT_20002d20 >> 0xe);
  _DAT_200031b2 = (short)((uint)DAT_200040ef * ((int)_DAT_20002d20 >> 0xe & 0xffffU) >> 8);
  return;
}



/* FUN_10012d68 at 10012d68 */

void FUN_10012d68(void)

{
  DAT_200041d5 = 0;
  DAT_200041d4 = 0;
  return;
}



/* FUN_10012d7c at 10012d7c */

/* WARNING: Removing unreachable block (ram,0x10012de4) */
/* WARNING: Removing unreachable block (ram,0x10012e1c) */
/* WARNING: Removing unreachable block (ram,0x10012e26) */
/* WARNING: Removing unreachable block (ram,0x10012e2a) */
/* WARNING: Removing unreachable block (ram,0x10012ed4) */
/* WARNING: Removing unreachable block (ram,0x10012dec) */
/* WARNING: Removing unreachable block (ram,0x10012e2e) */
/* WARNING: Removing unreachable block (ram,0x10012e36) */
/* WARNING: Removing unreachable block (ram,0x10012df0) */
/* WARNING: Removing unreachable block (ram,0x10012df4) */
/* WARNING: Removing unreachable block (ram,0x10012e12) */
/* WARNING: Removing unreachable block (ram,0x10012df8) */
/* WARNING: Removing unreachable block (ram,0x10012e00) */
/* WARNING: Removing unreachable block (ram,0x10012e16) */
/* WARNING: Removing unreachable block (ram,0x10012e04) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10012d7c(int param_1,int param_2)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 * 8 + 0x20003f9f + param_2);
  if (DAT_20003f88 < 4) {
                    /* WARNING: Subroutine does not return */
    FUN_10027708();
  }
  if (DAT_20003f8c < 2) {
    if (cVar1 == '\0') {
      if (((DAT_20003f89 == '\0') || (DAT_20003f88 != 2)) ||
         (DAT_20003fbb != '\0' || DAT_20003f8c != 0)) goto LAB_10012dc2;
      DAT_20003f88 = 3;
    }
    else {
      if (DAT_20003f89 != '\0') goto LAB_10012dc2;
      DAT_20003f88 = 0;
    }
    _DAT_20002808 = 0;
  }
  else if (DAT_20003f88 == 4) {
    DAT_20003f88 = 0;
  }
LAB_10012dc2:
  DAT_20003f89 = cVar1;
  if (DAT_20003f88 < 4) {
                    /* WARNING: Subroutine does not return */
    FUN_10027708(DAT_20003f88);
  }
  if (DAT_20003f8d < 6) {
                    /* WARNING: Subroutine does not return */
    FUN_10027708(DAT_20003f8d);
  }
  _DAT_20003198 = 0;
  _DAT_200031b0 = 0;
  return;
}



/* FUN_10012f28 at 10012f28 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10012f28(void)

{
  DAT_20003f64 = 0x19;
  DAT_20003f82 = 0x60;
  DAT_200041c4 = 0x57;
  DAT_20003fba = 0;
  DAT_20004100 = 0x56;
  DAT_20003f8c = 0;
  DAT_20003f8d = 0;
  DAT_20003f89 = 0;
  DAT_20003f88 = 4;
  _DAT_20002808 = 0;
  return;
}



/* FUN_10012f88 at 10012f88 */

void FUN_10012f88(void)

{
  int iVar1;
  
  iVar1 = FUN_1001c3c8((uint)DAT_200041eb << 2);
  iVar1 = iVar1 + (uint)DAT_200041eb * -2;
  if (iVar1 < 0x80) {
    if (iVar1 < -0x7f) {
      iVar1 = -0x7f;
    }
  }
  else {
    iVar1 = 0x7f;
  }
  DAT_200041ec = (char)iVar1;
  return;
}



/* FUN_10012fbc at 10012fbc */

void FUN_10012fbc(void)

{
  DAT_200041e1 = 0;
  DAT_200041ec = 0;
  return;
}



/* FUN_10012fd0 at 10012fd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined8 FUN_10012fd0(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  byte bVar4;
  byte *pbVar5;
  char cVar6;
  
  cVar1 = DAT_200041e4;
  if (DAT_200041ea != '\0') {
    if (DAT_2000402d == '\x01') {
      pbVar5 = &DAT_20003c61;
LAB_10012fe4:
      bVar4 = *pbVar5;
    }
    else {
      if (DAT_2000402d != '\x04') {
        pbVar5 = &DAT_20003fc8;
        goto LAB_10012fe4;
      }
      bVar4 = *(byte *)(DAT_20004075 + 0x20004155) & 0xf;
    }
    if (DAT_200041e8 != bVar4) {
      DAT_200041e7 = '\x01';
      DAT_200041e8 = bVar4;
    }
  }
  if (DAT_200041e2 == '\0') {
    if (DAT_200041e1 != DAT_200041e8) {
      DAT_200041e1 = DAT_200041e8;
      FUN_10012f88();
    }
  }
  else {
    if (DAT_200041e2 == '\x01') {
      cVar6 = *(char *)(param_1 * 8 + 0x20003f9f + param_2);
    }
    else {
      if (DAT_200041e2 != '\x02') goto LAB_100130f8;
      cVar6 = DAT_20003f80;
    }
    if (cVar6 != '\0') {
      if (DAT_200041e4 == '\0') {
        FUN_10012f88();
        if (DAT_200041e7 == '\0') {
          uVar3 = (uint)DAT_200041ed;
          if (DAT_200041e3 == '\0') {
            DAT_200041e1 = DAT_200041e1 + 1;
            if (((int)uVar3 < (int)(char)DAT_200041e1) && (DAT_200041e1 = 0, DAT_200041e9 != '\0'))
            {
              DAT_200041e1 = DAT_200041ed - 1 & (byte)((int)-uVar3 >> 0x1f);
              DAT_200041e3 = '\x01';
            }
          }
          else {
            uVar2 = DAT_200041e1 - 1 & 0xff;
            if ((int)((DAT_200041e1 - 1) * 0x1000000) < 0) {
              DAT_200041e3 = DAT_200041e7;
              uVar2 = 1;
            }
            DAT_200041e1 = (byte)uVar2;
            if (uVar3 < uVar2) {
              DAT_200041e1 = DAT_200041ed;
            }
          }
        }
        else {
          DAT_200041e7 = cVar1;
          DAT_200041e1 = DAT_200041e8;
          DAT_200041e3 = cVar1;
        }
      }
      goto LAB_10013046;
    }
  }
LAB_100130f8:
  cVar6 = '\0';
LAB_10013046:
  DAT_200041e4 = cVar6;
  if ((DAT_200041e2 != '\0') && (DAT_20003f84 != '\0')) {
    FUN_10012fbc();
  }
  uVar3 = (uint)*(byte *)(DAT_200041e1 + 0x20004069) + (int)DAT_200041ec;
  if ((int)uVar3 < 0x100) {
    uVar3 = uVar3 & (int)~uVar3 >> 0x1f;
  }
  else {
    uVar3 = 0xff;
  }
  uVar2 = (uint)DAT_200041ef;
  uVar3 = uVar3 * 0x400000;
  if (uVar2 == 0) {
    _DAT_20002f88 = uVar3;
  }
  else if (uVar3 < _DAT_20002f88) {
    uVar2 = _DAT_20002f88 - (*(uint *)(&DAT_10029588 + uVar2 * 4) >> 2);
    if (((int)uVar3 <= (int)uVar2) && (uVar3 = _DAT_20002f88, (int)uVar2 < (int)_DAT_20002f88)) {
      uVar3 = uVar2;
    }
    _DAT_20002f88 = uVar3;
  }
  else if (_DAT_20002f88 < uVar3) {
    uVar2 = (*(uint *)(&DAT_10029588 + uVar2 * 4) >> 2) + _DAT_20002f88;
    if (((int)_DAT_20002f88 <= (int)uVar2) && (_DAT_20002f88 = uVar3, (int)uVar2 < (int)uVar3)) {
      _DAT_20002f88 = uVar2;
    }
  }
  _DAT_200031b4 = (short)((uint)DAT_200041e6 * (_DAT_20002f88 >> 0xe) >> 8);
  return CONCAT44(&DAT_200041e2,param_1);
}



/* FUN_100131a4 at 100131a4 */

void FUN_100131a4(void)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    uVar1 = FUN_1001c3c8(0xff);
    *(undefined1 *)(iVar2 + 0x20004069) = uVar1;
    iVar2 = iVar2 + 1;
  } while (iVar2 != 0xc);
  return;
}



/* FUN_100131c0 at 100131c0 */

void FUN_100131c0(void)

{
  FUN_100131a4();
  DAT_200041ea = 0;
  DAT_200041e2 = 1;
  DAT_200041ed = 0xb;
  DAT_200041ee = 0;
  DAT_200041eb = 0;
  DAT_200041e9 = 0;
  return;
}



/* FUN_10013200 at 10013200 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10013200(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (uint)_DAT_200031b2 + (uint)_DAT_200031b0 + (uint)_DAT_200031b4;
  if (0xffff < uVar2) {
    uVar2 = 0xffff;
  }
  _DAT_200031aa = (undefined2)uVar2;
  iVar3 = (uint)_DAT_2000317a - ((uVar2 & 0xffff) >> 4);
  if (iVar3 < 0x1000) {
    uVar1 = (ushort)iVar3 & (short)~(ushort)((uint)iVar3 >> 0x10) >> 0xf;
  }
  else {
    uVar1 = 0xfff;
  }
  *(ushort *)((param_1 * 8 + param_2) * 2 + 0x200031e8) = uVar1;
  return;
}



/* FUN_10013268 at 10013268 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10013268(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  bVar1 = DAT_200041ce;
  uVar8 = _DAT_200013bc;
  if ((DAT_200041ce != 0) && (DAT_20003fd9 == '\0')) {
    _DAT_200013bc = _DAT_200013bc << 1;
    iVar4 = FUN_1001c3c8(0x3f);
    uVar6 = (uint)DAT_20004132;
    uVar8 = uVar8 >> 0x1f;
    DAT_20003f66 = 0;
    if ((iVar4 < (int)(uint)DAT_2000411c) &&
       ((uVar8 = _DAT_200013bc >> 0x1d & 1 ^ _DAT_200013bc >> 0x1f, DAT_20003f66 = bVar1, 3 < uVar6
        && (uVar8 = _DAT_200013bc >> 0x1c & 1 ^ uVar8, 5 < uVar6)))) {
      uVar8 = _DAT_200013bc >> 0x1a & 1 ^ uVar8;
    }
    uVar9 = uVar8 << (0x1f - uVar6 & 0xff) | _DAT_200013bc;
    uVar8 = -1 << (0x1f - uVar6 & 0xff);
    _DAT_200013bc = uVar8 & uVar9;
    if ((uVar8 & uVar9) == 0) {
      _DAT_200013bc = 0x80000000 >> uVar6;
    }
    FUN_10005708();
    _DAT_2000319c = FUN_100056dc(DAT_20003f97,DAT_20003f92,DAT_20003f93);
  }
  DAT_20003fd9 = bVar1;
  if (DAT_20003f8e == '\0') {
    bVar2 = (_DAT_20002f34 & _DAT_200013bc) != 0;
  }
  else {
    bVar2 = FUN_10005744();
  }
  DAT_2000413d = bVar1 & bVar2;
  if ((DAT_20003fe1 == '\0') && (DAT_2000413d != 0)) {
    FUN_10005ba4();
    DAT_20003fb8 = FUN_10005a08();
  }
  bVar1 = DAT_2000413d;
  if ((DAT_2000402e == '\0') || ((DAT_20003fe1 == '\0' && (DAT_2000413d != 0)))) {
    iVar7 = 0;
    iVar4 = 0;
    uVar8 = 0;
    do {
      if ((_DAT_200013bc >> (0x1fU - iVar4 & 0xff) & 1) != 0) {
        iVar7 = 1;
        uVar8 = uVar8 + *(byte *)(iVar4 + 0x20004155) & 0xffff;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 != 8);
    iVar4 = ((uVar8 & -iVar7) * (uint)DAT_2000411d >> 10) + (uint)DAT_20004030 + (int)_DAT_20003302;
    if (iVar4 < 0x61) {
      uVar3 = (ushort)iVar4 & (short)~(ushort)((uint)iVar4 >> 0x10) >> 0xf;
    }
    else {
      uVar3 = 0x60;
    }
    _DAT_200032f6 =
         FUN_10005874(uVar3,*(undefined2 *)((uint)DAT_20004125 * 2 + 0x2000080e),DAT_2000411f);
  }
  _DAT_200032f8 = *(undefined2 *)(&DAT_20003234 + (uint)_DAT_200032f6 * 2);
  uVar5 = FUN_10005990(_DAT_200032f8,DAT_20003fb8);
  _DAT_200032f8 = (undefined2)uVar5;
  _DAT_200032f8 = FUN_10005a44(uVar5,bVar1);
  DAT_20003fe0 = (undefined1)_DAT_200032f6;
  *(undefined2 *)((param_1 * 8 + param_2) * 2 + 0x200031be) = _DAT_200032f8;
  *(byte *)(param_1 * 8 + 0x20003f9f + param_2) = DAT_2000413d;
  return;
}



/* FUN_100135dc at 100135dc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100135dc(void)

{
  FUN_100037e0();
  if ((DAT_2000403f == '\x01') && (_DAT_20002d08 != 0)) {
    FUN_10003fcc();
  }
  else {
    if (DAT_2000403e == 0) {
      if (DAT_20003f85 != '\0') {
        FUN_10004144();
        return;
      }
    }
    else if (DAT_2000403e - 0x5c < 3) {
      FUN_1000478c();
      return;
    }
    if (DAT_2000402d < 8) {
                    /* WARNING: Subroutine does not return */
      FUN_10027708();
    }
  }
  return;
}



/* FUN_10013688 at 10013688 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10013688(void)

{
  int iVar1;
  
  if (DAT_200041d6 != '\0') {
    if (DAT_20004039 == '\0') {
      DAT_20000870 = DAT_20004037 ^ 1;
      FUN_10006c2c();
      if (_DAT_20002d04 != 0) {
        FUN_10009070();
      }
      FUN_100135dc();
      FUN_1000384c();
      DAT_20004039 = '\x01';
    }
    if ((_DAT_50000010 & 0x1000000) == 0) {
      do {
      } while ((_DAT_50000010 & 0x1000000) != 0);
      FUN_1001c40e(0x14);
      if (DAT_20004036 == '\0') {
        FUN_10006b34();
      }
      else {
        FUN_10006bdc();
      }
    }
    DAT_200041d6 = '\0';
  }
  iVar1 = FUN_100067c4();
  if ((iVar1 != 0) && (DAT_2000402d - 2 < 6)) {
                    /* WARNING: Subroutine does not return */
    FUN_10027708();
  }
  return;
}



/* FUN_10013758 at 10013758 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10013758(int param_1)

{
  if ((param_1 == 5) || (param_1 == 8)) {
    FUN_1001f4c8(0x20004155,0,0x40);
    FUN_1001f4c8(0x20004148,0,0xc);
    if (param_1 != 8) {
      return;
    }
  }
  else if (param_1 != 6) goto LAB_10013788;
  _DAT_20002f34 = 0;
  _DAT_20002f38 = 0;
  _DAT_20002f3c = 0;
LAB_10013788:
  if ((param_1 - 7U < 2) && (FUN_1001f4c8(0x20004195,0,0x20), param_1 == 8)) {
    FUN_1001f4c8(0x200041b5,0,0xc);
    FUN_1001f4c8(&DAT_20003fbe,0x11,8);
  }
  return;
}



/* FUN_100137d4 at 100137d4 */

bool FUN_100137d4(void)

{
  int iVar1;
  bool bVar2;
  
  DAT_20004040 = DAT_20004040 + 1;
  bVar2 = (byte)(&DAT_10028c8c)[(uint)*(byte *)(DAT_20004075 + 0x200041b5) * 2] < DAT_20004040;
  if (bVar2) {
    DAT_20004040 = 0;
    iVar1 = FUN_1001c3c8(0x40);
    DAT_20004041 = iVar1 <= (int)(uint)DAT_2000413f;
  }
  return bVar2;
}



/* FUN_10013948 at 10013948 */

void FUN_10013948(void)

{
  DAT_20004031 = 0;
  DAT_20004032 = 0;
  DAT_20004033 = 0;
  DAT_20004034 = 0;
  DAT_20004035 = 0;
  return;
}



/* FUN_10013974 at 10013974 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10013974(void)

{
  DAT_20004075 = 0;
  DAT_20004076 = 0;
  DAT_20003f9d = 0;
  DAT_20004040 = 0;
  DAT_20004154 = 1;
  DAT_20004041 = 1;
  DAT_200040f2 = 0;
  DAT_20003fb8 = 0;
  DAT_200040f1 = 0;
  DAT_20003fc6 = 0;
  FUN_10013948();
  DAT_20004129 = 0;
  DAT_2000412a = 0;
  DAT_2000412b = 0;
  DAT_20004141 = 0;
  DAT_20004142 = 0;
  DAT_20004143 = 0;
  _DAT_20003232 = 0;
  return;
}



/* FUN_100139f0 at 100139f0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100139f0(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  
  DAT_20004121 = 0;
  DAT_20003c51 = 0;
  FUN_10013758(8);
  cVar1 = DAT_2000402d;
  DAT_2000413e = 0;
  DAT_20004132 = 0x1f;
  if (((DAT_2000402d != '\x02') && (DAT_20004132 = 0xb, DAT_2000402d != '\x03')) &&
     (DAT_20004132 = 0xf, DAT_2000402d != '\x04')) {
    DAT_20004132 = 7;
  }
  (&DAT_20003faf)[DAT_20003c51] = 0x3f;
  DAT_20004140 = 0;
  DAT_20004145 = 0;
  DAT_2000411b = 0;
  DAT_2000413f = 0x3f;
  DAT_2000411d = 5;
  DAT_2000412f = 3;
  _DAT_20002d24 = 0xffffffff;
  _DAT_20002810 = 0xffffffff;
  _DAT_20002d1c = 0xffffffff;
  _DAT_20002f80 = 0xffffffff;
  DAT_20004130 = 0;
  DAT_20004131 = 0;
  DAT_20004133 = 3;
  DAT_20004134 = 2;
  DAT_20004135 = 2;
  DAT_2000412d = 4;
  DAT_2000412e = 5;
  DAT_2000412c = 0;
  DAT_2000413b = 2;
  DAT_20004139 = 1;
  DAT_20004136 = 0;
  DAT_20004137 = 0;
  DAT_20004138 = 0;
  DAT_2000413a = 4;
  DAT_2000401d = 0;
  DAT_2000402e = 1;
  if (cVar1 == '\x06') {
    iVar3 = 0;
    do {
      uVar2 = FUN_1001c3c8(0x40);
      *(undefined1 *)(iVar3 + 0x20004155) = uVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 != 8);
    DAT_2000411b = 0x20;
    DAT_20004132 = 0x1f;
    DAT_2000411d = 0x40;
    _DAT_20002f34 = 0x80000000;
    DAT_20003f97 = 0xf;
    DAT_20003f8e = 0;
    DAT_20003f93 = 0;
  }
  FUN_10013974();
  return;
}



/* FUN_10013b4c at 10013b4c */

void FUN_10013b4c(void)

{
  if (DAT_2000402d < 7) {
    if (1 < DAT_2000402d) {
      FUN_100139f0();
      return;
    }
    if (DAT_2000402d != 1) {
      return;
    }
  }
  else if (DAT_2000402d != 7) {
    return;
  }
  FUN_1000577c();
  return;
}



/* FUN_10013b74 at 10013b74 */

void FUN_10013b74(uint param_1)

{
  int iVar1;
  
  FUN_100053bc();
  FUN_10003e20();
  FUN_10003fac();
  DAT_2000402d = 0;
  FUN_1000577c();
  FUN_100139f0();
  FUN_100058d0();
  FUN_10005900();
  FUN_10005a24();
  FUN_10005b7c();
  FUN_10012d68();
  FUN_10012f28();
  FUN_100131c0();
  DAT_200040ef = 0x7f;
  DAT_20003f8a = 0x7f;
  DAT_200041e5 = 0;
  FUN_1000640c();
  if (param_1 < 0x18) {
    iVar1 = param_1 * 5;
    (&DAT_20004077)[iVar1] = 0x29;
    (&DAT_20004078)[iVar1] = 0x2e;
    (&DAT_2000407a)[iVar1] = 0x34;
    (&DAT_20004079)[iVar1] = 0x29;
    (&DAT_2000407b)[iVar1] = 8;
  }
  return;
}



/* FUN_10013bf4 at 10013bf4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10013bf4(void)

{
  if (DAT_20004147 == '\0') {
    FUN_10013b74(0xff);
  }
  else {
    FUN_10011e3c(DAT_20000878);
  }
  DAT_2000403e = 9;
  DAT_2000403f = 1;
  _DAT_20002d08 = 0x3fff;
  DAT_20003f85 = 0;
  DAT_200041c3 = 0;
  DAT_200041c2 = 0;
  return;
}



/* FUN_10013c54 at 10013c54 */

void FUN_10013c54(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0x20;
  uVar2 = 0;
  do {
    uVar2 = (uVar2 & 0x7fff) << 1;
    iVar1 = FUN_1001c8f4(10);
    if (iVar1 == 0) {
      uVar2 = uVar2 | 1;
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  if (uVar2 == 0xffff) {
    DAT_2000403e = 0x5b;
    DAT_20003f85 = 1;
    DAT_200041c3 = 0;
    DAT_200041c2 = 0;
    DAT_200041c6 = 1;
    DAT_2000402d = 0;
    FUN_10013b4c();
  }
  else {
    FUN_10013bf4();
  }
  return;
}



/* FUN_10013cbc at 10013cbc */

/* WARNING: Removing unreachable block (ram,0x10014192) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10013cbc(int param_1,undefined4 param_2,int param_3,int param_4,char param_5)

{
  undefined1 *puVar1;
  byte bVar2;
  undefined1 uVar3;
  int extraout_r2;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  int extraout_r3;
  uint extraout_r3_00;
  uint uVar8;
  byte *pbVar9;
  undefined4 unaff_pc;
  undefined4 in_cr4;
  undefined4 in_cr15;
  undefined8 uVar10;
  
  uVar10 = FUN_100047c8();
  pbVar9 = &DAT_2000403e;
  if (param_3 == 2) {
    if (param_4 == 1) {
      if (DAT_2000402d == 6) {
        DAT_2000411b = 0;
      }
      else {
        DAT_2000401e = 1;
      }
      FUN_10004ed8();
      goto LAB_10013cee;
    }
    if (param_5 == '\x01') {
      if (DAT_2000403e != '5') {
        if (DAT_2000403e != 'G') goto LAB_10013d7e;
        if (DAT_20003f85 == '\0') goto LAB_10013d7e;
        uVar10 = FUN_100131a4();
        goto LAB_10013d3e;
      }
      if (DAT_20003f85 == '\0') goto LAB_10013d7e;
      uVar10 = FUN_10005900();
      _DAT_20002d08 = 3000;
      puVar1 = &DAT_2000403f;
      uVar3 = 2;
      goto LAB_10013d2c;
    }
  }
  else if (param_3 == 3) {
    DAT_200041c3 = FUN_10004d00(DAT_2000403e);
    DAT_2000403e = 'X';
    DAT_20003f85 = '\x01';
    DAT_200041c2 = 0;
    FUN_10004ed8();
  }
  if (param_4 != 2) goto LAB_10013e06;
  if (param_5 == '\x02') {
    if (DAT_2000402d < 5) {
                    /* WARNING: Subroutine does not return */
      FUN_10027708();
    }
    FUN_10004ed8();
    goto LAB_10013d46;
  }
LAB_10013cee:
  do {
    if (param_5 != '\x04') goto LAB_10013d46;
    uVar6 = DAT_20000842 + 0xc;
    if (0x48 < uVar6) {
      uVar6 = 0x48;
    }
    DAT_20000842 = (byte)uVar6;
LAB_10013e1a:
    _DAT_20002d08 = 3000;
    DAT_2000403f = 0;
LAB_10013d46:
    do {
      puVar1 = (undefined1 *)(uint)*pbVar9;
      if (DAT_20003f85 != '\0') {
        if (puVar1 < (undefined1 *)0x5c) {
          FUN_10027718();
          bVar2 = DAT_200041c2;
          coprocessor_moveto(0xf,4,7,unaff_pc,in_cr4,in_cr15);
          coprocessor_moveto(0xf,4,7,unaff_pc,in_cr4,in_cr15);
          coprocessor_moveto(0xf,4,7,unaff_pc,in_cr4,in_cr15);
          coprocessor_moveto(0xf,4,7,unaff_pc,in_cr4,in_cr15);
          pbVar9 = (byte *)0x1;
          puVar1 = (undefined1 *)(extraout_r3_00 >> 0x1e);
          coprocessor_moveto(0xf,4,7,unaff_pc,in_cr4,in_cr15);
          if (_DAT_200031a8 != 0) {
            uVar6 = (uint)DAT_20003fc8;
            uVar4 = (uint)*(byte *)(uVar6 + 0x20004050);
            if (DAT_200041c2 == 0) {
              if (uVar4 < 0x61) {
                uVar8 = uVar4 & (int)~uVar4 >> 0x1f;
              }
              else {
                uVar8 = 0x60;
              }
              if (uVar8 != uVar4) {
                *(char *)(uVar6 + 0x20004050) = (char)uVar8;
                (&DAT_2000405d)[uVar6] = 8;
              }
            }
            else {
              puVar1 = &DAT_2000405d;
              bVar5 = (&DAT_2000405d)[uVar6];
              if (0xf < bVar5) {
                bVar5 = 0;
                *(byte *)(uVar6 + 0x20004050) = *(byte *)(uVar6 + 0x20004050) + 1;
              }
              (&DAT_2000405d)[uVar6] = bVar5;
            }
            if (param_3 == 4) {
              DAT_200041c2 = bVar2 ^ 1;
              FUN_10014870(puVar1);
              return;
            }
            FUN_10014870(puVar1);
            return;
          }
        }
LAB_10013e38:
        do {
          do {
            if (param_3 != 4) {
              FUN_10014870(puVar1);
            }
            puVar1 = (undefined1 *)FUN_1001467c();
          } while (extraout_r3 != 0x34);
          *pbVar9 = 9;
        } while( true );
      }
      puVar1 = puVar1 + param_1;
      bVar2 = 0x56;
      if ((int)puVar1 < 0x57) {
        bVar2 = (char)~(byte)((uint)puVar1 >> 0x18) >> 7 & (byte)puVar1;
      }
      *pbVar9 = bVar2;
      puVar1 = (undefined1 *)(uint)DAT_2000402d;
      if ((undefined1 *)0x7 < puVar1) goto LAB_10013e38;
      FUN_10027658();
      param_4 = (int)pbVar9 << 2;
      uVar10 = CONCAT44((int)pbVar9 << 1,extraout_r2 << 3);
      pbVar9 = (byte *)((int)pbVar9 << 1);
LAB_10013d7e:
      if (DAT_2000402d == 6) {
        uVar3 = 0x3f;
        puVar1 = &DAT_2000411b;
LAB_10013d2c:
        *puVar1 = uVar3;
      }
LAB_10013d3e:
      FUN_10004ed8((int)uVar10,(int)((ulonglong)uVar10 >> 0x20));
    } while (param_4 == 2);
LAB_10013e06:
  } while (param_4 != 4);
  iVar7 = DAT_20000842 - 0xc;
  if (iVar7 < 0x49) {
    DAT_20000842 = (byte)iVar7 & (char)~(byte)((uint)iVar7 >> 0x18) >> 7;
  }
  else {
    DAT_20000842 = 0x48;
  }
  goto LAB_10013e1a;
}



/* FUN_1001467c at 1001467c */

void FUN_1001467c(void)

{
  char cVar1;
  byte bVar2;
  char *unaff_r6;
  byte *unaff_r7;
  
  cVar1 = *unaff_r6;
  if (cVar1 == '[') {
    FUN_10014870();
    return;
  }
  bVar2 = *unaff_r7;
  *unaff_r7 = bVar2 ^ 1;
  DAT_200041c3 = 0;
  DAT_200041c2 = 0;
  if (cVar1 != '\x19') {
    FUN_10014870();
    return;
  }
  if ((bVar2 ^ 1) == 0) {
    FUN_10014870();
    return;
  }
  FUN_10013758(8);
  DAT_20004075 = 0;
  FUN_10014870();
  return;
}



/* FUN_10014870 at 10014870 */

undefined8 FUN_10014870(void)

{
  undefined8 in_stack_00000000;
  
  return in_stack_00000000;
}



/* FUN_1001535c at 1001535c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001535c(void)

{
  sbyte sVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  char *pcVar5;
  uint uVar6;
  int iVar7;
  char cVar8;
  ushort uVar9;
  uint uVar10;
  char cVar11;
  ushort *puVar12;
  char *local_30;
  int local_2c;
  char local_1c [8];
  
  local_1c[0] = '\0';
  local_1c[1] = '\0';
  uVar10 = (uint)DAT_2000087a;
  if (_DAT_20003192 == 0) {
    uVar4 = (_DAT_d0000004 & 0xfff) >> 0xb;
  }
  else {
    _DAT_20003192 = _DAT_20003192 + -1;
    uVar4 = uVar10 & 1;
  }
  if (_DAT_20003194 == 0) {
    uVar6 = (_DAT_d0000004 & 0x1fff) >> 0xc;
  }
  else {
    _DAT_20003194 = _DAT_20003194 + -1;
    uVar6 = DAT_2000087b & 1;
  }
  if ((uVar4 != (uVar10 & 1)) && (_DAT_20003192 == 0)) {
    DAT_2000087b = DAT_2000087b << 1 | (byte)uVar6;
    uVar10 = (uVar10 & 0x7f) << 1 | uVar4;
    DAT_2000087a = (byte)uVar10;
    _DAT_20003192 = 0xf;
  }
  if (((DAT_2000087b & 1) != uVar6) && (_DAT_20003194 == 0)) {
    DAT_2000087b = (byte)uVar6 | DAT_2000087b << 1;
    uVar10 = (uVar10 & 0x7f) << 1 | uVar4;
    DAT_2000087a = (byte)uVar10;
    _DAT_20003194 = 0xf;
  }
  if (_DAT_20002804 < 200) {
    _DAT_20002804 = _DAT_20002804 + 1;
  }
  if ((uVar10 & 0x1f) == 0x13) {
    if ((DAT_2000087b & 0x1f) != 0x19) goto LAB_100153e8;
    iVar7 = 1;
    if ((_DAT_20002804 < 200) && (iVar7 = 8, 99 < _DAT_20002804)) {
      iVar7 = 4;
    }
    uVar10 = 1;
    _DAT_20002804 = 0;
    DAT_2000087a = 0xff;
    DAT_2000087b = 0xff;
  }
  else if (((uVar10 & 0x1f) == 0x19) && ((DAT_2000087b & 0x1f) == 0x13)) {
    iVar7 = 1;
    if ((_DAT_20002804 < 200) && (iVar7 = 4, _DAT_20002804 < 100)) {
      iVar7 = 8;
    }
    _DAT_20002804 = 0;
    iVar7 = -iVar7;
    DAT_2000087a = 0xff;
    DAT_2000087b = 0xff;
    uVar10 = 0xffffffff;
  }
  else {
LAB_100153e8:
    iVar7 = 0;
    uVar10 = 0;
  }
  if (DAT_20003f87 == '\0') {
    uVar10 = (uint)(char)-(char)uVar10;
    iVar7 = (int)(char)-(char)iVar7;
  }
  _DAT_20003196 = _DAT_20003196 << 1;
  if ((int)(_DAT_d0000004 << 0x15) < 0) {
    if (_DAT_20003196 == 0x8000) {
      if (_DAT_20002f40 != 0) {
        cVar11 = (DAT_200041c6 ^ 1) << 2;
        goto LAB_100154a6;
      }
    }
    else if (_DAT_20003196 == 0) {
      DAT_200041c6 = 0;
    }
  }
  else {
    cVar11 = '\x01';
    _DAT_20003196 = _DAT_20003196 | 1;
    if (_DAT_20003196 == 0x7fff) {
      _DAT_20002f40 = 2000;
      goto LAB_100154a6;
    }
    if (_DAT_20003196 == 0xffff) {
      if ((_DAT_20002f40 == 0) || (_DAT_20002f40 = _DAT_20002f40 + -1, _DAT_20002f40 != 0)) {
        cVar11 = '\x02';
      }
      else {
        cVar11 = '\x03' - DAT_200041c6;
      }
      goto LAB_100154a6;
    }
  }
  cVar11 = '\0';
LAB_100154a6:
  local_2c = 0;
  local_30 = local_1c;
  puVar12 = (ushort *)&DAT_2000318c;
  pcVar5 = &DAT_20003f68;
  do {
    iVar2 = local_2c;
    uVar4 = _DAT_d0000004;
    sVar1 = (&DAT_10029584)[local_2c];
    uVar9 = *puVar12 << 1;
    *puVar12 = uVar9;
    if ((uVar4 & 1 << sVar1) == 0) {
      uVar9 = uVar9 | 1;
      *puVar12 = uVar9;
      if (uVar9 == 0x7fff) {
        cVar8 = '\x01';
      }
      else {
        if ((uVar9 != 0xffff) || (*pcVar5 != '\0')) goto LAB_10015522;
        cVar8 = '\x02';
      }
LAB_1001551e:
      *local_30 = cVar8;
    }
    else if (uVar9 == 0x8000) {
      if (*pcVar5 == '\0') {
        cVar8 = '\x04';
        goto LAB_1001551e;
      }
    }
    else if ((uVar9 == 0) && (*pcVar5 != '\0')) {
      *pcVar5 = '\0';
    }
LAB_10015522:
    local_30 = local_30 + 1;
    puVar12 = puVar12 + 1;
    pcVar5 = pcVar5 + 1;
    local_2c = 1;
    if (iVar2 == 1) {
      if (_DAT_200027f4 != 0) {
        _DAT_200027f4 = _DAT_200027f4 + -1;
      }
      cVar8 = local_1c[0];
      cVar3 = local_1c[1];
      FUN_10013cbc(uVar10,iVar7,cVar11,local_1c[0],local_1c[1]);
      if (((cVar8 == '\0' && cVar3 == '\0') && (uVar10 & 0xff) == 0) && cVar11 == '\0') {
        if ((_DAT_20002d04 != 0) && (DAT_2000403a < 4)) {
          _DAT_20002d04 = _DAT_20002d04 + -1;
        }
      }
      else {
        _DAT_20002d04 = *(int *)(&DAT_10029570 + (uint)DAT_2000403a * 4);
      }
      FUN_1001c8b0(0x16,DAT_20000842 < 0x24);
      FUN_1001c8b0(0x15,0x24 < DAT_20000842);
      return;
    }
  } while( true );
}



/* FUN_10015620 at 10015620 */

void FUN_10015620(void)

{
  uint uVar1;
  undefined1 *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  FUN_10013b74(0);
  puVar2 = &DAT_20004077;
  do {
    puVar2[3] = 0x34;
    *puVar2 = 0x29;
    puVar2[1] = 0x2e;
    puVar2[2] = 0x29;
    puVar2[4] = 8;
    uVar1 = uVar3 & 0xff;
    uVar3 = uVar3 + 1;
    FUN_1001111c(uVar1);
    puVar2 = puVar2 + 5;
  } while (uVar3 != 0x18);
  FUN_10012bb8(0);
  FUN_10012c38();
  return;
}



/* FUN_1001565c at 1001565c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001565c(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  byte local_4c [56];
  
  FUN_1001c258(&DAT_200013a8,0x1000);
  iVar6 = 0;
  do {
    bVar2 = FUN_1001c298(&DAT_200013a8,iVar6);
    pbVar4 = local_4c;
    pbVar4[iVar6] = bVar2;
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0x32);
  uVar3 = (uint)local_4c[0];
  DAT_20003f87 = (undefined1)((uVar3 & 0xf) >> 3);
  _DAT_2000315e = (ushort)((uVar3 & 0xf0) << 4) | (ushort)local_4c[1];
  iVar6 = 0;
  do {
    bVar2 = pbVar4[4];
    bVar1 = pbVar4[3];
    *(ushort *)(&DAT_200031de + iVar6) = (ushort)pbVar4[2] | (ushort)((bVar2 & 0xf) << 8);
    *(ushort *)(&DAT_2000317a + iVar6) = (ushort)bVar1 | (ushort)((bVar2 & 0xf0) << 4);
    iVar6 = iVar6 + 2;
    pbVar4 = pbVar4 + 3;
  } while (iVar6 != 10);
  uVar5 = (uint)local_4c[0x15];
  _DAT_200032fe = (ushort)((uVar5 & 3) << 8) | (ushort)local_4c[0x11];
  _DAT_2000322e = (ushort)local_4c[0x12] | (ushort)((uVar5 & 0xc) << 6);
  _DAT_2000320a = (ushort)local_4c[0x13] | (ushort)((uVar5 & 0x30) << 4);
  _DAT_20003208 = (ushort)local_4c[0x14] | (ushort)((uVar5 & 0xc0) << 2);
  DAT_20000879 = local_4c[0x16] & 7;
  DAT_200041f1 = (undefined1)((local_4c[0x16] & 0x1f) >> 3);
  DAT_2000403a = local_4c[0x16] >> 5;
  _DAT_20002d04 = *(undefined4 *)(&DAT_10029570 + (uint)DAT_2000403a * 4);
  DAT_20004024 = local_4c[0x17] & 1;
  DAT_20004147 = local_4c[0x17] >> 1 & 1;
  DAT_20000878 = local_4c[0x31];
  FUN_1001c388(&DAT_200013a8);
  if ((uVar3 & 7) != 1) {
    FUN_10004ef0();
    FUN_10004fa0();
    FUN_10015620();
  }
  FUN_10005124();
  FUN_10003574();
  return;
}



/* FUN_100157b0 at 100157b0 */

void FUN_100157b0(void)

{
  FUN_1001c402(5);
  FUN_10012c38();
  FUN_10004dc0();
  FUN_1001565c();
  FUN_10013c54();
  FUN_10006c44();
  FUN_10003468();
  FUN_10003a04();
  FUN_10003774(DAT_20000879);
  FUN_10006928();
  FUN_10006a94();
  FUN_10003a4c();
  FUN_1001c402(5);
  FUN_10004e90();
  DAT_200041d6 = 1;
  DAT_200040ff = 1;
  return;
}



/* FUN_1001580c at 1001580c */

undefined4 FUN_1001580c(int param_1)

{
  if ((byte)(&DAT_10028e82)[(uint)*(byte *)(param_1 + 0x20004195) * 2] < 8) {
                    /* WARNING: Subroutine does not return */
    FUN_10027708((&DAT_10028e82)[(uint)*(byte *)(param_1 + 0x20004195) * 2]);
  }
  return 0;
}



/* FUN_100164dc at 100164dc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_100164dc(void)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  uint local_20;
  
  uVar4 = 1 - DAT_2000403c & 0xff;
  puVar7 = (undefined2 *)(uVar4 * 0x10 + 0x200031be);
  puVar6 = (undefined2 *)(uVar4 * 0x10 + 0x200031e8);
  iVar3 = uVar4 * 8 + 0x20003f9f;
  local_20 = 0;
  do {
    uVar5 = local_20 & 0xff;
    FUN_10006588(uVar4,uVar5);
    FUN_10003af4(uVar4,uVar5);
    FUN_10003e58(DAT_20003f7d);
    FUN_100051a8();
    FUN_10012c64();
    if (DAT_2000402d < 8) {
                    /* WARNING: Subroutine does not return */
      FUN_10027708();
    }
    FUN_10012d7c(uVar4,uVar5);
    FUN_10012fd0(uVar4,uVar5);
    FUN_10013200(uVar4,uVar5);
    DAT_20003f84 = 0;
    cVar1 = *(char *)(iVar3 + local_20);
    if ((cVar1 != '\0') && (DAT_20003fe1 == '\0')) {
      DAT_20004030 = DAT_20000842;
    }
    DAT_20003fe1 = cVar1;
    if (DAT_2000403e == '[') {
      uVar5 = (uint)DAT_200041c3;
      if (uVar5 < 5) {
        uVar2 = *(undefined2 *)(&DAT_200031de + uVar5 * 2);
LAB_100165a0:
        *puVar7 = uVar2;
        uVar2 = _DAT_2000317a;
      }
      else {
        if (9 < uVar5) {
          if (uVar5 != 10) goto LAB_10016600;
          uVar2 = _DAT_200031de;
          goto LAB_100165a0;
        }
        *puVar7 = _DAT_200031de;
        uVar2 = *(undefined2 *)(&DAT_2000317a + (uVar5 - 5) * 2);
      }
      *puVar6 = uVar2;
    }
LAB_10016600:
    puVar7 = puVar7 + 1;
    local_20 = local_20 + 1;
    puVar6 = puVar6 + 1;
    if (local_20 == 8) {
      if (DAT_20003308 == '\0') {
        DAT_20004102 = DAT_20003308;
      }
      return CONCAT44(iVar3,8);
    }
  } while( true );
}



/* FUN_1001666c at 1001666c */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1001666c(undefined4 *param_1)

{
  uint uVar1;
  code *pcVar2;
  
  if ((code *)*param_1 != (code *)0x0) {
    (*(code *)*param_1)(param_1 + 0x1d);
  }
  uVar1 = (uint)*(byte *)((int)param_1 + 0x75);
  if (uVar1 < 0xe0) {
    if (uVar1 == 0xb0) {
      pcVar2 = (code *)param_1[5];
    }
    else {
      if (0xb0 < uVar1) {
        if (uVar1 == 0xc0) {
          pcVar2 = (code *)param_1[6];
        }
        else {
          if (uVar1 != 0xd0) {
            return;
          }
          pcVar2 = (code *)param_1[7];
        }
        if (pcVar2 == (code *)0x0) {
          return;
        }
        (*pcVar2)(*(undefined1 *)(param_1 + 0x1d),*(undefined1 *)((int)param_1 + 0x76));
        return;
      }
      if (uVar1 == 0x90) {
        pcVar2 = (code *)param_1[3];
      }
      else if (uVar1 == 0xa0) {
        pcVar2 = (code *)param_1[4];
      }
      else {
        if (uVar1 != 0x80) {
          return;
        }
        pcVar2 = (code *)param_1[2];
      }
    }
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(*(undefined1 *)(param_1 + 0x1d),*(undefined1 *)((int)param_1 + 0x76),
                *(undefined1 *)((int)param_1 + 0x77));
    }
  }
  else if (uVar1 - 0xe0 < 0x20) {
    FUN_100276e8();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  return;
}



/* FUN_100167dc at 100167dc */

bool FUN_100167dc(uint param_1)

{
  return (param_1 & 0xffffffcf) == 0x80 || ((param_1 & 0xffffffef) == 0xc0 || param_1 == 0xe0);
}



/* FUN_10016800 at 10016800 */

uint FUN_10016800(uint param_1)

{
  if ((((char)param_1 < '\0') && (1 < (param_1 + 0xc & 0xff))) && (param_1 != 0xfd)) {
    if (param_1 < 0xf0) {
      param_1 = param_1 & 0xfffffff0;
    }
  }
  else {
    param_1 = 0;
  }
  return param_1;
}



/* FUN_10016822 at 10016822 */

undefined8 FUN_10016822(int param_1,uint param_2,uint param_3,uint param_4,char param_5)

{
  if (param_2 < 0xe1) {
    if (((byte)(param_5 - 1) < 0x10) && ((char)param_2 < '\0')) {
      FUN_1000330c(**(undefined4 **)(param_1 + 0x54),(byte)(param_5 - 1) | param_2);
      FUN_1000330c(**(undefined4 **)(param_1 + 0x54),param_3 & 0x7f);
      if ((param_2 & 0xffffffef) != 0xc0) {
        FUN_1000330c(**(undefined4 **)(param_1 + 0x54),param_4 & 0x7f);
      }
    }
  }
  else if (0xf7 < param_2) {
    FUN_10003316(*(undefined4 *)(param_1 + 0x54),param_2);
  }
  return CONCAT44(param_4,param_1);
}



/* FUN_10016880 at 10016880 */

undefined8 FUN_10016880(uint param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint local_18;
  
  bVar1 = *(byte *)(param_1 + 0x70);
  local_18 = param_1;
  if ((-1 < (int)((uint)bVar1 << 0x1f)) || (local_18 = param_1, bVar1 < 2)) goto LAB_100168de;
  bVar2 = *(byte *)(param_1 + 0x75);
  local_18 = param_1;
  if ((byte)(bVar2 + 0x80) < 0x61) {
    uVar4 = (uint)*(byte *)(param_1 + 0x74);
    bVar1 = bVar1 >> 1;
    if (bVar1 == 2) {
      if (uVar4 != param_2 && param_2 != 0) goto LAB_100168de;
    }
    else if (bVar1 == 3) {
      if (uVar4 == param_2 || param_2 == 0) goto LAB_100168de;
    }
    else {
      local_18 = param_1;
      if (bVar1 != 1) goto LAB_100168de;
    }
    FUN_10016822(param_1,bVar2,*(undefined1 *)(param_1 + 0x76),*(undefined1 *)(param_1 + 0x77));
    local_18 = uVar4;
    goto LAB_100168de;
  }
  if (bVar2 < 0xf2) {
    if (bVar2 == 0xf0) {
      puVar6 = (undefined1 *)(param_1 + 0x78);
      uVar4 = (uint)*(ushort *)(param_1 + 0x76);
      if (0x80 < uVar4) {
        uVar4 = 0x80;
      }
      puVar5 = puVar6 + uVar4;
      for (; puVar6 != puVar5; puVar6 = puVar6 + 1) {
        FUN_1000330c(**(undefined4 **)(param_1 + 0x54),*puVar6);
      }
      goto LAB_100168de;
    }
    if (bVar2 != 0xf1) goto LAB_100168de;
    uVar4 = (*(byte *)(param_1 + 0x76) & 7) << 4 | *(byte *)(param_1 + 0x77) & 0xf;
    FUN_1000330c(**(undefined4 **)(param_1 + 0x54));
    puVar3 = *(undefined4 **)(param_1 + 0x54);
  }
  else {
    uVar4 = 1 << (uint)(byte)(bVar2 + 0xe);
    if ((uVar4 & 0x3750) != 0) {
      FUN_10003316(*(undefined4 *)(param_1 + 0x54));
      goto LAB_100168de;
    }
    if ((uVar4 & 1) == 0) {
      if (bVar2 != 0xf3) goto LAB_100168de;
      uVar4 = (uint)*(byte *)(param_1 + 0x76);
      FUN_1000330c(**(undefined4 **)(param_1 + 0x54));
    }
    else {
      bVar1 = *(byte *)(param_1 + 0x77);
      bVar2 = *(byte *)(param_1 + 0x76);
      FUN_1000330c(**(undefined4 **)(param_1 + 0x54),0xf2);
      FUN_1000330c(**(undefined4 **)(param_1 + 0x54),bVar2 & 0x7f);
      uVar4 = ((uint)bVar1 << 7 | (uint)bVar2) >> 7;
    }
    uVar4 = uVar4 & 0x7f;
    puVar3 = *(undefined4 **)(param_1 + 0x54);
  }
  FUN_1000330c(*puVar3,uVar4);
LAB_100168de:
  return CONCAT44(param_2,local_18);
}



/* FUN_100169b4 at 100169b4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_100169b4(byte *param_1,int param_2)

{
  bool bVar1;
  undefined1 *puVar2;
  byte bVar3;
  undefined1 uVar4;
  byte bVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int extraout_r2;
  char cVar9;
  uint uVar10;
  byte *extraout_r3;
  byte *pbVar11;
  undefined1 *puVar12;
  uint uVar13;
  uint uVar14;
  byte *local_20;
  int local_1c;
  
  puVar12 = &DAT_200013c0;
  uVar14 = (uint)DAT_20001418;
  local_20 = param_1;
  local_1c = param_2;
  if ((0x10 < uVar14) || (iVar6 = (**(code **)(*(int *)*_DAT_20001414 + 0x10))(), iVar6 == 0))
  goto LAB_10016b36;
  DAT_200014cd = DAT_200014cd & 0xfe;
  bVar5 = (**(code **)(*(int *)*_DAT_20001414 + 0x14))();
  uVar10 = _DAT_20001424;
  bVar3 = DAT_20001419;
  uVar13 = (uint)bVar5;
  if (uVar13 == 0xfd) goto LAB_10016b36;
  if (_DAT_20001424 == 0) {
    uVar10 = (uint)DAT_20001419;
    DAT_2000141b = bVar5;
    FUN_10016800(uVar10);
    iVar6 = FUN_100167dc();
    if (iVar6 != 0) {
      if (-1 < (int)((uint)bVar5 << 0x18)) {
        DAT_2000141b = bVar3;
        _DAT_20001424 = 1;
        uVar13 = uVar10;
        DAT_2000141c = bVar5;
      }
    }
    local_20 = (byte *)FUN_10016800(uVar13);
    if ((byte *)0xdf < local_20) {
      if (local_20 + -0xe0 < (byte *)0x20) {
        iVar6 = FUN_100276f8();
        uVar10 = extraout_r2 >> 9;
        puVar12 = (undefined1 *)(uint)*extraout_r3;
        *(short *)(uVar14 + iVar6) = (short)uVar13;
        uVar13 = *(byte *)(uVar14 + iVar6) - 0x3d;
        pbVar11 = extraout_r3;
LAB_10016a7e:
        if (uVar10 == 0xc0) {
          uVar8 = 2;
          goto LAB_10016a84;
        }
      }
LAB_10016b16:
      puVar12[0x10d] = puVar12[0x10d] | 1;
      if (*(code **)(puVar12 + 4) != (code *)0x0) {
        (**(code **)(puVar12 + 4))();
      }
      *(undefined4 *)(puVar12 + 100) = 0;
      *(undefined4 *)(puVar12 + 0x60) = 0;
      puVar12[0x59] = 0;
      goto LAB_10016b36;
    }
    pbVar11 = local_20;
    if (local_20 != (byte *)0xb0) {
      uVar10 = (uint)local_20 & 0xef;
      if ((byte *)0xb0 < local_20) goto LAB_10016a7e;
      if ((uVar10 != 0x80) && (local_20 != (byte *)0xa0)) goto LAB_10016b16;
    }
    uVar8 = 3;
LAB_10016a84:
    *(undefined4 *)(puVar12 + 0x60) = uVar8;
    if (*(uint *)(puVar12 + 100) < *(int *)(puVar12 + 0x60) - 1U) {
      *(uint *)(puVar12 + 100) = *(uint *)(puVar12 + 100) + 1;
      goto LAB_10016b36;
    }
    puVar12[0x75] = (char)pbVar11;
    puVar12[0x74] = ((byte)uVar13 & 0xf) + 1;
    puVar12[0x76] = puVar12[0x5c];
    puVar12[0x77] = 0;
    *(undefined4 *)(puVar12 + 100) = 0;
    *(undefined4 *)(puVar12 + 0x60) = 0;
    *(undefined4 *)(puVar12 + 0xfc) = 1;
    puVar12[0xf8] = 1;
    if (pbVar11 != (byte *)0x90) goto LAB_10016d00;
LAB_10016ace:
    puVar12[0x75] = 0x80;
    goto LAB_10016cb2;
  }
  if (((int)((uint)bVar5 << 0x18) < 0) && (uVar13 - 0xf0 < 0x10)) {
                    /* WARNING: Subroutine does not return */
    FUN_10027708();
  }
  if ((DAT_2000141b == 0xf0) || (DAT_2000141b == 0xf7)) {
    puVar2 = &DAT_20001438;
  }
  else {
    puVar2 = &DAT_2000141b;
  }
  puVar2[_DAT_20001424] = bVar5;
  uVar4 = DAT_200014b7;
  iVar6 = _DAT_20001420;
  bVar3 = DAT_2000141b;
  local_1c = _DAT_20001420;
  if (uVar10 < _DAT_20001420 - 1U) {
    _DAT_20001424 = uVar10 + 1;
    goto LAB_10016b36;
  }
  if ((DAT_2000141b == 0xf0) || (DAT_2000141b == 0xf7)) {
    DAT_200014b7 = 0xf0;
    _DAT_20001434 = 0x80f000;
    _DAT_200014bc = 0x80;
    DAT_200014b8 = 1;
    FUN_1001666c(&DAT_200013c0);
    DAT_20001438 = 0xf7;
    DAT_20001439 = uVar4;
    _DAT_20001424 = 2;
    goto LAB_10016b36;
  }
  local_20 = (byte *)FUN_10016800(DAT_2000141b);
  _DAT_20001434 = CONCAT11((char)local_20,DAT_20001434);
  iVar7 = FUN_100167dc();
  cVar9 = '\0';
  if (iVar7 != 0) {
    cVar9 = (bVar3 & 0xf) + 1;
  }
  _DAT_20001434 = CONCAT31(_DAT_20001435,cVar9);
  cVar9 = '\0';
  if (iVar6 == 3) {
    cVar9 = DAT_2000141d;
  }
  _DAT_20001434 = CONCAT13(cVar9,CONCAT12(DAT_2000141c,_DAT_20001434));
  _DAT_20001424 = 0;
  _DAT_20001420 = 0;
  DAT_200014b8 = 1;
  if (local_20 == (byte *)0xb0) {
LAB_10016cac:
    DAT_20001419 = bVar3;
LAB_10016cb2:
    if (((byte)puVar12[0x74] == uVar14) || (bVar1 = false, uVar14 == 0)) goto LAB_10016af8;
  }
  else {
    if (local_20 < (byte *)0xb1) {
      if (((uint)local_20 & 0xef) == 0x80) {
        DAT_20001419 = bVar3;
        if ((local_20 != (byte *)0x90) || (cVar9 != '\0')) goto LAB_10016cb2;
        goto LAB_10016ace;
      }
      if (local_20 == (byte *)0xa0) goto LAB_10016cac;
    }
    else if ((((uint)local_20 & 0xef) == 0xc0) || (local_20 == (byte *)0xe0)) goto LAB_10016cac;
    DAT_20001419 = 0;
LAB_10016d00:
    if (((uint)(local_20 + -0x80) & 0xff) < 0x61) goto LAB_10016cb2;
LAB_10016af8:
    FUN_1001666c(puVar12);
    bVar1 = true;
  }
  FUN_10016880(puVar12,uVar14);
  if (!bVar1) goto LAB_10016b36;
  cVar9 = puVar12[0x75];
  if (cVar9 == -8) {
    puVar12 = &DAT_20004020;
LAB_10016cde:
    *puVar12 = 1;
  }
  else {
    if (cVar9 == -6) {
      puVar12 = &DAT_20004022;
      goto LAB_10016cde;
    }
    if (cVar9 == -4) {
      puVar12 = &DAT_20004023;
      goto LAB_10016cde;
    }
    if ((DAT_20004020 == '\0' && DAT_20004022 == '\0') && (DAT_20004023 == '\0')) goto LAB_10016b36;
  }
  DAT_20003f7f = 1;
LAB_10016b36:
  return CONCAT44(local_1c,local_20);
}



/* FUN_10016d5c at 10016d5c */

void FUN_10016d5c(void)

{
  char cVar1;
  
  cVar1 = DAT_20003b2b;
  if (DAT_20004102 != '\0') {
    if ((DAT_20001310 != '\0') && (DAT_20003b2b == '\0')) {
      FUN_10027738(0x20001314);
      DAT_20003b2c = cVar1;
      FUN_1001f514(0xc0ded02e);
      do {
      } while (DAT_20003b2c == '\0');
    }
    FUN_100164dc();
    FUN_1001535c();
    DAT_2000080c = DAT_2000080c + -1;
    if (DAT_2000080c == '\0') {
      DAT_2000080c = '\b';
      DAT_200041d6 = 1;
    }
    if (DAT_20001310 != '\0') {
      FUN_10027618(0x20001314);
      DAT_20003b2c = '\0';
    }
    if (DAT_20004124 != '\0') {
      FUN_1001111c(DAT_20004126);
    }
    if (DAT_20004123 != '\0') {
      FUN_10012bb8(DAT_20000878);
    }
    if (DAT_20004122 != '\0') {
      FUN_10004fa0();
    }
    if (DAT_20004024 != '\0') {
      FUN_100169b4();
    }
  }
  return;
}



/* FUN_10016e44 at 10016e44 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10016e44(void)

{
  FUN_1001787c(0x20002f54,1);
  _DAT_20002e28 = 0x20002f54;
  _DAT_20001414 = &DAT_20002e28;
  _DAT_20001418 = 0;
  DAT_2000141a = 0;
  _DAT_20001428 = 0xffff;
  _DAT_2000142c = 0xffff;
  DAT_20001430 = 3;
  _DAT_200013c0 = 0;
  _DAT_200013c4 = 0;
  _DAT_200013c8 = 0;
  _DAT_200013cc = 0;
  _DAT_200013d0 = 0;
  _DAT_200013d4 = 0;
  _DAT_200013d8 = 0;
  _DAT_200013dc = 0;
  _DAT_200013e0 = 0;
  _DAT_200013e4 = 0;
  _DAT_200013e8 = 0;
  _DAT_200013ec = 0;
  _DAT_200013f0 = 0;
  _DAT_200013f4 = 0;
  _DAT_200013f8 = 0;
  _DAT_200013fc = 0;
  _DAT_20001400 = 0;
  _DAT_20001404 = 0;
  _DAT_20001408 = 0;
  _DAT_2000140c = 0;
  _DAT_20001410 = 0;
  _DAT_20001420 = 0;
  _DAT_20001424 = 0;
  _DAT_20001434 = 0;
  _DAT_200014b8 = 0;
  FUN_1001f4c8(&DAT_20001438,0,0x80);
  _DAT_200014c0 = 0;
  _DAT_200014c4 = 0;
  _DAT_200014c8 = 0;
  _DAT_200014cc = 0;
  return;
}



/* FUN_10016ed8 at 10016ed8 */

void FUN_10016ed8(undefined4 param_1)

{
  FUN_100173ec(0x200014ec,param_1);
  return;
}



/* FUN_10016eec at 10016eec */

void FUN_10016eec(void)

{
  char cVar1;
  char cVar2;
  
  cVar1 = DAT_20003b29;
  for (cVar2 = '\0'; cVar2 != cVar1; cVar2 = cVar2 + '\x01') {
    FUN_10017d0c(cVar2);
  }
  return;
}



/* FUN_10016fd8 at 10016fd8 */

undefined4 FUN_10016fd8(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  char cVar1;
  char cVar2;
  uint uVar3;
  char cVar4;
  undefined2 local_5c;
  char local_5a;
  undefined1 local_59;
  undefined2 local_58;
  undefined2 local_54;
  char local_52;
  undefined2 local_50;
  undefined1 local_4e;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_4a;
  undefined4 local_48;
  undefined1 local_44;
  char local_42;
  undefined1 local_41;
  undefined4 local_40;
  undefined2 local_3c;
  char local_3a;
  char local_39;
  undefined2 local_38;
  byte local_36;
  undefined1 local_35;
  undefined1 local_34;
  undefined2 local_32;
  undefined1 local_30;
  char local_2f;
  undefined1 local_2d;
  undefined1 local_2c;
  undefined2 local_28;
  char local_26;
  undefined1 local_25;
  undefined1 local_24;
  undefined1 local_21;
  undefined1 local_20;
  byte local_1f;
  undefined2 local_1e;
  
  if (param_3 == 0) {
    cVar4 = '\0';
    local_26 = '\0';
    local_36 = 0;
    local_1f = 0;
    uVar3 = param_4;
    cVar1 = DAT_20001608;
    cVar2 = DAT_2000160a;
  }
  else {
    local_36 = DAT_20001609 | 0x80;
    local_1f = DAT_20001609 + 1 | 0x80;
    uVar3 = 0x200015eb;
    cVar1 = DAT_20001608 + '\x02';
    DAT_20001609 = DAT_20001609 + 2;
    cVar2 = DAT_2000160a + '\x01';
    cVar4 = DAT_20001608;
    local_26 = DAT_2000160a;
  }
  DAT_2000160a = cVar2;
  DAT_20001608 = cVar1;
  FUN_1001f4c8(&local_5c,0,0x42,uVar3,local_26,local_36,local_1f);
  if (param_3 != 0) {
    if (param_4 < 0x42) {
      return 0;
    }
    local_4c = *(undefined1 *)(param_1 + 0x14);
    local_58 = 0x202;
    local_54 = 0x409;
    local_50 = 0x201;
    local_4a = 0x24;
    local_48 = 0x24050120;
    local_44 = 1;
    local_40 = 0x5060224;
    local_42 = cVar4 + '\x01';
    local_3c = 0x624;
    local_4b = 5;
    local_35 = 3;
    local_34 = 8;
    local_32 = 0x910;
    local_30 = 4;
    local_5c = 0xb08;
    local_2d = 2;
    local_2c = 10;
    local_59 = 2;
    local_4e = 2;
    local_38 = 0x507;
    local_28 = 0x507;
    local_41 = 4;
    local_25 = 2;
    local_24 = 0x40;
    local_21 = 7;
    local_20 = 5;
    local_1e = 0x4002;
    local_5a = cVar4;
    local_52 = cVar4;
    local_3a = cVar4;
    local_39 = local_42;
    local_2f = local_42;
    FUN_1001f4d4(param_3,&local_5c,0x42);
  }
  return 0x42;
}



/* FUN_10017154 at 10017154 */

void FUN_10017154(undefined4 *param_1)

{
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  *param_1 = &PTR_LAB_10016f0c_1_1002aa50;
  param_1[4] = &DAT_1002aa78;
  param_1[2] = 1000;
  *(undefined1 *)((int)param_1 + 0x15) = 0xff;
  return;
}



/* FUN_10017178 at 10017178 */

void FUN_10017178(int param_1)

{
  if (*(char *)(param_1 + 0x15) == -1) {
    if (DAT_20003b29 < 2) {
      *(byte *)(param_1 + 0x15) = DAT_20003b29;
      DAT_20003b29 = DAT_20003b29 + 1;
      FUN_10017508(param_1 + 0x10,"TinyUSB Serial");
      FUN_100173ac(0x200014ec,param_1 + 0x10);
    }
  }
  return;
}



/* FUN_100172e8 at 100172e8 */

void FUN_100172e8(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x124) = param_2;
  return;
}



/* FUN_100172ee at 100172ee */

void FUN_100172ee(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x128) = param_2;
  return;
}



/* FUN_100172f4 at 100172f4 */

uint FUN_100172f4(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*(byte *)(param_1 + 0x150);
  if (uVar1 < 0xc) {
    if (param_2 == 0) {
      uVar1 = 0;
    }
    else {
      *(byte *)(param_1 + 0x150) = *(byte *)(param_1 + 0x150) + 1;
      *(int *)((uVar1 + 0x48) * 4 + param_1) = param_2;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* FUN_1001731c at 1001731c */

void FUN_1001731c(undefined4 *param_1)

{
  undefined1 auStack_30 [12];
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  undefined2 local_14;
  
  FUN_1001f4d4(&local_24,&DAT_1002aa7c,0x12);
  *param_1 = local_24;
  param_1[1] = uStack_20;
  param_1[2] = uStack_1c;
  param_1[3] = local_18;
  *(undefined2 *)(param_1 + 4) = local_14;
  FUN_1001f4d4(auStack_30,&DAT_1002aa8e,9);
  FUN_1001f4d4(param_1 + 6,auStack_30,9);
  param_1[5] = param_1 + 6;
  param_1[0x46] = 0x1000009;
  *(undefined2 *)(param_1 + 0x47) = 0x100;
  *(undefined1 *)((int)param_1 + 0x11e) = 1;
  FUN_1001f4c8(param_1 + 0x4b,0,0x24);
  param_1[0x48] = 0x409;
  param_1[0x49] = "Generic";
  param_1[0x4a] = "RP2040";
  *(undefined1 *)(param_1 + 0x54) = 4;
  return;
}



/* FUN_100173ac at 100173ac */

bool FUN_100173ac(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = (**(code **)*param_2)
                    (param_2,*(undefined1 *)(param_1 + 0x11c),
                     *(int *)(param_1 + 0x14) + (uint)*(ushort *)(param_1 + 0x118),
                     (uint)*(ushort *)(param_1 + 0x11a) - (uint)*(ushort *)(param_1 + 0x118) &
                     0xffff,param_4);
  if (iVar1 != 0) {
    uVar3 = iVar1 + (uint)*(ushort *)(param_1 + 0x118);
    iVar2 = *(int *)(param_1 + 0x14);
    uVar4 = uVar3 & 0xffff;
    *(short *)(param_1 + 0x118) = (short)uVar3;
    *(char *)(iVar2 + 2) = (char)uVar4;
    *(char *)(iVar2 + 3) = (char)(uVar4 >> 8);
    *(undefined1 *)(iVar2 + 4) = *(undefined1 *)(param_1 + 0x11c);
  }
  return iVar1 != 0;
}



/* FUN_100173ec at 100173ec */

undefined4 FUN_100173ec(int param_1,undefined4 param_2)

{
  FUN_1001731c();
  *(undefined1 *)(param_1 + 6) = 1;
  *(undefined2 *)(param_1 + 4) = 0x2ef;
  FUN_10017178(0x200014d4,0x1c200);
  FUN_10017adc(param_2);
  return 1;
}



/* FUN_10017508 at 10017508 */

void FUN_10017508(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_100172f4(0x200014ec);
  *(undefined1 *)(param_1 + 4) = uVar1;
  return;
}



/* FUN_1001751c at 1001751c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1001751c(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 local_18;
  undefined2 local_14;
  
  local_14 = (undefined2)param_2;
  local_18 = param_1;
  if (_DAT_20001750 != (undefined4 *)0x0) {
    iVar2 = *(int *)*_DAT_20001750;
    if (param_2 == 0) {
      (**(code **)(iVar2 + 0x24))();
      uVar1 = *(undefined1 *)(_DAT_20001750 + 1);
    }
    else {
      local_14 = 0x100;
      local_18 = 26000000;
      (**(code **)(iVar2 + 0x20))((int *)*_DAT_20001750,26000000,0x100);
      uVar1 = *(undefined1 *)(_DAT_20001750 + 1);
    }
    FUN_1001c8b0(uVar1,param_2 == 0);
  }
  return (ulonglong)CONCAT24(local_14,local_18);
}



/* FUN_10017560 at 10017560 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_10017560(void)

{
  bool bVar1;
  
  bVar1 = _DAT_20001750 != (undefined4 *)0x0;
  if (bVar1) {
    (**(code **)(*(int *)*_DAT_20001750 + 0x14))();
  }
  return bVar1;
}



/* FUN_1001757c at 1001757c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001757c(void)

{
  if (_DAT_20001750 != 0) {
    FUN_1001cf68(0xd);
  }
  return;
}



/* FUN_100175d0 at 100175d0 */

void FUN_100175d0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined2 param_5)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = *(int *)(param_1 * 4 + 0x20001694);
  if ((iVar1 != 0) && (pcVar2 = *(code **)(iVar1 + 0x14), pcVar2 != (code *)0x0)) {
    (*pcVar2)(param_2,param_3,param_4,param_5);
  }
  return;
}



/* FUN_10017610 at 10017610 */

uint FUN_10017610(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined1 uVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  byte bVar7;
  undefined1 *puVar8;
  uint uVar9;
  char cVar10;
  char cVar11;
  uint uVar12;
  uint local_54;
  undefined2 local_3c;
  byte local_3a;
  undefined1 local_39;
  undefined4 local_38;
  undefined1 local_34;
  char local_33;
  undefined2 local_32;
  byte local_30;
  undefined1 local_2f;
  undefined1 local_2e;
  undefined1 local_2c;
  char local_2b;
  undefined2 local_2a;
  char local_28;
  undefined2 local_26;
  undefined1 local_24;
  undefined1 local_21;
  undefined2 local_20;
  undefined1 local_1d;
  char local_1c;
  undefined1 local_1b;
  
  cVar4 = DAT_2000160a;
  local_54 = (uint)*(byte *)(param_1 + 0x15) * 0x20 + 0x3c;
  if (param_3 != 0) {
    if (local_54 <= param_4) {
      cVar10 = DAT_20001608 + '\x01';
      bVar2 = DAT_20001609 | 0x80;
      DAT_2000160a = DAT_2000160a + '\x01';
      uVar1 = *(undefined1 *)(param_1 + 0x14);
      bVar7 = *(byte *)(param_1 + 0x15);
      local_3a = DAT_20001608;
      local_3c = 0x409;
      DAT_20001608 = DAT_20001608 + '\x02';
      DAT_20001609 = DAT_20001609 + 1;
      FUN_1001f4c8(&local_39,0,0x1c);
      local_38 = 0x10100;
      local_32 = 0x124;
      local_20 = 0x124;
      local_2f = 1;
      local_2c = 1;
      local_1d = 1;
      iVar6 = bVar7 + 0xd;
      local_33 = 9;
      local_2e = 9;
      local_26 = 0x102;
      local_21 = 7;
      local_1c = (bVar7 * '\x0f' + (char)iVar6) * '\x02' + '\a';
      local_2a = 0x409;
      local_24 = 3;
      local_1b = (undefined1)((uint)bVar7 * 0x1e + 7 + iVar6 * 2 >> 8);
      local_34 = uVar1;
      local_2b = cVar10;
      local_28 = cVar10;
      FUN_1001f4d4(param_3,&local_3c,0x22);
      cVar10 = '\x03';
      sVar5 = 0;
      while( true ) {
        bVar7 = *(byte *)(param_1 + 0x15);
        bVar3 = (byte)(sVar5 + 1);
        puVar8 = (undefined1 *)(param_3 + ((ushort)(sVar5 * 0x1e) + 0x22 & 0xffff));
        if ((uint)bVar7 < (uint)bVar3) break;
        cVar11 = cVar10 + -2;
        uVar1 = *(undefined1 *)(param_1 + (uint)bVar3 + 0x15);
        puVar8[4] = cVar11;
        puVar8[7] = 0x24;
        puVar8[10] = cVar10 + -1;
        puVar8[0xd] = 0x24;
        puVar8[0x12] = cVar10 + -1;
        puVar8[0x15] = 9;
        puVar8[1] = 0x24;
        *puVar8 = 6;
        puVar8[6] = 6;
        puVar8[0x16] = 0x24;
        puVar8[0xc] = 9;
        puVar8[0x10] = cVar10;
        puVar8[2] = 2;
        puVar8[3] = 1;
        puVar8[5] = uVar1;
        puVar8[8] = 2;
        puVar8[9] = 2;
        puVar8[0xb] = uVar1;
        puVar8[0xe] = 3;
        puVar8[0xf] = 1;
        puVar8[0x11] = 1;
        puVar8[0x13] = 1;
        puVar8[0x14] = uVar1;
        puVar8[0x17] = 3;
        puVar8[0x18] = 2;
        puVar8[0x19] = bVar3 << 2;
        cVar10 = cVar10 + '\x04';
        puVar8[0x1a] = 1;
        puVar8[0x1b] = cVar11;
        puVar8[0x1c] = 1;
        puVar8[0x1d] = uVar1;
        sVar5 = sVar5 + 1;
      }
      FUN_1001f4c8((int)&local_38 + 1,0,4);
      local_3c = 0x509;
      local_3a = cVar4;
      local_39 = 2;
      local_38._0_1_ = 0x40;
      local_33 = bVar7 + 4;
      local_32 = 0x125;
      local_30 = bVar7;
      FUN_1001f4d4(puVar8,&local_3c,0xd);
      bVar7 = 1;
      uVar12 = (ushort)(sVar5 * 0x1e) + 0x2f;
      while( true ) {
        uVar9 = uVar12 & 0xffff;
        bVar3 = *(byte *)(param_1 + 0x15);
        if (bVar3 < bVar7) break;
        cVar4 = bVar7 * '\x04';
        uVar12 = uVar9 + 1;
        bVar7 = bVar7 + 1;
        *(char *)(param_3 + uVar9) = cVar4 + -3;
      }
      FUN_1001f4c8((int)&local_38 + 1,0,4);
      local_3c = 0x509;
      local_39 = 2;
      local_38 = CONCAT31(local_38._1_3_,0x40);
      local_33 = bVar3 + 4;
      local_32 = 0x125;
      local_3a = bVar2;
      local_30 = bVar3;
      FUN_1001f4d4((char *)(param_3 + uVar9),&local_3c,0xd);
      uVar9 = uVar9 + 0xd;
      for (bVar7 = 1; uVar9 = uVar9 & 0xffff, bVar7 <= *(byte *)(param_1 + 0x15); bVar7 = bVar7 + 1)
      {
        *(byte *)(param_3 + uVar9) = bVar7 * '\x04' + -1;
        uVar9 = uVar9 + 1;
      }
      if (uVar9 == local_54) {
        return local_54;
      }
    }
    local_54 = 0;
  }
  return local_54;
}



/* FUN_1001787c at 1001787c */

undefined4 * FUN_1001787c(undefined4 *param_1,undefined1 param_2)

{
  param_1[2] = 1000;
  param_1[1] = 0;
  *param_1 = &PTR_LAB_10017848_1_1002aaa0;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[4] = &DAT_1002aac8;
  *(undefined1 *)((int)param_1 + 0x15) = param_2;
  FUN_1001f4c8((int)param_1 + 0x16,0,0x10);
  return param_1;
}



/* FUN_100178ac at 100178ac */

void FUN_100178ac(int param_1)

{
  FUN_100173ac(0x200014ec,param_1 + 0x10);
  return;
}



/* FUN_100178c0 at 100178c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 FUN_100178c0(void)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (_DAT_200016d0 != 0) {
    uVar1 = *(undefined1 *)(_DAT_200016d0 + 0x60);
  }
  return uVar1;
}



/* FUN_10017964 at 10017964 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

char FUN_10017964(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  code *pcVar3;
  int iVar4;
  
  if (_DAT_200016d0 != 0) {
    iVar4 = _DAT_200016d0 + param_1 * 0x2c;
    pcVar3 = *(code **)(iVar4 + 0x14);
    if (pcVar3 != (code *)0x0) {
      uVar2 = (*pcVar3)();
      *(undefined1 *)(iVar4 + 0x32) = uVar2;
    }
    cVar1 = *(char *)(_DAT_200016d0 + param_1 * 0x2c + 0x32);
    if (cVar1 != '\0') {
      return cVar1;
    }
    FUN_10018cc0(param_1,2,0x3a);
  }
  return '\0';
}



/* FUN_10017ab4 at 10017ab4 */

void FUN_10017ab4(void)

{
  int iVar1;
  
  iVar1 = FUN_10027688(0x20001768,0);
  if (iVar1 != 0) {
    FUN_1001ab64(0xffffffff,0);
    FUN_10027618(0x20001768);
  }
  return;
}



/* FUN_10017adc at 10017adc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_10017adc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 local_14;
  undefined2 uStack_12;
  undefined4 uStack_10;
  
  local_14 = (undefined2)param_2;
  uStack_12 = (undefined2)((uint)param_2 >> 0x10);
  uStack_10 = param_3;
  FUN_1001d27c(0x20001768);
  local_14 = 1;
  FUN_1001a8d8(param_1,&local_14);
  _DAT_20001684 = FUN_1001d244(1);
  FUN_1001cfc8(_DAT_20001684,0x10017ab5);
  FUN_1001cf68(_DAT_20001684,1);
  FUN_1001d008(5,&LAB_10017aa4_1,0);
  return CONCAT26(uStack_12,CONCAT24(local_14,param_1));
}



/* FUN_10017b3c at 10017b3c */

void FUN_10017b3c(void)

{
  int iVar1;
  
  iVar1 = FUN_10027688(0x20001768,0);
  if (iVar1 != 0) {
    FUN_1001ab64(0xffffffff,0);
    FUN_10027618(0x20001768);
  }
  return;
}



/* FUN_10017c04 at 10017c04 */

void FUN_10017c04(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_1001a8b8();
  if (((iVar1 != 0) && (iVar1 = FUN_1001a8c8(), iVar1 == 0)) && (*(char *)(param_1 + 3) != '\0')) {
    uVar2 = FUN_1001a518(param_1 + 0x10);
    if ((0x3f < uVar2) && (iVar1 = FUN_1001aa2c(0,*(undefined1 *)(param_1 + 3)), iVar1 != 0)) {
      uVar2 = FUN_1001a518(param_1 + 0x10);
      if (uVar2 < 0x40) {
        FUN_1001aa50(0,*(undefined1 *)(param_1 + 3));
      }
      else {
        FUN_1001aa74(0,*(undefined1 *)(param_1 + 3),param_1 + 0x248,0x40);
      }
    }
  }
  return;
}



/* FUN_10017c5c at 10017c5c */

byte FUN_10017c5c(int param_1)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = FUN_1001a8b8();
  if ((iVar2 == 0) || (iVar2 = FUN_1001a8c8(), iVar2 != 0)) {
    bVar1 = 0;
  }
  else {
    bVar1 = *(byte *)(param_1 * 0x2c8 + 0x20001778) & 1;
  }
  return bVar1;
}



/* FUN_10017ca8 at 10017ca8 */

void FUN_10017ca8(int param_1)

{
  FUN_1001a4bc(param_1 * 0x2c8 + 0x20001784);
  return;
}



/* FUN_10017cc0 at 10017cc0 */

undefined4 FUN_10017cc0(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  
  if (0xffff < param_3) {
    param_3 = 0xffff;
  }
  uVar1 = FUN_1001a582(param_1 * 0x2c8 + 0x20001784,param_2,param_3 & 0xffff);
  FUN_10017c04(&DAT_20001774 + param_1 * 0x2c8);
  return uVar1;
}



/* FUN_10017cf4 at 10017cf4 */

void FUN_10017cf4(int param_1)

{
  FUN_1001a5c8(param_1 * 0x2c8 + 0x20001784);
  return;
}



/* FUN_10017d0c at 10017d0c */

undefined8 FUN_10017d0c(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_1001a8b8();
  if ((iVar1 != 0) && (iVar1 = FUN_1001a8c8(), iVar1 == 0)) {
    iVar2 = param_1 * 0x2c8;
    iVar1 = FUN_1001a4bc(iVar2 + 0x20001798);
    if ((iVar1 != 0) && (iVar1 = FUN_1001aa2c(0,(&DAT_20001776)[iVar2]), iVar1 != 0)) {
      iVar1 = FUN_1001a582(iVar2 + 0x20001798,iVar2 + 0x200019fc,0x40);
      if (iVar1 == 0) {
        FUN_1001aa50(0,(&DAT_20001776)[iVar2]);
      }
      else {
        iVar2 = FUN_1001aa74(0,(&DAT_20001776)[iVar2],iVar2 + 0x200019fc,iVar1);
        if (iVar2 != 0) goto LAB_10017d74;
      }
    }
  }
  iVar1 = 0;
LAB_10017d74:
  return CONCAT44(param_1,iVar1);
}



/* FUN_10017d84 at 10017d84 */

undefined4 FUN_10017d84(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = param_1 * 0x2c8 + 0x20001798;
  if (0xffff < param_3) {
    param_3 = 0xffff;
  }
  uVar1 = FUN_1001a660(iVar3,param_2,param_3 & 0xffff);
  uVar2 = FUN_1001a4bc(iVar3);
  if (0x3f < uVar2) {
    FUN_10017d0c(param_1);
  }
  return uVar1;
}



/* FUN_10017dc4 at 10017dc4 */

void FUN_10017dc4(int param_1)

{
  FUN_1001a518(param_1 * 0x2c8 + 0x20001798);
  return;
}



/* FUN_10017fa4 at 10017fa4 */

uint FUN_10017fa4(undefined4 param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if ((param_2[5] == 2) && (param_2[6] == 2)) {
    iVar5 = 0;
    if (DAT_20001776 != '\0') {
      if (DAT_20001a3e != '\0') goto LAB_10017fb0;
      iVar5 = 1;
    }
    uVar4 = 9;
    uVar2 = -iVar5 & 0x2c8;
    (&DAT_20001774)[iVar5 * 0x2c8] = param_2[2];
    for (param_2 = param_2 + *param_2; param_2[1] == 0x24; param_2 = param_2 + *param_2) {
      if (param_3 < uVar4) goto LAB_10017ff4;
      uVar4 = *param_2 + uVar4 & 0xffff;
    }
    if (param_2[1] == 5) {
      iVar3 = FUN_1001a9ac(param_1,param_2);
      if (iVar3 == 0) goto LAB_10017fb0;
      *(byte *)(iVar5 * 0x2c8 + 0x20001775) = param_2[2];
      uVar4 = *param_2 + uVar4 & 0xffff;
      param_2 = param_2 + *param_2;
    }
LAB_10017ff4:
    if ((param_2[1] == 4) && (param_2[5] == 10)) {
      bVar1 = *param_2;
      iVar5 = FUN_1001a9e0(param_1,param_2 + bVar1,2,2,&DAT_20001777 + uVar2,&DAT_20001776 + uVar2);
      if (iVar5 == 0) goto LAB_10017fb0;
      uVar4 = uVar4 + 0xe + (uint)bVar1 & 0xffff;
    }
    FUN_10017c04(&DAT_20001774 + uVar2);
  }
  else {
LAB_10017fb0:
    uVar4 = 0;
  }
  return uVar4;
}



/* FUN_1001827a at 1001827a */

void FUN_1001827a(void)

{
  return;
}



/* FUN_1001827c at 1001827c */

void FUN_1001827c(void)

{
  return;
}



/* FUN_10018284 at 10018284 */

void FUN_10018284(void)

{
  FUN_1001f4c8(0x20001e28,0,0x198);
  return;
}



/* FUN_100182a4 at 100182a4 */

uint FUN_100182a4(undefined4 param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  if (param_2[5] == 3) {
    bVar1 = param_2[4];
    uVar5 = (uint)bVar1 * 7 + 0x12;
    if (uVar5 <= param_3) {
      iVar6 = 0;
      if (DAT_20001e29 != '\0') {
        if (DAT_20001ef5 != '\0') {
          return 0;
        }
        iVar6 = 1;
      }
      pbVar3 = param_2 + *param_2;
      if (pbVar3[1] == 0x21) {
        *(byte **)(iVar6 * 0xcc + 0x20001e30) = pbVar3;
        uVar4 = -iVar6 & 0xcc;
        iVar2 = FUN_1001a9e0(param_1,pbVar3 + *pbVar3,(uint)bVar1,3,&DAT_20001e2a + uVar4,
                             &DAT_20001e29 + uVar4);
        if (iVar2 != 0) {
          if (param_2[6] == 1) {
            *(byte *)(iVar6 * 0xcc + 0x20001e2b) = param_2[7];
          }
          iVar6 = iVar6 * 0xcc;
          *(undefined1 *)(iVar6 + 0x20001e2e) = 1;
          *(byte *)(iVar6 + 0x20001e28) = param_2[2];
          *(undefined2 *)(iVar6 + 0x20001e2c) = *(undefined2 *)(*(int *)(iVar6 + 0x20001e30) + 7);
          if ((&DAT_20001e2a)[iVar6] == '\0') {
            return uVar5;
          }
          FUN_1001aa74(param_1,(&DAT_20001e2a)[iVar6],uVar4 + 0x20001eb4,0x40);
          return uVar5;
        }
      }
    }
  }
  return 0;
}



/* FUN_100185a8 at 100185a8 */

int FUN_100185a8(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_1001a4bc(param_1 + 0x24);
  if ((iVar1 != 0) && (iVar1 = FUN_1001aa2c(0,*(undefined1 *)(param_1 + 1)), iVar1 != 0)) {
    iVar1 = FUN_1001a582(param_1 + 0x24,param_1 + 0x188,0x40);
    if (iVar1 == 0) {
      FUN_1001aa50(0,*(undefined1 *)(param_1 + 1));
    }
    else {
      iVar2 = FUN_1001aa74(0,*(undefined1 *)(param_1 + 1),param_1 + 0x188,iVar1);
      if (iVar2 != 0) {
        return iVar1;
      }
    }
  }
  return 0;
}



/* FUN_100185f6 at 100185f6 */

void FUN_100185f6(int param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_1001a518(param_1 + 0x10);
  if ((0x3f < uVar1) && (iVar2 = FUN_1001aa2c(0,*(undefined1 *)(param_1 + 2)), iVar2 != 0)) {
    uVar1 = FUN_1001a518(param_1 + 0x10);
    if (uVar1 < 0x40) {
      FUN_1001aa50(0,*(undefined1 *)(param_1 + 2));
    }
    else {
      FUN_1001aa74(0,*(undefined1 *)(param_1 + 2),param_1 + 0x148,0x40);
    }
  }
  return;
}



/* FUN_10018638 at 10018638 */

int FUN_10018638(int param_1)

{
  int iVar1;
  
  param_1 = param_1 * 0x1c8;
  iVar1 = FUN_1001a4bc(param_1 + 0x20001fd0);
  return ((uint)*(byte *)(param_1 + 0x20001fce) - (uint)*(byte *)(param_1 + 0x20001fcd) & 0xff) +
         iVar1;
}



/* FUN_10018660 at 10018660 */

bool FUN_10018660(int param_1,undefined4 param_2)

{
  int iVar1;
  bool bVar2;
  
  param_1 = param_1 * 0x1c8;
  bVar2 = false;
  if ((&DAT_20001fc2)[param_1] != '\0') {
    iVar1 = FUN_1001a582(param_1 + 0x20001fd0,param_2,4);
    bVar2 = iVar1 == 4;
    FUN_100185f6(&DAT_20001fc0 + param_1);
  }
  return bVar2;
}



/* FUN_10018694 at 10018694 */

int FUN_10018694(int param_1,undefined4 param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int local_2c;
  int local_28;
  
  if (param_4 == 0) {
LAB_100186ec:
    local_2c = 0;
  }
  else {
    iVar4 = param_1 * 0x1c8;
    local_2c = 0;
    local_28 = param_3;
    do {
      if (*(char *)(iVar4 + 0x20001fce) == '\0') {
        iVar1 = FUN_10018660(param_1,iVar4 + 0x20001fc9);
        if (iVar1 == 0) {
          return local_2c;
        }
        uVar2 = 1 << (*(byte *)(iVar4 + 0x20001fc9) & 0xf);
        if ((uVar2 & 0x3044) == 0) {
          if ((uVar2 & 3) != 0) goto LAB_100186ec;
          if ((uVar2 & 0x8020) == 0) {
            *(undefined1 *)(iVar4 + 0x20001fce) = 3;
          }
          else {
            *(undefined1 *)(iVar4 + 0x20001fce) = 1;
          }
        }
        else {
          *(undefined1 *)(iVar4 + 0x20001fce) = 2;
        }
      }
      uVar2 = (uint)*(byte *)(iVar4 + 0x20001fce) - (uint)*(byte *)(iVar4 + 0x20001fcd);
      if (param_4 < uVar2) {
        uVar2 = param_4;
      }
      uVar3 = uVar2 & 0xff;
      if (param_4 < uVar3) goto LAB_100186ec;
      FUN_1001f4d4(local_28,iVar4 + 0x20001fc9 + *(byte *)(iVar4 + 0x20001fcd) + 1,uVar3);
      local_2c = local_2c + uVar3;
      param_4 = param_4 - uVar3;
      uVar2 = (uVar2 & 0xff) + (uint)*(byte *)(iVar4 + 0x20001fcd);
      local_28 = local_28 + uVar3;
      *(char *)(iVar4 + 0x20001fcd) = (char)uVar2;
      if ((uint)*(byte *)(iVar4 + 0x20001fce) == (uVar2 & 0xff)) {
        *(undefined1 *)(iVar4 + 0x20001fcd) = 0;
        *(undefined1 *)(iVar4 + 0x20001fce) = 0;
      }
    } while (param_4 != 0);
  }
  return local_2c;
}



/* FUN_10018760 at 10018760 */

uint FUN_10018760(int param_1,int param_2,int param_3,uint param_4)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  uint local_34;
  
  iVar4 = param_1 * 0x1c8;
  local_34 = (uint)(byte)(&DAT_20001fc1)[iVar4];
  if (local_34 != 0) {
    local_34 = 0;
    do {
      do {
        if ((local_34 == param_4) || (uVar3 = FUN_1001a518(iVar4 + 0x20001fe4), uVar3 < 4)) {
          FUN_100185a8(&DAT_20001fc0 + iVar4);
          return local_34;
        }
        bVar2 = *(byte *)(param_3 + local_34);
        local_34 = local_34 + 1;
        iVar6 = param_1 * 0x1c8;
        bVar1 = *(byte *)(iVar6 + 0x20001fc7);
        uVar3 = (uint)bVar1;
        if (uVar3 == 0) {
          *(undefined1 *)(iVar6 + 0x20001fc7) = 2;
          *(byte *)(iVar6 + 0x20001fc4) = bVar2;
          if ((*(byte *)(iVar6 + 0x20001fc3) & 0xf) == 4) {
            if (bVar2 != 0xf7) {
              *(undefined1 *)(iVar6 + 0x20001fc8) = 4;
              goto LAB_100187ae;
            }
            *(byte *)(iVar6 + 0x20001fc3) = (byte)(param_2 << 4) | 5;
          }
          else {
            if ((bVar2 >> 4) - 8 < 8) {
                    /* WARNING: Subroutine does not return */
              FUN_10027708();
            }
            *(byte *)(iVar6 + 0x20001fc5) = bVar1;
            *(byte *)(iVar6 + 0x20001fc3) = (byte)(param_2 << 4) | 0xf;
            *(byte *)(iVar6 + 0x20001fc6) = bVar1;
          }
          *(undefined1 *)(iVar6 + 0x20001fc8) = 2;
        }
        else {
          if (3 < uVar3) {
            return local_34;
          }
          *(byte *)(iVar6 + uVar3 + 0x20001fc3) = bVar2;
          *(byte *)(iVar6 + 0x20001fc7) = bVar1 + 1;
          if (((*(byte *)(iVar6 + 0x20001fc3) & 0xf) == 4) && (bVar2 == 0xf7)) {
            *(byte *)(iVar6 + 0x20001fc3) = bVar1 + 4 | (byte)(param_2 << 4);
            *(byte *)(iVar6 + 0x20001fc8) = bVar1 + 1;
          }
        }
LAB_100187ae:
        uVar3 = (uint)*(byte *)(param_1 * 0x1c8 + 0x20001fc8);
      } while (*(byte *)(param_1 * 0x1c8 + 0x20001fc7) != uVar3);
      puVar5 = &DAT_20001fc0 + uVar3 + iVar4;
      for (; uVar3 < 4; uVar3 = uVar3 + 1 & 0xff) {
        puVar5[3] = 0;
        puVar5 = puVar5 + 1;
      }
      iVar6 = FUN_1001a660(iVar4 + 0x20001fe4,iVar4 + 0x20001fc3,4);
      *(undefined1 *)(param_1 * 0x1c8 + 0x20001fc8) = 0;
      *(undefined1 *)(param_1 * 0x1c8 + 0x20001fc7) = 0;
    } while (iVar6 == 4);
  }
  return local_34;
}



/* FUN_100189bc at 100189bc */

uint FUN_100189bc(undefined4 param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  
  if (((param_2[5] == 1) && (param_2[6] == 1)) && (param_2[7] == 0)) {
    uVar4 = (uint)*param_2;
    for (param_2 = param_2 + uVar4; param_2[1] == 0x24; param_2 = param_2 + *param_2) {
      if (param_3 < uVar4) {
        return 0;
      }
      uVar4 = *param_2 + uVar4 & 0xffff;
    }
    if ((((param_2[1] == 4) && (param_2[5] == 1)) &&
        ((param_2[6] == 3 && ((param_2[7] == 0 && (DAT_20001fc1 == 0)))))) && (DAT_20001fc2 == 0)) {
      DAT_20001fc0 = param_2[2];
      pbVar5 = param_2 + *param_2;
      bVar3 = 0;
      for (uVar4 = *param_2 + uVar4;
          (uVar4 = uVar4 & 0xffff, bVar3 < param_2[4] && (uVar4 <= param_3)); uVar4 = bVar1 + uVar4)
      {
        if (pbVar5[1] == 5) {
          iVar2 = FUN_1001a9ac(param_1,pbVar5);
          if (iVar2 == 0) {
            return 0;
          }
          bVar1 = pbVar5[2];
          if ((char)bVar1 < '\0') {
            DAT_20001fc1 = bVar1;
          }
          else {
            DAT_20001fc2 = bVar1;
          }
          bVar1 = *pbVar5;
          pbVar5 = pbVar5 + bVar1;
          uVar4 = bVar1 + uVar4 & 0xffff;
          bVar3 = bVar3 + 1;
        }
        bVar1 = *pbVar5;
        pbVar5 = pbVar5 + bVar1;
      }
      FUN_100185f6(&DAT_20001fc0);
      return uVar4;
    }
  }
  return 0;
}



/* FUN_10018cc0 at 10018cc0 */

undefined4 FUN_10018cc0(undefined4 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  DAT_200023c4 = param_2;
  DAT_200023c5 = param_3;
  DAT_200023c6 = param_4;
  return 1;
}



/* FUN_1001935c at 1001935c */

void FUN_1001935c(int param_1)

{
  if (param_1 == 0) {
    FUN_1001c0d0(0,&DAT_200024a8);
  }
  return;
}



/* FUN_100193d4 at 100193d4 */

undefined4 FUN_100193d4(void)

{
  FUN_1001c04e(&DAT_2000250c);
  FUN_1001c04e(&DAT_200024a8);
  return 1;
}



/* FUN_10019518 at 10019518 */

/* WARNING: Removing unreachable block (ram,0x10019538) */
/* WARNING: Removing unreachable block (ram,0x10019576) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10019518(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  
  if (DAT_2000250d == param_2) {
    if (_DAT_20002518 != 0) {
      FUN_1001a660(0x20002514,_DAT_20002510,param_4 & 0xffff);
    }
    FUN_1001c150(param_1,&DAT_2000250c);
  }
  else {
    if (DAT_200024a9 != param_2) {
      return 0;
    }
    iVar1 = FUN_1001c0d0(param_1,&DAT_200024a8);
    if (iVar1 == 0) {
      FUN_1001c054(param_1,&DAT_200024a8,param_4);
    }
  }
  return 1;
}



/* FUN_100195ac at 100195ac */

void FUN_100195ac(byte *param_1,byte *param_2,uint param_3)

{
  for (; (param_1 < param_2 && (param_1[1] != param_3)); param_1 = param_1 + *param_1) {
  }
  return;
}



/* FUN_100195c0 at 100195c0 */

byte * FUN_100195c0(byte *param_1,byte *param_2,uint param_3)

{
  while( true ) {
    if (param_2 <= param_1) {
      return param_2;
    }
    if (((param_1[2] < 0x11) && ((0x11050U >> (uint)param_1[2] & 1) != 0)) &&
       (param_1[3] == param_3)) break;
    param_1 = (byte *)FUN_100195ac(param_1 + *param_1,param_2,0x24);
  }
  return param_1;
}



/* FUN_100195f8 at 100195f8 */

byte * FUN_100195f8(byte *param_1,byte *param_2,uint param_3)

{
  while( true ) {
    if (param_2 <= param_1) {
      return param_2;
    }
    if (((param_1[2] < 0x12) && ((0x200a0U >> (uint)param_1[2] & 1) != 0)) &&
       (param_1[3] == param_3)) break;
    param_1 = (byte *)FUN_100195ac(param_1 + *param_1,param_2,0x24);
  }
  return param_1;
}



/* FUN_10019630 at 10019630 */

undefined8 FUN_10019630(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = (uint)*(byte *)(param_1 + 0x50);
  uVar4 = *(uint *)(param_1 + 0x18);
  uVar3 = (uVar1 - *(int *)(param_1 + 0x14)) + *(int *)(param_1 + 0x10);
  uVar2 = uVar3;
  if (uVar4 < uVar3) {
    uVar2 = uVar4;
  }
  if (uVar2 < uVar1) {
    uVar2 = 0;
  }
  else {
    FUN_1001f4d4(param_1 + uVar1 + 0x50,*(int *)(param_1 + 0xc) + *(int *)(param_1 + 0x14));
    *(uint *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + (uVar2 - uVar1);
    if (uVar3 <= uVar4) {
      *(byte *)(param_1 + 0x51) = *(byte *)(param_1 + 0x51) | 2;
    }
  }
  return CONCAT44(param_1,uVar2);
}



/* FUN_1001967e at 1001967e */

byte * FUN_1001967e(byte *param_1,byte *param_2,uint param_3,uint param_4)

{
  while( true ) {
    if (param_2 <= param_1) {
      return param_2;
    }
    if ((param_3 == param_1[2]) && (param_4 == param_1[3])) break;
    param_1 = (byte *)FUN_100195ac(param_1 + *param_1,param_2,4);
  }
  return param_1;
}



/* FUN_100196a8 at 100196a8 */

undefined8 FUN_100196a8(undefined4 param_1,int *param_2,undefined4 param_3)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 uVar5;
  byte *pbVar6;
  int iVar7;
  
  iVar3 = *param_2;
  uVar2 = *(ushort *)(param_2 + 1);
  uVar5 = param_1;
  pbVar4 = (byte *)FUN_1001967e(iVar3,(byte *)(iVar3 + (uint)uVar2),*(undefined1 *)(iVar3 + 2),
                                param_3,param_1,param_1,param_3);
  if (((pbVar4 < (byte *)(iVar3 + (uint)uVar2)) && (pbVar4[0x14] < 2)) &&
     ((pbVar4[4] == 0 ||
      (((pbVar4[4] == 1 &&
        (uVar2 = *(ushort *)(pbVar4 + 0xe), bVar1 = *pbVar4,
        pbVar6 = (byte *)FUN_100195ac(pbVar4 + (uint)pbVar4[9] + (uint)bVar1,
                                      pbVar4 + (uint)uVar2 + (uint)bVar1,5),
        pbVar6 < pbVar4 + (uint)uVar2 + (uint)bVar1)) &&
       (iVar7 = FUN_1001a9ac(uVar5,pbVar6), iVar7 != 0)))))) {
    uVar5 = 1;
    *(char *)((int)param_2 + 6) = (char)((int)pbVar4 - iVar3);
    *(char *)((int)param_2 + 7) = (char)((uint)((int)pbVar4 - iVar3) >> 8);
  }
  else {
    uVar5 = 0;
  }
  return CONCAT44(param_1,uVar5);
}



/* FUN_1001972e at 1001972e */

void FUN_1001972e(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  
  pbVar1 = param_1 + 2;
  do {
    if ((param_2 <= param_1) || (param_1[2] != *pbVar1)) {
      return;
    }
    do {
      param_1 = param_1 + *param_1;
      if ((param_2 <= param_1) || (param_1[1] == 4)) break;
    } while (param_1[1] != 0xb);
  } while( true );
}



/* FUN_10019750 at 10019750 */

int FUN_10019750(int param_1,int param_2)

{
  if (param_2 != 0) {
    param_2 = *(int *)(&DAT_20003c45 + param_1 * 0xb) + param_2;
  }
  return param_2;
}



/* FUN_1001977c at 1001977c */

undefined8 FUN_1001977c(byte *param_1,undefined4 param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  undefined4 uVar3;
  byte *pbVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *local_20;
  
  pbVar2 = (byte *)FUN_10019750();
  local_20 = param_1;
  if (pbVar2 != (byte *)0x0) {
    if (*(byte *)(param_3 + 2) <= pbVar2[0xc]) {
      if (*(byte *)(param_3 + 2) == 0) {
        if (pbVar2[0xc] < 2) {
          *(undefined1 *)(param_3 + 2) = 1;
          goto LAB_100197a0;
        }
LAB_10019798:
        uVar3 = 1;
        goto LAB_1001979a;
      }
LAB_100197a0:
      *(undefined1 *)(param_3 + 0x1a) = 0xc0;
      *(undefined1 *)(param_3 + 0x1b) = 0xfc;
      *(undefined1 *)(param_3 + 0x1e) = 3;
      *(undefined1 *)(param_3 + 0x1c) = 0x9b;
      *(undefined1 *)(param_3 + 0x1f) = 1;
      *(undefined1 *)(param_3 + 8) = 1;
      *(undefined1 *)(param_3 + 9) = 0;
      *(undefined1 *)(param_3 + 10) = 0;
      *(undefined1 *)(param_3 + 0xb) = 0;
      *(undefined1 *)(param_3 + 0xe) = 1;
      *(undefined1 *)(param_3 + 0xf) = 0;
      *(undefined1 *)(param_3 + 0x10) = 0;
      *(undefined1 *)(param_3 + 0x11) = 0;
      *(undefined1 *)(param_3 + 0x1d) = 1;
      *(undefined1 *)(param_3 + 0x20) = 1;
      *(undefined1 *)(param_3 + 0x21) = 1;
      *(undefined1 *)(param_3 + 0x22) = 0;
      *(undefined1 *)(param_3 + 0x23) = 8;
      local_20 = pbVar2 + (uint)*(ushort *)(pbVar2 + 0xd) + (uint)*pbVar2;
      pbVar2 = (byte *)FUN_100195c0(pbVar2 + *pbVar2,local_20);
      if (local_20 != pbVar2) {
        bVar1 = pbVar2[2];
        if (bVar1 == 4) {
          *(undefined1 *)(param_3 + 0xc) = 1;
          *(undefined1 *)(param_3 + 0xd) = 0;
        }
        else if (bVar1 != 6) goto LAB_1001980a;
        if (*(byte *)(param_3 + 3) <= pbVar2[4]) {
          if (*(byte *)(param_3 + 3) == 0) {
            if (1 < pbVar2[4]) goto LAB_10019798;
            *(undefined1 *)(param_3 + 3) = 1;
          }
          pbVar4 = (byte *)FUN_100195f8(pbVar2 + *pbVar2,local_20);
          if (local_20 != pbVar4) {
            uVar7 = *(uint *)(param_3 + 0x12);
            if (uVar7 == 0) {
              if (bVar1 == 4) {
                uVar6 = (uint)pbVar2[0x15] *
                        (uint)*(ushort *)(pbVar4 + 5) * (uint)*(ushort *)(pbVar4 + 7);
              }
              else {
                uVar6 = (uint)*(ushort *)(pbVar4 + 5) * (uint)*(ushort *)(pbVar4 + 7) * 0x10;
              }
              uVar7 = uVar6 >> 3;
              *(char *)(param_3 + 0x13) = (char)(uVar7 >> 8);
              *(char *)(param_3 + 0x14) = (char)(uVar6 >> 0x13);
              *(char *)(param_3 + 0x12) = (char)uVar7;
              *(byte *)(param_3 + 0x15) = (byte)(uVar6 >> 0x1b);
            }
            uVar6 = *(uint *)(param_3 + 4);
            if (uVar6 == 0) {
              if ((1 < pbVar4[0x19]) ||
                 ((uVar6 = *(uint *)(pbVar4 + 0x1a), pbVar4[0x19] == 0 &&
                  (*(uint *)(pbVar4 + 0x1e) != uVar6)))) goto LAB_10019798;
              *(char *)(param_3 + 5) = (char)(uVar6 >> 8);
              *(char *)(param_3 + 6) = (char)(uVar6 >> 0x10);
              *(char *)(param_3 + 4) = (char)uVar6;
              *(char *)(param_3 + 7) = (char)(uVar6 >> 0x18);
            }
            if (9999 < uVar6) {
              iVar5 = FUN_1001e4d0(uVar6,10000);
              iVar5 = FUN_1001e4d0((uVar7 - 1) + iVar5,iVar5);
              uVar7 = iVar5 + 2;
              if (0x100 < uVar7) {
                uVar7 = 0x100;
              }
              *(char *)(param_3 + 0x16) = (char)uVar7;
              *(char *)(param_3 + 0x17) = (char)(uVar7 >> 8);
              *(char *)(param_3 + 0x18) = (char)(uVar7 >> 0x10);
              *(char *)(param_3 + 0x19) = (char)(uVar7 >> 0x18);
              goto LAB_10019798;
            }
          }
        }
      }
    }
  }
LAB_1001980a:
  uVar3 = 0;
LAB_1001979a:
  return CONCAT44(local_20,uVar3);
}



/* FUN_10019924 at 10019924 */

undefined4 FUN_10019924(undefined4 param_1,byte *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  undefined4 uVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  iVar2 = *(int *)(&DAT_20003c45 + (uint)*param_2 * 0xb);
  if (*(ushort *)(param_2 + 8) != 0) {
    iVar5 = iVar2 + (uint)*(ushort *)(param_2 + 8);
    if ((*(byte *)(iVar5 + 3) & 3) == 1) {
      param_2[8] = 0;
      param_2[9] = 0;
      FUN_1001b11c(param_1,*(undefined1 *)(iVar5 + 2));
    }
    if ((*(ushort *)(param_2 + 10) != 0) &&
       (iVar5 = iVar2 + (uint)*(ushort *)(param_2 + 10), (*(byte *)(iVar5 + 3) & 3) == 1)) {
      param_2[10] = 0;
      param_2[0xb] = 0;
      FUN_1001b11c(param_1,*(undefined1 *)(iVar5 + 2));
    }
  }
  param_2[0xc] = 0;
  param_2[0xd] = 0;
  param_2[0xe] = 0;
  param_2[0xf] = 0;
  param_2[0x10] = 0;
  param_2[0x11] = 0;
  param_2[0x12] = 0;
  param_2[0x13] = 0;
  param_2[0x14] = 0;
  param_2[0x15] = 0;
  param_2[0x16] = 0;
  param_2[0x17] = 0;
  pbVar6 = (byte *)(iVar2 + (uint)*(ushort *)(param_2 + 4));
  pbVar3 = (byte *)FUN_1001967e(iVar2 + (uint)*(ushort *)(param_2 + 2),pbVar6,
                                *(undefined1 *)(iVar2 + (uint)*(ushort *)(param_2 + 2) + 2),param_3)
  ;
  if ((pbVar3 < pbVar6) && (bVar1 = pbVar3[4], bVar1 < 3)) {
    *(short *)(param_2 + 6) = (short)((int)pbVar3 - iVar2);
    if ((param_3 == 0) && (param_2[0x1d] != 1)) {
      param_2[0x1d] = 0;
      param_2[0x18] = 0;
      param_2[0x19] = 0;
      param_2[0x1a] = 0;
      param_2[0x1b] = 0;
      FUN_1001f4c8(param_2 + 0x1e,0,0x30);
      iVar5 = FUN_1001977c(*param_2,(int)pbVar3 - iVar2 & 0xffff,param_2 + 0x1e);
      if (iVar5 == 0) goto LAB_1001999c;
    }
    pbVar3 = pbVar3 + *pbVar3;
    for (pbVar7 = param_2; param_2 + (uint)bVar1 * 2 != pbVar7; pbVar7 = pbVar7 + 2) {
      while( true ) {
        if (pbVar6 <= pbVar3) goto LAB_1001999c;
        if (pbVar3[1] == 5) break;
        if (pbVar3[1] == 4) goto LAB_1001999c;
        pbVar3 = pbVar3 + *pbVar3;
      }
      if ((param_3 == 0) || ((pbVar3[3] & 3) != 1)) {
        if ((pbVar3[3] & 3) != 2) goto LAB_1001999c;
      }
      else if ((*(ushort *)(pbVar3 + 4) & 0x7ff) < *(uint *)(param_2 + 0x18)) goto LAB_1001999c;
      iVar5 = FUN_1001a9ac(param_1,pbVar3);
      if (iVar5 == 0) goto LAB_1001999c;
      *(short *)(pbVar7 + 8) = (short)pbVar3 - (short)iVar2;
      pbVar3 = pbVar3 + *pbVar3;
    }
    if (param_3 != 0) {
      param_2[0x1d] = 2;
    }
    uVar4 = 1;
  }
  else {
LAB_1001999c:
    uVar4 = 0;
  }
  return uVar4;
}



/* FUN_10019abc at 10019abc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_10019abc(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  uint uVar5;
  int local_30;
  undefined1 *local_28;
  
  if ((((*(char *)(param_2 + 5) == '\x0e') && (*(char *)(param_2 + 6) == '\x01')) &&
      (*(char *)(param_2 + 7) == '\x01')) &&
     (CONCAT13(DAT_20003c48,CONCAT12(DAT_20003c47,CONCAT11(DAT_20003c46,DAT_20003c45))) == 0)) {
    DAT_20003c46 = (undefined1)((uint)param_2 >> 8);
    DAT_20003c47 = (undefined1)((uint)param_2 >> 0x10);
    DAT_20003c45 = (undefined1)param_2;
    DAT_20003c48 = (undefined1)((uint)param_2 >> 0x18);
    DAT_20003c49 = (undefined1)param_3;
    DAT_20003c4a = (undefined1)((uint)param_3 >> 8);
    iVar2 = FUN_100196a8(param_1,&DAT_20003c45,0);
    if (iVar2 != 0) {
      cVar1 = *(char *)(CONCAT13(DAT_20003c48,
                                 CONCAT12(DAT_20003c47,CONCAT11(DAT_20003c46,DAT_20003c45))) +
                        (uint)CONCAT11(DAT_20003c4c,DAT_20003c4b) + 0x14);
      local_30 = FUN_1001972e(param_2,param_2 + param_3);
      local_28 = &DAT_20003c45;
      cVar4 = '\0';
      while( true ) {
        if (cVar1 == cVar4) {
          uVar3 = local_30 - param_2 & 0xffff;
          DAT_20003c49 = (char)(local_30 - param_2);
          DAT_20003c4a = (char)(uVar3 >> 8);
          return uVar3;
        }
        if (_DAT_20002572 != 0) break;
        local_28[8] = 0;
        uVar3 = local_30 - param_2;
        _DAT_20002572 = (short)uVar3;
        DAT_20002570 = 0;
        DAT_20002571 = cVar4;
        local_30 = FUN_1001972e(local_30,param_2 + param_3);
        _DAT_20002574 = (short)local_30 - (short)param_2;
        DAT_2000258d = 0;
        if (((cVar4 == '\0') && (cVar1 == '\x01')) &&
           ((uVar5 = (uint)_DAT_20002574, iVar2 = param_2 + (uVar3 & 0xffff),
            iVar2 = FUN_1001967e(iVar2,param_2 + uVar5,*(undefined1 *)(iVar2 + 2),1),
            param_2 + uVar5 == iVar2 && (iVar2 = FUN_10019924(param_1,&DAT_20002570,0), iVar2 == 0))
           )) {
          return 0;
        }
        cVar4 = cVar4 + '\x01';
        local_28 = local_28 + 1;
      }
    }
  }
  return 0;
}



/* FUN_1001a360 at 1001a360 */

uint FUN_1001a360(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  
  uVar1 = param_2 + param_3 & 0xffff;
  if ((uVar1 < param_2) || (param_1 * 2 <= (int)uVar1)) {
    uVar1 = uVar1 + param_1 * -2 & 0xffff;
  }
  return uVar1;
}



/* FUN_1001a376 at 1001a376 */

undefined4 FUN_1001a376(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar3 = param_3 - param_4 & 0xffff;
  uVar2 = *(ushort *)(param_1 + 1);
  uVar1 = (uint)uVar2;
  if (param_3 < param_4) {
    uVar3 = uVar3 + uVar1 * 2 & 0xffff;
  }
  uVar4 = 0;
  if (uVar3 != 0) {
    if (uVar1 < uVar3) {
      if (uVar1 <= param_3) {
        uVar2 = -uVar2;
      }
      uVar2 = (short)param_3 + uVar2;
      param_4 = (uint)uVar2;
      *(ushort *)((int)param_1 + 10) = uVar2;
    }
    for (; uVar1 <= param_4; param_4 = param_4 - uVar1 & 0xffff) {
    }
    FUN_1001f4d4(param_2,*param_1 + (*(ushort *)((int)param_1 + 6) & 0x7fff) * param_4);
    uVar4 = 1;
  }
  return uVar4;
}



/* FUN_1001a3c2 at 1001a3c2 */

uint FUN_1001a3c2(int *param_1,int param_2,uint param_3,uint param_4,ushort param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar2 = (uint)param_5;
  uVar5 = (uint)*(ushort *)(param_1 + 1);
  uVar3 = param_4 - uVar2 & 0xffff;
  if (param_4 < uVar2) {
    uVar3 = uVar3 + uVar5 * 2 & 0xffff;
  }
  uVar4 = 0;
  if (uVar3 != 0) {
    if (uVar5 < uVar3) {
      uVar3 = uVar5;
      if (uVar5 <= param_4) {
        uVar3 = -uVar5;
      }
      uVar2 = param_4 + uVar3 & 0xffff;
      *(short *)((int)param_1 + 10) = (short)(param_4 + uVar3);
      uVar3 = uVar5;
    }
    if (param_3 < uVar3) {
      uVar3 = param_3;
    }
    uVar4 = uVar3 & 0xffff;
    for (; uVar5 <= uVar2; uVar2 = uVar2 - uVar5 & 0xffff) {
    }
    uVar3 = *(ushort *)((int)param_1 + 6) & 0x7fff;
    uVar6 = uVar5 - uVar2 & 0xffff;
    iVar1 = *param_1 + uVar2 * uVar3;
    if (uVar6 < uVar4) {
      uVar6 = uVar3 * uVar6 & 0xffff;
      FUN_1001f4d4(param_2,iVar1,uVar6);
      param_2 = param_2 + uVar6;
      uVar3 = uVar3 * (uVar2 + (uVar4 - uVar5)) & 0xffff;
      iVar1 = *param_1;
    }
    else {
      uVar3 = uVar4 * uVar3;
    }
    FUN_1001f4d4(param_2,iVar1,uVar3);
  }
  return uVar4;
}



/* FUN_1001a458 at 1001a458 */

undefined8
FUN_1001a458(undefined4 *param_1,undefined4 param_2,uint param_3,ushort param_4,byte param_5)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_3 < 0x8001) {
    if (param_1[3] != 0) {
      FUN_100276a8(param_1[3],0xffffffff);
    }
    if (param_1[4] != 0) {
      FUN_100276a8(param_1[4],0xffffffff);
    }
    *(undefined2 *)((int)param_1 + 10) = 0;
    *param_1 = param_2;
    *(short *)(param_1 + 1) = (short)param_3;
    *(ushort *)((int)param_1 + 6) = (ushort)param_5 << 0xf | param_4 & 0x7fff;
    *(undefined2 *)(param_1 + 2) = 0;
    if (param_1[3] != 0) {
      FUN_10027618();
    }
    if (param_1[4] != 0) {
      FUN_10027618();
    }
    uVar1 = 1;
  }
  return CONCAT44(param_1,uVar1);
}



/* FUN_1001a4bc at 1001a4bc */

ushort FUN_1001a4bc(int param_1)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar3 = *(ushort *)(param_1 + 10);
  uVar2 = *(ushort *)(param_1 + 4);
  if (*(ushort *)(param_1 + 8) < uVar3) {
    sVar1 = uVar2 * 2 - uVar3;
  }
  else {
    sVar1 = -uVar3;
  }
  uVar3 = *(ushort *)(param_1 + 8) + sVar1;
  if (uVar3 < uVar2) {
    uVar2 = uVar3;
  }
  return uVar2;
}



/* FUN_1001a4e4 at 1001a4e4 */

bool FUN_1001a4e4(int param_1)

{
  return *(short *)(param_1 + 8) == *(short *)(param_1 + 10);
}



/* FUN_1001a4f2 at 1001a4f2 */

bool FUN_1001a4f2(int param_1)

{
  ushort uVar1;
  short sVar2;
  
  uVar1 = *(ushort *)(param_1 + 10);
  if (*(ushort *)(param_1 + 8) < uVar1) {
    sVar2 = *(ushort *)(param_1 + 4) * 2 - uVar1;
  }
  else {
    sVar2 = -uVar1;
  }
  return *(ushort *)(param_1 + 4) <= (ushort)(*(ushort *)(param_1 + 8) + sVar2);
}



/* FUN_1001a518 at 1001a518 */

short FUN_1001a518(int param_1)

{
  ushort uVar1;
  short sVar2;
  ushort uVar3;
  
  uVar3 = *(ushort *)(param_1 + 10);
  uVar1 = *(ushort *)(param_1 + 4);
  if (*(ushort *)(param_1 + 8) < uVar3) {
    sVar2 = uVar1 * 2 - uVar3;
  }
  else {
    sVar2 = -uVar3;
  }
  uVar3 = *(ushort *)(param_1 + 8) + sVar2;
  sVar2 = 0;
  if (uVar3 < uVar1) {
    sVar2 = uVar1 - uVar3;
  }
  return sVar2;
}



/* FUN_1001a540 at 1001a540 */

undefined4 FUN_1001a540(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_100276a8(*(int *)(param_1 + 0x10),0xffffffff);
  }
  uVar2 = FUN_1001a376(param_1,param_2,*(undefined2 *)(param_1 + 8),*(undefined2 *)(param_1 + 10));
  uVar1 = FUN_1001a360(*(undefined2 *)(param_1 + 4),*(undefined2 *)(param_1 + 10),uVar2);
  *(undefined2 *)(param_1 + 10) = uVar1;
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_10027618();
  }
  return uVar2;
}



/* FUN_1001a582 at 1001a582 */

undefined8 FUN_1001a582(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_100276a8(*(int *)(param_1 + 0x10),0xffffffff,param_3,param_4,param_1,param_2);
  }
  uVar3 = (uint)*(ushort *)(param_1 + 10);
  uVar2 = FUN_1001a3c2(param_1,param_2,param_3,*(undefined2 *)(param_1 + 8));
  uVar1 = FUN_1001a360(*(undefined2 *)(param_1 + 4),*(undefined2 *)(param_1 + 10),uVar2);
  *(undefined2 *)(param_1 + 10) = uVar1;
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_10027618();
  }
  return CONCAT44(uVar3,uVar2);
}



/* FUN_1001a5c8 at 1001a5c8 */

undefined4 FUN_1001a5c8(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_100276a8(*(int *)(param_1 + 0x10),0xffffffff);
  }
  uVar1 = FUN_1001a376(param_1,param_2,*(undefined2 *)(param_1 + 8),*(undefined2 *)(param_1 + 10));
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_10027618();
  }
  return uVar1;
}



/* FUN_1001a5fc at 1001a5fc */

undefined1 FUN_1001a5fc(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 uVar5;
  
  if (param_1[3] != 0) {
    FUN_100276a8(param_1[3],0xffffffff,param_3,param_4,param_4);
  }
  uVar1 = *(ushort *)(param_1 + 2);
  iVar3 = FUN_1001a4f2(param_1);
  if ((iVar3 == 0) || (uVar5 = 0, *(char *)((int)param_1 + 7) < '\0')) {
    for (uVar4 = (uint)uVar1; *(ushort *)(param_1 + 1) <= uVar4;
        uVar4 = uVar4 - *(ushort *)(param_1 + 1) & 0xffff) {
    }
    FUN_1001f4d4(*param_1 + (*(ushort *)((int)param_1 + 6) & 0x7fff) * uVar4,param_2);
    uVar2 = FUN_1001a360((short)param_1[1],(uint)uVar1,1);
    uVar5 = 1;
    *(undefined2 *)(param_1 + 2) = uVar2;
  }
  if (param_1[3] != 0) {
    FUN_10027618();
  }
  return uVar5;
}



/* FUN_1001a660 at 1001a660 */

uint FUN_1001a660(int *param_1,int param_2,uint param_3)

{
  ushort uVar1;
  ushort uVar2;
  short sVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint local_28;
  int local_24;
  
  if (param_3 == 0) {
    return 0;
  }
  if (param_1[3] != 0) {
    FUN_100276a8(param_1[3],0xffffffff);
  }
  uVar1 = *(ushort *)(param_1 + 2);
  uVar2 = *(ushort *)((int)param_1 + 10);
  uVar8 = (uint)*(ushort *)(param_1 + 1);
  uVar9 = (uint)uVar1;
  uVar6 = (uint)uVar2;
  local_24 = param_2;
  if (*(char *)((int)param_1 + 7) < '\0') {
    if (param_3 < uVar8) {
      sVar3 = -uVar2;
      if (uVar9 < uVar6) {
        sVar3 = (short)(uVar8 * 2) - uVar2;
      }
      if ((int)(uVar8 * 2) <= (int)((ushort)(uVar1 + sVar3) + param_3)) {
        uVar9 = FUN_1001a360(uVar8,uVar6,uVar8 - param_3 & 0xffff);
      }
    }
    else {
      if (uVar8 == 0) goto LAB_1001a6e0;
      local_24 = param_2 + (param_3 - uVar8) * (*(ushort *)((int)param_1 + 6) & 0x7fff);
      param_3 = uVar8;
      uVar9 = uVar6;
    }
  }
  else {
    if (uVar9 < uVar6) {
      sVar3 = *(ushort *)(param_1 + 1) * 2 - uVar2;
    }
    else {
      sVar3 = -uVar2;
    }
    if (uVar8 <= (ushort)(uVar1 + sVar3)) {
      uVar8 = 0;
      goto LAB_1001a6e0;
    }
    uVar6 = uVar8 - (ushort)(uVar1 + sVar3);
    if (param_3 < (uVar6 & 0xffff)) {
      uVar6 = param_3;
    }
    param_3 = uVar6 & 0xffff;
  }
  for (local_28 = uVar9; uVar8 <= local_28; local_28 = local_28 - uVar8 & 0xffff) {
  }
  uVar6 = *(ushort *)((int)param_1 + 6) & 0x7fff;
  uVar7 = uVar8 - local_28 & 0xffff;
  iVar5 = *param_1 + uVar6 * local_28;
  if (uVar7 < param_3) {
    uVar7 = uVar6 * uVar7 & 0xffff;
    FUN_1001f4d4(iVar5,local_24,uVar7);
    iVar5 = *param_1;
    uVar6 = uVar6 * (local_28 + (param_3 - uVar8)) & 0xffff;
    local_24 = local_24 + uVar7;
  }
  else {
    uVar6 = param_3 * uVar6;
  }
  FUN_1001f4d4(iVar5,local_24,uVar6);
  uVar4 = FUN_1001a360((short)param_1[1],uVar9,param_3);
  *(undefined2 *)(param_1 + 2) = uVar4;
  uVar8 = param_3;
LAB_1001a6e0:
  if (param_1[3] != 0) {
    FUN_10027618();
  }
  return uVar8;
}



/* FUN_1001a770 at 1001a770 */

undefined4 FUN_1001a770(int param_1)

{
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_100276a8(*(int *)(param_1 + 0xc),0xffffffff);
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_100276a8(*(int *)(param_1 + 0x10),0xffffffff);
  }
  *(undefined2 *)(param_1 + 10) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_10027618();
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_10027618();
  }
  return 1;
}



/* FUN_1001a7ae at 1001a7ae */

undefined4 FUN_1001a7ae(int param_1,char param_2)

{
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_100276a8(*(int *)(param_1 + 0xc),0xffffffff);
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_100276a8(*(int *)(param_1 + 0x10),0xffffffff);
  }
  *(byte *)(param_1 + 7) = *(byte *)(param_1 + 7) & 0x7f | param_2 << 7;
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_10027618();
  }
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_10027618();
  }
  return 1;
}



/* FUN_1001a7f4 at 1001a7f4 */

undefined4 * FUN_1001a7f4(undefined4 *param_1)

{
  bool bVar1;
  uint uVar2;
  
  uVar2 = param_1[1];
  DataMemoryBarrier(0x1f);
  *(undefined4 *)*param_1 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar2 & 1) == 1);
  }
  return param_1 + 2;
}



/* FUN_1001a804 at 1001a804 */

void FUN_1001a804(undefined4 *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*(int *)*param_1 == 0);
  DataMemoryBarrier(0x1f);
  param_1[1] = uVar2;
  return;
}



/* FUN_1001a81a at 1001a81a */

void FUN_1001a81a(undefined4 param_1,int param_2,undefined4 param_3)

{
  FUN_1001b250(*(undefined4 *)(param_2 + 0x14));
  (**(code **)(param_2 + 0x14))(param_1,1,param_3);
  return;
}



/* FUN_1001a834 at 1001a834 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001a834(undefined4 param_1)

{
  uint uVar1;
  undefined *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar1 = (uint)DAT_20003b2d;
    if (uVar1 + 5 < uVar3) {
      FUN_1001f4c8(&DAT_20003b30,0,0x54);
      FUN_1001f4c8(0x20003b34,0xff,0x10);
      FUN_1001f4c8(0x20003b44,0xff,0x20);
      return;
    }
    if (uVar3 < uVar1) {
      puVar2 = (undefined *)(_DAT_20001770 + uVar3 * 0x20);
      if (puVar2 == (undefined *)0x0) {
        return;
      }
    }
    else {
      puVar2 = &DAT_1002ab08 + (uVar3 - uVar1) * 0x20;
    }
    (**(code **)(puVar2 + 0xc))(param_1);
    uVar3 = uVar3 + 1 & 0xff;
  } while( true );
}



/* FUN_1001a8b8 at 1001a8b8 */

bool FUN_1001a8b8(void)

{
  return DAT_20003b31 != '\0';
}



/* FUN_1001a8c8 at 1001a8c8 */

uint FUN_1001a8c8(void)

{
  return (DAT_20003b30 & 7) >> 2;
}



/* FUN_1001a8d8 at 1001a8d8 */

/* WARNING: Removing unreachable block (ram,0x1001a926) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1001a8d8(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  undefined4 uVar6;
  byte *pbVar7;
  
  uVar6 = param_1;
  if (DAT_2000094c == -1) {
    if (param_2 != 0) {
      FUN_1001f4c8(&DAT_20003b30,0,0x54,0xff,param_1,param_2,param_3);
      DAT_20003c44 = 0;
      FUN_1001d27c(0x200023c8);
      _DAT_20002410 = 0x200023c8;
      FUN_1001d2f0(0x20000944);
      FUN_1001a770(0x20000930);
      _DAT_20002414 = 0x20000930;
      pbVar7 = &DAT_20003b2d;
      for (uVar5 = 0; uVar3 = (uint)*pbVar7, uVar5 <= uVar3 + 5; uVar5 = uVar5 + 1 & 0xff) {
        if (uVar5 < uVar3) {
          puVar4 = (undefined *)(_DAT_20001770 + uVar5 * 0x20);
          if (puVar4 == (undefined *)0x0) goto LAB_1001a8ea;
        }
        else {
          puVar4 = &DAT_1002ab08 + (uVar5 - uVar3) * 0x20;
        }
        if (*(code **)(puVar4 + 4) == (code *)0x0) goto LAB_1001a8ea;
        (**(code **)(puVar4 + 4))();
      }
      DAT_2000094c = (char)param_1;
      iVar2 = FUN_1001ba24(param_1,param_2);
      if (iVar2 != 0) {
        FUN_1001baac(param_1);
        goto LAB_1001a950;
      }
    }
LAB_1001a8ea:
    uVar1 = 0;
  }
  else {
LAB_1001a950:
    uVar1 = 1;
  }
  return CONCAT44(uVar6,uVar1);
}



/* FUN_1001a9ac at 1001a9ac */

undefined4 FUN_1001a9ac(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = DAT_2000094c;
  if (((*(byte *)(param_2 + 2) & 0x70) == 0) &&
     (iVar2 = FUN_1001bf68(param_2,DAT_20003b32), iVar2 != 0)) {
    uVar3 = FUN_1001bb44(uVar1,param_2);
    return uVar3;
  }
  return 0;
}



/* FUN_1001a9e0 at 1001a9e0 */

undefined8
FUN_1001a9e0(undefined4 param_1,byte *param_2,int param_3,uint param_4,byte *param_5,byte *param_6)

{
  undefined4 uVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    if (param_3 <= iVar4) {
      uVar1 = 1;
LAB_1001a9fc:
      return CONCAT44(param_1,uVar1);
    }
    if (((param_2[1] != 5) || ((param_2[3] & 3) != param_4)) ||
       (iVar2 = FUN_1001a9ac(param_1,param_2), iVar2 == 0)) {
      uVar1 = 0;
      goto LAB_1001a9fc;
    }
    if ((char)param_2[2] < '\0') {
      pbVar3 = param_6;
    }
    else {
      pbVar3 = param_5;
    }
    *pbVar3 = param_2[2];
    iVar4 = iVar4 + 1;
    param_2 = param_2 + *param_2;
  } while( true );
}



/* FUN_1001aa2c at 1001aa2c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001aa2c(undefined4 param_1,uint param_2)

{
  FUN_1001bee0((param_2 & 0x7f) * 2 + (param_2 >> 7) + 0x20003b64,_DAT_20002410);
  return;
}



/* FUN_1001aa50 at 1001aa50 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001aa50(undefined4 param_1,uint param_2)

{
  FUN_1001bf30((param_2 & 0x7f) * 2 + (param_2 >> 7) + 0x20003b64,_DAT_20002410);
  return;
}



/* FUN_1001aa74 at 1001aa74 */

int FUN_1001aa74(undefined4 param_1,uint param_2)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = DAT_2000094c;
  iVar3 = (param_2 & 0x7f) * 2 + (param_2 >> 7);
  if (-1 < (int)((uint)*(byte *)(iVar3 + 0x20003b64) << 0x1f)) {
    *(byte *)(iVar3 + 0x20003b64) = *(byte *)(iVar3 + 0x20003b64) | 1;
    iVar2 = FUN_1001bb8c(uVar1);
    if (iVar2 != 0) {
      return iVar2;
    }
    *(byte *)(iVar3 + 0x20003b64) = *(byte *)(iVar3 + 0x20003b64) & 0xfe;
    *(byte *)(iVar3 + 0x20003b64) = *(byte *)(iVar3 + 0x20003b64) & 0xfb;
  }
  return 0;
}



/* FUN_1001aabc at 1001aabc */

byte FUN_1001aabc(undefined4 param_1,uint param_2)

{
  return *(byte *)((param_2 & 0x7f) * 2 + (param_2 >> 7) + 0x20003b64) & 1;
}



/* FUN_1001aad8 at 1001aad8 */

void FUN_1001aad8(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  FUN_1001bbd0(DAT_2000094c);
  iVar1 = (param_2 & 0x7f) * 2 + (param_2 >> 7);
  *(byte *)(iVar1 + 0x20003b64) = *(byte *)(iVar1 + 0x20003b64) | 2;
  *(byte *)(iVar1 + 0x20003b64) = *(byte *)(iVar1 + 0x20003b64) | 1;
  return;
}



/* FUN_1001ab10 at 1001ab10 */

void FUN_1001ab10(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  FUN_1001bc08(DAT_2000094c);
  iVar1 = (param_2 & 0x7f) * 2 + (param_2 >> 7);
  *(byte *)(iVar1 + 0x20003b64) = *(byte *)(iVar1 + 0x20003b64) & 0xfd;
  *(byte *)(iVar1 + 0x20003b64) = *(byte *)(iVar1 + 0x20003b64) & 0xfe;
  return;
}



/* FUN_1001ab48 at 1001ab48 */

uint FUN_1001ab48(undefined4 param_1,uint param_2)

{
  return (*(byte *)((param_2 & 0x7f) * 2 + (param_2 >> 7) + 0x20003b64) & 3) >> 1;
}



/* FUN_1001ab64 at 1001ab64 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ab64(void)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 uStack_24;
  byte local_23;
  
  if (DAT_2000094c != -1) {
    while( true ) {
      iVar1 = _DAT_20002414;
      iVar3 = _DAT_20002414 + 0x14;
      FUN_1001a804(iVar3);
      iVar1 = FUN_1001a540(iVar1,&uStack_24);
      FUN_1001a7f4(iVar3);
      if (iVar1 == 0) break;
      if (local_23 - 1 < 8) {
        FUN_10027658();
        puVar2 = (undefined1 *)((int)&uStack_24 * 0x80000);
        FUN_1001a834(*puVar2,(int)&uStack_24 * 0x100000,(int)&uStack_24 * 0x400,0);
        FUN_1001b23c();
        DAT_20003b32 = puVar2[4];
      }
    }
  }
  return;
}



/* FUN_1001b11c at 1001b11c */

void FUN_1001b11c(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  FUN_1001bc34(DAT_2000094c);
  iVar1 = (param_2 & 0x7f) * 2 + (param_2 >> 7);
  *(byte *)(iVar1 + 0x20003b64) = *(byte *)(iVar1 + 0x20003b64) & 0xfd;
  *(byte *)(iVar1 + 0x20003b64) = *(byte *)(iVar1 + 0x20003b64) & 0xfe;
  *(byte *)(iVar1 + 0x20003b64) = *(byte *)(iVar1 + 0x20003b64) & 0xfb;
  return;
}



/* FUN_1001b15c at 1001b15c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b15c(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  ushort uVar3;
  
  uVar3 = _DAT_20001d10 - _DAT_20001d12;
  if (0x40 < uVar3) {
    uVar3 = 0x40;
  }
  if (DAT_20001d04 < 0x80) {
    uVar1 = 0;
    uVar2 = 0;
    if (_DAT_20001d10 != _DAT_20001d12) {
      uVar2 = 0x200023d0;
    }
  }
  else if (_DAT_20001d10 == _DAT_20001d12) {
    uVar1 = 0x80;
    uVar2 = 0;
  }
  else {
    FUN_1001f4d4(0x200023d0,_DAT_20001d0c,uVar3);
    uVar1 = 0x80;
    uVar2 = 0x200023d0;
  }
  FUN_1001aa74(param_1,uVar1,uVar2,uVar3);
  return;
}



/* FUN_1001b1b4 at 1001b1b4 */

void FUN_1001b1b4(undefined4 param_1,uint param_2)

{
  FUN_1001aa74(param_1,~param_2 & 0x80,0);
  return;
}



/* FUN_1001b1c8 at 1001b1c8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b1c8(undefined4 param_1,undefined1 *param_2)

{
  FUN_1001f4d4(&DAT_20001d04,param_2,8);
  _DAT_20001d0c = 0;
  _DAT_20001d10 = 0;
  FUN_1001b1b4(param_1,*param_2);
  return;
}



/* FUN_1001b1ec at 1001b1ec */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b1ec(undefined4 param_1,undefined1 *param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  FUN_1001f4d4(&DAT_20001d04,param_2,8,param_4,param_1,param_1,param_3);
  _DAT_20001d12 = 0;
  uVar2 = (uint)*(ushort *)(param_2 + 6);
  uVar1 = uVar2;
  if (param_4 < uVar2) {
    uVar1 = param_4;
  }
  _DAT_20001d10 = (undefined2)uVar1;
  _DAT_20001d0c = param_3;
  if (uVar2 == 0) {
    FUN_1001b1b4(param_1,*param_2);
  }
  else if (((uVar1 & 0xffff) == 0) || (param_3 != 0)) {
    FUN_1001b15c(param_1);
  }
  return;
}



/* FUN_1001b23c at 1001b23c */

void FUN_1001b23c(void)

{
  FUN_1001f4c8(&DAT_20001d04,0,0x14);
  return;
}



/* FUN_1001b250 at 1001b250 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b250(undefined4 param_1)

{
  _DAT_20001d14 = param_1;
  return;
}



/* FUN_1001b25c at 1001b25c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b25c(undefined4 param_1)

{
  FUN_1001f4d4(&DAT_20001d04,param_1,8);
  _DAT_20001d0c = 0;
  _DAT_20001d10 = 0;
  return;
}



/* FUN_1001b278 at 1001b278 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001b278(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  if ((uint)(DAT_20001d04 >> 7) == param_2 >> 7) {
    if (DAT_20001d04 < 0x80) {
      if (_DAT_20001d0c == 0) {
        return 0;
      }
      FUN_1001f4d4(_DAT_20001d0c,0x200023d0,param_4);
    }
    uVar3 = (uint)_DAT_20001d12;
    _DAT_20001d0c = _DAT_20001d0c + param_4;
    _DAT_20001d12 = (ushort)(uVar3 + param_4);
    if (((uint)_DAT_20001d0a != (uVar3 + param_4 & 0xffff)) && (0x3f < param_4)) {
      uVar1 = FUN_1001b15c(param_1);
      return uVar1;
    }
    if ((_DAT_20001d14 == (code *)0x0) ||
       (iVar2 = (*_DAT_20001d14)(param_1,2,&DAT_20001d04), iVar2 != 0)) {
      uVar1 = FUN_1001b1b4(param_1,DAT_20001d04);
      return uVar1;
    }
    FUN_1001bbd0(param_1);
    FUN_1001bbd0(param_1,0x80);
  }
  else {
    if (param_4 != 0) {
      return 0;
    }
    FUN_1001bb2c(param_1,&DAT_20001d04);
    if (_DAT_20001d14 != (code *)0x0) {
      (*_DAT_20001d14)(param_1,3,&DAT_20001d04);
    }
  }
  return 1;
}



/* FUN_1001b310 at 1001b310 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_1001b310(int param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  if ((param_1 - 1U & 0xff) < 5) {
    iVar3 = (param_1 - 1U) * 0x56;
    bVar1 = *(byte *)(iVar3 + 0x20002f94);
    uVar2 = bVar1 & 1;
    if ((bVar1 & 1) != 0) {
      uVar2 = FUN_1001bee0((param_2 & 0x7f) * 2 + (param_2 >> 7) + iVar3 + 0x20002fc5,_DAT_20002418)
      ;
    }
  }
  return uVar2;
}



/* FUN_1001b350 at 1001b350 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_1001b350(int param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  if ((param_1 - 1U & 0xff) < 5) {
    iVar3 = (param_1 - 1U) * 0x56;
    bVar1 = *(byte *)(iVar3 + 0x20002f94);
    uVar2 = bVar1 & 1;
    if ((bVar1 & 1) != 0) {
      uVar2 = FUN_1001bf30((param_2 & 0x7f) * 2 + (param_2 >> 7) + iVar3 + 0x20002fc5,_DAT_20002418)
      ;
    }
  }
  return uVar2;
}



/* FUN_1001b390 at 1001b390 */

int FUN_1001b390(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 - 1U & 0xff) < 5) {
    iVar1 = (param_1 - 1U) * 0x56;
    iVar2 = (param_2 & 0x7f) * 2 + iVar1 + (param_2 >> 7);
    if (-1 < (int)((uint)*(byte *)(iVar2 + 0x20002fc5) << 0x1f)) {
      *(byte *)(iVar2 + 0x20002fc5) = *(byte *)(iVar2 + 0x20002fc5) | 1;
      iVar1 = FUN_1001b698(*(undefined1 *)(iVar1 + 0x20002f90),param_1,param_2,param_3,param_4);
      if (iVar1 != 0) {
        return iVar1;
      }
      *(byte *)(iVar2 + 0x20002fc5) = *(byte *)(iVar2 + 0x20002fc5) & 0xfe;
      *(byte *)(iVar2 + 0x20002fc5) = *(byte *)(iVar2 + 0x20002fc5) & 0xfb;
    }
  }
  return 0;
}



/* FUN_1001b3f0 at 1001b3f0 */

undefined8 FUN_1001b3f0(uint param_1,uint param_2,uint param_3)

{
  int iVar1;
  byte *pbVar2;
  
  iVar1 = 1;
  pbVar2 = &DAT_20001d44;
  do {
    if (((*pbVar2 == param_1) && (((byte)(&DAT_20001d39)[iVar1 * 0xc] & 0xf) == param_2)) &&
       ((param_2 == 0 || (((byte)(&DAT_20001d39)[iVar1 * 0xc] & 0x3f) >> 5 == (param_3 ^ 1)))))
    goto LAB_1001b434;
    iVar1 = iVar1 + 1;
    pbVar2 = pbVar2 + 0xc;
  } while (iVar1 != 0x14);
  pbVar2 = (byte *)0x0;
LAB_1001b434:
  return CONCAT44(param_1,pbVar2);
}



/* FUN_1001b440 at 1001b440 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b440(undefined4 param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_100276a8(_DAT_20001d34,0xffffffff);
    FUN_1001757c(param_1,0);
  }
  FUN_1001751c(param_1,1);
  return;
}



/* FUN_1001b46c at 1001b46c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b46c(undefined4 param_1,int param_2)

{
  FUN_1001751c(param_1,0);
  if (param_2 == 0) {
    FUN_1001757c(param_1,1);
    FUN_10027618(_DAT_20001d34);
  }
  return;
}



/* FUN_1001b494 at 1001b494 */

void FUN_1001b494(undefined4 param_1,byte param_2,undefined4 param_3,undefined4 param_4,
                 undefined1 param_5)

{
  byte local_21 [8];
  undefined1 local_19 [5];
  
  local_21[0] = param_2 | 2;
  FUN_1001b440(param_1,param_5);
  FUN_10017560(param_1,local_21,local_19,1);
  DAT_20001d1b = local_19[0];
  FUN_10017560(param_1,param_3,0,param_4);
  FUN_1001b46c(param_1,param_5);
  return;
}



/* FUN_1001b4e8 at 1001b4e8 */

undefined4 FUN_1001b4e8(undefined4 param_1,byte param_2,undefined1 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  byte local_20;
  undefined1 local_1f;
  undefined2 local_1c [4];
  
  local_20 = param_2 | 2;
  local_1c[0] = 0;
  local_1f = param_3;
  FUN_1001b440(param_1,param_4);
  uVar1 = FUN_10017560(param_1,&local_20,local_1c,2);
  FUN_1001b46c(param_1,param_4);
  DAT_20001d1b = (undefined1)local_1c[0];
  return uVar1;
}



/* FUN_1001b52c at 1001b52c */

undefined8 FUN_1001b52c(undefined4 param_1,char *param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  char *pcVar3;
  undefined4 uVar4;
  
  cVar1 = *param_2;
  pcVar3 = param_2;
  uVar4 = param_3;
  if (DAT_20001d1e != cVar1) {
    DAT_20001d1e = cVar1;
    FUN_1001b4e8(param_1,0xe0,cVar1,param_3,param_1,param_2,param_3);
  }
  uVar2 = param_3;
  FUN_1001b494(param_1,0x20,*(undefined4 *)(param_2 + 8),8);
  DAT_20001d1f = 0x10;
  FUN_1001b4e8(param_1,0xf0,0x10,param_3,uVar2,pcVar3,uVar4);
  return CONCAT44(pcVar3,uVar2);
}



/* FUN_1001b56c at 1001b56c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b56c(undefined4 param_1,short *param_2,int param_3,undefined4 param_4)

{
  char cVar1;
  undefined4 uVar2;
  ushort uVar4;
  ushort uVar3;
  
  if (param_3 != 0) {
    cVar1 = (char)*param_2;
    if (DAT_20001d1e != cVar1) {
      DAT_20001d1e = cVar1;
      FUN_1001b4e8(param_1,0xe0,cVar1,param_4);
    }
    uVar2 = 0x40;
    if ((int)((uint)*(byte *)(param_2 + 1) << 0x1b) < 0) {
      uVar2 = 0x80;
    }
    FUN_1001b4e8(param_1,0xe8,uVar2,param_4);
  }
  if (*param_2 != _DAT_20001d20) {
    uVar3 = param_2[2] - param_2[3];
    if ((ushort)((ushort)param_2[1] >> 5) < (ushort)(param_2[2] - param_2[3])) {
      uVar3 = (ushort)param_2[1] >> 5;
    }
    uVar4 = uVar3 & 0xff;
    if (uVar4 != 0) {
      FUN_1001b494(param_1,0x10,*(undefined4 *)(param_2 + 4),uVar4,param_4);
    }
    DAT_20001d1a = (undefined1)uVar3;
    FUN_1001b4e8(param_1,0x38,uVar4,param_4);
  }
  DAT_20001d1f = *(char *)((int)param_2 + 1);
  _DAT_20001d20 = *param_2;
  FUN_1001b4e8(param_1,0xf0,DAT_20001d1f,param_4);
  return;
}



/* FUN_1001b5fc at 1001b5fc */

void FUN_1001b5fc(undefined4 param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = (uint)(byte)param_2[1];
  if ((param_2[1] & 0xfU) == 0) {
    if ((int)(uVar2 << 0x1b) < 0) {
      FUN_1001b52c(param_1,param_2);
      return;
    }
    if ((*(int *)(param_2 + 8) == 0) || (*(short *)(param_2 + 4) == 0)) {
      cVar1 = *param_2;
      uVar2 = uVar2 & 0x20 | 0x80;
      if (DAT_20001d1e != cVar1) {
        DAT_20001d1e = cVar1;
        FUN_1001b4e8(param_1,0xe0,cVar1,param_3,param_4);
      }
      DAT_20001d1f = (byte)uVar2;
      goto LAB_1001b646;
    }
  }
  if ((int)(uVar2 << 0x1a) < 0) {
    FUN_1001b56c(param_1,param_2,1,param_3);
    return;
  }
  cVar1 = *param_2;
  if (DAT_20001d1e != cVar1) {
    DAT_20001d1e = cVar1;
    FUN_1001b4e8(param_1,0xe0,cVar1,param_3,param_4);
  }
  uVar3 = 0x10;
  if ((param_2[2] & 0x10U) != 0) {
    uVar3 = 0x20;
  }
  FUN_1001b4e8(param_1,0xe8,uVar3,param_3,param_4);
  DAT_20001d1f = param_2[1];
  uVar2 = (uint)DAT_20001d1f;
LAB_1001b646:
  FUN_1001b4e8(param_1,0xf0,uVar2,param_3,param_4);
  return;
}



/* FUN_1001b698 at 1001b698 */

undefined8
FUN_1001b698(undefined4 param_1,int param_2,uint param_3,undefined4 param_4,undefined2 param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = param_3 & 0x7f;
  if (param_2 == 0 && uVar4 == 0) {
    iVar1 = 0x20001d38;
LAB_1001b6c0:
    *(byte *)(iVar1 + 1) = (byte)((param_3 >> 7 ^ 1) << 5) | *(byte *)(iVar1 + 1) & 0xcf;
    *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) | 0x10;
  }
  else {
    iVar1 = FUN_1001b3f0(param_2,uVar4,param_3 >> 7);
    uVar3 = 0;
    if (iVar1 == 0) goto LAB_1001b6fa;
    if (uVar4 == 0) goto LAB_1001b6c0;
  }
  *(undefined4 *)(iVar1 + 8) = param_4;
  *(undefined2 *)(iVar1 + 4) = param_5;
  *(undefined2 *)(iVar1 + 6) = 0;
  *(byte *)(iVar1 + 2) = *(byte *)(iVar1 + 2) & 0xf0 | 3;
  iVar2 = FUN_100276c8(0x20001d24);
  if (iVar2 != 0) {
    FUN_1001b5fc(param_1,iVar1,0);
  }
  uVar3 = 1;
LAB_1001b6fa:
  return CONCAT44(param_1,uVar3);
}



/* FUN_1001b714 at 1001b714 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b714(uint param_1,short param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = param_1 & 0x7f;
  uVar4 = param_1 >> 7;
  iVar5 = uVar2 * 2;
  iVar6 = (iVar5 + uVar4) * 0x20;
  *(char *)(iVar6 + 0x2000281e) = (char)param_1;
  *(byte *)(iVar6 + 0x2000281d) = ~(byte)uVar4 & 1;
  (&DAT_2000281f)[iVar6] = 0;
  *(short *)(iVar6 + 0x20002834) = param_2;
  *(char *)(iVar6 + 0x20002837) = (char)param_3;
  if (uVar4 == 1) {
    *(uint *)(uVar2 * 0x40 + 0x20002844) = uVar2 * 8 + 0x50100080;
  }
  else {
    *(uint *)(uVar2 * 0x40 + 0x20002824) = uVar2 * 8 + 0x50100084;
  }
  **(undefined4 **)((iVar5 + uVar4) * 0x20 + 0x20002824) = 0;
  if (uVar2 == 0) {
    *(undefined4 *)(uVar4 * 0x20 + 0x20002820) = 0;
    *(undefined4 *)(uVar4 * 0x20 + 0x20002828) = 0x50100100;
    return;
  }
  iVar6 = (uVar2 - 1) * 8;
  if (uVar4 == 1) {
    *(int *)(uVar2 * 0x40 + 0x20002840) = iVar6 + 0x50100008;
  }
  else {
    *(int *)(uVar2 * 0x40 + 0x20002820) = iVar6 + 0x5010000c;
  }
  uVar2 = (ushort)(param_2 + 0x3f) & 0xffffffc0;
  if (param_3 == 2) {
    uVar2 = uVar2 << 1;
  }
  iVar5 = (iVar5 + uVar4) * 0x20;
  uVar2 = _DAT_20002d00 + uVar2;
  *(uint *)(iVar5 + 0x20002828) = _DAT_20002d00;
  if ((uVar2 & 0x3f) == 0) {
    uVar4 = _DAT_20002d00 ^ 0x50100000;
    if ((uVar2 ^ 0x50100000) < 0x1001) {
      _DAT_20002d00 = uVar2;
      **(uint **)(iVar5 + 0x20002820) = param_3 << 0x1a | uVar4 | 0x80000000;
      return;
    }
    uVar1 = 0x53;
    pcVar3 = "hw_data_offset(next_buffer_ptr) <= USB_DPRAM_MAX";
  }
  else {
    uVar1 = 0x51;
    pcVar3 = "((uintptr_t) next_buffer_ptr & 0b111111u) == 0";
  }
  _DAT_20002d00 = uVar2;
                    /* WARNING: Subroutine does not return */
  FUN_1001fbec("/Users/mateszabo/Documents/Arduino/libraries/Adafruit_TinyUSB_Library/src/portable/raspberrypi/rp2040/dcd_rp2040.c"
               ,uVar1,"_hw_endpoint_alloc",pcVar3,param_4);
}



/* FUN_1001b810 at 1001b810 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001b810(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 8;
    iVar2 = iVar2 + 1;
    *(undefined4 *)(iVar1 + 0x50100008) = 0;
    *(undefined4 *)(iVar1 + 0x5010000c) = 0;
  } while (iVar2 != 0xf);
  FUN_1001f4c8(0x2000285c,0,0x3c0);
  _DAT_20002d00 = 0x50100180;
  return;
}



/* FUN_1001ba24 at 1001ba24 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001ba24(int param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1001fbec("/Users/mateszabo/Documents/Arduino/libraries/Adafruit_TinyUSB_Library/src/portable/raspberrypi/rp2040/dcd_rp2040.c"
                 ,0x176,"dcd_init","rhport == 0");
  }
  FUN_1001bd70();
  _DAT_50110078 = 0xc;
  FUN_1001d008(5,&LAB_1001b84c_1,0xff);
  FUN_1001f4c8(0x2000281c,0,0x40);
  FUN_1001b714(0,0x40,0);
  FUN_1001b714(0x80,0x40,0);
  FUN_1001b810();
  _DAT_50110040 = 1;
  _DAT_5011004c = 0x20000000;
  _DAT_50110090 = 0x1d010;
  _DAT_5011204c = 0x10000;
  return;
}



/* FUN_1001baac at 1001baac */

void FUN_1001baac(int param_1)

{
  if (param_1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1001fbec("/Users/mateszabo/Documents/Arduino/libraries/Adafruit_TinyUSB_Library/src/portable/raspberrypi/rp2040/dcd_rp2040.c"
                 ,0x1aa,"dcd_int_enable","rhport == 0");
  }
  FUN_1001cf68(5,1);
  return;
}



/* FUN_1001bb2c at 1001bb2c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001bb2c(undefined4 param_1,byte *param_2)

{
  if (((*param_2 & 0x7f) == 0) && (param_2[1] == 5)) {
    _DAT_50110000 = (uint)param_2[2];
  }
  return;
}



/* FUN_1001bb44 at 1001bb44 */

undefined4 FUN_1001bb44(int param_1,int param_2)

{
  if (param_1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1001fbec("/Users/mateszabo/Documents/Arduino/libraries/Adafruit_TinyUSB_Library/src/portable/raspberrypi/rp2040/dcd_rp2040.c"
                 ,0x1f1,"dcd_edpt_open","rhport == 0");
  }
  FUN_1001b714(*(undefined1 *)(param_2 + 2),*(ushort *)(param_2 + 4) & 0x7ff,
               *(byte *)(param_2 + 3) & 3);
  return 1;
}



/* FUN_1001bb8c at 1001bb8c */

undefined4 FUN_1001bb8c(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1001fbec("/Users/mateszabo/Documents/Arduino/libraries/Adafruit_TinyUSB_Library/src/portable/raspberrypi/rp2040/dcd_rp2040.c"
                 ,0x1fe,"dcd_edpt_xfer","rhport == 0");
  }
  FUN_1001be84(((param_2 & 0x7f) * 2 + (param_2 >> 7)) * 0x20 + 0x2000281c,param_3,param_4);
  return 1;
}



/* FUN_1001bbd0 at 1001bbd0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1001bbd0(undefined4 param_1,uint param_2)

{
  if ((param_2 & 0x7f) == 0) {
    _DAT_50112068 = (param_2 == 0) + 1;
  }
  FUN_1001bdbc(((param_2 & 0x7f) * 2 + (param_2 >> 7)) * 0x20 + 0x2000281c,0,0x800);
  return CONCAT44(param_2,param_1);
}



/* FUN_1001bc08 at 1001bc08 */

void FUN_1001bc08(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  if ((param_2 & 0x7f) != 0) {
    iVar1 = ((param_2 & 0x7f) * 2 + (param_2 >> 7)) * 0x20;
    (&DAT_2000281f)[iVar1] = 0;
    FUN_1001bdbc(iVar1 + 0x2000281c,0xfffff7ff);
  }
  return;
}



/* FUN_1001bc34 at 1001bc34 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001bc34(undefined4 param_1,uint param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar1 = ((param_2 & 0x7f) * 2 + (param_2 >> 7)) * 0x20;
  iVar3 = 0x2000281c;
  **(undefined4 **)(iVar1 + 0x20002820) = 0;
  **(undefined4 **)(iVar1 + 0x20002824) = 0;
  FUN_1001f4c8(iVar1 + 0x2000281c,0,0x20);
  cVar2 = '\x01';
  while( true ) {
    if (*(int *)(iVar3 + 0x4c) != 0) {
      return;
    }
    if (*(int *)(iVar3 + 0x6c) != 0) break;
    cVar2 = cVar2 + '\x01';
    iVar3 = iVar3 + 0x40;
    if (cVar2 == '\x10') {
      _DAT_20002d00 = 0x50100180;
      return;
    }
  }
  return;
}



/* FUN_1001bc84 at 1001bc84 */

uint FUN_1001bc84(int param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar1 = *(ushort *)(param_1 + 0x14);
  uVar4 = *(ushort *)(param_1 + 0x18);
  if (uVar1 < *(ushort *)(param_1 + 0x18)) {
    uVar4 = uVar1;
  }
  uVar5 = (uint)uVar4;
  *(ushort *)(param_1 + 0x14) = uVar1 - uVar4;
  uVar2 = (uint)(*(byte *)(param_1 + 3) != 0) * 0x2000 | uVar5 | 0x400;
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) ^ 1;
  if (*(char *)(param_1 + 1) == '\0') {
    iVar6 = *(int *)(param_1 + 0xc);
    iVar7 = *(int *)(param_1 + 0x10);
    for (uVar3 = 0; uVar5 != uVar3; uVar3 = uVar3 + 1) {
      *(undefined1 *)(iVar6 + param_2 * 0x40 + uVar3) = *(undefined1 *)(iVar7 + uVar3);
    }
    *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar5;
    uVar2 = uVar2 | 0x8000;
  }
  if (*(short *)(param_1 + 0x14) == 0) {
    uVar2 = uVar2 | 0x4000;
  }
  if (param_2 != 0) {
    uVar2 = uVar2 << 0x10;
  }
  return uVar2;
}



/* FUN_1001bcec at 1001bcec */

void FUN_1001bcec(int param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  
  uVar3 = **(uint **)(param_1 + 8);
  if (param_2 != 0) {
    uVar3 = uVar3 >> 0x10;
  }
  uVar1 = uVar3 & 0x3ff;
  if (*(char *)(param_1 + 1) == '\0') {
    if ((uVar3 & 0x8000) == 0) {
      *(short *)(param_1 + 0x16) = (short)uVar1 + *(short *)(param_1 + 0x16);
LAB_1001bd20:
      if (uVar1 < *(ushort *)(param_1 + 0x18)) {
        *(undefined2 *)(param_1 + 0x14) = 0;
      }
      return;
    }
    uVar2 = 0xe8;
    pcVar5 = "!(buf_ctrl & USB_BUF_CTRL_FULL)";
  }
  else {
    if ((uVar3 & 0x8000) != 0) {
      iVar4 = *(int *)(param_1 + 0xc);
      iVar6 = *(int *)(param_1 + 0x10);
      for (uVar3 = 0; uVar1 != uVar3; uVar3 = uVar3 + 1) {
        *(undefined1 *)(iVar6 + uVar3) = *(undefined1 *)(iVar4 + param_2 * 0x40 + uVar3);
      }
      *(short *)(param_1 + 0x16) = (short)uVar1 + *(short *)(param_1 + 0x16);
      *(uint *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + uVar1;
      goto LAB_1001bd20;
    }
    uVar2 = 0xee;
    pcVar5 = "buf_ctrl & USB_BUF_CTRL_FULL";
  }
                    /* WARNING: Subroutine does not return */
  FUN_1001fbec("/Users/mateszabo/Documents/Arduino/libraries/Adafruit_TinyUSB_Library/src/portable/raspberrypi/rp2040/rp2040_usb.c"
               ,uVar2,"sync_ep_buffer",pcVar5);
}



/* FUN_1001bd70 at 1001bd70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001bd70(void)

{
  _DAT_4000e000 = 0x1000000;
  _DAT_4000f000 = 0x1000000;
  do {
  } while ((~_DAT_4000c008 & 0x1000000) != 0);
  FUN_1001f4c8(&DAT_50100000,0,0x1000);
  _DAT_50110074 = 9;
  return;
}



/* FUN_1001bdb0 at 1001bdb0 */

void FUN_1001bdb0(int param_1)

{
  *(undefined1 *)(param_1 + 0x1a) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



/* FUN_1001bdbc at 1001bdbc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001bdbc(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  bool bVar4;
  
  puVar2 = *(uint **)(param_1 + 8);
  uVar1 = 0;
  if (param_2 != 0) {
    uVar1 = param_2 & *puVar2;
  }
  if ((param_3 != 0) && (uVar1 = uVar1 | param_3, (param_3 & 0x400) != 0)) {
    if ((*puVar2 & 0x400) != 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001ce0c("ep %02X was already available",*(undefined1 *)(param_1 + 2));
    }
    *puVar2 = uVar1 & 0xfffffbff;
    if (-1 < _DAT_50110040 << 0x1e) {
      uVar3 = 0xc;
      do {
        bVar4 = 2 < uVar3;
        uVar3 = uVar3 - 3;
      } while (bVar4);
    }
  }
  **(uint **)(param_1 + 8) = uVar1;
  return;
}



/* FUN_1001be0c at 1001be0c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001be0c(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 *puVar4;
  bool bVar5;
  
  uVar3 = **(uint **)(param_1 + 4);
  uVar1 = FUN_1001bc84(param_1,0);
  uVar1 = uVar1 | 0x1000;
  if (_DAT_50110040 << 0x1e < 0) {
    bVar5 = (*(byte *)(param_1 + 2) & 0x7f) != 0;
  }
  else {
    bVar5 = (bool)(~(*(byte *)(param_1 + 2) >> 7) & 1);
  }
  if ((*(short *)(param_1 + 0x14) == 0) || (bVar5 != false)) {
    puVar4 = (undefined1 *)(uVar3 & 0xafffffff);
    uVar3 = 0x20000000;
  }
  else {
    uVar2 = FUN_1001bc84(param_1,1);
    uVar1 = uVar1 | uVar2;
    uVar3 = uVar3 & 0xdfffffff;
    puVar4 = &DAT_50000000;
  }
  **(uint **)(param_1 + 4) = (uint)puVar4 | uVar3;
  FUN_1001bdbc(param_1,0,uVar1);
  return;
}



/* FUN_1001be84 at 1001be84 */

void FUN_1001be84(int param_1,undefined4 param_2,undefined2 param_3)

{
  *(undefined2 *)(param_1 + 0x16) = 0;
  *(undefined2 *)(param_1 + 0x14) = param_3;
  *(undefined1 *)(param_1 + 0x1a) = 1;
  *(undefined4 *)(param_1 + 0x10) = param_2;
  FUN_1001be0c();
  return;
}



/* FUN_1001be98 at 1001be98 */

char FUN_1001be98(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  char cVar2;
  
  cVar2 = *(char *)(param_1 + 0x1a);
  if (cVar2 == '\0') {
                    /* WARNING: Subroutine does not return */
    FUN_1001ce0c("Can\'t continue xfer on inactive ep %02X",*(undefined1 *)(param_1 + 2));
  }
  uVar1 = FUN_1001bcec(param_1,0,param_3,**(undefined4 **)(param_1 + 8));
  if ((**(int **)(param_1 + 4) << 1 < 0) && (*(ushort *)(param_1 + 0x18) == uVar1)) {
    FUN_1001bcec(param_1,1);
  }
  if (*(short *)(param_1 + 0x14) != 0) {
    FUN_1001be0c(param_1);
    cVar2 = '\0';
  }
  return cVar2;
}



/* FUN_1001bee0 at 1001bee0 */

uint FUN_1001bee0(byte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if ((*param_1 & 1) == 0) {
    iVar1 = (uint)*param_1 * 0x20000000;
    uVar3 = (*param_1 & 7) >> 2;
    uVar2 = *param_1 & 1;
    if (-1 < iVar1) {
      FUN_100276a8(param_2,0xffffffff,param_3,iVar1,param_4);
      if (((*param_1 & 1) == 0) && (uVar3 = *param_1 & 1, -1 < (int)((uint)*param_1 << 0x1d))) {
        uVar3 = 1;
        *param_1 = *param_1 | 4;
      }
      FUN_10027618(param_2);
      uVar2 = uVar3;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* FUN_1001bf30 at 1001bf30 */

uint FUN_1001bf30(byte *param_1,undefined4 param_2)

{
  uint uVar1;
  
  FUN_100276a8(param_2,0xffffffff);
  uVar1 = (*param_1 & 7) >> 2;
  if ((int)((uint)*param_1 * 0x20000000) < 0) {
    if ((int)((uint)*param_1 << 0x1f) < 0) {
      uVar1 = 0;
    }
    else {
      *param_1 = *param_1 & 0xfb;
    }
  }
  FUN_10027618(param_2);
  return uVar1;
}



/* FUN_1001bf68 at 1001bf68 */

bool FUN_1001bf68(int param_1,int param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  
  uVar3 = *(ushort *)(param_1 + 4) & 0x7ff;
  bVar1 = *(byte *)(param_1 + 3) & 3;
  if (bVar1 == 2) {
    if (param_2 == 2) {
      return uVar3 == 0x200;
    }
    uVar2 = 0x40;
  }
  else {
    if (bVar1 != 3) {
      if (bVar1 == 1) {
        return uVar3 <= (ushort)((param_2 == 2) + 0x3ff);
      }
      return false;
    }
    uVar2 = 0x40;
    if (param_2 == 2) {
      uVar2 = 0x400;
    }
  }
  return uVar3 <= uVar2;
}



/* FUN_1001bfee at 1001bfee */

undefined4
FUN_1001bfee(byte *param_1,byte param_2,int param_3,undefined4 param_4,int param_5,short param_6,
            undefined4 param_7,undefined2 param_8)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  
  *param_1 = *param_1 & 0xfe | param_2 & 1;
  FUN_1001a458(param_1 + 8,param_5,param_6,1,param_4);
  if ((param_5 != 0) && (param_6 != 0)) {
    pbVar2 = param_1 + 0x1c;
    FUN_1001d27c(pbVar2);
    pbVar1 = (byte *)0x0;
    pbVar3 = pbVar2;
    if (param_3 != 0) {
      pbVar3 = (byte *)0x0;
      pbVar1 = pbVar2;
    }
    *(byte **)(param_1 + 0x14) = pbVar1;
    *(byte **)(param_1 + 0x18) = pbVar3;
  }
  *(undefined4 *)(param_1 + 4) = param_7;
  *(undefined2 *)(param_1 + 2) = param_8;
  return 1;
}



/* FUN_1001c04e at 1001c04e */

undefined4 FUN_1001c04e(void)

{
  return 1;
}



/* FUN_1001c054 at 1001c054 */

undefined8 FUN_1001c054(undefined4 param_1,byte *param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  byte bVar3;
  undefined4 uVar4;
  byte *pbVar5;
  uint uVar6;
  
  bVar3 = *param_2;
  uVar4 = param_1;
  pbVar5 = param_2;
  uVar6 = param_3;
  iVar1 = FUN_1001a4bc(param_2 + 8);
  if (((iVar1 == 0) && (param_3 != 0)) &&
     ((param_3 & (-(uint)((bVar3 & 2) == 0) & 0xfffffe40) + 0x1ff) == 0)) {
    if ((int)((uint)*param_2 << 0x1f) < 0) {
      iVar1 = FUN_1001b310();
    }
    else {
      iVar1 = FUN_1001aa2c(param_1,param_2[1]);
    }
    if (iVar1 != 0) {
      bVar3 = *param_2 & 1;
      if ((*param_2 & 1) == 0) {
        uVar2 = FUN_1001aa74(param_1,param_2[1],bVar3,bVar3,uVar4,pbVar5,uVar6);
      }
      else {
        uVar4 = 0;
        uVar2 = FUN_1001b390(param_1,param_2[1],0,0,0,0);
      }
      goto LAB_1001c080;
    }
  }
  uVar2 = 0;
LAB_1001c080:
  return CONCAT44(uVar4,uVar2);
}



/* FUN_1001c0d0 at 1001c0d0 */

undefined8 FUN_1001c0d0(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  byte *pbVar5;
  
  uVar4 = param_1;
  pbVar5 = param_2;
  iVar2 = FUN_1001a4bc(param_2 + 8);
  if (iVar2 != 0) {
    if ((int)((uint)*param_2 << 0x1f) < 0) {
      iVar2 = FUN_1001b310();
    }
    else {
      iVar2 = FUN_1001aa2c(param_1,param_2[1]);
    }
    if (iVar2 != 0) {
      iVar2 = FUN_1001a582(param_2 + 8,*(undefined4 *)(param_2 + 4),*(undefined2 *)(param_2 + 2));
      bVar1 = param_2[1];
      if (iVar2 == 0) {
        if ((*param_2 & 1) == 0) {
          FUN_1001aa50(param_1,bVar1);
        }
        else {
          FUN_1001b350();
        }
      }
      else {
        if ((*param_2 & 1) == 0) {
          iVar3 = FUN_1001aa74(param_1,bVar1,*(undefined4 *)(param_2 + 4),iVar2,uVar4,pbVar5);
        }
        else {
          uVar4 = 0;
          iVar3 = FUN_1001b390(param_1,bVar1,*(undefined4 *)(param_2 + 4),iVar2,0,0);
        }
        if (iVar3 != 0) goto LAB_1001c128;
      }
    }
  }
  iVar2 = 0;
LAB_1001c128:
  return CONCAT44(uVar4,iVar2);
}



/* FUN_1001c150 at 1001c150 */

undefined8 FUN_1001c150(undefined4 param_1,byte *param_2,undefined4 param_3)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  undefined4 uVar10;
  byte *pbVar11;
  
  uVar10 = param_1;
  if (*(short *)(param_2 + 0xc) == 0) {
    pbVar11 = param_2;
    if ((int)((uint)*param_2 << 0x1f) < 0) {
      iVar5 = FUN_1001b310();
    }
    else {
      iVar5 = FUN_1001aa2c(param_1,param_2[1]);
    }
    if (iVar5 != 0) {
      sVar3 = *(short *)(param_2 + 2);
      uVar6 = *param_2 & 1;
      if ((*param_2 & 1) == 0) {
        if (sVar3 != 0) {
          uVar6 = *(uint *)(param_2 + 4);
        }
        iVar5 = FUN_1001aa74(param_1,param_2[1],uVar6,sVar3,uVar10,pbVar11,param_3);
      }
      else {
        uVar7 = 0;
        if (sVar3 != 0) {
          uVar7 = *(undefined4 *)(param_2 + 4);
        }
        uVar10 = 0;
        iVar5 = FUN_1001b390(param_1,param_2[1],uVar7,sVar3,0,0);
      }
      if (iVar5 != 0) {
        uVar6 = (uint)*(ushort *)(param_2 + 2);
        goto LAB_1001c198;
      }
    }
  }
  else {
    uVar9 = (-(uint)((*param_2 & 2) == 0) & 0xfffffe40) + 0x200;
    uVar6 = FUN_1001a518(param_2 + 8);
    if (uVar9 <= uVar6) {
      if ((int)((uint)*param_2 << 0x1f) < 0) {
        iVar5 = FUN_1001b310();
      }
      else {
        iVar5 = FUN_1001aa2c(param_1,param_2[1]);
      }
      if (iVar5 != 0) {
        uVar6 = FUN_1001a518(param_2 + 8);
        bVar1 = *param_2;
        bVar2 = param_2[1];
        uVar8 = bVar1 & 1;
        if (uVar6 < uVar9) {
          if ((bVar1 & 1) == 0) {
            FUN_1001aa50(param_1,bVar2);
          }
          else {
            FUN_1001b350();
          }
        }
        else {
          uVar4 = (ushort)(-uVar9 & uVar6);
          if ((uint)*(ushort *)(param_2 + 2) < (-uVar9 & uVar6 & 0xffff)) {
            uVar4 = *(ushort *)(param_2 + 2);
          }
          uVar6 = (uint)uVar4;
          if ((bVar1 & 1) == 0) {
            if (uVar6 != 0) {
              uVar8 = *(uint *)(param_2 + 4);
            }
            iVar5 = FUN_1001aa74(param_1,bVar2,uVar8,uVar6);
          }
          else {
            uVar7 = 0;
            if (uVar6 != 0) {
              uVar7 = *(undefined4 *)(param_2 + 4);
            }
            uVar10 = 0;
            iVar5 = FUN_1001b390(param_1,bVar2,uVar7,uVar6,0,0);
          }
          if (iVar5 != 0) goto LAB_1001c198;
        }
      }
    }
  }
  uVar6 = 0;
LAB_1001c198:
  return CONCAT44(uVar10,uVar6);
}



/* FUN_1001c258 at 1001c258 */

void FUN_1001c258(undefined4 *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (0xfff < param_2 - 1U) {
    param_2 = 0x1000;
  }
  iVar1 = param_1[1];
  uVar2 = param_2 + 0xffU & 0xffffff00;
  if (iVar1 != 0) {
    if (param_1[2] == uVar2) goto LAB_1001c288;
    FUN_1001f904();
  }
  iVar1 = FUN_1001f930(uVar2);
  param_1[1] = iVar1;
LAB_1001c288:
  param_1[2] = uVar2;
  FUN_1001f4d4(iVar1,*param_1,uVar2);
  *(undefined1 *)(param_1 + 3) = 0;
  return;
}



/* FUN_1001c298 at 1001c298 */

undefined1 FUN_1001c298(int param_1,uint param_2)

{
  undefined1 uVar1;
  
  uVar1 = 0;
  if (((-1 < (int)param_2) && (param_2 < *(uint *)(param_1 + 8))) &&
     (uVar1 = 0, *(int *)(param_1 + 4) != 0)) {
    uVar1 = *(undefined1 *)(*(int *)(param_1 + 4) + param_2);
  }
  return uVar1;
}



/* FUN_1001c2b0 at 1001c2b0 */

void FUN_1001c2b0(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  if ((((-1 < (int)param_2) && (param_2 < *(uint *)(param_1 + 8))) &&
      (iVar1 = *(int *)(param_1 + 4), iVar1 != 0)) && (*(byte *)(iVar1 + param_2) != param_3)) {
    *(char *)(iVar1 + param_2) = (char)param_3;
    *(undefined1 *)(param_1 + 0xc) = 1;
  }
  return;
}



/* FUN_1001c2d4 at 1001c2d4 */

undefined8 FUN_1001c2d4(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1[2] == 0) goto LAB_1001c2e6;
  if ((char)param_1[3] != '\0') {
    uVar2 = 0;
    if (param_1[1] == 0) goto LAB_1001c2e6;
    if (DAT_20003b2b == '\0') {
      FUN_1001c954();
    }
    cVar1 = DAT_20003b2b;
    if ((DAT_20001310 != '\0') && (DAT_20003b2b == '\0')) {
      FUN_10027738(0x20001314);
      DAT_20003b2c = cVar1;
      FUN_1001f514(0xc0ded02e);
      do {
      } while (DAT_20003b2c == '\0');
    }
    FUN_10027698(*param_1 + -0x10000000,0x1000);
    FUN_10027648(*param_1 + -0x10000000,param_1[1],param_1[2]);
    if (DAT_20001310 == '\0') {
LAB_1001c36a:
      if (DAT_20003b2b == '\0') goto LAB_1001c344;
    }
    else {
      FUN_10027618(0x20001314);
      DAT_20003b2c = '\0';
      if (DAT_20003b2b != '\0') goto LAB_1001c36a;
LAB_1001c344:
      FUN_1001c910();
    }
    *(undefined1 *)(param_1 + 3) = 0;
  }
  uVar2 = 1;
LAB_1001c2e6:
  return CONCAT44(param_1,uVar2);
}



/* FUN_1001c388 at 1001c388 */

undefined4 FUN_1001c388(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 8) != 0) {
    uVar1 = FUN_1001c2d4();
    if (*(int *)(param_1 + 4) != 0) {
      FUN_1001f904();
    }
    *(undefined4 *)(param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    *(undefined1 *)(param_1 + 0xc) = 0;
  }
  return uVar1;
}



/* FUN_1001c3c8 at 1001c3c8 */

undefined4 FUN_1001c3c8(int param_1)

{
  undefined4 uVar1;
  undefined4 extraout_r1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = FUN_1001fb68();
    FUN_1001e480(uVar1,param_1);
    uVar1 = extraout_r1;
  }
  return uVar1;
}



/* FUN_1001c3de at 1001c3de */

int FUN_1001c3de(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while ((iVar2 != param_3 &&
         (iVar1 = (**(code **)*param_1)(param_1,*(undefined1 *)(param_2 + iVar2)), iVar1 != 0))) {
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}



/* FUN_1001c402 at 1001c402 */

void FUN_1001c402(int param_1)

{
  if (param_1 != 0) {
    FUN_1001d87c();
  }
  return;
}



/* FUN_1001c40e at 1001c40e */

void FUN_1001c40e(int param_1)

{
  if (param_1 != 0) {
    FUN_1001d858(param_1,0);
  }
  return;
}



/* FUN_1001c41c at 1001c41c */

void FUN_1001c41c(void)

{
  FUN_10017b3c();
  FUN_10016eec();
  return;
}



/* FUN_1001c428 at 1001c428 */

void FUN_1001c428(void)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_1001d960();
  iVar1 = (int)((ulonglong)uVar2 >> 0x20);
  if (iVar1 == 0) {
    FUN_1001e4d0((int)uVar2,1000);
  }
  else {
    FUN_1001e54c((int)uVar2,iVar1,1000,0);
  }
  return;
}



/* FUN_1001c464 at 1001c464 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001c464(void)

{
  _DAT_d0000050 = 0xff;
  FUN_1001cfc8(_DAT_d0000000 + 0xf,0x2000023d);
  FUN_1001cf68(_DAT_d0000000 + 0xf,1);
  return;
}



/* FUN_1001c4bc at 1001c4bc */

void FUN_1001c4bc(void)

{
  undefined4 uVar1;
  
  FUN_1001d27c(0x20001314);
  uVar1 = FUN_1001ce3c();
  FUN_1001d984(0x2000131c,4,8,uVar1);
  uVar1 = FUN_1001ce3c();
  FUN_1001d984(0x2000132c,4,8,uVar1);
  DAT_20001310 = 1;
  return;
}



/* FUN_1001c500 at 1001c500 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001c500(undefined4 *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int local_2c [3];
  undefined4 local_20;
  undefined4 local_1c;
  
  *param_1 = 0;
  param_1[1] = 0;
  if (DAT_20003b2b == '\0') {
    FUN_1001dc9c(0xf,&LAB_1001c448_1);
    _DAT_e000e010 = 7;
    _DAT_e000e014 = 0xffffff;
  }
  else {
    local_2c[0] = 0;
    uVar1 = FUN_1001f90c(0xc);
    FUN_1001cace(uVar1,&DAT_1002ac30);
    param_1[0xf] = uVar1;
    FUN_1001cadc(uVar1,param_1 + 0xd,param_1 + 0xe,local_2c,0,1);
    iVar3 = param_1[0xd];
    local_2c[1] = 0x10000;
    local_20 = 0xc0000;
    iVar5 = param_1[0xe];
    local_2c[2] = (local_2c[0] + 1) * 0x1000 | local_2c[0] << 7;
    local_1c = 0;
    FUN_1001e240(iVar3,iVar5,local_2c[0],local_2c + 1);
    uVar2 = param_1[0xe];
    puVar4 = (undefined4 *)(iVar3 + iVar5 * 0x18 + 0xd8);
    *puVar4 = 0xe020;
    *puVar4 = 0xe040;
    *(uint *)param_1[0xd] = 1 << (uVar2 & 0xff) | *(uint *)param_1[0xd];
  }
  return;
}



/* FUN_1001c5bc at 1001c5bc */

void FUN_1001c5bc(void)

{
  return;
}



/* FUN_1001c5c0 at 1001c5c0 */

/* WARNING: Removing unreachable block (ram,0x1001c5d6) */
/* WARNING: Removing unreachable block (ram,0x1001c5cc) */
/* WARNING: Removing unreachable block (ram,0x1001c5e0) */

void FUN_1001c5c0(void)

{
  FUN_1001c41c();
  return;
}



/* FUN_1001c5f4 at 1001c5f4 */

/* WARNING: Removing unreachable block (ram,0x1001c68c) */
/* WARNING: Removing unreachable block (ram,0x1001c63c) */
/* WARNING: Removing unreachable block (ram,0x1001c6ee) */
/* WARNING: Removing unreachable block (ram,0x1001c6aa) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001c5f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_1c = param_2;
  local_18 = param_3;
  local_14 = param_4;
  uVar1 = FUN_1001dc20();
  if (uVar1 < 0xc) {
    FUN_1001dc04(0xc);
    uVar1 = 12000;
    do {
      bVar3 = 2 < uVar1;
      uVar1 = uVar1 - 3;
    } while (bVar3);
  }
  iVar2 = FUN_1001daf0(250000,&local_1c,&local_18,&local_14,param_1);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1001ce0c("System clock of %u kHz cannot be exactly achieved",250000);
  }
  FUN_1001da90(local_1c,local_18,local_14);
  DAT_20003b2b = '\0';
  iVar2 = FUN_1001c7a4(1,0x4c);
  _DAT_20001688 = iVar2;
  FUN_1001f4c8(iVar2,0,0x4c);
  *(undefined1 **)(iVar2 + 4) = &DAT_20001030;
  *(undefined1 **)(iVar2 + 8) = &DAT_200010a0;
  *(undefined1 **)(iVar2 + 0xc) = &DAT_20001110;
  FUN_1001c500(&DAT_20001308);
  FUN_1001c5bc();
  FUN_10016ed8(0);
  if (((DAT_20003b2b != '\0') || (FUN_1001c4bc(), DAT_20003b2b != '\0')) ||
     (FUN_1001c464(), DAT_20003b2b != '\0')) {
    FUN_1001c4bc();
    return 0;
  }
  FUN_1001c402(1);
  if (DAT_20003f81 == '\0') {
    FUN_1001f5c4(&LAB_1001c488_1);
  }
  else {
    _DAT_200027f0 = FUN_1001c78c(0x2000);
    FUN_1001f590(&LAB_1001c488_1,_DAT_200027f0,0x2000);
  }
  FUN_100157b0();
  do {
    FUN_10016d5c();
    FUN_1001c5c0();
  } while( true );
}



/* FUN_1001c744 at 1001c744 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001c744(void)

{
  undefined4 *puVar1;
  
  if (_DAT_d0000000 == 0) {
    puVar1 = (undefined4 *)&DAT_20000e00;
  }
  else {
    puVar1 = (undefined4 *)&DAT_20001688;
  }
  return *puVar1;
}



/* FUN_1001c78c at 1001c78c */

undefined4 FUN_1001c78c(undefined4 param_1)

{
  undefined4 uVar1;
  
  FUN_1001c954();
  uVar1 = FUN_100243bc(param_1);
  FUN_1001c910();
  return uVar1;
}



/* FUN_1001c7a4 at 1001c7a4 */

undefined4 FUN_1001c7a4(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  FUN_1001c954();
  uVar1 = FUN_10021a74(param_1,param_2);
  FUN_1001c910();
  return uVar1;
}



/* FUN_1001c7c0 at 1001c7c0 */

undefined4 FUN_1001c7c0(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  FUN_1001c954();
  uVar1 = FUN_10021e48(param_1,param_2);
  FUN_1001c910();
  return uVar1;
}



/* FUN_1001c7dc at 1001c7dc */

void FUN_1001c7dc(undefined4 param_1)

{
  FUN_1001c954();
  FUN_100243cc(param_1);
  FUN_1001c910();
  return;
}



/* FUN_1001c7f0 at 1001c7f0 */

void FUN_1001c7f0(uint param_1,uint param_2)

{
  if ((param_1 < 0x1e) && (param_2 < 9)) {
                    /* WARNING: Subroutine does not return */
    FUN_10027708(param_2);
  }
  return;
}



/* FUN_1001c8b0 at 1001c8b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001c8b0(uint param_1,int param_2)

{
  int iVar1;
  
  if (0x1d < param_1) {
    return;
  }
  FUN_1001ce74(param_1,5);
  iVar1 = 1 << (param_1 & 0xff);
  if (*(char *)(param_1 + 0x20003b0b) == '\x03') {
    if (param_2 != 0) {
      _DAT_d0000024 = iVar1;
      return;
    }
  }
  else {
    if (*(char *)(param_1 + 0x20003b0b) != '\x02') {
      if (param_2 == 0) {
        _DAT_d0000018 = iVar1;
        return;
      }
      _DAT_d0000014 = iVar1;
      return;
    }
    if (param_2 != 1) {
      _DAT_d0000024 = iVar1;
      return;
    }
  }
  _DAT_d0000028 = iVar1;
  return;
}



/* FUN_1001c8f4 at 1001c8f4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_1001c8f4(uint param_1)

{
  return param_1 < 0x1e && (_DAT_d0000004 & 1 << (param_1 & 0xff)) != 0;
}



/* FUN_1001c910 at 1001c910 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001c910(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = _DAT_d0000000;
  if (DAT_20003b2a == '\0') {
    iVar3 = *(int *)(_DAT_d0000000 * 4 + 0x2000168c);
    if (iVar3 != 0) {
      iVar3 = iVar3 + -1;
      *(int *)(_DAT_d0000000 * 4 + 0x2000168c) = iVar3;
      bVar1 = (bool)isCurrentModePrivileged();
      if (bVar1) {
        enableIRQinterrupts((*(uint *)((iVar2 * 0xf + iVar3) * 4 + 0x200016d4) & 1) == 1);
      }
    }
  }
  return;
}



/* FUN_1001c954 at 1001c954 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001c954(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar2 = _DAT_d0000000;
  if (DAT_20003b2a == '\0') {
    iVar5 = _DAT_d0000000 * 4;
    if (*(int *)(iVar5 + 0x2000168c) == 0xf) {
                    /* WARNING: Subroutine does not return */
      FUN_1001ce0c("IRQ stack overflow");
    }
    uVar4 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      uVar4 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    iVar3 = *(int *)(iVar5 + 0x2000168c);
    *(int *)(iVar5 + 0x2000168c) = iVar3 + 1;
    *(undefined4 *)((iVar2 * 0xf + iVar3) * 4 + 0x200016d4) = uVar4;
  }
  return;
}



/* FUN_1001c9a4 at 1001c9a4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1001c9a4(int *param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int local_14;
  undefined4 uStack_10;
  
  *param_1 = param_2;
  *(undefined1 *)(param_1 + 1) = 0;
  cVar1 = DAT_20003b2b;
  *(char *)((int)param_1 + 5) = (char)param_3;
  param_1[2] = 0;
  local_14 = param_2;
  uStack_10 = param_3;
  if (cVar1 == '\0') {
    iVar2 = FUN_10027688(param_2,&local_14);
    if (iVar2 == 0) {
      if (local_14 == _DAT_d0000000) goto LAB_1001c9d8;
      FUN_10027738(*param_1);
    }
  }
  else {
    iVar2 = FUN_1001cc9c();
    if ((iVar2 != 0) && (iVar2 == 0)) goto LAB_1001c9d8;
  }
  *(undefined1 *)(param_1 + 1) = 1;
LAB_1001c9d8:
  return CONCAT44(param_1,param_1);
}



/* FUN_1001ca0c at 1001ca0c */

undefined4 * FUN_1001ca0c(undefined4 *param_1)

{
  if (*(char *)(param_1 + 1) != '\0') {
    if (DAT_20003b2b == '\0') {
      FUN_10027618(*param_1);
    }
    else {
      FUN_1001cc9c(*param_1,0);
    }
  }
  return param_1;
}



/* FUN_1001ca50 at 1001ca50 */

undefined8 FUN_1001ca50(int param_1,uint *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  uint *puVar7;
  
  iVar2 = param_1 + 4;
  bVar6 = true;
  uVar5 = *param_2;
  iVar1 = *(int *)(param_1 + 8);
  iVar4 = iVar2;
  while (iVar3 = iVar1, iVar3 != 0) {
    bVar6 = *(uint *)(iVar3 + 0x10) <= uVar5;
    if (bVar6) {
      iVar1 = *(int *)(iVar3 + 0xc);
    }
    else {
      iVar1 = *(int *)(iVar3 + 8);
    }
    bVar6 = !bVar6;
    iVar4 = iVar3;
  }
  puVar7 = param_2;
  if (bVar6) {
    if (iVar4 != *(int *)(param_1 + 0xc)) {
      iVar1 = FUN_1001f938(iVar4);
      goto LAB_1001ca78;
    }
  }
  else {
    iVar1 = iVar4;
LAB_1001ca78:
    if (uVar5 <= *(uint *)(iVar1 + 0x10)) goto LAB_1001cab2;
  }
  puVar7 = (uint *)0x1;
  if (iVar2 != iVar4) {
    puVar7 = (uint *)(uint)(uVar5 < *(uint *)(iVar4 + 0x10));
  }
  iVar1 = FUN_1001f90c(0x18);
  uVar5 = param_2[1];
  *(uint *)(iVar1 + 0x10) = *param_2;
  *(uint *)(iVar1 + 0x14) = uVar5;
  FUN_1001f970(puVar7,iVar1,iVar4,iVar2,iVar2,puVar7,param_3);
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
LAB_1001cab2:
  return CONCAT44(puVar7,iVar2);
}



/* FUN_1001cace at 1001cace */

void FUN_1001cace(undefined4 *param_1,undefined4 param_2)

{
  param_1[1] = 0;
  *param_1 = param_2;
  param_1[2] = 0xffffffff;
  return;
}



/* FUN_1001cadc at 1001cadc */

undefined4
FUN_1001cadc(uint *param_1,uint *param_2,uint *param_3,undefined4 *param_4,int param_5,int param_6)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined1 *puVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  bool bVar10;
  uint local_40;
  uint local_3c;
  undefined4 local_38;
  uint local_34 [4];
  undefined1 auStack_24 [16];
  
  FUN_1001c9a4(auStack_24,0x20000fc8,1);
  local_34[1] = 0x50300000;
  puVar7 = &DAT_200016a4;
  local_34[0] = 0x50200000;
  iVar4 = 0;
  do {
    puVar1 = *(undefined1 **)(puVar7 + 4);
    puVar9 = puVar7;
    while (puVar5 = puVar1, puVar5 != (undefined1 *)0x0) {
      if (*(uint *)(puVar5 + 0x10) < *param_1) {
        puVar1 = *(undefined1 **)(puVar5 + 0xc);
      }
      else {
        puVar1 = *(undefined1 **)(puVar5 + 8);
        puVar9 = puVar5;
      }
    }
    if (((puVar9 != puVar7) && (*(uint *)(puVar9 + 0x10) <= *param_1)) && (param_5 + param_6 < 0x20)
       ) {
      uVar6 = local_34[iVar4];
      uVar2 = FUN_1001e0f4(uVar6);
      if (-1 < (int)uVar2) {
        param_1[1] = uVar6;
        param_1[2] = uVar2;
        *param_2 = uVar6;
        *param_3 = uVar2;
        local_38 = *(undefined4 *)(puVar9 + 0x14);
        goto LAB_1001cb48;
      }
    }
    puVar7 = puVar7 + 0x18;
    bVar10 = iVar4 != 1;
    iVar4 = 1;
  } while (bVar10);
  iVar4 = 0;
  do {
    if ((*(char *)(iVar4 + 0x20003b09) != '\0') && (param_5 + param_6 < 0x20)) {
      uVar2 = local_34[iVar4];
      iVar3 = FUN_1001e128(uVar2,*param_1);
      if (iVar3 != 0) {
        uVar6 = FUN_1001e0f4(uVar2,0);
        if (-1 < (int)uVar6) {
          uVar8 = FUN_1001e16c(uVar2,*param_1);
          local_34[2] = *param_1;
          local_34[3] = uVar8;
          FUN_1001ca50((-iVar4 & 0x18U) + 0x200016a0);
          param_1[1] = uVar2;
          param_1[2] = uVar6;
          *param_2 = uVar2;
          *param_3 = uVar6;
          local_38 = uVar8;
          goto LAB_1001cb48;
        }
      }
    }
    bVar10 = iVar4 != 1;
    iVar4 = 1;
  } while (bVar10);
  iVar4 = FUN_1001e2d0(*param_1,&local_40,&local_3c,&local_38,param_5,param_6,1);
  uVar8 = 0;
  if (iVar4 != 0) {
    uVar2 = local_40;
    if (local_40 != 0x50200000) {
      uVar2 = 0x50300000;
    }
    uVar6 = (uint)(local_40 != 0x50200000);
    if (*(char *)(uVar6 + 0x20003b09) != '\0') {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/Users/mateszabo/Library/Arduino15/packages/rp2040/hardware/rp2040/4.5.1/cores/rp2040/PIOProgram.cpp"
                   ,0x7b,"bool PIOProgram::prepare(pio_hw_t**, int*, int*, int, int)",
                   "!__pioAllocated[o]");
    }
    *(undefined1 *)(uVar6 + 0x20003b09) = 1;
    local_34[2] = *param_1;
    local_34[3] = local_38;
    FUN_1001ca50((-uVar6 & 0x18) + 0x200016a0);
    param_1[1] = uVar2;
    param_1[2] = local_3c;
    *param_2 = uVar2;
    *param_3 = local_3c;
LAB_1001cb48:
    *param_4 = local_38;
    uVar8 = 1;
  }
  FUN_1001ca0c(auStack_24);
  return uVar8;
}



/* FUN_1001cc9c at 1001cc9c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_1001cc9c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (_DAT_2000169c == (int *)0x0) {
    _DAT_2000169c = (int *)FUN_1001c7a4(0x10,8,param_3,param_4,param_4);
  }
  piVar1 = _DAT_2000169c;
  piVar2 = _DAT_2000169c;
  do {
    if (*piVar2 == param_1) {
      return (int *)piVar2[1];
    }
    piVar2 = piVar2 + 2;
  } while (piVar2 != _DAT_2000169c + 0x20);
  iVar3 = 0;
  do {
    if (*(int *)((int)_DAT_2000169c + iVar3) == 0) {
      if (_DAT_2000169c == (int *)0x0) {
        return (int *)0x0;
      }
      piVar2 = (int *)((int)_DAT_2000169c + iVar3);
      *piVar2 = param_1;
      piVar2[1] = (int)piVar1;
      return piVar1;
    }
    iVar3 = iVar3 + 8;
  } while (iVar3 != 0x80);
  return (int *)0x0;
}



/* FUN_1001ccfc at 1001ccfc */

void FUN_1001ccfc(int *param_1)

{
  if (*param_1 != 0) {
    FUN_1001c7dc();
  }
  *param_1 = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  return;
}



/* FUN_1001cd14 at 1001cd14 */

bool FUN_1001cd14(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_1001c7c0(*param_1,param_2 + 1);
  if (iVar1 != 0) {
    *param_1 = iVar1;
    param_1[1] = param_2;
  }
  return iVar1 != 0;
}



/* FUN_1001cd2c at 1001cd2c */

undefined4 FUN_1001cd2c(int *param_1,uint param_2)

{
  int iVar1;
  
  if ((*param_1 == 0) || ((uint)param_1[1] < param_2)) {
    iVar1 = FUN_1001cd14(param_1);
    if (iVar1 == 0) {
      return 0;
    }
    if (param_1[2] == 0) {
      *(undefined1 *)*param_1 = 0;
    }
  }
  return 1;
}



/* FUN_1001cd54 at 1001cd54 */

int * FUN_1001cd54(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = FUN_1001cd2c(param_1,param_3);
  if (iVar1 == 0) {
    FUN_1001ccfc(param_1);
  }
  else {
    param_1[2] = param_3;
    FUN_1001f4d4(*param_1,param_2,param_3);
    *(undefined1 *)(*param_1 + param_1[2]) = 0;
  }
  return param_1;
}



/* FUN_1001cd86 at 1001cd86 */

undefined4 * FUN_1001cd86(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (param_2 != 0) {
    uVar1 = FUN_10024360(param_2);
    FUN_1001cd54(param_1,param_2,uVar1);
  }
  return param_1;
}



/* FUN_1001cdac at 1001cdac */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001cdac(undefined4 param_1)

{
  undefined8 uVar1;
  
  uVar1 = FUN_10027638(1,0,param_1);
  _DAT_20001180 = _DAT_20001180 & ~(uint)uVar1;
  _DAT_20001184 = _DAT_20001184 & ~(uint)((ulonglong)uVar1 >> 0x20);
  return;
}



/* FUN_1001cdcc at 1001cdcc */

/* WARNING: Removing unreachable block (ram,0x1001cdee) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001cdcc(void)

{
  do {
  } while ((~_DAT_4000c008 & 1) != 0);
  do {
  } while( true );
}



/* FUN_1001ce00 at 1001ce00 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_1001ce00(void)

{
  return _DAT_40000000 >> 0x1c;
}



/* FUN_1001ce0c at 1001ce0c */

void FUN_1001ce0c(int param_1)

{
  FUN_10021a64("\n*** PANIC ***\n");
  if (param_1 != 0) {
    FUN_10022648(param_1);
    FUN_10021a64("\n");
  }
                    /* WARNING: Subroutine does not return */
  FUN_100275a6(1);
}



/* FUN_1001ce3c at 1001ce3c */

void FUN_1001ce3c(void)

{
  DAT_2000094d = DAT_2000094d + 1;
  if (0x17 < DAT_2000094d) {
    DAT_2000094d = 0x10;
  }
  return;
}



/* FUN_1001ce54 at 1001ce54 */

void FUN_1001ce54(undefined4 param_1,undefined4 param_2)

{
  FUN_1001f83c(0x200027c4,param_1,0x18,0x1f,"No spinlocks are available",param_2);
  return;
}



/* FUN_1001ce74 at 1001ce74 */

void FUN_1001ce74(int param_1,undefined4 param_2)

{
  *(uint *)(param_1 * 4 + 0x4001d004) = (*(uint *)(param_1 * 4 + 0x4001c004) ^ 0x40) & 0xc0;
  *(undefined4 *)(param_1 * 8 + 0x40014004) = param_2;
  return;
}



/* FUN_1001cea4 at 1001cea4 */

void FUN_1001cea4(int param_1,int param_2,int param_3)

{
  *(uint *)(param_1 * 4 + 0x4001d004) =
       ((param_3 << 2 | param_2 << 3) ^ *(uint *)(param_1 * 4 + 0x4001c004)) & 0xc;
  return;
}



/* FUN_1001cee8 at 1001cee8 */

void FUN_1001cee8(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 0) {
    iVar1 = 0x4001f004;
  }
  else {
    iVar1 = 0x4001e004;
  }
  *(undefined4 *)(param_1 * 4 + iVar1) = 0x40;
  return;
}



/* FUN_1001cf1c at 1001cf1c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001cf1c(int param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  
  *(undefined4 *)((param_1 + 0x10) * 4 + _DAT_e000ed08) = param_2;
  DataMemoryBarrier(0x1f);
  DataMemoryBarrier(0x1f);
  _DAT_d0000124 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((param_3 & 1) == 1);
  }
  return;
}



/* FUN_1001cf68 at 1001cf68 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001cf68(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 1 << (param_1 & 0x1f);
  if (param_2 == 0) {
    _DAT_e000e180 = iVar1;
  }
  else {
    _DAT_e000e100 = iVar1;
    _DAT_e000e280 = iVar1;
  }
  return;
}



/* FUN_1001cf90 at 1001cf90 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_1001cf90(uint param_1)

{
  return (_DAT_e000e100 & 1 << (param_1 & 0xff)) != 0;
}



/* FUN_1001cfa8 at 1001cfa8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001cfa8(uint param_1)

{
  _DAT_e000e200 = 1 << (param_1 & 0xff);
  return;
}



/* FUN_1001cfb8 at 1001cfb8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001cfb8(int param_1)

{
  return *(undefined4 *)((param_1 + 0x10) * 4 + _DAT_e000ed08);
}



/* FUN_1001cfc8 at 1001cfc8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001cfc8(undefined4 param_1,undefined1 *param_2)

{
  bool bVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (_DAT_d0000124 == 0);
  DataMemoryBarrier(0x1f);
  puVar2 = (undefined1 *)FUN_1001cfb8(param_1);
  if ((puVar2 != &LAB_100030cc_1) && (puVar2 != param_2)) {
    FUN_1001f608();
  }
  FUN_1001cf1c(param_1,param_2,uVar3);
  return;
}



/* FUN_1001d008 at 1001d008 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d008(int param_1,undefined4 param_2,uint param_3)

{
  char cVar1;
  bool bVar2;
  undefined1 uVar3;
  byte bVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  ushort uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  int iVar11;
  undefined4 *puVar12;
  
  uVar8 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar8 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (_DAT_d0000124 == 0);
  DataMemoryBarrier(0x1f);
  if (0x7f < DAT_20003fc7) {
    FUN_1001f608();
  }
  bVar4 = DAT_20003fc7;
  iVar9 = (int)(char)DAT_20003fc7;
  iVar11 = iVar9 * 0xc;
  DAT_20003fc7 = *(undefined1 *)(iVar11 + 0x20000956);
  puVar5 = *(undefined1 **)((param_1 + 0x10) * 4 + _DAT_e000ed08);
  uVar3 = (undefined1)param_3;
  if (puVar5 + -0x20000950 < (undefined1 *)0x30) {
    puVar12 = (undefined4 *)((uint)puVar5 & 0xfffffffe);
    puVar6 = (undefined4 *)0x0;
    for (puVar10 = puVar12; param_3 < *(byte *)((int)puVar10 + 7);
        puVar10 = (undefined4 *)(*(char *)((int)puVar10 + 6) * 0xc + 0x20000950)) {
      puVar6 = puVar10;
      if (*(char *)((int)puVar10 + 6) < 0) break;
    }
    if (puVar6 != (undefined4 *)0x0) {
      cVar1 = *(char *)((int)puVar6 + 6);
      if (cVar1 < '\0') {
        uVar7 = 0xbd01;
      }
      else {
        uVar7 = (ushort)(((int)puVar6 +
                          (((int)((uint)*(ushort *)(puVar6 + 1) << 0x15) >> 0x14) -
                          (iVar11 + 0x20000954)) + 4 & 0xfffU) >> 1) | 0xe000;
      }
      *(ushort *)(puVar6 + 1) =
           (ushort)((((iVar11 + 0x20000950U) - (int)puVar6) - 8 & 0xfff) >> 1) | 0xe000;
      *(byte *)((int)puVar6 + 6) = bVar4;
      iVar9 = iVar9 * 0xc;
      *(ushort *)(iVar9 + 0x20000954) = uVar7;
      *(undefined4 *)(iVar9 + 0x20000950) = 0x47804801;
      *(undefined1 *)(iVar9 + 0x20000957) = uVar3;
      *(char *)(iVar9 + 0x20000956) = cVar1;
      *(undefined4 *)(iVar9 + 0x20000958) = param_2;
      goto LAB_1001d100;
    }
    iVar9 = iVar9 * 0xc;
    *(undefined2 *)(iVar9 + 0x20000950) = 0xa100;
    *(ushort *)(iVar9 + 0x20000952) =
         (ushort)((0x2000097cU - (iVar11 + 0x20000952) & 0xfff) >> 1) | 0xe000;
    *(undefined1 *)(iVar9 + 0x20000957) = uVar3;
    *(undefined4 *)(iVar9 + 0x20000958) = param_2;
    *(ushort *)(iVar9 + 0x20000954) =
         (ushort)(((int)puVar12 + (-4 - (iVar11 + 0x20000954)) & 0xfffU) >> 1) | 0xe000;
    *(char *)(iVar9 + 0x20000956) =
         (char)(((int)(puVar12 + -0x8000254) * 2 + (uint)((undefined4 *)0x2000094f < puVar12)) *
                0xaaaa >> 0x14);
    *puVar12 = 0x47804801;
  }
  else {
    if (puVar5 != &LAB_100030cc_1) {
      FUN_1001f608();
    }
    iVar9 = iVar9 * 0xc;
    *(undefined2 *)(iVar9 + 0x20000950) = 0xa100;
    *(ushort *)(iVar9 + 0x20000952) =
         (ushort)((0x2000097cU - (iVar11 + 0x20000952) & 0xfff) >> 1) | 0xe000;
    *(undefined2 *)(iVar9 + 0x20000954) = 0xbd01;
    *(undefined1 *)(iVar9 + 0x20000956) = 0xff;
    *(undefined1 *)(iVar9 + 0x20000957) = uVar3;
    *(undefined4 *)(iVar9 + 0x20000958) = param_2;
  }
  puVar5 = (undefined1 *)(iVar11 + 0x20000950U | 1);
LAB_1001d100:
  FUN_1001cf1c(param_1,puVar5,uVar8);
  return;
}



/* FUN_1001d244 at 1001d244 */

undefined8 FUN_1001d244(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = "No user IRQs are available";
  iVar1 = FUN_1001f83c(0x200041d8,param_1,0,5,"No user IRQs are available",param_2);
  if (-1 < iVar1) {
    iVar1 = 0x1f - iVar1;
  }
  return CONCAT44(pcVar2,iVar1);
}



/* FUN_1001d26c at 1001d26c */

void FUN_1001d26c(int *param_1,int param_2)

{
  *param_1 = (param_2 + 0x34000040) * 4;
  return;
}



/* FUN_1001d27c at 1001d27c */

void FUN_1001d27c(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001ce3c();
  FUN_1001d26c(param_1,uVar1);
  *(undefined1 *)(param_1 + 4) = 0xff;
  DataMemoryBarrier(0x1f);
  return;
}



/* FUN_1001d296 at 1001d296 */

void FUN_1001d296(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001ce3c();
  FUN_1001d26c(param_1,uVar1);
  *(undefined2 *)(param_1 + 4) = 0xff;
  DataMemoryBarrier(0x1f);
  return;
}



/* FUN_1001d2b0 at 1001d2b0 */

void FUN_1001d2b0(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)&DAT_20000fc0;
  while (piVar1 < &DAT_20001028) {
    iVar2 = *piVar1;
    piVar1 = piVar1 + 2;
    if (iVar2 == 0) {
      FUN_1001d27c();
    }
    else {
      FUN_1001d296();
    }
  }
  return;
}



/* FUN_1001d2dc at 1001d2dc */

void FUN_1001d2dc(int *param_1,int param_2)

{
  *param_1 = (param_2 + 0x34000040) * 4;
  DataMemoryBarrier(0x1f);
  return;
}



/* FUN_1001d2f0 at 1001d2f0 */

void FUN_1001d2f0(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001ce54(1);
  FUN_1001d2dc(param_1,uVar1);
  return;
}



/* FUN_1001d334 at 1001d334 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d334(undefined1 *param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  *(int *)(param_1 + 0xc) = param_2;
  iVar2 = param_4;
  iVar1 = FUN_1001ce3c();
  *param_1 = (char)param_3;
  param_1[1] = (char)_DAT_d0000000;
  *(short *)(param_1 + 10) = (short)param_4;
  *(short *)(param_1 + 2) = (short)param_4 + -1;
  *(int *)(param_1 + 0x10) = (iVar1 + 0x34000040) * 4;
  *(undefined2 *)(param_1 + 8) = 0xffff;
  *(undefined2 *)(param_1 + 4) = 0xffff;
  for (iVar1 = 0; iVar1 != param_4; iVar1 = iVar1 + 1) {
    *(short *)(iVar1 * 0x18 + *(int *)(param_1 + 0x14)) = (short)iVar1 + -1;
  }
  *(undefined1 **)(param_3 * 4 + 0x20002d0c) = param_1;
  iVar1 = 1 << (param_3 & 0xff);
  *(int *)(param_2 + 0x20) = iVar1;
  FUN_1001cfc8(param_3,0x1001d409,param_3 * 4,0x20002d0c,iVar2);
  FUN_1001cf68(param_3,1);
  *(int *)(param_2 + 0x2038) = iVar1;
  return;
}



/* FUN_1001d3b0 at 1001d3b0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d3b0(void)

{
  if (_DAT_200009a8 == 0) {
    FUN_1001d924(0x40054000,3);
    FUN_1001d334(&DAT_20000998,0x40054000,3,0x10);
  }
  FUN_1001d26c(&DAT_20002f30,10);
  return;
}



/* FUN_1001d3e4 at 1001d3e4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool FUN_1001d3e4(uint param_1,uint param_2)

{
  bool bVar1;
  
  bVar1 = false;
  if ((param_2 <= _DAT_40054024) && (bVar1 = true, _DAT_40054028 < param_1)) {
    bVar1 = param_2 != _DAT_40054024;
  }
  return bVar1;
}



/* FUN_1001d408 at 1001d408 */

/* WARNING: Removing unreachable block (ram,0x1001d454) */
/* WARNING: Removing unreachable block (ram,0x1001d666) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d408(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  bool bVar4;
  int iVar5;
  short *psVar6;
  uint uVar7;
  longlong *plVar8;
  int iVar9;
  short *psVar10;
  int iVar11;
  int iVar12;
  short *psVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  longlong lVar17;
  longlong lVar18;
  uint local_38;
  int local_34;
  
  uVar7 = 0;
  bVar4 = (bool)isCurrentModePrivileged();
  if (bVar4) {
    uVar7 = getCurrentExceptionNumber();
    uVar7 = uVar7 & 0x1ff;
  }
  uVar7 = uVar7 & 3;
  iVar12 = *(int *)(uVar7 * 4 + 0x20002d0c);
  iVar11 = 1 << uVar7;
  _DAT_4005703c = iVar11;
  do {
    sVar1 = *(short *)(iVar12 + 8);
    _DAT_40054034 = iVar11;
    if (-1 < sVar1) {
      psVar13 = (short *)(*(int *)(iVar12 + 0x14) + sVar1 * 0x18);
      uVar15 = *(uint *)(psVar13 + 4);
      iVar16 = *(int *)(psVar13 + 6);
      lVar18 = *(longlong *)(psVar13 + 4);
      lVar17 = FUN_1001d938(0x40054000);
      if (lVar18 <= lVar17) {
        if (-1 < iVar16) {
          plVar8 = *(longlong **)(psVar13 + 10);
          if (*(code **)(psVar13 + 8) == FUN_1001d408 + 1) {
            iVar14 = (**(code **)(plVar8 + 2))(plVar8);
            if (iVar14 == 0) goto LAB_1001d53a;
            lVar18 = *plVar8;
          }
          else {
            lVar18 = (**(code **)(psVar13 + 8))
                               (CONCAT22(*(undefined2 *)(iVar12 + 8),psVar13[1]),plVar8);
          }
          local_34 = (int)((ulonglong)lVar18 >> 0x20);
          local_38 = (uint)lVar18;
          if (lVar18 != 0) {
            if (lVar18 < 0) {
              lVar17 = CONCAT44((iVar16 - local_34) - (uint)(uVar15 < local_38),uVar15 - local_38);
            }
            else {
              lVar17 = FUN_1001d938(0x40054000);
              lVar17 = lVar17 + lVar18;
            }
            iVar14 = (int)((ulonglong)lVar17 >> 0x20);
            iVar16 = (int)*psVar13;
            *(longlong *)(psVar13 + 4) = lVar17;
            if (-1 < iVar16) {
              iVar9 = iVar16 * 0x18 + *(int *)(iVar12 + 0x14);
              iVar5 = *(int *)(iVar9 + 0xc);
              if ((iVar5 <= iVar14) && ((iVar5 != iVar14 || (*(uint *)(iVar9 + 8) <= (uint)lVar17)))
                 ) {
                *(short *)(iVar12 + 8) = *psVar13;
                psVar6 = (short *)(iVar12 + 8);
                while( true ) {
                  psVar10 = (short *)(iVar16 * 0x18 + *(int *)(iVar12 + 0x14));
                  if (iVar14 < *(int *)(psVar10 + 6)) break;
                  if (((*(int *)(psVar10 + 6) == iVar14) && ((uint)lVar17 < *(uint *)(psVar10 + 4)))
                     || (iVar16 = (int)*psVar10, psVar6 = psVar10, iVar16 < 0)) break;
                }
                *psVar13 = (short)iVar16;
                *psVar6 = sVar1;
              }
            }
            goto LAB_1001d4e4;
          }
        }
LAB_1001d53a:
        *(short *)(iVar12 + 8) = *psVar13;
        uVar15 = 0;
        bVar4 = (bool)isCurrentModePrivileged();
        if (bVar4) {
          uVar15 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        do {
        } while (**(int **)(iVar12 + 0x10) == 0);
        DataMemoryBarrier(0x1f);
        *psVar13 = *(short *)(iVar12 + 2);
        *(short *)(iVar12 + 2) = sVar1;
        DataMemoryBarrier(0x1f);
        **(undefined4 **)(iVar12 + 0x10) = 0;
        bVar4 = (bool)isCurrentModePrivileged();
        if (bVar4) {
          enableIRQinterrupts((uVar15 & 1) == 1);
        }
      }
    }
LAB_1001d4e4:
    if (-1 < *(short *)(iVar12 + 4)) {
      uVar15 = 0;
      bVar4 = (bool)isCurrentModePrivileged();
      if (bVar4) {
        uVar15 = isIRQinterruptsEnabled();
      }
      disableIRQinterrupts();
      do {
      } while (**(int **)(iVar12 + 0x10) == 0);
      DataMemoryBarrier(0x1f);
      sVar1 = *(short *)(iVar12 + 4);
      *(undefined2 *)(iVar12 + 4) = 0xffff;
      DataMemoryBarrier(0x1f);
      **(undefined4 **)(iVar12 + 0x10) = 0;
      bVar4 = (bool)isCurrentModePrivileged();
      if (bVar4) {
        enableIRQinterrupts((uVar15 & 1) == 1);
      }
      while (-1 < sVar1) {
        psVar6 = (short *)(*(int *)(iVar12 + 0x14) + sVar1 * 0x18);
        sVar2 = *(short *)(iVar12 + 8);
        psVar13 = (short *)(iVar12 + 8);
        while (-1 < sVar2) {
          psVar10 = (short *)(*(int *)(iVar12 + 0x14) + *psVar13 * 0x18);
          if ((*(int *)(psVar6 + 6) < *(int *)(psVar10 + 6)) ||
             ((*(int *)(psVar10 + 6) == *(int *)(psVar6 + 6) &&
              (*(uint *)(psVar6 + 4) < *(uint *)(psVar10 + 4))))) break;
          psVar13 = psVar10;
          sVar2 = *psVar10;
        }
        *psVar13 = sVar1;
        sVar1 = *psVar6;
        *psVar6 = sVar2;
      }
    }
    if (*(char *)(iVar12 + 6) != '\0') {
      *(undefined1 *)(iVar12 + 6) = 0;
      psVar13 = (short *)(iVar12 + 8);
      sVar1 = *(short *)(iVar12 + 8);
      while (sVar2 = sVar1, psVar6 = psVar13, iVar16 = (int)sVar2, iVar16 != -1) {
        psVar10 = (short *)(*(int *)(iVar12 + 0x14) + iVar16 * 0x18);
        sVar1 = *(short *)(*(int *)(iVar12 + 0x14) + iVar16 * 0x18);
        psVar13 = psVar10;
        if (psVar10[1] < 0) {
          sVar3 = *(short *)(iVar12 + 8);
          psVar10[4] = -1;
          psVar10[5] = -1;
          psVar10[6] = -1;
          psVar10[7] = -1;
          psVar13 = psVar6;
          if (iVar16 != sVar3) {
            *psVar6 = sVar1;
            *psVar10 = *(short *)(iVar12 + 8);
            *(short *)(iVar12 + 8) = sVar2;
          }
        }
      }
    }
    if (*(short *)(iVar12 + 8) < 0) {
      return;
    }
    iVar16 = *(int *)(iVar12 + 0x14) + *(short *)(iVar12 + 8) * 0x18;
    plVar8 = (longlong *)(iVar16 + 8);
    iVar14 = *(int *)plVar8;
    lVar18 = *plVar8;
    if (((iVar14 != -1) || (*(int *)(iVar16 + 0xc) != -1)) &&
       (((uint)(iVar14 - _DAT_40054028) < (uint)(*(int *)(uVar7 * 4 + 0x40054010) - _DAT_40054028)
        || ((_DAT_40054020 & 1 << uVar7) == 0)))) {
      *(int *)(uVar7 * 4 + 0x40054010) = iVar14;
    }
    lVar17 = FUN_1001d938(0x40054000);
    if (lVar17 < lVar18) {
      return;
    }
  } while( true );
}



/* FUN_1001d680 at 1001d680 */

uint FUN_1001d680(sbyte *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  short sVar1;
  bool bVar2;
  uint uVar3;
  undefined2 *puVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    uVar6 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (**(int **)(param_1 + 0x10) == 0);
  DataMemoryBarrier(0x1f);
  sVar1 = *(short *)(param_1 + 2);
  iVar5 = (int)sVar1;
  puVar4 = (undefined2 *)(*(int *)(param_1 + 0x14) + iVar5 * 0x18);
  if (-1 < iVar5) {
    *(undefined2 *)(param_1 + 2) = *puVar4;
  }
  DataMemoryBarrier(0x1f);
  **(undefined4 **)(param_1 + 0x10) = 0;
  bVar2 = (bool)isCurrentModePrivileged();
  if (bVar2) {
    enableIRQinterrupts((uVar6 & 1) == 1);
  }
  if (iVar5 < 0) {
    uVar6 = 0xffffffff;
  }
  else {
    *(undefined4 *)(puVar4 + 6) = param_4;
    *(undefined4 *)(puVar4 + 8) = param_5;
    uVar6 = (ushort)puVar4[1] + 1 & 0x7fff;
    *(undefined4 *)(puVar4 + 4) = param_3;
    *(undefined4 *)(puVar4 + 10) = param_6;
    if (uVar6 == 0) {
      uVar6 = 1;
    }
    puVar4[1] = (short)uVar6;
    uVar6 = iVar5 << 0x10 | uVar6;
    uVar3 = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      uVar3 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    do {
    } while (**(int **)(param_1 + 0x10) == 0);
    DataMemoryBarrier(0x1f);
    *puVar4 = *(undefined2 *)(param_1 + 4);
    *(short *)(param_1 + 4) = sVar1;
    DataMemoryBarrier(0x1f);
    **(undefined4 **)(param_1 + 0x10) = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      enableIRQinterrupts((uVar3 & 1) == 1);
    }
    *(int *)(*(int *)(param_1 + 0xc) + 0x203c) = 1 << *param_1;
  }
  return uVar6;
}



/* FUN_1001d720 at 1001d720 */

undefined8
FUN_1001d720(undefined4 param_1,int param_2,uint param_3,int param_4,undefined4 param_5,
            undefined4 param_6,char param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar4 = param_3;
  if ((param_7 == '\0') &&
     (uVar3 = param_1, uVar2 = FUN_1001d960(), param_2 = (int)((ulonglong)uVar2 >> 0x20),
     (int)((param_4 - param_2) - (uint)(param_3 < (uint)uVar2)) < 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_1001d680(param_1,param_2,param_3,param_4,param_5,param_6,uVar4);
    uVar3 = param_5;
  }
  return CONCAT44(uVar3,uVar1);
}



/* FUN_1001d758 at 1001d758 */

undefined1 FUN_1001d758(sbyte *param_1,uint param_2)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  if ((int)param_2 >> 0x10 < (int)(uint)*(ushort *)(param_1 + 10)) {
    iVar3 = *(int *)(param_1 + 0x14) + ((int)param_2 >> 0x10) * 0x18;
    uVar4 = 0;
    bVar5 = (bool)isCurrentModePrivileged();
    if (bVar5) {
      uVar4 = isIRQinterruptsEnabled();
    }
    disableIRQinterrupts();
    do {
    } while (**(int **)(param_1 + 0x10) == 0);
    DataMemoryBarrier(0x1f);
    uVar1 = *(ushort *)(iVar3 + 2);
    bVar5 = (uint)uVar1 == (param_2 & 0xffff);
    if (bVar5) {
      *(ushort *)(iVar3 + 2) = uVar1 | 0x8000;
      param_1[6] = 1;
    }
    DataMemoryBarrier(0x1f);
    **(undefined4 **)(param_1 + 0x10) = 0;
    bVar2 = (bool)isCurrentModePrivileged();
    if (bVar2) {
      enableIRQinterrupts((uVar4 & 1) == 1);
    }
    if (bVar5) {
      *(int *)(*(int *)(param_1 + 0xc) + 0x203c) = 1 << *param_1;
      return 1;
    }
  }
  return 0;
}



/* FUN_1001d7c0 at 1001d7c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d7c0(uint param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  uVar5 = param_1 - 6;
  uVar6 = (param_2 - 1) + (uint)(5 < param_1);
  if ((param_2 < uVar6) || ((uVar6 == param_2 && (param_1 < uVar5)))) {
    uVar5 = 0;
    uVar6 = 0;
  }
  uVar7 = FUN_1001d960();
  iVar3 = (int)((ulonglong)uVar7 >> 0x20);
  uVar4 = uVar6 - iVar3;
  uVar2 = (uint)(uVar5 < (uint)uVar7);
  if ((0 < (int)(uVar4 - uVar2)) || ((uVar4 == uVar2 && (uVar5 != (uint)uVar7)))) {
    iVar3 = FUN_1001d720(&DAT_20000998,iVar3,uVar5,uVar6,&LAB_1001d304_1,0,0);
    if (iVar3 != -1) {
      while (iVar3 = FUN_1001d3e4(uVar5,uVar6), iVar3 == 0) {
        uVar4 = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          uVar4 = isIRQinterruptsEnabled();
        }
        disableIRQinterrupts();
        do {
        } while (*_DAT_20002f30 == 0);
        DataMemoryBarrier(0x1f);
        DataMemoryBarrier(0x1f);
        *_DAT_20002f30 = 0;
        bVar1 = (bool)isCurrentModePrivileged();
        if (bVar1) {
          enableIRQinterrupts((uVar4 & 1) == 1);
        }
        WaitForEvent();
      }
    }
  }
  FUN_1001d970(param_1,param_2);
  return;
}



/* FUN_1001d858 at 1001d858 */

void FUN_1001d858(undefined4 param_1,undefined4 param_2)

{
  longlong lVar1;
  
  lVar1 = FUN_1001d960();
  lVar1 = lVar1 + CONCAT44(param_2,param_1);
  if (lVar1 < 0) {
    lVar1 = 0x7fffffffffffffff;
  }
  FUN_1001d7c0((int)lVar1,(int)((ulonglong)lVar1 >> 0x20));
  return;
}



/* FUN_1001d87c at 1001d87c */

void FUN_1001d87c(undefined4 param_1)

{
  FUN_1001f484(param_1,0,1000,0);
  FUN_1001d858();
  return;
}



/* FUN_1001d890 at 1001d890 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001d890(uint param_1,int param_2)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  iVar3 = _DAT_200009a4;
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = getCurrentExceptionNumber();
    uVar5 = uVar5 & 0x1ff;
  }
  if (uVar5 == 0) {
    uVar6 = (uint)DAT_20000998;
    uVar7 = FUN_1001d938(_DAT_200009a4);
    uVar2 = (uint)uVar7;
    uVar5 = param_2 - (int)((ulonglong)uVar7 >> 0x20);
    if (((int)(uVar5 - (param_1 < uVar2)) < 0) ||
       ((uVar5 == param_1 < uVar2 && (param_1 - uVar2 < *(int *)((uVar6 + 4) * 4 + iVar3) - uVar2)))
       ) {
      iVar3 = FUN_1001d720(&DAT_20000998,0,param_1,param_2,&LAB_1001d304_1,0,0);
      if (0 < iVar3) {
        iVar4 = FUN_1001d3e4(param_1,param_2);
        if (iVar4 == 0) {
          WaitForEvent();
        }
        FUN_1001d758(&DAT_20000998,iVar3);
      }
    }
    else {
      WaitForEvent();
    }
  }
  FUN_1001d3e4(param_1,param_2);
  return;
}



/* FUN_1001d924 at 1001d924 */

void FUN_1001d924(undefined4 param_1,undefined4 param_2)

{
  FUN_1001f802(0x20003f6a,param_2,"Hardware alarm %d already claimed");
  return;
}



/* FUN_1001d938 at 1001d938 */

undefined4 FUN_1001d938(int param_1)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = *(int *)(param_1 + 0x24);
  do {
    bVar2 = iVar1 != *(int *)(param_1 + 0x24);
    iVar1 = *(int *)(param_1 + 0x24);
  } while (bVar2);
  return *(undefined4 *)(param_1 + 0x28);
}



/* FUN_1001d948 at 1001d948 */

void FUN_1001d948(int param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint uVar1;
  
  do {
    uVar1 = *(uint *)(param_1 + 0x24);
  } while (uVar1 < param_4);
  while ((uVar1 == param_4 && (*(uint *)(param_1 + 0x28) < param_3))) {
    uVar1 = *(uint *)(param_1 + 0x24);
  }
  return;
}



/* FUN_1001d960 at 1001d960 */

void FUN_1001d960(void)

{
  FUN_1001d938(0x40054000);
  return;
}



/* FUN_1001d970 at 1001d970 */

void FUN_1001d970(undefined4 param_1,undefined4 param_2)

{
  FUN_1001d948(0x40054000,param_2,param_1,param_2);
  return;
}



/* FUN_1001d984 at 1001d984 */

void FUN_1001d984(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  FUN_1001d26c(param_1,param_4);
  uVar1 = FUN_1001c7a4(param_3 + 1,param_2);
  *(short *)(param_1 + 0xe) = (short)param_3;
  *(short *)(param_1 + 0xc) = (short)param_2;
  *(undefined4 *)(param_1 + 4) = uVar1;
  *(undefined4 *)(param_1 + 8) = 0;
  return;
}



/* FUN_1001d9a8 at 1001d9a8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1001d9a8(int param_1,uint param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  iVar3 = param_1 * 0xc;
  if (*(uint *)(iVar3 + 0x40008004) < param_5) {
    *(uint *)(iVar3 + 0x40008004) = param_5;
  }
  uVar4 = param_1 - 4U & 0xff;
  if ((uVar4 < 2) && (param_2 == 1)) {
    *(undefined4 *)(iVar3 + 0x4000b000) = 3;
    do {
    } while ((*(uint *)(iVar3 + 0x40008008) & 1) == 0);
  }
  else {
    *(undefined4 *)(iVar3 + 0x4000b000) = 0x800;
    if (*(int *)(param_1 * 4 + 0x200027c8) != 0) {
      iVar1 = FUN_1001e4d0(_DAT_200027dc);
      uVar2 = (iVar1 + 1) * 3;
      do {
        bVar5 = 2 < uVar2;
        uVar2 = uVar2 - 3;
      } while (bVar5);
    }
  }
  *(uint *)(iVar3 + 0x40009000) = (param_3 << 5 ^ *(uint *)(iVar3 + 0x40008000)) & 0xe0;
  if (uVar4 < 2) {
    *(uint *)(iVar3 + 0x40009000) = (*(uint *)(iVar3 + 0x40008000) ^ param_2) & 3;
    do {
    } while ((1 << (param_2 & 0xff) & *(uint *)(iVar3 + 0x40008008)) == 0);
  }
  *(undefined4 *)(iVar3 + 0x4000a000) = 0x800;
  *(uint *)(iVar3 + 0x40008004) = param_5;
  *(undefined4 *)(param_1 * 4 + 0x200027c8) = param_4;
  return CONCAT44(param_4,param_3);
}



/* FUN_1001da50 at 1001da50 */

undefined8
FUN_1001da50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar2 = param_2;
  uVar1 = FUN_1001e4d0(param_4,param_5,param_3,param_4,param_1,param_2,param_3);
  param_5 = param_5 << 8;
  FUN_1001d9a8(param_1,param_2,param_3,uVar1);
  return CONCAT44(uVar2,param_5);
}



/* FUN_1001da74 at 1001da74 */

undefined8 FUN_1001da74(undefined4 param_1,undefined4 param_2)

{
  FUN_1001d9a8();
  return CONCAT44(param_2,0x100);
}



/* FUN_1001da84 at 1001da84 */

undefined4 FUN_1001da84(int param_1)

{
  return *(undefined4 *)(param_1 * 4 + 0x200027c8);
}



/* FUN_1001da90 at 1001da90 */

undefined8 FUN_1001da90(undefined4 param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_1001da74(5,1,1,48000000,param_1);
  iVar2 = param_3;
  FUN_1001db68(0x40028000,1,param_1,param_2);
  uVar1 = FUN_1001e4d0(param_1,param_2 * param_3);
  FUN_1001da74(4,2,0,12000000);
  FUN_1001da74(5,1,0,uVar1);
  FUN_1001da74(6,0,2,48000000);
  return CONCAT44(param_2,iVar2);
}



/* FUN_1001daf0 at 1001daf0 */

undefined4 FUN_1001daf0(int param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined8 uVar5;
  
  iVar2 = 0x140;
  do {
    iVar1 = 7;
    if (iVar2 * 12000 - 750000U < 0xcf851) {
      do {
        iVar4 = iVar1 * iVar1;
        iVar3 = iVar1;
        do {
          uVar5 = FUN_1001e4d0(iVar2 * 12000,iVar4);
          if (((int)uVar5 == param_1) && ((int)((ulonglong)uVar5 >> 0x20) == 0)) {
            *param_2 = iVar2 * 12000000;
            *param_3 = iVar1;
            *param_4 = iVar3;
            return 1;
          }
          iVar3 = iVar3 + -1;
          iVar4 = iVar4 - iVar1;
        } while (iVar3 != 0);
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    iVar2 = iVar2 + -1;
    if (iVar2 == 0xf) {
      return 0;
    }
  } while( true );
}



/* FUN_1001db68 at 1001db68 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001db68(uint *param_1,uint param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_1001e4d0(12000000);
  uVar2 = FUN_1001e4d0(param_3,uVar1);
  uVar3 = param_4 << 0x10 | param_5 << 0xc;
  if ((((-1 < (int)*param_1) || ((*param_1 & 0x3f) != param_2)) || ((param_1[2] & 0xfff) != uVar2))
     || ((param_1[3] & 0x77000) != uVar3)) {
    _DAT_4000e000 = 1 << (param_1 == (uint *)0x4002c000) + 0xc;
    do {
    } while ((_DAT_4000e000 & ~_DAT_4000c008) != 0);
    _DAT_4000f000 = _DAT_4000e000;
    *param_1 = param_2;
    param_1[2] = uVar2;
    param_1[0xc01] = 0x21;
    do {
    } while (-1 < (int)*param_1);
    param_1[3] = uVar3;
    param_1[0xc01] = 8;
  }
  return;
}



/* FUN_1001dc04 at 1001dc04 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001dc04(int param_1)

{
  _DAT_40065000 = (param_1 << 4 ^ _DAT_40064000) & 0xf0;
  return;
}



/* FUN_1001dc20 at 1001dc20 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_1001dc20(void)

{
  return (_DAT_40064000 & 0xff) >> 4;
}



/* FUN_1001dc30 at 1001dc30 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001dc30(undefined4 param_1)

{
  (*(code *)(uint)_DAT_00000018)(_DAT_00000014,param_1);
  return;
}



/* FUN_1001dc40 at 1001dc40 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001dc40(undefined4 param_1)

{
  (*(code *)(uint)_DAT_00000018)(_DAT_00000016,param_1);
  return;
}



/* FUN_1001dc50 at 1001dc50 */

byte FUN_1001dc50(int *param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  bVar2 = 1;
  for (iVar3 = 0; iVar3 != param_2; iVar3 = iVar3 + 1) {
    iVar1 = FUN_1001dc30(*param_1);
    *param_1 = iVar1;
    param_1 = param_1 + 1;
    bVar2 = bVar2 & 1U - (iVar1 == 0);
  }
  return bVar2;
}



/* FUN_1001dc8c at 1001dc8c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001dc8c(int param_1)

{
  return *(undefined4 *)(param_1 * 4 + _DAT_e000ed08);
}



/* FUN_1001dc9c at 1001dc9c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * FUN_1001dc9c(int param_1,undefined *param_2)

{
  bool bVar1;
  undefined *puVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  puVar2 = (undefined *)FUN_1001dc8c();
  if ((puVar2 != param_2) && ((puVar2 < &DAT_100030c0 || (&DAT_100030cb < puVar2)))) {
    FUN_1001f608();
  }
  *(undefined **)(param_1 * 4 + _DAT_e000ed08) = param_2;
  DataMemoryBarrier(0x1f);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar3 & 1) == 1);
  }
  return puVar2;
}



/* FUN_1001dce4 at 1001dce4 */

void FUN_1001dce4(undefined4 param_1)

{
  undefined1 local_28 [16];
  undefined1 auStack_18 [5];
  undefined1 auStack_13 [11];
  
  FUN_1001f4c8(local_28,0,0xd);
  FUN_1001f4c8(auStack_18,0,0xd);
  local_28[0] = 0x4b;
  FUN_10027608(local_28,auStack_18,0xd);
  FUN_1001f4d4(param_1,auStack_13,8);
  return;
}



/* FUN_1001dd1e at 1001dd1e */

int FUN_1001dd1e(int *param_1,undefined4 param_2,int param_3,int param_4,byte param_5,code *param_6,
                undefined4 param_7)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int local_2c;
  
  iVar4 = 0;
  uVar5 = 0;
  local_2c = 0;
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x6c) = 0;
  *(undefined4 *)(iVar2 + 4) = param_2;
  *(undefined4 *)(iVar2 + 0x6c) = 1;
  do {
    if (param_4 <= iVar4) {
LAB_1001dd44:
      *(byte *)(param_1 + 1) = param_5;
      return iVar4;
    }
    if (param_6 != (code *)0x0) {
      (*param_6)(param_7,1);
    }
    uVar1 = 0;
    if (iVar4 == 0) {
      uVar1 = (uint)*(byte *)(param_1 + 1);
    }
    uVar3 = 0;
    if (param_4 + -1 == iVar4) {
      uVar3 = param_5 ^ 1;
    }
    uVar6 = 0;
    *(uint *)(*param_1 + 0x10) = uVar3 << 9 | (uint)*(byte *)(param_3 + iVar4) | uVar1 << 10;
    uVar1 = uVar5;
    do {
      if (param_6 != (code *)0x0) {
        uVar1 = (*param_6)(param_7,0);
        uVar6 = uVar6 | uVar1 & 0xff;
      }
      if (uVar1 != 0) goto LAB_1001ddda;
    } while ((*(uint *)(*param_1 + 0x34) & 0x10) == 0);
    local_2c = *(int *)(*param_1 + 0x80);
    if (local_2c == 0) {
      if ((uVar6 != 0) || ((uVar5 = 0, param_4 + -1 == iVar4 && (param_5 == 0)))) goto LAB_1001ddb8;
    }
    else {
      uVar6 = 1;
LAB_1001ddb8:
      do {
        if (param_6 != (code *)0x0) {
          uVar5 = (*param_6)(param_7,0);
          uVar6 = uVar6 | uVar5 & 0xff;
          if (uVar5 != 0) goto LAB_1001de0e;
        }
      } while ((*(uint *)(*param_1 + 0x34) & 0x200) == 0);
LAB_1001ddda:
      uVar5 = uVar1;
      if (uVar6 != 0) {
LAB_1001de0e:
        if (uVar5 == 0) {
          if (((local_2c != 0) && (-1 < local_2c << 0x1f)) && (local_2c << 0x1c < 0))
          goto LAB_1001dd44;
          iVar4 = 1;
        }
        else {
          iVar4 = 2;
        }
        iVar4 = -iVar4;
        goto LAB_1001dd44;
      }
    }
    iVar4 = iVar4 + 1;
  } while( true );
}



/* FUN_1001de16 at 1001de16 */

uint FUN_1001de16(int *param_1,undefined4 param_2,int param_3,int param_4,byte param_5,code *param_6
                 ,undefined4 param_7)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x6c) = 0;
  *(undefined4 *)(iVar2 + 4) = param_2;
  *(undefined4 *)(iVar2 + 0x6c) = 1;
  do {
    if (param_4 <= (int)uVar4) {
LAB_1001de3a:
      *(byte *)(param_1 + 1) = param_5;
      return uVar4;
    }
    if (param_6 != (code *)0x0) {
      (*param_6)(param_7,1);
    }
    iVar2 = *param_1;
    do {
    } while (*(int *)(iVar2 + 0x74) == 0x10);
    uVar1 = 0;
    if (uVar4 == 0) {
      uVar1 = (uint)*(byte *)(param_1 + 1);
    }
    uVar3 = 0;
    if (param_4 - 1U == uVar4) {
      uVar3 = param_5 ^ 1;
    }
    *(uint *)(iVar2 + 0x10) = uVar3 << 9 | uVar1 << 10 | 0x100;
    do {
      uVar1 = *(uint *)(iVar2 + 0x34);
      uVar3 = uVar1 & 0x40;
      if ((uVar1 & 0x40) != 0) {
        uVar1 = *(uint *)(iVar2 + 0x54);
        if (param_6 != (code *)0x0) {
          uVar3 = 1;
          goto LAB_1001de94;
        }
        uVar1 = 0;
LAB_1001debc:
        uVar4 = ~uVar1;
        goto LAB_1001de3a;
      }
      if (param_6 != (code *)0x0) {
LAB_1001de94:
        uVar1 = (*param_6)(param_7,0,iVar2,uVar1);
        if ((uVar1 != 0) || (uVar3 != 0)) goto LAB_1001debc;
      }
      iVar2 = *param_1;
    } while (*(int *)(iVar2 + 0x78) == 0);
    *(char *)(param_3 + uVar4) = (char)*(undefined4 *)(iVar2 + 0x10);
    uVar4 = uVar4 + 1;
  } while( true );
}



/* FUN_1001dec0 at 1001dec0 */

void FUN_1001dec0(undefined4 *param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint uVar8;
  
  iVar1 = FUN_1001da84(5);
  iVar2 = FUN_1001e4d0((param_2 >> 1) + iVar1,param_2);
  uVar8 = iVar2 * 3;
  uVar3 = FUN_1001e4d0(uVar8,5);
  if (param_2 < 1000000) {
    uVar6 = 10000000;
  }
  else {
    uVar6 = 25000000;
  }
  iVar4 = FUN_1001e4d0(iVar1 * 3,uVar6);
  uVar5 = 1;
  puVar7 = (uint *)*param_1;
  puVar7[0x1b] = 0;
  puVar7[0x400] = (*puVar7 ^ 4) & 6;
  puVar7[7] = iVar2 - uVar3;
  puVar7[8] = uVar3;
  if (0x4f < uVar8) {
    uVar5 = FUN_1001e4d0(uVar8,0x50);
  }
  puVar7[0x28] = uVar5;
  puVar7[0x41f] = (iVar4 + 1U ^ puVar7[0x1f]) & 0xffff;
  puVar7[0x1b] = 1;
  FUN_1001e4d0(iVar1,iVar2);
  return;
}



/* FUN_1001df6c at 1001df6c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001df6c(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  _DAT_4000e000 = 1 << (4 - (param_1 == (undefined4 *)&DAT_200009b0) & 0xff);
  do {
  } while ((_DAT_4000e000 & ~_DAT_4000c008) != 0);
  puVar1 = (undefined4 *)*param_1;
  _DAT_4000f000 = _DAT_4000e000;
  *(undefined1 *)(param_1 + 1) = 0;
  puVar1[0x1b] = 0;
  *puVar1 = 0x165;
  puVar1[0xf] = 0;
  puVar1[0xe] = 0;
  puVar1[0x22] = 3;
  FUN_1001dec0();
  return;
}



/* FUN_1001dfc0 at 1001dfc0 */

void FUN_1001dfc0(void)

{
  FUN_1001dd1e();
  return;
}



/* FUN_1001dfd8 at 1001dfd8 */

void FUN_1001dfd8(void)

{
  FUN_1001de16();
  return;
}



/* FUN_1001dff0 at 1001dff0 */

int FUN_1001dff0(int param_1,uint param_2,uint param_3,int param_4,uint param_5)

{
  int iVar1;
  
  if (param_4 == 0) {
    if (((int)param_3 < 0) || (param_3 == param_5)) {
      if ((*(uint *)((param_1 + 0xafe00000U >> 0x14) * 4 + 0x2000241c) &
          (1 << (param_2 & 0xff)) + -1 << (param_5 & 0xff)) == 0) {
        return 0;
      }
      return -9;
    }
    iVar1 = 0xb;
  }
  else {
    iVar1 = 0x14;
  }
  return -iVar1;
}



/* FUN_1001e030 at 1001e030 */

undefined8 FUN_1001e030(int param_1,int *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = (uint)*(byte *)(param_2 + 1);
  uVar5 = param_3;
  uVar1 = FUN_1001dff0(param_1,uVar4,(int)*(char *)((int)param_2 + 5),
                       *(undefined1 *)((int)param_2 + 6),param_3,param_2,param_3);
  if (uVar1 == 0) {
    for (uVar1 = 0; uVar1 < uVar4; uVar1 = uVar1 + 1) {
      uVar2 = (uint)*(ushort *)(uVar1 * 2 + *param_2);
      if (uVar2 < 0x2000) {
        uVar2 = uVar2 + param_3;
      }
      *(uint *)((param_3 + uVar1 + 0x12) * 4 + param_1) = uVar2;
    }
    iVar3 = (param_1 + 0xafe00000U >> 0x14) * 4;
    *(uint *)(iVar3 + 0x2000241c) =
         (1 << uVar4) + -1 << (param_3 & 0xff) | *(uint *)(iVar3 + 0x2000241c);
    uVar1 = param_3;
  }
  return CONCAT44(uVar5,uVar1);
}



/* FUN_1001e090 at 1001e090 */

uint FUN_1001e090(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)((param_1 + 0xafe00000U >> 0x14) * 4 + 0x2000241c);
  uVar1 = 0x20 - param_2;
  iVar2 = (1 << (param_2 & 0xff)) + -1;
  if ((int)param_3 < 0) {
    for (; -1 < (int)uVar1; uVar1 = uVar1 - 1) {
      if ((uVar3 & iVar2 << (uVar1 & 0xff)) == 0) {
        return uVar1;
      }
    }
    iVar2 = 9;
  }
  else {
    if (((int)param_3 <= (int)uVar1) && ((uVar3 & iVar2 << (param_3 & 0xff)) == 0)) {
      return param_3;
    }
    iVar2 = 1;
  }
  return -iVar2;
}



/* FUN_1001e0d8 at 1001e0d8 */

void FUN_1001e0d8(int param_1,int param_2)

{
  FUN_1001f88e(0x20003f6b,(param_1 + 0xafe00000U >> 0x14) * 4 + param_2);
  return;
}



/* FUN_1001e0f4 at 1001e0f4 */

undefined8 FUN_1001e0f4(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  
  uVar2 = param_1 + 0xafe00000U >> 0x14;
  iVar3 = uVar2 * 4;
  pcVar4 = "No PIO state machines are available";
  iVar1 = FUN_1001f83c(0x20003f6b,param_2,iVar3,iVar3 + 3,"No PIO state machines are available",
                       param_2);
  if (iVar1 < iVar3) {
    iVar1 = -1;
  }
  else {
    iVar1 = iVar1 + uVar2 * -4;
  }
  return CONCAT44(pcVar4,iVar1);
}



/* FUN_1001e128 at 1001e128 */

bool FUN_1001e128(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = FUN_1001f7c0();
  cVar2 = *(char *)(param_2 + 5);
  uVar1 = *(undefined1 *)(param_2 + 4);
  iVar4 = FUN_1001e090(param_1,uVar1,(int)cVar2);
  if (-1 < iVar4) {
    iVar4 = FUN_1001dff0(param_1,uVar1,(int)cVar2,*(undefined1 *)(param_2 + 6),iVar4);
  }
  FUN_1001f7d8(uVar3);
  return iVar4 == 0;
}



/* FUN_1001e16c at 1001e16c */

int FUN_1001e16c(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_1001f7c0();
  iVar2 = FUN_1001e090(param_1,*(undefined1 *)(param_2 + 4),(int)*(char *)(param_2 + 5));
  if (-1 < iVar2) {
    iVar2 = FUN_1001e030(param_1,param_2,iVar2);
  }
  FUN_1001f7d8(uVar1);
  return iVar2;
}



/* FUN_1001e1a0 at 1001e1a0 */

undefined4 FUN_1001e1a0(int param_1,int param_2,uint param_3,uint param_4,char param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if (param_3 < 0x20) {
    iVar2 = param_1 + param_2 * 0x18;
    uVar4 = *(uint *)(iVar2 + 0xdc);
    uVar3 = *(undefined4 *)(iVar2 + 0xcc);
    *(undefined4 *)(param_1 + param_2 * 0x18 + 0x30cc) = 0x20000;
    uVar1 = 0;
    if (param_5 != '\0') {
      uVar1 = 0x1f;
    }
    iVar2 = param_1 + param_2 * 0x18;
    for (; 5 < param_4; param_4 = param_4 - 5) {
      *(uint *)(iVar2 + 0xdc) = param_3 << 5 | 0x14000000;
      *(uint *)(iVar2 + 0xd8) = uVar1 | 0xe080;
      param_3 = param_3 + 5 & 0x1f;
    }
    param_1 = param_1 + param_2 * 0x18;
    *(uint *)(param_1 + 0xdc) = param_4 << 0x1a | param_3 << 5;
    *(uint *)(param_1 + 0xd8) = uVar1 | 0xe080;
    *(uint *)(param_1 + 0xdc) = uVar4;
    *(undefined4 *)(param_1 + 0xcc) = uVar3;
    uVar3 = 0;
  }
  else {
    uVar3 = 0xfffffffb;
  }
  return uVar3;
}



/* FUN_1001e240 at 1001e240 */

undefined4 FUN_1001e240(uint *param_1,uint param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint *puVar2;
  
  *param_1 = *param_1 & ~(1 << (param_2 & 0xff));
  if (param_4 == (uint *)0x0) {
    puVar2 = param_1 + param_2 * 6;
    puVar2[0x32] = 0x10000;
    puVar2[0x34] = 0xc0000;
    puVar2[0x33] = 0x1f000;
    uVar1 = 0;
  }
  else {
    puVar2 = param_1 + param_2 * 6;
    puVar2[0x32] = *param_4;
    puVar2[0x34] = param_4[2];
    uVar1 = param_4[3];
    puVar2[0x33] = param_4[1];
  }
  puVar2[0x37] = uVar1;
  param_1[param_2 * 6 + 0x434] = 0x80000000;
  param_1[param_2 * 6 + 0x434] = 0x80000000;
  param_1[2] = 0x1010101 << (param_2 & 0xff);
  param_1[0x800] = 1 << (param_2 + 4 & 0xff);
  param_1[0x800] = 1 << (param_2 + 8 & 0xff);
  param_1[param_2 * 6 + 0x36] = param_3 & 0x1f;
  return 0;
}



/* FUN_1001e2d0 at 1001e2d0 */

undefined4 FUN_1001e2d0(int param_1,int *param_2,int *param_3,int *param_4)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 2;
  iVar2 = 2;
  do {
    iVar2 = (iVar2 + 0x501) * 0x100000;
    *param_2 = iVar2;
    bVar1 = FUN_1001e0f4(iVar2,0);
    if (-1 < (int)((uint)bVar1 << 0x18)) {
      uVar3 = FUN_1001f7c0();
      iVar4 = *param_2;
      iVar2 = FUN_1001e090(iVar4,*(undefined1 *)(param_1 + 4),(int)*(char *)(param_1 + 5));
      if ((-1 < iVar2) && (iVar2 = FUN_1001e030(iVar4,param_1,iVar2), -1 < iVar2)) {
        *param_3 = (int)(char)bVar1;
        *param_4 = iVar2;
      }
      FUN_1001f7d8(uVar3);
      if (-1 < iVar2) {
        return 1;
      }
      FUN_1001e0d8(*param_2,(int)(char)bVar1);
    }
    iVar2 = 1;
    if (iVar5 == 1) {
      *param_2 = 0;
      return 0;
    }
    iVar5 = 1;
  } while( true );
}



/* FUN_1001e354 at 1001e354 */

void FUN_1001e354(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  
  uVar6 = 2;
  uVar1 = FUN_1001da84(6);
  uVar4 = param_1[1];
  param_1[0xc01] = 2;
  uVar2 = param_2 * 0x200;
  uVar3 = uVar2;
  uVar5 = param_2 >> 0x17;
  do {
    if ((uVar5 != 0) || (uVar1 < uVar3)) break;
    uVar6 = uVar6 + 2;
    bVar10 = CARRY4(uVar3,uVar2);
    uVar3 = uVar3 + uVar2;
    uVar5 = (param_2 >> 0x17) + (uint)bVar10;
  } while (uVar6 != 0x100);
  iVar9 = uVar6 * 0xff;
  iVar7 = 0x100;
  do {
    uVar3 = FUN_1001e4d0(uVar1,iVar9);
    iVar8 = iVar7 + -1;
    if (param_2 < uVar3) {
      iVar9 = iVar8;
      iVar8 = iVar7;
      goto LAB_1001e3c0;
    }
    iVar9 = iVar9 - uVar6;
    iVar7 = iVar8;
  } while (iVar8 != 1);
  iVar9 = 0;
LAB_1001e3c0:
  param_1[4] = uVar6;
  param_1[0x400] = (iVar9 << 8 ^ *param_1) & 0xff00;
  param_1[0x801] = uVar4 & 2;
  FUN_1001e4d0(uVar1,iVar8 * uVar6);
  return;
}



/* FUN_1001e3f8 at 1001e3f8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e3f8(uint *param_1)

{
  _DAT_4000e000 = 1 << (0x11 - (param_1 == (uint *)&DAT_4003c000) & 0xff);
  do {
  } while ((_DAT_4000e000 & ~_DAT_4000c008) != 0);
  _DAT_4000f000 = _DAT_4000e000;
  FUN_1001e354(param_1);
  param_1[0xc01] = 2;
  param_1[0x400] = (*param_1 ^ 7) & 0xcf;
  param_1[0x801] = param_1[1] & 2;
  param_1[0x809] = 3;
  param_1[0x801] = 2;
  return;
}



/* FUN_1001e480 at 1001e480 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1001e480(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int extraout_r2;
  ulonglong uVar6;
  
  uVar4 = _DAT_d0000074;
  uVar3 = _DAT_d0000070;
  uVar2 = _DAT_d0000064;
  uVar1 = _DAT_d0000060;
  if ((_DAT_d0000078 >> 1 & 1) != 0) {
    uVar6 = FUN_1001e488();
    *(undefined4 *)(extraout_r2 + 0x60) = uVar1;
    *(undefined4 *)(extraout_r2 + 100) = uVar2;
    *(undefined4 *)(extraout_r2 + 0x74) = uVar4;
    *(undefined4 *)(extraout_r2 + 0x70) = uVar3;
    return uVar6;
  }
  iRamd0000068 = param_1;
  iRamd000006c = param_2;
  if (param_2 != 0) {
    return CONCAT44(_DAT_d0000074,_DAT_d0000070);
  }
  uVar5 = 0;
  if (param_1 != 0) {
    uVar5 = ~(param_1 >> 0x1f ^ 0x80000000U);
  }
  uVar5 = FUN_10027668(uVar5);
  return (ulonglong)uVar5;
}



/* FUN_1001e488 at 1001e488 */

ulonglong FUN_1001e488(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  *(int *)(param_3 + 0x68) = param_1;
  *(int *)(param_3 + 0x6c) = param_2;
  if (param_2 != 0) {
    return *(ulonglong *)(param_3 + 0x70);
  }
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = ~(param_1 >> 0x1f ^ 0x80000000U);
  }
  uVar1 = FUN_10027668(uVar1);
  return (ulonglong)uVar1;
}



/* FUN_1001e4d0 at 1001e4d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1001e4d0(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int extraout_r2;
  ulonglong uVar6;
  
  uVar3 = _DAT_d0000074;
  uVar2 = _DAT_d0000070;
  uVar1 = _DAT_d0000064;
  uVar4 = _DAT_d0000060;
  if ((_DAT_d0000078 >> 1 & 1) != 0) {
    uVar6 = FUN_1001e4d8();
    *(undefined4 *)(extraout_r2 + 0x60) = uVar4;
    *(undefined4 *)(extraout_r2 + 100) = uVar1;
    *(undefined4 *)(extraout_r2 + 0x74) = uVar3;
    *(undefined4 *)(extraout_r2 + 0x70) = uVar2;
    return uVar6;
  }
  _DAT_d0000060 = param_1;
  _DAT_d0000064 = param_2;
  if (param_2 != 0) {
    return CONCAT44(_DAT_d0000074,_DAT_d0000070);
  }
  uVar4 = 0;
  if (param_1 != 0) {
    uVar4 = 0xffffffff;
  }
  uVar5 = FUN_10027668(uVar4);
  return (ulonglong)uVar5;
}



/* FUN_1001e4d8 at 1001e4d8 */

ulonglong FUN_1001e4d8(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  *(int *)(param_3 + 0x60) = param_1;
  *(int *)(param_3 + 100) = param_2;
  if (param_2 != 0) {
    return *(ulonglong *)(param_3 + 0x70);
  }
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = 0xffffffff;
  }
  uVar2 = FUN_10027668(uVar1);
  return (ulonglong)uVar2;
}



/* FUN_1001e54c at 1001e54c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e54c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = _DAT_d0000074;
  uVar3 = _DAT_d0000070;
  uVar2 = _DAT_d0000064;
  uVar1 = _DAT_d0000060;
  if ((_DAT_d0000078 >> 1 & 1) == 0) {
    FUN_1001e604(param_1,param_2,param_3);
    return;
  }
  FUN_1001e604(param_1,param_2,param_3);
  _DAT_d0000060 = uVar1;
  _DAT_d0000064 = uVar2;
  _DAT_d0000074 = uVar4;
  _DAT_d0000070 = uVar3;
  return;
}



/* FUN_1001e604 at 1001e604 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ulonglong FUN_1001e604(uint param_1,uint param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  bool bVar14;
  bool bVar15;
  ulonglong uVar16;
  
  if (param_2 == 0) {
    if (param_4 != 0) {
      return 0;
    }
    if (param_3 != 0) {
      _DAT_d0000060 = param_1;
      _DAT_d0000064 = param_3;
      return (ulonglong)_DAT_d0000070;
    }
    uVar5 = 0;
    uVar1 = 0;
    if (param_1 == 0) goto LAB_1001e632;
  }
  else {
    if (param_4 != 0) {
      if (param_4 >> 0x10 != 0) {
        uVar7 = 0;
        if (param_4 + 1 != 0) {
          uVar7 = _DAT_d0000070;
          _DAT_d0000060 = param_2;
          _DAT_d0000064 = param_4 + 1;
        }
        uVar8 = uVar7 * (param_3 & 0xffff);
        uVar4 = param_1 - uVar8;
        uVar9 = uVar7 * (param_3 >> 0x10);
        uVar8 = (((param_2 - uVar7 * (param_4 & 0xffff)) - (uint)(param_1 < uVar8)) -
                (uVar7 * (param_4 >> 0x10) * 0x10000 | uVar9 >> 0x10)) -
                (uint)(uVar4 < uVar9 * 0x10000);
        for (uVar4 = uVar4 + uVar9 * -0x10000;
            (param_4 <= uVar8 && ((uVar8 != param_4 || (param_3 <= uVar4))));
            uVar4 = uVar4 - param_3) {
          uVar8 = (uVar8 - param_4) - (uint)(uVar4 < param_3);
          uVar7 = uVar7 + 1;
        }
        return (ulonglong)uVar7;
      }
      uVar8 = 0;
      uVar7 = param_3;
      uVar4 = param_4;
      if (param_4 >> 8 == 0) {
        uVar4 = param_4 << 8 | param_3 >> 0x18;
        uVar7 = param_3 << 8;
        uVar8 = 8;
      }
      if (uVar4 >> 0xc == 0) {
        uVar4 = uVar4 << 4 | uVar7 >> 0x1c;
        uVar7 = uVar7 << 4;
        uVar8 = uVar8 + 4;
      }
      if (uVar4 >> 0xe == 0) {
        uVar4 = uVar4 << 2 | uVar7 >> 0x1e;
        uVar7 = uVar7 << 2;
        uVar8 = uVar8 + 2;
      }
      if (uVar4 >> 0xf == 0) {
        bVar14 = CARRY4(uVar7,uVar7);
        uVar7 = uVar7 * 2;
        uVar4 = uVar4 * 2 + (uint)bVar14;
        uVar8 = uVar8 + 1;
      }
      _DAT_d0000064 = uVar4 * 2 + (uint)CARRY4(uVar7,uVar7) + 1;
      _DAT_d0000060 = 0xffffffff;
      uVar9 = _DAT_d0000070 * (param_2 >> 0x10) >> 0x10;
      uVar10 = uVar9 * (uVar7 & 0xffff);
      if (param_1 < uVar10) {
        param_2 = param_2 - 1;
      }
      uVar2 = (param_1 - uVar10) - uVar10;
      if (param_1 - uVar10 < uVar10) {
        param_2 = param_2 - 1;
      }
      uVar11 = uVar9 * (uVar7 >> 0x10);
      uVar10 = uVar2 + uVar11 * -0x20000;
      uVar2 = ((param_2 + uVar9 * (uVar4 & 0xffff) * -2) - (uVar11 >> 0xf)) -
              (uint)(uVar2 < uVar11 * 0x20000);
      uVar11 = _DAT_d0000070 * (uVar2 >> 3) >> 0x10;
      if (uVar8 < 0xc) {
        uVar7 = uVar11 >> (0xc - uVar8 & 0xff);
        iVar13 = (uVar9 << uVar8) * 2;
      }
      else {
        uVar12 = uVar11 * (uVar7 >> 0xc & 0xffff);
        uVar3 = uVar10 - uVar12;
        if (uVar10 < uVar12) {
          uVar2 = uVar2 - 1;
        }
        uVar7 = uVar11 * ((uVar7 >> 0xc | uVar4 << 0x14) >> 0x10);
        uVar10 = uVar3 + uVar7 * -0x10000;
        uVar2 = ((uVar2 - uVar11 * (uVar4 >> 0xc & 0xffff)) - (uVar7 >> 0x10)) -
                (uint)(uVar3 < uVar7 * 0x10000);
        uVar7 = _DAT_d0000070 * (uVar10 >> 0x16 | uVar2 * 0x400) >> (0x29 - uVar8 & 0xff);
        iVar13 = uVar9 * 0x2000 + uVar11 << (uVar8 - 0xc & 0xff);
      }
      uVar9 = uVar7 * (param_3 & 0xffff);
      uVar4 = uVar10 - uVar9;
      uVar11 = uVar7 * (param_3 >> 0x10);
      uVar8 = uVar4 + uVar11 * -0x10000;
      uVar4 = (((uVar2 - uVar7 * (param_4 & 0xffff)) - (uint)(uVar10 < uVar9)) - (uVar11 >> 0x10)) -
              (uint)(uVar4 < uVar11 * 0x10000);
      uVar7 = iVar13 + uVar7;
      do {
        uVar10 = uVar7;
        bVar15 = param_3 <= uVar8;
        uVar8 = uVar8 - param_3;
        uVar9 = uVar4 - param_4;
        bVar14 = param_4 < uVar4;
        uVar4 = (uVar4 - param_4) - (uint)!bVar15;
        uVar7 = uVar10 + 1;
      } while (bVar14 || uVar9 < bVar15);
      return (ulonglong)uVar10;
    }
    if (param_3 >> 0x10 != 0) {
      uVar4 = 0;
      uVar7 = param_3;
      if (param_3 >> 0x18 == 0) {
        uVar7 = param_3 << 8;
        uVar4 = 8;
      }
      if (uVar7 >> 0x1c == 0) {
        uVar7 = uVar7 << 4;
        uVar4 = uVar4 + 4;
      }
      if (uVar7 >> 0x1e == 0) {
        uVar7 = uVar7 << 2;
        uVar4 = uVar4 + 2;
      }
      if (-1 < (int)uVar7) {
        uVar7 = uVar7 << 1;
        uVar4 = uVar4 + 1;
      }
      _DAT_d0000064 = (uVar7 >> 0xf) + 1;
      _DAT_d0000060 = 0xffffffff;
      uVar10 = _DAT_d0000070 * (param_2 >> 0x10) >> 0x10;
      uVar9 = uVar10 * (uVar7 & 0xffff);
      uVar8 = param_1 + uVar9 * -0x20000;
      uVar11 = ((param_2 - (uVar9 >> 0xf)) - (uint)(param_1 < uVar9 * 0x20000)) +
               uVar10 * (uVar7 >> 0x10) * -2;
      uVar12 = _DAT_d0000070 * (uVar11 >> 3) >> 0x10;
      uVar2 = uVar10 * 0x2000 + uVar12;
      uVar3 = uVar12 * (uVar7 & 0xffff);
      uVar9 = uVar8 + uVar3 * -0x10;
      uVar12 = uVar12 * (uVar7 >> 0x10);
      uVar10 = uVar9 + uVar12 * -0x100000;
      iVar13 = (((uVar11 - (uVar3 >> 0x1c)) - (uint)(uVar8 < uVar3 * 0x10)) - (uVar12 >> 0xc)) -
               (uint)(uVar9 < uVar12 * 0x100000);
      uVar8 = _DAT_d0000070 * (uVar10 >> 0x16 | iVar13 * 0x400) >> 0x10;
      if (8 < uVar4) {
        uVar10 = uVar10 - uVar8 * (uVar7 >> 9);
        uVar7 = -uVar4 + 0x16;
        uVar9 = (_DAT_d0000070 * (uVar10 >> 9) >> 0x10) >> (uVar7 & 0xff);
        uVar8 = ((uVar8 << 0xd) >> (uVar7 & 0xff)) + uVar9;
        uVar10 = uVar10 - param_3 * uVar9;
        uVar7 = uVar2 >> (-uVar4 + 0x1c & 0xff);
        uVar2 = uVar2 << uVar4 + 4;
        iVar13 = uVar2 + uVar8;
        if (!CARRY4(uVar2,uVar8)) goto LAB_1001e762;
        do {
          uVar7 = uVar7 + 1;
LAB_1001e762:
          do {
            if (uVar10 < param_3) {
              return CONCAT44(uVar7,iVar13);
            }
            uVar10 = uVar10 - param_3;
            bVar14 = iVar13 != -1;
            iVar13 = iVar13 + 1;
          } while (bVar14);
        } while( true );
      }
      uVar8 = uVar8 >> (-uVar4 + 9 & 0xff);
      uVar9 = uVar8 * (param_3 & 0xffff);
      uVar7 = uVar10 - uVar9;
      if (uVar10 < uVar9) {
        iVar13 = iVar13 + -1;
      }
      uVar9 = uVar8 * (param_3 >> 0x10);
      uVar10 = uVar7 + uVar9 * -0x10000;
      iVar6 = (iVar13 - (uVar9 >> 0x10)) - (uint)(uVar7 < uVar9 * 0x10000);
      uVar7 = uVar2 >> (-uVar4 + 0x1c & 0xff);
      uVar2 = uVar2 << uVar4 + 4;
      iVar13 = uVar2 + uVar8;
      if (CARRY4(uVar2,uVar8)) {
        uVar7 = uVar7 + 1;
      }
      if (iVar6 != 0) {
        do {
          bVar14 = iVar13 == -1;
          iVar13 = iVar13 + 1;
          if (bVar14) {
            uVar7 = uVar7 + 1;
          }
          bVar14 = uVar10 < param_3;
          uVar10 = uVar10 - param_3;
          if ((bVar14) && (iVar6 = iVar6 + -1, iVar6 == 0)) goto LAB_1001e7c6;
        } while( true );
      }
      if (uVar10 < param_3) {
        return CONCAT44(uVar7,iVar13);
      }
      do {
        bVar14 = iVar13 == -1;
        iVar13 = iVar13 + 1;
        if (bVar14) {
          uVar7 = uVar7 + 1;
        }
        uVar10 = uVar10 - param_3;
LAB_1001e7c6:
      } while (param_3 <= uVar10);
      return CONCAT44(uVar7,iVar13);
    }
    if (param_3 != 0) {
      _DAT_d0000060 = _DAT_d0000074 << 0x10 | param_1 & 0xffff;
      _DAT_d0000064 = param_3;
      return CONCAT44(_DAT_d0000070 + (_DAT_d0000070 >> 0x10) +
                      (uint)CARRY4(_DAT_d0000070,_DAT_d0000070 * 0x10000),_DAT_d0000070 * 0x10001);
    }
  }
  uVar1 = 0xffffffff;
  uVar5 = 0xffffffff;
LAB_1001e632:
  uVar16 = FUN_10027628(uVar1,uVar5);
  return uVar16;
}



/* FUN_1001e946 at 1001e946 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e946(void)

{
  return;
}



/* FUN_1001e958 at 1001e958 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e958(void)

{
  return;
}



/* FUN_1001e96a at 1001e96a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e96a(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = _DAT_d0000074;
  uVar3 = _DAT_d0000070;
  uVar2 = _DAT_d0000064;
  uVar1 = _DAT_d0000060;
  if ((_DAT_d0000078 >> 1 & 1) == 0) {
    return;
  }
  FUN_1001e976(param_1,param_2,param_3);
  _DAT_d0000060 = uVar1;
  _DAT_d0000064 = uVar2;
  _DAT_d0000074 = uVar4;
  _DAT_d0000070 = uVar3;
  return;
}



/* FUN_1001e976 at 1001e976 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e976(void)

{
  return;
}



/* FUN_1001e9a6 at 1001e9a6 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001e9a6(void)

{
  return;
}



/* FUN_1001e9c0 at 1001e9c0 */

undefined8 FUN_1001e9c0(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_4 & 0x7fffffff) >> 0x14;
  if (uVar3 == 0) {
LAB_1001e9e2:
    param_3 = 0;
    param_4 = param_4 & 0xfff00000;
  }
  else if (uVar3 == 0x7ff) {
    if ((param_4 & 0x100000) != 0 && (param_4 & 0xfffff) != 0) goto LAB_1001ea0c;
    goto LAB_1001e9e2;
  }
  uVar3 = (param_2 & 0x7fffffff) >> 0x14;
  if (uVar3 == 0) {
LAB_1001e9f6:
    iVar1 = 0;
    uVar2 = param_2 & 0xfff00000;
  }
  else {
    iVar1 = param_1;
    uVar2 = param_2;
    if (uVar3 == 0x7ff) {
      if ((param_2 & 0x100000) != 0 && (param_2 & 0xfffff) != 0) goto LAB_1001ea0c;
      goto LAB_1001e9f6;
    }
  }
  if ((int)(uVar2 ^ param_4) < 0) {
    if ((((uVar2 ^ param_4 | param_4) & 0x7fffffff) != 0 || param_3 != 0) || iVar1 != 0) {
      return CONCAT44(param_2,param_1);
    }
  }
  else if ((-1 < (int)uVar2) && (param_4 == uVar2)) {
    return CONCAT44(param_2,param_1);
  }
LAB_1001ea0c:
  return CONCAT44(param_2,param_1);
}



/* FUN_1001e9d0 at 1001e9d0 */

undefined8 FUN_1001e9d0(int param_1,uint param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_2 & 0x7fffffff) >> 0x14;
  if (uVar3 == 0) {
LAB_1001e9e2:
    iVar1 = 0;
    uVar2 = param_2 & 0xfff00000;
  }
  else {
    iVar1 = param_1;
    uVar2 = param_2;
    if (uVar3 == 0x7ff) {
      if ((param_2 & 0x100000) != 0 && (param_2 & 0xfffff) != 0) goto LAB_1001ea0c;
      goto LAB_1001e9e2;
    }
  }
  uVar3 = (param_4 & 0x7fffffff) >> 0x14;
  if (uVar3 == 0) {
LAB_1001e9f6:
    param_3 = 0;
    param_4 = param_4 & 0xfff00000;
  }
  else if (uVar3 == 0x7ff) {
    if ((param_4 & 0x100000) != 0 && (param_4 & 0xfffff) != 0) goto LAB_1001ea0c;
    goto LAB_1001e9f6;
  }
  if ((int)(param_4 ^ uVar2) < 0) {
    if ((((param_4 ^ uVar2 | uVar2) & 0x7fffffff) != 0 || iVar1 != 0) || param_3 != 0) {
      return CONCAT44(param_2,param_1);
    }
  }
  else if ((-1 < (int)param_4) && (uVar2 == param_4)) {
    return CONCAT44(param_2,param_1);
  }
LAB_1001ea0c:
  return CONCAT44(param_2,param_1);
}



/* FUN_1001ea2c at 1001ea2c */

undefined4 FUN_1001ea2c(void)

{
  char in_ZR;
  
  FUN_1001e9d0();
  if (in_ZR == '\0') {
    return 0;
  }
  return 1;
}



/* FUN_1001ea3c at 1001ea3c */

int FUN_1001ea3c(void)

{
  undefined1 in_CY;
  
  FUN_1001e9d0();
  return -(uint)!(bool)in_CY;
}



/* FUN_1001ea48 at 1001ea48 */

undefined4 FUN_1001ea48(void)

{
  undefined1 in_ZR;
  undefined1 in_CY;
  
  FUN_1001e9d0();
  if ((bool)in_CY && !(bool)in_ZR) {
    return 0;
  }
  return 1;
}



/* FUN_1001ea58 at 1001ea58 */

int FUN_1001ea58(void)

{
  undefined1 in_CY;
  
  FUN_1001e9c0();
  return -(uint)!(bool)in_CY;
}



/* FUN_1001ea62 at 1001ea62 */

undefined4 FUN_1001ea62(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  if (((uint)(param_2 * 2) < 0xffe00001) && ((uint)(param_4 * 2) < 0xffe00001)) {
    return 0;
  }
  return 1;
}



/* FUN_1001ea7c at 1001ea7c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1001ea7c(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = (*_DAT_20002e2c)();
  uVar2 = param_1 << (iVar1 + 1U & 0xff);
  return CONCAT44((0x41f - (iVar1 + 1U)) * 0x100000 | uVar2 >> 0xc,uVar2 << 0x14);
}



/* FUN_1001ea84 at 1001ea84 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong FUN_1001ea84(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = (int)param_1 >> 0x1f;
  iVar1 = (param_1 ^ uVar3) - uVar3;
  if (iVar1 == 0) {
    return (ulonglong)uVar3 << 0x20;
  }
  iVar2 = (*_DAT_20002e2c)();
  uVar4 = iVar1 << (iVar2 + 1U & 0xff);
  return CONCAT44((0x41f - (iVar2 + 1U)) * 0x100000 | uVar3 << 0x1f | uVar4 >> 0xc,uVar4 << 0x14);
}



/* FUN_1001eab4 at 1001eab4 */

int FUN_1001eab4(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = (param_2 & 0x7fffffff) >> 0x14;
  iVar3 = uVar2 - 0x380;
  if (iVar3 < 0x7f) {
    return 0;
  }
  if (0x9d < iVar3) {
    return 0x7fffffff - ((int)param_2 >> 0x1f);
  }
  uVar2 = -(uVar2 - 0x41e);
  uVar1 = ((param_2 & 0xfffff) << 0xb | 0x80000000) >> (uVar2 & 0xff);
  iVar3 = ((int)param_2 >> 0x1f) * 2 + 1;
  uVar2 = uVar2 + 0x15;
  if ((int)uVar2 < 0x20) {
    return iVar3 * (param_1 >> (uVar2 & 0xff) | uVar1);
  }
  return iVar3 * uVar1;
}



/* FUN_1001eafc at 1001eafc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eafc(void)

{
  return;
}



/* FUN_1001eb14 at 1001eb14 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eb14(void)

{
  return;
}



/* FUN_1001eb2c at 1001eb2c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 FUN_1001eb2c(undefined4 param_1,uint param_2)

{
  longlong lVar1;
  
  if (!CARRY4(param_2,param_2)) {
    return CONCAT44(param_2,param_1);
  }
  lVar1 = FUN_1001eb6c(param_1,param_2 & 0x7fffffff,0);
  if (lVar1 < 0) {
    return 0x8000000000000000;
  }
  return CONCAT44(-(uint)((int)lVar1 != 0) - (int)((ulonglong)lVar1 >> 0x20),-(int)lVar1);
}



/* FUN_1001eb6c at 1001eb6c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eb6c(void)

{
  return;
}



/* FUN_1001eb84 at 1001eb84 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001eb84(void)

{
  return;
}



/* FUN_1001f26a at 1001f26a */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f26a(void)

{
                    /* WARNING: Could not recover jumptable at 0x1001f26e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_20002e34)();
  return;
}



/* FUN_1001f270 at 1001f270 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f270(void)

{
                    /* WARNING: Could not recover jumptable at 0x1001f274. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_20002e30)();
  return;
}



/* FUN_1001f276 at 1001f276 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f276(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = _DAT_d0000074;
  uVar3 = _DAT_d0000070;
  uVar2 = _DAT_d0000064;
  uVar1 = _DAT_d0000060;
  if ((_DAT_d0000078 >> 1 & 1) == 0) {
                    /* WARNING: Could not recover jumptable at 0x1001f282. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_DAT_20002e3c)();
    return;
  }
  FUN_1001f27e();
  _DAT_d0000060 = uVar1;
  _DAT_d0000064 = uVar2;
  _DAT_d0000074 = uVar4;
  _DAT_d0000070 = uVar3;
  return;
}



/* FUN_1001f27e at 1001f27e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f27e(void)

{
                    /* WARNING: Could not recover jumptable at 0x1001f282. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_20002e3c)();
  return;
}



/* FUN_1001f29e at 1001f29e */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f29e(void)

{
                    /* WARNING: Could not recover jumptable at 0x1001f2a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_20002e38)();
  return;
}



/* FUN_1001f324 at 1001f324 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001f324(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  code *UNRECOVERED_JUMPTABLE;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = (*_DAT_20002e2c)();
  uVar4 = param_1 << (uVar1 & 0xff);
  iVar3 = -(uVar1 - 0x9e);
  uVar1 = uVar4 + 0x80;
  if (uVar4 < 0xffffff80) {
    if ((uVar1 & 0xff) == 0) {
      uVar1 = (uVar1 >> 9) << 10;
    }
    else {
      uVar1 = uVar1 * 2;
    }
  }
  else {
    iVar3 = iVar3 + 1;
  }
                    /* WARNING: Could not recover jumptable at 0x1001f360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (*UNRECOVERED_JUMPTABLE)(iVar3 << 0x17 | uVar1 >> 9);
  return uVar2;
}



/* FUN_1001f330 at 1001f330 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f330(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  code *UNRECOVERED_JUMPTABLE;
  
  uVar3 = param_1 & 0x80000000;
  if ((int)uVar3 < 0) {
    param_1 = -param_1;
  }
  if (param_1 == 0) {
    return;
  }
  uVar1 = (*_DAT_20002e2c)();
  param_1 = param_1 << (uVar1 & 0xff);
  iVar2 = -(uVar1 - 0x9e);
  uVar1 = param_1 + 0x80;
  if (param_1 < 0xffffff80) {
    if ((uVar1 & 0xff) == 0) {
      uVar1 = (uVar1 >> 9) << 10;
    }
    else {
      uVar1 = uVar1 * 2;
    }
  }
  else {
    iVar2 = iVar2 + 1;
  }
                    /* WARNING: Could not recover jumptable at 0x1001f360. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(iVar2 << 0x17 | uVar3 | uVar1 >> 9);
  return;
}



/* FUN_1001f374 at 1001f374 */

int FUN_1001f374(uint param_1)

{
  uint uVar1;
  
  uVar1 = (param_1 & 0x7fffffff) >> 0x17;
  if (uVar1 < 0x7f) {
    return 0;
  }
  if (uVar1 < 0x9e) {
    return (((int)param_1 >> 0x1f) * 2 + 1) *
           (((param_1 & 0x7fffff) << 8 | 0x80000000) >> (-(uVar1 - 0x9e) & 0xff));
  }
  return 0x7fffffff - ((int)param_1 >> 0x1f);
}



/* FUN_1001f3d8 at 1001f3d8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f3d8(void)

{
                    /* WARNING: Could not recover jumptable at 0x1001f3dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_20002e54)();
  return;
}



/* FUN_1001f484 at 1001f484 */

undefined8 FUN_1001f484(uint param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar4 = (param_3 >> 0x10) * (param_1 & 0xffff);
  uVar1 = (param_3 & 0xffff) * (param_1 & 0xffff);
  uVar3 = (param_1 >> 0x10) * (param_3 & 0xffff);
  uVar6 = uVar4 * 0x10000;
  uVar2 = uVar1 + uVar6;
  uVar5 = uVar3 * 0x10000;
  return CONCAT44((param_1 >> 0x10) * (param_3 >> 0x10) + (uVar4 >> 0x10) +
                  (uint)CARRY4(uVar1,uVar6) + (uVar3 >> 0x10) + (uint)CARRY4(uVar2,uVar5) +
                  param_3 * param_2 + param_1 * param_4,uVar2 + uVar5);
}



/* FUN_1001f4c8 at 1001f4c8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f4c8(void)

{
                    /* WARNING: Could not recover jumptable at 0x1001f4cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_200009d0)();
  return;
}



/* FUN_1001f4d4 at 1001f4d4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f4d4(void)

{
                    /* WARNING: Could not recover jumptable at 0x1001f4d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_200009d4)();
  return;
}



/* FUN_1001f4e0 at 1001f4e0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001f4e0(void)

{
  while ((_DAT_d0000050 & 1) == 0) {
    WaitForEvent();
  }
  return _DAT_d0000058;
}



/* FUN_1001f502 at 1001f502 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f502(undefined4 param_1)

{
  do {
  } while ((_DAT_d0000050 & 2) == 0);
  _DAT_d0000054 = param_1;
  return;
}



/* FUN_1001f514 at 1001f514 */

void FUN_1001f514(void)

{
  FUN_1001f502();
  return;
}



/* FUN_1001f524 at 1001f524 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f524(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_30 [7];
  
  uVar1 = FUN_1001cf90(0xf);
  FUN_1001cf68(0xf,0);
  local_30[4] = param_2;
  local_30[5] = param_1;
  iVar3 = 0;
  local_30[0] = 0;
  local_30[1] = 0;
  local_30[2] = 1;
  local_30[3] = param_3;
  do {
    while( true ) {
      iVar4 = local_30[iVar3];
      if (iVar4 == 0) {
        do {
        } while ((_DAT_d0000050 & 1) != 0);
      }
      FUN_1001f502(iVar4);
      iVar2 = FUN_1001f4e0();
      if (iVar4 == iVar2) break;
      iVar3 = 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 != 6);
  FUN_1001cf68(0xf,uVar1);
  return;
}



/* FUN_1001f590 at 1001f590 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f590(undefined4 param_1,int param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = _DAT_e000ed08;
  iVar2 = param_2 + (param_3 & 0xfffffffc);
  *(undefined4 *)(iVar2 + -0xc) = param_1;
  *(int *)(iVar2 + -8) = param_2;
  *(undefined1 **)(iVar2 + -4) = &LAB_1001f4f6_1;
  FUN_1001f524(&DAT_1001f4f5,(undefined4 *)(iVar2 + -0xc),uVar1);
  return;
}



/* FUN_1001f5c4 at 1001f5c4 */

/* WARNING: Removing unreachable block (ram,0x1001f5ce) */

void FUN_1001f5c4(undefined4 param_1)

{
  FUN_1001f590(param_1,0x20040800,0x800);
  return;
}



/* FUN_1001f5e4 at 1001f5e4 */

void FUN_1001f5e4(void)

{
  FUN_1001dce4(0x20004113);
  return;
}



/* FUN_1001f604 at 1001f604 */

void FUN_1001f604(void)

{
  return;
}



/* FUN_1001f608 at 1001f608 */

void FUN_1001f608(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_1001ce0c("Hard assert");
}



/* FUN_1001f614 at 1001f614 */

void FUN_1001f614(void)

{
  undefined **ppuVar1;
  
  for (ppuVar1 = &PTR_FUN_1001f64c_1_10027748; ppuVar1 < &PTR_FUN_100031e8_1_10027784;
      ppuVar1 = ppuVar1 + 1) {
    (*(code *)*ppuVar1)();
  }
  return;
}



/* FUN_1001f630 at 1001f630 */

void FUN_1001f630(void)

{
  undefined **ppuVar1;
  
  for (ppuVar1 = (undefined **)&DAT_1002777c; ppuVar1 < &PTR_FUN_100031e8_1_10027784;
      ppuVar1 = ppuVar1 + 1) {
    (*(code *)*ppuVar1)();
  }
  return;
}



/* FUN_1001f64c at 1001f64c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f64c(void)

{
  _DAT_4000e000 = 0xfefbcdbf;
  _DAT_4000f000 = 0x3c7ffe;
  do {
  } while ((~_DAT_4000c008 & 0x3c7ffe) != 0);
  return;
}



/* FUN_1001f6d0 at 1001f6d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f6d0(void)

{
  FUN_1001f4d4(0x20000000,_DAT_e000ed08,0xc0);
  _DAT_e000ed08 = 0x20000000;
  return;
}



/* FUN_1001f7c0 at 1001f7c0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001f7c0(void)

{
  bool bVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (_DAT_d000012c == 0);
  DataMemoryBarrier(0x1f);
  return uVar2;
}



/* FUN_1001f7d8 at 1001f7d8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f7d8(uint param_1)

{
  bool bVar1;
  
  DataMemoryBarrier(0x1f);
  _DAT_d000012c = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((param_1 & 1) == 1);
  }
  return;
}



/* FUN_1001f7ec at 1001f7ec */

bool FUN_1001f7ec(int param_1,uint param_2)

{
  return (1 << (param_2 & 7) & (uint)*(byte *)(param_1 + (param_2 >> 3))) != 0;
}



/* FUN_1001f802 at 1001f802 */

void FUN_1001f802(int param_1,uint param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_1001f7c0();
  iVar2 = FUN_1001f7ec(param_1,param_2);
  if (iVar2 != 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1001ce0c(param_3,param_2);
  }
  *(byte *)(param_1 + (param_2 >> 3)) =
       (byte)(1 << (param_2 & 7)) | *(byte *)(param_1 + (param_2 >> 3));
  FUN_1001f7d8(uVar1);
  return;
}



/* FUN_1001f83c at 1001f83c */

undefined8 FUN_1001f83c(int param_1,int param_2,uint param_3,uint param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_1001f7c0();
  do {
    if (param_4 < param_3) {
      param_3 = 0xffffffff;
LAB_1001f872:
      FUN_1001f7d8(uVar1);
      if (((int)param_3 < 0) && (param_2 != 0)) {
                    /* WARNING: Subroutine does not return */
        FUN_1001ce0c(param_5);
      }
      return CONCAT44(param_1,param_3);
    }
    iVar2 = FUN_1001f7ec(param_1,param_3);
    if (iVar2 == 0) {
      *(byte *)(param_1 + (param_3 >> 3)) =
           (byte)(1 << (param_3 & 7)) | *(byte *)(param_1 + (param_3 >> 3));
      goto LAB_1001f872;
    }
    param_3 = param_3 + 1;
  } while( true );
}



/* FUN_1001f88e at 1001f88e */

void FUN_1001f88e(int param_1,uint param_2)

{
  FUN_1001f7c0();
  *(byte *)(param_1 + (param_2 >> 3)) =
       *(byte *)(param_1 + (param_2 >> 3)) & ~(byte)(1 << (param_2 & 7));
  FUN_1001f7d8();
  return;
}



/* FUN_1001f8b0 at 1001f8b0 */

void FUN_1001f8b0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)&DAT_d0000100;
  do {
    DataMemoryBarrier(0x1f);
    *puVar1 = 0;
    puVar1 = puVar1 + 1;
  } while (puVar1 != (undefined4 *)0xd0000180);
  return;
}



/* FUN_1001f8cc at 1001f8cc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f8cc(undefined4 param_1,uint param_2)

{
  _DAT_4005802c = param_2 | 0x200;
  return;
}



/* FUN_1001f8dc at 1001f8dc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1001f8dc(void)

{
  _DAT_40024000 = 0xaa0;
  _DAT_4002400c = 0xbc0;
  _DAT_40026000 = 0xfab000;
  do {
  } while (-1 < _DAT_40024004);
  return;
}



/* FUN_1001f904 at 1001f904 */

void FUN_1001f904(void)

{
  FUN_1001faf4();
  return;
}



/* FUN_1001f90c at 1001f90c */

void FUN_1001f90c(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  while( true ) {
    iVar1 = FUN_1001c78c(param_1);
    if (iVar1 != 0) {
      return;
    }
    pcVar2 = (code *)FUN_1001fafc();
    if (pcVar2 == (code *)0x0) break;
    (*pcVar2)();
  }
                    /* WARNING: Subroutine does not return */
  FUN_10021d94();
}



/* FUN_1001f930 at 1001f930 */

void FUN_1001f930(void)

{
  FUN_1001f90c();
  return;
}



/* FUN_1001f938 at 1001f938 */

int FUN_1001f938(char *param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  if ((*param_1 == '\0') && (param_1 == *(char **)(*(int *)(param_1 + 4) + 4))) {
    iVar1 = *(int *)(param_1 + 0xc);
  }
  else {
    iVar2 = *(int *)(param_1 + 8);
    if (*(int *)(param_1 + 8) == 0) {
      iVar1 = *(int *)(param_1 + 4);
      iVar2 = iVar1;
      if (param_1 == *(char **)(iVar1 + 8)) {
        do {
          iVar1 = *(int *)(iVar2 + 4);
          bVar3 = *(int *)(iVar1 + 8) == iVar2;
          iVar2 = iVar1;
        } while (bVar3);
      }
    }
    else {
      do {
        iVar1 = iVar2;
        iVar2 = *(int *)(iVar1 + 0xc);
      } while (*(int *)(iVar1 + 0xc) != 0);
    }
  }
  return iVar1;
}



/* FUN_1001f970 at 1001f970 */

void FUN_1001f970(int param_1,char *param_2,int param_3,int param_4)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  
  *(int *)(param_2 + 4) = param_3;
  param_2[8] = '\0';
  param_2[9] = '\0';
  param_2[10] = '\0';
  param_2[0xb] = '\0';
  param_2[0xc] = '\0';
  param_2[0xd] = '\0';
  param_2[0xe] = '\0';
  param_2[0xf] = '\0';
  *param_2 = '\0';
  if (param_1 == 0) {
    *(char **)(param_3 + 0xc) = param_2;
    if (*(int *)(param_4 + 0xc) == param_3) {
      *(char **)(param_4 + 0xc) = param_2;
    }
    pcVar6 = *(char **)(param_4 + 4);
  }
  else {
    *(char **)(param_3 + 8) = param_2;
    if (param_4 == param_3) {
      *(char **)(param_4 + 4) = param_2;
      *(char **)(param_4 + 0xc) = param_2;
      pcVar6 = param_2;
      goto LAB_1001fa2e;
    }
    pcVar6 = *(char **)(param_4 + 4);
    if (*(int *)(param_4 + 8) == param_3) {
      *(char **)(param_4 + 8) = param_2;
    }
  }
  if (param_2 != pcVar6) {
    do {
      while( true ) {
        pcVar1 = *(char **)(param_2 + 4);
        if (*pcVar1 != '\0') goto LAB_1001fa2e;
        pcVar3 = *(char **)(pcVar1 + 4);
        pcVar4 = *(char **)(pcVar3 + 8);
        if (pcVar4 != pcVar1) break;
        pcVar7 = *(char **)(pcVar3 + 0xc);
        if ((pcVar7 == (char *)0x0) || (*pcVar7 != '\0')) {
          pcVar6 = pcVar1;
          if (*(char **)(pcVar1 + 0xc) == param_2) {
            iVar2 = *(int *)(param_2 + 8);
            *(int *)(pcVar1 + 0xc) = iVar2;
            if (iVar2 == 0) {
              *(char **)(param_2 + 4) = pcVar3;
              if (pcVar1 == *(char **)(param_4 + 4)) goto LAB_1001faf0;
              pcVar6 = pcVar3;
LAB_1001fae8:
              *(char **)(pcVar6 + 8) = param_2;
            }
            else {
              *(char **)(iVar2 + 4) = pcVar1;
              pcVar6 = *(char **)(pcVar1 + 4);
              *(char **)(param_2 + 4) = pcVar6;
              if (pcVar1 == *(char **)(param_4 + 4)) {
LAB_1001faf0:
                *(char **)(param_4 + 4) = param_2;
              }
              else {
                if (pcVar1 == *(char **)(pcVar6 + 8)) goto LAB_1001fae8;
                *(char **)(pcVar6 + 0xc) = param_2;
              }
            }
            *(char **)(param_2 + 8) = pcVar1;
            pcVar4 = *(char **)(pcVar3 + 8);
            *(char **)(pcVar1 + 4) = param_2;
            pcVar6 = param_2;
            param_2 = pcVar1;
          }
          *pcVar6 = '\x01';
          *pcVar3 = '\0';
          iVar2 = *(int *)(pcVar4 + 0xc);
          *(int *)(pcVar3 + 8) = iVar2;
          if (iVar2 != 0) {
            *(char **)(iVar2 + 4) = pcVar3;
          }
          iVar2 = *(int *)(pcVar3 + 4);
          *(int *)(pcVar4 + 4) = iVar2;
          if (pcVar3 == *(char **)(param_4 + 4)) {
            *(char **)(param_4 + 4) = pcVar4;
          }
          else if (pcVar3 == *(char **)(iVar2 + 0xc)) {
            *(char **)(iVar2 + 0xc) = pcVar4;
          }
          else {
            *(char **)(iVar2 + 8) = pcVar4;
          }
          *(char **)(pcVar4 + 0xc) = pcVar3;
          *(char **)(pcVar3 + 4) = pcVar4;
          pcVar6 = *(char **)(param_4 + 4);
        }
        else {
          *pcVar4 = '\x01';
          *pcVar7 = '\x01';
LAB_1001f9c4:
          *pcVar3 = '\0';
          param_2 = pcVar3;
        }
        if (pcVar6 == param_2) goto LAB_1001fa2e;
      }
      if ((pcVar4 != (char *)0x0) && (*pcVar4 == '\0')) {
        *pcVar1 = '\x01';
        *pcVar4 = '\x01';
        goto LAB_1001f9c4;
      }
      pcVar6 = pcVar1;
      if (*(char **)(pcVar1 + 8) == param_2) {
        iVar2 = *(int *)(param_2 + 0xc);
        *(int *)(pcVar1 + 8) = iVar2;
        pcVar6 = pcVar3;
        if (iVar2 != 0) {
          *(char **)(iVar2 + 4) = pcVar1;
          pcVar6 = *(char **)(pcVar1 + 4);
        }
        *(char **)(param_2 + 4) = pcVar6;
        if (pcVar1 == *(char **)(param_4 + 4)) {
          *(char **)(param_4 + 4) = param_2;
        }
        else if (pcVar1 == *(char **)(pcVar6 + 0xc)) {
          *(char **)(pcVar6 + 0xc) = param_2;
        }
        else {
          *(char **)(pcVar6 + 8) = param_2;
        }
        *(char **)(param_2 + 0xc) = pcVar1;
        *(char **)(pcVar1 + 4) = param_2;
        pcVar6 = param_2;
        param_2 = pcVar1;
      }
      *pcVar6 = '\x01';
      *pcVar3 = '\0';
      iVar2 = *(int *)(pcVar3 + 0xc);
      iVar5 = *(int *)(iVar2 + 8);
      *(int *)(pcVar3 + 0xc) = iVar5;
      if (iVar5 != 0) {
        *(char **)(iVar5 + 4) = pcVar3;
      }
      iVar5 = *(int *)(pcVar3 + 4);
      *(int *)(iVar2 + 4) = iVar5;
      if (pcVar3 == *(char **)(param_4 + 4)) {
        *(int *)(param_4 + 4) = iVar2;
      }
      else if (pcVar3 == *(char **)(iVar5 + 8)) {
        *(int *)(iVar5 + 8) = iVar2;
      }
      else {
        *(int *)(iVar5 + 0xc) = iVar2;
      }
      *(char **)(iVar2 + 8) = pcVar3;
      *(int *)(pcVar3 + 4) = iVar2;
      pcVar6 = *(char **)(param_4 + 4);
    } while (pcVar6 != param_2);
  }
LAB_1001fa2e:
  *pcVar6 = '\x01';
  return;
}



/* FUN_1001faf4 at 1001faf4 */

void FUN_1001faf4(void)

{
  FUN_1001c7dc();
  return;
}



/* FUN_1001fafc at 1001fafc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1001fafc(void)

{
  return _DAT_2000174c;
}



/* FUN_1001fb68 at 1001fb68 */

uint FUN_1001fb68(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  longlong lVar4;
  
  iVar1 = FUN_1001c744();
  puVar3 = *(undefined4 **)(iVar1 + 0x30);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)FUN_1001c78c(0x18);
    *(undefined4 **)(iVar1 + 0x30) = puVar3;
    if (puVar3 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/rand.c",0x52,0,"REENT malloc succeeded")
      ;
    }
    *puVar3 = 0xabcd330e;
    puVar3[1] = 0xe66d1234;
    puVar3[2] = 0x5deec;
    *(undefined2 *)(puVar3 + 3) = 0xb;
    puVar3[4] = 1;
    puVar3[5] = 0;
    uVar2 = 0x5851f42d;
    lVar4 = 0x5851f42d4c957f2e;
  }
  else {
    lVar4 = FUN_1001f484(puVar3[4],puVar3[5],0x4c957f2d,0x5851f42d);
    lVar4 = lVar4 + 1;
    uVar2 = (uint)((ulonglong)lVar4 >> 0x20) & 0x7fffffff;
  }
  *(longlong *)(puVar3 + 4) = lVar4;
  return uVar2;
}



/* FUN_1001fbec at 1001fbec */

void FUN_1001fbec(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = FUN_1001c744();
  if (param_3 == (char *)0x0) {
    pcVar2 = "";
    param_3 = "";
  }
  else {
    pcVar2 = ", function: ";
  }
  FUN_10024838(*(undefined4 *)(iVar1 + 0xc),"assertion \"%s\" failed: file \"%s\", line %d%s%s\n",
               param_4,param_1,param_2,pcVar2,param_3);
                    /* WARNING: Subroutine does not return */
  FUN_10021d94();
}



/* FUN_1001fcc0 at 1001fcc0 */

void FUN_1001fcc0(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined8 uVar2;
  
  uVar2 = FUN_1002628c();
  if ((param_3 != 0) && (iVar1 = 0x6b - ((param_2 & 0x7fffffff) >> 0x14), 0 < iVar1)) {
    FUN_1001e9a6((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),0,iVar1 * 0x100000 + 0x3ff00000);
  }
  return;
}



/* FUN_1001fcf0 at 1001fcf0 */

/* WARNING: Control flow encountered bad instruction data */

longlong FUN_1001fcf0(undefined4 *param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  ulonglong uVar5;
  undefined4 uVar6;
  int iVar7;
  byte *pbVar8;
  int iVar9;
  byte *pbVar10;
  uint extraout_r1;
  undefined4 uVar11;
  undefined4 extraout_r1_00;
  byte *extraout_r1_01;
  undefined4 *puVar12;
  uint extraout_r1_02;
  uint extraout_r1_03;
  uint uVar13;
  int iVar14;
  undefined4 *puVar15;
  undefined4 *extraout_r2;
  int extraout_r2_00;
  uint uVar16;
  uint uVar17;
  int iVar18;
  uint uVar19;
  uint uVar20;
  undefined4 *puVar21;
  byte *pbVar22;
  uint uVar23;
  byte *pbVar24;
  byte *unaff_r9;
  int iVar25;
  byte *pbVar26;
  int iVar27;
  byte *extraout_r12;
  char cVar28;
  undefined8 uVar29;
  longlong lVar30;
  undefined8 uVar31;
  ulonglong uVar32;
  int local_90;
  uint local_8c;
  byte *local_80;
  byte *local_7c;
  uint local_78;
  uint local_74;
  undefined4 uStack_60;
  int iStack_5c;
  int local_58;
  byte *local_3c;
  int local_38;
  int iStack_34;
  int aiStack_30 [3];
  
  local_38 = 0;
  local_90 = 0;
  local_8c = 0;
  uVar32 = 0;
  pbVar22 = param_2;
LAB_1001fd12:
  uVar13 = (uint)*pbVar22;
  switch(uVar13) {
  case 0:
    goto code_r0x1001fe9e;
  default:
    bVar2 = false;
    local_3c = pbVar22;
    goto LAB_1001fd28;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0x20:
    goto switchD_1001fd22_caseD_9;
  case 0x2b:
    bVar2 = false;
    break;
  case 0x2d:
    bVar2 = true;
  }
  local_3c = pbVar22 + 1;
  uVar13 = (uint)pbVar22[1];
  if (uVar13 == 0) {
    lVar30 = switchD_1001fd22::caseD_0();
    return lVar30;
  }
LAB_1001fd28:
  local_80 = (byte *)0x0;
  if (uVar13 == 0x30) {
    pbVar22 = local_3c + 1;
    if ((local_3c[1] & 0xdf) == 0x58) {
      FUN_100206c6();
    }
    do {
      local_3c = pbVar22;
      uVar13 = (uint)*local_3c;
      pbVar22 = local_3c + 1;
    } while (uVar13 == 0x30);
    if (uVar13 == 0) {
LAB_10020264:
      uVar13 = 0;
      if (param_3 != (undefined4 *)0x0) {
        *param_3 = local_3c;
      }
      if (bVar2) {
        uVar13 = 0x80000000;
      }
      goto LAB_1001feaa;
    }
    local_80 = (byte *)0x1;
  }
  pbVar22 = local_3c;
  if (uVar13 < 0x30) {
    uVar29 = FUN_100225e0(local_3c,&DAT_1002acc4,1);
    if ((int)uVar29 != 0) {
      if (local_80 == (byte *)0x0) {
        lVar30 = switchD_1001fd22::caseD_0();
        return lVar30;
      }
      goto LAB_10020264;
    }
    pbVar24 = local_3c + 1;
    pbVar8 = local_3c + 1;
    pbVar26 = (byte *)0x0;
    local_3c = pbVar24;
    FUN_1001fe6a(0,(int)((ulonglong)uVar29 >> 0x20),*pbVar8);
    FUN_10020148();
    uVar16 = extraout_r1_03;
LAB_1002098e:
    local_8c = (uint)(uVar32 >> 0x20);
    local_90 = (int)uVar32;
    uVar32 = FUN_1001e96a(local_90,local_8c,*(undefined4 *)(&DAT_1002b358 + uVar16 * 8),
                          *(undefined4 *)(&DAT_1002b35c + uVar16 * 8));
    if (pbVar24 == (byte *)0x0) {
      FUN_1001ff8a();
    }
LAB_10020452:
    if (0x1f < (int)pbVar24) {
LAB_1002055a:
      *param_1 = 0x22;
      lVar30 = FUN_10020268();
      return lVar30;
    }
    local_7c = (byte *)((uint)pbVar24 & 0x10);
    if (((uint)pbVar24 & 0x10) != 0) {
      local_7c = (byte *)0x6a;
    }
    puVar21 = &DAT_1002aef8;
    while( true ) {
      while( true ) {
        uVar13 = (uint)pbVar24 & 1;
        pbVar24 = (byte *)((int)pbVar24 >> 1);
        if (uVar13 != 0) break;
        puVar21 = puVar21 + 2;
      }
      uVar32 = FUN_1001e9a6((int)uVar32,(int)(uVar32 >> 0x20),*puVar21,puVar21[1]);
      uVar13 = (uint)(uVar32 >> 0x20);
      if (pbVar24 == (byte *)0x0) break;
      puVar21 = puVar21 + 2;
    }
    if (local_7c != (byte *)0x0) {
      uVar16 = (uVar13 & 0x7fffffff) >> 0x14;
      uVar19 = 0x6b - uVar16;
      if (0 < (int)uVar19) {
        if ((int)uVar19 < 0x20) {
          uVar32 = CONCAT44(uVar13,(uint)uVar32 & -1 << (uVar19 & 0xff));
        }
        else if ((int)uVar19 < 0x35) {
          uVar32 = (ulonglong)(uVar13 & -1 << (0x4b - uVar16 & 0xff)) << 0x20;
        }
        else {
          uVar32 = 0x370000000000000;
        }
      }
    }
    local_8c = (uint)(uVar32 >> 0x20);
    local_90 = (int)uVar32;
    iVar9 = FUN_1001ea2c(local_90,local_8c,0,0);
    if (iVar9 != 0) goto LAB_1002055a;
  }
  else {
    pbVar26 = (byte *)0x0;
    puVar21 = (undefined4 *)0x0;
    pbVar24 = (byte *)0x0;
    pbVar8 = local_3c;
    do {
      local_3c = pbVar8;
      pbVar10 = pbVar24;
      if (0x39 < uVar13) {
        iVar9 = FUN_100225e0(local_3c,&DAT_1002acc4,1);
        if (iVar9 == 0) {
          pbVar24 = local_3c + 1;
          uVar13 = (uint)local_3c[1];
          local_3c = pbVar24;
          if (pbVar10 != (byte *)0x0) goto LAB_10020230;
          pbVar8 = (byte *)0x0;
          if (uVar13 == 0x30) {
            do {
              pbVar8 = local_3c;
              local_3c = pbVar8 + 1;
              uVar13 = (uint)*local_3c;
            } while (uVar13 == 0x30);
            pbVar8 = pbVar8 + (1 - (int)pbVar24);
          }
          if (uVar13 - 0x31 < 9) {
            puVar15 = (undefined4 *)(uVar13 - 0x30);
            pbVar24 = (byte *)0x1;
            pbVar22 = local_3c;
            do {
              puVar12 = puVar21;
              pbVar8 = (byte *)((int)puVar15 + (int)pbVar26 * 10);
              local_3c = pbVar22 + 1;
              lVar30 = ZEXT48(local_3c) << 0x20;
              puVar15 = (undefined4 *)(*local_3c - 0x30);
              if (puVar15 < (undefined4 *)0xa) {
                iVar9 = 1;
                if (puVar15 == (undefined4 *)0x0) {
                  lVar30 = FUN_10020caa();
                  iVar9 = extraout_r2_00;
                }
                if (iVar9 == 1) {
                  lVar30 = FUN_10020ca6();
                }
                pbVar10 = pbVar24 + 1;
                pbVar22 = pbVar10;
                pbVar26 = pbVar8;
                do {
                  if ((int)(pbVar22 + -1) < 9) {
                    pbVar26 = (byte *)((int)pbVar26 * 10);
                  }
                  else if ((int)pbVar22 < 0x11) {
                    puVar12 = (undefined4 *)((int)puVar12 * 10);
                  }
                  pbVar22 = pbVar22 + 1;
                } while ((int)(pbVar22 + (-1 - (int)pbVar24)) < (int)lVar30);
              }
              else {
                uVar32 = FUN_1001feee(0,local_3c,1);
                if ((int)uVar32 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
                  halt_baddata();
                }
                puVar15 = &DAT_1002b330;
                bVar2 = false;
                uVar32 = uVar32 & 0xffffffff00000000;
                puVar21 = puVar12;
                do {
                  if (((uint)param_2 & 1) != 0) {
                    uVar32 = FUN_1001e9a6((int)uVar32,(int)(uVar32 >> 0x20),*puVar15,puVar15[1]);
                    bVar2 = true;
                  }
                  puVar21 = (undefined4 *)((int)puVar21 + 1);
                  param_2 = (byte *)((int)param_2 >> 1);
                  puVar15 = puVar15 + 2;
                } while (param_2 != (byte *)0x1);
                uVar5 = CONCAT44(local_8c,local_90);
                if (bVar2) {
                  uVar5 = uVar32;
                }
                local_8c = (uint)(uVar5 >> 0x20);
                local_90 = (int)uVar5;
                FUN_1001e9a6((&DAT_1002b330)[(int)puVar21 * 2],(&DAT_1002b334)[(int)puVar21 * 2],
                             local_90,local_8c + -0x3500000);
                if (0x7ca00000 < (extraout_r1_02 & 0x7ff00000)) {
                  *param_1 = 0x22;
                  goto LAB_1002050a;
                }
                if ((extraout_r1_02 & 0x7ff00000) < 0x7c900001) {
                  FUN_1001ff8a();
                }
                pbVar26 = (byte *)0x7fefffff;
                local_90 = 0xffffffff;
                local_8c = 0x7fefffff;
                uVar29 = FUN_1001ff8a();
                puVar12 = (undefined4 *)((ulonglong)uVar29 >> 0x20);
                lVar30 = CONCAT44(puVar21,(int)uVar29);
                param_2 = pbVar8;
                pbVar10 = extraout_r12;
              }
              pbVar22 = (byte *)((ulonglong)lVar30 >> 0x20);
              pbVar10 = pbVar10 + (int)lVar30 + -1;
              puVar21 = puVar12;
LAB_10020878:
              pbVar24 = pbVar10 + 1;
              if (8 < (int)pbVar10) {
                if ((int)pbVar24 < 0x11) {
                  lVar30 = FUN_1002037c(0,pbVar22,puVar12,(int)puVar21 * 10);
                  return lVar30;
                }
                lVar30 = FUN_1002037c(0);
                return lVar30;
              }
            } while( true );
          }
          if ((uVar13 & 0xffffffdf) == 0x45) {
            local_7c = (byte *)0x0;
            bVar3 = true;
            pbVar10 = pbVar8;
            goto LAB_1002029e;
          }
          if (local_80 != (byte *)0x0 || pbVar8 != (byte *)0x0) goto LAB_10020264;
          goto code_r0x1001fe9e;
        }
        pbVar8 = (byte *)0x0;
        bVar3 = false;
        local_7c = pbVar10;
        if (uVar13 == 0x65) goto LAB_1002029e;
        local_74 = 0;
        if (uVar13 == 0x45) goto LAB_1002029e;
        goto LAB_1001fefe;
      }
      if ((int)pbVar10 < 9) {
        bVar1 = local_3c[1];
        pbVar26 = (byte *)((int)pbVar26 * 10 + uVar13 + -0x30);
      }
      else {
        bVar1 = local_3c[1];
        puVar21 = (undefined4 *)((int)puVar21 * 10 + uVar13 + -0x30);
      }
      uVar13 = (uint)bVar1;
      pbVar24 = pbVar10 + 1;
      pbVar8 = local_3c + 1;
    } while (0x2f < uVar13);
    pbVar10 = pbVar10 + 1;
    local_3c = local_3c + 1;
    iVar9 = FUN_100225e0(local_3c,&DAT_1002acc4,1);
    if (iVar9 == 0) {
      uVar13 = (uint)local_3c[1];
      local_3c = local_3c + 1;
LAB_10020230:
      puVar15 = (undefined4 *)(uVar13 - 0x30);
      if (puVar15 < (undefined4 *)0xa) {
        pbVar22 = local_3c;
        puVar12 = puVar15;
        if (puVar15 == (undefined4 *)0x0) {
          FUN_10020cb0();
          pbVar22 = extraout_r1_01;
          puVar12 = extraout_r2;
        }
        goto LAB_10020878;
      }
      if ((uVar13 & 0xffffffdf) == 0x45) {
        pbVar8 = (byte *)0x0;
        bVar3 = true;
        param_2 = local_3c;
        local_7c = pbVar10;
        goto LAB_100202a8;
      }
      uVar32 = FUN_1001ea7c(pbVar26);
      if ((int)pbVar10 < 10) {
        lVar30 = FUN_100206c0();
        return lVar30;
      }
      pbVar24 = pbVar10;
      if (0x10 < (int)pbVar10) {
        pbVar24 = (byte *)0x10;
      }
      local_74 = 0;
      local_80 = pbVar10;
LAB_1001fdb6:
      uVar29 = FUN_1001e9a6((int)uVar32,(int)(uVar32 >> 0x20),
                            *(undefined4 *)(&DAT_1002b358 + (int)(pbVar24 + -9) * 8),
                            *(undefined4 *)(&DAT_1002b35c + (int)(pbVar24 + -9) * 8));
      uVar31 = FUN_1001ea7c(puVar21);
      uVar32 = FUN_1001e958((int)uVar29,(int)((ulonglong)uVar29 >> 0x20),(int)uVar31,
                            (int)((ulonglong)uVar31 >> 0x20));
      if ((int)local_80 < 0x10) goto LAB_1001fdea;
    }
    else {
      local_74 = 0;
      local_80 = pbVar10;
LAB_1001fd9c:
      pbVar24 = local_80;
      if (0x10 < (int)local_80) {
        pbVar24 = (byte *)0x10;
      }
      uVar32 = FUN_1001ea7c(pbVar26);
      if (9 < (int)local_80) goto LAB_1001fdb6;
LAB_1001fdea:
      local_8c = (uint)(uVar32 >> 0x20);
      local_90 = (int)uVar32;
      if (local_74 == 0) {
        FUN_100206c0();
      }
      if ((int)local_74 < 1) {
        if (-0x17 < (int)local_74) {
          FUN_1001e96a(local_90,local_8c,*(undefined4 *)(&DAT_1002b358 + local_74 * -8),
                       *(undefined4 *)(&DAT_1002b35c + local_74 * -8));
          lVar30 = FUN_10020268();
          return lVar30;
        }
      }
      else {
        if ((int)local_74 < 0x17) {
          FUN_100208c2();
        }
        if ((int)local_74 <= 0x25 - (int)local_80) {
          iVar9 = (0xf - (int)local_80) * 8;
          uVar29 = FUN_1001e9a6(*(undefined4 *)(&DAT_1002b358 + iVar9),
                                *(undefined4 *)(&DAT_1002b35c + iVar9),local_90,local_8c);
          iVar9 = (local_74 - (0xf - (int)local_80)) * 8;
          FUN_1001e9a6((int)uVar29,(int)((ulonglong)uVar29 >> 0x20),
                       *(undefined4 *)(&DAT_1002b358 + iVar9),*(undefined4 *)(&DAT_1002b35c + iVar9)
                      );
          lVar30 = FUN_10020268();
          return lVar30;
        }
      }
    }
    local_8c = (uint)(uVar32 >> 0x20);
    local_90 = (int)uVar32;
    local_58 = 0;
    pbVar24 = local_80 + (local_74 - (int)pbVar24);
    unaff_r9 = local_80;
    local_78 = local_74;
    if ((int)pbVar24 < 1) {
      if (pbVar24 == (byte *)0x0) {
        lVar30 = FUN_1001ff8a();
        return lVar30;
      }
      uVar13 = -(int)pbVar24;
      uVar16 = uVar13 & 0xf;
      pbVar24 = (byte *)((int)uVar13 >> 4);
      if ((uVar13 & 0xf) != 0) goto LAB_1002098e;
      goto LAB_10020452;
    }
    uVar13 = (uint)pbVar24 & 0xf;
    if (((uint)pbVar24 & 0xf) == 0) {
      FUN_100207c4();
      uVar13 = extraout_r1;
    }
    uVar32 = FUN_1001e9a6(*(undefined4 *)(&DAT_1002b358 + uVar13 * 8),
                          *(undefined4 *)(&DAT_1002b35c + uVar13 * 8),local_90,local_8c);
    if (((uint)pbVar24 & 0xfffffff0) != 0) {
      FUN_100207c4();
    }
    local_7c = (byte *)0x0;
  }
  iVar9 = FUN_10025b2c(param_1,pbVar22,unaff_r9,local_80,pbVar26);
  if (iVar9 == 0) {
    FUN_100208dc();
  }
  uVar16 = local_78 & (int)~local_78 >> 0x1f;
  uVar13 = local_58 - local_74 & (int)local_78 >> 0x1f;
  iVar25 = 0;
  iVar27 = 0;
  while( true ) {
    local_8c = (uint)(uVar32 >> 0x20);
    local_90 = (int)uVar32;
    local_80 = (byte *)FUN_100259c0(param_1,*(undefined4 *)(iVar9 + 4));
    if (local_80 == (byte *)0x0) break;
    FUN_1001f4d4((int)local_80 + 0xc,iVar9 + 0xc,(*(int *)(iVar9 + 0x10) + 2) * 4);
    local_38 = FUN_10026384(param_1,extraout_r1_00,local_90,local_8c,&iStack_34,aiStack_30);
    if ((local_38 == 0) || (iVar25 = FUN_10025ccc(param_1,1), iVar25 == 0)) break;
    if (iStack_34 < 0) {
      uVar19 = uVar16 - iStack_34;
      uVar23 = uVar13;
    }
    else {
      uVar23 = iStack_34 + uVar13;
      uVar19 = uVar16;
    }
    iVar14 = 0x36 - aiStack_30[0];
    iVar18 = (iStack_34 - (int)local_7c) + aiStack_30[0] + -1;
    if (iVar18 < -0x3fe) {
      iVar14 = iVar14 - (-0x3fe - iVar18);
    }
    uVar17 = uVar23 + iVar14;
    uVar20 = uVar19 + iVar14 + (int)local_7c;
    uVar19 = uVar23;
    if ((int)uVar17 < (int)uVar23) {
      uVar19 = uVar17;
    }
    if ((int)uVar20 < (int)uVar19) {
      uVar19 = uVar20;
    }
    if (0 < (int)uVar19) {
      uVar17 = uVar17 - uVar19;
      uVar20 = uVar20 - uVar19;
      uVar23 = uVar23 - uVar19;
    }
    if (0 < (int)uVar13) {
      iVar25 = FUN_10025ea8(param_1,iVar25,uVar13);
      if ((iVar25 == 0) || (iVar14 = FUN_10025cf8(param_1,iVar25,local_38), iVar14 == 0)) break;
      FUN_10025a44(param_1,local_38);
      local_38 = iVar14;
    }
    if ((((((0 < (int)uVar17) && (local_38 = FUN_10025fb4(param_1,local_38,uVar17), local_38 == 0))
          || ((0 < (int)local_78 &&
              (local_80 = (byte *)FUN_10025ea8(param_1,local_80,uVar16), local_80 == (byte *)0x0))))
         || ((0 < (int)uVar20 &&
             (local_80 = (byte *)FUN_10025fb4(param_1,local_80,uVar20), local_80 == (byte *)0x0))))
        || ((0 < (int)uVar23 && (iVar25 = FUN_10025fb4(param_1,iVar25,uVar23), iVar25 == 0)))) ||
       (iVar27 = FUN_100260e4(param_1,local_38,local_80), iVar27 == 0)) break;
    iVar18 = *(int *)(iVar27 + 0xc);
    *(undefined4 *)(iVar27 + 0xc) = 0;
    iVar14 = FUN_100260a8(iVar27,iVar25);
    cVar28 = iVar14 == 0;
    if (iVar14 < 0) {
      FUN_10020a86();
    }
    if (cVar28 != '\0') {
      FUN_100209c2();
    }
    uVar29 = FUN_10026448(iVar27,iVar25);
    uVar11 = (undefined4)((ulonglong)uVar29 >> 0x20);
    uVar6 = (undefined4)uVar29;
    iVar14 = FUN_1001ea48(uVar6,uVar11,0,0x40000000);
    if (iVar14 == 0) {
      uVar29 = FUN_1001e9a6(uVar6,uVar11,0,0x3fe00000);
      if (iVar18 != 0) {
        lVar30 = FUN_100200e8();
        return lVar30;
      }
    }
    else {
      if (iVar18 != 0) {
        lVar30 = FUN_100200e8();
        return lVar30;
      }
      if (local_90 != 0) {
        if (uVar32 != 1) goto LAB_100206ae;
        *param_1 = 0x22;
        goto LAB_100205d8;
      }
      if ((uVar32 & 0xfffff00000000) != 0) {
LAB_100206ae:
        lVar30 = FUN_100200e8();
        return lVar30;
      }
      iVar14 = FUN_1001ea3c(uVar6,uVar11,0,0x3ff00000);
      if (iVar14 != 0) {
        FUN_100209ae();
      }
      uVar29 = FUN_1001e9a6(uVar6,uVar11,0,0x3fe00000);
    }
    iStack_5c = (int)((ulonglong)uVar29 >> 0x20);
    uStack_60 = (undefined4)uVar29;
    iVar14 = iStack_5c + -0x80000000;
    uVar19 = local_8c & 0x7ff00000;
    if (uVar19 == 0x7fe00000) {
      uVar31 = FUN_1002628c(local_90,local_8c + 0xfcb00000);
      uVar31 = FUN_1001e9a6((int)uVar31,(int)((ulonglong)uVar31 >> 0x20),uStack_60,iVar14);
      uVar31 = FUN_1001e958((int)uVar31,(int)((ulonglong)uVar31 >> 0x20),local_90,
                            local_8c + 0xfcb00000);
      uVar23 = (uint)((ulonglong)uVar31 >> 0x20);
      if ((uVar23 & 0x7ff00000) < 0x7ca00000) {
        uVar32 = CONCAT44(uVar23 + 0x3500000,(int)uVar31);
        goto LAB_10020178;
      }
      if (uVar32 == 0x7fefffffffffffff) break;
      uVar32 = 0x7fefffffffffffff;
    }
    else {
      if ((local_7c != (byte *)0x0) && (uVar19 < 0x6a00001)) {
        iVar7 = FUN_1001ea48(uStack_60,iStack_5c,0xffc00000,0x41dfffff);
        if (iVar7 != 0) {
          iVar14 = FUN_1001eafc(uStack_60,iStack_5c);
          if (iVar14 == 0) {
            iVar14 = 1;
          }
          uVar29 = FUN_1001ea7c(iVar14);
          uVar31 = uVar29;
          if (iVar18 != 0) {
            uVar31 = FUN_10020982();
          }
          uStack_60 = (undefined4)uVar31;
          iVar14 = (int)((ulonglong)uVar31 >> 0x20) + -0x80000000;
        }
        iVar14 = (iVar14 + 0x6b00000) - uVar19;
      }
      uVar31 = FUN_1002628c(local_90,local_8c);
      uVar31 = FUN_1001e9a6(uStack_60,iVar14,(int)uVar31,(int)((ulonglong)uVar31 >> 0x20));
      uVar32 = FUN_1001e958((int)uVar31,(int)((ulonglong)uVar31 >> 0x20),local_90,local_8c);
LAB_10020178:
      local_8c = (uint)(uVar32 >> 0x20);
      local_90 = (int)uVar32;
      iStack_5c = (int)((ulonglong)uVar29 >> 0x20);
      uStack_60 = (undefined4)uVar29;
      if ((local_7c == (byte *)0x0) && (uVar19 == (local_8c & 0x7ff00000))) {
        FUN_1001eb2c(uStack_60,iStack_5c);
        uVar29 = FUN_1001eb14();
        uVar29 = FUN_1001e946(uStack_60,iStack_5c,(int)uVar29,(int)((ulonglong)uVar29 >> 0x20));
        uVar11 = (undefined4)((ulonglong)uVar29 >> 0x20);
        uVar6 = (undefined4)uVar29;
        if ((iVar18 == 0 && local_90 == 0) && (uVar32 & 0xfffff00000000) == 0) {
          iVar14 = FUN_1001ea3c(uVar6,uVar11,0x94a03595,0x3fcfffff);
        }
        else {
          iVar14 = FUN_1001ea3c(uVar6,uVar11,0x94a03595,0x3fdfffff);
          if (iVar14 != 0) goto LAB_100205d8;
          iVar14 = FUN_1001ea58(uVar6,uVar11,0x35afe535,0x3fe00000);
        }
        if (iVar14 != 0) goto LAB_100205d8;
      }
    }
    FUN_10025a44(param_1,local_38);
    FUN_10025a44(param_1,local_80);
    FUN_10025a44(param_1,iVar25);
    FUN_10025a44(param_1,iVar27);
  }
  *param_1 = 0x22;
LAB_100205d8:
  FUN_10025a44(param_1,local_38);
  FUN_10025a44(param_1,local_80);
  FUN_10025a44(param_1,iVar25);
  FUN_10025a44(param_1,iVar9);
  FUN_10025a44(param_1,iVar27);
  lVar30 = FUN_10020268();
  return lVar30;
switchD_1001fd22_caseD_9:
  pbVar22 = pbVar22 + 1;
  goto LAB_1001fd12;
LAB_1002029e:
  if (pbVar10 == (byte *)0x0 && local_80 == (byte *)0x0) {
    lVar30 = switchD_1001fd22::caseD_0();
    return lVar30;
  }
  param_2 = local_3c;
LAB_100202a8:
  local_3c = param_2 + 1;
  uVar13 = (uint)param_2[1];
  if (uVar13 == 0x2b) {
    bVar4 = false;
LAB_100202be:
    local_3c = param_2 + 2;
    uVar13 = (uint)param_2[2];
  }
  else {
    if (uVar13 == 0x2d) {
      bVar4 = true;
      goto LAB_100202be;
    }
    bVar4 = false;
  }
  local_74 = uVar13 - 0x30;
  if (local_74 < 10) {
    pbVar24 = local_3c;
    if (uVar13 == 0x30) {
      do {
        pbVar24 = local_3c + 1;
        uVar13 = (uint)*pbVar24;
        local_3c = pbVar24;
      } while (uVar13 == 0x30);
      local_74 = 0;
      if (8 < uVar13 - 0x31) goto LAB_1001fefe;
      local_74 = uVar13 - 0x30;
    }
    local_3c = pbVar24 + 1;
    uVar13 = (uint)pbVar24[1];
    if (uVar13 < 0x30) {
LAB_100208ac:
      if (19999 < (int)local_74) goto LAB_1002034a;
    }
    else {
      while (uVar13 < 0x3a) {
        iVar9 = local_74 * 10 + uVar13;
        uVar13 = (uint)local_3c[1];
        local_74 = iVar9 - 0x30;
        if (uVar13 < 0x30) {
          local_3c = local_3c + 1;
          goto LAB_10020338;
        }
        local_3c = local_3c + 1;
      }
LAB_10020338:
      if ((int)local_3c - (int)pbVar24 < 9) goto LAB_100208ac;
LAB_1002034a:
      local_74 = 19999;
    }
    if (bVar4) {
      local_74 = -local_74;
    }
  }
  else {
    local_74 = 0;
    local_3c = param_2;
  }
LAB_1001fefe:
  if (local_7c != (byte *)0x0) {
    local_80 = local_7c;
    if (local_7c != (byte *)0x0) {
      local_80 = local_7c;
    }
    goto LAB_1001fd9c;
  }
  if (local_80 != (byte *)0x0 || pbVar8 != (byte *)0x0) goto LAB_10020264;
  if (!bVar3) {
    if (uVar13 != 0x69) {
      if (0x69 < uVar13) {
        FUN_100208a0();
      }
      if (uVar13 != 0x49) {
        if ((uVar13 == 0x4e) && (iVar9 = FUN_100251f4(&local_3c,&DAT_1002acd4), iVar9 != 0)) {
          if (*local_3c == 0x28) {
            FUN_10020a30();
          }
          FUN_1002592c("");
          lVar30 = FUN_10020268();
          return lVar30;
        }
        goto code_r0x1001fe9e;
      }
    }
    iVar9 = FUN_100251f4(&local_3c,&DAT_1002acc8);
    if (iVar9 == 0) {
      lVar30 = switchD_1001fd22::caseD_0();
      return lVar30;
    }
    local_3c = local_3c + -1;
    iVar9 = FUN_100251f4(&local_3c,"inity");
    if (iVar9 == 0) {
      local_3c = local_3c + 1;
    }
LAB_1002050a:
    lVar30 = FUN_10020268();
    return lVar30;
  }
code_r0x1001fe9e:
  uVar13 = 0;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = param_2;
  }
LAB_1001feaa:
  return (ulonglong)uVar13 << 0x20;
}



/* FUN_1001fe6a at 1001fe6a */

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x1001ff02) */
/* WARNING: Removing unreachable block (ram,0x10020296) */
/* WARNING: Removing unreachable block (ram,0x10020294) */
/* WARNING: Removing unreachable block (ram,0x1001fd9c) */
/* WARNING: Removing unreachable block (ram,0x1001fda4) */
/* WARNING: Removing unreachable block (ram,0x1001fda6) */
/* WARNING: Removing unreachable block (ram,0x1001fdb6) */
/* WARNING: Removing unreachable block (ram,0x1001fdea) */
/* WARNING: Removing unreachable block (ram,0x1001fdf0) */
/* WARNING: Removing unreachable block (ram,0x1001fdf4) */
/* WARNING: Removing unreachable block (ram,0x1001fdfc) */
/* WARNING: Removing unreachable block (ram,0x1001fe00) */
/* WARNING: Removing unreachable block (ram,0x1001fe04) */
/* WARNING: Removing unreachable block (ram,0x1001fe12) */
/* WARNING: Removing unreachable block (ram,0x1001fe10) */
/* WARNING: Removing unreachable block (ram,0x1001fdfa) */
/* WARNING: Removing unreachable block (ram,0x10020492) */
/* WARNING: Removing unreachable block (ram,0x10020490) */
/* WARNING: Removing unreachable block (ram,0x1001fde8) */
/* WARNING: Removing unreachable block (ram,0x1001ff4a) */
/* WARNING: Removing unreachable block (ram,0x1001ff58) */
/* WARNING: Removing unreachable block (ram,0x10020440) */
/* WARNING: Removing unreachable block (ram,0x10020442) */
/* WARNING: Removing unreachable block (ram,0x10020450) */
/* WARNING: Removing unreachable block (ram,0x100209a8) */
/* WARNING: Removing unreachable block (ram,0x100209ac) */
/* WARNING: Removing unreachable block (ram,0x10020452) */
/* WARNING: Removing unreachable block (ram,0x10020458) */
/* WARNING: Removing unreachable block (ram,0x10020464) */
/* WARNING: Removing unreachable block (ram,0x10020468) */
/* WARNING: Removing unreachable block (ram,0x10020472) */
/* WARNING: Removing unreachable block (ram,0x10020478) */
/* WARNING: Removing unreachable block (ram,0x1002047a) */
/* WARNING: Removing unreachable block (ram,0x10020510) */
/* WARNING: Removing unreachable block (ram,0x10020522) */
/* WARNING: Removing unreachable block (ram,0x10020532) */
/* WARNING: Removing unreachable block (ram,0x10020538) */
/* WARNING: Removing unreachable block (ram,0x10020542) */
/* WARNING: Removing unreachable block (ram,0x10020540) */
/* WARNING: Removing unreachable block (ram,0x10020536) */
/* WARNING: Removing unreachable block (ram,0x10020548) */
/* WARNING: Removing unreachable block (ram,0x10020558) */
/* WARNING: Removing unreachable block (ram,0x10020486) */
/* WARNING: Removing unreachable block (ram,0x10020456) */
/* WARNING: Removing unreachable block (ram,0x1002055a) */
/* WARNING: Removing unreachable block (ram,0x1001ff5a) */
/* WARNING: Removing unreachable block (ram,0x1001ff68) */
/* WARNING: Removing unreachable block (ram,0x1001ff6c) */
/* WARNING: Removing unreachable block (ram,0x1001ff86) */
/* WARNING: Removing unreachable block (ram,0x1001ff8a) */
/* WARNING: Removing unreachable block (ram,0x1001ff8e) */
/* WARNING: Removing unreachable block (ram,0x1001ffa4) */
/* WARNING: Removing unreachable block (ram,0x1001ffa8) */
/* WARNING: Removing unreachable block (ram,0x100201a8) */
/* WARNING: Removing unreachable block (ram,0x100201b8) */
/* WARNING: Removing unreachable block (ram,0x100201ba) */
/* WARNING: Removing unreachable block (ram,0x100201e8) */
/* WARNING: Removing unreachable block (ram,0x100201ea) */
/* WARNING: Removing unreachable block (ram,0x100201f8) */
/* WARNING: Removing unreachable block (ram,0x100201fa) */
/* WARNING: Removing unreachable block (ram,0x10020202) */
/* WARNING: Removing unreachable block (ram,0x10020200) */
/* WARNING: Removing unreachable block (ram,0x10020208) */
/* WARNING: Removing unreachable block (ram,0x1002021e) */
/* WARNING: Removing unreachable block (ram,0x1001ffdc) */
/* WARNING: Removing unreachable block (ram,0x1001ffe6) */
/* WARNING: Removing unreachable block (ram,0x1001ffe4) */
/* WARNING: Removing unreachable block (ram,0x1001fff0) */
/* WARNING: Removing unreachable block (ram,0x10020002) */
/* WARNING: Removing unreachable block (ram,0x10020004) */
/* WARNING: Removing unreachable block (ram,0x10020008) */
/* WARNING: Removing unreachable block (ram,0x1002000a) */
/* WARNING: Removing unreachable block (ram,0x1002000e) */
/* WARNING: Removing unreachable block (ram,0x10020018) */
/* WARNING: Removing unreachable block (ram,0x1002001e) */
/* WARNING: Removing unreachable block (ram,0x10020594) */
/* WARNING: Removing unreachable block (ram,0x100205a6) */
/* WARNING: Removing unreachable block (ram,0x10020020) */
/* WARNING: Removing unreachable block (ram,0x10020026) */
/* WARNING: Removing unreachable block (ram,0x100205cc) */
/* WARNING: Removing unreachable block (ram,0x100205ca) */
/* WARNING: Removing unreachable block (ram,0x10020028) */
/* WARNING: Removing unreachable block (ram,0x1002002e) */
/* WARNING: Removing unreachable block (ram,0x1002062a) */
/* WARNING: Removing unreachable block (ram,0x10020628) */
/* WARNING: Removing unreachable block (ram,0x10020030) */
/* WARNING: Removing unreachable block (ram,0x10020034) */
/* WARNING: Removing unreachable block (ram,0x10020610) */
/* WARNING: Removing unreachable block (ram,0x10020036) */
/* WARNING: Removing unreachable block (ram,0x1002003a) */
/* WARNING: Removing unreachable block (ram,0x1002004a) */
/* WARNING: Removing unreachable block (ram,0x1002004c) */
/* WARNING: Removing unreachable block (ram,0x1002005c) */
/* WARNING: Removing unreachable block (ram,0x1002005e) */
/* WARNING: Removing unreachable block (ram,0x10020070) */
/* WARNING: Removing unreachable block (ram,0x10020074) */
/* WARNING: Removing unreachable block (ram,0x1002007a) */
/* WARNING: Removing unreachable block (ram,0x1002007e) */
/* WARNING: Removing unreachable block (ram,0x1002009a) */
/* WARNING: Removing unreachable block (ram,0x100200a0) */
/* WARNING: Removing unreachable block (ram,0x100200a2) */
/* WARNING: Removing unreachable block (ram,0x100200a8) */
/* WARNING: Removing unreachable block (ram,0x10020764) */
/* WARNING: Removing unreachable block (ram,0x1002076a) */
/* WARNING: Removing unreachable block (ram,0x100200aa) */
/* WARNING: Removing unreachable block (ram,0x100200b0) */
/* WARNING: Removing unreachable block (ram,0x100206ae) */
/* WARNING: Removing unreachable block (ram,0x100200b2) */
/* WARNING: Removing unreachable block (ram,0x100200c2) */
/* WARNING: Removing unreachable block (ram,0x100200c6) */
/* WARNING: Removing unreachable block (ram,0x10020098) */
/* WARNING: Removing unreachable block (ram,0x10020644) */
/* WARNING: Removing unreachable block (ram,0x1002057c) */
/* WARNING: Removing unreachable block (ram,0x100200de) */
/* WARNING: Removing unreachable block (ram,0x100200fc) */
/* WARNING: Removing unreachable block (ram,0x10020102) */
/* WARNING: Removing unreachable block (ram,0x1002010a) */
/* WARNING: Removing unreachable block (ram,0x1002011a) */
/* WARNING: Removing unreachable block (ram,0x10020126) */
/* WARNING: Removing unreachable block (ram,0x10020128) */
/* WARNING: Removing unreachable block (ram,0x10020136) */
/* WARNING: Removing unreachable block (ram,0x1002013a) */
/* WARNING: Removing unreachable block (ram,0x1002014c) */
/* WARNING: Removing unreachable block (ram,0x10020156) */
/* WARNING: Removing unreachable block (ram,0x100200fa) */
/* WARNING: Removing unreachable block (ram,0x10020690) */
/* WARNING: Removing unreachable block (ram,0x10020178) */
/* WARNING: Removing unreachable block (ram,0x1002017e) */
/* WARNING: Removing unreachable block (ram,0x10020186) */
/* WARNING: Removing unreachable block (ram,0x10020742) */
/* WARNING: Removing unreachable block (ram,0x1002074c) */
/* WARNING: Removing unreachable block (ram,0x1002075c) */
/* WARNING: Removing unreachable block (ram,0x1002075e) */
/* WARNING: Removing unreachable block (ram,0x1002072c) */
/* WARNING: Removing unreachable block (ram,0x10020736) */
/* WARNING: Removing unreachable block (ram,0x10020738) */
/* WARNING: Removing unreachable block (ram,0x10020692) */
/* WARNING: Removing unreachable block (ram,0x10020698) */
/* WARNING: Removing unreachable block (ram,0x10020612) */
/* WARNING: Removing unreachable block (ram,0x100205ce) */
/* WARNING: Removing unreachable block (ram,0x100205d8) */
/* WARNING: Removing unreachable block (ram,0x1002069c) */
/* WARNING: Removing unreachable block (ram,0x10020188) */
/* WARNING: Removing unreachable block (ram,0x1001ff10) */
/* WARNING: Removing unreachable block (ram,0x1001ff14) */
/* WARNING: Removing unreachable block (ram,0x1001ff16) */
/* WARNING: Removing unreachable block (ram,0x1001ff18) */
/* WARNING: Removing unreachable block (ram,0x1001ff1c) */
/* WARNING: Removing unreachable block (ram,0x1001ff20) */
/* WARNING: Removing unreachable block (ram,0x100204e4) */
/* WARNING: Removing unreachable block (ram,0x100204f0) */
/* WARNING: Removing unreachable block (ram,0x100204f2) */
/* WARNING: Removing unreachable block (ram,0x10020504) */
/* WARNING: Removing unreachable block (ram,0x1001ff22) */
/* WARNING: Removing unreachable block (ram,0x1001ff26) */
/* WARNING: Removing unreachable block (ram,0x1001ff32) */
/* WARNING: Removing unreachable block (ram,0x1001ff3a) */
/* WARNING: Removing unreachable block (ram,0x1001ff3e) */

undefined4 FUN_1001fe6a(undefined4 param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  bool bVar2;
  ulonglong uVar3;
  byte *pbVar4;
  int iVar5;
  undefined4 uVar6;
  uint extraout_r1;
  undefined4 *puVar7;
  int iVar8;
  int extraout_r2;
  byte *unaff_r4;
  byte *unaff_r5;
  uint uVar9;
  int iVar10;
  undefined4 *unaff_r8;
  byte *unaff_r9;
  byte *pbVar11;
  int unaff_r10;
  int extraout_r12;
  longlong lVar12;
  ulonglong uVar13;
  undefined8 uVar14;
  undefined4 in_stack_00000010;
  int in_stack_00000014;
  undefined4 *in_stack_00000018;
  int in_stack_00000020;
  undefined4 *puStack00000024;
  byte *pbStack00000048;
  byte *in_stack_00000064;
  
  pbVar4 = (byte *)0x0;
  pbVar11 = unaff_r5;
  if (param_3 == 0x30) {
    do {
      pbVar4 = pbVar11;
      in_stack_00000064 = pbVar4 + 1;
      param_3 = (uint)*in_stack_00000064;
      pbVar11 = in_stack_00000064;
    } while (param_3 == 0x30);
    pbVar4 = pbVar4 + (1 - (int)unaff_r5);
  }
  pbVar11 = in_stack_00000064;
  if (param_3 - 0x31 < 9) {
    pbStack00000048 = pbVar4 + 1;
    puVar7 = (undefined4 *)(param_3 - 0x30);
    iVar10 = 1;
    puStack00000024 = (undefined4 *)0x0;
    do {
      pbVar11 = (byte *)((int)puVar7 + (int)unaff_r9 * 10);
      in_stack_00000064 = in_stack_00000064 + 1;
      lVar12 = ZEXT48(in_stack_00000064) << 0x20;
      puVar7 = (undefined4 *)(*in_stack_00000064 - 0x30);
      if (puVar7 < (undefined4 *)0xa) {
        iVar8 = 1;
        if (puVar7 == (undefined4 *)0x0) {
          lVar12 = FUN_10020caa();
          iVar8 = extraout_r2;
        }
        pbStack00000048 = pbStack00000048 + iVar8;
        if (iVar8 == 1) {
          lVar12 = FUN_10020ca6();
        }
        iVar5 = iVar10 + 1;
        iVar8 = iVar5;
        unaff_r9 = pbVar11;
        do {
          if (iVar8 + -1 < 9) {
            unaff_r9 = (byte *)((int)unaff_r9 * 10);
          }
          else if (iVar8 < 0x11) {
            unaff_r10 = unaff_r10 * 10;
          }
          iVar8 = iVar8 + 1;
        } while ((iVar8 - iVar10) + -1 < (int)lVar12);
      }
      else {
        uVar13 = FUN_1001feee(0,in_stack_00000064,1);
        if ((int)uVar13 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        puVar7 = &DAT_1002b330;
        puStack00000024 = &DAT_1002b330;
        bVar2 = false;
        uVar13 = uVar13 & 0xffffffff00000000;
        iVar10 = unaff_r10;
        do {
          if (((uint)unaff_r4 & 1) != 0) {
            uVar13 = FUN_1001e9a6((int)uVar13,(int)(uVar13 >> 0x20),*puVar7,puVar7[1]);
            bVar2 = true;
          }
          iVar10 = iVar10 + 1;
          unaff_r4 = (byte *)((int)unaff_r4 >> 1);
          puVar7 = puVar7 + 2;
        } while (unaff_r4 != (byte *)0x1);
        uVar3 = CONCAT44(in_stack_00000014,in_stack_00000010);
        if (bVar2) {
          uVar3 = uVar13;
        }
        in_stack_00000014 = (int)(uVar3 >> 0x20);
        in_stack_00000010 = (undefined4)uVar3;
        FUN_1001e9a6(puStack00000024[iVar10 * 2],(puStack00000024 + iVar10 * 2)[1],in_stack_00000010
                     ,in_stack_00000014 + -0x3500000);
        if (0x7ca00000 < (extraout_r1 & 0x7ff00000)) {
          *unaff_r8 = 0x22;
          uVar6 = FUN_10020268();
          return uVar6;
        }
        if ((extraout_r1 & 0x7ff00000) < 0x7c900001) {
          FUN_1001ff8a();
        }
        unaff_r9 = (byte *)0x7fefffff;
        in_stack_00000010 = 0xffffffff;
        in_stack_00000014 = 0x7fefffff;
        uVar14 = FUN_1001ff8a();
        unaff_r10 = (int)((ulonglong)uVar14 >> 0x20);
        lVar12 = CONCAT44(iVar10,(int)uVar14);
        unaff_r4 = pbVar11;
        iVar5 = extraout_r12;
      }
      in_stack_00000064 = (byte *)((ulonglong)lVar12 >> 0x20);
      iVar5 = (int)lVar12 + -1 + iVar5;
      iVar10 = iVar5 + 1;
      if (8 < iVar5) {
        if (iVar10 < 0x11) {
          uVar6 = FUN_1002037c(0,in_stack_00000064,unaff_r10,unaff_r10 * 10);
          return uVar6;
        }
        uVar6 = FUN_1002037c(0);
        return uVar6;
      }
    } while( true );
  }
  if ((param_3 & 0xffffffdf) != 0x45) {
    pbVar11 = unaff_r4;
    if (in_stack_00000020 == 0 && pbVar4 == (byte *)0x0) goto code_r0x1001fe9e;
    goto LAB_10020264;
  }
  puStack00000024 = (undefined4 *)0x0;
  pbStack00000048 = (byte *)0x0;
  if (pbVar4 == (byte *)0x0 && in_stack_00000020 == 0) {
    uVar6 = switchD_1001fd22::caseD_0();
    return uVar6;
  }
  uVar9 = (uint)in_stack_00000064[1];
  if (uVar9 == 0x2b) {
    bVar2 = false;
LAB_100202be:
    uVar9 = (uint)in_stack_00000064[2];
    in_stack_00000064 = in_stack_00000064 + 2;
  }
  else {
    if (uVar9 == 0x2d) {
      bVar2 = true;
      goto LAB_100202be;
    }
    bVar2 = false;
    in_stack_00000064 = in_stack_00000064 + 1;
  }
  if (uVar9 - 0x30 < 10) {
    if (uVar9 == 0x30) {
      do {
        in_stack_00000064 = in_stack_00000064 + 1;
      } while (*in_stack_00000064 == 0x30);
      if (8 < *in_stack_00000064 - 0x31) goto LAB_1001fefe;
    }
    bVar1 = in_stack_00000064[1];
    while ((in_stack_00000064 = in_stack_00000064 + 1, 0x2f < bVar1 && (bVar1 < 0x3a))) {
      bVar1 = in_stack_00000064[1];
    }
    if (bVar2) {
    }
  }
  else {
    in_stack_00000064 = pbVar11;
  }
LAB_1001fefe:
  if (in_stack_00000020 == 0 && pbVar4 == (byte *)0x0) {
code_r0x1001fe9e:
    if (in_stack_00000018 == (undefined4 *)0x0) {
      return 0;
    }
    *in_stack_00000018 = pbVar11;
    return 0;
  }
LAB_10020264:
  if (in_stack_00000018 != (undefined4 *)0x0) {
    *in_stack_00000018 = in_stack_00000064;
  }
  return 0;
}



/* caseD_0 at 1001fe9e */

undefined8 switchD_1001fd22::caseD_0(void)

{
  undefined4 unaff_r4;
  undefined4 *in_stack_00000018;
  
  if (in_stack_00000018 != (undefined4 *)0x0) {
    *in_stack_00000018 = unaff_r4;
  }
  return 0;
}



/* FUN_1001feee at 1001feee */

undefined4 FUN_1001feee(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  undefined4 uVar2;
  uint extraout_r1;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  byte *pbVar11;
  uint uVar12;
  int iVar13;
  byte *unaff_r4;
  uint uVar14;
  undefined4 *puVar15;
  uint unaff_r5;
  uint uVar16;
  uint uVar17;
  int unaff_r6;
  undefined4 *unaff_r8;
  char cVar18;
  ulonglong uVar19;
  undefined8 uVar20;
  undefined8 uVar21;
  int iStack00000010;
  uint uStack00000014;
  undefined4 *in_stack_00000018;
  int in_stack_00000020;
  uint uStack00000024;
  uint uStack0000002c;
  undefined4 uStack00000040;
  int iStack00000044;
  int in_stack_00000048;
  undefined4 uStack00000064;
  int in_stack_00000068;
  int in_stack_0000006c;
  int in_stack_00000070;
  
  pbVar11 = uStack00000064;
  if ((unaff_r5 == 0x65) || (uStack0000002c = 0, uStack00000064 = pbVar11, unaff_r5 == 0x45)) {
    if ((unaff_r6 == 0 && param_1 == 0) && in_stack_00000020 == 0) {
      uVar2 = switchD_1001fd22::caseD_0();
      return uVar2;
    }
    unaff_r5 = (uint)uStack00000064[1];
    if (unaff_r5 == 0x2b) {
      bVar1 = false;
LAB_100202be:
      unaff_r5 = (uint)uStack00000064[2];
      uStack00000064 = uStack00000064 + 2;
    }
    else {
      if (unaff_r5 == 0x2d) {
        bVar1 = true;
        goto LAB_100202be;
      }
      bVar1 = false;
      uStack00000064 = uStack00000064 + 1;
    }
    uStack0000002c = unaff_r5 - 0x30;
    unaff_r4 = pbVar11;
    if (uStack0000002c < 10) {
      pbVar11 = uStack00000064;
      if (unaff_r5 == 0x30) {
        do {
          pbVar11 = uStack00000064 + 1;
          unaff_r5 = (uint)*pbVar11;
          uStack00000064 = pbVar11;
        } while (unaff_r5 == 0x30);
        uStack0000002c = 0;
        if (8 < unaff_r5 - 0x31) goto LAB_1001fefe;
        uStack0000002c = unaff_r5 - 0x30;
      }
      uStack00000064 = pbVar11 + 1;
      unaff_r5 = (uint)pbVar11[1];
      if (unaff_r5 < 0x30) {
LAB_100208ac:
        if (19999 < (int)uStack0000002c) goto LAB_1002034a;
      }
      else {
        while (unaff_r5 < 0x3a) {
          iVar13 = uStack0000002c * 10 + unaff_r5;
          unaff_r5 = (uint)uStack00000064[1];
          uStack0000002c = iVar13 - 0x30;
          if (unaff_r5 < 0x30) {
            uStack00000064 = uStack00000064 + 1;
            goto LAB_10020338;
          }
          uStack00000064 = uStack00000064 + 1;
        }
LAB_10020338:
        if ((int)uStack00000064 - (int)pbVar11 < 9) goto LAB_100208ac;
LAB_1002034a:
        uStack0000002c = 19999;
      }
      if (bVar1) {
        uStack0000002c = -uStack0000002c;
      }
    }
    else {
      uStack0000002c = 0;
      uStack00000064 = pbVar11;
    }
  }
LAB_1001fefe:
  if (unaff_r6 == 0) {
    if (in_stack_00000020 == 0 && param_1 == 0) {
      if (param_3 == 0) {
        if (unaff_r5 == 0x69) {
LAB_100204e4:
          iVar13 = FUN_100251f4(&uStack00000064,&DAT_1002acc8);
          if (iVar13 == 0) {
            uVar2 = switchD_1001fd22::caseD_0();
            return uVar2;
          }
          uStack00000064 = uStack00000064 + -1;
          iVar13 = FUN_100251f4(&uStack00000064,"inity");
          if (iVar13 == 0) {
            uStack00000064 = uStack00000064 + 1;
          }
          uVar2 = FUN_10020268();
          return uVar2;
        }
        if (0x69 < (int)unaff_r5) {
          FUN_100208a0();
        }
        if (unaff_r5 == 0x49) goto LAB_100204e4;
        if ((unaff_r5 == 0x4e) &&
           (iVar13 = FUN_100251f4(&uStack00000064,&DAT_1002acd4), iVar13 != 0)) {
          if (*uStack00000064 == 0x28) {
            FUN_10020a30();
          }
          FUN_1002592c("");
          uVar2 = FUN_10020268();
          return uVar2;
        }
      }
      if (in_stack_00000018 != (undefined4 *)0x0) {
        *in_stack_00000018 = unaff_r4;
      }
    }
    else if (in_stack_00000018 != (undefined4 *)0x0) {
      *in_stack_00000018 = uStack00000064;
    }
    return 0;
  }
  uVar10 = uStack0000002c - in_stack_00000048;
  iVar13 = unaff_r6;
  if (0x10 < unaff_r6) {
    iVar13 = 0x10;
  }
  uVar19 = FUN_1001ea7c();
  if (unaff_r6 < 10) {
LAB_1001fdea:
    uStack00000014 = (uint)(uVar19 >> 0x20);
    iStack00000010 = (int)uVar19;
    if (uVar10 == 0) {
      FUN_100206c0();
    }
    if ((int)uVar10 < 1) {
      if (-0x17 < (int)uVar10) {
        iVar13 = (in_stack_00000048 - uStack0000002c) * 8;
        FUN_1001e96a(iStack00000010,uStack00000014,*(undefined4 *)(&DAT_1002b358 + iVar13),
                     *(undefined4 *)(&DAT_1002b35c + iVar13));
        uVar2 = FUN_10020268();
        return uVar2;
      }
    }
    else {
      if ((int)uVar10 < 0x17) {
        FUN_100208c2();
      }
      if ((int)uVar10 <= 0x25 - unaff_r6) {
        iVar13 = (0xf - unaff_r6) * 8;
        uVar20 = FUN_1001e9a6(*(undefined4 *)(&DAT_1002b358 + iVar13),
                              *(undefined4 *)(&DAT_1002b35c + iVar13),iStack00000010,uStack00000014)
        ;
        iVar13 = (uVar10 - (0xf - unaff_r6)) * 8;
        FUN_1001e9a6((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),
                     *(undefined4 *)(&DAT_1002b358 + iVar13),*(undefined4 *)(&DAT_1002b35c + iVar13)
                    );
        uVar2 = FUN_10020268();
        return uVar2;
      }
    }
  }
  else {
    iVar4 = (iVar13 + -9) * 8;
    uVar20 = FUN_1001e9a6((int)uVar19,(int)(uVar19 >> 0x20),*(undefined4 *)(&DAT_1002b358 + iVar4),
                          *(undefined4 *)(&DAT_1002b35c + iVar4));
    uVar21 = FUN_1001ea7c();
    uVar19 = FUN_1001e958((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar21,
                          (int)((ulonglong)uVar21 >> 0x20));
    if (unaff_r6 < 0x10) goto LAB_1001fdea;
  }
  uStack00000014 = (uint)(uVar19 >> 0x20);
  iStack00000010 = (int)uVar19;
  uVar6 = (unaff_r6 - iVar13) + uVar10;
  if ((int)uVar6 < 1) {
    if (uVar6 == 0) {
      uVar2 = FUN_1001ff8a();
      return uVar2;
    }
    uVar6 = -uVar6;
    uVar17 = (int)uVar6 >> 4;
    if (((uVar6 & 0xf) != 0) &&
       (iVar13 = (uVar6 & 0xf) * 8,
       uVar19 = FUN_1001e96a(iStack00000010,uStack00000014,*(undefined4 *)(&DAT_1002b358 + iVar13),
                             *(undefined4 *)(&DAT_1002b35c + iVar13)), uVar17 == 0)) {
      FUN_1001ff8a();
    }
    if ((int)uVar17 < 0x20) {
      uStack00000024 = uVar17 & 0x10;
      if ((uVar17 & 0x10) != 0) {
        uStack00000024 = 0x6a;
      }
      puVar15 = &DAT_1002aef8;
      while( true ) {
        while( true ) {
          uVar6 = uVar17 & 1;
          uVar17 = (int)uVar17 >> 1;
          if (uVar6 != 0) break;
          puVar15 = puVar15 + 2;
        }
        uVar19 = FUN_1001e9a6((int)uVar19,(int)(uVar19 >> 0x20),*puVar15,puVar15[1]);
        uVar6 = (uint)(uVar19 >> 0x20);
        if (uVar17 == 0) break;
        puVar15 = puVar15 + 2;
      }
      if (uStack00000024 != 0) {
        uVar17 = (uVar6 & 0x7fffffff) >> 0x14;
        uVar12 = 0x6b - uVar17;
        if (0 < (int)uVar12) {
          if ((int)uVar12 < 0x20) {
            uVar19 = CONCAT44(uVar6,(uint)uVar19 & -1 << (uVar12 & 0xff));
          }
          else if ((int)uVar12 < 0x35) {
            uVar19 = (ulonglong)(uVar6 & -1 << (0x4b - uVar17 & 0xff)) << 0x20;
          }
          else {
            uVar19 = 0x370000000000000;
          }
        }
      }
      uStack00000014 = (uint)(uVar19 >> 0x20);
      iStack00000010 = (int)uVar19;
      iVar13 = FUN_1001ea2c(iStack00000010,uStack00000014,0,0);
      if (iVar13 == 0) goto LAB_1001ff8e;
    }
    *unaff_r8 = 0x22;
    uVar2 = FUN_10020268();
    return uVar2;
  }
  uVar17 = uVar6 & 0xf;
  if ((uVar6 & 0xf) == 0) {
    FUN_100207c4();
    uVar17 = extraout_r1;
  }
  uVar19 = FUN_1001e9a6(*(undefined4 *)(&DAT_1002b358 + uVar17 * 8),
                        *(undefined4 *)(&DAT_1002b35c + uVar17 * 8),iStack00000010,uStack00000014);
  if ((uVar6 & 0xfffffff0) != 0) {
    FUN_100207c4();
  }
  uStack00000024 = 0;
LAB_1001ff8e:
  iVar13 = FUN_10025b2c();
  if (iVar13 == 0) {
    FUN_100208dc();
  }
  uVar17 = uVar10 & (int)~uVar10 >> 0x1f;
  uVar6 = in_stack_00000048 - uStack0000002c & (int)uVar10 >> 0x1f;
  while( true ) {
    uStack00000014 = (uint)(uVar19 >> 0x20);
    iStack00000010 = (int)uVar19;
    iVar4 = FUN_100259c0();
    if (iVar4 == 0) break;
    FUN_1001f4d4(iVar4 + 0xc,iVar13 + 0xc,(*(int *)(iVar13 + 0x10) + 2) * 4);
    in_stack_00000068 = FUN_10026384();
    if ((in_stack_00000068 == 0) || (iVar4 = FUN_10025ccc(), iVar4 == 0)) break;
    if (in_stack_0000006c < 0) {
      uVar12 = uVar17 - in_stack_0000006c;
      uVar16 = uVar6;
    }
    else {
      uVar16 = in_stack_0000006c + uVar6;
      uVar12 = uVar17;
    }
    iVar5 = 0x36 - in_stack_00000070;
    iVar9 = (in_stack_0000006c - uStack00000024) + in_stack_00000070 + -1;
    if (iVar9 < -0x3fe) {
      iVar5 = iVar5 - (-0x3fe - iVar9);
    }
    uVar7 = uVar16 + iVar5;
    uVar14 = uVar12 + iVar5 + uStack00000024;
    uVar12 = uVar16;
    if ((int)uVar7 < (int)uVar16) {
      uVar12 = uVar7;
    }
    if ((int)uVar14 < (int)uVar12) {
      uVar12 = uVar14;
    }
    if (0 < (int)uVar12) {
      uVar7 = uVar7 - uVar12;
      uVar14 = uVar14 - uVar12;
      uVar16 = uVar16 - uVar12;
    }
    if (0 < (int)uVar6) {
      iVar4 = FUN_10025ea8();
      if ((iVar4 == 0) || (iVar5 = FUN_10025cf8(), iVar5 == 0)) break;
      FUN_10025a44();
      in_stack_00000068 = iVar5;
    }
    if ((((((0 < (int)uVar7) && (in_stack_00000068 = FUN_10025fb4(), in_stack_00000068 == 0)) ||
          ((0 < (int)uVar10 && (iVar5 = FUN_10025ea8(), iVar5 == 0)))) ||
         ((0 < (int)uVar14 && (iVar5 = FUN_10025fb4(), iVar5 == 0)))) ||
        ((0 < (int)uVar16 && (iVar4 = FUN_10025fb4(), iVar4 == 0)))) ||
       (iVar5 = FUN_100260e4(), iVar5 == 0)) break;
    iVar8 = *(int *)(iVar5 + 0xc);
    *(undefined4 *)(iVar5 + 0xc) = 0;
    iVar9 = FUN_100260a8(iVar5,iVar4);
    cVar18 = iVar9 == 0;
    if (iVar9 < 0) {
      FUN_10020a86();
    }
    if (cVar18 != '\0') {
      FUN_100209c2();
    }
    uVar20 = FUN_10026448(iVar5,iVar4);
    uVar3 = (undefined4)((ulonglong)uVar20 >> 0x20);
    uVar2 = (undefined4)uVar20;
    iVar4 = FUN_1001ea48(uVar2,uVar3,0,0x40000000);
    if (iVar4 == 0) {
      uVar20 = FUN_1001e9a6(uVar2,uVar3,0,0x3fe00000);
      if (iVar8 != 0) {
        uVar2 = FUN_100200e8();
        return uVar2;
      }
    }
    else {
      if (iVar8 != 0) {
        uVar2 = FUN_100200e8();
        return uVar2;
      }
      if (iStack00000010 != 0) {
        if (uVar19 != 1) {
LAB_100206ae:
          uVar2 = FUN_100200e8();
          return uVar2;
        }
        *unaff_r8 = 0x22;
        goto LAB_100205d8;
      }
      if ((uVar19 & 0xfffff00000000) != 0) goto LAB_100206ae;
      iVar4 = FUN_1001ea3c(uVar2,uVar3,0,0x3ff00000);
      if (iVar4 != 0) {
        FUN_100209ae();
      }
      uVar20 = FUN_1001e9a6(uVar2,uVar3,0,0x3fe00000);
    }
    iStack00000044 = (int)((ulonglong)uVar20 >> 0x20);
    uStack00000040 = (undefined4)uVar20;
    iVar4 = iStack00000044 + -0x80000000;
    uVar12 = uStack00000014 & 0x7ff00000;
    if (uVar12 == 0x7fe00000) {
      uVar21 = FUN_1002628c(iStack00000010,uStack00000014 + 0xfcb00000);
      uVar21 = FUN_1001e9a6((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),uStack00000040,iVar4);
      uVar21 = FUN_1001e958((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),iStack00000010,
                            uStack00000014 + 0xfcb00000);
      uVar16 = (uint)((ulonglong)uVar21 >> 0x20);
      if ((uVar16 & 0x7ff00000) < 0x7ca00000) {
        uVar19 = CONCAT44(uVar16 + 0x3500000,(int)uVar21);
        goto LAB_10020178;
      }
      if (uVar19 == 0x7fefffffffffffff) break;
      uVar19 = 0x7fefffffffffffff;
    }
    else {
      if ((uStack00000024 != 0) && (uVar12 < 0x6a00001)) {
        iVar5 = FUN_1001ea48(uStack00000040,iStack00000044,0xffc00000,0x41dfffff);
        if (iVar5 != 0) {
          iVar4 = FUN_1001eafc(uStack00000040,iStack00000044);
          if (iVar4 == 0) {
            iVar4 = 1;
          }
          uVar20 = FUN_1001ea7c(iVar4);
          uVar21 = uVar20;
          if (iVar8 != 0) {
            uVar21 = FUN_10020982();
          }
          uStack00000040 = (undefined4)uVar21;
          iVar4 = (int)((ulonglong)uVar21 >> 0x20) + -0x80000000;
        }
        iVar4 = (iVar4 + 0x6b00000) - uVar12;
      }
      uVar21 = FUN_1002628c(iStack00000010,uStack00000014);
      uVar21 = FUN_1001e9a6(uStack00000040,iVar4,(int)uVar21,(int)((ulonglong)uVar21 >> 0x20));
      uVar19 = FUN_1001e958((int)uVar21,(int)((ulonglong)uVar21 >> 0x20),iStack00000010,
                            uStack00000014);
LAB_10020178:
      uStack00000014 = (uint)(uVar19 >> 0x20);
      iStack00000010 = (int)uVar19;
      iStack00000044 = (int)((ulonglong)uVar20 >> 0x20);
      uStack00000040 = (undefined4)uVar20;
      if ((uStack00000024 == 0) && (uVar12 == (uStack00000014 & 0x7ff00000))) {
        FUN_1001eb2c(uStack00000040,iStack00000044);
        uVar20 = FUN_1001eb14();
        uVar20 = FUN_1001e946(uStack00000040,iStack00000044,(int)uVar20,
                              (int)((ulonglong)uVar20 >> 0x20));
        uVar3 = (undefined4)((ulonglong)uVar20 >> 0x20);
        uVar2 = (undefined4)uVar20;
        if ((iVar8 == 0 && iStack00000010 == 0) && (uVar19 & 0xfffff00000000) == 0) {
          iVar4 = FUN_1001ea3c(uVar2,uVar3,0x94a03595,0x3fcfffff);
        }
        else {
          iVar4 = FUN_1001ea3c(uVar2,uVar3,0x94a03595,0x3fdfffff);
          if (iVar4 != 0) goto LAB_100205d8;
          iVar4 = FUN_1001ea58(uVar2,uVar3,0x35afe535,0x3fe00000);
        }
        if (iVar4 != 0) goto LAB_100205d8;
      }
    }
    FUN_10025a44();
    FUN_10025a44();
    FUN_10025a44();
    FUN_10025a44();
  }
  *unaff_r8 = 0x22;
LAB_100205d8:
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  uVar2 = FUN_10020268();
  return uVar2;
}



/* FUN_1001ff26 at 1001ff26 */

undefined4 FUN_1001ff26(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 unaff_r4;
  undefined4 *in_stack_00000018;
  undefined4 uStack00000064;
  
  iVar1 = FUN_100251f4(&uStack00000064,&DAT_1002acd4);
  if (iVar1 == 0) {
    if (in_stack_00000018 != (undefined4 *)0x0) {
      *in_stack_00000018 = unaff_r4;
    }
    return 0;
  }
  if (*uStack00000064 == '(') {
    FUN_10020a30();
  }
  FUN_1002592c("");
  uVar2 = FUN_10020268();
  return uVar2;
}



/* FUN_1001ff3e at 1001ff3e */

void FUN_1001ff3e(void)

{
  FUN_1002592c("");
  FUN_10020268();
  return;
}



/* FUN_1001ff8a at 1001ff8a */

void FUN_1001ff8a(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  undefined4 *unaff_r8;
  char cVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  undefined8 uVar17;
  int in_stack_00000010;
  uint in_stack_00000014;
  int iStack00000024;
  uint in_stack_00000028;
  int in_stack_0000002c;
  undefined4 uStack00000040;
  int iStack00000044;
  int in_stack_00000048;
  int in_stack_0000006c;
  int in_stack_00000070;
  
  uVar16 = CONCAT44(in_stack_00000014,in_stack_00000010);
  iStack00000024 = 0;
  iVar1 = FUN_10025b2c();
  if (iVar1 == 0) {
    FUN_100208dc();
  }
  uVar7 = in_stack_00000028 & (int)~in_stack_00000028 >> 0x1f;
  uVar2 = in_stack_00000048 - in_stack_0000002c & (int)in_stack_00000028 >> 0x1f;
  while( true ) {
    in_stack_00000014 = (uint)(uVar16 >> 0x20);
    in_stack_00000010 = (int)uVar16;
    iVar4 = FUN_100259c0();
    if (iVar4 == 0) break;
    FUN_1001f4d4(iVar4 + 0xc,iVar1 + 0xc,(*(int *)(iVar1 + 0x10) + 2) * 4);
    iVar4 = FUN_10026384();
    if ((iVar4 == 0) || (iVar4 = FUN_10025ccc(), iVar4 == 0)) break;
    if (in_stack_0000006c < 0) {
      uVar10 = uVar7 - in_stack_0000006c;
      uVar13 = uVar2;
    }
    else {
      uVar13 = in_stack_0000006c + uVar2;
      uVar10 = uVar7;
    }
    iVar6 = 0x36 - in_stack_00000070;
    iVar11 = (in_stack_0000006c - iStack00000024) + in_stack_00000070 + -1;
    if (iVar11 < -0x3fe) {
      iVar6 = iVar6 - (-0x3fe - iVar11);
    }
    uVar8 = uVar13 + iVar6;
    uVar12 = uVar10 + iVar6 + iStack00000024;
    uVar10 = uVar13;
    if ((int)uVar8 < (int)uVar13) {
      uVar10 = uVar8;
    }
    if ((int)uVar12 < (int)uVar10) {
      uVar10 = uVar12;
    }
    if (0 < (int)uVar10) {
      uVar8 = uVar8 - uVar10;
      uVar12 = uVar12 - uVar10;
      uVar13 = uVar13 - uVar10;
    }
    if (0 < (int)uVar2) {
      iVar4 = FUN_10025ea8();
      if ((iVar4 == 0) || (iVar6 = FUN_10025cf8(), iVar6 == 0)) break;
      FUN_10025a44();
    }
    if ((((((0 < (int)uVar8) && (iVar6 = FUN_10025fb4(), iVar6 == 0)) ||
          ((0 < (int)in_stack_00000028 && (iVar6 = FUN_10025ea8(), iVar6 == 0)))) ||
         ((0 < (int)uVar12 && (iVar6 = FUN_10025fb4(), iVar6 == 0)))) ||
        ((0 < (int)uVar13 && (iVar4 = FUN_10025fb4(), iVar4 == 0)))) ||
       (iVar6 = FUN_100260e4(), iVar6 == 0)) break;
    iVar9 = *(int *)(iVar6 + 0xc);
    *(undefined4 *)(iVar6 + 0xc) = 0;
    iVar11 = FUN_100260a8(iVar6,iVar4);
    cVar14 = iVar11 == 0;
    if (iVar11 < 0) {
      FUN_10020a86();
    }
    if (cVar14 != '\0') {
      FUN_100209c2();
    }
    uVar15 = FUN_10026448(iVar6,iVar4);
    uVar5 = (undefined4)((ulonglong)uVar15 >> 0x20);
    uVar3 = (undefined4)uVar15;
    iVar4 = FUN_1001ea48(uVar3,uVar5,0,0x40000000);
    if (iVar4 == 0) {
      uVar15 = FUN_1001e9a6(uVar3,uVar5,0,0x3fe00000);
      if (iVar9 != 0) {
        FUN_100200e8();
        return;
      }
    }
    else {
      if (iVar9 != 0) {
        FUN_100200e8();
        return;
      }
      if (in_stack_00000010 != 0) {
        if (uVar16 != 1) {
LAB_100206ae:
          FUN_100200e8();
          return;
        }
        *unaff_r8 = 0x22;
        goto LAB_100205d8;
      }
      if ((uVar16 & 0xfffff00000000) != 0) goto LAB_100206ae;
      iVar4 = FUN_1001ea3c(uVar3,uVar5,0,0x3ff00000);
      if (iVar4 != 0) {
        FUN_100209ae();
      }
      uVar15 = FUN_1001e9a6(uVar3,uVar5,0,0x3fe00000);
    }
    iStack00000044 = (int)((ulonglong)uVar15 >> 0x20);
    uStack00000040 = (undefined4)uVar15;
    iVar4 = iStack00000044 + -0x80000000;
    uVar10 = in_stack_00000014 & 0x7ff00000;
    if (uVar10 == 0x7fe00000) {
      uVar17 = FUN_1002628c(in_stack_00000010,in_stack_00000014 + 0xfcb00000);
      uVar17 = FUN_1001e9a6((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uStack00000040,iVar4);
      uVar17 = FUN_1001e958((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),in_stack_00000010,
                            in_stack_00000014 + 0xfcb00000);
      uVar13 = (uint)((ulonglong)uVar17 >> 0x20);
      if ((uVar13 & 0x7ff00000) < 0x7ca00000) {
        uVar16 = CONCAT44(uVar13 + 0x3500000,(int)uVar17);
        goto LAB_10020178;
      }
      if (uVar16 == 0x7fefffffffffffff) break;
      uVar16 = 0x7fefffffffffffff;
    }
    else {
      if ((iStack00000024 != 0) && (uVar10 < 0x6a00001)) {
        iVar6 = FUN_1001ea48(uStack00000040,iStack00000044,0xffc00000,0x41dfffff);
        if (iVar6 != 0) {
          iVar4 = FUN_1001eafc(uStack00000040,iStack00000044);
          if (iVar4 == 0) {
            iVar4 = 1;
          }
          uVar15 = FUN_1001ea7c(iVar4);
          uVar17 = uVar15;
          if (iVar9 != 0) {
            uVar17 = FUN_10020982();
          }
          uStack00000040 = (undefined4)uVar17;
          iVar4 = (int)((ulonglong)uVar17 >> 0x20) + -0x80000000;
        }
        iVar4 = (iVar4 + 0x6b00000) - uVar10;
      }
      uVar17 = FUN_1002628c(in_stack_00000010,in_stack_00000014);
      uVar17 = FUN_1001e9a6(uStack00000040,iVar4,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
      uVar16 = FUN_1001e958((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),in_stack_00000010,
                            in_stack_00000014);
LAB_10020178:
      in_stack_00000014 = (uint)(uVar16 >> 0x20);
      in_stack_00000010 = (int)uVar16;
      iStack00000044 = (int)((ulonglong)uVar15 >> 0x20);
      uStack00000040 = (undefined4)uVar15;
      if ((iStack00000024 == 0) && (uVar10 == (in_stack_00000014 & 0x7ff00000))) {
        FUN_1001eb2c(uStack00000040,iStack00000044);
        uVar15 = FUN_1001eb14();
        uVar15 = FUN_1001e946(uStack00000040,iStack00000044,(int)uVar15,
                              (int)((ulonglong)uVar15 >> 0x20));
        uVar5 = (undefined4)((ulonglong)uVar15 >> 0x20);
        uVar3 = (undefined4)uVar15;
        if ((iVar9 == 0 && in_stack_00000010 == 0) && (uVar16 & 0xfffff00000000) == 0) {
          iVar4 = FUN_1001ea3c(uVar3,uVar5,0x94a03595,0x3fcfffff);
        }
        else {
          iVar4 = FUN_1001ea3c(uVar3,uVar5,0x94a03595,0x3fdfffff);
          if (iVar4 != 0) goto LAB_100205d8;
          iVar4 = FUN_1001ea58(uVar3,uVar5,0x35afe535,0x3fe00000);
        }
        if (iVar4 != 0) goto LAB_100205d8;
      }
    }
    FUN_10025a44();
    FUN_10025a44();
    FUN_10025a44();
    FUN_10025a44();
  }
  *unaff_r8 = 0x22;
LAB_100205d8:
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10020268();
  return;
}



/* FUN_100200e8 at 100200e8 */

void FUN_100200e8(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 uVar9;
  undefined4 *unaff_r8;
  char cVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  undefined8 uVar13;
  int in_stack_00000010;
  uint uStack00000014;
  int in_stack_00000024;
  int in_stack_00000028;
  uint in_stack_0000002c;
  undefined4 in_stack_00000030;
  int in_stack_00000034;
  int in_stack_00000038;
  undefined4 in_stack_00000040;
  int in_stack_00000044;
  int in_stack_00000048;
  int in_stack_0000004c;
  int in_stack_00000050;
  int in_stack_0000006c;
  int in_stack_00000070;
  
  uVar11 = CONCAT44(unaff_r7,unaff_r6);
  uVar13 = CONCAT44(in_stack_00000044,in_stack_00000040);
  while( true ) {
    uVar9 = (undefined4)(uVar11 >> 0x20);
    in_stack_00000044 = (int)((ulonglong)uVar13 >> 0x20);
    in_stack_00000040 = (undefined4)uVar13;
    uVar6 = in_stack_0000002c & 0x7ff00000;
    if (uVar6 == 0x7fe00000) break;
    if ((in_stack_00000024 != 0) && (uVar6 < 0x6a00001)) {
      iVar2 = FUN_1001ea48(in_stack_00000040,in_stack_00000044,0xffc00000,0x41dfffff);
      if (iVar2 != 0) {
        iVar2 = FUN_1001eafc(in_stack_00000040,in_stack_00000044);
        if (iVar2 == 0) {
          iVar2 = 1;
        }
        uVar13 = FUN_1001ea7c(iVar2);
        uVar12 = uVar13;
        if (in_stack_00000038 != 0) {
          uVar12 = FUN_10020982();
        }
        in_stack_00000030 = (undefined4)uVar12;
        in_stack_00000034 = (int)((ulonglong)uVar12 >> 0x20) + -0x80000000;
      }
      in_stack_00000034 = (in_stack_00000034 + 0x6b00000) - uVar6;
    }
    uVar12 = FUN_1002628c((int)uVar11,uVar9);
    uVar12 = FUN_1001e9a6(in_stack_00000030,in_stack_00000034,(int)uVar12,
                          (int)((ulonglong)uVar12 >> 0x20));
    uVar11 = FUN_1001e958((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar11,uVar9);
LAB_10020178:
    uStack00000014 = (uint)(uVar11 >> 0x20);
    in_stack_00000010 = (int)uVar11;
    in_stack_00000044 = (int)((ulonglong)uVar13 >> 0x20);
    in_stack_00000040 = (undefined4)uVar13;
    if ((in_stack_00000024 == 0) && (uVar6 == (uStack00000014 & 0x7ff00000))) {
      FUN_1001eb2c(in_stack_00000040,in_stack_00000044);
      uVar13 = FUN_1001eb14();
      uVar13 = FUN_1001e946(in_stack_00000040,in_stack_00000044,(int)uVar13,
                            (int)((ulonglong)uVar13 >> 0x20));
      uVar4 = (undefined4)((ulonglong)uVar13 >> 0x20);
      uVar9 = (undefined4)uVar13;
      if ((in_stack_00000038 == 0 && in_stack_00000010 == 0) && (uVar11 & 0xfffff00000000) == 0) {
        iVar2 = FUN_1001ea3c(uVar9,uVar4,0x94a03595,0x3fcfffff);
      }
      else {
        iVar2 = FUN_1001ea3c(uVar9,uVar4,0x94a03595,0x3fdfffff);
        if (iVar2 != 0) goto LAB_100205d8;
        iVar2 = FUN_1001ea58(uVar9,uVar4,0x35afe535,0x3fe00000);
      }
      if (iVar2 != 0) goto LAB_100205d8;
    }
LAB_10020188:
    uStack00000014 = (uint)(uVar11 >> 0x20);
    in_stack_00000010 = (int)uVar11;
    FUN_10025a44();
    FUN_10025a44();
    FUN_10025a44();
    FUN_10025a44();
    iVar2 = FUN_100259c0();
    if (iVar2 == 0) goto LAB_100205ce;
    FUN_1001f4d4(iVar2 + 0xc,in_stack_0000004c + 0xc,(*(int *)(in_stack_0000004c + 0x10) + 2) * 4);
    iVar2 = FUN_10026384();
    if ((iVar2 == 0) || (iVar2 = FUN_10025ccc(), iVar2 == 0)) goto LAB_100205ce;
    if (in_stack_0000006c < 0) {
      iVar1 = in_stack_00000050 - in_stack_0000006c;
      iVar8 = in_stack_00000048;
    }
    else {
      iVar8 = in_stack_0000006c + in_stack_00000048;
      iVar1 = in_stack_00000050;
    }
    iVar5 = 0x36 - in_stack_00000070;
    iVar7 = (in_stack_0000006c - in_stack_00000024) + in_stack_00000070 + -1;
    if (iVar7 < -0x3fe) {
      iVar5 = iVar5 - (-0x3fe - iVar7);
    }
    iVar7 = iVar8 + iVar5;
    iVar5 = iVar1 + iVar5 + in_stack_00000024;
    iVar1 = iVar8;
    if (iVar7 < iVar8) {
      iVar1 = iVar7;
    }
    if (iVar5 < iVar1) {
      iVar1 = iVar5;
    }
    if (0 < iVar1) {
      iVar7 = iVar7 - iVar1;
      iVar5 = iVar5 - iVar1;
      iVar8 = iVar8 - iVar1;
    }
    if (0 < in_stack_00000048) {
      iVar2 = FUN_10025ea8();
      if ((iVar2 == 0) || (iVar1 = FUN_10025cf8(), iVar1 == 0)) goto LAB_100205ce;
      FUN_10025a44();
    }
    if ((((((0 < iVar7) && (iVar1 = FUN_10025fb4(), iVar1 == 0)) ||
          ((0 < in_stack_00000028 && (iVar1 = FUN_10025ea8(), iVar1 == 0)))) ||
         ((0 < iVar5 && (iVar1 = FUN_10025fb4(), iVar1 == 0)))) ||
        ((0 < iVar8 && (iVar2 = FUN_10025fb4(), iVar2 == 0)))) ||
       (iVar1 = FUN_100260e4(), iVar1 == 0)) goto LAB_100205ce;
    in_stack_00000038 = *(int *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0xc) = 0;
    iVar8 = FUN_100260a8(iVar1,iVar2);
    cVar10 = iVar8 == 0;
    if (iVar8 < 0) {
      FUN_10020a86();
    }
    in_stack_0000002c = uStack00000014;
    if (cVar10 != '\0') {
      FUN_100209c2();
    }
    uVar13 = FUN_10026448(iVar1,iVar2);
    uVar4 = (undefined4)((ulonglong)uVar13 >> 0x20);
    uVar9 = (undefined4)uVar13;
    iVar2 = FUN_1001ea48(uVar9,uVar4,0,0x40000000);
    if (iVar2 == 0) {
      uVar13 = FUN_1001e9a6(uVar9,uVar4,0,0x3fe00000);
      if (in_stack_00000038 != 0) {
        FUN_100200e8();
        return;
      }
    }
    else {
      if (in_stack_00000038 != 0) {
        FUN_100200e8();
        return;
      }
      if (in_stack_00000010 != 0) {
        if (uVar11 != 1) goto LAB_100206ae;
        *unaff_r8 = 0x22;
        goto LAB_100205d8;
      }
      if ((uVar11 & 0xfffff00000000) != 0) {
LAB_100206ae:
        FUN_100200e8();
        return;
      }
      iVar2 = FUN_1001ea3c(uVar9,uVar4,0,0x3ff00000);
      if (iVar2 != 0) {
        FUN_100209ae();
      }
      uVar13 = FUN_1001e9a6(uVar9,uVar4,0,0x3fe00000);
    }
    in_stack_00000044 = (int)((ulonglong)uVar13 >> 0x20);
    in_stack_00000040 = (undefined4)uVar13;
    in_stack_00000034 = in_stack_00000044 + -0x80000000;
    in_stack_00000030 = in_stack_00000040;
  }
  uVar12 = FUN_1002628c(in_stack_00000010,in_stack_0000002c + 0xfcb00000);
  uVar12 = FUN_1001e9a6((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),in_stack_00000030,
                        in_stack_00000034);
  uVar12 = FUN_1001e958((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),in_stack_00000010,
                        in_stack_0000002c + 0xfcb00000);
  uVar3 = (uint)((ulonglong)uVar12 >> 0x20);
  if ((uVar3 & 0x7ff00000) < 0x7ca00000) {
    uVar11 = CONCAT44(uVar3 + 0x3500000,(int)uVar12);
    goto LAB_10020178;
  }
  if (uVar11 != 0x7fefffffffffffff) {
    uVar11 = 0x7fefffffffffffff;
    goto LAB_10020188;
  }
LAB_100205ce:
  *unaff_r8 = 0x22;
LAB_100205d8:
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10020268();
  return;
}



/* FUN_10020148 at 10020148 */

void FUN_10020148(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 uVar8;
  undefined4 *unaff_r8;
  uint unaff_r10;
  char cVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  undefined8 uVar12;
  int iStack00000010;
  uint uStack00000014;
  int in_stack_00000024;
  int in_stack_00000028;
  int in_stack_00000038;
  undefined4 in_stack_00000040;
  int in_stack_00000044;
  int in_stack_00000048;
  int in_stack_0000004c;
  int in_stack_00000050;
  undefined4 in_stack_00000058;
  int in_stack_0000005c;
  int in_stack_0000006c;
  int in_stack_00000070;
  
  uVar11 = CONCAT44(unaff_r7,unaff_r6);
  uVar12 = CONCAT44(in_stack_00000044,in_stack_00000040);
code_r0x10020148:
  in_stack_00000040 = in_stack_00000058;
LAB_1002014c:
  in_stack_0000005c = (in_stack_0000005c + 0x6b00000) - unaff_r10;
LAB_10020156:
  uVar8 = (undefined4)(uVar11 >> 0x20);
  uVar10 = FUN_1002628c((int)uVar11,uVar8);
  uVar10 = FUN_1001e9a6(in_stack_00000040,in_stack_0000005c,(int)uVar10,
                        (int)((ulonglong)uVar10 >> 0x20));
  uVar11 = FUN_1001e958((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),(int)uVar11,uVar8);
LAB_10020178:
  uStack00000014 = (uint)(uVar11 >> 0x20);
  iStack00000010 = (int)uVar11;
  in_stack_00000044 = (int)((ulonglong)uVar12 >> 0x20);
  in_stack_00000040 = (undefined4)uVar12;
  if ((in_stack_00000024 == 0) && (unaff_r10 == (uStack00000014 & 0x7ff00000))) {
    FUN_1001eb2c(in_stack_00000040,in_stack_00000044);
    uVar12 = FUN_1001eb14();
    uVar12 = FUN_1001e946(in_stack_00000040,in_stack_00000044,(int)uVar12,
                          (int)((ulonglong)uVar12 >> 0x20));
    uVar4 = (undefined4)((ulonglong)uVar12 >> 0x20);
    uVar8 = (undefined4)uVar12;
    if ((in_stack_00000038 == 0 && iStack00000010 == 0) && (uVar11 & 0xfffff00000000) == 0) {
      iVar2 = FUN_1001ea3c(uVar8,uVar4,0x94a03595,0x3fcfffff);
    }
    else {
      iVar2 = FUN_1001ea3c(uVar8,uVar4,0x94a03595,0x3fdfffff);
      if (iVar2 != 0) goto LAB_100205d8;
      iVar2 = FUN_1001ea58(uVar8,uVar4,0x35afe535,0x3fe00000);
    }
    if (iVar2 != 0) {
LAB_100205d8:
      FUN_10025a44();
      FUN_10025a44();
      FUN_10025a44();
      FUN_10025a44();
      FUN_10025a44();
      FUN_10020268();
      return;
    }
  }
  do {
    uStack00000014 = (uint)(uVar11 >> 0x20);
    iStack00000010 = (int)uVar11;
    FUN_10025a44();
    FUN_10025a44();
    FUN_10025a44();
    FUN_10025a44();
    iVar2 = FUN_100259c0();
    if (iVar2 == 0) {
LAB_100205ce:
      *unaff_r8 = 0x22;
      goto LAB_100205d8;
    }
    FUN_1001f4d4(iVar2 + 0xc,in_stack_0000004c + 0xc,(*(int *)(in_stack_0000004c + 0x10) + 2) * 4);
    iVar2 = FUN_10026384();
    if ((iVar2 == 0) || (iVar2 = FUN_10025ccc(), iVar2 == 0)) goto LAB_100205ce;
    if (in_stack_0000006c < 0) {
      iVar1 = in_stack_00000050 - in_stack_0000006c;
      iVar7 = in_stack_00000048;
    }
    else {
      iVar7 = in_stack_0000006c + in_stack_00000048;
      iVar1 = in_stack_00000050;
    }
    iVar5 = 0x36 - in_stack_00000070;
    iVar6 = (in_stack_0000006c - in_stack_00000024) + in_stack_00000070 + -1;
    if (iVar6 < -0x3fe) {
      iVar5 = iVar5 - (-0x3fe - iVar6);
    }
    iVar6 = iVar7 + iVar5;
    iVar5 = iVar1 + iVar5 + in_stack_00000024;
    iVar1 = iVar7;
    if (iVar6 < iVar7) {
      iVar1 = iVar6;
    }
    if (iVar5 < iVar1) {
      iVar1 = iVar5;
    }
    if (0 < iVar1) {
      iVar6 = iVar6 - iVar1;
      iVar5 = iVar5 - iVar1;
      iVar7 = iVar7 - iVar1;
    }
    if (0 < in_stack_00000048) {
      iVar2 = FUN_10025ea8();
      if ((iVar2 == 0) || (iVar1 = FUN_10025cf8(), iVar1 == 0)) goto LAB_100205ce;
      FUN_10025a44();
    }
    if ((((((0 < iVar6) && (iVar1 = FUN_10025fb4(), iVar1 == 0)) ||
          ((0 < in_stack_00000028 && (iVar1 = FUN_10025ea8(), iVar1 == 0)))) ||
         ((0 < iVar5 && (iVar1 = FUN_10025fb4(), iVar1 == 0)))) ||
        ((0 < iVar7 && (iVar2 = FUN_10025fb4(), iVar2 == 0)))) ||
       (iVar1 = FUN_100260e4(), iVar1 == 0)) goto LAB_100205ce;
    in_stack_00000038 = *(int *)(iVar1 + 0xc);
    *(undefined4 *)(iVar1 + 0xc) = 0;
    iVar7 = FUN_100260a8(iVar1,iVar2);
    cVar9 = iVar7 == 0;
    if (iVar7 < 0) {
      FUN_10020a86();
    }
    if (cVar9 != '\0') {
      FUN_100209c2();
    }
    uVar12 = FUN_10026448(iVar1,iVar2);
    uVar4 = (undefined4)((ulonglong)uVar12 >> 0x20);
    uVar8 = (undefined4)uVar12;
    iVar2 = FUN_1001ea48(uVar8,uVar4,0,0x40000000);
    if (iVar2 == 0) {
      uVar12 = FUN_1001e9a6(uVar8,uVar4,0,0x3fe00000);
      if (in_stack_00000038 != 0) {
        FUN_100200e8();
        return;
      }
    }
    else {
      if (in_stack_00000038 != 0) {
        FUN_100200e8();
        return;
      }
      if (iStack00000010 != 0) {
        if (uVar11 != 1) {
LAB_100206ae:
          FUN_100200e8();
          return;
        }
        *unaff_r8 = 0x22;
        goto LAB_100205d8;
      }
      if ((uVar11 & 0xfffff00000000) != 0) goto LAB_100206ae;
      iVar2 = FUN_1001ea3c(uVar8,uVar4,0,0x3ff00000);
      if (iVar2 != 0) {
        FUN_100209ae();
      }
      uVar12 = FUN_1001e9a6(uVar8,uVar4,0,0x3fe00000);
    }
    in_stack_00000044 = (int)((ulonglong)uVar12 >> 0x20);
    in_stack_00000040 = (undefined4)uVar12;
    in_stack_0000005c = in_stack_00000044 + -0x80000000;
    unaff_r10 = uStack00000014 & 0x7ff00000;
    if (unaff_r10 != 0x7fe00000) {
      if ((in_stack_00000024 == 0) || (0x6a00000 < unaff_r10)) goto LAB_10020156;
      iVar2 = FUN_1001ea48(in_stack_00000040,in_stack_00000044,0xffc00000,0x41dfffff);
      if (iVar2 == 0) goto LAB_1002014c;
      iVar2 = FUN_1001eafc(in_stack_00000040,in_stack_00000044);
      if (iVar2 == 0) {
        iVar2 = 1;
      }
      uVar12 = FUN_1001ea7c(iVar2);
      uVar10 = uVar12;
      if (in_stack_00000038 != 0) {
        uVar10 = FUN_10020982();
      }
      in_stack_00000058 = (undefined4)uVar10;
      in_stack_0000005c = (int)((ulonglong)uVar10 >> 0x20) + -0x80000000;
      goto code_r0x10020148;
    }
    uVar10 = FUN_1002628c(iStack00000010,uStack00000014 + 0xfcb00000);
    uVar10 = FUN_1001e9a6((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),in_stack_00000040,
                          in_stack_0000005c);
    uVar10 = FUN_1001e958((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),iStack00000010,
                          uStack00000014 + 0xfcb00000);
    uVar3 = (uint)((ulonglong)uVar10 >> 0x20);
    if ((uVar3 & 0x7ff00000) < 0x7ca00000) break;
    if (uVar11 == 0x7fefffffffffffff) goto LAB_100205ce;
    uVar11 = 0x7fefffffffffffff;
  } while( true );
  uVar11 = CONCAT44(uVar3 + 0x3500000,(int)uVar10);
  goto LAB_10020178;
}



/* FUN_10020268 at 10020268 */

void FUN_10020268(void)

{
  undefined4 *in_stack_00000018;
  undefined4 in_stack_00000064;
  
  if (in_stack_00000018 != (undefined4 *)0x0) {
    *in_stack_00000018 = in_stack_00000064;
  }
  return;
}



/* FUN_1002037c at 1002037c */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1002037c(int param_1,int param_2)

{
  bool bVar1;
  ulonglong uVar2;
  int iVar3;
  uint extraout_r1;
  int extraout_r2;
  undefined4 *puVar4;
  uint unaff_r4;
  uint uVar5;
  int unaff_r6;
  int iVar6;
  undefined4 *unaff_r8;
  uint unaff_r9;
  int unaff_r10;
  int extraout_r12;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined4 in_stack_00000010;
  int in_stack_00000014;
  byte *pbStack00000064;
  
  do {
    pbStack00000064 = (byte *)(param_2 + 1);
    uVar8 = CONCAT44(pbStack00000064,param_1);
    puVar4 = (undefined4 *)(*pbStack00000064 - 0x30);
    if (puVar4 < (undefined4 *)0xa) {
      param_1 = param_1 + 1;
      if (puVar4 == (undefined4 *)0x0) {
        uVar8 = FUN_10020caa();
        param_1 = extraout_r2;
      }
      if (param_1 == 1) {
        uVar8 = FUN_10020ca6();
      }
      iVar3 = unaff_r6 + 1;
      iVar6 = iVar3;
      uVar5 = unaff_r9;
      do {
        if (iVar6 + -1 < 9) {
          uVar5 = uVar5 * 10;
        }
        else if (iVar6 < 0x11) {
          unaff_r10 = unaff_r10 * 10;
        }
        iVar6 = iVar6 + 1;
      } while ((iVar6 - unaff_r6) + -1 < (int)uVar8);
    }
    else {
      uVar7 = FUN_1001feee(param_1,pbStack00000064,1);
      if ((int)uVar7 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      puVar4 = &DAT_1002b330;
      bVar1 = false;
      uVar7 = uVar7 & 0xffffffff00000000;
      iVar6 = unaff_r10;
      do {
        if ((unaff_r4 & 1) != 0) {
          uVar7 = FUN_1001e9a6((int)uVar7,(int)(uVar7 >> 0x20),*puVar4,puVar4[1]);
          bVar1 = true;
        }
        iVar6 = iVar6 + 1;
        unaff_r4 = (int)unaff_r4 >> 1;
        puVar4 = puVar4 + 2;
      } while (unaff_r4 != 1);
      uVar2 = CONCAT44(in_stack_00000014,in_stack_00000010);
      if (bVar1) {
        uVar2 = uVar7;
      }
      in_stack_00000014 = (int)(uVar2 >> 0x20);
      in_stack_00000010 = (undefined4)uVar2;
      FUN_1001e9a6((&DAT_1002b330)[iVar6 * 2],(&DAT_1002b334)[iVar6 * 2],in_stack_00000010,
                   in_stack_00000014 + -0x3500000);
      if (0x7ca00000 < (extraout_r1 & 0x7ff00000)) {
        *unaff_r8 = 0x22;
        FUN_10020268();
        return;
      }
      if ((extraout_r1 & 0x7ff00000) < 0x7c900001) {
        FUN_1001ff8a();
      }
      uVar5 = 0x7fefffff;
      in_stack_00000010 = 0xffffffff;
      in_stack_00000014 = 0x7fefffff;
      uVar8 = FUN_1001ff8a();
      unaff_r10 = (int)((ulonglong)uVar8 >> 0x20);
      uVar8 = CONCAT44(iVar6,(int)uVar8);
      unaff_r4 = unaff_r9;
      iVar3 = extraout_r12;
    }
    param_2 = (int)((ulonglong)uVar8 >> 0x20);
    iVar3 = (int)uVar8 + -1 + iVar3;
    unaff_r6 = iVar3 + 1;
    if (8 < iVar3) {
      if (unaff_r6 < 0x11) {
        FUN_1002037c(0,param_2,unaff_r10,unaff_r10 * 10);
        return;
      }
      FUN_1002037c(0);
      return;
    }
    param_1 = 0;
    unaff_r9 = (int)puVar4 + uVar5 * 10;
  } while( true );
}



/* FUN_1002037e at 1002037e */

/* WARNING: Control flow encountered bad instruction data */

void FUN_1002037e(int param_1,undefined4 param_2,undefined4 param_3,byte *param_4)

{
  bool bVar1;
  ulonglong uVar2;
  int iVar3;
  uint extraout_r1;
  int extraout_r2;
  undefined4 *puVar4;
  uint unaff_r4;
  uint uVar5;
  int unaff_r6;
  int iVar6;
  undefined4 *unaff_r8;
  uint unaff_r9;
  int unaff_r10;
  int extraout_r12;
  ulonglong uVar7;
  undefined8 uVar8;
  undefined4 in_stack_00000010;
  int in_stack_00000014;
  byte *pbStack00000064;
  
  do {
    uVar8 = CONCAT44(param_4,param_1);
    puVar4 = (undefined4 *)(*param_4 - 0x30);
    pbStack00000064 = param_4;
    if (puVar4 < (undefined4 *)0xa) {
      param_1 = param_1 + 1;
      if (puVar4 == (undefined4 *)0x0) {
        uVar8 = FUN_10020caa();
        param_1 = extraout_r2;
      }
      if (param_1 == 1) {
        uVar8 = FUN_10020ca6();
      }
      iVar3 = unaff_r6 + 1;
      iVar6 = iVar3;
      uVar5 = unaff_r9;
      do {
        if (iVar6 + -1 < 9) {
          uVar5 = uVar5 * 10;
        }
        else if (iVar6 < 0x11) {
          unaff_r10 = unaff_r10 * 10;
        }
        iVar6 = iVar6 + 1;
      } while ((iVar6 - unaff_r6) + -1 < (int)uVar8);
    }
    else {
      uVar7 = FUN_1001feee(param_1,param_4,1);
      if ((int)uVar7 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      puVar4 = &DAT_1002b330;
      bVar1 = false;
      uVar7 = uVar7 & 0xffffffff00000000;
      iVar6 = unaff_r10;
      do {
        if ((unaff_r4 & 1) != 0) {
          uVar7 = FUN_1001e9a6((int)uVar7,(int)(uVar7 >> 0x20),*puVar4,puVar4[1]);
          bVar1 = true;
        }
        iVar6 = iVar6 + 1;
        unaff_r4 = (int)unaff_r4 >> 1;
        puVar4 = puVar4 + 2;
      } while (unaff_r4 != 1);
      uVar2 = CONCAT44(in_stack_00000014,in_stack_00000010);
      if (bVar1) {
        uVar2 = uVar7;
      }
      in_stack_00000014 = (int)(uVar2 >> 0x20);
      in_stack_00000010 = (undefined4)uVar2;
      FUN_1001e9a6((&DAT_1002b330)[iVar6 * 2],(&DAT_1002b334)[iVar6 * 2],in_stack_00000010,
                   in_stack_00000014 + -0x3500000);
      if (0x7ca00000 < (extraout_r1 & 0x7ff00000)) {
        *unaff_r8 = 0x22;
        FUN_10020268();
        return;
      }
      if ((extraout_r1 & 0x7ff00000) < 0x7c900001) {
        FUN_1001ff8a();
      }
      uVar5 = 0x7fefffff;
      in_stack_00000010 = 0xffffffff;
      in_stack_00000014 = 0x7fefffff;
      uVar8 = FUN_1001ff8a();
      unaff_r10 = (int)((ulonglong)uVar8 >> 0x20);
      uVar8 = CONCAT44(iVar6,(int)uVar8);
      unaff_r4 = unaff_r9;
      iVar3 = extraout_r12;
    }
    iVar6 = (int)((ulonglong)uVar8 >> 0x20);
    iVar3 = (int)uVar8 + -1 + iVar3;
    unaff_r6 = iVar3 + 1;
    if (8 < iVar3) {
      if (unaff_r6 < 0x11) {
        FUN_1002037c(0,iVar6,unaff_r10,unaff_r10 * 10);
        return;
      }
      FUN_1002037c(0);
      return;
    }
    param_1 = 0;
    unaff_r9 = (int)puVar4 + uVar5 * 10;
    param_4 = (byte *)(iVar6 + 1);
  } while( true );
}



/* FUN_100206c0 at 100206c0 */

void FUN_100206c0(void)

{
  FUN_10020268();
  return;
}



/* FUN_100206c6 at 100206c6 */

longlong FUN_100206c6(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 in_r3;
  longlong lVar3;
  undefined4 *puStack00000000;
  int iStack00000004;
  undefined4 uStack00000008;
  uint uStack00000014;
  undefined4 *in_stack_00000018;
  int in_stack_0000001c;
  undefined4 in_stack_00000064;
  undefined4 uStack00000068;
  int in_stack_0000006c;
  undefined4 uStack00000070;
  uint in_stack_00000074;
  
  iStack00000004 = in_stack_0000001c;
  puStack00000000 = &uStack00000068;
  uStack00000008 = in_r3;
  uVar1 = FUN_100213c8();
  if ((uVar1 & 0xf) == 0) {
    uVar1 = 0;
    if (in_stack_00000018 != (undefined4 *)0x0) {
      *in_stack_00000018 = in_stack_00000064;
    }
    if (in_stack_0000001c != 0) {
      uVar1 = 0x80000000;
    }
    return (ulonglong)uVar1 << 0x20;
  }
  if ((uVar1 & 0xf) == 6) {
    lVar3 = FUN_10020268();
    return lVar3;
  }
  if (uStack00000068 != 0) {
    FUN_100264e4(&uStack00000070,0x35);
    FUN_10025a44();
  }
  switch(uVar1 & 0xf) {
  default:
    goto LAB_1002093e;
  case 1:
  case 5:
    uStack00000014 = in_stack_00000074 & 0xffefffff | (in_stack_0000006c + 0x433) * 0x100000;
    break;
  case 2:
    uStack00000014 = in_stack_00000074;
    break;
  case 3:
    uStack00000014 = 0x7ff00000;
    goto LAB_10020952;
  case 4:
    uStack00000014 = 0x7fffffff;
LAB_10020952:
    if (-1 < (int)(uVar1 << 0x17)) {
      lVar3 = FUN_100206c0();
      return lVar3;
    }
    goto LAB_1002092a;
  }
  if ((int)(uVar1 << 0x17) < 0) {
LAB_1002092a:
  }
  if ((uStack00000014 & 0x7ff00000) != 0) {
    lVar3 = FUN_10020268();
    return lVar3;
  }
LAB_1002093e:
  puVar2 = (undefined4 *)FUN_100219bc();
  *puVar2 = 0x22;
  lVar3 = FUN_10020268();
  return lVar3;
}



/* FUN_100207c4 at 100207c4 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_100207c4(void)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint extraout_r1;
  int extraout_r2;
  int iVar5;
  byte *pbVar6;
  int iVar7;
  int unaff_r4;
  uint uVar8;
  undefined4 *unaff_r5;
  int iVar9;
  undefined4 *unaff_r8;
  uint unaff_r9;
  int extraout_r12;
  longlong lVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined4 in_stack_00000010;
  int in_stack_00000014;
  
  if (0x134 < unaff_r4) {
    FUN_100208dc();
    return;
  }
  uVar8 = unaff_r4 >> 4;
  if (uVar8 == 1) {
    uVar8 = unaff_r9;
    iVar5 = 0;
    uVar12 = CONCAT44(in_stack_00000014,in_stack_00000010);
    goto LAB_10020818;
  }
  iVar5 = 0;
  iVar9 = 0;
  uVar2 = in_stack_00000010;
  uVar4 = in_stack_00000014;
  do {
    uVar11 = CONCAT44(uVar4,uVar2);
    unaff_r5 = &DAT_1002b330;
    bVar1 = false;
    do {
      if ((iVar5 + 1U & uVar8) != 0) {
        uVar11 = FUN_1001e9a6((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),*unaff_r5,unaff_r5[1]);
        bVar1 = true;
      }
      iVar9 = iVar9 + 1;
      uVar8 = (int)uVar8 >> 1;
      unaff_r5 = unaff_r5 + 2;
    } while (uVar8 != 1);
    uVar8 = unaff_r9;
    iVar5 = iVar9;
    uVar12 = CONCAT44(in_stack_00000014,in_stack_00000010);
    if (bVar1) {
      uVar12 = uVar11;
    }
LAB_10020818:
    in_stack_00000014 = (int)((ulonglong)uVar12 >> 0x20);
    in_stack_00000010 = (undefined4)uVar12;
    FUN_1001e9a6((&DAT_1002b330)[iVar5 * 2],(&DAT_1002b334)[iVar5 * 2],in_stack_00000010,
                 in_stack_00000014 + -0x3500000);
    if (0x7ca00000 < (extraout_r1 & 0x7ff00000)) {
      *unaff_r8 = 0x22;
      FUN_10020268();
      return;
    }
    if ((extraout_r1 & 0x7ff00000) < 0x7c900001) {
      FUN_1001ff8a();
    }
    unaff_r9 = 0x7fefffff;
    in_stack_00000010 = 0xffffffff;
    in_stack_00000014 = 0x7fefffff;
    uVar12 = FUN_1001ff8a();
    iVar9 = (int)((ulonglong)uVar12 >> 0x20);
    lVar10 = CONCAT44(iVar5,(int)uVar12);
    iVar5 = extraout_r12;
    while( true ) {
      iVar7 = (int)((ulonglong)lVar10 >> 0x20);
      iVar3 = (int)lVar10 + -1 + iVar5;
      if (8 < iVar3) {
        if (iVar3 + 1 < 0x11) {
          FUN_1002037c(0,iVar7,iVar9,iVar9 * 10);
          return;
        }
        FUN_1002037c(0);
        return;
      }
      unaff_r9 = (int)unaff_r5 + unaff_r9 * 10;
      pbVar6 = (byte *)(iVar7 + 1);
      lVar10 = ZEXT48(pbVar6) << 0x20;
      unaff_r5 = (undefined4 *)(*pbVar6 - 0x30);
      if ((undefined4 *)0x9 < unaff_r5) break;
      iVar5 = 1;
      if (unaff_r5 == (undefined4 *)0x0) {
        lVar10 = FUN_10020caa();
        iVar5 = extraout_r2;
      }
      if (iVar5 == 1) {
        lVar10 = FUN_10020ca6();
      }
      iVar5 = iVar3 + 2;
      iVar7 = iVar5;
      do {
        if (iVar7 + -1 < 9) {
          unaff_r9 = unaff_r9 * 10;
        }
        else if (iVar7 < 0x11) {
          iVar9 = iVar9 * 10;
        }
        iVar7 = iVar7 + 1;
      } while ((iVar7 - (iVar3 + 1)) + -1 < (int)lVar10);
    }
    uVar12 = FUN_1001feee(0,pbVar6,1);
    iVar5 = (int)uVar12 >> 0x20;
    uVar2 = 0;
    uVar4 = (int)((ulonglong)uVar12 >> 0x20);
  } while ((int)uVar12 == 0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* FUN_100208a0 at 100208a0 */

undefined4 FUN_100208a0(void)

{
  undefined4 uVar1;
  int iVar2;
  uint extraout_r1;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int extraout_r2;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  undefined4 unaff_r4;
  uint uVar14;
  uint uVar15;
  int unaff_r5;
  int unaff_r6;
  undefined4 *unaff_r8;
  char cVar16;
  ulonglong uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  int iStack00000010;
  uint uStack00000014;
  undefined4 *in_stack_00000018;
  int in_stack_00000020;
  uint uStack00000024;
  int in_stack_00000028;
  int in_stack_0000002c;
  undefined4 uStack00000040;
  int iStack00000044;
  int in_stack_00000048;
  undefined4 uStack00000064;
  int in_stack_00000068;
  int in_stack_0000006c;
  int in_stack_00000070;
  
  if (unaff_r5 == 0x6e) {
    FUN_1001ff26();
  }
  iVar2 = switchD_1001fd22::caseD_0();
  if (19999 < in_stack_0000002c) {
    in_stack_0000002c = 19999;
  }
  if (in_stack_00000028 != 0) {
    in_stack_0000002c = -in_stack_0000002c;
  }
  if (unaff_r6 == 0) {
    if (in_stack_00000020 == 0 && iVar2 == 0) {
      if (extraout_r2 == 0) {
        if (unaff_r5 == 0x69) {
LAB_100204e4:
          iVar2 = FUN_100251f4(&uStack00000064,&DAT_1002acc8);
          if (iVar2 == 0) {
            uVar1 = switchD_1001fd22::caseD_0();
            return uVar1;
          }
          uStack00000064 = uStack00000064 + -1;
          iVar2 = FUN_100251f4(&uStack00000064,"inity");
          if (iVar2 == 0) {
            uStack00000064 = uStack00000064 + 1;
          }
          uVar1 = FUN_10020268();
          return uVar1;
        }
        if (0x69 < unaff_r5) {
          FUN_100208a0();
        }
        if (unaff_r5 == 0x49) goto LAB_100204e4;
        if ((unaff_r5 == 0x4e) && (iVar2 = FUN_100251f4(&uStack00000064,&DAT_1002acd4), iVar2 != 0))
        {
          if (*uStack00000064 == '(') {
            FUN_10020a30();
          }
          FUN_1002592c("");
          uVar1 = FUN_10020268();
          return uVar1;
        }
      }
      if (in_stack_00000018 != (undefined4 *)0x0) {
        *in_stack_00000018 = unaff_r4;
      }
    }
    else if (in_stack_00000018 != (undefined4 *)0x0) {
      *in_stack_00000018 = uStack00000064;
    }
    return 0;
  }
  uVar10 = in_stack_0000002c - in_stack_00000048;
  iVar2 = unaff_r6;
  if (0x10 < unaff_r6) {
    iVar2 = 0x10;
  }
  uVar17 = FUN_1001ea7c();
  if (unaff_r6 < 10) {
LAB_1001fdea:
    uStack00000014 = (uint)(uVar17 >> 0x20);
    iStack00000010 = (int)uVar17;
    if (uVar10 == 0) {
      FUN_100206c0();
    }
    if ((int)uVar10 < 1) {
      if (-0x17 < (int)uVar10) {
        iVar2 = (in_stack_00000048 - in_stack_0000002c) * 8;
        FUN_1001e96a(iStack00000010,uStack00000014,*(undefined4 *)(&DAT_1002b358 + iVar2),
                     *(undefined4 *)(&DAT_1002b35c + iVar2));
        uVar1 = FUN_10020268();
        return uVar1;
      }
    }
    else {
      if ((int)uVar10 < 0x17) {
        FUN_100208c2();
      }
      if ((int)uVar10 <= 0x25 - unaff_r6) {
        iVar2 = (0xf - unaff_r6) * 8;
        uVar18 = FUN_1001e9a6(*(undefined4 *)(&DAT_1002b358 + iVar2),
                              *(undefined4 *)(&DAT_1002b35c + iVar2),iStack00000010,uStack00000014);
        iVar2 = (uVar10 - (0xf - unaff_r6)) * 8;
        FUN_1001e9a6((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),
                     *(undefined4 *)(&DAT_1002b358 + iVar2),*(undefined4 *)(&DAT_1002b35c + iVar2));
        uVar1 = FUN_10020268();
        return uVar1;
      }
    }
  }
  else {
    iVar4 = (iVar2 + -9) * 8;
    uVar18 = FUN_1001e9a6((int)uVar17,(int)(uVar17 >> 0x20),*(undefined4 *)(&DAT_1002b358 + iVar4),
                          *(undefined4 *)(&DAT_1002b35c + iVar4));
    uVar19 = FUN_1001ea7c();
    uVar17 = FUN_1001e958((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar19,
                          (int)((ulonglong)uVar19 >> 0x20));
    if (unaff_r6 < 0x10) goto LAB_1001fdea;
  }
  uStack00000014 = (uint)(uVar17 >> 0x20);
  iStack00000010 = (int)uVar17;
  uVar6 = (unaff_r6 - iVar2) + uVar10;
  if ((int)uVar6 < 1) {
    if (uVar6 == 0) {
      uVar1 = FUN_1001ff8a();
      return uVar1;
    }
    uVar6 = -uVar6;
    uVar15 = (int)uVar6 >> 4;
    if (((uVar6 & 0xf) != 0) &&
       (iVar2 = (uVar6 & 0xf) * 8,
       uVar17 = FUN_1001e96a(iStack00000010,uStack00000014,*(undefined4 *)(&DAT_1002b358 + iVar2),
                             *(undefined4 *)(&DAT_1002b35c + iVar2)), uVar15 == 0)) {
      FUN_1001ff8a();
    }
    if ((int)uVar15 < 0x20) {
      uStack00000024 = uVar15 & 0x10;
      if ((uVar15 & 0x10) != 0) {
        uStack00000024 = 0x6a;
      }
      puVar13 = &DAT_1002aef8;
      while( true ) {
        while( true ) {
          uVar6 = uVar15 & 1;
          uVar15 = (int)uVar15 >> 1;
          if (uVar6 != 0) break;
          puVar13 = puVar13 + 2;
        }
        uVar17 = FUN_1001e9a6((int)uVar17,(int)(uVar17 >> 0x20),*puVar13,puVar13[1]);
        uVar6 = (uint)(uVar17 >> 0x20);
        if (uVar15 == 0) break;
        puVar13 = puVar13 + 2;
      }
      if (uStack00000024 != 0) {
        uVar15 = (uVar6 & 0x7fffffff) >> 0x14;
        uVar11 = 0x6b - uVar15;
        if (0 < (int)uVar11) {
          if ((int)uVar11 < 0x20) {
            uVar17 = CONCAT44(uVar6,(uint)uVar17 & -1 << (uVar11 & 0xff));
          }
          else if ((int)uVar11 < 0x35) {
            uVar17 = (ulonglong)(uVar6 & -1 << (0x4b - uVar15 & 0xff)) << 0x20;
          }
          else {
            uVar17 = 0x370000000000000;
          }
        }
      }
      uStack00000014 = (uint)(uVar17 >> 0x20);
      iStack00000010 = (int)uVar17;
      iVar2 = FUN_1001ea2c(iStack00000010,uStack00000014,0,0);
      if (iVar2 == 0) goto LAB_1001ff8e;
    }
    *unaff_r8 = 0x22;
    uVar1 = FUN_10020268();
    return uVar1;
  }
  uVar15 = uVar6 & 0xf;
  if ((uVar6 & 0xf) == 0) {
    FUN_100207c4();
    uVar15 = extraout_r1;
  }
  uVar17 = FUN_1001e9a6(*(undefined4 *)(&DAT_1002b358 + uVar15 * 8),
                        *(undefined4 *)(&DAT_1002b35c + uVar15 * 8),iStack00000010,uStack00000014);
  if ((uVar6 & 0xfffffff0) != 0) {
    FUN_100207c4();
  }
  uStack00000024 = 0;
LAB_1001ff8e:
  iVar2 = FUN_10025b2c();
  if (iVar2 == 0) {
    FUN_100208dc();
  }
  uVar15 = uVar10 & (int)~uVar10 >> 0x1f;
  uVar6 = in_stack_00000048 - in_stack_0000002c & (int)uVar10 >> 0x1f;
  while( true ) {
    uStack00000014 = (uint)(uVar17 >> 0x20);
    iStack00000010 = (int)uVar17;
    iVar4 = FUN_100259c0();
    if (iVar4 == 0) break;
    FUN_1001f4d4(iVar4 + 0xc,iVar2 + 0xc,(*(int *)(iVar2 + 0x10) + 2) * 4);
    in_stack_00000068 = FUN_10026384();
    if ((in_stack_00000068 == 0) || (iVar4 = FUN_10025ccc(), iVar4 == 0)) break;
    if (in_stack_0000006c < 0) {
      uVar11 = uVar15 - in_stack_0000006c;
      uVar14 = uVar6;
    }
    else {
      uVar14 = in_stack_0000006c + uVar6;
      uVar11 = uVar15;
    }
    iVar5 = 0x36 - in_stack_00000070;
    iVar9 = (in_stack_0000006c - uStack00000024) + in_stack_00000070 + -1;
    if (iVar9 < -0x3fe) {
      iVar5 = iVar5 - (-0x3fe - iVar9);
    }
    uVar7 = uVar14 + iVar5;
    uVar12 = uVar11 + iVar5 + uStack00000024;
    uVar11 = uVar14;
    if ((int)uVar7 < (int)uVar14) {
      uVar11 = uVar7;
    }
    if ((int)uVar12 < (int)uVar11) {
      uVar11 = uVar12;
    }
    if (0 < (int)uVar11) {
      uVar7 = uVar7 - uVar11;
      uVar12 = uVar12 - uVar11;
      uVar14 = uVar14 - uVar11;
    }
    if (0 < (int)uVar6) {
      iVar4 = FUN_10025ea8();
      if ((iVar4 == 0) || (iVar5 = FUN_10025cf8(), iVar5 == 0)) break;
      FUN_10025a44();
      in_stack_00000068 = iVar5;
    }
    if ((((((0 < (int)uVar7) && (in_stack_00000068 = FUN_10025fb4(), in_stack_00000068 == 0)) ||
          ((0 < (int)uVar10 && (iVar5 = FUN_10025ea8(), iVar5 == 0)))) ||
         ((0 < (int)uVar12 && (iVar5 = FUN_10025fb4(), iVar5 == 0)))) ||
        ((0 < (int)uVar14 && (iVar4 = FUN_10025fb4(), iVar4 == 0)))) ||
       (iVar5 = FUN_100260e4(), iVar5 == 0)) break;
    iVar8 = *(int *)(iVar5 + 0xc);
    *(undefined4 *)(iVar5 + 0xc) = 0;
    iVar9 = FUN_100260a8(iVar5,iVar4);
    cVar16 = iVar9 == 0;
    if (iVar9 < 0) {
      FUN_10020a86();
    }
    if (cVar16 != '\0') {
      FUN_100209c2();
    }
    uVar18 = FUN_10026448(iVar5,iVar4);
    uVar3 = (undefined4)((ulonglong)uVar18 >> 0x20);
    uVar1 = (undefined4)uVar18;
    iVar4 = FUN_1001ea48(uVar1,uVar3,0,0x40000000);
    if (iVar4 == 0) {
      uVar18 = FUN_1001e9a6(uVar1,uVar3,0,0x3fe00000);
      if (iVar8 != 0) {
        uVar1 = FUN_100200e8();
        return uVar1;
      }
    }
    else {
      if (iVar8 != 0) {
        uVar1 = FUN_100200e8();
        return uVar1;
      }
      if (iStack00000010 != 0) {
        if (uVar17 != 1) {
LAB_100206ae:
          uVar1 = FUN_100200e8();
          return uVar1;
        }
        *unaff_r8 = 0x22;
        goto LAB_100205d8;
      }
      if ((uVar17 & 0xfffff00000000) != 0) goto LAB_100206ae;
      iVar4 = FUN_1001ea3c(uVar1,uVar3,0,0x3ff00000);
      if (iVar4 != 0) {
        FUN_100209ae();
      }
      uVar18 = FUN_1001e9a6(uVar1,uVar3,0,0x3fe00000);
    }
    iStack00000044 = (int)((ulonglong)uVar18 >> 0x20);
    uStack00000040 = (undefined4)uVar18;
    iVar4 = iStack00000044 + -0x80000000;
    uVar11 = uStack00000014 & 0x7ff00000;
    if (uVar11 == 0x7fe00000) {
      uVar19 = FUN_1002628c(iStack00000010,uStack00000014 + 0xfcb00000);
      uVar19 = FUN_1001e9a6((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),uStack00000040,iVar4);
      uVar19 = FUN_1001e958((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),iStack00000010,
                            uStack00000014 + 0xfcb00000);
      uVar14 = (uint)((ulonglong)uVar19 >> 0x20);
      if ((uVar14 & 0x7ff00000) < 0x7ca00000) {
        uVar17 = CONCAT44(uVar14 + 0x3500000,(int)uVar19);
        goto LAB_10020178;
      }
      if (uVar17 == 0x7fefffffffffffff) break;
      uVar17 = 0x7fefffffffffffff;
    }
    else {
      if ((uStack00000024 != 0) && (uVar11 < 0x6a00001)) {
        iVar5 = FUN_1001ea48(uStack00000040,iStack00000044,0xffc00000,0x41dfffff);
        if (iVar5 != 0) {
          iVar4 = FUN_1001eafc(uStack00000040,iStack00000044);
          if (iVar4 == 0) {
            iVar4 = 1;
          }
          uVar18 = FUN_1001ea7c(iVar4);
          uVar19 = uVar18;
          if (iVar8 != 0) {
            uVar19 = FUN_10020982();
          }
          uStack00000040 = (undefined4)uVar19;
          iVar4 = (int)((ulonglong)uVar19 >> 0x20) + -0x80000000;
        }
        iVar4 = (iVar4 + 0x6b00000) - uVar11;
      }
      uVar19 = FUN_1002628c(iStack00000010,uStack00000014);
      uVar19 = FUN_1001e9a6(uStack00000040,iVar4,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
      uVar17 = FUN_1001e958((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),iStack00000010,
                            uStack00000014);
LAB_10020178:
      uStack00000014 = (uint)(uVar17 >> 0x20);
      iStack00000010 = (int)uVar17;
      iStack00000044 = (int)((ulonglong)uVar18 >> 0x20);
      uStack00000040 = (undefined4)uVar18;
      if ((uStack00000024 == 0) && (uVar11 == (uStack00000014 & 0x7ff00000))) {
        FUN_1001eb2c(uStack00000040,iStack00000044);
        uVar18 = FUN_1001eb14();
        uVar18 = FUN_1001e946(uStack00000040,iStack00000044,(int)uVar18,
                              (int)((ulonglong)uVar18 >> 0x20));
        uVar3 = (undefined4)((ulonglong)uVar18 >> 0x20);
        uVar1 = (undefined4)uVar18;
        if ((iVar8 == 0 && iStack00000010 == 0) && (uVar17 & 0xfffff00000000) == 0) {
          iVar4 = FUN_1001ea3c(uVar1,uVar3,0x94a03595,0x3fcfffff);
        }
        else {
          iVar4 = FUN_1001ea3c(uVar1,uVar3,0x94a03595,0x3fdfffff);
          if (iVar4 != 0) goto LAB_100205d8;
          iVar4 = FUN_1001ea58(uVar1,uVar3,0x35afe535,0x3fe00000);
        }
        if (iVar4 != 0) goto LAB_100205d8;
      }
    }
    FUN_10025a44();
    FUN_10025a44();
    FUN_10025a44();
    FUN_10025a44();
  }
  *unaff_r8 = 0x22;
LAB_100205d8:
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  uVar1 = FUN_10020268();
  return uVar1;
}



/* FUN_100208c2 at 100208c2 */

void FUN_100208c2(void)

{
  undefined4 in_stack_00000010;
  undefined4 in_stack_00000014;
  int in_stack_00000028;
  
  FUN_1001e9a6(*(undefined4 *)(&DAT_1002b358 + in_stack_00000028 * 8),
               *(undefined4 *)(&DAT_1002b35c + in_stack_00000028 * 8),in_stack_00000010,
               in_stack_00000014);
  FUN_10020268();
  return;
}



/* FUN_100208dc at 100208dc */

void FUN_100208dc(void)

{
  undefined4 *unaff_r8;
  
  *unaff_r8 = 0x22;
  FUN_10020268();
  return;
}



/* FUN_10020982 at 10020982 */

void FUN_10020982(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int extraout_r1;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  uint uVar14;
  uint unaff_r5;
  undefined4 *unaff_r8;
  char cVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  ulonglong uVar18;
  int in_stack_00000010;
  uint in_stack_00000014;
  uint uStack00000024;
  uint in_stack_00000028;
  int in_stack_0000002c;
  undefined4 in_stack_00000040;
  int in_stack_00000044;
  int in_stack_00000048;
  undefined4 uStack00000058;
  int iStack0000005c;
  int in_stack_0000006c;
  int in_stack_00000070;
  
  uStack00000058 = in_stack_00000040;
  iStack0000005c = in_stack_00000044;
  FUN_10020148();
  uVar18 = FUN_1001e96a(in_stack_00000010,in_stack_00000014,
                        *(undefined4 *)(&DAT_1002b358 + extraout_r1 * 8),
                        *(undefined4 *)(&DAT_1002b35c + extraout_r1 * 8));
  if (unaff_r5 == 0) {
    FUN_1001ff8a();
  }
  if ((int)unaff_r5 < 0x20) {
    uStack00000024 = unaff_r5 & 0x10;
    if ((unaff_r5 & 0x10) != 0) {
      uStack00000024 = 0x6a;
    }
    puVar13 = &DAT_1002aef8;
    while( true ) {
      while( true ) {
        uVar1 = unaff_r5 & 1;
        unaff_r5 = (int)unaff_r5 >> 1;
        if (uVar1 != 0) break;
        puVar13 = puVar13 + 2;
      }
      uVar18 = FUN_1001e9a6((int)uVar18,(int)(uVar18 >> 0x20),*puVar13,puVar13[1]);
      uVar1 = (uint)(uVar18 >> 0x20);
      if (unaff_r5 == 0) break;
      puVar13 = puVar13 + 2;
    }
    if (uStack00000024 != 0) {
      uVar7 = (uVar1 & 0x7fffffff) >> 0x14;
      uVar11 = 0x6b - uVar7;
      if (0 < (int)uVar11) {
        if ((int)uVar11 < 0x20) {
          uVar18 = CONCAT44(uVar1,(uint)uVar18 & -1 << (uVar11 & 0xff));
        }
        else if ((int)uVar11 < 0x35) {
          uVar18 = (ulonglong)(uVar1 & -1 << (0x4b - uVar7 & 0xff)) << 0x20;
        }
        else {
          uVar18 = 0x370000000000000;
        }
      }
    }
    in_stack_00000014 = (uint)(uVar18 >> 0x20);
    in_stack_00000010 = (int)uVar18;
    iVar4 = FUN_1001ea2c(in_stack_00000010,in_stack_00000014,0,0);
    if (iVar4 == 0) {
      iVar4 = FUN_10025b2c();
      if (iVar4 == 0) {
        FUN_100208dc();
      }
      uVar7 = in_stack_00000028 & (int)~in_stack_00000028 >> 0x1f;
      uVar1 = in_stack_00000048 - in_stack_0000002c & (int)in_stack_00000028 >> 0x1f;
      while( true ) {
        in_stack_00000014 = (uint)(uVar18 >> 0x20);
        in_stack_00000010 = (int)uVar18;
        iVar3 = FUN_100259c0();
        if (iVar3 == 0) break;
        FUN_1001f4d4(iVar3 + 0xc,iVar4 + 0xc,(*(int *)(iVar4 + 0x10) + 2) * 4);
        iVar3 = FUN_10026384();
        if ((iVar3 == 0) || (iVar3 = FUN_10025ccc(), iVar3 == 0)) break;
        if (in_stack_0000006c < 0) {
          uVar11 = uVar7 - in_stack_0000006c;
          uVar14 = uVar1;
        }
        else {
          uVar14 = in_stack_0000006c + uVar1;
          uVar11 = uVar7;
        }
        iVar6 = 0x36 - in_stack_00000070;
        iVar10 = (in_stack_0000006c - uStack00000024) + in_stack_00000070 + -1;
        if (iVar10 < -0x3fe) {
          iVar6 = iVar6 - (-0x3fe - iVar10);
        }
        uVar8 = uVar14 + iVar6;
        uVar12 = uVar11 + iVar6 + uStack00000024;
        uVar11 = uVar14;
        if ((int)uVar8 < (int)uVar14) {
          uVar11 = uVar8;
        }
        if ((int)uVar12 < (int)uVar11) {
          uVar11 = uVar12;
        }
        if (0 < (int)uVar11) {
          uVar8 = uVar8 - uVar11;
          uVar12 = uVar12 - uVar11;
          uVar14 = uVar14 - uVar11;
        }
        if (0 < (int)uVar1) {
          iVar3 = FUN_10025ea8();
          if ((iVar3 == 0) || (iVar6 = FUN_10025cf8(), iVar6 == 0)) break;
          FUN_10025a44();
        }
        if ((((((0 < (int)uVar8) && (iVar6 = FUN_10025fb4(), iVar6 == 0)) ||
              ((0 < (int)in_stack_00000028 && (iVar6 = FUN_10025ea8(), iVar6 == 0)))) ||
             ((0 < (int)uVar12 && (iVar6 = FUN_10025fb4(), iVar6 == 0)))) ||
            ((0 < (int)uVar14 && (iVar3 = FUN_10025fb4(), iVar3 == 0)))) ||
           (iVar6 = FUN_100260e4(), iVar6 == 0)) break;
        iVar9 = *(int *)(iVar6 + 0xc);
        *(undefined4 *)(iVar6 + 0xc) = 0;
        iVar10 = FUN_100260a8(iVar6,iVar3);
        cVar15 = iVar10 == 0;
        if (iVar10 < 0) {
          FUN_10020a86();
        }
        if (cVar15 != '\0') {
          FUN_100209c2();
        }
        uVar16 = FUN_10026448(iVar6,iVar3);
        uVar5 = (undefined4)((ulonglong)uVar16 >> 0x20);
        uVar2 = (undefined4)uVar16;
        iVar3 = FUN_1001ea48(uVar2,uVar5,0,0x40000000);
        if (iVar3 == 0) {
          uVar16 = FUN_1001e9a6(uVar2,uVar5,0,0x3fe00000);
          if (iVar9 != 0) {
            FUN_100200e8();
            return;
          }
        }
        else {
          if (iVar9 != 0) {
            FUN_100200e8();
            return;
          }
          if (in_stack_00000010 != 0) {
            if (uVar18 != 1) {
LAB_100206ae:
              FUN_100200e8();
              return;
            }
            *unaff_r8 = 0x22;
            goto LAB_100205d8;
          }
          if ((uVar18 & 0xfffff00000000) != 0) goto LAB_100206ae;
          iVar3 = FUN_1001ea3c(uVar2,uVar5,0,0x3ff00000);
          if (iVar3 != 0) {
            FUN_100209ae();
          }
          uVar16 = FUN_1001e9a6(uVar2,uVar5,0,0x3fe00000);
        }
        in_stack_00000044 = (int)((ulonglong)uVar16 >> 0x20);
        in_stack_00000040 = (undefined4)uVar16;
        iVar3 = in_stack_00000044 + -0x80000000;
        uVar11 = in_stack_00000014 & 0x7ff00000;
        if (uVar11 == 0x7fe00000) {
          uVar17 = FUN_1002628c(in_stack_00000010,in_stack_00000014 + 0xfcb00000);
          uVar17 = FUN_1001e9a6((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),in_stack_00000040,iVar3
                               );
          uVar17 = FUN_1001e958((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),in_stack_00000010,
                                in_stack_00000014 + 0xfcb00000);
          uVar14 = (uint)((ulonglong)uVar17 >> 0x20);
          if ((uVar14 & 0x7ff00000) < 0x7ca00000) {
            uVar18 = CONCAT44(uVar14 + 0x3500000,(int)uVar17);
            goto LAB_10020178;
          }
          if (uVar18 == 0x7fefffffffffffff) break;
          uVar18 = 0x7fefffffffffffff;
        }
        else {
          if ((uStack00000024 != 0) && (uVar11 < 0x6a00001)) {
            iVar6 = FUN_1001ea48(in_stack_00000040,in_stack_00000044,0xffc00000,0x41dfffff);
            if (iVar6 != 0) {
              iVar3 = FUN_1001eafc(in_stack_00000040,in_stack_00000044);
              if (iVar3 == 0) {
                iVar3 = 1;
              }
              uVar16 = FUN_1001ea7c(iVar3);
              uVar17 = uVar16;
              if (iVar9 != 0) {
                uVar17 = FUN_10020982();
              }
              in_stack_00000040 = (undefined4)uVar17;
              iVar3 = (int)((ulonglong)uVar17 >> 0x20) + -0x80000000;
              uStack00000058 = in_stack_00000040;
              iStack0000005c = iVar3;
            }
            iVar3 = (iVar3 + 0x6b00000) - uVar11;
          }
          uVar17 = FUN_1002628c(in_stack_00000010,in_stack_00000014);
          uVar17 = FUN_1001e9a6(in_stack_00000040,iVar3,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20)
                               );
          uVar18 = FUN_1001e958((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),in_stack_00000010,
                                in_stack_00000014);
LAB_10020178:
          in_stack_00000014 = (uint)(uVar18 >> 0x20);
          in_stack_00000010 = (int)uVar18;
          in_stack_00000044 = (int)((ulonglong)uVar16 >> 0x20);
          in_stack_00000040 = (undefined4)uVar16;
          if ((uStack00000024 == 0) && (uVar11 == (in_stack_00000014 & 0x7ff00000))) {
            FUN_1001eb2c(in_stack_00000040,in_stack_00000044);
            uVar16 = FUN_1001eb14();
            uVar16 = FUN_1001e946(in_stack_00000040,in_stack_00000044,(int)uVar16,
                                  (int)((ulonglong)uVar16 >> 0x20));
            uVar5 = (undefined4)((ulonglong)uVar16 >> 0x20);
            uVar2 = (undefined4)uVar16;
            if ((iVar9 == 0 && in_stack_00000010 == 0) && (uVar18 & 0xfffff00000000) == 0) {
              iVar3 = FUN_1001ea3c(uVar2,uVar5,0x94a03595,0x3fcfffff);
            }
            else {
              iVar3 = FUN_1001ea3c(uVar2,uVar5,0x94a03595,0x3fdfffff);
              if (iVar3 != 0) goto LAB_100205d8;
              iVar3 = FUN_1001ea58(uVar2,uVar5,0x35afe535,0x3fe00000);
            }
            if (iVar3 != 0) goto LAB_100205d8;
          }
        }
        FUN_10025a44();
        FUN_10025a44();
        FUN_10025a44();
        FUN_10025a44();
      }
      *unaff_r8 = 0x22;
LAB_100205d8:
      FUN_10025a44();
      FUN_10025a44();
      FUN_10025a44();
      FUN_10025a44();
      FUN_10025a44();
      FUN_10020268();
      return;
    }
  }
  *unaff_r8 = 0x22;
  FUN_10020268();
  return;
}



/* FUN_100209ae at 100209ae */

void FUN_100209ae(void)

{
  int iVar1;
  uint extraout_r1;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 *unaff_r8;
  longlong lVar2;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int in_stack_00000024;
  uint in_stack_0000002c;
  undefined4 uStack00000030;
  undefined4 uStack00000034;
  int in_stack_00000038;
  uint uStack00000040;
  undefined4 uStack00000044;
  uint in_stack_00000054;
  
  lVar2 = CONCAT44(unaff_r7,unaff_r6);
  uStack00000030 = 0;
  uStack00000034 = 0xbfe00000;
  uStack00000040 = 0;
  uStack00000044 = 0x3fe00000;
  FUN_100200e8();
  if (in_stack_00000038 == 0) {
    if ((in_stack_00000014 & 0xfffff) != 0) {
      if (in_stack_00000054 == 0) {
        in_stack_0000002c = uStack00000040 & in_stack_00000010;
      }
      else {
        in_stack_0000002c = in_stack_0000002c & in_stack_00000054;
      }
joined_r0x10020be6:
      lVar2 = CONCAT44(unaff_r7,unaff_r6);
      if (in_stack_0000002c != 0) {
        FUN_1001fcc0(in_stack_00000010,in_stack_00000014,in_stack_00000024);
        lVar2 = FUN_1001e946();
        iVar1 = FUN_1001ea2c((int)lVar2,(int)((ulonglong)lVar2 >> 0x20),0,0);
        if (iVar1 != 0) {
LAB_1002076c:
          *unaff_r8 = 0x22;
          goto LAB_100205d8;
        }
      }
      goto LAB_10020a06;
    }
    if (in_stack_00000010 != 0) {
      if (in_stack_00000054 == 0) {
        in_stack_0000002c = uStack00000040 & in_stack_00000010;
      }
      else {
        in_stack_0000002c = in_stack_0000002c & in_stack_00000054;
      }
      goto joined_r0x10020be6;
    }
    if (in_stack_00000024 == 0) goto LAB_100205d8;
    in_stack_0000002c = in_stack_0000002c & 0x7ff00000;
    if (in_stack_0000002c < 0x6b00001) {
      if (0x3700000 < in_stack_0000002c) goto LAB_10020a0e;
      goto LAB_1002076c;
    }
    lVar2 = CONCAT44(in_stack_0000002c - 0x100000 | 0xfffff,0xffffffff);
  }
  else {
    if ((in_stack_00000014 & 0xfffff) == 0xfffff) {
      if (in_stack_00000024 == 0) {
        if (in_stack_00000010 == 0xffffffff) goto LAB_10020c04;
        if (in_stack_00000054 == 0) {
          in_stack_0000002c = uStack00000040 & in_stack_00000010;
        }
        else {
          in_stack_0000002c = in_stack_0000002c & in_stack_00000054;
        }
        if (in_stack_0000002c == 0) goto LAB_100205d8;
LAB_100209ec:
        FUN_1001fcc0(in_stack_00000010,in_stack_00000014,in_stack_00000024);
        lVar2 = FUN_1001e958();
      }
      else {
        if ((in_stack_0000002c & 0x7ff00000) < 0x6a00001) {
          if (in_stack_00000010 != -1 << (0x6b - ((in_stack_0000002c & 0x7ff00000) >> 0x14) & 0xff))
          {
            if (in_stack_00000054 == 0) goto LAB_10020c5a;
            in_stack_0000002c = in_stack_0000002c & in_stack_00000054;
            goto joined_r0x10020c42;
          }
        }
        else if (in_stack_00000010 != 0xffffffff) {
          if (in_stack_00000054 == 0) {
LAB_10020c5a:
            in_stack_0000002c = uStack00000040 & in_stack_00000010;
          }
          else {
            in_stack_0000002c = in_stack_0000002c & in_stack_00000054;
          }
joined_r0x10020c42:
          if (in_stack_0000002c == 0) goto LAB_10020a0e;
          goto LAB_100209ec;
        }
LAB_10020c04:
        if ((in_stack_0000002c == 0x7fefffff) && (in_stack_00000010 == 0xffffffff)) {
          *unaff_r8 = 0x22;
          goto LAB_100205d8;
        }
        lVar2 = (ulonglong)((in_stack_0000002c & 0x7ff00000) + 0x100000) << 0x20;
      }
    }
    else {
      if (in_stack_00000054 == 0) {
        in_stack_0000002c = uStack00000040 & in_stack_00000010;
      }
      else {
        in_stack_0000002c = in_stack_0000002c & in_stack_00000054;
      }
      lVar2 = CONCAT44(unaff_r7,unaff_r6);
      if (in_stack_0000002c != 0) goto LAB_100209ec;
    }
LAB_10020a06:
    if (in_stack_00000024 == 0) goto LAB_100205d8;
  }
LAB_10020a0e:
  FUN_1001e9a6((int)lVar2,(int)((ulonglong)lVar2 >> 0x20),0,0x39500000);
  if ((extraout_r1 & 0x7ff00000) == 0) {
    *unaff_r8 = 0x22;
  }
LAB_100205d8:
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10020268();
  return;
}



/* FUN_100209c2 at 100209c2 */

void FUN_100209c2(void)

{
  int iVar1;
  uint extraout_r1;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 *unaff_r8;
  longlong lVar2;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int in_stack_00000024;
  uint in_stack_0000002c;
  int in_stack_00000038;
  uint in_stack_00000040;
  uint in_stack_00000054;
  
  lVar2 = CONCAT44(unaff_r7,unaff_r6);
  if (in_stack_00000038 == 0) {
    if ((in_stack_00000014 & 0xfffff) != 0) {
      if (in_stack_00000054 == 0) {
        in_stack_0000002c = in_stack_00000040 & in_stack_00000010;
      }
      else {
        in_stack_0000002c = in_stack_0000002c & in_stack_00000054;
      }
joined_r0x10020be6:
      lVar2 = CONCAT44(unaff_r7,unaff_r6);
      if (in_stack_0000002c != 0) {
        FUN_1001fcc0(in_stack_00000010,in_stack_00000014,in_stack_00000024);
        lVar2 = FUN_1001e946();
        iVar1 = FUN_1001ea2c((int)lVar2,(int)((ulonglong)lVar2 >> 0x20),0,0);
        if (iVar1 != 0) {
LAB_1002076c:
          *unaff_r8 = 0x22;
          goto LAB_100205d8;
        }
      }
      goto LAB_10020a06;
    }
    if (in_stack_00000010 != 0) {
      if (in_stack_00000054 == 0) {
        in_stack_0000002c = in_stack_00000040 & in_stack_00000010;
      }
      else {
        in_stack_0000002c = in_stack_0000002c & in_stack_00000054;
      }
      goto joined_r0x10020be6;
    }
    if (in_stack_00000024 == 0) goto LAB_100205d8;
    in_stack_0000002c = in_stack_0000002c & 0x7ff00000;
    if (in_stack_0000002c < 0x6b00001) {
      if (0x3700000 < in_stack_0000002c) goto LAB_10020a0e;
      goto LAB_1002076c;
    }
    lVar2 = CONCAT44(in_stack_0000002c - 0x100000 | 0xfffff,0xffffffff);
  }
  else {
    if ((in_stack_00000014 & 0xfffff) == 0xfffff) {
      if (in_stack_00000024 == 0) {
        if (in_stack_00000010 == 0xffffffff) goto LAB_10020c04;
        if (in_stack_00000054 == 0) {
          in_stack_00000040 = in_stack_00000040 & in_stack_00000010;
        }
        else {
          in_stack_00000040 = in_stack_0000002c & in_stack_00000054;
        }
        if (in_stack_00000040 == 0) goto LAB_100205d8;
LAB_100209ec:
        FUN_1001fcc0(in_stack_00000010,in_stack_00000014,in_stack_00000024);
        lVar2 = FUN_1001e958();
      }
      else {
        if ((in_stack_0000002c & 0x7ff00000) < 0x6a00001) {
          if (in_stack_00000010 != -1 << (0x6b - ((in_stack_0000002c & 0x7ff00000) >> 0x14) & 0xff))
          {
            if (in_stack_00000054 == 0) goto LAB_10020c5a;
            in_stack_0000002c = in_stack_0000002c & in_stack_00000054;
            goto joined_r0x10020c42;
          }
        }
        else if (in_stack_00000010 != 0xffffffff) {
          if (in_stack_00000054 == 0) {
LAB_10020c5a:
            in_stack_0000002c = in_stack_00000040 & in_stack_00000010;
          }
          else {
            in_stack_0000002c = in_stack_0000002c & in_stack_00000054;
          }
joined_r0x10020c42:
          if (in_stack_0000002c == 0) goto LAB_10020a0e;
          goto LAB_100209ec;
        }
LAB_10020c04:
        if ((in_stack_0000002c == 0x7fefffff) && (in_stack_00000010 == 0xffffffff)) {
          *unaff_r8 = 0x22;
          goto LAB_100205d8;
        }
        lVar2 = (ulonglong)((in_stack_0000002c & 0x7ff00000) + 0x100000) << 0x20;
      }
    }
    else {
      if (in_stack_00000054 == 0) {
        in_stack_00000040 = in_stack_00000040 & in_stack_00000010;
      }
      else {
        in_stack_00000040 = in_stack_0000002c & in_stack_00000054;
      }
      lVar2 = CONCAT44(unaff_r7,unaff_r6);
      if (in_stack_00000040 != 0) goto LAB_100209ec;
    }
LAB_10020a06:
    if (in_stack_00000024 == 0) goto LAB_100205d8;
  }
LAB_10020a0e:
  FUN_1001e9a6((int)lVar2,(int)((ulonglong)lVar2 >> 0x20),0,0x39500000);
  if ((extraout_r1 & 0x7ff00000) == 0) {
    *unaff_r8 = 0x22;
  }
LAB_100205d8:
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10020268();
  return;
}



/* FUN_10020a30 at 10020a30 */

void FUN_10020a30(void)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint extraout_r1;
  uint uVar5;
  int extraout_r3;
  undefined4 *unaff_r8;
  uint extraout_r12;
  undefined8 uVar6;
  ulonglong uVar7;
  int in_stack_00000024;
  uint in_stack_0000002c;
  uint in_stack_00000040;
  undefined1 uStack00000064;
  undefined4 in_stack_00000068;
  undefined4 uStack00000070;
  uint in_stack_00000074;
  
  iVar4 = FUN_10025220(&uStack00000064,&DAT_1002aee4,&uStack00000070);
  if (iVar4 != 5) {
    FUN_1001ff3e();
  }
  uVar3 = in_stack_00000074;
  uVar2 = uStack00000070;
  uVar5 = in_stack_00000074 | 0x7ff00000;
  uVar7 = CONCAT44(in_stack_00000074,uStack00000070) | 0x7ff0000000000000;
  uVar1 = CONCAT44(in_stack_00000074,uStack00000070);
  FUN_10020268();
  if (extraout_r3 == 0) {
    if (uVar2 != 0) {
      if (extraout_r12 == 0) {
        in_stack_0000002c = in_stack_00000040 & uVar2;
        uVar7 = uVar1 | 0x7ff0000000000000;
      }
      else {
        in_stack_0000002c = in_stack_0000002c & extraout_r12;
      }
      goto joined_r0x10020be6;
    }
    if (in_stack_00000024 == 0) goto LAB_100205d8;
    in_stack_0000002c = in_stack_0000002c & 0x7ff00000;
    if (in_stack_0000002c < 0x6b00001) {
      if (0x3700000 < in_stack_0000002c) goto LAB_10020a0e;
      goto LAB_1002076c;
    }
    uVar7 = CONCAT44(in_stack_0000002c - 0x100000 | 0xfffff,0xffffffff);
  }
  else {
    if (extraout_r12 == 0) {
      in_stack_0000002c = in_stack_00000040 & uVar2;
    }
    else {
      in_stack_0000002c = in_stack_0000002c & extraout_r12;
    }
    uVar7 = CONCAT44(uVar3,uVar2) | 0x7ff0000000000000;
joined_r0x10020be6:
    if (in_stack_0000002c != 0) {
      uVar6 = FUN_1001fcc0(uVar2,uVar5,in_stack_00000024);
      uVar7 = FUN_1001e946(uVar2,uVar5,(int)uVar6,(int)((ulonglong)uVar6 >> 0x20));
      iVar4 = FUN_1001ea2c((int)uVar7,(int)(uVar7 >> 0x20),0,0);
      if (iVar4 != 0) {
LAB_1002076c:
        *unaff_r8 = 0x22;
        goto LAB_100205d8;
      }
    }
    if (in_stack_00000024 == 0) goto LAB_100205d8;
  }
LAB_10020a0e:
  FUN_1001e9a6((int)uVar7,(int)(uVar7 >> 0x20),0,0x39500000);
  if ((extraout_r1 & 0x7ff00000) == 0) {
    *unaff_r8 = 0x22;
  }
LAB_100205d8:
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10020268();
  return;
}



/* FUN_10020a86 at 10020a86 */

void FUN_10020a86(void)

{
  int iVar1;
  uint extraout_r1;
  undefined4 unaff_r6;
  uint unaff_r7;
  undefined4 *unaff_r8;
  int unaff_r11;
  int in_stack_00000010;
  uint in_stack_00000014;
  int in_stack_00000024;
  int in_stack_00000038;
  
  if ((((in_stack_00000038 == 0 && in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0))
      && (0x6b00000 < (in_stack_00000014 & 0x7ff00000))) &&
     ((*(int *)(unaff_r11 + 0x14) != 0 || (1 < *(int *)(unaff_r11 + 0x10))))) {
    FUN_10025fb4();
    iVar1 = FUN_100260a8();
    if (iVar1 < 1) goto LAB_10020a06;
    if (in_stack_00000024 == 0) goto LAB_100205d8;
    unaff_r7 = (in_stack_00000014 & 0x7ff00000) - 0x100000 | 0xfffff;
    unaff_r6 = 0xffffffff;
  }
  else {
LAB_10020a06:
    if (in_stack_00000024 == 0) goto LAB_100205d8;
  }
  FUN_1001e9a6(unaff_r6,unaff_r7,0,0x39500000);
  if ((extraout_r1 & 0x7ff00000) == 0) {
    *unaff_r8 = 0x22;
  }
LAB_100205d8:
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10025a44();
  FUN_10020268();
  return;
}



/* FUN_10020ca6 at 10020ca6 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_10020ca6(undefined4 param_1,int param_2,int param_3)

{
  bool bVar1;
  ulonglong uVar2;
  uint extraout_r1;
  int extraout_r2;
  byte *pbVar3;
  int iVar4;
  uint unaff_r4;
  undefined4 *unaff_r5;
  int iVar5;
  int unaff_r6;
  undefined4 *unaff_r8;
  uint uVar6;
  uint unaff_r9;
  int unaff_r10;
  int extraout_r12;
  longlong lVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  undefined4 in_stack_00000010;
  int in_stack_00000014;
  
  do {
    if (8 < unaff_r6) {
      if (unaff_r6 + 1 < 0x11) {
        FUN_1002037c(0,param_2,param_3,unaff_r10 * 10);
        return;
      }
      FUN_1002037c(0);
      return;
    }
    uVar6 = (int)unaff_r5 + unaff_r9 * 10;
    pbVar3 = (byte *)(param_2 + 1);
    lVar7 = ZEXT48(pbVar3) << 0x20;
    unaff_r5 = (undefined4 *)(*pbVar3 - 0x30);
    if (unaff_r5 < (undefined4 *)0xa) {
      iVar5 = 1;
      if (unaff_r5 == (undefined4 *)0x0) {
        lVar7 = FUN_10020caa();
        iVar5 = extraout_r2;
      }
      if (iVar5 == 1) {
        lVar7 = FUN_10020ca6();
      }
      iVar4 = unaff_r6 + 2;
      iVar5 = iVar4;
      unaff_r9 = uVar6;
      do {
        if (iVar5 + -1 < 9) {
          unaff_r9 = unaff_r9 * 10;
        }
        else if (iVar5 < 0x11) {
          unaff_r10 = unaff_r10 * 10;
        }
        iVar5 = iVar5 + 1;
      } while ((iVar5 - (unaff_r6 + 1)) + -1 < (int)lVar7);
    }
    else {
      uVar8 = FUN_1001feee(0,pbVar3,1);
      if ((int)uVar8 != 0) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      unaff_r5 = &DAT_1002b330;
      bVar1 = false;
      uVar8 = uVar8 & 0xffffffff00000000;
      iVar5 = unaff_r10;
      do {
        if ((unaff_r4 & 1) != 0) {
          uVar8 = FUN_1001e9a6((int)uVar8,(int)(uVar8 >> 0x20),*unaff_r5,unaff_r5[1]);
          bVar1 = true;
        }
        iVar5 = iVar5 + 1;
        unaff_r4 = (int)unaff_r4 >> 1;
        unaff_r5 = unaff_r5 + 2;
      } while (unaff_r4 != 1);
      uVar2 = CONCAT44(in_stack_00000014,in_stack_00000010);
      if (bVar1) {
        uVar2 = uVar8;
      }
      in_stack_00000014 = (int)(uVar2 >> 0x20);
      in_stack_00000010 = (undefined4)uVar2;
      FUN_1001e9a6((&DAT_1002b330)[iVar5 * 2],(&DAT_1002b334)[iVar5 * 2],in_stack_00000010,
                   in_stack_00000014 + -0x3500000);
      if (0x7ca00000 < (extraout_r1 & 0x7ff00000)) {
        *unaff_r8 = 0x22;
        FUN_10020268();
        return;
      }
      if ((extraout_r1 & 0x7ff00000) < 0x7c900001) {
        FUN_1001ff8a();
      }
      unaff_r9 = 0x7fefffff;
      in_stack_00000010 = 0xffffffff;
      in_stack_00000014 = 0x7fefffff;
      uVar9 = FUN_1001ff8a();
      unaff_r10 = (int)((ulonglong)uVar9 >> 0x20);
      lVar7 = CONCAT44(iVar5,(int)uVar9);
      unaff_r4 = uVar6;
      iVar4 = extraout_r12;
    }
    param_2 = (int)((ulonglong)lVar7 >> 0x20);
    unaff_r6 = (int)lVar7 + -1 + iVar4;
    param_3 = unaff_r10;
  } while( true );
}



/* FUN_10020caa at 10020caa */

/* WARNING: Control flow encountered bad instruction data */

void FUN_10020caa(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_1002037e(param_3);
  FUN_1002037c(1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* FUN_10020cb0 at 10020cb0 */

/* WARNING: Control flow encountered bad instruction data */

void FUN_10020cb0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uStack00000048;
  
  uStack00000048 = param_3;
  FUN_1002037c(1);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



/* FUN_10020ccc at 10020ccc */

void FUN_10020ccc(void)

{
  FUN_1001fcf0();
  return;
}



/* FUN_10020e90 at 10020e90 */

undefined4 FUN_10020e90(undefined4 *param_1,int *param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar1 = *param_2;
  if ((uint)param_2[2] <= param_4) {
    if (((int)(short)param_2[3] & 0x480U) == 0) {
      param_4 = param_2[2];
    }
    else {
      iVar4 = iVar1 - param_2[4];
      uVar5 = (param_2[5] * 3) / 2;
      uVar2 = param_4 + 1 + iVar4;
      if (uVar5 < uVar2) {
        uVar5 = uVar2;
      }
      if ((int)(short)param_2[3] << 0x15 < 0) {
        iVar3 = FUN_10022670(param_1,uVar5);
        if (iVar3 == 0) goto LAB_10020f48;
        FUN_1001f4d4(iVar3,param_2[4],iVar4);
        *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xfb7f | 0x80;
      }
      else {
        iVar3 = FUN_1002487c(param_1);
        if (iVar3 == 0) {
          FUN_10023f9c(param_1,param_2[4]);
LAB_10020f48:
          *param_1 = 0xc;
          *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x40;
          return 0xffffffff;
        }
      }
      iVar1 = iVar3 + iVar4;
      param_2[5] = uVar5;
      param_2[4] = iVar3;
      *param_2 = iVar1;
      param_2[2] = uVar5 - iVar4;
    }
  }
  FUN_10025130(iVar1,param_3,param_4);
  param_2[2] = param_2[2] - param_4;
  *param_2 = *param_2 + param_4;
  return 0;
}



/* FUN_10020f60 at 10020f60 */

undefined4 FUN_10020f60(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  
  if (param_3[2] == 0) {
LAB_1002105e:
    uVar8 = 0;
LAB_10021060:
    param_3[1] = 0;
    return uVar8;
  }
  puVar5 = (undefined4 *)*param_3;
  uVar7 = 0;
  iVar4 = *param_2;
  uVar8 = 0;
  uVar6 = param_2[2];
  do {
    if (uVar7 != 0) {
      if (uVar7 < uVar6) {
        uVar1 = uVar7;
      }
      else {
        uVar1 = uVar6;
        if ((*(ushort *)(param_2 + 3) & 0x480) != 0) {
          iVar3 = iVar4 - param_2[4];
          uVar6 = (param_2[5] * 3) / 2;
          uVar1 = iVar3 + 1 + uVar7;
          if (uVar6 < uVar1) {
            uVar6 = uVar1;
          }
          if ((*(ushort *)(param_2 + 3) & 0x400) == 0) {
            iVar2 = FUN_1002487c(param_1);
            if (iVar2 == 0) {
              FUN_10023f9c(param_1,param_2[4]);
              goto LAB_10021044;
            }
          }
          else {
            iVar2 = FUN_10022670(param_1,uVar6);
            if (iVar2 == 0) {
LAB_10021044:
              *param_1 = 0xc;
              uVar8 = 0xffffffff;
              *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x40;
              param_3[2] = 0;
              goto LAB_10021060;
            }
            FUN_1001f4d4(iVar2,param_2[4],iVar3);
            *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xfb7f | 0x80;
          }
          iVar4 = iVar2 + iVar3;
          param_2[4] = iVar2;
          param_2[2] = uVar6 - iVar3;
          *param_2 = iVar4;
          param_2[5] = uVar6;
          uVar1 = uVar7;
        }
      }
      FUN_10025130(iVar4,uVar8,uVar1);
      iVar3 = param_3[2];
      uVar6 = param_2[2] - uVar1;
      iVar4 = *param_2 + uVar1;
      param_2[2] = uVar6;
      *param_2 = iVar4;
      param_3[2] = iVar3 - uVar7;
      if (iVar3 - uVar7 == 0) goto LAB_1002105e;
    }
    uVar8 = *puVar5;
    uVar7 = puVar5[1];
    puVar5 = puVar5 + 2;
  } while( true );
}



/* FUN_10021078 at 10021078 */

/* WARNING: Removing unreachable block (ram,0x10021282) */

int FUN_10021078(undefined4 *param_1,int *param_2,byte *param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  byte *pbVar6;
  int *local_8c;
  uint local_88;
  int local_84;
  undefined4 local_80;
  int local_7c;
  int local_74;
  byte local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined1 uStack_45;
  undefined4 local_30;
  
  if (((int)((uint)*(ushort *)(param_2 + 3) << 0x18) < 0) && (param_2[4] == 0)) {
    iVar3 = FUN_10022670(param_1,0x40);
    *param_2 = iVar3;
    param_2[4] = iVar3;
    if (iVar3 == 0) {
      *param_1 = 0xc;
      return -1;
    }
    param_2[5] = 0x40;
  }
  local_74 = 0;
  local_6f = 0x20;
  local_6e = 0x30;
  bVar5 = *param_3;
  local_8c = param_4;
  while (bVar5 != 0) {
    pbVar6 = param_3;
    do {
      if (bVar5 == 0x25) {
        iVar3 = (int)pbVar6 - (int)param_3;
        if (pbVar6 != param_3) goto LAB_1002121c;
        goto LAB_100210d2;
      }
      bVar5 = pbVar6[1];
      pbVar6 = pbVar6 + 1;
    } while (bVar5 != 0);
    iVar3 = (int)pbVar6 - (int)param_3;
    if (pbVar6 == param_3) break;
LAB_1002121c:
    iVar1 = FUN_10020e90(param_1,param_2,param_3,iVar3);
    if (iVar1 == -1) break;
    local_74 = local_74 + iVar3;
LAB_100210d2:
    if (*pbVar6 == 0) break;
    local_88 = 0;
    local_84 = -1;
    local_80 = 0;
    local_7c = 0;
    uStack_45 = 0;
    local_30 = 0;
    pbVar6 = pbVar6 + 1;
    while( true ) {
      iVar3 = FUN_10026614("#-0+ ",*pbVar6,5);
      if (iVar3 == 0) break;
      local_88 = 1 << (iVar3 + 0xeffd5328U & 0xff) | local_88;
      pbVar6 = pbVar6 + 1;
    }
    if ((int)(local_88 << 0x1b) < 0) {
      uStack_45 = 0x20;
    }
    if ((int)(local_88 << 0x1c) < 0) {
      uStack_45 = 0x2b;
    }
    uVar4 = (uint)*pbVar6;
    if (uVar4 == 0x2a) {
      local_7c = *local_8c;
      if (local_7c < 0) {
        local_7c = -local_7c;
        local_88 = local_88 | 2;
      }
      uVar4 = (uint)pbVar6[1];
      pbVar6 = pbVar6 + 1;
      local_8c = local_8c + 1;
    }
    else {
      uVar2 = uVar4 - 0x30;
      if (uVar2 < 10) {
        do {
          local_7c = local_7c * 10 + uVar2;
          uVar4 = (uint)pbVar6[1];
          pbVar6 = pbVar6 + 1;
          uVar2 = uVar4 - 0x30;
        } while (uVar2 < 10);
      }
    }
    param_3 = pbVar6;
    if (uVar4 == 0x2e) {
      if (pbVar6[1] == 0x2a) {
        param_3 = pbVar6 + 2;
        local_84 = *local_8c;
        if (local_84 < 0) {
          local_84 = -1;
        }
        uVar4 = (uint)pbVar6[2];
        local_8c = local_8c + 1;
      }
      else {
        local_84 = 0;
        uVar4 = (uint)pbVar6[1];
        param_3 = pbVar6 + 1;
        uVar2 = uVar4 - 0x30;
        if (uVar2 < 10) {
          local_84 = 0;
          do {
            local_84 = local_84 * 10 + uVar2;
            uVar4 = (uint)param_3[1];
            param_3 = param_3 + 1;
            uVar2 = uVar4 - 0x30;
          } while (uVar2 < 10);
        }
      }
    }
    iVar3 = FUN_10026614(&DAT_1002ace0,uVar4,3);
    if (iVar3 != 0) {
      local_88 = local_88 | 0x40 << (iVar3 + 0xeffd5320U & 0xff);
      param_3 = param_3 + 1;
    }
    local_70 = *param_3;
    if (((local_88 & 0x80) != 0) && (local_70 == 0x6c)) {
      local_88 = local_88 & 0xffffff7f | 0x800;
      local_70 = param_3[1];
      param_3 = param_3 + 1;
    }
    if (((local_88 & 0x40) != 0) && (local_70 == 0x68)) {
      local_88 = local_88 & 0xffffffbf | 0x200;
      local_70 = param_3[1];
      param_3 = param_3 + 1;
    }
    if ((local_70 == 0x7a) || (local_70 == 0x74)) {
      local_70 = param_3[1];
      param_3 = param_3 + 1;
    }
    if (local_70 == 0x6a) {
      local_88 = local_88 | 0x800;
      local_70 = param_3[1];
      param_3 = param_3 + 1;
    }
    param_3 = param_3 + 1;
    iVar3 = FUN_10026614("efgEFG",local_70,6);
    if (iVar3 == 0) {
      iVar3 = FUN_10024d10(param_1,&local_88,param_2,0x10020e91,&local_8c);
    }
    else {
      iVar3 = FUN_10022000(param_1,&local_88,param_2,0x10020e91,&local_8c);
    }
    if (iVar3 == -1) break;
    local_74 = local_74 + iVar3;
    bVar5 = *param_3;
  }
  if ((int)((uint)*(ushort *)(param_2 + 3) << 0x19) < 0) {
    return -1;
  }
  return local_74;
}



/* FUN_10021318 at 10021318 */

void FUN_10021318(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  
  iVar4 = *(int *)(param_1 + 0x10);
  iVar8 = (int)param_2 >> 5;
  if (iVar8 < iVar4) {
    puVar7 = (uint *)(param_1 + 0x14);
    puVar6 = puVar7 + iVar4;
    puVar5 = puVar7 + iVar8;
    uVar1 = param_2 & 0x1f;
    if ((param_2 & 0x1f) == 0) {
      puVar3 = puVar7;
      if (puVar6 <= puVar5) goto LAB_1002132e;
      do {
        uVar1 = *puVar5;
        puVar5 = puVar5 + 1;
        *puVar3 = uVar1;
        puVar3 = puVar3 + 1;
      } while (puVar5 < puVar6);
      puVar5 = puVar7 + (iVar4 - iVar8);
    }
    else {
      puVar3 = puVar5 + 1;
      uVar2 = *puVar5 >> uVar1;
      if (puVar3 < puVar6) {
        puVar5 = puVar7;
        do {
          *puVar5 = *puVar3 << (0x20 - uVar1 & 0xff) | uVar2;
          puVar5 = puVar5 + 1;
          uVar2 = *puVar3;
          puVar3 = puVar3 + 1;
          uVar2 = uVar2 >> uVar1;
        } while (puVar3 < puVar6);
        puVar6 = puVar7 + (iVar4 - iVar8);
        puVar6[-1] = uVar2;
        puVar5 = puVar6 + -1;
        if (uVar2 != 0) {
          puVar5 = puVar6;
        }
      }
      else {
        *(uint *)(param_1 + 0x14) = uVar2;
        if (uVar2 == 0) goto LAB_1002132e;
        puVar5 = (uint *)(param_1 + 0x18);
      }
    }
    *(int *)(param_1 + 0x10) = (int)puVar5 - (int)puVar7 >> 2;
    if (puVar5 != puVar7) {
      return;
    }
  }
  else {
LAB_1002132e:
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}



/* FUN_100213c8 at 100213c8 */

byte FUN_100213c8(undefined4 param_1,int *param_2,uint *param_3,uint *param_4,int *param_5,
                 int param_6)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  bool bVar6;
  uint uVar7;
  char cVar8;
  byte bVar9;
  byte *pbVar10;
  uint *puVar11;
  byte *pbVar12;
  byte *pbVar13;
  byte *pbVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  byte *pbVar19;
  bool bVar20;
  uint local_3c;
  uint *local_30;
  
  iVar3 = *param_2;
  uVar7 = (uint)*(byte *)(iVar3 + 2);
  if (uVar7 == 0x30) {
    pbVar19 = (byte *)(iVar3 + 3);
    do {
      pbVar12 = pbVar19;
      uVar7 = (uint)*pbVar12;
      pbVar19 = pbVar12 + 1;
    } while (uVar7 == 0x30);
    pbVar19 = pbVar12 + (-2 - iVar3);
  }
  else {
    pbVar12 = (byte *)(iVar3 + 2);
    pbVar19 = (byte *)0x0;
  }
  if ((&DAT_1002af20)[uVar7] == '\0') {
    iVar3 = FUN_100225e0(pbVar12,&DAT_1002acc4,1);
    if (iVar3 == 0) {
      uVar7 = (uint)pbVar12[1];
      pbVar10 = pbVar12 + 1;
      pbVar13 = pbVar10;
      if ((&DAT_1002af20)[uVar7] != '\0') {
        pbVar12 = pbVar10;
        if (uVar7 == 0x30) {
          do {
            pbVar19 = pbVar12 + 1;
            pbVar12 = pbVar12 + 1;
          } while (*pbVar19 == 0x30);
          cVar8 = (&DAT_1002af20)[*pbVar19];
          bVar20 = cVar8 == '\0';
          pbVar19 = (byte *)0x1;
          goto LAB_10021414;
        }
        pbVar19 = (byte *)0x1;
        bVar20 = false;
        goto LAB_1002141a;
      }
    }
    else {
      uVar7 = (uint)*pbVar12;
      pbVar13 = pbVar12;
    }
    if ((uVar7 & 0xffffffdf) != 0x50) {
      *param_2 = (int)pbVar13;
      goto LAB_10021556;
    }
    local_3c = 0;
    bVar20 = true;
LAB_100214f4:
    uVar7 = (uint)pbVar13[1];
    if (uVar7 == 0x2b) {
      bVar6 = false;
LAB_10021504:
      uVar7 = (uint)pbVar13[2];
      pbVar10 = pbVar13 + 2;
    }
    else {
      if (uVar7 == 0x2d) {
        bVar6 = true;
        goto LAB_10021504;
      }
      bVar6 = false;
      pbVar10 = pbVar13 + 1;
    }
    if (0x18 < (byte)(&DAT_1002af20)[uVar7] - 1) goto LAB_10021450;
    pbVar14 = pbVar10 + 1;
    iVar3 = (byte)(&DAT_1002af20)[uVar7] - 0x10;
    uVar7 = (uint)(byte)(&DAT_1002af20)[pbVar10[1]];
    if (uVar7 != 0) {
      do {
        if (0x19 < uVar7) break;
        pbVar14 = pbVar14 + 1;
        iVar3 = iVar3 * 10 + uVar7 + -0x10;
        uVar7 = (uint)(byte)(&DAT_1002af20)[*pbVar14];
      } while (uVar7 != 0);
    }
    if (bVar6) {
      iVar3 = -iVar3;
    }
    local_3c = local_3c + iVar3;
    *param_2 = (int)pbVar14;
  }
  else {
    pbVar10 = (byte *)0x0;
    bVar20 = false;
    cVar8 = (&DAT_1002af20)[*pbVar12];
LAB_10021414:
    if (cVar8 == '\0') {
      pbVar13 = pbVar12;
    }
    else {
LAB_1002141a:
      pbVar13 = pbVar12;
      do {
        pbVar14 = pbVar13 + 1;
        pbVar13 = pbVar13 + 1;
      } while ((&DAT_1002af20)[*pbVar14] != '\0');
    }
    iVar3 = FUN_100225e0(pbVar13,&DAT_1002acc4,1);
    if (iVar3 == 0) {
      if (pbVar10 == (byte *)0x0) {
        uVar7 = (uint)pbVar13[1];
        pbVar10 = pbVar13 + 1;
        pbVar13 = pbVar10;
        if ((&DAT_1002af20)[uVar7] != '\0') {
          do {
            uVar7 = (uint)pbVar13[1];
            pbVar13 = pbVar13 + 1;
          } while ((&DAT_1002af20)[uVar7] != '\0');
          goto LAB_10021440;
        }
        local_3c = 0;
        goto LAB_10021446;
      }
      local_3c = ((int)pbVar10 - (int)pbVar13) * 4;
      if ((*pbVar13 & 0xdf) == 0x50) goto LAB_100214f4;
    }
    else {
      uVar7 = (uint)*pbVar13;
      local_3c = 0;
      if (pbVar10 != (byte *)0x0) {
LAB_10021440:
        local_3c = ((int)pbVar10 - (int)pbVar13) * 4;
      }
LAB_10021446:
      if ((uVar7 & 0xffffffdf) == 0x50) goto LAB_100214f4;
    }
LAB_10021450:
    *param_2 = (int)pbVar13;
  }
  if (bVar20) {
LAB_10021556:
    return -(pbVar19 == (byte *)0x0) & 6;
  }
  iVar3 = 0;
  for (pbVar19 = pbVar13 + (-1 - (int)pbVar12); 7 < (int)pbVar19;
      pbVar19 = (byte *)((int)pbVar19 >> 1)) {
    iVar3 = iVar3 + 1;
  }
  iVar3 = FUN_100259c0(param_1,iVar3);
  if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/gdtoa-gethex.c",0xe4,0,"Balloc succeeded")
    ;
  }
  local_30 = (uint *)(iVar3 + 0x14);
  puVar2 = local_30;
  if (pbVar12 < pbVar13) {
    uVar18 = 0;
    uVar7 = 0;
    do {
      pbVar13 = pbVar13 + -1;
      if ((*pbVar13 == 0x2e) && (pbVar12 <= pbVar13)) {
        iVar1 = FUN_100225e0(pbVar13,&DAT_1002acc4,1);
        uVar17 = uVar7;
        if (iVar1 != 0) {
          if (uVar7 == 0x20) goto LAB_100214d2;
          goto LAB_1002149e;
        }
      }
      else {
        if (uVar7 == 0x20) {
LAB_100214d2:
          *puVar2 = uVar18;
          puVar2 = puVar2 + 1;
          uVar7 = 0;
          uVar17 = 4;
          uVar18 = 0;
        }
        else {
LAB_1002149e:
          uVar17 = uVar7 + 4;
        }
        uVar18 = uVar18 | ((byte)(&DAT_1002af20)[*pbVar13] & 0xf) << (uVar7 & 0xff);
      }
      uVar7 = uVar17;
    } while (pbVar13 != pbVar12);
  }
  else {
    uVar18 = 0;
  }
  *puVar2 = uVar18;
  iVar15 = (int)puVar2 + (4 - (int)local_30) >> 2;
  *(int *)(iVar3 + 0x10) = iVar15;
  iVar1 = FUN_10025bdc(uVar18);
  uVar7 = *param_3;
  iVar1 = iVar15 * 0x20 - iVar1;
  if ((int)uVar7 < iVar1) {
    iVar1 = iVar1 - uVar7;
    iVar15 = FUN_10026524(iVar3,iVar1);
    uVar16 = 0;
    if (iVar15 != 0) {
      uVar18 = iVar1 - 1;
      uVar16 = 1;
      if ((local_30[(int)uVar18 >> 5] & 1 << (uVar18 & 0x1f)) != 0) {
        if (((int)uVar18 < 2) || (iVar15 = FUN_10026524(iVar3,iVar1 + -2), iVar15 == 0)) {
          uVar16 = 2;
        }
        else {
          uVar16 = 3;
        }
      }
    }
    FUN_10021318(iVar3,iVar1);
    local_3c = local_3c + iVar1;
    if ((int)param_3[2] < (int)local_3c) goto LAB_10021728;
    uVar18 = param_3[1];
    if ((int)uVar18 <= (int)local_3c) {
      bVar9 = 1;
      goto LAB_1002178e;
    }
    local_3c = uVar18 - local_3c;
    if ((int)local_3c < (int)uVar7) {
      uVar17 = local_3c - 1;
      if (uVar16 == 0) goto LAB_100215b8;
      uVar16 = 1;
      goto LAB_100215c0;
    }
  }
  else {
    if (iVar1 < (int)uVar7) {
      iVar3 = FUN_10025fb4(param_1,iVar3,uVar7 - iVar1);
      local_3c = local_3c - (uVar7 - iVar1);
      if ((int)param_3[2] < (int)local_3c) goto LAB_10021728;
      uVar18 = param_3[1];
      if ((int)uVar18 <= (int)local_3c) goto LAB_100216e0;
      local_30 = (uint *)(iVar3 + 0x14);
    }
    else {
      if ((int)param_3[2] < (int)local_3c) goto LAB_10021728;
      uVar18 = param_3[1];
      if ((int)uVar18 <= (int)local_3c) {
LAB_100216e0:
        bVar9 = 1;
        goto LAB_100216e2;
      }
    }
    local_3c = uVar18 - local_3c;
    uVar17 = local_3c - 1;
    if ((int)local_3c < (int)uVar7) {
LAB_100215b8:
      uVar16 = 0;
      if (uVar17 != 0) {
        uVar16 = FUN_10026524(iVar3,uVar17);
      }
LAB_100215c0:
      uVar7 = uVar7 - local_3c;
      if ((local_30[(int)uVar17 >> 5] & 1 << (uVar17 & 0x1f)) == 0) {
        FUN_10021318(iVar3,local_3c);
        local_3c = param_3[1];
        bVar9 = 2;
LAB_1002178e:
        if (uVar16 == 0) goto LAB_100216e2;
        uVar18 = param_3[3];
        if (uVar18 != 2) {
          if (uVar18 != 3) {
            if ((uVar18 == 1) && ((int)(uVar16 << 0x1e) < 0)) goto LAB_10021852;
            goto LAB_100217a2;
          }
          goto LAB_100217b0;
        }
LAB_100217a8:
        param_6 = 1 - param_6;
LAB_100217b0:
        iVar1 = iVar3;
        if (param_6 != 0) {
LAB_100217b6:
          iVar15 = *(int *)(iVar1 + 0x10);
          puVar2 = local_30;
          do {
            iVar3 = iVar1;
            if (*puVar2 != 0xffffffff) {
              *puVar2 = *puVar2 + 1;
              if (bVar9 != 2) goto LAB_100217de;
              goto LAB_100218b2;
            }
            *puVar2 = 0;
            puVar2 = puVar2 + 1;
          } while (puVar2 < local_30 + iVar15);
          if (iVar15 < *(int *)(iVar1 + 8)) {
            iVar4 = iVar15 + 1;
            *(int *)(iVar1 + 0x10) = iVar4;
            *(undefined4 *)(iVar15 * 4 + iVar1 + 0x14) = 1;
            if (bVar9 != 2) goto LAB_10021806;
          }
          else {
            iVar3 = FUN_100259c0(param_1,*(int *)(iVar1 + 4) + 1);
            if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
              FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/gdtoa-gethex.c",0x84,0,
                           "Balloc succeeded");
            }
            FUN_1001f4d4(iVar3 + 0xc,iVar1 + 0xc,(*(int *)(iVar1 + 0x10) + 2) * 4);
            FUN_10025a44(param_1,iVar1);
            iVar1 = *(int *)(iVar3 + 0x10);
            iVar4 = iVar1 + 1;
            *(int *)(iVar3 + 0x10) = iVar4;
            *(undefined4 *)(iVar3 + iVar1 * 4 + 0x14) = 1;
            local_30 = (uint *)(iVar3 + 0x14);
            if (bVar9 != 2) {
              if (iVar4 <= iVar15) {
LAB_100217de:
                bVar9 = 0x21;
                if (((uVar7 & 0x1f) == 0) ||
                   (iVar1 = FUN_10025bdc(local_30[iVar15 + -1]),
                   (int)(0x20 - (uVar7 & 0x1f)) <= iVar1)) goto LAB_100216e2;
                iVar4 = *(int *)(iVar3 + 0x10);
              }
LAB_10021806:
              if (iVar4 < 1) {
                *(undefined4 *)(iVar3 + 0x10) = 0;
LAB_10021812:
                *(undefined4 *)(iVar3 + 0x14) = 0;
              }
              else {
                puVar5 = local_30 + iVar4;
                puVar2 = (uint *)(iVar3 + 0x18);
                uVar7 = *(uint *)(iVar3 + 0x14) >> 1;
                if (puVar2 < puVar5) {
                  puVar11 = local_30;
                  do {
                    *puVar11 = *puVar2 << 0x1f | uVar7;
                    puVar11 = puVar11 + 1;
                    uVar7 = *puVar2;
                    puVar2 = puVar2 + 1;
                    uVar7 = uVar7 >> 1;
                  } while (puVar2 < puVar5);
                  puVar2 = (uint *)((int)local_30 +
                                   ((int)puVar5 + (-0x19 - iVar3) & 0xfffffffcU) + 4);
                  *puVar2 = uVar7;
                  if (uVar7 != 0) {
                    puVar2 = puVar2 + 1;
                  }
                }
                else {
                  *local_30 = uVar7;
                  if (uVar7 == 0) {
                    *(undefined4 *)(iVar3 + 0x10) = 0;
                    goto LAB_10021812;
                  }
                  puVar2 = local_30 + 1;
                }
                *(int *)(iVar3 + 0x10) = (int)puVar2 - (int)local_30 >> 2;
                if (puVar2 == local_30) goto LAB_10021812;
              }
              local_3c = local_3c + 1;
              if ((int)param_3[2] < (int)local_3c) {
LAB_10021728:
                FUN_10025a44(param_1,iVar3);
                *param_5 = 0;
                return 0xa3;
              }
              bVar9 = 0x21;
              goto LAB_100216e2;
            }
          }
LAB_100218b2:
          bVar9 = 0x22;
          if (*param_3 - 1 == uVar7) {
            bVar9 = ((local_30[(int)uVar7 >> 5] & 1 << (uVar7 & 0x1f)) == 0) + 0x21;
          }
          goto LAB_100216e2;
        }
      }
      else {
        FUN_10021318(iVar3,local_3c);
        local_3c = param_3[1];
        uVar18 = param_3[3];
        if (uVar18 == 2) {
          bVar9 = 2;
          goto LAB_100217a8;
        }
        if (uVar18 == 3) {
          bVar9 = 2;
          goto LAB_100217b0;
        }
        if (uVar18 != 1) {
          bVar9 = 0x12;
          goto LAB_100216e2;
        }
        bVar9 = 2;
LAB_10021852:
        iVar1 = iVar3;
        if ((int)((uVar16 | *local_30) << 0x1f) < 0) goto LAB_100217b6;
      }
LAB_100217a2:
      bVar9 = bVar9 | 0x10;
LAB_100216e2:
      *param_5 = iVar3;
      *param_4 = local_3c;
      return bVar9;
    }
  }
  uVar17 = param_3[3];
  if (uVar17 == 2) {
    if (param_6 == 0) goto LAB_100216c2;
  }
  else if (uVar17 == 3) {
    if (param_6 != 0) goto LAB_100216c2;
  }
  else if ((uVar17 == 1) && (local_3c == uVar7)) {
    if (local_3c != 1) {
      iVar1 = FUN_10026524(iVar3,local_3c - 1);
      if (iVar1 == 0) goto LAB_10021716;
      uVar18 = param_3[1];
    }
LAB_100216c2:
    *param_4 = uVar18;
    *(undefined4 *)(iVar3 + 0x10) = 1;
    *local_30 = 1;
    *param_5 = iVar3;
    return 0x62;
  }
LAB_10021716:
  FUN_10025a44(param_1,iVar3);
  *param_5 = 0;
  return 0x50;
}



/* FUN_100219bc at 100219bc */

void FUN_100219bc(void)

{
  FUN_1001c744();
  return;
}



/* FUN_100219c4 at 100219c4 */

int FUN_100219c4(int param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined *local_18;
  undefined4 local_14;
  
  local_1c = FUN_10024360(param_2);
  local_2c = &local_20;
  local_18 = &DAT_1002ad38;
  local_28 = 2;
  local_24 = local_1c + 1;
  local_14 = 1;
  iVar3 = *(int *)(param_1 + 8);
  local_20 = param_2;
  if (*(int *)(param_1 + 0x20) == 0) {
    FUN_10021cfc(param_1);
  }
  uVar2 = (uint)*(short *)(iVar3 + 0xc);
  if ((-1 < *(int *)(iVar3 + 0x68) << 0x1f) && (-1 < (int)(uVar2 << 0x16))) {
    FUN_100274fc(iVar3 + 0x58);
    uVar2 = (uint)*(short *)(iVar3 + 0xc);
  }
  if ((uVar2 & 0x2000) == 0) {
    *(ushort *)(iVar3 + 0xc) = (ushort)uVar2 | 0x2000;
    *(uint *)(iVar3 + 0x68) = *(uint *)(iVar3 + 0x68) & 0xffffdfff;
  }
  iVar1 = FUN_1002695c(param_1,iVar3,&local_2c);
  if ((-1 < *(int *)(iVar3 + 0x68) << 0x1f) && (-1 < (int)((uint)*(ushort *)(iVar3 + 0xc) << 0x16)))
  {
    FUN_1002751c(iVar3 + 0x58);
  }
  return (-(uint)(iVar1 == 0) & 0xb) - 1;
}



/* FUN_10021a64 at 10021a64 */

void FUN_10021a64(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001c744();
  FUN_100219c4(uVar1,param_1);
  return;
}



/* FUN_10021a74 at 10021a74 */

void FUN_10021a74(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001c744();
  FUN_10021da4(uVar1,param_1,param_2);
  return;
}



/* FUN_10021a88 at 10021a88 */

void FUN_10021a88(void)

{
  FUN_1002431c(0x20000e04,0x10026875,&DAT_200009e0);
  return;
}



/* FUN_10021b18 at 10021b18 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021b18(void)

{
  _DAT_20001028 = 0x10021a89;
  _DAT_20001030 = 0;
  _DAT_20001034 = 0;
  _DAT_20001038 = 0;
  _DAT_20001098 = 0;
  _DAT_20001040 = 0;
  _DAT_20001044 = 0;
  _DAT_20001048 = 0;
  _DAT_2000103c = 4;
  FUN_1001f4c8(0x20001090,0,8);
  _DAT_20001054 = &LAB_10026570_1;
  _DAT_2000105c = &LAB_100265dc_1;
  _DAT_20001060 = &LAB_10026608_1;
  _DAT_20001058 = &LAB_1002659c_1;
  _DAT_20001050 = &DAT_20001030;
  FUN_100274a8(0x20001088);
  _DAT_20001108 = 0;
  _DAT_200010ac = 0x10009;
  _DAT_200010b0 = 0;
  _DAT_200010b4 = 0;
  _DAT_200010b8 = 0;
  _DAT_200010a0 = 0;
  _DAT_200010a4 = 0;
  _DAT_200010a8 = 0;
  FUN_1001f4c8(0x20001100,0,8);
  _DAT_200010c0 = &DAT_200010a0;
  _DAT_200010c4 = &LAB_10026570_1;
  _DAT_200010c8 = &LAB_1002659c_1;
  _DAT_200010cc = &LAB_100265dc_1;
  _DAT_200010d0 = &LAB_10026608_1;
  FUN_100274a8(0x200010f8);
  _DAT_20001110 = 0;
  _DAT_20001114 = 0;
  _DAT_20001118 = 0;
  _DAT_20001178 = 0;
  _DAT_2000111c = 0x20012;
  _DAT_20001120 = 0;
  _DAT_20001124 = 0;
  _DAT_20001128 = 0;
  FUN_1001f4c8(0x20001170,0,8);
  _DAT_20001130 = &DAT_20001110;
  _DAT_20001134 = &LAB_10026570_1;
  _DAT_20001138 = &LAB_1002659c_1;
  _DAT_2000113c = &LAB_100265dc_1;
  _DAT_20001140 = &LAB_10026608_1;
  FUN_100274a8(0x20001168);
  return;
}



/* FUN_10021c34 at 10021c34 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_10021c34(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  bool bVar4;
  
  FUN_100274fc(0x20001018);
  if (_DAT_20001028 == 0) {
    FUN_10021b18();
  }
  puVar3 = (undefined4 *)&DAT_200009e0;
  while( true ) {
    while( true ) {
      puVar2 = (undefined4 *)puVar3[2];
      iVar1 = puVar3[1] + -1;
      if (-1 < iVar1) {
        do {
          if (*(short *)(puVar2 + 3) == 0) {
            puVar2[3] = 0xffff0001;
            puVar2[0x1a] = 0;
            FUN_100274a8(puVar2 + 0x16);
            FUN_1002751c(0x20001018);
            *puVar2 = 0;
            puVar2[2] = 0;
            puVar2[1] = 0;
            puVar2[4] = 0;
            puVar2[5] = 0;
            puVar2[6] = 0;
            FUN_1001f4c8(puVar2 + 0x18,0,8);
            puVar2[0xd] = 0;
            puVar2[0xe] = 0;
            puVar2[0x12] = 0;
            puVar2[0x13] = 0;
            return puVar2;
          }
          puVar2 = puVar2 + 0x1c;
          bVar4 = iVar1 != 0;
          iVar1 = iVar1 + -1;
        } while (bVar4);
      }
      if ((undefined4 *)*puVar3 == (undefined4 *)0x0) break;
      puVar3 = (undefined4 *)*puVar3;
    }
    puVar2 = (undefined4 *)FUN_10022670(param_1,0x1d0);
    if (puVar2 == (undefined4 *)0x0) break;
    *puVar2 = 0;
    puVar2[1] = 4;
    puVar2[2] = puVar2 + 4;
    FUN_1001f4c8(puVar2 + 4,0,0x1c0);
    *puVar3 = puVar2;
    puVar3 = puVar2;
  }
  *puVar3 = 0;
  FUN_1002751c(0x20001018);
  *param_1 = 0xc;
  return (undefined4 *)0x0;
}



/* FUN_10021cfc at 10021cfc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10021cfc(int param_1)

{
  FUN_100274fc(0x20001018);
  if (*(int *)(param_1 + 0x20) == 0) {
    *(undefined1 **)(param_1 + 0x20) = &LAB_10021aa4_1;
    if (_DAT_20001028 == 0) {
      FUN_10021b18();
    }
  }
  FUN_1002751c(0x20001018);
  return;
}



/* FUN_10021d34 at 10021d34 */

void FUN_10021d34(void)

{
  FUN_100274fc(0x20001018);
  return;
}



/* FUN_10021d44 at 10021d44 */

void FUN_10021d44(void)

{
  FUN_1002751c(0x20001018);
  return;
}



/* FUN_10021d54 at 10021d54 */

void FUN_10021d54(void)

{
  FUN_100274fc(0x20001018);
  FUN_1002431c(0,&LAB_10021ae0_1,&DAT_200009e0);
  return;
}



/* FUN_10021d74 at 10021d74 */

void FUN_10021d74(void)

{
  FUN_1002431c(0,&LAB_10021afc_1,&DAT_200009e0);
  FUN_1002751c(0x20001018);
  return;
}



/* FUN_10021d94 at 10021d94 */

void FUN_10021d94(void)

{
  FUN_100267b4(6);
                    /* WARNING: Subroutine does not return */
  FUN_100275a6(1);
}



/* FUN_10021da4 at 10021da4 */

undefined4 * FUN_10021da4(undefined4 param_1,uint param_2,uint param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_2 >> 0x10;
  uVar5 = param_3 >> 0x10;
  if (uVar4 == 0) {
    if (uVar5 == 0) {
      puVar2 = (undefined4 *)FUN_10022670(param_1,(param_2 & 0xffff) * (param_3 & 0xffff));
    }
    else {
      uVar4 = uVar5;
      uVar1 = param_2;
LAB_10021e08:
      uVar5 = (param_2 & 0xffff) * (param_3 & 0xffff);
      uVar4 = (uVar1 & 0xffff) * uVar4 + (uVar5 >> 0x10);
      if (uVar4 >> 0x10 != 0) goto LAB_10021e32;
      puVar2 = (undefined4 *)FUN_10022670(param_1,uVar4 * 0x10000 | uVar5 & 0xffff);
    }
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      uVar4 = (puVar2[-1] & 0xfffffffc) - 4;
      if (uVar4 < 0x25) {
        puVar3 = puVar2;
        if (0x13 < uVar4) {
          *puVar2 = 0;
          puVar2[1] = 0;
          puVar3 = puVar2 + 2;
          if (0x1b < uVar4) {
            puVar2[2] = 0;
            puVar2[3] = 0;
            if (uVar4 == 0x24) {
              puVar2[4] = 0;
              puVar3 = puVar2 + 6;
              puVar2[5] = 0;
            }
            else {
              puVar3 = puVar2 + 4;
            }
          }
        }
        *puVar3 = 0;
        puVar3[1] = 0;
        puVar3[2] = 0;
      }
      else {
        FUN_1001f4c8(puVar2,0);
      }
    }
  }
  else {
    uVar1 = param_3;
    if (uVar5 == 0) goto LAB_10021e08;
LAB_10021e32:
    puVar3 = (undefined4 *)FUN_100219bc();
    puVar2 = (undefined4 *)0x0;
    *puVar3 = 0xc;
  }
  return puVar2;
}



/* FUN_10021e48 at 10021e48 */

void FUN_10021e48(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001c744();
  FUN_1002487c(uVar1,param_1,param_2);
  return;
}



/* FUN_10021e5c at 10021e5c */

char * FUN_10021e5c(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5
                   ,int param_6,undefined1 *param_7,int *param_8,uint param_9,int *param_10)

{
  char *pcVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined1 auStack_20 [4];
  char *local_1c;
  
  uVar3 = 0;
  if (param_4 < 0) {
    param_2 = 0x80000000;
    param_4 = param_4 + -0x80000000;
    uVar3 = 0x2d;
  }
  *param_7 = uVar3;
  uVar4 = param_9 & 0xffffffdf;
  if (uVar4 == 0x46) {
    uVar5 = 3;
LAB_10021f08:
    pcVar1 = (char *)FUN_10022d7c(param_1,param_2,param_3,param_4,uVar5,param_5,param_8,auStack_20,
                                  &local_1c);
    pcVar6 = pcVar1 + param_5;
    if (uVar4 != 0x46) goto LAB_10021eba;
    if (*pcVar1 == '0') {
      iVar2 = FUN_1001ea2c(param_3,param_4,0,0);
      if (iVar2 != 0) {
        local_1c = pcVar6 + *param_8;
        goto LAB_10021ee2;
      }
      param_5 = 1 - param_5;
      *param_8 = param_5;
    }
    else {
      param_5 = *param_8;
    }
    pcVar6 = pcVar6 + param_5;
    iVar2 = FUN_1001ea2c(param_3,param_4,0,0);
  }
  else {
    if (uVar4 == 0x45) {
      param_5 = param_5 + 1;
      uVar5 = 2;
      goto LAB_10021f08;
    }
    pcVar1 = (char *)FUN_10022d7c(param_1,param_2,param_3,param_4,2,param_5,param_8,auStack_20,
                                  &local_1c);
    if (((param_9 == 0x67) || (param_9 == 0x47)) && (-1 < param_6 << 0x1f)) goto LAB_10021ee2;
    pcVar6 = pcVar1 + param_5;
LAB_10021eba:
    iVar2 = FUN_1001ea2c(param_3,param_4,0,0);
  }
  if (iVar2 == 0) {
    for (; local_1c < pcVar6; local_1c = local_1c + 1) {
      *local_1c = '0';
    }
  }
  else {
    local_1c = pcVar6;
  }
LAB_10021ee2:
  *param_10 = (int)local_1c - (int)pcVar1;
  return pcVar1;
}



/* FUN_10021f7c at 10021f7c */

int FUN_10021f7c(undefined1 *param_1,int param_2,undefined1 param_3)

{
  bool bVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  char extraout_r1;
  char *pcVar5;
  undefined1 uVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char local_23 [6];
  char cStack_1d;
  
  uVar6 = 0x2b;
  *param_1 = param_3;
  if (param_2 < 0) {
    param_2 = -param_2;
    uVar6 = 0x2d;
  }
  param_1[1] = uVar6;
  if (param_2 < 10) {
    param_1[2] = 0x30;
    pcVar4 = param_1 + 4;
    param_1[3] = (char)param_2 + '0';
  }
  else {
    pcVar7 = local_23 + 2;
    pcVar4 = pcVar7;
    do {
      pcVar9 = pcVar4;
      FUN_1001e480(param_2,10);
      pcVar9[-1] = extraout_r1 + '0';
      iVar3 = FUN_1001e480(param_2,10);
      bVar1 = 99 < param_2;
      param_2 = iVar3;
      pcVar4 = pcVar9 + -1;
    } while (bVar1);
    pcVar8 = pcVar9 + -2;
    pcVar4 = param_1 + 2;
    *pcVar8 = (char)iVar3 + '0';
    if (pcVar8 < pcVar7) {
      pcVar5 = pcVar4;
      do {
        cVar2 = *pcVar8;
        pcVar8 = pcVar8 + 1;
        *pcVar5 = cVar2;
        pcVar5 = pcVar5 + 1;
      } while (pcVar7 != pcVar8);
      pcVar4 = local_23 + 4 + (int)pcVar4 + -(int)pcVar9;
    }
  }
  return (int)pcVar4 - (int)param_1;
}



/* FUN_10022000 at 10022000 */

/* WARNING: Type propagation algorithm not settling */

uint FUN_10022000(undefined4 param_1,uint *param_2,undefined4 param_3,code *param_4,int *param_5)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  undefined *puVar11;
  undefined4 local_58 [2];
  uint local_50;
  uint local_4c;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  char local_35;
  uint local_34;
  uint local_30;
  uint local_2c [2];
  
  puVar1 = (undefined4 *)FUN_100225d0();
  local_44 = *puVar1;
  local_40 = FUN_10024360(local_44);
  local_30 = 0;
  uVar7 = (uint)(byte)param_2[6];
  uVar8 = *param_2;
  puVar9 = (uint *)(*param_5 + 7U & 0xfffffff8);
  uVar5 = *puVar9;
  local_4c = puVar9[1];
  *param_5 = (int)(puVar9 + 2);
  param_2[0x12] = uVar5;
  param_2[0x13] = local_4c;
  uVar10 = local_4c & 0x7fffffff;
  local_50 = uVar5;
  iVar2 = FUN_1001ea62(uVar5,uVar10,0xffffffff,0x7fefffff);
  if ((iVar2 == 0) && (iVar2 = FUN_1001ea48(uVar5,uVar10,0xffffffff,0x7fefffff), iVar2 == 0)) {
    iVar2 = FUN_1001ea3c(local_50,local_4c,0,0);
    if (iVar2 != 0) {
      *(undefined1 *)((int)param_2 + 0x43) = 0x2d;
    }
    if (uVar7 < 0x48) {
      puVar11 = &UNK_1002ad3c;
    }
    else {
      puVar11 = &DAT_1002ad40;
    }
LAB_1002218e:
    param_2[4] = 3;
    iVar2 = 0;
    *param_2 = uVar8 & 0xfffffffb;
  }
  else {
    iVar2 = FUN_1001ea62(local_50,local_4c,local_50,local_4c);
    if (iVar2 != 0) {
      if ((int)local_4c < 0) {
        *(undefined1 *)((int)param_2 + 0x43) = 0x2d;
      }
      if (uVar7 < 0x48) {
        puVar11 = &UNK_1002ad44;
      }
      else {
        puVar11 = &UNK_1002ad48;
      }
      goto LAB_1002218e;
    }
    local_3c = uVar7 & 0xffffffdf;
    uVar5 = param_2[1];
    uVar8 = uVar8 | 0x400;
    if (uVar5 == 0xffffffff) {
      param_2[1] = 6;
      *param_2 = uVar8;
      local_58[0] = 0;
      puVar11 = (undefined *)
                FUN_10021e5c(param_1,local_58,local_50,local_4c,6,uVar8,&local_35,&local_34,uVar7,
                             &local_30);
      if (local_3c != 0x47) goto LAB_100220d0;
joined_r0x10022142:
      if (((int)local_34 < -3) || ((int)param_2[1] < (int)local_34)) {
        uVar7 = uVar7 - 2 & 0xff;
        goto LAB_1002214e;
      }
      uVar7 = 0x67;
LAB_100220de:
      if ((int)local_34 < (int)local_30) {
        iVar2 = 1;
        if ((int)local_34 < 1) {
          iVar2 = 2 - local_34;
        }
        param_2[4] = local_30 + iVar2;
      }
      else {
        param_2[4] = local_34;
        if ((int)(*param_2 << 0x1f) < 0) {
          param_2[4] = local_34 + 1;
        }
      }
LAB_100220f4:
      iVar2 = 0;
      param_2[0x16] = local_34;
    }
    else {
      if (local_3c == 0x47) {
        if (uVar5 == 0) {
          uVar5 = 1;
          param_2[1] = 1;
        }
        *param_2 = uVar8;
        local_58[0] = 0;
        puVar11 = (undefined *)
                  FUN_10021e5c(param_1,local_58,local_50,local_4c,uVar5,uVar8,&local_35,&local_34,
                               uVar7,&local_30);
        goto joined_r0x10022142;
      }
      *param_2 = uVar8;
      local_58[0] = 0;
      puVar11 = (undefined *)
                FUN_10021e5c(param_1,local_58,local_50,local_4c,uVar5,uVar8,&local_35,&local_34,
                             uVar7,&local_30);
LAB_100220d0:
      if (0x65 < uVar7) {
        if (uVar7 != 0x66) goto LAB_100220de;
        uVar5 = param_2[1];
        if ((int)local_34 < 1) {
          if (uVar5 == 0) {
            uVar5 = 1;
            if ((int)(*param_2 << 0x1f) < 0) {
              uVar5 = 2;
            }
          }
          else {
            uVar5 = uVar5 + 2;
          }
          param_2[4] = uVar5;
        }
        else {
          param_2[4] = local_34;
          if ((uVar5 != 0) || ((int)(*param_2 << 0x1f) < 0)) {
            param_2[4] = uVar5 + 1 + local_34;
          }
        }
        goto LAB_100220f4;
      }
LAB_1002214e:
      local_34 = local_34 - 1;
      iVar2 = FUN_10021f7c(param_2 + 0x14,local_34,uVar7);
      param_2[4] = local_30 + iVar2;
      if ((1 < (int)local_30) || ((int)(*param_2 << 0x1f) < 0)) {
        param_2[4] = local_30 + iVar2 + 1;
      }
    }
    if (local_35 != '\0') {
      *(undefined1 *)((int)param_2 + 0x43) = 0x2d;
    }
  }
  iVar3 = FUN_10024bcc(param_1,param_2,local_2c,param_3,param_4);
  if (iVar3 == -1) {
    return 0xffffffff;
  }
  if ((int)(*param_2 << 0x15) < 0) {
    if (uVar7 < 0x66) {
      local_50 = local_30;
      if (((int)local_30 < 2) && (-1 < (int)(*param_2 << 0x1f))) {
        iVar3 = (*param_4)(param_1,param_3,puVar11,1);
joined_r0x1002238c:
        if (iVar3 == -1) {
          return 0xffffffff;
        }
      }
      else {
        iVar3 = (*param_4)(param_1,param_3,puVar11,1);
        if (iVar3 == -1) {
          return 0xffffffff;
        }
        iVar3 = (*param_4)(param_1,param_3,local_44,local_40);
        if (iVar3 == -1) {
          return 0xffffffff;
        }
        iVar6 = local_50 - 1;
        iVar3 = FUN_1001ea2c(param_2[0x12],param_2[0x13],0,0);
        if (iVar3 == 0) {
          iVar3 = (*param_4)(param_1,param_3,puVar11 + 1,iVar6);
          goto joined_r0x1002238c;
        }
        iVar3 = 0;
        if (1 < (int)local_50) {
          do {
            iVar4 = (*param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
            if (iVar4 == -1) {
              return 0xffffffff;
            }
            iVar3 = iVar3 + 1;
          } while (iVar3 != iVar6);
        }
      }
      iVar2 = (*param_4)(param_1,param_3,param_2 + 0x14,iVar2);
      goto joined_r0x1002239e;
    }
    iVar2 = FUN_1001ea2c(param_2[0x12],param_2[0x13],0,0);
    if (iVar2 == 0) {
      if ((int)local_34 < 1) {
        iVar2 = (*param_4)(param_1,param_3,&DAT_1002ad4c,1);
        if (iVar2 == -1) {
          return 0xffffffff;
        }
        if ((local_34 == 0 && local_30 == 0) && (uVar7 = *param_2, -1 < (int)(uVar7 << 0x1f)))
        goto LAB_100221c8;
        iVar2 = (*param_4)(param_1,param_3,local_44,local_40);
        if (iVar2 == -1) {
          return 0xffffffff;
        }
        if ((int)local_34 < 0) {
          iVar2 = 0;
          do {
            iVar3 = (*param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
            if (iVar3 == -1) {
              return 0xffffffff;
            }
            iVar2 = iVar2 + 1;
          } while (-iVar2 != local_34 && iVar2 <= (int)-local_34);
        }
        uVar5 = local_30;
        goto LAB_100221ba;
      }
      uVar7 = param_2[0x16];
      local_50 = local_30;
      uVar5 = local_30;
      if ((int)uVar7 < (int)local_30) {
        uVar5 = uVar7;
      }
      if (0 < (int)uVar5) {
        iVar2 = (*param_4)(param_1,param_3,puVar11,uVar5);
        if (iVar2 == -1) {
          return 0xffffffff;
        }
        uVar7 = param_2[0x16];
      }
      uVar5 = (int)~uVar5 >> 0x1f & uVar5;
      if ((int)uVar5 < (int)uVar7) {
        iVar2 = 0;
        do {
          iVar3 = (*param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
          if (iVar3 == -1) {
            return 0xffffffff;
          }
          uVar7 = param_2[0x16];
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)(uVar7 - uVar5));
      }
      if (((int)local_34 < (int)local_50) || ((int)(*param_2 << 0x1f) < 0)) {
        iVar2 = (*param_4)(param_1,param_3,local_44,local_40);
        if (iVar2 == -1) {
          return 0xffffffff;
        }
        uVar8 = local_50 - local_34;
        uVar5 = local_50 - uVar7;
        if ((int)uVar8 < (int)(local_50 - uVar7)) {
          uVar5 = uVar8;
        }
        if (0 < (int)uVar5) {
          iVar2 = (*param_4)(param_1,param_3,puVar11 + uVar7,uVar5);
          if (iVar2 == -1) {
            return 0xffffffff;
          }
          uVar8 = local_50 - local_34;
        }
      }
      else {
        uVar8 = local_50 - local_34;
        uVar5 = local_50 - uVar7;
        if ((int)uVar8 < (int)(local_50 - uVar7)) {
          uVar5 = uVar8;
        }
      }
      uVar7 = local_50;
      uVar5 = uVar5 & (int)~uVar5 >> 0x1f;
      iVar2 = 0;
      if ((int)uVar5 < (int)uVar8) {
        do {
          iVar3 = (*param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
          if (iVar3 == -1) {
            return 0xffffffff;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < (int)((uVar7 - local_34) - uVar5));
        uVar7 = *param_2;
        goto LAB_100221c8;
      }
    }
    else {
      iVar2 = (*param_4)(param_1,param_3,&DAT_1002ad4c,1);
      uVar5 = local_30;
      if (iVar2 == -1) {
        return 0xffffffff;
      }
      if (((int)local_30 <= (int)local_34) && (uVar7 = *param_2, -1 < (int)(uVar7 << 0x1f)))
      goto LAB_100221c8;
      iVar2 = (*param_4)(param_1,param_3,local_44,local_40);
      if (iVar2 == -1) {
        return 0xffffffff;
      }
      if (1 < (int)uVar5) {
        iVar2 = 0;
        do {
          iVar3 = (*param_4)(param_1,param_3,(int)param_2 + 0x1a,1);
          if (iVar3 == -1) {
            return 0xffffffff;
          }
          iVar2 = iVar2 + 1;
        } while (uVar5 - 1 != iVar2);
        uVar7 = *param_2;
        goto LAB_100221c8;
      }
    }
  }
  else {
    uVar5 = param_2[4];
LAB_100221ba:
    iVar2 = (*param_4)(param_1,param_3,puVar11,uVar5);
joined_r0x1002239e:
    if (iVar2 == -1) {
      return 0xffffffff;
    }
  }
  uVar7 = *param_2;
LAB_100221c8:
  uVar5 = param_2[3];
  if (((int)(uVar7 << 0x1e) < 0) && ((int)local_2c[0] < (int)uVar5)) {
    iVar2 = 0;
    do {
      iVar3 = (*param_4)(param_1,param_3,(int)param_2 + 0x19,1);
      if (iVar3 == -1) {
        return 0xffffffff;
      }
      uVar5 = param_2[3];
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uVar5 - local_2c[0]));
  }
  if ((int)uVar5 < (int)local_2c[0]) {
    return local_2c[0];
  }
  return uVar5;
}



/* FUN_100225d0 at 100225d0 */

undefined4 FUN_100225d0(void)

{
  return 0x20000f40;
}



/* FUN_100225e0 at 100225e0 */

int FUN_100225e0(uint *param_1,uint *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_3 == 0) {
LAB_10022636:
    iVar1 = 0;
  }
  else {
    if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
      for (; (3 < param_3 && (uVar2 = *param_1, uVar2 == *param_2)); param_1 = param_1 + 1) {
        param_3 = param_3 - 4;
        if ((param_3 == 0) || ((uVar2 + 0xfefefeff & ~uVar2 & 0x80808080) != 0)) goto LAB_10022636;
        param_2 = param_2 + 1;
      }
    }
    uVar4 = (uint)(byte)*param_2;
    uVar3 = (uint)(byte)*param_1;
    uVar2 = 1;
    if (uVar3 == uVar4) {
      do {
        if ((param_3 == uVar2) || (uVar3 == 0)) goto LAB_10022636;
        uVar3 = (uint)*(byte *)((int)param_1 + uVar2);
        uVar4 = (uint)*(byte *)((int)param_2 + uVar2);
        uVar2 = uVar2 + 1;
      } while (uVar3 == uVar4);
    }
    iVar1 = uVar3 - uVar4;
  }
  return iVar1;
}



/* FUN_10022648 at 10022648 */

void FUN_10022648(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_1001c744();
  FUN_1002553c(iVar1,*(undefined4 *)(iVar1 + 8),param_1,param_2);
  return;
}



/* FUN_10022670 at 10022670 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_10022670(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  undefined1 *puVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  int iVar10;
  undefined1 *puVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  undefined1 *puVar16;
  uint local_34;
  
  uVar12 = param_2 + 0xb;
  if (uVar12 < 0x17) {
    if (0x10 < param_2) goto LAB_10022838;
    FUN_10025050();
    uVar13 = 0x10;
    iVar6 = 0x18;
    uVar12 = 2;
LAB_10022698:
    puVar11 = *(undefined1 **)(&DAT_200009fc + iVar6);
    if (puVar11 == &DAT_200009f0 + iVar6) {
      puVar11 = *(undefined1 **)(iVar6 + 0x20000a04);
      uVar12 = uVar12 + 2;
      if ((undefined1 *)(iVar6 + 0x200009f8) == puVar11) goto LAB_1002273e;
    }
    iVar6 = *(int *)(puVar11 + 8);
    uVar14 = *(uint *)(puVar11 + 4) & 0xfffffffc;
    iVar10 = *(int *)(puVar11 + 0xc);
    *(int *)(iVar6 + 0xc) = iVar10;
    *(int *)(iVar10 + 8) = iVar6;
LAB_100226b6:
    *(uint *)(puVar11 + uVar14 + 4) = *(uint *)(puVar11 + uVar14 + 4) | 1;
    FUN_10025060(param_1);
    return (int *)(puVar11 + 8);
  }
  uVar13 = uVar12 & 0xfffffff8;
  if (((int)uVar13 < 0) || (uVar13 < param_2)) {
LAB_10022838:
    *param_1 = 0xc;
    return (int *)0x0;
  }
  FUN_10025050();
  if (uVar13 < 0x1f8) {
    uVar12 = uVar12 >> 3;
    iVar6 = uVar13 + 8;
    goto LAB_10022698;
  }
  uVar14 = uVar12 >> 9;
  if (uVar14 == 0) {
    uVar12 = 0x40;
    uVar1 = 0x3f;
    iVar6 = 0x200;
  }
  else if (uVar14 < 5) {
    uVar1 = (uVar12 >> 6) + 0x38;
    uVar12 = (uVar12 >> 6) + 0x39;
    iVar6 = uVar12 * 8;
  }
  else if (uVar14 < 0x15) {
    uVar1 = uVar14 + 0x5b;
    uVar12 = uVar14 + 0x5c;
    iVar6 = uVar12 * 8;
  }
  else if (uVar14 < 0x55) {
    uVar1 = (uVar12 >> 0xc) + 0x6e;
    uVar12 = (uVar12 >> 0xc) + 0x6f;
    iVar6 = uVar12 * 8;
  }
  else if (uVar14 < 0x155) {
    uVar1 = (uVar12 >> 0xf) + 0x77;
    uVar12 = (uVar12 >> 0xf) + 0x78;
    iVar6 = uVar12 * 8;
  }
  else if (uVar14 < 0x555) {
    uVar1 = (uVar12 >> 0x12) + 0x7c;
    uVar12 = (uVar12 >> 0x12) + 0x7d;
    iVar6 = uVar12 * 8;
  }
  else {
    uVar12 = 0x7f;
    uVar1 = 0x7e;
    iVar6 = 0x3f8;
  }
  puVar11 = *(undefined1 **)(&DAT_200009fc + iVar6);
  if (&DAT_200009f0 + iVar6 != puVar11) {
    while( true ) {
      uVar14 = *(uint *)(puVar11 + 4) & 0xfffffffc;
      if (0xf < (int)(uVar14 - uVar13)) break;
      puVar4 = *(undefined1 **)(puVar11 + 0xc);
      if (-1 < (int)(uVar14 - uVar13)) {
        iVar6 = *(int *)(puVar11 + 8);
        *(undefined1 **)(iVar6 + 0xc) = puVar4;
        *(int *)(puVar4 + 8) = iVar6;
        goto LAB_100226b6;
      }
      if (&DAT_200009f0 + iVar6 == puVar4) goto LAB_1002273e;
      puVar11 = puVar4;
    }
    uVar12 = uVar1;
  }
LAB_1002273e:
  puVar11 = _DAT_20000a08;
  if (_DAT_20000a08 == &DAT_20000a00) {
    uVar14 = _DAT_200009fc;
  }
  else {
    uVar5 = *(uint *)(_DAT_20000a08 + 4);
    uVar14 = uVar5 & 0xfffffffc;
    uVar1 = uVar14 - uVar13;
    if (0xf < (int)uVar1) {
      puVar4 = _DAT_20000a08 + uVar13;
      *(uint *)(_DAT_20000a08 + 4) = uVar13 | 1;
      _DAT_20000a08 = puVar4;
      _DAT_20000a0c = puVar4;
      *(undefined1 **)(puVar4 + 0xc) = &DAT_20000a00;
      *(undefined1 **)(puVar4 + 8) = &DAT_20000a00;
      *(uint *)(puVar4 + 4) = uVar1 | 1;
      *(uint *)(puVar11 + uVar14) = uVar1;
      FUN_10025060(param_1);
      return (int *)(puVar11 + 8);
    }
    _DAT_20000a08 = &DAT_20000a00;
    _DAT_20000a0c = &DAT_20000a00;
    if (-1 < (int)uVar1) goto LAB_100226b6;
    if (uVar14 < 0x200) {
      uVar14 = _DAT_200009fc | 1 << (uVar5 >> 5 & 0xff);
      uVar5 = uVar5 & 0xfffffff8;
      iVar6 = *(int *)(&DAT_20000a00 + uVar5);
      _DAT_200009fc = uVar14;
      *(uint *)(puVar11 + 0xc) = uVar5 + 0x200009f8;
      *(int *)(puVar11 + 8) = iVar6;
      *(undefined1 **)(&DAT_20000a00 + uVar5) = puVar11;
      *(undefined1 **)(iVar6 + 0xc) = puVar11;
    }
    else {
      uVar1 = uVar5 >> 9;
      if (uVar1 < 5) {
        iVar6 = (uVar5 >> 6) + 0x38;
        iVar10 = ((uVar5 >> 6) + 0x39) * 8;
      }
      else if (uVar1 < 0x15) {
        iVar6 = uVar1 + 0x5b;
        iVar10 = (uVar1 + 0x5c) * 8;
      }
      else if (uVar1 < 0x55) {
        iVar6 = (uVar5 >> 0xc) + 0x6e;
        iVar10 = ((uVar5 >> 0xc) + 0x6f) * 8;
      }
      else if (uVar1 < 0x155) {
        iVar6 = (uVar5 >> 0xf) + 0x77;
        iVar10 = ((uVar5 >> 0xf) + 0x78) * 8;
      }
      else if (uVar1 < 0x555) {
        iVar6 = (uVar5 >> 0x12) + 0x7c;
        iVar10 = ((uVar5 >> 0x12) + 0x7d) * 8;
      }
      else {
        iVar10 = 0x3f8;
        iVar6 = 0x7e;
      }
      puVar16 = &DAT_200009f0 + iVar10;
      puVar4 = *(undefined1 **)(iVar10 + 0x200009f8);
      if (puVar16 == puVar4) {
        _DAT_200009fc = _DAT_200009fc | 1 << (iVar6 >> 2 & 0xffU);
      }
      else {
        do {
          if ((*(uint *)(puVar4 + 4) & 0xfffffffc) <= uVar14) break;
          puVar4 = *(undefined1 **)(puVar4 + 8);
        } while (puVar16 != puVar4);
        puVar16 = *(undefined1 **)(puVar4 + 0xc);
      }
      uVar14 = _DAT_200009fc;
      *(undefined1 **)(puVar11 + 8) = puVar4;
      *(undefined1 **)(puVar11 + 0xc) = puVar16;
      *(undefined1 **)(puVar16 + 8) = puVar11;
      *(undefined1 **)(puVar4 + 0xc) = puVar11;
    }
  }
  uVar1 = _DAT_20000a00;
  local_34 = 1 << ((int)uVar12 >> 2 & 0xffU);
  if (local_34 <= uVar14) {
    if ((uVar14 & local_34) == 0) {
      uVar12 = uVar12 & 0xfffffffc;
      do {
        local_34 = local_34 << 1;
        uVar12 = uVar12 + 4;
      } while ((uVar14 & local_34) == 0);
    }
    do {
      piVar2 = (int *)(uVar12 * 8 + 0x200009f8);
      piVar9 = piVar2;
      uVar14 = uVar12;
      do {
        piVar7 = (int *)piVar9[3];
        while (piVar8 = piVar7, piVar9 != piVar8) {
          uVar5 = piVar8[1] & 0xfffffffc;
          piVar7 = (int *)piVar8[3];
          uVar3 = uVar5 - uVar13;
          if (0xf < (int)uVar3) {
            iVar6 = (int)piVar8 + uVar13;
            piVar8[1] = uVar13 | 1;
            iVar10 = piVar8[2];
            *(int **)(iVar10 + 0xc) = piVar7;
            piVar7[2] = iVar10;
            _DAT_20000a08 = (undefined1 *)iVar6;
            _DAT_20000a0c = (undefined1 *)iVar6;
            *(uint *)(iVar6 + 4) = uVar3 | 1;
            *(undefined1 **)(iVar6 + 0xc) = &DAT_20000a00;
            *(undefined1 **)(iVar6 + 8) = &DAT_20000a00;
            *(uint *)((int)piVar8 + uVar5) = uVar3;
            FUN_10025060(param_1);
            return piVar8 + 2;
          }
          if (-1 < (int)uVar3) {
            *(uint *)((int)piVar8 + uVar5 + 4) = *(uint *)((int)piVar8 + uVar5 + 4) | 1;
            iVar6 = piVar8[2];
            *(int **)(iVar6 + 0xc) = piVar7;
            piVar7[2] = iVar6;
            FUN_10025060(param_1);
            return piVar8 + 2;
          }
        }
        uVar14 = uVar14 + 1;
        piVar9 = piVar9 + 2;
      } while ((uVar14 & 3) != 0);
      do {
        if ((uVar12 & 3) == 0) {
          _DAT_200009fc = _DAT_200009fc & ~local_34;
          break;
        }
        piVar9 = (int *)*piVar2;
        piVar2 = piVar2 + -2;
        uVar12 = uVar12 - 1;
      } while (piVar9 == piVar2);
      local_34 = local_34 * 2;
      if ((_DAT_200009fc < local_34) || (uVar12 = uVar14, local_34 == 0)) break;
      for (; (_DAT_200009fc & local_34) == 0; local_34 = local_34 << 1) {
        uVar12 = uVar12 + 4;
      }
    } while( true );
  }
  uVar12 = *(uint *)(_DAT_20000a00 + 4) & 0xfffffffc;
  if (uVar13 <= uVar12) {
    uVar5 = uVar12 - uVar13;
    uVar14 = _DAT_20000a00;
    if (0xf < (int)uVar5) goto LAB_10022992;
  }
  uVar5 = _DAT_20000a00 + uVar12;
  local_34 = _DAT_2000136c + 0x10 + uVar13;
  iVar6 = FUN_10024860(8);
  if (_DAT_200009f0 != 0xffffffff) {
    local_34 = (local_34 - 1) + iVar6 & -iVar6;
  }
  uVar3 = FUN_10026850(param_1,local_34);
  uVar14 = _DAT_20000a00;
  if (uVar3 == 0xffffffff) {
LAB_10022ae6:
    local_34 = *(uint *)(_DAT_20000a00 + 4);
  }
  else {
    if (uVar3 < uVar5) {
      if (uVar1 != 0x200009f8) goto LAB_10022ae6;
LAB_100228d8:
      uVar15 = iVar6 - 1;
      _DAT_20001370 = _DAT_20001370 + local_34;
      if (_DAT_200009f0 == 0xffffffff) {
        _DAT_200009f0 = uVar3;
      }
      else {
        _DAT_20001370 = (uVar3 - uVar5) + _DAT_20001370;
      }
      uVar14 = uVar3 & 7;
      if ((uVar3 & 7) == 0) {
        uVar5 = iVar6 - (local_34 + uVar3 & uVar15);
        iVar6 = FUN_10026850(param_1);
        if (iVar6 != -1) goto LAB_10022924;
        uVar15 = 0;
        uVar14 = uVar3;
      }
      else {
        iVar10 = 8 - uVar14;
        uVar3 = uVar3 + iVar10;
        uVar5 = (iVar10 + iVar6) - (local_34 + uVar3 & uVar15);
        iVar6 = FUN_10026850(param_1);
        if (iVar6 == -1) {
          local_34 = ((uVar14 - 8) + local_34 + uVar3) - uVar3;
          uVar15 = 0;
          uVar14 = uVar3;
        }
        else {
LAB_10022924:
          uVar15 = uVar15 & uVar5;
          local_34 = (iVar6 - uVar3) + uVar15;
          uVar14 = uVar3;
        }
      }
      uVar15 = _DAT_20001370 + uVar15;
      local_34 = local_34 | 1;
      _DAT_20000a00 = uVar14;
      _DAT_20001370 = uVar15;
      *(uint *)(uVar14 + 4) = local_34;
      if (uVar1 != 0x200009f8) {
        if (uVar12 < 0x10) {
          *(undefined4 *)(uVar14 + 4) = 1;
          goto LAB_10022afa;
        }
        uVar12 = uVar12 - 0xc & 0xfffffff8;
        *(uint *)(uVar1 + 4) = *(uint *)(uVar1 + 4) & 1 | uVar12;
        *(undefined4 *)(uVar1 + uVar12 + 4) = 5;
        *(undefined4 *)(uVar1 + uVar12 + 8) = 5;
        if (uVar12 < 0x10) {
          local_34 = *(uint *)(uVar14 + 4);
        }
        else {
          FUN_10023f9c(param_1,uVar1 + 8);
          local_34 = *(uint *)(_DAT_20000a00 + 4);
          uVar15 = _DAT_20001370;
          uVar14 = _DAT_20000a00;
        }
      }
    }
    else {
      uVar15 = _DAT_20001370 + local_34;
      if ((uVar5 != uVar3) || ((uVar3 & iVar6 - 1U) != 0)) goto LAB_100228d8;
      local_34 = local_34 + uVar12 | 1;
      _DAT_20001370 = uVar15;
      *(uint *)(_DAT_20000a00 + 4) = local_34;
    }
    if (_DAT_20001398 < uVar15) {
      _DAT_20001398 = uVar15;
    }
    if (_DAT_2000139c < uVar15) {
      _DAT_2000139c = uVar15;
    }
  }
  uVar5 = (local_34 & 0xfffffffc) - uVar13;
  if ((uVar13 <= (local_34 & 0xfffffffc)) && (0xf < (int)uVar5)) {
LAB_10022992:
    _DAT_20000a00 = uVar14 + uVar13;
    *(uint *)(uVar14 + 4) = uVar13 | 1;
    *(uint *)(_DAT_20000a00 + 4) = uVar5 | 1;
    FUN_10025060(param_1);
    return (int *)(uVar14 + 8);
  }
LAB_10022afa:
  FUN_10025060(param_1);
  return (int *)0x0;
}



/* FUN_10022c2c at 10022c2c */

int FUN_10022c2c(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint *puVar10;
  uint *puVar11;
  uint *local_38;
  
  if (*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10)) {
    iVar2 = 0;
  }
  else {
    iVar9 = *(int *)(param_2 + 0x10) + -1;
    puVar4 = (uint *)(param_2 + 0x14);
    puVar11 = (uint *)(param_1 + 0x14);
    puVar10 = puVar4 + iVar9;
    puVar5 = puVar11 + iVar9;
    uVar6 = *puVar5;
    uVar7 = *puVar10;
    iVar2 = FUN_1001e4d0(uVar6,uVar7 + 1);
    if (uVar7 + 1 <= uVar6) {
      iVar1 = 0;
      uVar6 = 0;
      puVar3 = puVar11;
      local_38 = puVar4;
      do {
        uVar7 = *local_38;
        local_38 = local_38 + 1;
        uVar6 = iVar2 * (uVar7 & 0xffff) + uVar6;
        uVar7 = iVar2 * (uVar7 >> 0x10) + (uVar6 >> 0x10);
        uVar6 = ((*puVar3 & 0xffff) - (uVar6 & 0xffff)) + iVar1;
        iVar8 = ((*puVar3 >> 0x10) - (uVar7 & 0xffff)) + ((int)uVar6 >> 0x10);
        iVar1 = iVar8 >> 0x10;
        *puVar3 = iVar8 * 0x10000 | uVar6 & 0xffff;
        puVar3 = puVar3 + 1;
        uVar6 = uVar7 >> 0x10;
      } while (local_38 <= puVar10);
      if (*puVar5 == 0) {
        while ((puVar5 = puVar5 + -1, puVar11 < puVar5 && (*puVar5 == 0))) {
          iVar9 = iVar9 + -1;
        }
        *(int *)(param_1 + 0x10) = iVar9;
      }
    }
    iVar1 = FUN_100260a8(param_1,param_2);
    if (-1 < iVar1) {
      iVar1 = 0;
      puVar5 = puVar11;
      do {
        uVar7 = *puVar4;
        puVar4 = puVar4 + 1;
        uVar6 = ((*puVar5 & 0xffff) - (uVar7 & 0xffff)) + iVar1;
        iVar8 = ((*puVar5 >> 0x10) - (uVar7 >> 0x10)) + ((int)uVar6 >> 0x10);
        iVar1 = iVar8 >> 0x10;
        *puVar5 = iVar8 * 0x10000 | uVar6 & 0xffff;
        puVar5 = puVar5 + 1;
      } while (puVar4 <= puVar10);
      puVar5 = puVar11 + iVar9;
      if (*puVar5 == 0) {
        while ((puVar5 = puVar5 + -1, puVar11 < puVar5 && (*puVar5 == 0))) {
          iVar9 = iVar9 + -1;
        }
        iVar2 = iVar2 + 1;
        *(int *)(param_1 + 0x10) = iVar9;
      }
      else {
        iVar2 = iVar2 + 1;
      }
    }
  }
  return iVar2;
}



/* FUN_10022d7c at 10022d7c */

undefined *
FUN_10022d7c(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,int param_6,
            int *param_7,uint *param_8,undefined4 *param_9)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined *puVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int iVar9;
  char *pcVar10;
  int extraout_r1;
  uint extraout_r3;
  char *pcVar11;
  uint uVar12;
  uint extraout_r3_00;
  char *extraout_r3_01;
  uint extraout_r3_02;
  char *pcVar13;
  char *extraout_r3_03;
  undefined4 uVar14;
  char *pcVar15;
  int *piVar16;
  char *pcVar17;
  int iVar18;
  uint uVar19;
  undefined4 uVar20;
  char *pcVar21;
  char *pcVar22;
  bool bVar23;
  undefined4 *puVar24;
  undefined8 uVar25;
  undefined8 uVar26;
  ulonglong uVar27;
  undefined8 uVar28;
  char *local_8c;
  uint local_88;
  uint local_84;
  uint local_80;
  uint local_78;
  char *local_74;
  char *pcStack_70;
  char *pcStack_6c;
  uint local_68;
  char *pcStack_60;
  uint uStack_5c;
  char *pcStack_58;
  char *pcStack_54;
  uint uStack_44;
  char *pcStack_40;
  int local_30;
  int local_2c [2];
  
  piVar16 = *(int **)(param_1 + 0x1c);
  if (piVar16 == (int *)0x0) {
    puVar8 = (undefined4 *)FUN_1001c78c(0x10);
    *(undefined4 **)(param_1 + 0x1c) = puVar8;
    if (puVar8 == (undefined4 *)0x0) {
      puVar8 = (undefined4 *)FUN_10023ea4();
    }
    puVar8[1] = 0;
    puVar8[2] = 0;
    *puVar8 = 0;
    puVar8[3] = 0;
  }
  else {
    iVar9 = *piVar16;
    if (iVar9 != 0) {
      uVar19 = piVar16[1];
      *(uint *)(iVar9 + 4) = uVar19;
      *(int *)(iVar9 + 8) = 1 << (uVar19 & 0xff);
      FUN_10025a44();
      **(undefined4 **)(param_1 + 0x1c) = 0;
    }
  }
  local_84 = param_4;
  if ((int)param_4 < 0) {
    local_84 = param_4 & 0x7fffffff;
  }
  *param_8 = (uint)((int)param_4 < 0);
  if ((local_84 & 0x7ff00000) == 0x7ff00000) {
    *param_7 = 9999;
    if ((local_84 & 0xfffff) == 0 && param_3 == 0) {
      if (param_9 == (undefined4 *)0x0) {
        FUN_10023ebc();
      }
      pcVar11 = "";
    }
    else {
      if (param_9 == (undefined4 *)0x0) {
        puVar5 = (undefined *)FUN_10022e06();
        return puVar5;
      }
      pcVar11 = "";
    }
    *param_9 = pcVar11;
    puVar5 = (undefined *)FUN_10022e06();
    return puVar5;
  }
  uVar25 = FUN_1001ea2c(param_3,local_84,0,0);
  if ((int)uVar25 != 0) {
    *param_7 = 1;
    if (param_9 != (undefined4 *)0x0) {
      *param_9 = &DAT_1002ad4d;
    }
    return &DAT_1002ad4c;
  }
  pcVar11 = (char *)FUN_10026384(param_1,(int)((ulonglong)uVar25 >> 0x20),param_3,local_84,local_2c,
                                 &local_30);
  iVar9 = local_30;
  if (local_84 >> 0x14 == 0) {
    iVar18 = local_2c[0] + local_30;
    iVar4 = iVar18 + 0x432;
    if (iVar4 < 0x21) {
      uVar19 = param_3 << (0x20U - iVar4 & 0xff);
    }
    else {
      uVar19 = local_84 << (0x40U - iVar4 & 0xff) | param_3 >> (iVar18 + 0x412U & 0xff);
    }
    uVar25 = FUN_1001ea7c(uVar19);
    uVar19 = (uint)uVar25;
    bVar23 = true;
    iVar18 = iVar18 + -1;
    uVar12 = (int)((ulonglong)uVar25 >> 0x20) + 0xfe100000;
  }
  else {
    uVar12 = local_84 & 0xfffff | 0x3ff00000;
    iVar18 = (local_84 >> 0x14) - 0x3ff;
    bVar23 = false;
    uVar19 = param_3;
  }
  uVar25 = FUN_1001e946(uVar19,uVar12,0,0x3ff80000);
  uVar25 = FUN_1001e9a6((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),0x636f4361,0x3fd287a7);
  uVar25 = FUN_1001e958((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),0x8b60c8b3,0x3fc68a28);
  uVar26 = FUN_1001ea84(iVar18);
  uVar26 = FUN_1001e9a6((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),0x509f79fb,0x3fd34413);
  uVar25 = FUN_1001e958((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),(int)uVar26,
                        (int)((ulonglong)uVar26 >> 0x20));
  uVar7 = (undefined4)((ulonglong)uVar25 >> 0x20);
  local_78 = FUN_1001eab4();
  iVar4 = FUN_1001ea3c((int)uVar25,uVar7,0,0);
  if (iVar4 != 0) {
    uVar26 = FUN_1001ea84(local_78);
    iVar4 = FUN_1001ea2c((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),(int)uVar25,uVar7);
    local_78 = local_78 - (iVar4 == 0);
  }
  pcVar22 = (char *)(iVar9 - iVar18);
  pcStack_40 = pcVar22 + -1;
  if (local_78 < 0x17) {
    iVar9 = FUN_1001ea3c(param_3,local_84,*(undefined4 *)(&DAT_1002b358 + local_78 * 8),
                         *(undefined4 *)(&DAT_1002b35c + local_78 * 8));
    if (iVar9 != 0) {
      local_78 = local_78 - 1;
      bVar1 = false;
      goto LAB_100232fe;
    }
    if ((int)pcVar22 < 1) {
      FUN_10023a8e();
    }
    local_68 = local_78;
    pcStack_40 = pcStack_40 + local_78;
    bVar1 = false;
    local_74 = (char *)0x0;
    pcStack_6c = (char *)0x0;
  }
  else {
    bVar1 = true;
LAB_100232fe:
    local_74 = (char *)0x0;
    if ((int)pcStack_40 < 0) {
      local_74 = (char *)(1 - (int)pcVar22);
      pcStack_40 = (char *)0x0;
    }
    if (-1 < (int)local_78) {
      puVar5 = (undefined *)FUN_10022f0a();
      return puVar5;
    }
    local_74 = (char *)((int)local_74 - local_78);
    pcStack_6c = (char *)-local_78;
    local_68 = 0;
  }
  pcVar17 = *(char **)(param_1 + 0x1c);
  pcStack_60 = pcVar11;
  local_88 = param_3;
  if (param_5 < 10) {
    if ((int)param_5 < 6) {
      uVar19 = param_5;
      if (param_5 == 4) {
        FUN_10023a86();
        uVar19 = extraout_r3_00;
      }
      if (uVar19 == 5) {
        bVar23 = true;
        goto LAB_10022f9e;
      }
      if (uVar19 == 2) {
        while( true ) {
          if (0 < param_6) {
            FUN_10022fb8();
          }
          pcVar17[4] = '\0';
          pcVar17[5] = '\0';
          pcVar17[6] = '\0';
          pcVar17[7] = '\0';
          iVar9 = FUN_100259c0(param_1,0);
          if (iVar9 == 0) break;
          **(int **)(param_1 + 0x1c) = iVar9;
          param_6 = 1;
          FUN_10022ff0();
        }
        puVar5 = (undefined *)FUN_10023dc4();
        return puVar5;
      }
      if (uVar19 == 3) {
        bVar23 = true;
        bVar2 = false;
        goto LAB_10022fa2;
      }
      goto LAB_1002323a;
    }
    param_5 = param_5 - 4;
    bVar23 = false;
    uVar19 = param_5;
    if (param_5 == 4) {
      FUN_10023a88();
      uVar19 = extraout_r3;
    }
    if (uVar19 == 5) {
LAB_10022f9e:
      bVar2 = true;
    }
    else {
      if (uVar19 == 2) {
        FUN_10023a48();
      }
      param_5 = 3;
      bVar2 = false;
    }
LAB_10022fa2:
    pcVar10 = (char *)(param_6 + local_78);
    pcVar13 = pcVar10 + 1;
    if ((int)pcVar13 < 1) {
                    /* WARNING: Subroutine does not return */
      FUN_10023e9c();
    }
    iVar4 = 4;
    iVar9 = 1;
    if ((int)pcVar13 < 0x18) {
                    /* WARNING: Subroutine does not return */
      FUN_10023e9c();
    }
    do {
      iVar18 = iVar9;
      iVar4 = iVar4 * 2;
      iVar9 = iVar18 + 1;
    } while ((char *)(iVar4 + 0x14) <= pcVar13);
    *(int *)(pcVar17 + 4) = iVar18;
    pcVar6 = (char *)FUN_100259c0(param_1);
    pcVar21 = pcVar6;
    if (pcVar6 == (char *)0x0) {
      pcVar21 = (char *)FUN_10023dc4();
    }
    **(undefined4 **)(param_1 + 0x1c) = pcVar21;
    local_8c = pcVar6;
    pcStack_70 = pcVar13;
    pcStack_58 = pcVar10;
    if (((char *)0xe < pcVar13) || (!bVar23)) {
      if ((-1 < local_2c[0]) && ((int)local_78 < 0xf)) {
        uVar14 = *(undefined4 *)(&DAT_1002b35c + local_78 * 8);
        uVar7 = *(undefined4 *)(&DAT_1002b358 + local_78 * 8);
        if (-1 < param_6) {
          FUN_10023bb2();
        }
        if (0 < (int)pcVar13) {
          FUN_10023bb2();
        }
        if (pcVar13 == (char *)0x0) {
          uVar25 = FUN_1001e9a6(uVar7,uVar14,0,0x40140000);
          iVar9 = FUN_1001ea48(param_3,local_84,(int)uVar25,(int)((ulonglong)uVar25 >> 0x20));
          if (iVar9 == 0) {
LAB_10023056:
            *pcVar6 = '1';
            FUN_10025a44(param_1,0);
            FUN_10025a44(param_1,pcVar11);
            pcVar6[1] = '\0';
            *param_7 = local_78 + 2;
            if (param_9 == (undefined4 *)0x0) {
              puVar5 = (undefined *)FUN_10022e06();
              return puVar5;
            }
            *param_9 = pcVar6 + 1;
            puVar5 = (undefined *)FUN_10022e06();
            return puVar5;
          }
        }
LAB_1002344e:
        FUN_10025a44(param_1,0);
        puVar5 = (undefined *)FUN_1002306c();
        return puVar5;
      }
      if (bVar2) {
        FUN_10023e32();
      }
      uVar19 = local_68;
      if (local_74 == (char *)0x0) {
        if (pcStack_6c == (char *)0x0) {
          local_80 = FUN_10025ccc(param_1,1);
          pcVar17 = (char *)0x0;
          if (local_68 != 0) goto code_r0x100235a6;
LAB_100234a4:
          pcVar10 = (char *)0x0;
          pcVar13 = (char *)(uVar19 + 1);
          goto LAB_1002311e;
        }
      }
      else if (pcStack_40 == (char *)0x0) {
        if (pcStack_6c == (char *)0x0) {
          local_80 = FUN_10025ccc(param_1,1);
          pcVar10 = (char *)0x0;
          pcVar17 = local_74;
          if (local_68 == 0) {
            pcVar13 = (char *)0x1;
            goto LAB_1002311e;
          }
code_r0x100235a6:
          pcVar10 = (char *)0x0;
          local_80 = FUN_10025ea8(param_1,local_80,local_68);
          local_68 = 0;
          if (1 < (int)param_5) goto LAB_100235be;
          goto LAB_10023b16;
        }
      }
      else {
        pcVar22 = local_74;
        if ((int)pcStack_40 < (int)local_74) {
          pcVar22 = pcStack_40;
        }
        pcVar17 = local_74 + -(int)pcVar22;
        pcStack_40 = pcStack_40 + -(int)pcVar22;
        local_74 = pcVar17;
        if (pcStack_6c == (char *)0x0) {
          local_80 = FUN_10025ccc(param_1,1);
          if (local_68 != 0) {
            FUN_10023df2();
            uVar19 = extraout_r3_02;
          }
          goto LAB_100234a4;
        }
      }
      pcVar11 = (char *)FUN_10025ea8(param_1,pcVar11,pcStack_6c);
      local_80 = FUN_10025ccc(param_1,1);
      pcStack_6c = (char *)0x0;
      if (local_68 != 0) {
        FUN_10023d9c();
        pcStack_6c = extraout_r3_01;
      }
      pcVar10 = (char *)0x0;
      pcVar13 = pcStack_6c + 1;
      pcVar17 = local_74;
      goto LAB_1002311e;
    }
    if ((int)local_78 < 1) {
      if (local_78 == 0) goto LAB_10023d58;
      iVar9 = (-local_78 & 0xf) * 8;
      uVar25 = FUN_1001e9a6(param_3,local_84,*(undefined4 *)(&DAT_1002b358 + iVar9),
                            *(undefined4 *)(&DAT_1002b35c + iVar9));
      uVar19 = (int)-local_78 >> 4;
      if (uVar19 != 0) {
        puVar8 = &DAT_1002b330;
        do {
          while( true ) {
            uStack_5c = (uint)((ulonglong)uVar25 >> 0x20);
            pcStack_60 = (char *)uVar25;
            uVar12 = uVar19 & 1;
            uVar19 = (int)uVar19 >> 1;
            if (uVar12 != 0) break;
            puVar8 = puVar8 + 2;
          }
          uVar7 = *puVar8;
          puVar24 = puVar8 + 1;
          puVar8 = puVar8 + 2;
          uVar25 = FUN_1001e9a6(pcStack_60,uStack_5c,uVar7,*puVar24);
        } while (uVar19 != 0);
        puVar5 = (undefined *)FUN_100233d4();
        return puVar5;
      }
      goto LAB_10023e94;
    }
    uVar19 = (int)local_78 >> 4;
    uVar26 = *(undefined8 *)(&DAT_1002b358 + (local_78 & 0xf) * 8);
    uVar25 = *(undefined8 *)(&DAT_1002b358 + (local_78 & 0xf) * 8);
    if ((int)(local_78 << 0x17) < 0) {
      uVar19 = uVar19 & 0xf;
      uVar28 = FUN_1001e96a(param_3,local_84,0x7f73bf3c,0x75154fdd);
      uStack_5c = (uint)((ulonglong)uVar28 >> 0x20);
      pcStack_60 = (char *)uVar28;
      pcVar17 = (char *)0x3;
    }
    else {
      uStack_5c = local_84;
      pcVar17 = (char *)0x2;
      pcStack_60 = (char *)param_3;
    }
    if (uVar19 != 0) {
      puVar8 = &DAT_1002b330;
      uVar25 = uVar26;
      do {
        while( true ) {
          uVar12 = uVar19 & 1;
          uVar19 = (int)uVar19 >> 1;
          if (uVar12 != 0) break;
          puVar8 = puVar8 + 2;
        }
        uVar7 = *puVar8;
        puVar24 = puVar8 + 1;
        puVar8 = puVar8 + 2;
        pcVar17 = pcVar17 + 1;
        uVar25 = FUN_1001e9a6((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),uVar7,*puVar24);
      } while (uVar19 != 0);
    }
    uVar25 = FUN_1001e96a(pcStack_60,uStack_5c,(int)uVar25,(int)((ulonglong)uVar25 >> 0x20));
    uVar14 = (undefined4)((ulonglong)uVar25 >> 0x20);
    uVar7 = (undefined4)uVar25;
    if ((!bVar1) || (iVar9 = FUN_1001ea3c(uVar7,uVar14,0,0x3ff00000), iVar9 == 0)) {
      uVar26 = FUN_1001ea84(pcVar17);
      uVar26 = FUN_1001e9a6((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),uVar7,uVar14);
      uVar26 = FUN_1001e958((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),0,0x401c0000);
      iVar9 = (int)((ulonglong)uVar26 >> 0x20);
      uVar20 = (undefined4)uVar26;
      iVar4 = iVar9 + -0x3400000;
      uStack_44 = local_78;
      pcStack_54 = pcVar13;
      if (pcVar13 == (char *)0x0) {
        uVar25 = FUN_1001e946(uVar7,uVar14,0,0x40140000);
        uVar7 = (undefined4)((ulonglong)uVar25 >> 0x20);
        iVar4 = FUN_1001ea58((int)uVar25,uVar7,uVar20,iVar4);
        if (iVar4 != 0) goto LAB_10023056;
        iVar9 = FUN_1001ea3c((int)uVar25,uVar7,uVar20,iVar9 + 0x7cc00000);
        if (iVar9 == 0) {
          puVar5 = (undefined *)FUN_10022ff6();
          return puVar5;
        }
        goto LAB_1002344e;
      }
    }
    else {
      if (pcVar13 == (char *)0x0) {
        uVar25 = FUN_1001ea84(pcVar17);
        uVar25 = FUN_1001e9a6((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),uVar7,uVar14);
        FUN_1001e958((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),0,0x401c0000);
        pcVar22 = (char *)(extraout_r1 + -0x3400000);
        FUN_1002341a();
        pcVar10 = (char *)0x0;
        uVar27 = FUN_100235a6();
        pcVar21 = local_74;
        local_80 = param_3;
        goto LAB_10023dfa;
      }
      if ((int)pcVar10 < 1) {
        FUN_10022ff6();
      }
      uStack_44 = local_78 - 1;
      uVar25 = FUN_1001e9a6(uVar7,uVar14,0,0x40240000);
      uVar26 = FUN_1001ea84(pcVar17 + 1);
      uVar26 = FUN_1001e9a6((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),(int)uVar25,
                            (int)((ulonglong)uVar25 >> 0x20));
      uVar26 = FUN_1001e958((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),0,0x401c0000);
      uVar20 = (undefined4)uVar26;
      iVar4 = (int)((ulonglong)uVar26 >> 0x20) + -0x3400000;
      pcStack_54 = pcVar10;
    }
    uStack_5c = (uint)((ulonglong)uVar25 >> 0x20);
    pcStack_60 = (char *)uVar25;
    uVar7 = *(undefined4 *)(&DAT_1002b35c + (int)(pcStack_54 + -1) * 8);
    pcVar17 = *(char **)(&DAT_1002b358 + (int)(pcStack_54 + -1) * 8);
    cVar3 = FUN_1001eab4(pcStack_60,uStack_5c);
    uVar25 = FUN_1001ea84();
    uVar25 = FUN_1001e946(pcStack_60,uStack_5c,(int)uVar25,(int)((ulonglong)uVar25 >> 0x20));
    pcStack_60 = pcVar6 + 1;
    pcVar22 = pcStack_60;
    if (bVar2) {
      uVar26 = FUN_1001e96a(0,0x3fe00000,pcVar17,uVar7);
      uVar26 = FUN_1001e946((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),uVar20,iVar4);
      *pcVar6 = cVar3 + '0';
      iVar9 = FUN_1001ea58((int)uVar26,(int)((ulonglong)uVar26 >> 0x20),(int)uVar25,
                           (int)((ulonglong)uVar25 >> 0x20));
      if (iVar9 == 0) {
        iVar9 = 0;
        do {
          uVar7 = (undefined4)((ulonglong)uVar26 >> 0x20);
          pcVar15 = (char *)((ulonglong)uVar25 >> 0x20);
          uVar28 = FUN_1001e946(0,0x3ff00000,(int)uVar25,pcVar15);
          iVar4 = FUN_1001ea3c((int)uVar28,(int)((ulonglong)uVar28 >> 0x20),(int)uVar26,uVar7);
          if (iVar4 != 0) {
            pcStack_40 = pcVar22;
            goto LAB_100239ec;
          }
          iVar9 = iVar9 + 1;
          pcStack_60 = pcVar11;
          if ((int)pcStack_54 <= iVar9) goto LAB_10023e1a;
          uVar26 = FUN_1001e9a6((int)uVar26,uVar7,0,0x40240000);
          uVar25 = FUN_1001e9a6((int)uVar25,pcVar15,0,0x40240000);
          cVar3 = FUN_1001eab4();
          uVar28 = FUN_1001ea84();
          uVar25 = FUN_1001e946((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),(int)uVar28,
                                (int)((ulonglong)uVar28 >> 0x20));
          pcVar6[iVar9] = cVar3 + '0';
          pcVar22 = pcVar22 + 1;
          iVar4 = FUN_1001ea3c((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),(int)uVar26,
                               (int)((ulonglong)uVar26 >> 0x20));
          pcVar17 = pcStack_40;
        } while (iVar4 == 0);
      }
      pcStack_40 = pcVar17;
      local_78 = uStack_44 + 1;
      FUN_1002306c();
LAB_10023e1a:
      if ((-1 < local_2c[0]) && ((int)local_78 < 0xf)) {
        FUN_1002300a();
      }
      pcVar15 = pcStack_6c;
      if ((int)pcVar10 <= (int)pcStack_6c) goto LAB_10023a14;
      FUN_10025ccc(param_1,1);
      if (local_74 == (char *)0x0) {
        FUN_100232a6();
      }
      pcVar11 = local_74;
      if ((int)(pcStack_40 + (int)pcVar13) < (int)local_74) {
        pcVar11 = pcStack_40 + (int)pcVar13;
      }
      pcVar17 = local_74 + -(int)pcVar11;
      FUN_100232a6();
LAB_10023e8c:
      FUN_100230e6();
LAB_10023e94:
      FUN_100233d4();
      pcVar17[4] = '\0';
      pcVar17[5] = '\0';
      pcVar17[6] = '\0';
      pcVar17[7] = '\0';
      FUN_10022fd4();
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0xef,0,"REENT malloc succeeded")
      ;
    }
    uVar26 = FUN_1001e9a6(pcVar17,uVar7,uVar20,iVar4);
    uVar7 = (undefined4)((ulonglong)uVar26 >> 0x20);
    *pcVar6 = cVar3 + '0';
    pcVar17 = pcStack_54 + (int)pcVar6;
    if (pcStack_54 != (char *)0x1) {
      pcVar17 = pcStack_60;
      do {
        uVar25 = FUN_1001e9a6((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),0,0x40240000);
        cVar3 = FUN_1001eab4();
        uVar28 = FUN_1001ea84();
        uVar25 = FUN_1001e946((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),(int)uVar28,
                              (int)((ulonglong)uVar28 >> 0x20));
        *pcVar17 = cVar3 + '0';
        pcVar17 = pcVar17 + 1;
      } while (pcStack_54 + (int)pcVar6 != pcVar17);
      pcVar22 = pcVar6 + (int)pcStack_54;
    }
    pcVar15 = (char *)((ulonglong)uVar25 >> 0x20);
    uVar14 = (undefined4)uVar25;
    uVar25 = FUN_1001e958((int)uVar26,uVar7,0,0x3fe00000);
    iVar9 = FUN_1001ea3c((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),uVar14,pcVar15);
    if (iVar9 != 0) goto LAB_100239ec;
    uVar25 = FUN_1001e946(0,0x3fe00000,(int)uVar26,uVar7);
    iVar9 = FUN_1001ea58((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),uVar14,pcVar15);
    if (iVar9 != 0) {
      do {
        pcVar22 = pcVar22 + -1;
      } while (*pcVar22 == '0');
      uVar26 = FUN_1002306c();
      uVar25 = CONCAT44((int)((ulonglong)uVar26 >> 0x20),uVar14);
      uVar7 = (undefined4)uVar26;
      pcStack_60 = pcVar11;
      goto LAB_10023d1e;
    }
    if ((local_2c[0] < 0) || (0xe < (int)local_78)) goto LAB_10023e8c;
    uVar19 = *(uint *)(&DAT_1002b35c + local_78 * 8);
    local_88 = *(uint *)(&DAT_1002b358 + local_78 * 8);
    FUN_1001e96a(param_3,local_84,local_88,uVar19);
    iVar9 = FUN_1001eab4();
    uVar25 = FUN_1001ea84();
    uVar25 = FUN_1001e9a6((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),local_88,uVar19);
    uVar25 = FUN_1001e946(param_3,local_84,(int)uVar25,(int)((ulonglong)uVar25 >> 0x20));
    *pcVar6 = (char)iVar9 + '0';
    local_84 = uVar19;
    if (pcVar13 != (char *)0x1) goto LAB_100234ee;
  }
  else {
    param_5 = 0;
LAB_1002323a:
    pcVar17[4] = '\0';
    pcVar17[5] = '\0';
    pcVar17[6] = '\0';
    pcVar17[7] = '\0';
    local_8c = (char *)FUN_100259c0(param_1,0);
    if (local_8c == (char *)0x0) {
      FUN_10023dc4();
    }
    **(undefined4 **)(param_1 + 0x1c) = local_8c;
    if ((local_2c[0] < 0) || (0xe < (int)local_78)) {
      pcVar15 = pcStack_6c;
      if (!bVar23) {
        pcStack_70 = (char *)0xffffffff;
        pcStack_58 = (char *)0xffffffff;
        pcVar11 = (char *)(0x36 - local_30);
        goto LAB_1002327e;
      }
      pcStack_70 = (char *)0xffffffff;
      pcStack_58 = (char *)0xffffffff;
      pcVar11 = (char *)(local_2c[0] + 0x433);
      goto LAB_1002327e;
    }
    local_88 = *(uint *)(&DAT_1002b358 + local_78 * 8);
    uVar19 = *(uint *)(&DAT_1002b35c + local_78 * 8);
    FUN_1001e96a(param_3,local_84,local_88,uVar19);
    cVar3 = FUN_1001eab4();
    uVar25 = FUN_1001ea84();
    uVar25 = FUN_1001e9a6((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),local_88,uVar19);
    uVar25 = FUN_1001e946(param_3,local_84,(int)uVar25,(int)((ulonglong)uVar25 >> 0x20));
    pcStack_60 = local_8c + 1;
    *local_8c = cVar3 + '0';
    pcStack_70 = (char *)0xffffffff;
    local_84 = uVar19;
LAB_100234ee:
    pcStack_40 = local_8c + -1;
    pcVar22 = (char *)0x1;
    do {
      uVar25 = FUN_1001e9a6((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),0,0x40240000);
      uVar14 = (undefined4)((ulonglong)uVar25 >> 0x20);
      uVar7 = (undefined4)uVar25;
      iVar9 = FUN_1001ea2c(uVar7,uVar14,0,0);
      if (iVar9 != 0) {
        puVar5 = (undefined *)FUN_1002306c();
        return puVar5;
      }
      FUN_1001e96a(uVar7,uVar14,local_88,local_84);
      iVar9 = FUN_1001eab4();
      uVar25 = FUN_1001ea84();
      uVar25 = FUN_1001e9a6((int)uVar25,(int)((ulonglong)uVar25 >> 0x20),local_88,local_84);
      uVar25 = FUN_1001e946(uVar7,uVar14,(int)uVar25,(int)((ulonglong)uVar25 >> 0x20));
      pcVar22 = pcVar22 + 1;
      pcStack_40[(int)pcVar22] = (char)iVar9 + '0';
      pcStack_60 = pcStack_60 + 1;
    } while (pcStack_70 != pcVar22);
  }
  uVar7 = (undefined4)((ulonglong)uVar25 >> 0x20);
  uVar25 = FUN_1001e958((int)uVar25,uVar7,(int)uVar25,uVar7);
  pcVar15 = (char *)((ulonglong)uVar25 >> 0x20);
  iVar4 = FUN_1001ea58((int)uVar25,pcVar15,local_88,local_84);
  if ((iVar4 == 0) &&
     ((iVar4 = FUN_1001ea2c((int)uVar25,pcVar15,local_88,local_84), iVar4 == 0 ||
      (-1 < iVar9 << 0x1f)))) {
    FUN_1002306c();
    puVar5 = (undefined *)FUN_100235a6();
    return puVar5;
  }
  pcVar6 = local_8c;
  pcVar22 = pcStack_60;
LAB_100239ec:
  do {
    pcVar22 = pcVar22 + -1;
    if (*pcVar22 != '9') {
      cVar3 = *pcVar22 + '\x01';
      pcVar10 = pcVar15;
      pcStack_60 = pcVar11;
      goto LAB_100239fa;
    }
  } while (pcVar22 != pcVar6);
LAB_10023d68:
  cVar3 = '1';
  pcVar10 = pcVar15;
  pcStack_60 = pcVar11;
LAB_100239fa:
  *pcVar22 = cVar3;
  FUN_1002306c();
  *local_8c = '1';
  FUN_1002320c();
  pcVar15 = extraout_r3_03;
LAB_10023a14:
  pcVar15 = pcVar15 + -(int)pcVar10;
  pcVar11 = pcStack_70;
  if ((int)pcStack_70 < 0) {
    uVar25 = FUN_10025ccc(param_1,1);
    pcVar22 = local_74;
    local_74 = local_74 + -(int)pcStack_70;
  }
  else {
LAB_1002327e:
    pcVar22 = local_74 + (int)pcVar11;
    pcStack_40 = pcStack_40 + (int)pcVar11;
    uVar25 = FUN_10025ccc(param_1,1);
    pcVar10 = (char *)uVar25;
    if (local_74 == (char *)0x0) {
      if (pcStack_6c != (char *)0x0) {
        if (pcVar15 != (char *)0x0) {
          FUN_10023c1c();
        }
        pcVar11 = (char *)FUN_10025ea8(param_1,pcStack_60,pcStack_6c);
        local_80 = FUN_10025ccc(param_1,1);
        if (local_68 != 0) {
          FUN_10023bac();
        }
        pcVar17 = (char *)0x0;
        if (((((int)param_5 < 2) && (local_88 == 0)) && ((local_84 & 0xfffff) == 0)) &&
           ((local_84 & 0x7ff00000) != 0)) {
          local_74 = pcVar22 + 1;
          pcVar13 = (char *)0x1;
          pcStack_6c = (char *)0x1;
          pcStack_40 = pcStack_40 + 1;
          local_68 = 1;
        }
        else {
          pcVar13 = (char *)0x1;
          pcStack_6c = (char *)0x1;
          local_74 = pcVar22;
        }
LAB_1002311e:
        do {
          uVar19 = (uint)(pcVar13 + (int)pcStack_40) & 0x1f;
          if (((uint)(pcVar13 + (int)pcStack_40) & 0x1f) == 0) {
            iVar9 = 0x1c;
LAB_1002313a:
            pcVar17 = pcVar17 + iVar9;
            local_74 = local_74 + iVar9;
            pcStack_40 = pcStack_40 + iVar9;
          }
          else {
            if (4 < (int)(0x20 - uVar19)) {
              iVar9 = 0x1c - uVar19;
              goto LAB_1002313a;
            }
            if (0x20 - uVar19 != 4) {
              iVar9 = 0x3c - uVar19;
              goto LAB_1002313a;
            }
          }
          pcVar21 = pcVar11;
          if (0 < (int)local_74) {
            pcVar21 = (char *)FUN_10025fb4(param_1,pcVar11,local_74);
          }
          if (0 < (int)pcStack_40) {
            local_80 = FUN_10025fb4(param_1,local_80,pcStack_40);
          }
          if ((!bVar1) || (iVar9 = FUN_100260a8(pcVar21,local_80), -1 < iVar9)) {
            if ((0 < (int)pcStack_70) || ((int)param_5 < 3)) goto LAB_1002317c;
          }
          else {
            pcVar21 = (char *)FUN_10025a90(param_1,pcVar21,10,0);
            if (pcStack_6c == (char *)0x0) {
              pcStack_70 = pcStack_58;
              if ((0 < (int)pcStack_58) || ((int)param_5 < 3)) goto LAB_1002318a;
            }
            else {
              pcVar10 = (char *)FUN_10025a90(param_1,pcVar10,10,0);
              pcStack_70 = pcStack_58;
              if ((0 < (int)pcStack_58) || ((int)param_5 < 3)) goto LAB_1002366c;
            }
          }
          if (pcStack_70 == (char *)0x0) {
            local_80 = FUN_10025a90(param_1,local_80,5);
            iVar9 = FUN_100260a8(pcVar21,local_80);
            if (0 < iVar9) {
              *local_8c = '1';
              FUN_10025a44(param_1,local_80);
              if (pcVar10 == (char *)0x0) {
                puVar5 = (undefined *)FUN_1002306c();
                return puVar5;
              }
              puVar5 = (undefined *)FUN_1002322c();
              return puVar5;
            }
          }
          FUN_10025a44(param_1,local_80);
          if (pcVar10 != (char *)0x0) {
            FUN_1002322c();
          }
          FUN_1002306c();
          pcVar17 = local_8c;
          pcVar11 = pcVar21;
LAB_10023b16:
          if (((local_88 == 0) && ((local_84 & 0xfffff) == 0)) && ((local_84 & 0x7ff00000) != 0)) {
            local_74 = local_74 + 1;
            local_68 = 1;
            pcStack_40 = pcStack_40 + 1;
          }
LAB_100235be:
          iVar9 = FUN_10025bdc(*(undefined4 *)(*(int *)(local_80 + 0x10) * 4 + local_80 + 0x10));
          pcVar13 = (char *)(0x20 - iVar9);
        } while( true );
      }
      goto LAB_10023a42;
    }
  }
  uVar7 = (undefined4)uVar25;
  if ((int)pcStack_40 < 1) {
    if (pcStack_6c != (char *)0x0) {
      puVar5 = (undefined *)FUN_1002329e();
      return puVar5;
    }
LAB_10023a42:
    puVar5 = (undefined *)FUN_100232b4();
    return puVar5;
  }
LAB_10023d1e:
  pcVar10 = (char *)uVar25;
  pcVar11 = local_74;
  if ((int)pcStack_40 < (int)local_74) {
    pcVar11 = pcStack_40;
  }
  pcVar17 = pcVar22 + -(int)pcVar11;
  pcVar21 = local_74 + -(int)pcVar11;
  if (pcStack_6c != (char *)0x0) {
    FUN_1002329e(uVar7,(int)((ulonglong)uVar25 >> 0x20),pcStack_40);
  }
  FUN_100232b4();
  pcVar22 = pcStack_60;
  local_74 = pcVar17;
  goto LAB_10023d44;
LAB_1002317c:
  if (pcStack_6c == (char *)0x0) {
LAB_1002318a:
    iVar9 = 1;
    while( true ) {
      iVar4 = FUN_10022c2c(pcVar21,local_80);
      local_8c[iVar9 + -1] = (char)iVar4 + '0';
      if ((int)pcStack_70 <= iVar9) break;
      pcVar21 = (char *)FUN_10025a90(param_1,pcVar21,10,0);
      iVar9 = iVar9 + 1;
    }
    pcVar11 = (char *)0x0;
    if (0 < (int)pcStack_70) {
      pcVar11 = pcStack_70 + -1;
    }
    pcVar11 = pcVar11 + (int)(local_8c + 1);
    uVar7 = FUN_10025fb4(param_1,pcVar21,1,0);
    uVar25 = FUN_100260a8(uVar7,local_80);
    iVar9 = (int)uVar25;
    if ((0 < iVar9) || ((iVar9 == 0 && (iVar4 << 0x1f < 0)))) {
      puVar5 = (undefined *)FUN_100231fe(iVar9,(int)((ulonglong)uVar25 >> 0x20),local_8c);
      return puVar5;
    }
    do {
      pcVar11 = pcVar11 + -1;
    } while (*pcVar11 == '0');
    puVar5 = (undefined *)FUN_1002320c();
    return puVar5;
  }
LAB_1002366c:
  if (0 < (int)pcVar17) {
    pcVar10 = (char *)FUN_10025fb4(param_1,pcVar10,pcVar17);
  }
  pcVar17 = pcVar10;
  if (local_68 != 0) {
    iVar9 = FUN_100259c0(param_1,*(undefined4 *)(pcVar10 + 4));
    if (iVar9 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded");
    }
    FUN_1001f4d4(iVar9 + 0xc,pcVar10 + 0xc,(*(int *)(pcVar10 + 0x10) + 2) * 4);
    pcVar17 = (char *)FUN_10025fb4(param_1,iVar9,1);
  }
  pcStack_70 = pcStack_70 + (int)(local_8c + -1);
  local_68 = local_88 & 1;
  pcStack_40 = local_8c;
LAB_100236a2:
  pcStack_6c = (char *)FUN_10022c2c(pcVar21,local_80);
  pcVar22 = pcStack_6c + 0x30;
  iVar9 = FUN_100260a8(pcVar21,pcVar10);
  iVar4 = FUN_100260e4(param_1,local_80,pcVar17);
  pcVar13 = pcVar10;
  pcVar11 = pcVar21;
  if (*(int *)(iVar4 + 0xc) != 0) {
    uVar27 = FUN_10025a44(param_1,iVar4);
    if (iVar9 < 0) goto LAB_10023762;
    if ((local_88 & 1) == 0 && (iVar9 == 0 && param_5 == 0)) goto LAB_10023762;
LAB_100237c2:
    pcVar10 = pcVar17;
    if (pcVar22 != (char *)0x39) {
      *pcStack_40 = (char)pcStack_6c + '1';
      puVar5 = (undefined *)FUN_1002320c();
      return puVar5;
    }
    goto LAB_10023d72;
  }
  local_74 = (char *)FUN_100260a8(pcVar21,iVar4);
  uVar27 = FUN_10025a44(param_1,iVar4);
  if (local_74 == (char *)0x0 && param_5 == 0) {
    if (local_68 == 0) {
      pcVar10 = pcVar17;
      if (pcVar22 == (char *)0x39) goto LAB_10023d72;
      if (0 < iVar9) goto LAB_10023780;
      goto LAB_10023784;
    }
    if (iVar9 < 0) goto LAB_10023784;
  }
  else {
    if (iVar9 < 0) goto LAB_10023d8c;
    if ((iVar9 == 0 && param_5 == 0) && local_68 == 0) goto LAB_10023d8c;
    if (0 < (int)local_74) goto LAB_100237c2;
  }
  pcVar15 = pcStack_40 + 1;
  *pcStack_40 = (char)pcVar22;
  if (pcStack_40 != pcStack_70) {
    pcVar21 = (char *)FUN_10025a90(param_1,pcVar21,10,0);
    pcStack_40 = pcVar15;
    if (pcVar10 == pcVar17) {
      pcVar10 = (char *)FUN_10025a90(param_1,pcVar10,10,0);
      pcVar17 = pcVar10;
    }
    else {
      pcVar10 = (char *)FUN_10025a90(param_1,pcVar10,10,0);
      pcVar17 = (char *)FUN_10025a90(param_1,pcVar17,10,0);
    }
    goto LAB_100236a2;
  }
LAB_10023d44:
  FUN_100231da();
  pcVar13 = pcVar15;
  pcVar11 = pcVar21;
  pcStack_40 = pcVar10;
LAB_10023d58:
  FUN_100233d4();
  pcVar15 = pcVar13;
  goto LAB_10023d68;
LAB_10023d72:
  *pcStack_40 = '9';
  FUN_100231fe((int)uVar27,(int)(uVar27 >> 0x20),local_8c);
  pcVar17 = pcVar22;
  pcVar22 = pcVar11;
  pcStack_40 = pcVar13;
LAB_10023d8c:
  if ((int)local_74 < 1) goto LAB_10023784;
LAB_10023762:
  pcVar11 = (char *)FUN_10025fb4(param_1,pcVar21,1);
  uVar27 = FUN_100260a8(pcVar11,local_80);
  if ((int)uVar27 < 1) {
LAB_10023dfa:
    if (((int)uVar27 != 0) || (-1 < (int)pcVar22 << 0x1f)) goto LAB_10023784;
    uVar27 = uVar27 & 0xffffffff00000000;
  }
  if (pcVar22 != (char *)0x39) {
LAB_10023780:
    pcVar22 = pcStack_6c + 0x31;
LAB_10023784:
    *pcStack_40 = (char)pcVar22;
    puVar5 = (undefined *)FUN_1002320c();
    return puVar5;
  }
  pcVar22 = (char *)0x39;
  pcVar13 = pcVar10;
  pcVar10 = pcVar17;
  goto LAB_10023d72;
}



/* FUN_10022e06 at 10022e06 */

undefined4 FUN_10022e06(void)

{
  undefined4 in_stack_0000000c;
  
  return in_stack_0000000c;
}



/* FUN_10022f0a at 10022f0a */

void FUN_10022f0a(void)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  uint uVar10;
  int extraout_r1;
  int iVar11;
  uint extraout_r3;
  uint extraout_r3_00;
  char *extraout_r3_01;
  uint extraout_r3_02;
  char *pcVar12;
  char *extraout_r3_03;
  undefined4 uVar13;
  char *pcVar14;
  undefined4 *puVar15;
  char *pcVar16;
  undefined4 uVar17;
  char *unaff_r7;
  char *pcVar18;
  int unaff_r8;
  int unaff_r9;
  char *unaff_r10;
  char *unaff_r11;
  undefined4 *puVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  char *pcStack0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  uint in_stack_00000020;
  char *in_stack_00000024;
  char *pcStack00000028;
  char *pcStack0000002c;
  uint in_stack_00000030;
  int in_stack_00000034;
  undefined4 uStack0000003c;
  char *in_stack_00000040;
  char *pcStack00000044;
  uint uStack00000054;
  int in_stack_00000068;
  int in_stack_0000006c;
  uint in_stack_00000098;
  int in_stack_0000009c;
  int *in_stack_000000a0;
  undefined4 *in_stack_000000a8;
  
  pcStack0000002c = (char *)0x0;
  pcVar16 = *(char **)(unaff_r9 + 0x1c);
  if (in_stack_00000098 < 10) {
    if ((int)in_stack_00000098 < 6) {
      uVar10 = in_stack_00000098;
      if (in_stack_00000098 == 4) {
        FUN_10023a86();
        uVar10 = extraout_r3_00;
      }
      if (uVar10 == 5) {
        bVar2 = true;
        goto LAB_10022f9e;
      }
      if (uVar10 == 2) {
        while( true ) {
          if (0 < in_stack_0000009c) {
            FUN_10022fb8();
          }
          pcVar16[4] = '\0';
          pcVar16[5] = '\0';
          pcVar16[6] = '\0';
          pcVar16[7] = '\0';
          iVar7 = FUN_100259c0();
          if (iVar7 == 0) break;
          **(int **)(unaff_r9 + 0x1c) = iVar7;
          in_stack_0000009c = 1;
          FUN_10022ff0();
        }
        FUN_10023dc4();
        return;
      }
      if (uVar10 == 3) {
        bVar2 = true;
        bVar3 = false;
        goto LAB_10022fa2;
      }
      goto LAB_1002323a;
    }
    in_stack_00000098 = in_stack_00000098 - 4;
    bVar2 = false;
    uVar10 = in_stack_00000098;
    if (in_stack_00000098 == 4) {
      FUN_10023a88();
      uVar10 = extraout_r3;
    }
    if (uVar10 == 5) {
LAB_10022f9e:
      bVar3 = true;
    }
    else {
      if (uVar10 == 2) {
        FUN_10023a48();
      }
      in_stack_00000098 = 3;
      bVar3 = false;
    }
LAB_10022fa2:
    pcVar8 = (char *)(in_stack_0000009c + in_stack_00000020);
    pcVar12 = pcVar8 + 1;
    if ((int)pcVar12 < 1) {
                    /* WARNING: Subroutine does not return */
      FUN_10023e9c();
    }
    iVar9 = 4;
    iVar7 = 1;
    if ((int)pcVar12 < 0x18) {
                    /* WARNING: Subroutine does not return */
      FUN_10023e9c();
    }
    do {
      iVar11 = iVar7;
      iVar9 = iVar9 * 2;
      iVar7 = iVar11 + 1;
    } while ((char *)(iVar9 + 0x14) <= pcVar12);
    *(int *)(pcVar16 + 4) = iVar11;
    pcVar5 = (char *)FUN_100259c0();
    pcVar18 = pcVar5;
    if (pcVar5 == (char *)0x0) {
      pcVar18 = (char *)FUN_10023dc4();
    }
    **(undefined4 **)(unaff_r9 + 0x1c) = pcVar18;
    pcStack0000000c = pcVar5;
    pcStack00000028 = pcVar12;
    in_stack_00000040 = pcVar8;
    if (((char *)0xe < pcVar12) || (!bVar2)) {
      if ((-1 < in_stack_0000006c) && ((int)in_stack_00000020 < 0xf)) {
        uVar13 = *(undefined4 *)(&DAT_1002b35c + in_stack_00000020 * 8);
        uVar6 = *(undefined4 *)(&DAT_1002b358 + in_stack_00000020 * 8);
        if (-1 < in_stack_0000009c) {
          FUN_10023bb2();
        }
        if (0 < (int)pcVar12) {
          FUN_10023bb2();
        }
        if (pcVar12 == (char *)0x0) {
          uVar20 = FUN_1001e9a6(uVar6,uVar13,0,0x40140000);
          iVar7 = FUN_1001ea48(in_stack_00000018,in_stack_0000001c,(int)uVar20,
                               (int)((ulonglong)uVar20 >> 0x20));
          if (iVar7 == 0) {
LAB_10023056:
            *pcVar5 = '1';
            FUN_10025a44();
            FUN_10025a44();
            pcVar5[1] = '\0';
            *in_stack_000000a0 = in_stack_00000020 + 2;
            if (in_stack_000000a8 == (undefined4 *)0x0) {
              FUN_10022e06();
              return;
            }
            *in_stack_000000a8 = pcVar5 + 1;
            FUN_10022e06();
            return;
          }
        }
LAB_1002344e:
        FUN_10025a44();
        FUN_1002306c();
        return;
      }
      if (bVar3) {
        FUN_10023e32();
      }
      uVar10 = in_stack_00000030;
      if (in_stack_00000024 == (char *)0x0) {
        if (pcStack0000002c == (char *)0x0) {
          in_stack_00000018 = FUN_10025ccc();
          pcVar16 = (char *)0x0;
          if (in_stack_00000030 != 0) goto code_r0x100235a6;
LAB_100234a4:
          pcVar8 = (char *)0x0;
          pcVar12 = (char *)(uVar10 + 1);
          goto LAB_1002311e;
        }
      }
      else if (unaff_r11 == (char *)0x0) {
        if (pcStack0000002c == (char *)0x0) {
          in_stack_00000018 = FUN_10025ccc();
          pcVar8 = (char *)0x0;
          pcVar16 = in_stack_00000024;
          if (in_stack_00000030 == 0) {
            pcVar12 = (char *)0x1;
            goto LAB_1002311e;
          }
code_r0x100235a6:
          pcVar8 = (char *)0x0;
          in_stack_00000018 = FUN_10025ea8();
          in_stack_00000030 = 0;
          if (1 < (int)in_stack_00000098) goto LAB_100235be;
          goto LAB_10023b16;
        }
      }
      else {
        pcVar12 = in_stack_00000024;
        if ((int)unaff_r11 < (int)in_stack_00000024) {
          pcVar12 = unaff_r11;
        }
        pcVar16 = in_stack_00000024 + -(int)pcVar12;
        unaff_r11 = unaff_r11 + -(int)pcVar12;
        in_stack_00000024 = pcVar16;
        if (pcStack0000002c == (char *)0x0) {
          in_stack_00000018 = FUN_10025ccc();
          if (in_stack_00000030 != 0) {
            FUN_10023df2();
            uVar10 = extraout_r3_02;
          }
          goto LAB_100234a4;
        }
      }
      unaff_r10 = (char *)FUN_10025ea8();
      in_stack_00000018 = FUN_10025ccc();
      pcVar18 = (char *)0x0;
      if (in_stack_00000030 != 0) {
        FUN_10023d9c();
        pcVar18 = extraout_r3_01;
      }
      pcVar8 = (char *)0x0;
      pcVar12 = pcVar18 + 1;
      pcVar16 = in_stack_00000024;
      pcStack0000002c = pcVar18;
      goto LAB_1002311e;
    }
    if ((int)in_stack_00000020 < 1) {
      if (in_stack_00000020 == 0) goto LAB_10023d58;
      iVar7 = (-in_stack_00000020 & 0xf) * 8;
      uVar20 = FUN_1001e9a6(in_stack_00000018,in_stack_0000001c,
                            *(undefined4 *)(&DAT_1002b358 + iVar7),
                            *(undefined4 *)(&DAT_1002b35c + iVar7));
      uVar10 = (int)-in_stack_00000020 >> 4;
      if (uVar10 != 0) {
        puVar15 = &DAT_1002b330;
        do {
          while( true ) {
            uStack0000003c = (undefined4)((ulonglong)uVar20 >> 0x20);
            uVar1 = uVar10 & 1;
            uVar10 = (int)uVar10 >> 1;
            if (uVar1 != 0) break;
            puVar15 = puVar15 + 2;
          }
          uVar6 = *puVar15;
          puVar19 = puVar15 + 1;
          puVar15 = puVar15 + 2;
          uVar20 = FUN_1001e9a6((int)uVar20,uStack0000003c,uVar6,*puVar19);
        } while (uVar10 != 0);
        FUN_100233d4();
        return;
      }
      goto LAB_10023e94;
    }
    uVar10 = (int)in_stack_00000020 >> 4;
    uVar22 = *(undefined8 *)(&DAT_1002b358 + (in_stack_00000020 & 0xf) * 8);
    uVar20 = *(undefined8 *)(&DAT_1002b358 + (in_stack_00000020 & 0xf) * 8);
    if ((int)(in_stack_00000020 << 0x17) < 0) {
      uVar10 = uVar10 & 0xf;
      uVar23 = FUN_1001e96a(in_stack_00000018,in_stack_0000001c,0x7f73bf3c,0x75154fdd);
      uStack0000003c = (undefined4)((ulonglong)uVar23 >> 0x20);
      iVar7 = (int)uVar23;
      pcVar16 = (char *)0x3;
    }
    else {
      uStack0000003c = in_stack_0000001c;
      pcVar16 = (char *)0x2;
      iVar7 = in_stack_00000018;
    }
    if (uVar10 != 0) {
      puVar15 = &DAT_1002b330;
      uVar20 = uVar22;
      do {
        while( true ) {
          uVar1 = uVar10 & 1;
          uVar10 = (int)uVar10 >> 1;
          if (uVar1 != 0) break;
          puVar15 = puVar15 + 2;
        }
        uVar6 = *puVar15;
        puVar19 = puVar15 + 1;
        puVar15 = puVar15 + 2;
        pcVar16 = pcVar16 + 1;
        uVar20 = FUN_1001e9a6((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),uVar6,*puVar19);
      } while (uVar10 != 0);
    }
    uVar20 = FUN_1001e96a(iVar7,uStack0000003c,(int)uVar20,(int)((ulonglong)uVar20 >> 0x20));
    uVar13 = (undefined4)((ulonglong)uVar20 >> 0x20);
    uVar6 = (undefined4)uVar20;
    if ((in_stack_00000034 == 0) || (iVar7 = FUN_1001ea3c(uVar6,uVar13,0,0x3ff00000), iVar7 == 0)) {
      uVar22 = FUN_1001ea84(pcVar16);
      uVar22 = FUN_1001e9a6((int)uVar22,(int)((ulonglong)uVar22 >> 0x20),uVar6,uVar13);
      uVar22 = FUN_1001e958((int)uVar22,(int)((ulonglong)uVar22 >> 0x20),0,0x401c0000);
      iVar7 = (int)((ulonglong)uVar22 >> 0x20);
      uVar17 = (undefined4)uVar22;
      iVar9 = iVar7 + -0x3400000;
      uStack00000054 = in_stack_00000020;
      pcStack00000044 = pcVar12;
      if (pcVar12 == (char *)0x0) {
        uVar20 = FUN_1001e946(uVar6,uVar13,0,0x40140000);
        uVar6 = (undefined4)((ulonglong)uVar20 >> 0x20);
        iVar9 = FUN_1001ea58((int)uVar20,uVar6,uVar17,iVar9);
        if (iVar9 != 0) goto LAB_10023056;
        iVar7 = FUN_1001ea3c((int)uVar20,uVar6,uVar17,iVar7 + 0x7cc00000);
        if (iVar7 == 0) {
          FUN_10022ff6();
          return;
        }
        goto LAB_1002344e;
      }
    }
    else {
      if (pcVar12 == (char *)0x0) {
        uVar20 = FUN_1001ea84(pcVar16);
        uVar20 = FUN_1001e9a6((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),uVar6,uVar13);
        FUN_1001e958((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),0,0x401c0000);
        unaff_r7 = (char *)(extraout_r1 + -0x3400000);
        FUN_1002341a();
        pcVar8 = (char *)0x0;
        uVar21 = FUN_100235a6();
        goto LAB_10023dfa;
      }
      if ((int)pcVar8 < 1) {
        FUN_10022ff6();
      }
      uStack00000054 = in_stack_00000020 - 1;
      uVar20 = FUN_1001e9a6(uVar6,uVar13,0,0x40240000);
      uVar22 = FUN_1001ea84(pcVar16 + 1);
      uVar22 = FUN_1001e9a6((int)uVar22,(int)((ulonglong)uVar22 >> 0x20),(int)uVar20,
                            (int)((ulonglong)uVar20 >> 0x20));
      uVar22 = FUN_1001e958((int)uVar22,(int)((ulonglong)uVar22 >> 0x20),0,0x401c0000);
      uVar17 = (undefined4)uVar22;
      iVar9 = (int)((ulonglong)uVar22 >> 0x20) + -0x3400000;
      pcStack00000044 = pcVar8;
    }
    uStack0000003c = (undefined4)((ulonglong)uVar20 >> 0x20);
    uVar6 = *(undefined4 *)(&DAT_1002b35c + (int)(pcStack00000044 + -1) * 8);
    pcVar16 = *(char **)(&DAT_1002b358 + (int)(pcStack00000044 + -1) * 8);
    cVar4 = FUN_1001eab4((int)uVar20,uStack0000003c);
    uVar22 = FUN_1001ea84();
    uVar20 = FUN_1001e946((int)uVar20,uStack0000003c,(int)uVar22,(int)((ulonglong)uVar22 >> 0x20));
    pcVar18 = pcVar5 + 1;
    unaff_r7 = pcVar18;
    if (bVar3) {
      uVar22 = FUN_1001e96a(0,0x3fe00000,pcVar16,uVar6);
      uVar22 = FUN_1001e946((int)uVar22,(int)((ulonglong)uVar22 >> 0x20),uVar17,iVar9);
      *pcVar5 = cVar4 + '0';
      iVar7 = FUN_1001ea58((int)uVar22,(int)((ulonglong)uVar22 >> 0x20),(int)uVar20,
                           (int)((ulonglong)uVar20 >> 0x20));
      if (iVar7 == 0) {
        iVar7 = 0;
        do {
          uVar6 = (undefined4)((ulonglong)uVar22 >> 0x20);
          pcVar14 = (char *)((ulonglong)uVar20 >> 0x20);
          uVar23 = FUN_1001e946(0,0x3ff00000,(int)uVar20,pcVar14);
          iVar9 = FUN_1001ea3c((int)uVar23,(int)((ulonglong)uVar23 >> 0x20),(int)uVar22,uVar6);
          if (iVar9 != 0) {
            unaff_r11 = unaff_r7;
            goto LAB_100239ec;
          }
          iVar7 = iVar7 + 1;
          if ((int)pcStack00000044 <= iVar7) goto LAB_10023e1a;
          uVar22 = FUN_1001e9a6((int)uVar22,uVar6,0,0x40240000);
          uVar20 = FUN_1001e9a6((int)uVar20,pcVar14,0,0x40240000);
          cVar4 = FUN_1001eab4();
          uVar23 = FUN_1001ea84();
          uVar20 = FUN_1001e946((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar23,
                                (int)((ulonglong)uVar23 >> 0x20));
          pcVar5[iVar7] = cVar4 + '0';
          unaff_r7 = unaff_r7 + 1;
          iVar9 = FUN_1001ea3c((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar22,
                               (int)((ulonglong)uVar22 >> 0x20));
          pcVar18 = unaff_r10;
          pcVar16 = unaff_r11;
        } while (iVar9 == 0);
      }
      in_stack_00000020 = uStack00000054 + 1;
      FUN_1002306c();
      unaff_r10 = pcVar18;
      unaff_r11 = pcVar16;
LAB_10023e1a:
      if ((-1 < in_stack_0000006c) && ((int)in_stack_00000020 < 0xf)) {
        FUN_1002300a();
      }
      pcVar14 = pcStack0000002c;
      if ((int)pcVar8 <= (int)pcStack0000002c) goto LAB_10023a14;
      FUN_10025ccc();
      if (in_stack_00000024 == (char *)0x0) {
        pcStack0000002c = pcVar8;
        FUN_100232a6();
      }
      pcVar16 = in_stack_00000024;
      if ((int)(unaff_r11 + (int)pcVar12) < (int)in_stack_00000024) {
        pcVar16 = unaff_r11 + (int)pcVar12;
      }
      pcVar16 = in_stack_00000024 + -(int)pcVar16;
      pcStack0000002c = pcVar8;
      FUN_100232a6();
LAB_10023e8c:
      FUN_100230e6();
LAB_10023e94:
      FUN_100233d4();
      pcVar16[4] = '\0';
      pcVar16[5] = '\0';
      pcVar16[6] = '\0';
      pcVar16[7] = '\0';
      FUN_10022fd4();
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0xef,0,"REENT malloc succeeded")
      ;
    }
    uVar22 = FUN_1001e9a6(pcVar16,uVar6,uVar17,iVar9);
    uVar6 = (undefined4)((ulonglong)uVar22 >> 0x20);
    *pcVar5 = cVar4 + '0';
    pcVar16 = pcStack00000044 + (int)pcVar5;
    if (pcStack00000044 != (char *)0x1) {
      pcVar16 = pcVar18;
      do {
        uVar20 = FUN_1001e9a6((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),0,0x40240000);
        cVar4 = FUN_1001eab4();
        uVar23 = FUN_1001ea84();
        uVar20 = FUN_1001e946((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),(int)uVar23,
                              (int)((ulonglong)uVar23 >> 0x20));
        *pcVar16 = cVar4 + '0';
        pcVar16 = pcVar16 + 1;
      } while (pcStack00000044 + (int)pcVar5 != pcVar16);
      unaff_r7 = pcVar5 + (int)pcStack00000044;
    }
    pcVar14 = (char *)((ulonglong)uVar20 >> 0x20);
    uVar13 = (undefined4)uVar20;
    uVar20 = FUN_1001e958((int)uVar22,uVar6,0,0x3fe00000);
    iVar7 = FUN_1001ea3c((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),uVar13,pcVar14);
    if (iVar7 != 0) goto LAB_100239ec;
    uVar20 = FUN_1001e946(0,0x3fe00000,(int)uVar22,uVar6);
    iVar7 = FUN_1001ea58((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),uVar13,pcVar14);
    if (iVar7 != 0) {
      do {
        unaff_r7 = unaff_r7 + -1;
      } while (*unaff_r7 == '0');
      uVar22 = FUN_1002306c();
      uVar20 = CONCAT44((int)((ulonglong)uVar22 >> 0x20),uVar13);
      uVar6 = (undefined4)uVar22;
      pcVar16 = unaff_r10;
      goto LAB_10023d1e;
    }
    if ((in_stack_0000006c < 0) || (0xe < (int)in_stack_00000020)) goto LAB_10023e8c;
    in_stack_00000014 = *(uint *)(&DAT_1002b35c + in_stack_00000020 * 8);
    in_stack_00000010 = *(uint *)(&DAT_1002b358 + in_stack_00000020 * 8);
    FUN_1001e96a(in_stack_00000018,in_stack_0000001c,in_stack_00000010,in_stack_00000014);
    iVar7 = FUN_1001eab4();
    uVar20 = FUN_1001ea84();
    uVar20 = FUN_1001e9a6((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),in_stack_00000010,
                          in_stack_00000014);
    uVar20 = FUN_1001e946(in_stack_00000018,in_stack_0000001c,(int)uVar20,
                          (int)((ulonglong)uVar20 >> 0x20));
    *pcVar5 = (char)iVar7 + '0';
    if (pcVar12 != (char *)0x1) goto LAB_100234ee;
  }
  else {
    in_stack_00000098 = 0;
LAB_1002323a:
    pcVar16[4] = '\0';
    pcVar16[5] = '\0';
    pcVar16[6] = '\0';
    pcVar16[7] = '\0';
    pcStack0000000c = (char *)FUN_100259c0();
    if (pcStack0000000c == (char *)0x0) {
      FUN_10023dc4();
    }
    **(undefined4 **)(unaff_r9 + 0x1c) = pcStack0000000c;
    if ((in_stack_0000006c < 0) || (0xe < (int)in_stack_00000020)) {
      pcVar14 = pcStack0000002c;
      if (unaff_r8 == 0) {
        pcStack00000028 = (char *)0xffffffff;
        in_stack_00000040 = (char *)0xffffffff;
        pcVar16 = (char *)(0x36 - in_stack_00000068);
        goto LAB_1002327e;
      }
      pcStack00000028 = (char *)0xffffffff;
      in_stack_00000040 = (char *)0xffffffff;
      pcVar16 = (char *)(in_stack_0000006c + 0x433);
      goto LAB_1002327e;
    }
    in_stack_00000010 = *(uint *)(&DAT_1002b358 + in_stack_00000020 * 8);
    in_stack_00000014 = *(uint *)(&DAT_1002b35c + in_stack_00000020 * 8);
    FUN_1001e96a(in_stack_00000018,in_stack_0000001c,in_stack_00000010,in_stack_00000014);
    cVar4 = FUN_1001eab4();
    uVar20 = FUN_1001ea84();
    uVar20 = FUN_1001e9a6((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),in_stack_00000010,
                          in_stack_00000014);
    uVar20 = FUN_1001e946(in_stack_00000018,in_stack_0000001c,(int)uVar20,
                          (int)((ulonglong)uVar20 >> 0x20));
    pcVar18 = pcStack0000000c + 1;
    *pcStack0000000c = cVar4 + '0';
    pcStack00000028 = (char *)0xffffffff;
LAB_100234ee:
    unaff_r11 = pcStack0000000c + -1;
    pcVar16 = (char *)0x1;
    do {
      uVar20 = FUN_1001e9a6((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),0,0x40240000);
      uVar13 = (undefined4)((ulonglong)uVar20 >> 0x20);
      uVar6 = (undefined4)uVar20;
      iVar7 = FUN_1001ea2c(uVar6,uVar13,0,0);
      if (iVar7 != 0) {
        FUN_1002306c();
        return;
      }
      FUN_1001e96a(uVar6,uVar13,in_stack_00000010,in_stack_00000014);
      iVar7 = FUN_1001eab4();
      uVar20 = FUN_1001ea84();
      uVar20 = FUN_1001e9a6((int)uVar20,(int)((ulonglong)uVar20 >> 0x20),in_stack_00000010,
                            in_stack_00000014);
      uVar20 = FUN_1001e946(uVar6,uVar13,(int)uVar20,(int)((ulonglong)uVar20 >> 0x20));
      pcVar16 = pcVar16 + 1;
      unaff_r11[(int)pcVar16] = (char)iVar7 + '0';
      pcVar18 = pcVar18 + 1;
    } while (pcStack00000028 != pcVar16);
  }
  uVar6 = (undefined4)((ulonglong)uVar20 >> 0x20);
  uVar20 = FUN_1001e958((int)uVar20,uVar6,(int)uVar20,uVar6);
  pcVar14 = (char *)((ulonglong)uVar20 >> 0x20);
  iVar9 = FUN_1001ea58((int)uVar20,pcVar14,in_stack_00000010,in_stack_00000014);
  if ((iVar9 == 0) &&
     ((iVar9 = FUN_1001ea2c((int)uVar20,pcVar14,in_stack_00000010,in_stack_00000014), iVar9 == 0 ||
      (-1 < iVar7 << 0x1f)))) {
    FUN_1002306c();
    pcStack0000002c = (char *)0x1;
    FUN_100235a6();
    return;
  }
  pcVar5 = pcStack0000000c;
  unaff_r7 = pcVar18;
LAB_100239ec:
  do {
    unaff_r7 = unaff_r7 + -1;
    if (*unaff_r7 != '9') {
      cVar4 = *unaff_r7 + '\x01';
      pcVar8 = pcVar14;
      goto LAB_100239fa;
    }
  } while (unaff_r7 != pcVar5);
LAB_10023d68:
  cVar4 = '1';
  pcVar8 = pcVar14;
LAB_100239fa:
  *unaff_r7 = cVar4;
  FUN_1002306c();
  *pcStack0000000c = '1';
  FUN_1002320c();
  pcVar14 = extraout_r3_03;
LAB_10023a14:
  pcVar14 = pcVar14 + -(int)pcVar8;
  pcVar16 = pcStack00000028;
  if ((int)pcStack00000028 < 0) {
    uVar20 = FUN_10025ccc();
    unaff_r7 = in_stack_00000024;
    in_stack_00000024 = in_stack_00000024 + -(int)pcStack00000028;
  }
  else {
LAB_1002327e:
    unaff_r7 = in_stack_00000024 + (int)pcVar16;
    unaff_r11 = unaff_r11 + (int)pcVar16;
    uVar20 = FUN_10025ccc();
    pcVar8 = (char *)uVar20;
    if (in_stack_00000024 == (char *)0x0) {
      if (pcStack0000002c != (char *)0x0) {
        if (pcVar14 != (char *)0x0) {
          FUN_10023c1c();
        }
        unaff_r10 = (char *)FUN_10025ea8();
        in_stack_00000018 = FUN_10025ccc();
        if (in_stack_00000030 != 0) {
          FUN_10023bac();
        }
        pcVar16 = (char *)0x0;
        if (((((int)in_stack_00000098 < 2) && (in_stack_00000010 == 0)) &&
            ((in_stack_00000014 & 0xfffff) == 0)) && ((in_stack_00000014 & 0x7ff00000) != 0)) {
          in_stack_00000024 = unaff_r7 + 1;
          pcVar12 = (char *)0x1;
          pcStack0000002c = (char *)0x1;
          unaff_r11 = unaff_r11 + 1;
          in_stack_00000030 = 1;
        }
        else {
          pcVar12 = (char *)0x1;
          pcStack0000002c = (char *)0x1;
          in_stack_00000024 = unaff_r7;
        }
LAB_1002311e:
        do {
          uVar10 = (uint)(pcVar12 + (int)unaff_r11) & 0x1f;
          if (((uint)(pcVar12 + (int)unaff_r11) & 0x1f) == 0) {
            iVar7 = 0x1c;
LAB_1002313a:
            pcVar16 = pcVar16 + iVar7;
            in_stack_00000024 = in_stack_00000024 + iVar7;
            unaff_r11 = unaff_r11 + iVar7;
          }
          else {
            if (4 < (int)(0x20 - uVar10)) {
              iVar7 = 0x1c - uVar10;
              goto LAB_1002313a;
            }
            if (0x20 - uVar10 != 4) {
              iVar7 = 0x3c - uVar10;
              goto LAB_1002313a;
            }
          }
          if (0 < (int)in_stack_00000024) {
            unaff_r10 = (char *)FUN_10025fb4();
          }
          if (0 < (int)unaff_r11) {
            in_stack_00000018 = FUN_10025fb4();
          }
          if ((in_stack_00000034 == 0) ||
             (iVar7 = FUN_100260a8(unaff_r10,in_stack_00000018), -1 < iVar7)) {
            if ((0 < (int)pcStack00000028) || ((int)in_stack_00000098 < 3)) goto LAB_1002317c;
          }
          else {
            unaff_r10 = (char *)FUN_10025a90();
            if (pcStack0000002c == (char *)0x0) {
              pcStack00000028 = in_stack_00000040;
              if ((0 < (int)in_stack_00000040) || ((int)in_stack_00000098 < 3)) goto LAB_1002318a;
            }
            else {
              pcVar8 = (char *)FUN_10025a90();
              pcStack00000028 = in_stack_00000040;
              if ((0 < (int)in_stack_00000040) || ((int)in_stack_00000098 < 3)) goto LAB_1002366c;
            }
          }
          if (pcStack00000028 == (char *)0x0) {
            in_stack_00000018 = FUN_10025a90();
            iVar7 = FUN_100260a8(unaff_r10,in_stack_00000018);
            if (0 < iVar7) {
              *pcStack0000000c = '1';
              FUN_10025a44();
              if (pcVar8 == (char *)0x0) {
                FUN_1002306c();
                return;
              }
              FUN_1002322c();
              return;
            }
          }
          FUN_10025a44();
          if (pcVar8 != (char *)0x0) {
            FUN_1002322c();
          }
          FUN_1002306c();
          pcVar16 = pcStack0000000c;
LAB_10023b16:
          if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
             ((in_stack_00000014 & 0x7ff00000) != 0)) {
            in_stack_00000024 = in_stack_00000024 + 1;
            in_stack_00000030 = 1;
            unaff_r11 = unaff_r11 + 1;
          }
LAB_100235be:
          iVar7 = FUN_10025bdc(*(undefined4 *)
                                (*(int *)(in_stack_00000018 + 0x10) * 4 + in_stack_00000018 + 0x10))
          ;
          pcVar12 = (char *)(0x20 - iVar7);
        } while( true );
      }
      goto LAB_10023a42;
    }
  }
  uVar6 = (undefined4)uVar20;
  pcVar16 = unaff_r10;
  if ((int)unaff_r11 < 1) {
    if (pcStack0000002c != (char *)0x0) {
      FUN_1002329e();
      return;
    }
LAB_10023a42:
    FUN_100232b4();
    return;
  }
LAB_10023d1e:
  pcVar8 = (char *)uVar20;
  pcVar12 = in_stack_00000024;
  if ((int)unaff_r11 < (int)in_stack_00000024) {
    pcVar12 = unaff_r11;
  }
  pcVar18 = unaff_r7 + -(int)pcVar12;
  unaff_r10 = in_stack_00000024 + -(int)pcVar12;
  if (pcStack0000002c != (char *)0x0) {
    FUN_1002329e(uVar6,(int)((ulonglong)uVar20 >> 0x20),unaff_r11);
  }
  FUN_100232b4();
  unaff_r7 = pcVar16;
  in_stack_00000024 = pcVar18;
  goto LAB_10023d44;
LAB_1002317c:
  if (pcStack0000002c == (char *)0x0) {
LAB_1002318a:
    iVar7 = 1;
    while( true ) {
      iVar9 = FUN_10022c2c(unaff_r10,in_stack_00000018);
      pcStack0000000c[iVar7 + -1] = (char)iVar9 + '0';
      if ((int)pcStack00000028 <= iVar7) break;
      unaff_r10 = (char *)FUN_10025a90();
      iVar7 = iVar7 + 1;
    }
    pcVar16 = (char *)0x0;
    if (0 < (int)pcStack00000028) {
      pcVar16 = pcStack00000028 + -1;
    }
    pcVar16 = pcVar16 + (int)(pcStack0000000c + 1);
    uVar6 = FUN_10025fb4();
    uVar20 = FUN_100260a8(uVar6,in_stack_00000018);
    iVar7 = (int)uVar20;
    if ((0 < iVar7) || ((iVar7 == 0 && (iVar9 << 0x1f < 0)))) {
      FUN_100231fe(iVar7,(int)((ulonglong)uVar20 >> 0x20),pcStack0000000c);
      return;
    }
    do {
      pcVar16 = pcVar16 + -1;
    } while (*pcVar16 == '0');
    FUN_1002320c();
    return;
  }
LAB_1002366c:
  if (0 < (int)pcVar16) {
    pcVar8 = (char *)FUN_10025fb4();
  }
  pcVar16 = pcVar8;
  if (in_stack_00000030 != 0) {
    iVar7 = FUN_100259c0();
    if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded");
    }
    FUN_1001f4d4(iVar7 + 0xc,pcVar8 + 0xc,(*(int *)(pcVar8 + 0x10) + 2) * 4);
    pcVar16 = (char *)FUN_10025fb4();
  }
  pcStack00000028 = pcStack00000028 + (int)(pcStack0000000c + -1);
  in_stack_00000030 = in_stack_00000010 & 1;
  unaff_r11 = pcStack0000000c;
LAB_100236a2:
  pcVar18 = (char *)FUN_10022c2c(unaff_r10,in_stack_00000018);
  unaff_r7 = pcVar18 + 0x30;
  pcStack0000002c = pcVar18;
  iVar7 = FUN_100260a8(unaff_r10,pcVar8);
  iVar9 = FUN_100260e4();
  pcVar12 = pcVar8;
  if (*(int *)(iVar9 + 0xc) != 0) {
    uVar21 = FUN_10025a44();
    if (iVar7 < 0) goto LAB_10023762;
    if ((in_stack_00000010 & 1) == 0 && (iVar7 == 0 && in_stack_00000098 == 0)) goto LAB_10023762;
LAB_100237c2:
    pcVar8 = pcVar16;
    if (unaff_r7 != (char *)0x39) {
      *unaff_r11 = (char)pcVar18 + '1';
      FUN_1002320c();
      return;
    }
    goto LAB_10023d72;
  }
  in_stack_00000024 = (char *)FUN_100260a8(unaff_r10,iVar9);
  uVar21 = FUN_10025a44();
  if (in_stack_00000024 == (char *)0x0 && in_stack_00000098 == 0) {
    if (in_stack_00000030 == 0) {
      pcVar8 = pcVar16;
      if (unaff_r7 == (char *)0x39) goto LAB_10023d72;
      if (0 < iVar7) goto LAB_10023780;
      goto LAB_10023784;
    }
    if (iVar7 < 0) goto LAB_10023784;
  }
  else {
    if (iVar7 < 0) goto LAB_10023d8c;
    if ((iVar7 == 0 && in_stack_00000098 == 0) && in_stack_00000030 == 0) goto LAB_10023d8c;
    if (0 < (int)in_stack_00000024) goto LAB_100237c2;
  }
  pcVar14 = unaff_r11 + 1;
  *unaff_r11 = (char)unaff_r7;
  if (unaff_r11 != pcStack00000028) {
    unaff_r10 = (char *)FUN_10025a90();
    unaff_r11 = pcVar14;
    if (pcVar8 == pcVar16) {
      pcVar8 = (char *)FUN_10025a90();
      pcVar16 = pcVar8;
    }
    else {
      pcVar8 = (char *)FUN_10025a90();
      pcVar16 = (char *)FUN_10025a90();
    }
    goto LAB_100236a2;
  }
LAB_10023d44:
  FUN_100231da();
  pcVar12 = pcVar14;
  unaff_r11 = pcVar8;
LAB_10023d58:
  FUN_100233d4();
  pcVar14 = pcVar12;
  goto LAB_10023d68;
LAB_10023d72:
  *unaff_r11 = '9';
  FUN_100231fe((int)uVar21,(int)(uVar21 >> 0x20),pcStack0000000c);
  pcVar16 = unaff_r7;
  unaff_r7 = unaff_r10;
  unaff_r11 = pcVar12;
LAB_10023d8c:
  if ((int)in_stack_00000024 < 1) goto LAB_10023784;
LAB_10023762:
  unaff_r10 = (char *)FUN_10025fb4();
  uVar21 = FUN_100260a8(unaff_r10,in_stack_00000018);
  if ((int)uVar21 < 1) {
LAB_10023dfa:
    if (((int)uVar21 != 0) || (-1 < (int)unaff_r7 << 0x1f)) goto LAB_10023784;
    uVar21 = uVar21 & 0xffffffff00000000;
  }
  if (unaff_r7 != (char *)0x39) {
LAB_10023780:
    unaff_r7 = pcStack0000002c + 0x31;
LAB_10023784:
    *unaff_r11 = (char)unaff_r7;
    FUN_1002320c();
    return;
  }
  unaff_r7 = (char *)0x39;
  pcVar12 = pcVar8;
  pcVar8 = pcVar16;
  goto LAB_10023d72;
}



/* FUN_10022fb8 at 10022fb8 */

void FUN_10022fb8(void)

{
  uint uVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  uint uVar7;
  int extraout_r1;
  int iVar8;
  int iVar9;
  int extraout_r3;
  uint extraout_r3_00;
  int iVar10;
  int extraout_r3_01;
  int unaff_r4;
  undefined4 uVar11;
  char *unaff_r5;
  undefined4 *puVar12;
  char *unaff_r6;
  undefined4 uVar13;
  char *unaff_r7;
  char *pcVar14;
  int unaff_r9;
  char *unaff_r10;
  char *unaff_r11;
  undefined4 *puVar15;
  undefined8 uVar16;
  ulonglong uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  uint in_stack_00000020;
  char *in_stack_00000024;
  char *in_stack_00000028;
  int in_stack_0000002c;
  uint in_stack_00000030;
  int in_stack_00000034;
  undefined4 uStack0000003c;
  char *in_stack_00000040;
  char *pcStack00000044;
  int in_stack_00000048;
  uint uStack00000054;
  int in_stack_0000006c;
  int in_stack_00000098;
  int in_stack_0000009c;
  int *in_stack_000000a0;
  undefined4 *in_stack_000000a8;
  
  iVar9 = 4;
  iVar10 = 1;
  if ((int)unaff_r5 < 0x18) {
                    /* WARNING: Subroutine does not return */
    FUN_10023e9c();
  }
  do {
    iVar8 = iVar10;
    iVar9 = iVar9 * 2;
    iVar10 = iVar8 + 1;
  } while ((char *)(iVar9 + 0x14) <= unaff_r5);
  *(int *)(unaff_r6 + 4) = iVar8;
  pcVar3 = (char *)FUN_100259c0();
  pcVar4 = pcVar3;
  if (pcVar3 == (char *)0x0) {
    pcVar4 = (char *)FUN_10023dc4();
  }
  **(undefined4 **)(unaff_r9 + 0x1c) = pcVar4;
  if (((char *)0xe < in_stack_00000028) || (unaff_r4 == 0)) {
    if ((-1 < in_stack_0000006c) && ((int)in_stack_00000020 < 0xf)) {
      uVar11 = *(undefined4 *)(&DAT_1002b35c + in_stack_00000020 * 8);
      uVar5 = *(undefined4 *)(&DAT_1002b358 + in_stack_00000020 * 8);
      if (-1 < in_stack_0000009c) {
        FUN_10023bb2();
      }
      if (0 < (int)in_stack_00000028) {
        FUN_10023bb2();
      }
      if (in_stack_00000028 == (char *)0x0) {
        uVar16 = FUN_1001e9a6(uVar5,uVar11,0,0x40140000);
        iVar10 = FUN_1001ea48(in_stack_00000018,in_stack_0000001c,(int)uVar16,
                              (int)((ulonglong)uVar16 >> 0x20));
        if (iVar10 == 0) {
LAB_10023056:
          *pcVar3 = '1';
          FUN_10025a44();
          FUN_10025a44();
          pcVar3[1] = '\0';
          *in_stack_000000a0 = in_stack_00000020 + 2;
          if (in_stack_000000a8 == (undefined4 *)0x0) {
            FUN_10022e06();
            return;
          }
          *in_stack_000000a8 = pcVar3 + 1;
          FUN_10022e06();
          return;
        }
      }
LAB_1002344e:
      FUN_10025a44();
      FUN_1002306c();
      return;
    }
    if (in_stack_00000048 != 0) {
      FUN_10023e32();
    }
    uVar7 = in_stack_00000030;
    if (in_stack_00000024 == (char *)0x0) {
      if (in_stack_0000002c == 0) {
        in_stack_00000018 = FUN_10025ccc();
        pcVar4 = (char *)0x0;
        if (in_stack_00000030 != 0) goto code_r0x100235a6;
LAB_100234a4:
        pcVar6 = (char *)0x0;
        iVar10 = uVar7 + 1;
        goto LAB_1002311e;
      }
    }
    else if (unaff_r11 == (char *)0x0) {
      if (in_stack_0000002c == 0) {
        in_stack_00000018 = FUN_10025ccc();
        pcVar6 = (char *)0x0;
        pcVar4 = in_stack_00000024;
        if (in_stack_00000030 == 0) {
          iVar10 = 1;
          goto LAB_1002311e;
        }
code_r0x100235a6:
        pcVar6 = (char *)0x0;
        in_stack_00000018 = FUN_10025ea8();
        in_stack_00000030 = 0;
        if (1 < in_stack_00000098) goto LAB_100235be;
        goto LAB_10023b16;
      }
    }
    else {
      pcVar6 = in_stack_00000024;
      if ((int)unaff_r11 < (int)in_stack_00000024) {
        pcVar6 = unaff_r11;
      }
      pcVar4 = in_stack_00000024 + -(int)pcVar6;
      unaff_r11 = unaff_r11 + -(int)pcVar6;
      in_stack_00000024 = pcVar4;
      if (in_stack_0000002c == 0) {
        in_stack_00000018 = FUN_10025ccc();
        if (in_stack_00000030 != 0) {
          FUN_10023df2();
          uVar7 = extraout_r3_00;
        }
        goto LAB_100234a4;
      }
    }
    unaff_r10 = (char *)FUN_10025ea8();
    in_stack_00000018 = FUN_10025ccc();
    in_stack_0000002c = 0;
    if (in_stack_00000030 != 0) {
      FUN_10023d9c();
      in_stack_0000002c = extraout_r3;
    }
    pcVar6 = (char *)0x0;
    iVar10 = in_stack_0000002c + 1;
    pcVar4 = in_stack_00000024;
    goto LAB_1002311e;
  }
  if ((int)in_stack_00000020 < 1) {
    pcVar6 = unaff_r11;
    if (in_stack_00000020 == 0) goto LAB_10023d58;
    iVar10 = (-in_stack_00000020 & 0xf) * 8;
    uVar16 = FUN_1001e9a6(in_stack_00000018,in_stack_0000001c,
                          *(undefined4 *)(&DAT_1002b358 + iVar10),
                          *(undefined4 *)(&DAT_1002b35c + iVar10));
    uVar7 = (int)-in_stack_00000020 >> 4;
    if (uVar7 != 0) {
      puVar12 = &DAT_1002b330;
      do {
        while( true ) {
          uStack0000003c = (undefined4)((ulonglong)uVar16 >> 0x20);
          uVar1 = uVar7 & 1;
          uVar7 = (int)uVar7 >> 1;
          if (uVar1 != 0) break;
          puVar12 = puVar12 + 2;
        }
        uVar5 = *puVar12;
        puVar15 = puVar12 + 1;
        puVar12 = puVar12 + 2;
        uVar16 = FUN_1001e9a6((int)uVar16,uStack0000003c,uVar5,*puVar15);
      } while (uVar7 != 0);
      FUN_100233d4();
      return;
    }
  }
  else {
    uVar7 = (int)in_stack_00000020 >> 4;
    uVar18 = *(undefined8 *)(&DAT_1002b358 + (in_stack_00000020 & 0xf) * 8);
    uVar16 = *(undefined8 *)(&DAT_1002b358 + (in_stack_00000020 & 0xf) * 8);
    if ((int)(in_stack_00000020 << 0x17) < 0) {
      uVar7 = uVar7 & 0xf;
      uVar19 = FUN_1001e96a(in_stack_00000018,in_stack_0000001c,0x7f73bf3c,0x75154fdd);
      uStack0000003c = (undefined4)((ulonglong)uVar19 >> 0x20);
      iVar10 = (int)uVar19;
      pcVar4 = (char *)0x3;
    }
    else {
      uStack0000003c = in_stack_0000001c;
      pcVar4 = (char *)0x2;
      iVar10 = in_stack_00000018;
    }
    if (uVar7 != 0) {
      puVar12 = &DAT_1002b330;
      uVar16 = uVar18;
      do {
        while( true ) {
          uVar1 = uVar7 & 1;
          uVar7 = (int)uVar7 >> 1;
          if (uVar1 != 0) break;
          puVar12 = puVar12 + 2;
        }
        uVar5 = *puVar12;
        puVar15 = puVar12 + 1;
        puVar12 = puVar12 + 2;
        pcVar4 = pcVar4 + 1;
        uVar16 = FUN_1001e9a6((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar5,*puVar15);
      } while (uVar7 != 0);
    }
    uVar16 = FUN_1001e96a(iVar10,uStack0000003c,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
    uVar11 = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar5 = (undefined4)uVar16;
    if ((in_stack_00000034 == 0) || (iVar10 = FUN_1001ea3c(uVar5,uVar11,0,0x3ff00000), iVar10 == 0))
    {
      uVar18 = FUN_1001ea84(pcVar4);
      uVar18 = FUN_1001e9a6((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar5,uVar11);
      uVar18 = FUN_1001e958((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),0,0x401c0000);
      iVar10 = (int)((ulonglong)uVar18 >> 0x20);
      uVar13 = (undefined4)uVar18;
      iVar9 = iVar10 + -0x3400000;
      uStack00000054 = in_stack_00000020;
      pcStack00000044 = in_stack_00000028;
      if (in_stack_00000028 == (char *)0x0) {
        uVar16 = FUN_1001e946(uVar5,uVar11,0,0x40140000);
        uVar5 = (undefined4)((ulonglong)uVar16 >> 0x20);
        iVar9 = FUN_1001ea58((int)uVar16,uVar5,uVar13,iVar9);
        if (iVar9 != 0) goto LAB_10023056;
        iVar10 = FUN_1001ea3c((int)uVar16,uVar5,uVar13,iVar10 + 0x7cc00000);
        if (iVar10 == 0) {
          FUN_10022ff6();
          return;
        }
        goto LAB_1002344e;
      }
    }
    else {
      if (in_stack_00000028 == (char *)0x0) {
        uVar16 = FUN_1001ea84(pcVar4);
        uVar16 = FUN_1001e9a6((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar5,uVar11);
        FUN_1001e958((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),0,0x401c0000);
        unaff_r7 = (char *)(extraout_r1 + -0x3400000);
        FUN_1002341a();
        pcVar6 = (char *)0x0;
        uVar17 = FUN_100235a6();
        goto LAB_10023dfa;
      }
      if ((int)in_stack_00000040 < 1) {
        FUN_10022ff6();
      }
      uStack00000054 = in_stack_00000020 - 1;
      uVar16 = FUN_1001e9a6(uVar5,uVar11,0,0x40240000);
      uVar18 = FUN_1001ea84(pcVar4 + 1);
      uVar18 = FUN_1001e9a6((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar16,
                            (int)((ulonglong)uVar16 >> 0x20));
      uVar18 = FUN_1001e958((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),0,0x401c0000);
      uVar13 = (undefined4)uVar18;
      iVar9 = (int)((ulonglong)uVar18 >> 0x20) + -0x3400000;
      pcStack00000044 = in_stack_00000040;
    }
    uStack0000003c = (undefined4)((ulonglong)uVar16 >> 0x20);
    uVar5 = *(undefined4 *)(&DAT_1002b35c + (int)(pcStack00000044 + -1) * 8);
    pcVar6 = *(char **)(&DAT_1002b358 + (int)(pcStack00000044 + -1) * 8);
    cVar2 = FUN_1001eab4((int)uVar16,uStack0000003c);
    uVar18 = FUN_1001ea84();
    uVar16 = FUN_1001e946((int)uVar16,uStack0000003c,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
    pcVar4 = pcVar3 + 1;
    if (in_stack_00000048 == 0) {
      uVar18 = FUN_1001e9a6(pcVar6,uVar5,uVar13,iVar9);
      uVar5 = (undefined4)((ulonglong)uVar18 >> 0x20);
      *pcVar3 = cVar2 + '0';
      unaff_r6 = pcStack00000044 + (int)pcVar3;
      pcVar14 = pcVar4;
      if (pcStack00000044 != (char *)0x1) {
        unaff_r6 = pcVar4;
        do {
          uVar16 = FUN_1001e9a6((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),0,0x40240000);
          cVar2 = FUN_1001eab4();
          uVar19 = FUN_1001ea84();
          uVar16 = FUN_1001e946((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar19,
                                (int)((ulonglong)uVar19 >> 0x20));
          *unaff_r6 = cVar2 + '0';
          unaff_r6 = unaff_r6 + 1;
        } while (pcStack00000044 + (int)pcVar3 != unaff_r6);
        pcVar14 = pcVar3 + (int)pcStack00000044;
      }
      unaff_r5 = (char *)((ulonglong)uVar16 >> 0x20);
      uVar11 = (undefined4)uVar16;
      uVar16 = FUN_1001e958((int)uVar18,uVar5,0,0x3fe00000);
      iVar10 = FUN_1001ea3c((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar11,unaff_r5);
      pcVar6 = unaff_r11;
      if (iVar10 != 0) {
LAB_100239ec:
        while( true ) {
          unaff_r7 = pcVar14 + -1;
          if (*unaff_r7 != '9') break;
          pcVar14 = unaff_r7;
          if (unaff_r7 == pcVar3) goto LAB_10023d68;
        }
        cVar2 = *unaff_r7 + '\x01';
        goto LAB_100239fa;
      }
      uVar16 = FUN_1001e946(0,0x3fe00000,(int)uVar18,uVar5);
      iVar10 = FUN_1001ea58((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar11,unaff_r5);
      if (iVar10 != 0) {
        do {
          pcVar14 = pcVar14 + -1;
        } while (*pcVar14 == '0');
        uVar18 = FUN_1002306c();
        uVar16 = CONCAT44((int)((ulonglong)uVar18 >> 0x20),uVar11);
        uVar5 = (undefined4)uVar18;
        unaff_r7 = unaff_r10;
        goto LAB_10023d1e;
      }
      if ((-1 < in_stack_0000006c) && ((int)in_stack_00000020 < 0xf)) {
        in_stack_00000014 = *(uint *)(&DAT_1002b35c + in_stack_00000020 * 8);
        in_stack_00000010 = *(uint *)(&DAT_1002b358 + in_stack_00000020 * 8);
        FUN_1001e96a(in_stack_00000018,in_stack_0000001c,in_stack_00000010,in_stack_00000014);
        iVar10 = FUN_1001eab4();
        uVar16 = FUN_1001ea84();
        uVar16 = FUN_1001e9a6((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),in_stack_00000010,
                              in_stack_00000014);
        uVar16 = FUN_1001e946(in_stack_00000018,in_stack_0000001c,(int)uVar16,
                              (int)((ulonglong)uVar16 >> 0x20));
        *pcVar3 = (char)iVar10 + '0';
        if (in_stack_00000028 != (char *)0x1) {
          unaff_r11 = pcVar3 + -1;
          pcVar6 = (char *)0x1;
          do {
            uVar16 = FUN_1001e9a6((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),0,0x40240000);
            uVar11 = (undefined4)((ulonglong)uVar16 >> 0x20);
            uVar5 = (undefined4)uVar16;
            iVar10 = FUN_1001ea2c(uVar5,uVar11,0,0);
            if (iVar10 != 0) {
              FUN_1002306c();
              return;
            }
            FUN_1001e96a(uVar5,uVar11,in_stack_00000010,in_stack_00000014);
            iVar10 = FUN_1001eab4();
            uVar16 = FUN_1001ea84();
            uVar16 = FUN_1001e9a6((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),in_stack_00000010,
                                  in_stack_00000014);
            uVar16 = FUN_1001e946(uVar5,uVar11,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
            pcVar6 = pcVar6 + 1;
            unaff_r11[(int)pcVar6] = (char)iVar10 + '0';
            pcVar4 = pcVar4 + 1;
          } while (in_stack_00000028 != pcVar6);
        }
        uVar5 = (undefined4)((ulonglong)uVar16 >> 0x20);
        uVar16 = FUN_1001e958((int)uVar16,uVar5,(int)uVar16,uVar5);
        unaff_r5 = (char *)((ulonglong)uVar16 >> 0x20);
        iVar9 = FUN_1001ea58((int)uVar16,unaff_r5,in_stack_00000010,in_stack_00000014);
        pcVar14 = pcVar4;
        pcVar6 = unaff_r11;
        if ((iVar9 == 0) &&
           ((iVar9 = FUN_1001ea2c((int)uVar16,unaff_r5,in_stack_00000010,in_stack_00000014),
            iVar9 == 0 || (-1 < iVar10 << 0x1f)))) {
          FUN_1002306c();
          FUN_100235a6();
          return;
        }
        goto LAB_100239ec;
      }
    }
    else {
      uVar18 = FUN_1001e96a(0,0x3fe00000,pcVar6,uVar5);
      uVar18 = FUN_1001e946((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar13,iVar9);
      *pcVar3 = cVar2 + '0';
      iVar10 = FUN_1001ea58((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar16,
                            (int)((ulonglong)uVar16 >> 0x20));
      pcVar14 = pcVar4;
      if (iVar10 == 0) {
        iVar10 = 0;
        do {
          uVar5 = (undefined4)((ulonglong)uVar18 >> 0x20);
          unaff_r5 = (char *)((ulonglong)uVar16 >> 0x20);
          uVar19 = FUN_1001e946(0,0x3ff00000,(int)uVar16,unaff_r5);
          iVar9 = FUN_1001ea3c((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,uVar5);
          pcVar14 = pcVar4;
          pcVar6 = pcVar4;
          if (iVar9 != 0) goto LAB_100239ec;
          iVar10 = iVar10 + 1;
          pcVar6 = unaff_r11;
          if ((int)pcStack00000044 <= iVar10) goto LAB_10023e1a;
          uVar18 = FUN_1001e9a6((int)uVar18,uVar5,0,0x40240000);
          uVar16 = FUN_1001e9a6((int)uVar16,unaff_r5,0,0x40240000);
          cVar2 = FUN_1001eab4();
          uVar19 = FUN_1001ea84();
          uVar16 = FUN_1001e946((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar19,
                                (int)((ulonglong)uVar19 >> 0x20));
          pcVar3[iVar10] = cVar2 + '0';
          pcVar4 = pcVar4 + 1;
          iVar9 = FUN_1001ea3c((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar18,
                               (int)((ulonglong)uVar18 >> 0x20));
          pcVar14 = unaff_r10;
        } while (iVar9 == 0);
      }
      in_stack_00000020 = uStack00000054 + 1;
      FUN_1002306c();
      unaff_r10 = pcVar14;
LAB_10023e1a:
      if ((-1 < in_stack_0000006c) && ((int)in_stack_00000020 < 0xf)) {
        FUN_1002300a();
      }
      unaff_r5 = in_stack_00000028 + -1;
      iVar10 = in_stack_0000002c;
      if ((int)unaff_r5 <= in_stack_0000002c) {
LAB_10023a14:
        unaff_r5 = (char *)(iVar10 - (int)unaff_r5);
        if ((int)in_stack_00000028 < 0) {
          uVar16 = FUN_10025ccc();
          pcVar14 = in_stack_00000024;
          unaff_r11 = pcVar6;
          in_stack_00000024 = in_stack_00000024 + -(int)in_stack_00000028;
        }
        else {
          pcVar14 = in_stack_00000024 + (int)in_stack_00000028;
          unaff_r11 = pcVar6 + (int)in_stack_00000028;
          uVar16 = FUN_10025ccc();
          pcVar6 = (char *)uVar16;
          if (in_stack_00000024 == (char *)0x0) {
            if (in_stack_0000002c != 0) {
              if (unaff_r5 != (char *)0x0) {
                FUN_10023c1c();
              }
              unaff_r10 = (char *)FUN_10025ea8();
              in_stack_00000018 = FUN_10025ccc();
              if (in_stack_00000030 != 0) {
                FUN_10023bac();
              }
              pcVar4 = (char *)0x0;
              if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) &&
                  ((in_stack_00000014 & 0xfffff) == 0)) && ((in_stack_00000014 & 0x7ff00000) != 0))
              {
                in_stack_00000024 = pcVar14 + 1;
                iVar10 = 1;
                in_stack_0000002c = 1;
                unaff_r11 = unaff_r11 + 1;
                in_stack_00000030 = 1;
              }
              else {
                iVar10 = 1;
                in_stack_0000002c = 1;
                in_stack_00000024 = pcVar14;
              }
LAB_1002311e:
              do {
                uVar7 = (uint)(unaff_r11 + iVar10) & 0x1f;
                if (((uint)(unaff_r11 + iVar10) & 0x1f) == 0) {
                  iVar10 = 0x1c;
LAB_1002313a:
                  pcVar4 = pcVar4 + iVar10;
                  in_stack_00000024 = in_stack_00000024 + iVar10;
                  unaff_r11 = unaff_r11 + iVar10;
                }
                else {
                  if (4 < (int)(0x20 - uVar7)) {
                    iVar10 = 0x1c - uVar7;
                    goto LAB_1002313a;
                  }
                  if (0x20 - uVar7 != 4) {
                    iVar10 = 0x3c - uVar7;
                    goto LAB_1002313a;
                  }
                }
                if (0 < (int)in_stack_00000024) {
                  unaff_r10 = (char *)FUN_10025fb4();
                }
                if (0 < (int)unaff_r11) {
                  in_stack_00000018 = FUN_10025fb4();
                }
                if ((in_stack_00000034 == 0) ||
                   (iVar10 = FUN_100260a8(unaff_r10,in_stack_00000018), -1 < iVar10)) {
                  if ((0 < (int)in_stack_00000028) || (in_stack_00000098 < 3)) goto LAB_1002317c;
                }
                else {
                  unaff_r10 = (char *)FUN_10025a90();
                  if (in_stack_0000002c == 0) {
                    in_stack_00000028 = in_stack_00000040;
                    if ((0 < (int)in_stack_00000040) || (in_stack_00000098 < 3)) goto LAB_1002318a;
                  }
                  else {
                    pcVar6 = (char *)FUN_10025a90();
                    in_stack_00000028 = in_stack_00000040;
                    if ((0 < (int)in_stack_00000040) || (in_stack_00000098 < 3)) goto LAB_1002366c;
                  }
                }
                if (in_stack_00000028 == (char *)0x0) {
                  in_stack_00000018 = FUN_10025a90();
                  iVar10 = FUN_100260a8(unaff_r10,in_stack_00000018);
                  if (0 < iVar10) {
                    *pcVar3 = '1';
                    FUN_10025a44();
                    if (pcVar6 == (char *)0x0) {
                      FUN_1002306c();
                      return;
                    }
                    FUN_1002322c();
                    return;
                  }
                }
                FUN_10025a44();
                if (pcVar6 != (char *)0x0) {
                  FUN_1002322c();
                }
                FUN_1002306c();
                pcVar4 = pcVar3;
LAB_10023b16:
                if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
                   ((in_stack_00000014 & 0x7ff00000) != 0)) {
                  in_stack_00000024 = in_stack_00000024 + 1;
                  in_stack_00000030 = 1;
                  unaff_r11 = unaff_r11 + 1;
                }
LAB_100235be:
                iVar10 = FUN_10025bdc(*(undefined4 *)
                                       (*(int *)(in_stack_00000018 + 0x10) * 4 + in_stack_00000018 +
                                       0x10));
                iVar10 = 0x20 - iVar10;
              } while( true );
            }
            goto LAB_10023a42;
          }
        }
        uVar5 = (undefined4)uVar16;
        unaff_r7 = unaff_r10;
        if ((int)unaff_r11 < 1) {
          if (in_stack_0000002c != 0) {
            FUN_1002329e();
            return;
          }
LAB_10023a42:
          FUN_100232b4();
          return;
        }
LAB_10023d1e:
        pcVar6 = (char *)uVar16;
        pcVar4 = in_stack_00000024;
        if ((int)unaff_r11 < (int)in_stack_00000024) {
          pcVar4 = unaff_r11;
        }
        unaff_r10 = in_stack_00000024 + -(int)pcVar4;
        if (in_stack_0000002c != 0) {
          FUN_1002329e(uVar5,(int)((ulonglong)uVar16 >> 0x20),unaff_r11);
        }
        FUN_100232b4();
        in_stack_00000024 = pcVar14 + -(int)pcVar4;
        goto LAB_10023d44;
      }
      FUN_10025ccc();
      if (in_stack_00000024 == (char *)0x0) {
        FUN_100232a6();
      }
      pcVar4 = in_stack_00000024;
      if ((int)(pcVar6 + (int)in_stack_00000028) < (int)in_stack_00000024) {
        pcVar4 = pcVar6 + (int)in_stack_00000028;
      }
      unaff_r6 = in_stack_00000024 + -(int)pcVar4;
      FUN_100232a6();
    }
    FUN_100230e6();
  }
  FUN_100233d4();
  unaff_r6[4] = '\0';
  unaff_r6[5] = '\0';
  unaff_r6[6] = '\0';
  unaff_r6[7] = '\0';
  FUN_10022fd4();
                    /* WARNING: Subroutine does not return */
  FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0xef,0,"REENT malloc succeeded");
LAB_1002317c:
  if (in_stack_0000002c == 0) {
LAB_1002318a:
    iVar10 = 1;
    while( true ) {
      iVar9 = FUN_10022c2c(unaff_r10,in_stack_00000018);
      pcVar3[iVar10 + -1] = (char)iVar9 + '0';
      if ((int)in_stack_00000028 <= iVar10) break;
      unaff_r10 = (char *)FUN_10025a90();
      iVar10 = iVar10 + 1;
    }
    pcVar4 = (char *)0x0;
    if (0 < (int)in_stack_00000028) {
      pcVar4 = in_stack_00000028 + -1;
    }
    pcVar4 = pcVar4 + (int)(pcVar3 + 1);
    uVar5 = FUN_10025fb4();
    uVar16 = FUN_100260a8(uVar5,in_stack_00000018);
    iVar10 = (int)uVar16;
    if ((0 < iVar10) || ((iVar10 == 0 && (iVar9 << 0x1f < 0)))) {
      FUN_100231fe(iVar10,(int)((ulonglong)uVar16 >> 0x20),pcVar3);
      return;
    }
    do {
      pcVar4 = pcVar4 + -1;
    } while (*pcVar4 == '0');
    FUN_1002320c();
    return;
  }
LAB_1002366c:
  if (0 < (int)pcVar4) {
    pcVar6 = (char *)FUN_10025fb4();
  }
  pcVar4 = pcVar6;
  if (in_stack_00000030 != 0) {
    iVar10 = FUN_100259c0();
    if (iVar10 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded");
    }
    FUN_1001f4d4(iVar10 + 0xc,pcVar6 + 0xc,(*(int *)(pcVar6 + 0x10) + 2) * 4);
    pcVar4 = (char *)FUN_10025fb4();
  }
  in_stack_00000028 = in_stack_00000028 + (int)(pcVar3 + -1);
  in_stack_00000030 = in_stack_00000010 & 1;
  unaff_r11 = pcVar3;
LAB_100236a2:
  in_stack_0000002c = FUN_10022c2c(unaff_r10,in_stack_00000018);
  unaff_r7 = (char *)(in_stack_0000002c + 0x30);
  iVar10 = FUN_100260a8(unaff_r10,pcVar6);
  iVar9 = FUN_100260e4();
  pcVar14 = pcVar6;
  if (*(int *)(iVar9 + 0xc) != 0) {
    uVar17 = FUN_10025a44();
    if (iVar10 < 0) goto LAB_10023762;
    if ((in_stack_00000010 & 1) == 0 && (iVar10 == 0 && in_stack_00000098 == 0)) goto LAB_10023762;
LAB_100237c2:
    pcVar6 = pcVar4;
    if (unaff_r7 != (char *)0x39) {
      *unaff_r11 = (char)in_stack_0000002c + '1';
      FUN_1002320c();
      return;
    }
    goto LAB_10023d72;
  }
  in_stack_00000024 = (char *)FUN_100260a8(unaff_r10,iVar9);
  uVar17 = FUN_10025a44();
  if (in_stack_00000024 == (char *)0x0 && in_stack_00000098 == 0) {
    if (in_stack_00000030 == 0) {
      pcVar6 = pcVar4;
      if (unaff_r7 == (char *)0x39) goto LAB_10023d72;
      if (0 < iVar10) goto LAB_10023780;
      goto LAB_10023784;
    }
    if (iVar10 < 0) goto LAB_10023784;
  }
  else {
    if (iVar10 < 0) goto LAB_10023d8c;
    if ((iVar10 == 0 && in_stack_00000098 == 0) && in_stack_00000030 == 0) goto LAB_10023d8c;
    if (0 < (int)in_stack_00000024) goto LAB_100237c2;
  }
  unaff_r5 = unaff_r11 + 1;
  *unaff_r11 = (char)unaff_r7;
  if (unaff_r11 != in_stack_00000028) {
    unaff_r10 = (char *)FUN_10025a90();
    unaff_r11 = unaff_r5;
    if (pcVar6 == pcVar4) {
      pcVar6 = (char *)FUN_10025a90();
      pcVar4 = pcVar6;
    }
    else {
      pcVar6 = (char *)FUN_10025a90();
      pcVar4 = (char *)FUN_10025a90();
    }
    goto LAB_100236a2;
  }
LAB_10023d44:
  FUN_100231da();
LAB_10023d58:
  FUN_100233d4();
LAB_10023d68:
  cVar2 = '1';
LAB_100239fa:
  *unaff_r7 = cVar2;
  FUN_1002306c();
  *pcVar3 = '1';
  FUN_1002320c();
  iVar10 = extraout_r3_01;
  goto LAB_10023a14;
LAB_10023d72:
  *unaff_r11 = '9';
  FUN_100231fe((int)uVar17,(int)(uVar17 >> 0x20),pcVar3);
  pcVar4 = unaff_r7;
  unaff_r7 = unaff_r10;
  unaff_r11 = pcVar14;
LAB_10023d8c:
  if ((int)in_stack_00000024 < 1) goto LAB_10023784;
LAB_10023762:
  unaff_r10 = (char *)FUN_10025fb4();
  uVar17 = FUN_100260a8(unaff_r10,in_stack_00000018);
  if ((int)uVar17 < 1) {
LAB_10023dfa:
    if (((int)uVar17 != 0) || (-1 < (int)unaff_r7 << 0x1f)) goto LAB_10023784;
    uVar17 = uVar17 & 0xffffffff00000000;
  }
  if (unaff_r7 != (char *)0x39) {
LAB_10023780:
    unaff_r7 = (char *)(in_stack_0000002c + 0x31);
LAB_10023784:
    *unaff_r11 = (char)unaff_r7;
    FUN_1002320c();
    return;
  }
  unaff_r7 = (char *)0x39;
  pcVar14 = pcVar6;
  pcVar6 = pcVar4;
  goto LAB_10023d72;
}



/* FUN_10022fd4 at 10022fd4 */

void FUN_10022fd4(void)

{
  uint uVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  int extraout_r1;
  int extraout_r3;
  uint extraout_r3_00;
  int iVar9;
  int extraout_r3_01;
  int unaff_r4;
  undefined4 uVar10;
  char *unaff_r5;
  undefined4 *puVar11;
  char *unaff_r6;
  undefined4 uVar12;
  char *unaff_r7;
  char *pcVar13;
  int unaff_r9;
  char *unaff_r10;
  char *unaff_r11;
  undefined4 *puVar14;
  undefined8 uVar15;
  ulonglong uVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  uint in_stack_00000020;
  char *in_stack_00000024;
  char *in_stack_00000028;
  int in_stack_0000002c;
  uint in_stack_00000030;
  int in_stack_00000034;
  undefined4 uStack0000003c;
  char *in_stack_00000040;
  char *pcStack00000044;
  int in_stack_00000048;
  uint uStack00000054;
  int in_stack_0000006c;
  int in_stack_00000098;
  int in_stack_0000009c;
  int *in_stack_000000a0;
  undefined4 *in_stack_000000a8;
  
  pcVar3 = (char *)FUN_100259c0();
  pcVar4 = pcVar3;
  if (pcVar3 == (char *)0x0) {
    pcVar4 = (char *)FUN_10023dc4();
  }
  **(undefined4 **)(unaff_r9 + 0x1c) = pcVar4;
  if (((char *)0xe < in_stack_00000028) || (unaff_r4 == 0)) {
    if ((-1 < in_stack_0000006c) && ((int)in_stack_00000020 < 0xf)) {
      uVar10 = *(undefined4 *)(&DAT_1002b35c + in_stack_00000020 * 8);
      uVar5 = *(undefined4 *)(&DAT_1002b358 + in_stack_00000020 * 8);
      if (-1 < in_stack_0000009c) {
        FUN_10023bb2();
      }
      if (0 < (int)in_stack_00000028) {
        FUN_10023bb2();
      }
      if (in_stack_00000028 == (char *)0x0) {
        uVar15 = FUN_1001e9a6(uVar5,uVar10,0,0x40140000);
        iVar9 = FUN_1001ea48(in_stack_00000018,in_stack_0000001c,(int)uVar15,
                             (int)((ulonglong)uVar15 >> 0x20));
        if (iVar9 == 0) {
LAB_10023056:
          *pcVar3 = '1';
          FUN_10025a44();
          FUN_10025a44();
          pcVar3[1] = '\0';
          *in_stack_000000a0 = in_stack_00000020 + 2;
          if (in_stack_000000a8 == (undefined4 *)0x0) {
            FUN_10022e06();
            return;
          }
          *in_stack_000000a8 = pcVar3 + 1;
          FUN_10022e06();
          return;
        }
      }
LAB_1002344e:
      FUN_10025a44();
      FUN_1002306c();
      return;
    }
    if (in_stack_00000048 != 0) {
      FUN_10023e32();
    }
    uVar8 = in_stack_00000030;
    if (in_stack_00000024 == (char *)0x0) {
      if (in_stack_0000002c == 0) {
        in_stack_00000018 = FUN_10025ccc();
        pcVar4 = (char *)0x0;
        if (in_stack_00000030 != 0) goto code_r0x100235a6;
LAB_100234a4:
        pcVar6 = (char *)0x0;
        iVar9 = uVar8 + 1;
        goto LAB_1002311e;
      }
    }
    else if (unaff_r11 == (char *)0x0) {
      if (in_stack_0000002c == 0) {
        in_stack_00000018 = FUN_10025ccc();
        pcVar6 = (char *)0x0;
        pcVar4 = in_stack_00000024;
        if (in_stack_00000030 == 0) {
          iVar9 = 1;
          goto LAB_1002311e;
        }
code_r0x100235a6:
        pcVar6 = (char *)0x0;
        in_stack_00000018 = FUN_10025ea8();
        in_stack_00000030 = 0;
        if (1 < in_stack_00000098) goto LAB_100235be;
        goto LAB_10023b16;
      }
    }
    else {
      pcVar6 = in_stack_00000024;
      if ((int)unaff_r11 < (int)in_stack_00000024) {
        pcVar6 = unaff_r11;
      }
      pcVar4 = in_stack_00000024 + -(int)pcVar6;
      unaff_r11 = unaff_r11 + -(int)pcVar6;
      in_stack_00000024 = pcVar4;
      if (in_stack_0000002c == 0) {
        in_stack_00000018 = FUN_10025ccc();
        if (in_stack_00000030 != 0) {
          FUN_10023df2();
          uVar8 = extraout_r3_00;
        }
        goto LAB_100234a4;
      }
    }
    unaff_r10 = (char *)FUN_10025ea8();
    in_stack_00000018 = FUN_10025ccc();
    in_stack_0000002c = 0;
    if (in_stack_00000030 != 0) {
      FUN_10023d9c();
      in_stack_0000002c = extraout_r3;
    }
    pcVar6 = (char *)0x0;
    iVar9 = in_stack_0000002c + 1;
    pcVar4 = in_stack_00000024;
    goto LAB_1002311e;
  }
  if ((int)in_stack_00000020 < 1) {
    pcVar6 = unaff_r11;
    if (in_stack_00000020 == 0) goto LAB_10023d58;
    iVar9 = (-in_stack_00000020 & 0xf) * 8;
    uVar15 = FUN_1001e9a6(in_stack_00000018,in_stack_0000001c,*(undefined4 *)(&DAT_1002b358 + iVar9)
                          ,*(undefined4 *)(&DAT_1002b35c + iVar9));
    uVar8 = (int)-in_stack_00000020 >> 4;
    if (uVar8 != 0) {
      puVar11 = &DAT_1002b330;
      do {
        while( true ) {
          uStack0000003c = (undefined4)((ulonglong)uVar15 >> 0x20);
          uVar1 = uVar8 & 1;
          uVar8 = (int)uVar8 >> 1;
          if (uVar1 != 0) break;
          puVar11 = puVar11 + 2;
        }
        uVar5 = *puVar11;
        puVar14 = puVar11 + 1;
        puVar11 = puVar11 + 2;
        uVar15 = FUN_1001e9a6((int)uVar15,uStack0000003c,uVar5,*puVar14);
      } while (uVar8 != 0);
      FUN_100233d4();
      return;
    }
  }
  else {
    uVar8 = (int)in_stack_00000020 >> 4;
    uVar17 = *(undefined8 *)(&DAT_1002b358 + (in_stack_00000020 & 0xf) * 8);
    uVar15 = *(undefined8 *)(&DAT_1002b358 + (in_stack_00000020 & 0xf) * 8);
    if ((int)(in_stack_00000020 << 0x17) < 0) {
      uVar8 = uVar8 & 0xf;
      uVar18 = FUN_1001e96a(in_stack_00000018,in_stack_0000001c,0x7f73bf3c,0x75154fdd);
      uStack0000003c = (undefined4)((ulonglong)uVar18 >> 0x20);
      iVar9 = (int)uVar18;
      pcVar4 = (char *)0x3;
    }
    else {
      uStack0000003c = in_stack_0000001c;
      pcVar4 = (char *)0x2;
      iVar9 = in_stack_00000018;
    }
    if (uVar8 != 0) {
      puVar11 = &DAT_1002b330;
      uVar15 = uVar17;
      do {
        while( true ) {
          uVar1 = uVar8 & 1;
          uVar8 = (int)uVar8 >> 1;
          if (uVar1 != 0) break;
          puVar11 = puVar11 + 2;
        }
        uVar5 = *puVar11;
        puVar14 = puVar11 + 1;
        puVar11 = puVar11 + 2;
        pcVar4 = pcVar4 + 1;
        uVar15 = FUN_1001e9a6((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),uVar5,*puVar14);
      } while (uVar8 != 0);
    }
    uVar15 = FUN_1001e96a(iVar9,uStack0000003c,(int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
    uVar10 = (undefined4)((ulonglong)uVar15 >> 0x20);
    uVar5 = (undefined4)uVar15;
    if ((in_stack_00000034 == 0) || (iVar9 = FUN_1001ea3c(uVar5,uVar10,0,0x3ff00000), iVar9 == 0)) {
      uVar17 = FUN_1001ea84(pcVar4);
      uVar17 = FUN_1001e9a6((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar5,uVar10);
      uVar17 = FUN_1001e958((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0,0x401c0000);
      iVar9 = (int)((ulonglong)uVar17 >> 0x20);
      uVar12 = (undefined4)uVar17;
      iVar7 = iVar9 + -0x3400000;
      uStack00000054 = in_stack_00000020;
      pcStack00000044 = in_stack_00000028;
      if (in_stack_00000028 == (char *)0x0) {
        uVar15 = FUN_1001e946(uVar5,uVar10,0,0x40140000);
        uVar5 = (undefined4)((ulonglong)uVar15 >> 0x20);
        iVar7 = FUN_1001ea58((int)uVar15,uVar5,uVar12,iVar7);
        if (iVar7 != 0) goto LAB_10023056;
        iVar9 = FUN_1001ea3c((int)uVar15,uVar5,uVar12,iVar9 + 0x7cc00000);
        if (iVar9 == 0) {
          FUN_10022ff6();
          return;
        }
        goto LAB_1002344e;
      }
    }
    else {
      if (in_stack_00000028 == (char *)0x0) {
        uVar15 = FUN_1001ea84(pcVar4);
        uVar15 = FUN_1001e9a6((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),uVar5,uVar10);
        FUN_1001e958((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),0,0x401c0000);
        unaff_r7 = (char *)(extraout_r1 + -0x3400000);
        FUN_1002341a();
        pcVar6 = (char *)0x0;
        uVar16 = FUN_100235a6();
        goto LAB_10023dfa;
      }
      if ((int)in_stack_00000040 < 1) {
        FUN_10022ff6();
      }
      uStack00000054 = in_stack_00000020 - 1;
      uVar15 = FUN_1001e9a6(uVar5,uVar10,0,0x40240000);
      uVar17 = FUN_1001ea84(pcVar4 + 1);
      uVar17 = FUN_1001e9a6((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar15,
                            (int)((ulonglong)uVar15 >> 0x20));
      uVar17 = FUN_1001e958((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),0,0x401c0000);
      uVar12 = (undefined4)uVar17;
      iVar7 = (int)((ulonglong)uVar17 >> 0x20) + -0x3400000;
      pcStack00000044 = in_stack_00000040;
    }
    uStack0000003c = (undefined4)((ulonglong)uVar15 >> 0x20);
    uVar5 = *(undefined4 *)(&DAT_1002b35c + (int)(pcStack00000044 + -1) * 8);
    pcVar6 = *(char **)(&DAT_1002b358 + (int)(pcStack00000044 + -1) * 8);
    cVar2 = FUN_1001eab4((int)uVar15,uStack0000003c);
    uVar17 = FUN_1001ea84();
    uVar15 = FUN_1001e946((int)uVar15,uStack0000003c,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
    pcVar4 = pcVar3 + 1;
    if (in_stack_00000048 == 0) {
      uVar17 = FUN_1001e9a6(pcVar6,uVar5,uVar12,iVar7);
      uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
      *pcVar3 = cVar2 + '0';
      unaff_r6 = pcStack00000044 + (int)pcVar3;
      pcVar13 = pcVar4;
      if (pcStack00000044 != (char *)0x1) {
        unaff_r6 = pcVar4;
        do {
          uVar15 = FUN_1001e9a6((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),0,0x40240000);
          cVar2 = FUN_1001eab4();
          uVar18 = FUN_1001ea84();
          uVar15 = FUN_1001e946((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),(int)uVar18,
                                (int)((ulonglong)uVar18 >> 0x20));
          *unaff_r6 = cVar2 + '0';
          unaff_r6 = unaff_r6 + 1;
        } while (pcStack00000044 + (int)pcVar3 != unaff_r6);
        pcVar13 = pcVar3 + (int)pcStack00000044;
      }
      unaff_r5 = (char *)((ulonglong)uVar15 >> 0x20);
      uVar10 = (undefined4)uVar15;
      uVar15 = FUN_1001e958((int)uVar17,uVar5,0,0x3fe00000);
      iVar9 = FUN_1001ea3c((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),uVar10,unaff_r5);
      pcVar6 = unaff_r11;
      if (iVar9 != 0) {
LAB_100239ec:
        while( true ) {
          unaff_r7 = pcVar13 + -1;
          if (*unaff_r7 != '9') break;
          pcVar13 = unaff_r7;
          if (unaff_r7 == pcVar3) goto LAB_10023d68;
        }
        cVar2 = *unaff_r7 + '\x01';
        goto LAB_100239fa;
      }
      uVar15 = FUN_1001e946(0,0x3fe00000,(int)uVar17,uVar5);
      iVar9 = FUN_1001ea58((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),uVar10,unaff_r5);
      if (iVar9 != 0) {
        do {
          pcVar13 = pcVar13 + -1;
        } while (*pcVar13 == '0');
        uVar17 = FUN_1002306c();
        uVar15 = CONCAT44((int)((ulonglong)uVar17 >> 0x20),uVar10);
        uVar5 = (undefined4)uVar17;
        unaff_r7 = unaff_r10;
        goto LAB_10023d1e;
      }
      if ((-1 < in_stack_0000006c) && ((int)in_stack_00000020 < 0xf)) {
        in_stack_00000014 = *(uint *)(&DAT_1002b35c + in_stack_00000020 * 8);
        in_stack_00000010 = *(uint *)(&DAT_1002b358 + in_stack_00000020 * 8);
        FUN_1001e96a(in_stack_00000018,in_stack_0000001c,in_stack_00000010,in_stack_00000014);
        iVar9 = FUN_1001eab4();
        uVar15 = FUN_1001ea84();
        uVar15 = FUN_1001e9a6((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),in_stack_00000010,
                              in_stack_00000014);
        uVar15 = FUN_1001e946(in_stack_00000018,in_stack_0000001c,(int)uVar15,
                              (int)((ulonglong)uVar15 >> 0x20));
        *pcVar3 = (char)iVar9 + '0';
        if (in_stack_00000028 != (char *)0x1) {
          unaff_r11 = pcVar3 + -1;
          pcVar6 = (char *)0x1;
          do {
            uVar15 = FUN_1001e9a6((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),0,0x40240000);
            uVar10 = (undefined4)((ulonglong)uVar15 >> 0x20);
            uVar5 = (undefined4)uVar15;
            iVar9 = FUN_1001ea2c(uVar5,uVar10,0,0);
            if (iVar9 != 0) {
              FUN_1002306c();
              return;
            }
            FUN_1001e96a(uVar5,uVar10,in_stack_00000010,in_stack_00000014);
            iVar9 = FUN_1001eab4();
            uVar15 = FUN_1001ea84();
            uVar15 = FUN_1001e9a6((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),in_stack_00000010,
                                  in_stack_00000014);
            uVar15 = FUN_1001e946(uVar5,uVar10,(int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
            pcVar6 = pcVar6 + 1;
            unaff_r11[(int)pcVar6] = (char)iVar9 + '0';
            pcVar4 = pcVar4 + 1;
          } while (in_stack_00000028 != pcVar6);
        }
        uVar5 = (undefined4)((ulonglong)uVar15 >> 0x20);
        uVar15 = FUN_1001e958((int)uVar15,uVar5,(int)uVar15,uVar5);
        unaff_r5 = (char *)((ulonglong)uVar15 >> 0x20);
        iVar7 = FUN_1001ea58((int)uVar15,unaff_r5,in_stack_00000010,in_stack_00000014);
        pcVar13 = pcVar4;
        pcVar6 = unaff_r11;
        if ((iVar7 == 0) &&
           ((iVar7 = FUN_1001ea2c((int)uVar15,unaff_r5,in_stack_00000010,in_stack_00000014),
            iVar7 == 0 || (-1 < iVar9 << 0x1f)))) {
          FUN_1002306c();
          FUN_100235a6();
          return;
        }
        goto LAB_100239ec;
      }
    }
    else {
      uVar17 = FUN_1001e96a(0,0x3fe00000,pcVar6,uVar5);
      uVar17 = FUN_1001e946((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar12,iVar7);
      *pcVar3 = cVar2 + '0';
      iVar9 = FUN_1001ea58((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar15,
                           (int)((ulonglong)uVar15 >> 0x20));
      pcVar13 = pcVar4;
      if (iVar9 == 0) {
        iVar9 = 0;
        do {
          uVar5 = (undefined4)((ulonglong)uVar17 >> 0x20);
          unaff_r5 = (char *)((ulonglong)uVar15 >> 0x20);
          uVar18 = FUN_1001e946(0,0x3ff00000,(int)uVar15,unaff_r5);
          iVar7 = FUN_1001ea3c((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,uVar5);
          pcVar13 = pcVar4;
          pcVar6 = pcVar4;
          if (iVar7 != 0) goto LAB_100239ec;
          iVar9 = iVar9 + 1;
          pcVar6 = unaff_r11;
          if ((int)pcStack00000044 <= iVar9) goto LAB_10023e1a;
          uVar17 = FUN_1001e9a6((int)uVar17,uVar5,0,0x40240000);
          uVar15 = FUN_1001e9a6((int)uVar15,unaff_r5,0,0x40240000);
          cVar2 = FUN_1001eab4();
          uVar18 = FUN_1001ea84();
          uVar15 = FUN_1001e946((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),(int)uVar18,
                                (int)((ulonglong)uVar18 >> 0x20));
          pcVar3[iVar9] = cVar2 + '0';
          pcVar4 = pcVar4 + 1;
          iVar7 = FUN_1001ea3c((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),(int)uVar17,
                               (int)((ulonglong)uVar17 >> 0x20));
          pcVar13 = unaff_r10;
        } while (iVar7 == 0);
      }
      in_stack_00000020 = uStack00000054 + 1;
      FUN_1002306c();
      unaff_r10 = pcVar13;
LAB_10023e1a:
      if ((-1 < in_stack_0000006c) && ((int)in_stack_00000020 < 0xf)) {
        FUN_1002300a();
      }
      unaff_r5 = in_stack_00000028 + -1;
      iVar9 = in_stack_0000002c;
      if ((int)unaff_r5 <= in_stack_0000002c) {
LAB_10023a14:
        unaff_r5 = (char *)(iVar9 - (int)unaff_r5);
        if ((int)in_stack_00000028 < 0) {
          uVar15 = FUN_10025ccc();
          pcVar13 = in_stack_00000024;
          unaff_r11 = pcVar6;
          in_stack_00000024 = in_stack_00000024 + -(int)in_stack_00000028;
        }
        else {
          pcVar13 = in_stack_00000024 + (int)in_stack_00000028;
          unaff_r11 = pcVar6 + (int)in_stack_00000028;
          uVar15 = FUN_10025ccc();
          pcVar6 = (char *)uVar15;
          if (in_stack_00000024 == (char *)0x0) {
            if (in_stack_0000002c != 0) {
              if (unaff_r5 != (char *)0x0) {
                FUN_10023c1c();
              }
              unaff_r10 = (char *)FUN_10025ea8();
              in_stack_00000018 = FUN_10025ccc();
              if (in_stack_00000030 != 0) {
                FUN_10023bac();
              }
              pcVar4 = (char *)0x0;
              if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) &&
                  ((in_stack_00000014 & 0xfffff) == 0)) && ((in_stack_00000014 & 0x7ff00000) != 0))
              {
                in_stack_00000024 = pcVar13 + 1;
                iVar9 = 1;
                in_stack_0000002c = 1;
                unaff_r11 = unaff_r11 + 1;
                in_stack_00000030 = 1;
              }
              else {
                iVar9 = 1;
                in_stack_0000002c = 1;
                in_stack_00000024 = pcVar13;
              }
LAB_1002311e:
              do {
                uVar8 = (uint)(unaff_r11 + iVar9) & 0x1f;
                if (((uint)(unaff_r11 + iVar9) & 0x1f) == 0) {
                  iVar9 = 0x1c;
LAB_1002313a:
                  pcVar4 = pcVar4 + iVar9;
                  in_stack_00000024 = in_stack_00000024 + iVar9;
                  unaff_r11 = unaff_r11 + iVar9;
                }
                else {
                  if (4 < (int)(0x20 - uVar8)) {
                    iVar9 = 0x1c - uVar8;
                    goto LAB_1002313a;
                  }
                  if (0x20 - uVar8 != 4) {
                    iVar9 = 0x3c - uVar8;
                    goto LAB_1002313a;
                  }
                }
                if (0 < (int)in_stack_00000024) {
                  unaff_r10 = (char *)FUN_10025fb4();
                }
                if (0 < (int)unaff_r11) {
                  in_stack_00000018 = FUN_10025fb4();
                }
                if ((in_stack_00000034 == 0) ||
                   (iVar9 = FUN_100260a8(unaff_r10,in_stack_00000018), -1 < iVar9)) {
                  if ((0 < (int)in_stack_00000028) || (in_stack_00000098 < 3)) goto LAB_1002317c;
                }
                else {
                  unaff_r10 = (char *)FUN_10025a90();
                  if (in_stack_0000002c == 0) {
                    in_stack_00000028 = in_stack_00000040;
                    if ((0 < (int)in_stack_00000040) || (in_stack_00000098 < 3)) goto LAB_1002318a;
                  }
                  else {
                    pcVar6 = (char *)FUN_10025a90();
                    in_stack_00000028 = in_stack_00000040;
                    if ((0 < (int)in_stack_00000040) || (in_stack_00000098 < 3)) goto LAB_1002366c;
                  }
                }
                if (in_stack_00000028 == (char *)0x0) {
                  in_stack_00000018 = FUN_10025a90();
                  iVar9 = FUN_100260a8(unaff_r10,in_stack_00000018);
                  if (0 < iVar9) {
                    *pcVar3 = '1';
                    FUN_10025a44();
                    if (pcVar6 == (char *)0x0) {
                      FUN_1002306c();
                      return;
                    }
                    FUN_1002322c();
                    return;
                  }
                }
                FUN_10025a44();
                if (pcVar6 != (char *)0x0) {
                  FUN_1002322c();
                }
                FUN_1002306c();
                pcVar4 = pcVar3;
LAB_10023b16:
                if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
                   ((in_stack_00000014 & 0x7ff00000) != 0)) {
                  in_stack_00000024 = in_stack_00000024 + 1;
                  in_stack_00000030 = 1;
                  unaff_r11 = unaff_r11 + 1;
                }
LAB_100235be:
                iVar9 = FUN_10025bdc(*(undefined4 *)
                                      (*(int *)(in_stack_00000018 + 0x10) * 4 + in_stack_00000018 +
                                      0x10));
                iVar9 = 0x20 - iVar9;
              } while( true );
            }
            goto LAB_10023a42;
          }
        }
        uVar5 = (undefined4)uVar15;
        unaff_r7 = unaff_r10;
        if ((int)unaff_r11 < 1) {
          if (in_stack_0000002c != 0) {
            FUN_1002329e();
            return;
          }
LAB_10023a42:
          FUN_100232b4();
          return;
        }
LAB_10023d1e:
        pcVar6 = (char *)uVar15;
        pcVar4 = in_stack_00000024;
        if ((int)unaff_r11 < (int)in_stack_00000024) {
          pcVar4 = unaff_r11;
        }
        unaff_r10 = in_stack_00000024 + -(int)pcVar4;
        if (in_stack_0000002c != 0) {
          FUN_1002329e(uVar5,(int)((ulonglong)uVar15 >> 0x20),unaff_r11);
        }
        FUN_100232b4();
        in_stack_00000024 = pcVar13 + -(int)pcVar4;
        goto LAB_10023d44;
      }
      FUN_10025ccc();
      if (in_stack_00000024 == (char *)0x0) {
        FUN_100232a6();
      }
      pcVar4 = in_stack_00000024;
      if ((int)(pcVar6 + (int)in_stack_00000028) < (int)in_stack_00000024) {
        pcVar4 = pcVar6 + (int)in_stack_00000028;
      }
      unaff_r6 = in_stack_00000024 + -(int)pcVar4;
      FUN_100232a6();
    }
    FUN_100230e6();
  }
  FUN_100233d4();
  unaff_r6[4] = '\0';
  unaff_r6[5] = '\0';
  unaff_r6[6] = '\0';
  unaff_r6[7] = '\0';
  FUN_10022fd4();
                    /* WARNING: Subroutine does not return */
  FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0xef,0,"REENT malloc succeeded");
LAB_1002317c:
  if (in_stack_0000002c == 0) {
LAB_1002318a:
    iVar9 = 1;
    while( true ) {
      iVar7 = FUN_10022c2c(unaff_r10,in_stack_00000018);
      pcVar3[iVar9 + -1] = (char)iVar7 + '0';
      if ((int)in_stack_00000028 <= iVar9) break;
      unaff_r10 = (char *)FUN_10025a90();
      iVar9 = iVar9 + 1;
    }
    pcVar4 = (char *)0x0;
    if (0 < (int)in_stack_00000028) {
      pcVar4 = in_stack_00000028 + -1;
    }
    pcVar4 = pcVar4 + (int)(pcVar3 + 1);
    uVar5 = FUN_10025fb4();
    uVar15 = FUN_100260a8(uVar5,in_stack_00000018);
    iVar9 = (int)uVar15;
    if ((0 < iVar9) || ((iVar9 == 0 && (iVar7 << 0x1f < 0)))) {
      FUN_100231fe(iVar9,(int)((ulonglong)uVar15 >> 0x20),pcVar3);
      return;
    }
    do {
      pcVar4 = pcVar4 + -1;
    } while (*pcVar4 == '0');
    FUN_1002320c();
    return;
  }
LAB_1002366c:
  if (0 < (int)pcVar4) {
    pcVar6 = (char *)FUN_10025fb4();
  }
  pcVar4 = pcVar6;
  if (in_stack_00000030 != 0) {
    iVar9 = FUN_100259c0();
    if (iVar9 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded");
    }
    FUN_1001f4d4(iVar9 + 0xc,pcVar6 + 0xc,(*(int *)(pcVar6 + 0x10) + 2) * 4);
    pcVar4 = (char *)FUN_10025fb4();
  }
  in_stack_00000028 = in_stack_00000028 + (int)(pcVar3 + -1);
  in_stack_00000030 = in_stack_00000010 & 1;
  unaff_r11 = pcVar3;
LAB_100236a2:
  in_stack_0000002c = FUN_10022c2c(unaff_r10,in_stack_00000018);
  unaff_r7 = (char *)(in_stack_0000002c + 0x30);
  iVar9 = FUN_100260a8(unaff_r10,pcVar6);
  iVar7 = FUN_100260e4();
  pcVar13 = pcVar6;
  if (*(int *)(iVar7 + 0xc) != 0) {
    uVar16 = FUN_10025a44();
    if (iVar9 < 0) goto LAB_10023762;
    if ((in_stack_00000010 & 1) == 0 && (iVar9 == 0 && in_stack_00000098 == 0)) goto LAB_10023762;
LAB_100237c2:
    pcVar6 = pcVar4;
    if (unaff_r7 != (char *)0x39) {
      *unaff_r11 = (char)in_stack_0000002c + '1';
      FUN_1002320c();
      return;
    }
    goto LAB_10023d72;
  }
  in_stack_00000024 = (char *)FUN_100260a8(unaff_r10,iVar7);
  uVar16 = FUN_10025a44();
  if (in_stack_00000024 == (char *)0x0 && in_stack_00000098 == 0) {
    if (in_stack_00000030 == 0) {
      pcVar6 = pcVar4;
      if (unaff_r7 == (char *)0x39) goto LAB_10023d72;
      if (0 < iVar9) goto LAB_10023780;
      goto LAB_10023784;
    }
    if (iVar9 < 0) goto LAB_10023784;
  }
  else {
    if (iVar9 < 0) goto LAB_10023d8c;
    if ((iVar9 == 0 && in_stack_00000098 == 0) && in_stack_00000030 == 0) goto LAB_10023d8c;
    if (0 < (int)in_stack_00000024) goto LAB_100237c2;
  }
  unaff_r5 = unaff_r11 + 1;
  *unaff_r11 = (char)unaff_r7;
  if (unaff_r11 != in_stack_00000028) {
    unaff_r10 = (char *)FUN_10025a90();
    unaff_r11 = unaff_r5;
    if (pcVar6 == pcVar4) {
      pcVar6 = (char *)FUN_10025a90();
      pcVar4 = pcVar6;
    }
    else {
      pcVar6 = (char *)FUN_10025a90();
      pcVar4 = (char *)FUN_10025a90();
    }
    goto LAB_100236a2;
  }
LAB_10023d44:
  FUN_100231da();
LAB_10023d58:
  FUN_100233d4();
LAB_10023d68:
  cVar2 = '1';
LAB_100239fa:
  *unaff_r7 = cVar2;
  FUN_1002306c();
  *pcVar3 = '1';
  FUN_1002320c();
  iVar9 = extraout_r3_01;
  goto LAB_10023a14;
LAB_10023d72:
  *unaff_r11 = '9';
  FUN_100231fe((int)uVar16,(int)(uVar16 >> 0x20),pcVar3);
  pcVar4 = unaff_r7;
  unaff_r7 = unaff_r10;
  unaff_r11 = pcVar13;
LAB_10023d8c:
  if ((int)in_stack_00000024 < 1) goto LAB_10023784;
LAB_10023762:
  unaff_r10 = (char *)FUN_10025fb4();
  uVar16 = FUN_100260a8(unaff_r10,in_stack_00000018);
  if ((int)uVar16 < 1) {
LAB_10023dfa:
    if (((int)uVar16 != 0) || (-1 < (int)unaff_r7 << 0x1f)) goto LAB_10023784;
    uVar16 = uVar16 & 0xffffffff00000000;
  }
  if (unaff_r7 != (char *)0x39) {
LAB_10023780:
    unaff_r7 = (char *)(in_stack_0000002c + 0x31);
LAB_10023784:
    *unaff_r11 = (char)unaff_r7;
    FUN_1002320c();
    return;
  }
  unaff_r7 = (char *)0x39;
  pcVar13 = pcVar6;
  pcVar6 = pcVar4;
  goto LAB_10023d72;
}



/* FUN_10022ff0 at 10022ff0 */

void FUN_10022ff0(void)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  int extraout_r1;
  int extraout_r3;
  uint extraout_r3_00;
  int iVar7;
  int extraout_r3_01;
  int unaff_r4;
  undefined4 uVar8;
  char *unaff_r5;
  undefined4 *puVar9;
  char *unaff_r6;
  char *pcVar10;
  undefined4 uVar11;
  char *unaff_r7;
  char *pcVar12;
  char *unaff_r10;
  char *unaff_r11;
  undefined4 *puVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  char *in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  uint in_stack_00000020;
  char *in_stack_00000024;
  char *in_stack_00000028;
  int in_stack_0000002c;
  uint in_stack_00000030;
  int in_stack_00000034;
  undefined4 uStack0000003c;
  char *in_stack_00000040;
  char *pcStack00000044;
  int in_stack_00000048;
  uint uStack00000054;
  int in_stack_0000006c;
  int in_stack_00000098;
  int in_stack_0000009c;
  int *in_stack_000000a0;
  undefined4 *in_stack_000000a8;
  
  if (unaff_r4 == 0) {
    if ((-1 < in_stack_0000006c) && ((int)in_stack_00000020 < 0xf)) {
      uVar8 = *(undefined4 *)(&DAT_1002b35c + in_stack_00000020 * 8);
      uVar3 = *(undefined4 *)(&DAT_1002b358 + in_stack_00000020 * 8);
      if (-1 < in_stack_0000009c) {
        FUN_10023bb2();
      }
      if (0 < (int)in_stack_00000028) {
        FUN_10023bb2();
      }
      if (in_stack_00000028 == (char *)0x0) {
        uVar14 = FUN_1001e9a6(uVar3,uVar8,0,0x40140000);
        iVar7 = FUN_1001ea48(in_stack_00000018,in_stack_0000001c,(int)uVar14,
                             (int)((ulonglong)uVar14 >> 0x20));
        if (iVar7 == 0) {
LAB_10023056:
          *in_stack_0000000c = '1';
          FUN_10025a44();
          FUN_10025a44();
          in_stack_0000000c[1] = '\0';
          *in_stack_000000a0 = in_stack_00000020 + 2;
          if (in_stack_000000a8 == (undefined4 *)0x0) {
            FUN_10022e06();
            return;
          }
          *in_stack_000000a8 = in_stack_0000000c + 1;
          FUN_10022e06();
          return;
        }
      }
LAB_1002344e:
      FUN_10025a44();
      FUN_1002306c();
      return;
    }
    if (in_stack_00000048 != 0) {
      FUN_10023e32();
    }
    uVar6 = in_stack_00000030;
    if (in_stack_00000024 == (char *)0x0) {
      if (in_stack_0000002c == 0) {
        in_stack_00000018 = FUN_10025ccc();
        pcVar10 = (char *)0x0;
        if (in_stack_00000030 != 0) goto code_r0x100235a6;
LAB_100234a4:
        pcVar4 = (char *)0x0;
        iVar7 = uVar6 + 1;
        goto LAB_1002311e;
      }
    }
    else if (unaff_r11 == (char *)0x0) {
      if (in_stack_0000002c == 0) {
        in_stack_00000018 = FUN_10025ccc();
        pcVar4 = (char *)0x0;
        pcVar10 = in_stack_00000024;
        if (in_stack_00000030 == 0) {
          iVar7 = 1;
          goto LAB_1002311e;
        }
code_r0x100235a6:
        pcVar4 = (char *)0x0;
        in_stack_00000018 = FUN_10025ea8();
        in_stack_00000030 = 0;
        if (1 < in_stack_00000098) goto LAB_100235be;
        goto LAB_10023b16;
      }
    }
    else {
      pcVar4 = in_stack_00000024;
      if ((int)unaff_r11 < (int)in_stack_00000024) {
        pcVar4 = unaff_r11;
      }
      pcVar10 = in_stack_00000024 + -(int)pcVar4;
      unaff_r11 = unaff_r11 + -(int)pcVar4;
      in_stack_00000024 = pcVar10;
      if (in_stack_0000002c == 0) {
        in_stack_00000018 = FUN_10025ccc();
        if (in_stack_00000030 != 0) {
          FUN_10023df2();
          uVar6 = extraout_r3_00;
        }
        goto LAB_100234a4;
      }
    }
    unaff_r10 = (char *)FUN_10025ea8();
    in_stack_00000018 = FUN_10025ccc();
    in_stack_0000002c = 0;
    if (in_stack_00000030 != 0) {
      FUN_10023d9c();
      in_stack_0000002c = extraout_r3;
    }
    pcVar4 = (char *)0x0;
    iVar7 = in_stack_0000002c + 1;
    pcVar10 = in_stack_00000024;
    goto LAB_1002311e;
  }
  if ((int)in_stack_00000020 < 1) {
    pcVar4 = unaff_r11;
    if (in_stack_00000020 == 0) goto LAB_10023d58;
    iVar7 = (-in_stack_00000020 & 0xf) * 8;
    uVar14 = FUN_1001e9a6(in_stack_00000018,in_stack_0000001c,*(undefined4 *)(&DAT_1002b358 + iVar7)
                          ,*(undefined4 *)(&DAT_1002b35c + iVar7));
    uVar6 = (int)-in_stack_00000020 >> 4;
    if (uVar6 != 0) {
      puVar9 = &DAT_1002b330;
      do {
        while( true ) {
          uStack0000003c = (undefined4)((ulonglong)uVar14 >> 0x20);
          uVar1 = uVar6 & 1;
          uVar6 = (int)uVar6 >> 1;
          if (uVar1 != 0) break;
          puVar9 = puVar9 + 2;
        }
        uVar3 = *puVar9;
        puVar13 = puVar9 + 1;
        puVar9 = puVar9 + 2;
        uVar14 = FUN_1001e9a6((int)uVar14,uStack0000003c,uVar3,*puVar13);
      } while (uVar6 != 0);
      FUN_100233d4();
      return;
    }
  }
  else {
    uVar6 = (int)in_stack_00000020 >> 4;
    uVar16 = *(undefined8 *)(&DAT_1002b358 + (in_stack_00000020 & 0xf) * 8);
    uVar14 = *(undefined8 *)(&DAT_1002b358 + (in_stack_00000020 & 0xf) * 8);
    if ((int)(in_stack_00000020 << 0x17) < 0) {
      uVar6 = uVar6 & 0xf;
      uVar17 = FUN_1001e96a(in_stack_00000018,in_stack_0000001c,0x7f73bf3c,0x75154fdd);
      uStack0000003c = (undefined4)((ulonglong)uVar17 >> 0x20);
      iVar7 = (int)uVar17;
      pcVar10 = (char *)0x3;
    }
    else {
      uStack0000003c = in_stack_0000001c;
      pcVar10 = (char *)0x2;
      iVar7 = in_stack_00000018;
    }
    if (uVar6 != 0) {
      puVar9 = &DAT_1002b330;
      uVar14 = uVar16;
      do {
        while( true ) {
          uVar1 = uVar6 & 1;
          uVar6 = (int)uVar6 >> 1;
          if (uVar1 != 0) break;
          puVar9 = puVar9 + 2;
        }
        uVar3 = *puVar9;
        puVar13 = puVar9 + 1;
        puVar9 = puVar9 + 2;
        pcVar10 = pcVar10 + 1;
        uVar14 = FUN_1001e9a6((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),uVar3,*puVar13);
      } while (uVar6 != 0);
    }
    uVar14 = FUN_1001e96a(iVar7,uStack0000003c,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
    uVar8 = (undefined4)((ulonglong)uVar14 >> 0x20);
    uVar3 = (undefined4)uVar14;
    if ((in_stack_00000034 == 0) || (iVar7 = FUN_1001ea3c(uVar3,uVar8,0,0x3ff00000), iVar7 == 0)) {
      uVar16 = FUN_1001ea84(pcVar10);
      uVar16 = FUN_1001e9a6((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar3,uVar8);
      uVar16 = FUN_1001e958((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),0,0x401c0000);
      iVar7 = (int)((ulonglong)uVar16 >> 0x20);
      uVar11 = (undefined4)uVar16;
      iVar5 = iVar7 + -0x3400000;
      uStack00000054 = in_stack_00000020;
      pcStack00000044 = in_stack_00000028;
      if (in_stack_00000028 == (char *)0x0) {
        uVar14 = FUN_1001e946(uVar3,uVar8,0,0x40140000);
        uVar3 = (undefined4)((ulonglong)uVar14 >> 0x20);
        iVar5 = FUN_1001ea58((int)uVar14,uVar3,uVar11,iVar5);
        if (iVar5 != 0) goto LAB_10023056;
        iVar7 = FUN_1001ea3c((int)uVar14,uVar3,uVar11,iVar7 + 0x7cc00000);
        if (iVar7 == 0) {
          FUN_10022ff6();
          return;
        }
        goto LAB_1002344e;
      }
    }
    else {
      if (in_stack_00000028 == (char *)0x0) {
        uVar14 = FUN_1001ea84(pcVar10);
        uVar14 = FUN_1001e9a6((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),uVar3,uVar8);
        FUN_1001e958((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0x401c0000);
        unaff_r7 = (char *)(extraout_r1 + -0x3400000);
        FUN_1002341a();
        pcVar4 = (char *)0x0;
        uVar15 = FUN_100235a6();
        goto LAB_10023dfa;
      }
      if ((int)in_stack_00000040 < 1) {
        FUN_10022ff6();
      }
      uStack00000054 = in_stack_00000020 - 1;
      uVar14 = FUN_1001e9a6(uVar3,uVar8,0,0x40240000);
      uVar16 = FUN_1001ea84(pcVar10 + 1);
      uVar16 = FUN_1001e9a6((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar14,
                            (int)((ulonglong)uVar14 >> 0x20));
      uVar16 = FUN_1001e958((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),0,0x401c0000);
      uVar11 = (undefined4)uVar16;
      iVar5 = (int)((ulonglong)uVar16 >> 0x20) + -0x3400000;
      pcStack00000044 = in_stack_00000040;
    }
    uStack0000003c = (undefined4)((ulonglong)uVar14 >> 0x20);
    uVar3 = *(undefined4 *)(&DAT_1002b35c + (int)(pcStack00000044 + -1) * 8);
    pcVar4 = *(char **)(&DAT_1002b358 + (int)(pcStack00000044 + -1) * 8);
    cVar2 = FUN_1001eab4((int)uVar14,uStack0000003c);
    uVar16 = FUN_1001ea84();
    uVar14 = FUN_1001e946((int)uVar14,uStack0000003c,(int)uVar16,(int)((ulonglong)uVar16 >> 0x20));
    pcVar10 = in_stack_0000000c + 1;
    if (in_stack_00000048 == 0) {
      uVar16 = FUN_1001e9a6(pcVar4,uVar3,uVar11,iVar5);
      uVar3 = (undefined4)((ulonglong)uVar16 >> 0x20);
      *in_stack_0000000c = cVar2 + '0';
      unaff_r6 = pcStack00000044 + (int)in_stack_0000000c;
      pcVar12 = pcVar10;
      if (pcStack00000044 != (char *)0x1) {
        unaff_r6 = pcVar10;
        do {
          uVar14 = FUN_1001e9a6((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0x40240000);
          cVar2 = FUN_1001eab4();
          uVar17 = FUN_1001ea84();
          uVar14 = FUN_1001e946((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(int)uVar17,
                                (int)((ulonglong)uVar17 >> 0x20));
          *unaff_r6 = cVar2 + '0';
          unaff_r6 = unaff_r6 + 1;
        } while (pcStack00000044 + (int)in_stack_0000000c != unaff_r6);
        pcVar12 = in_stack_0000000c + (int)pcStack00000044;
      }
      unaff_r5 = (char *)((ulonglong)uVar14 >> 0x20);
      uVar8 = (undefined4)uVar14;
      uVar14 = FUN_1001e958((int)uVar16,uVar3,0,0x3fe00000);
      iVar7 = FUN_1001ea3c((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),uVar8,unaff_r5);
      pcVar4 = unaff_r11;
      if (iVar7 != 0) {
LAB_100239ec:
        while( true ) {
          unaff_r7 = pcVar12 + -1;
          if (*unaff_r7 != '9') break;
          pcVar12 = unaff_r7;
          if (unaff_r7 == in_stack_0000000c) goto LAB_10023d68;
        }
        cVar2 = *unaff_r7 + '\x01';
        goto LAB_100239fa;
      }
      uVar14 = FUN_1001e946(0,0x3fe00000,(int)uVar16,uVar3);
      iVar7 = FUN_1001ea58((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),uVar8,unaff_r5);
      if (iVar7 != 0) {
        do {
          pcVar12 = pcVar12 + -1;
        } while (*pcVar12 == '0');
        uVar16 = FUN_1002306c();
        uVar14 = CONCAT44((int)((ulonglong)uVar16 >> 0x20),uVar8);
        uVar3 = (undefined4)uVar16;
        unaff_r7 = unaff_r10;
        goto LAB_10023d1e;
      }
      if ((-1 < in_stack_0000006c) && ((int)in_stack_00000020 < 0xf)) {
        in_stack_00000014 = *(uint *)(&DAT_1002b35c + in_stack_00000020 * 8);
        in_stack_00000010 = *(uint *)(&DAT_1002b358 + in_stack_00000020 * 8);
        FUN_1001e96a(in_stack_00000018,in_stack_0000001c,in_stack_00000010,in_stack_00000014);
        iVar7 = FUN_1001eab4();
        uVar14 = FUN_1001ea84();
        uVar14 = FUN_1001e9a6((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),in_stack_00000010,
                              in_stack_00000014);
        uVar14 = FUN_1001e946(in_stack_00000018,in_stack_0000001c,(int)uVar14,
                              (int)((ulonglong)uVar14 >> 0x20));
        *in_stack_0000000c = (char)iVar7 + '0';
        if (in_stack_00000028 != (char *)0x1) {
          unaff_r11 = in_stack_0000000c + -1;
          pcVar4 = (char *)0x1;
          do {
            uVar14 = FUN_1001e9a6((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0x40240000);
            uVar8 = (undefined4)((ulonglong)uVar14 >> 0x20);
            uVar3 = (undefined4)uVar14;
            iVar7 = FUN_1001ea2c(uVar3,uVar8,0,0);
            if (iVar7 != 0) {
              FUN_1002306c();
              return;
            }
            FUN_1001e96a(uVar3,uVar8,in_stack_00000010,in_stack_00000014);
            iVar7 = FUN_1001eab4();
            uVar14 = FUN_1001ea84();
            uVar14 = FUN_1001e9a6((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),in_stack_00000010,
                                  in_stack_00000014);
            uVar14 = FUN_1001e946(uVar3,uVar8,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
            pcVar4 = pcVar4 + 1;
            unaff_r11[(int)pcVar4] = (char)iVar7 + '0';
            pcVar10 = pcVar10 + 1;
          } while (in_stack_00000028 != pcVar4);
        }
        uVar3 = (undefined4)((ulonglong)uVar14 >> 0x20);
        uVar14 = FUN_1001e958((int)uVar14,uVar3,(int)uVar14,uVar3);
        unaff_r5 = (char *)((ulonglong)uVar14 >> 0x20);
        iVar5 = FUN_1001ea58((int)uVar14,unaff_r5,in_stack_00000010,in_stack_00000014);
        pcVar12 = pcVar10;
        pcVar4 = unaff_r11;
        if ((iVar5 == 0) &&
           ((iVar5 = FUN_1001ea2c((int)uVar14,unaff_r5,in_stack_00000010,in_stack_00000014),
            iVar5 == 0 || (-1 < iVar7 << 0x1f)))) {
          FUN_1002306c();
          FUN_100235a6();
          return;
        }
        goto LAB_100239ec;
      }
    }
    else {
      uVar16 = FUN_1001e96a(0,0x3fe00000,pcVar4,uVar3);
      uVar16 = FUN_1001e946((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar11,iVar5);
      *in_stack_0000000c = cVar2 + '0';
      iVar7 = FUN_1001ea58((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar14,
                           (int)((ulonglong)uVar14 >> 0x20));
      pcVar12 = pcVar10;
      if (iVar7 == 0) {
        iVar7 = 0;
        do {
          uVar3 = (undefined4)((ulonglong)uVar16 >> 0x20);
          unaff_r5 = (char *)((ulonglong)uVar14 >> 0x20);
          uVar17 = FUN_1001e946(0,0x3ff00000,(int)uVar14,unaff_r5);
          iVar5 = FUN_1001ea3c((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar16,uVar3);
          pcVar12 = pcVar10;
          pcVar4 = pcVar10;
          if (iVar5 != 0) goto LAB_100239ec;
          iVar7 = iVar7 + 1;
          pcVar4 = unaff_r11;
          if ((int)pcStack00000044 <= iVar7) goto LAB_10023e1a;
          uVar16 = FUN_1001e9a6((int)uVar16,uVar3,0,0x40240000);
          uVar14 = FUN_1001e9a6((int)uVar14,unaff_r5,0,0x40240000);
          cVar2 = FUN_1001eab4();
          uVar17 = FUN_1001ea84();
          uVar14 = FUN_1001e946((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(int)uVar17,
                                (int)((ulonglong)uVar17 >> 0x20));
          in_stack_0000000c[iVar7] = cVar2 + '0';
          pcVar10 = pcVar10 + 1;
          iVar5 = FUN_1001ea3c((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(int)uVar16,
                               (int)((ulonglong)uVar16 >> 0x20));
          pcVar12 = unaff_r10;
        } while (iVar5 == 0);
      }
      in_stack_00000020 = uStack00000054 + 1;
      FUN_1002306c();
      unaff_r10 = pcVar12;
LAB_10023e1a:
      if ((-1 < in_stack_0000006c) && ((int)in_stack_00000020 < 0xf)) {
        FUN_1002300a();
      }
      unaff_r5 = in_stack_00000028 + -1;
      iVar7 = in_stack_0000002c;
      if ((int)unaff_r5 <= in_stack_0000002c) {
LAB_10023a14:
        unaff_r5 = (char *)(iVar7 - (int)unaff_r5);
        if ((int)in_stack_00000028 < 0) {
          uVar14 = FUN_10025ccc();
          pcVar12 = in_stack_00000024;
          unaff_r11 = pcVar4;
          in_stack_00000024 = in_stack_00000024 + -(int)in_stack_00000028;
        }
        else {
          pcVar12 = in_stack_00000024 + (int)in_stack_00000028;
          unaff_r11 = pcVar4 + (int)in_stack_00000028;
          uVar14 = FUN_10025ccc();
          pcVar4 = (char *)uVar14;
          if (in_stack_00000024 == (char *)0x0) {
            if (in_stack_0000002c != 0) {
              if (unaff_r5 != (char *)0x0) {
                FUN_10023c1c();
              }
              unaff_r10 = (char *)FUN_10025ea8();
              in_stack_00000018 = FUN_10025ccc();
              if (in_stack_00000030 != 0) {
                FUN_10023bac();
              }
              pcVar10 = (char *)0x0;
              if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) &&
                  ((in_stack_00000014 & 0xfffff) == 0)) && ((in_stack_00000014 & 0x7ff00000) != 0))
              {
                in_stack_00000024 = pcVar12 + 1;
                iVar7 = 1;
                in_stack_0000002c = 1;
                unaff_r11 = unaff_r11 + 1;
                in_stack_00000030 = 1;
              }
              else {
                iVar7 = 1;
                in_stack_0000002c = 1;
                in_stack_00000024 = pcVar12;
              }
LAB_1002311e:
              do {
                uVar6 = (uint)(unaff_r11 + iVar7) & 0x1f;
                if (((uint)(unaff_r11 + iVar7) & 0x1f) == 0) {
                  iVar7 = 0x1c;
LAB_1002313a:
                  pcVar10 = pcVar10 + iVar7;
                  in_stack_00000024 = in_stack_00000024 + iVar7;
                  unaff_r11 = unaff_r11 + iVar7;
                }
                else {
                  if (4 < (int)(0x20 - uVar6)) {
                    iVar7 = 0x1c - uVar6;
                    goto LAB_1002313a;
                  }
                  if (0x20 - uVar6 != 4) {
                    iVar7 = 0x3c - uVar6;
                    goto LAB_1002313a;
                  }
                }
                if (0 < (int)in_stack_00000024) {
                  unaff_r10 = (char *)FUN_10025fb4();
                }
                if (0 < (int)unaff_r11) {
                  in_stack_00000018 = FUN_10025fb4();
                }
                if ((in_stack_00000034 == 0) ||
                   (iVar7 = FUN_100260a8(unaff_r10,in_stack_00000018), -1 < iVar7)) {
                  if ((0 < (int)in_stack_00000028) || (in_stack_00000098 < 3)) goto LAB_1002317c;
                }
                else {
                  unaff_r10 = (char *)FUN_10025a90();
                  if (in_stack_0000002c == 0) {
                    in_stack_00000028 = in_stack_00000040;
                    if ((0 < (int)in_stack_00000040) || (in_stack_00000098 < 3)) goto LAB_1002318a;
                  }
                  else {
                    pcVar4 = (char *)FUN_10025a90();
                    in_stack_00000028 = in_stack_00000040;
                    if ((0 < (int)in_stack_00000040) || (in_stack_00000098 < 3)) goto LAB_1002366c;
                  }
                }
                if (in_stack_00000028 == (char *)0x0) {
                  in_stack_00000018 = FUN_10025a90();
                  iVar7 = FUN_100260a8(unaff_r10,in_stack_00000018);
                  if (0 < iVar7) {
                    *in_stack_0000000c = '1';
                    FUN_10025a44();
                    if (pcVar4 == (char *)0x0) {
                      FUN_1002306c();
                      return;
                    }
                    FUN_1002322c();
                    return;
                  }
                }
                FUN_10025a44();
                if (pcVar4 != (char *)0x0) {
                  FUN_1002322c();
                }
                FUN_1002306c();
                pcVar10 = in_stack_0000000c;
LAB_10023b16:
                if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
                   ((in_stack_00000014 & 0x7ff00000) != 0)) {
                  in_stack_00000024 = in_stack_00000024 + 1;
                  in_stack_00000030 = 1;
                  unaff_r11 = unaff_r11 + 1;
                }
LAB_100235be:
                iVar7 = FUN_10025bdc(*(undefined4 *)
                                      (*(int *)(in_stack_00000018 + 0x10) * 4 + in_stack_00000018 +
                                      0x10));
                iVar7 = 0x20 - iVar7;
              } while( true );
            }
            goto LAB_10023a42;
          }
        }
        uVar3 = (undefined4)uVar14;
        unaff_r7 = unaff_r10;
        if ((int)unaff_r11 < 1) {
          if (in_stack_0000002c != 0) {
            FUN_1002329e();
            return;
          }
LAB_10023a42:
          FUN_100232b4();
          return;
        }
LAB_10023d1e:
        pcVar4 = (char *)uVar14;
        pcVar10 = in_stack_00000024;
        if ((int)unaff_r11 < (int)in_stack_00000024) {
          pcVar10 = unaff_r11;
        }
        unaff_r10 = in_stack_00000024 + -(int)pcVar10;
        if (in_stack_0000002c != 0) {
          FUN_1002329e(uVar3,(int)((ulonglong)uVar14 >> 0x20),unaff_r11);
        }
        FUN_100232b4();
        in_stack_00000024 = pcVar12 + -(int)pcVar10;
        goto LAB_10023d44;
      }
      FUN_10025ccc();
      if (in_stack_00000024 == (char *)0x0) {
        FUN_100232a6();
      }
      pcVar10 = in_stack_00000024;
      if ((int)(pcVar4 + (int)in_stack_00000028) < (int)in_stack_00000024) {
        pcVar10 = pcVar4 + (int)in_stack_00000028;
      }
      unaff_r6 = in_stack_00000024 + -(int)pcVar10;
      FUN_100232a6();
    }
    FUN_100230e6();
  }
  FUN_100233d4();
  unaff_r6[4] = '\0';
  unaff_r6[5] = '\0';
  unaff_r6[6] = '\0';
  unaff_r6[7] = '\0';
  FUN_10022fd4();
                    /* WARNING: Subroutine does not return */
  FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0xef,0,"REENT malloc succeeded");
LAB_1002317c:
  if (in_stack_0000002c == 0) {
LAB_1002318a:
    iVar7 = 1;
    while( true ) {
      iVar5 = FUN_10022c2c(unaff_r10,in_stack_00000018);
      in_stack_0000000c[iVar7 + -1] = (char)iVar5 + '0';
      if ((int)in_stack_00000028 <= iVar7) break;
      unaff_r10 = (char *)FUN_10025a90();
      iVar7 = iVar7 + 1;
    }
    pcVar10 = (char *)0x0;
    if (0 < (int)in_stack_00000028) {
      pcVar10 = in_stack_00000028 + -1;
    }
    pcVar10 = pcVar10 + (int)(in_stack_0000000c + 1);
    uVar3 = FUN_10025fb4();
    uVar14 = FUN_100260a8(uVar3,in_stack_00000018);
    iVar7 = (int)uVar14;
    if ((0 < iVar7) || ((iVar7 == 0 && (iVar5 << 0x1f < 0)))) {
      FUN_100231fe(iVar7,(int)((ulonglong)uVar14 >> 0x20),in_stack_0000000c);
      return;
    }
    do {
      pcVar10 = pcVar10 + -1;
    } while (*pcVar10 == '0');
    FUN_1002320c();
    return;
  }
LAB_1002366c:
  if (0 < (int)pcVar10) {
    pcVar4 = (char *)FUN_10025fb4();
  }
  pcVar10 = pcVar4;
  if (in_stack_00000030 != 0) {
    iVar7 = FUN_100259c0();
    if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded");
    }
    FUN_1001f4d4(iVar7 + 0xc,pcVar4 + 0xc,(*(int *)(pcVar4 + 0x10) + 2) * 4);
    pcVar10 = (char *)FUN_10025fb4();
  }
  in_stack_00000028 = in_stack_00000028 + (int)(in_stack_0000000c + -1);
  in_stack_00000030 = in_stack_00000010 & 1;
  unaff_r11 = in_stack_0000000c;
LAB_100236a2:
  in_stack_0000002c = FUN_10022c2c(unaff_r10,in_stack_00000018);
  unaff_r7 = (char *)(in_stack_0000002c + 0x30);
  iVar7 = FUN_100260a8(unaff_r10,pcVar4);
  iVar5 = FUN_100260e4();
  pcVar12 = pcVar4;
  if (*(int *)(iVar5 + 0xc) != 0) {
    uVar15 = FUN_10025a44();
    if (iVar7 < 0) goto LAB_10023762;
    if ((in_stack_00000010 & 1) == 0 && (iVar7 == 0 && in_stack_00000098 == 0)) goto LAB_10023762;
LAB_100237c2:
    pcVar4 = pcVar10;
    if (unaff_r7 != (char *)0x39) {
      *unaff_r11 = (char)in_stack_0000002c + '1';
      FUN_1002320c();
      return;
    }
    goto LAB_10023d72;
  }
  in_stack_00000024 = (char *)FUN_100260a8(unaff_r10,iVar5);
  uVar15 = FUN_10025a44();
  if (in_stack_00000024 == (char *)0x0 && in_stack_00000098 == 0) {
    if (in_stack_00000030 == 0) {
      pcVar4 = pcVar10;
      if (unaff_r7 == (char *)0x39) goto LAB_10023d72;
      if (0 < iVar7) goto LAB_10023780;
      goto LAB_10023784;
    }
    if (iVar7 < 0) goto LAB_10023784;
  }
  else {
    if (iVar7 < 0) goto LAB_10023d8c;
    if ((iVar7 == 0 && in_stack_00000098 == 0) && in_stack_00000030 == 0) goto LAB_10023d8c;
    if (0 < (int)in_stack_00000024) goto LAB_100237c2;
  }
  unaff_r5 = unaff_r11 + 1;
  *unaff_r11 = (char)unaff_r7;
  if (unaff_r11 != in_stack_00000028) {
    unaff_r10 = (char *)FUN_10025a90();
    unaff_r11 = unaff_r5;
    if (pcVar4 == pcVar10) {
      pcVar4 = (char *)FUN_10025a90();
      pcVar10 = pcVar4;
    }
    else {
      pcVar4 = (char *)FUN_10025a90();
      pcVar10 = (char *)FUN_10025a90();
    }
    goto LAB_100236a2;
  }
LAB_10023d44:
  FUN_100231da();
LAB_10023d58:
  FUN_100233d4();
LAB_10023d68:
  cVar2 = '1';
LAB_100239fa:
  *unaff_r7 = cVar2;
  FUN_1002306c();
  *in_stack_0000000c = '1';
  FUN_1002320c();
  iVar7 = extraout_r3_01;
  goto LAB_10023a14;
LAB_10023d72:
  *unaff_r11 = '9';
  FUN_100231fe((int)uVar15,(int)(uVar15 >> 0x20),in_stack_0000000c);
  pcVar10 = unaff_r7;
  unaff_r7 = unaff_r10;
  unaff_r11 = pcVar12;
LAB_10023d8c:
  if ((int)in_stack_00000024 < 1) goto LAB_10023784;
LAB_10023762:
  unaff_r10 = (char *)FUN_10025fb4();
  uVar15 = FUN_100260a8(unaff_r10,in_stack_00000018);
  if ((int)uVar15 < 1) {
LAB_10023dfa:
    if (((int)uVar15 != 0) || (-1 < (int)unaff_r7 << 0x1f)) goto LAB_10023784;
    uVar15 = uVar15 & 0xffffffff00000000;
  }
  if (unaff_r7 != (char *)0x39) {
LAB_10023780:
    unaff_r7 = (char *)(in_stack_0000002c + 0x31);
LAB_10023784:
    *unaff_r11 = (char)unaff_r7;
    FUN_1002320c();
    return;
  }
  unaff_r7 = (char *)0x39;
  pcVar12 = pcVar4;
  pcVar4 = pcVar10;
  goto LAB_10023d72;
}



/* FUN_10022ff6 at 10022ff6 */

void FUN_10022ff6(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int extraout_r3;
  uint extraout_r3_00;
  char *pcVar6;
  int extraout_r3_01;
  char *pcVar7;
  undefined4 uVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *pcVar12;
  char *unaff_r10;
  char *unaff_r11;
  undefined8 uVar13;
  char *in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  int in_stack_00000020;
  char *in_stack_00000024;
  char *in_stack_00000028;
  int in_stack_0000002c;
  uint in_stack_00000030;
  int in_stack_00000034;
  char *in_stack_00000040;
  int in_stack_00000048;
  int in_stack_0000006c;
  int in_stack_00000098;
  int in_stack_0000009c;
  int *in_stack_000000a0;
  undefined4 *in_stack_000000a8;
  
  if ((-1 < in_stack_0000006c) && (in_stack_00000020 < 0xf)) {
    uVar8 = *(undefined4 *)(&DAT_1002b35c + in_stack_00000020 * 8);
    uVar5 = *(undefined4 *)(&DAT_1002b358 + in_stack_00000020 * 8);
    if (-1 < in_stack_0000009c) {
      FUN_10023bb2();
    }
    if (0 < (int)in_stack_00000028) {
      FUN_10023bb2();
    }
    if (in_stack_00000028 == (char *)0x0) {
      uVar13 = FUN_1001e9a6(uVar5,uVar8,0,0x40140000);
      iVar1 = FUN_1001ea48(in_stack_00000018,in_stack_0000001c,(int)uVar13,
                           (int)((ulonglong)uVar13 >> 0x20));
      if (iVar1 == 0) {
        *in_stack_0000000c = '1';
        FUN_10025a44();
        FUN_10025a44();
        in_stack_0000000c[1] = '\0';
        *in_stack_000000a0 = in_stack_00000020 + 2;
        if (in_stack_000000a8 == (undefined4 *)0x0) {
          FUN_10022e06();
          return;
        }
        *in_stack_000000a8 = in_stack_0000000c + 1;
        FUN_10022e06();
        return;
      }
    }
    FUN_10025a44();
    FUN_1002306c();
    return;
  }
  if (in_stack_00000048 != 0) {
    FUN_10023e32();
  }
  uVar4 = in_stack_00000030;
  if (in_stack_00000024 == (char *)0x0) {
    if (in_stack_0000002c == 0) {
      in_stack_00000018 = FUN_10025ccc();
      pcVar11 = (char *)0x0;
      if (in_stack_00000030 != 0) {
FUN_100235a6:
        pcVar9 = (char *)0x0;
        in_stack_00000018 = FUN_10025ea8();
        in_stack_00000030 = 0;
        if (1 < in_stack_00000098) goto LAB_100235be;
        goto LAB_10023b16;
      }
LAB_100234a4:
      pcVar9 = (char *)0x0;
      iVar1 = uVar4 + 1;
      goto LAB_1002311e;
    }
  }
  else if (unaff_r11 == (char *)0x0) {
    if (in_stack_0000002c == 0) {
      in_stack_00000018 = FUN_10025ccc();
      pcVar9 = (char *)0x0;
      pcVar11 = in_stack_00000024;
      if (in_stack_00000030 != 0) goto FUN_100235a6;
      iVar1 = 1;
      goto LAB_1002311e;
    }
  }
  else {
    pcVar9 = in_stack_00000024;
    if ((int)unaff_r11 < (int)in_stack_00000024) {
      pcVar9 = unaff_r11;
    }
    pcVar11 = in_stack_00000024 + -(int)pcVar9;
    unaff_r11 = unaff_r11 + -(int)pcVar9;
    in_stack_00000024 = pcVar11;
    if (in_stack_0000002c == 0) {
      in_stack_00000018 = FUN_10025ccc();
      if (in_stack_00000030 != 0) {
        FUN_10023df2();
        uVar4 = extraout_r3_00;
      }
      goto LAB_100234a4;
    }
  }
  unaff_r10 = (char *)FUN_10025ea8();
  in_stack_00000018 = FUN_10025ccc();
  in_stack_0000002c = 0;
  if (in_stack_00000030 != 0) {
    FUN_10023d9c();
    in_stack_0000002c = extraout_r3;
  }
  pcVar9 = (char *)0x0;
  iVar1 = in_stack_0000002c + 1;
  pcVar11 = in_stack_00000024;
LAB_1002311e:
  do {
    uVar4 = (uint)(unaff_r11 + iVar1) & 0x1f;
    if (((uint)(unaff_r11 + iVar1) & 0x1f) == 0) {
      iVar1 = 0x1c;
LAB_1002313a:
      pcVar11 = pcVar11 + iVar1;
      in_stack_00000024 = in_stack_00000024 + iVar1;
      unaff_r11 = unaff_r11 + iVar1;
    }
    else {
      if (4 < (int)(0x20 - uVar4)) {
        iVar1 = 0x1c - uVar4;
        goto LAB_1002313a;
      }
      if (0x20 - uVar4 != 4) {
        iVar1 = 0x3c - uVar4;
        goto LAB_1002313a;
      }
    }
    if (0 < (int)in_stack_00000024) {
      unaff_r10 = (char *)FUN_10025fb4();
    }
    if (0 < (int)unaff_r11) {
      in_stack_00000018 = FUN_10025fb4();
    }
    if ((in_stack_00000034 == 0) || (iVar1 = FUN_100260a8(unaff_r10,in_stack_00000018), -1 < iVar1))
    {
      if ((0 < (int)in_stack_00000028) || (in_stack_00000098 < 3)) {
        if (in_stack_0000002c == 0) goto LAB_1002318a;
LAB_1002366c:
        if (0 < (int)pcVar11) {
          pcVar9 = (char *)FUN_10025fb4();
        }
        pcVar11 = pcVar9;
        if (in_stack_00000030 != 0) {
          iVar1 = FUN_100259c0();
          if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded"
                        );
          }
          FUN_1001f4d4(iVar1 + 0xc,pcVar9 + 0xc,(*(int *)(pcVar9 + 0x10) + 2) * 4);
          pcVar11 = (char *)FUN_10025fb4();
        }
        in_stack_00000028 = in_stack_00000028 + (int)(in_stack_0000000c + -1);
        in_stack_00000030 = in_stack_00000010 & 1;
        pcVar12 = in_stack_0000000c;
LAB_100236a2:
        iVar1 = FUN_10022c2c(unaff_r10,in_stack_00000018);
        pcVar6 = (char *)(iVar1 + 0x30);
        iVar2 = FUN_100260a8(unaff_r10,pcVar9);
        iVar3 = FUN_100260e4();
        pcVar10 = pcVar9;
        if (*(int *)(iVar3 + 0xc) != 0) {
          uVar13 = FUN_10025a44();
          if (iVar2 < 0) goto LAB_10023762;
          if ((in_stack_00000010 & 1) == 0 && (iVar2 == 0 && in_stack_00000098 == 0))
          goto LAB_10023762;
LAB_100237c2:
          pcVar9 = pcVar11;
          if (pcVar6 != (char *)0x39) {
            *pcVar12 = (char)iVar1 + '1';
            FUN_1002320c();
            return;
          }
          break;
        }
        in_stack_00000024 = (char *)FUN_100260a8(unaff_r10,iVar3);
        uVar13 = FUN_10025a44();
        if (in_stack_00000024 == (char *)0x0 && in_stack_00000098 == 0) {
          if (in_stack_00000030 == 0) {
            pcVar9 = pcVar11;
            if (pcVar6 == (char *)0x39) break;
            if (0 < iVar2) goto LAB_10023780;
            goto LAB_10023784;
          }
          if (iVar2 < 0) goto LAB_10023784;
        }
        else {
          if (iVar2 < 0) goto LAB_10023d8c;
          if ((iVar2 == 0 && in_stack_00000098 == 0) && in_stack_00000030 == 0) goto LAB_10023d8c;
          if (0 < (int)in_stack_00000024) goto LAB_100237c2;
        }
        pcVar10 = pcVar12 + 1;
        *pcVar12 = (char)pcVar6;
        if (pcVar12 != in_stack_00000028) {
          unaff_r10 = (char *)FUN_10025a90();
          pcVar12 = pcVar10;
          if (pcVar9 == pcVar11) {
            pcVar9 = (char *)FUN_10025a90();
            pcVar11 = pcVar9;
          }
          else {
            pcVar9 = (char *)FUN_10025a90();
            pcVar11 = (char *)FUN_10025a90();
          }
          goto LAB_100236a2;
        }
        do {
          pcVar11 = unaff_r10;
          FUN_100231da();
          FUN_100233d4();
          *pcVar6 = '1';
          FUN_1002306c();
          *in_stack_0000000c = '1';
          FUN_1002320c();
          pcVar10 = (char *)(extraout_r3_01 - (int)pcVar10);
          if ((int)in_stack_00000028 < 0) {
            uVar13 = FUN_10025ccc();
            pcVar12 = in_stack_00000024;
            unaff_r11 = pcVar9;
            in_stack_00000024 = in_stack_00000024 + -(int)in_stack_00000028;
          }
          else {
            pcVar12 = in_stack_00000024 + (int)in_stack_00000028;
            unaff_r11 = pcVar9 + (int)in_stack_00000028;
            uVar13 = FUN_10025ccc();
            pcVar9 = (char *)uVar13;
            if (in_stack_00000024 == (char *)0x0) goto LAB_10023294;
          }
          pcVar9 = (char *)uVar13;
          if ((int)unaff_r11 < 1) {
            if (iVar1 != 0) {
              FUN_1002329e();
              return;
            }
            goto LAB_10023a42;
          }
          pcVar7 = in_stack_00000024;
          if ((int)unaff_r11 < (int)in_stack_00000024) {
            pcVar7 = unaff_r11;
          }
          if (iVar1 != 0) {
            FUN_1002329e(pcVar9,(int)((ulonglong)uVar13 >> 0x20),unaff_r11);
          }
          FUN_100232b4();
          unaff_r10 = in_stack_00000024 + -(int)pcVar7;
          pcVar6 = pcVar11;
          in_stack_00000024 = pcVar12 + -(int)pcVar7;
        } while( true );
      }
    }
    else {
      unaff_r10 = (char *)FUN_10025a90();
      if (in_stack_0000002c == 0) {
        in_stack_00000028 = in_stack_00000040;
        if ((0 < (int)in_stack_00000040) || (in_stack_00000098 < 3)) {
LAB_1002318a:
          iVar1 = 1;
          while( true ) {
            iVar2 = FUN_10022c2c(unaff_r10,in_stack_00000018);
            in_stack_0000000c[iVar1 + -1] = (char)iVar2 + '0';
            if ((int)in_stack_00000028 <= iVar1) break;
            unaff_r10 = (char *)FUN_10025a90();
            iVar1 = iVar1 + 1;
          }
          pcVar11 = (char *)0x0;
          if (0 < (int)in_stack_00000028) {
            pcVar11 = in_stack_00000028 + -1;
          }
          pcVar11 = pcVar11 + (int)(in_stack_0000000c + 1);
          uVar5 = FUN_10025fb4();
          uVar13 = FUN_100260a8(uVar5,in_stack_00000018);
          iVar1 = (int)uVar13;
          if ((0 < iVar1) || ((iVar1 == 0 && (iVar2 << 0x1f < 0)))) {
            FUN_100231fe(iVar1,(int)((ulonglong)uVar13 >> 0x20),in_stack_0000000c);
            return;
          }
          do {
            pcVar11 = pcVar11 + -1;
          } while (*pcVar11 == '0');
          FUN_1002320c();
          return;
        }
      }
      else {
        pcVar9 = (char *)FUN_10025a90();
        in_stack_00000028 = in_stack_00000040;
        if ((0 < (int)in_stack_00000040) || (in_stack_00000098 < 3)) goto LAB_1002366c;
      }
    }
    if (in_stack_00000028 == (char *)0x0) {
      in_stack_00000018 = FUN_10025a90();
      iVar1 = FUN_100260a8(unaff_r10,in_stack_00000018);
      if (0 < iVar1) {
        *in_stack_0000000c = '1';
        FUN_10025a44();
        if (pcVar9 == (char *)0x0) {
          FUN_1002306c();
          return;
        }
        FUN_1002322c();
        return;
      }
    }
    FUN_10025a44();
    if (pcVar9 != (char *)0x0) {
      FUN_1002322c();
    }
    FUN_1002306c();
    pcVar11 = in_stack_0000000c;
LAB_10023b16:
    if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
       ((in_stack_00000014 & 0x7ff00000) != 0)) {
      in_stack_00000024 = in_stack_00000024 + 1;
      in_stack_00000030 = 1;
      unaff_r11 = unaff_r11 + 1;
    }
LAB_100235be:
    iVar1 = FUN_10025bdc(*(undefined4 *)
                          (*(int *)(in_stack_00000018 + 0x10) * 4 + in_stack_00000018 + 0x10));
    iVar1 = 0x20 - iVar1;
  } while( true );
LAB_10023d72:
  *pcVar12 = '9';
  FUN_100231fe((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),in_stack_0000000c);
  pcVar11 = pcVar6;
  pcVar6 = unaff_r10;
  pcVar12 = pcVar10;
LAB_10023d8c:
  if ((int)in_stack_00000024 < 1) goto LAB_10023784;
LAB_10023762:
  unaff_r10 = (char *)FUN_10025fb4();
  uVar13 = FUN_100260a8(unaff_r10,in_stack_00000018);
  if (((int)uVar13 < 1) && (((int)uVar13 != 0 || (-1 < (int)pcVar6 << 0x1f)))) goto LAB_10023784;
  if (pcVar6 != (char *)0x39) {
LAB_10023780:
    pcVar6 = (char *)(iVar1 + 0x31);
LAB_10023784:
    *pcVar12 = (char)pcVar6;
    FUN_1002320c();
    return;
  }
  pcVar6 = (char *)0x39;
  pcVar10 = pcVar9;
  pcVar9 = pcVar11;
  goto LAB_10023d72;
LAB_10023294:
  if (iVar1 == 0) {
LAB_10023a42:
    FUN_100232b4();
    return;
  }
  if (pcVar10 != (char *)0x0) {
    FUN_10023c1c();
  }
  unaff_r10 = (char *)FUN_10025ea8();
  in_stack_00000018 = FUN_10025ccc();
  if (in_stack_00000030 != 0) {
    FUN_10023bac();
  }
  pcVar11 = (char *)0x0;
  if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) && ((in_stack_00000014 & 0xfffff) == 0)
      ) && ((in_stack_00000014 & 0x7ff00000) != 0)) {
    in_stack_00000024 = pcVar12 + 1;
    iVar1 = 1;
    in_stack_0000002c = 1;
    unaff_r11 = unaff_r11 + 1;
    in_stack_00000030 = 1;
  }
  else {
    iVar1 = 1;
    in_stack_0000002c = 1;
    in_stack_00000024 = pcVar12;
  }
  goto LAB_1002311e;
}



/* FUN_1002300a at 1002300a */

void FUN_1002300a(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined8 uVar3;
  undefined1 *in_stack_0000000c;
  undefined4 uStack00000010;
  undefined4 uStack00000014;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  int in_stack_00000020;
  int in_stack_00000028;
  int in_stack_00000050;
  int in_stack_0000009c;
  int *in_stack_000000a0;
  undefined4 *in_stack_000000a8;
  
  puVar2 = (undefined4 *)(in_stack_00000020 * 8 + in_stack_00000050);
  uStack00000014 = puVar2[1];
  uStack00000010 = *puVar2;
  if (-1 < in_stack_0000009c) {
    FUN_10023bb2();
  }
  if (0 < in_stack_00000028) {
    FUN_10023bb2();
  }
  if (in_stack_00000028 == 0) {
    uVar3 = FUN_1001e9a6(uStack00000010,uStack00000014,0,0x40140000);
    iVar1 = FUN_1001ea48(in_stack_00000018,in_stack_0000001c,(int)uVar3,
                         (int)((ulonglong)uVar3 >> 0x20));
    if (iVar1 == 0) {
      *in_stack_0000000c = 0x31;
      FUN_10025a44();
      FUN_10025a44();
      in_stack_0000000c[1] = 0;
      *in_stack_000000a0 = in_stack_00000020 + 2;
      if (in_stack_000000a8 == (undefined4 *)0x0) {
        FUN_10022e06();
        return;
      }
      *in_stack_000000a8 = in_stack_0000000c + 1;
      FUN_10022e06();
      return;
    }
  }
  FUN_10025a44();
  FUN_1002306c();
  return;
}



/* FUN_1002306c at 1002306c */

void FUN_1002306c(void)

{
  undefined1 *unaff_r6;
  undefined4 in_stack_00000020;
  undefined4 *in_stack_000000a0;
  undefined4 *in_stack_000000a8;
  
  FUN_10025a44();
  *unaff_r6 = 0;
  *in_stack_000000a0 = in_stack_00000020;
  if (in_stack_000000a8 == (undefined4 *)0x0) {
    FUN_10022e06();
    return;
  }
  *in_stack_000000a8 = unaff_r6;
  FUN_10022e06();
  return;
}



/* FUN_100230e6 at 100230e6 */

void FUN_100230e6(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int extraout_r3;
  int iVar5;
  uint extraout_r3_00;
  char *pcVar6;
  int extraout_r3_01;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *unaff_r10;
  char *unaff_r11;
  undefined8 uVar12;
  char *in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int iStack00000018;
  char *in_stack_00000024;
  char *in_stack_00000028;
  int in_stack_0000002c;
  uint in_stack_00000030;
  int in_stack_00000034;
  char *in_stack_00000040;
  int in_stack_00000098;
  
  uVar4 = in_stack_00000030;
  if (in_stack_00000024 == (char *)0x0) {
    if (in_stack_0000002c == 0) {
      iStack00000018 = FUN_10025ccc();
      pcVar10 = (char *)0x0;
      if (in_stack_00000030 != 0) {
FUN_100235a6:
        pcVar8 = (char *)0x0;
        iStack00000018 = FUN_10025ea8();
        in_stack_00000030 = 0;
        if (1 < in_stack_00000098) goto LAB_100235be;
        goto LAB_10023b16;
      }
LAB_100234a4:
      pcVar8 = (char *)0x0;
      iVar5 = uVar4 + 1;
      goto LAB_1002311e;
    }
  }
  else if (unaff_r11 == (char *)0x0) {
    if (in_stack_0000002c == 0) {
      iStack00000018 = FUN_10025ccc();
      pcVar8 = (char *)0x0;
      pcVar10 = in_stack_00000024;
      if (in_stack_00000030 != 0) goto FUN_100235a6;
      iVar5 = 1;
      goto LAB_1002311e;
    }
  }
  else {
    pcVar8 = in_stack_00000024;
    if ((int)unaff_r11 < (int)in_stack_00000024) {
      pcVar8 = unaff_r11;
    }
    pcVar10 = in_stack_00000024 + -(int)pcVar8;
    unaff_r11 = unaff_r11 + -(int)pcVar8;
    in_stack_00000024 = pcVar10;
    if (in_stack_0000002c == 0) {
      iStack00000018 = FUN_10025ccc();
      if (in_stack_00000030 != 0) {
        FUN_10023df2();
        uVar4 = extraout_r3_00;
      }
      goto LAB_100234a4;
    }
  }
  unaff_r10 = (char *)FUN_10025ea8();
  iStack00000018 = FUN_10025ccc();
  in_stack_0000002c = 0;
  if (in_stack_00000030 != 0) {
    FUN_10023d9c();
    in_stack_0000002c = extraout_r3;
  }
  pcVar8 = (char *)0x0;
  iVar5 = in_stack_0000002c + 1;
  pcVar10 = in_stack_00000024;
LAB_1002311e:
  do {
    uVar4 = (uint)(unaff_r11 + iVar5) & 0x1f;
    if (((uint)(unaff_r11 + iVar5) & 0x1f) == 0) {
      iVar5 = 0x1c;
LAB_1002313a:
      pcVar10 = pcVar10 + iVar5;
      in_stack_00000024 = in_stack_00000024 + iVar5;
      unaff_r11 = unaff_r11 + iVar5;
    }
    else {
      if (4 < (int)(0x20 - uVar4)) {
        iVar5 = 0x1c - uVar4;
        goto LAB_1002313a;
      }
      if (0x20 - uVar4 != 4) {
        iVar5 = 0x3c - uVar4;
        goto LAB_1002313a;
      }
    }
    if (0 < (int)in_stack_00000024) {
      unaff_r10 = (char *)FUN_10025fb4();
    }
    if (0 < (int)unaff_r11) {
      iStack00000018 = FUN_10025fb4();
    }
    if ((in_stack_00000034 == 0) || (iVar5 = FUN_100260a8(unaff_r10,iStack00000018), -1 < iVar5)) {
      if ((0 < (int)in_stack_00000028) || (in_stack_00000098 < 3)) {
        if (in_stack_0000002c == 0) goto LAB_1002318a;
LAB_1002366c:
        if (0 < (int)pcVar10) {
          pcVar8 = (char *)FUN_10025fb4();
        }
        pcVar10 = pcVar8;
        if (in_stack_00000030 != 0) {
          iVar5 = FUN_100259c0();
          if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded"
                        );
          }
          FUN_1001f4d4(iVar5 + 0xc,pcVar8 + 0xc,(*(int *)(pcVar8 + 0x10) + 2) * 4);
          pcVar10 = (char *)FUN_10025fb4();
        }
        in_stack_00000028 = in_stack_00000028 + (int)(in_stack_0000000c + -1);
        in_stack_00000030 = in_stack_00000010 & 1;
        pcVar11 = in_stack_0000000c;
LAB_100236a2:
        iVar5 = FUN_10022c2c(unaff_r10,iStack00000018);
        pcVar6 = (char *)(iVar5 + 0x30);
        iVar2 = FUN_100260a8(unaff_r10,pcVar8);
        iVar3 = FUN_100260e4();
        pcVar9 = pcVar8;
        if (*(int *)(iVar3 + 0xc) != 0) {
          uVar12 = FUN_10025a44();
          if (iVar2 < 0) goto LAB_10023762;
          if ((in_stack_00000010 & 1) == 0 && (iVar2 == 0 && in_stack_00000098 == 0))
          goto LAB_10023762;
LAB_100237c2:
          pcVar8 = pcVar10;
          if (pcVar6 != (char *)0x39) {
            *pcVar11 = (char)iVar5 + '1';
            FUN_1002320c();
            return;
          }
          break;
        }
        in_stack_00000024 = (char *)FUN_100260a8(unaff_r10,iVar3);
        uVar12 = FUN_10025a44();
        if (in_stack_00000024 == (char *)0x0 && in_stack_00000098 == 0) {
          if (in_stack_00000030 == 0) {
            pcVar8 = pcVar10;
            if (pcVar6 == (char *)0x39) break;
            if (0 < iVar2) goto LAB_10023780;
            goto LAB_10023784;
          }
          if (iVar2 < 0) goto LAB_10023784;
        }
        else {
          if (iVar2 < 0) goto LAB_10023d8c;
          if ((iVar2 == 0 && in_stack_00000098 == 0) && in_stack_00000030 == 0) goto LAB_10023d8c;
          if (0 < (int)in_stack_00000024) goto LAB_100237c2;
        }
        pcVar9 = pcVar11 + 1;
        *pcVar11 = (char)pcVar6;
        if (pcVar11 != in_stack_00000028) {
          unaff_r10 = (char *)FUN_10025a90();
          pcVar11 = pcVar9;
          if (pcVar8 == pcVar10) {
            pcVar8 = (char *)FUN_10025a90();
            pcVar10 = pcVar8;
          }
          else {
            pcVar8 = (char *)FUN_10025a90();
            pcVar10 = (char *)FUN_10025a90();
          }
          goto LAB_100236a2;
        }
        do {
          pcVar10 = unaff_r10;
          FUN_100231da();
          FUN_100233d4();
          *pcVar6 = '1';
          FUN_1002306c();
          *in_stack_0000000c = '1';
          FUN_1002320c();
          pcVar9 = (char *)(extraout_r3_01 - (int)pcVar9);
          if ((int)in_stack_00000028 < 0) {
            uVar12 = FUN_10025ccc();
            pcVar11 = in_stack_00000024;
            unaff_r11 = pcVar8;
            in_stack_00000024 = in_stack_00000024 + -(int)in_stack_00000028;
          }
          else {
            pcVar11 = in_stack_00000024 + (int)in_stack_00000028;
            unaff_r11 = pcVar8 + (int)in_stack_00000028;
            uVar12 = FUN_10025ccc();
            pcVar8 = (char *)uVar12;
            if (in_stack_00000024 == (char *)0x0) goto LAB_10023294;
          }
          pcVar8 = (char *)uVar12;
          if ((int)unaff_r11 < 1) {
            if (iVar5 != 0) {
              FUN_1002329e();
              return;
            }
            goto LAB_10023a42;
          }
          pcVar7 = in_stack_00000024;
          if ((int)unaff_r11 < (int)in_stack_00000024) {
            pcVar7 = unaff_r11;
          }
          if (iVar5 != 0) {
            FUN_1002329e(pcVar8,(int)((ulonglong)uVar12 >> 0x20),unaff_r11);
          }
          FUN_100232b4();
          unaff_r10 = in_stack_00000024 + -(int)pcVar7;
          pcVar6 = pcVar10;
          in_stack_00000024 = pcVar11 + -(int)pcVar7;
        } while( true );
      }
    }
    else {
      unaff_r10 = (char *)FUN_10025a90();
      if (in_stack_0000002c == 0) {
        in_stack_00000028 = in_stack_00000040;
        if ((0 < (int)in_stack_00000040) || (in_stack_00000098 < 3)) {
LAB_1002318a:
          iVar5 = 1;
          while( true ) {
            iVar2 = FUN_10022c2c(unaff_r10,iStack00000018);
            in_stack_0000000c[iVar5 + -1] = (char)iVar2 + '0';
            if ((int)in_stack_00000028 <= iVar5) break;
            unaff_r10 = (char *)FUN_10025a90();
            iVar5 = iVar5 + 1;
          }
          pcVar10 = (char *)0x0;
          if (0 < (int)in_stack_00000028) {
            pcVar10 = in_stack_00000028 + -1;
          }
          pcVar10 = pcVar10 + (int)(in_stack_0000000c + 1);
          uVar1 = FUN_10025fb4();
          uVar12 = FUN_100260a8(uVar1,iStack00000018);
          iVar5 = (int)uVar12;
          if ((0 < iVar5) || ((iVar5 == 0 && (iVar2 << 0x1f < 0)))) {
            FUN_100231fe(iVar5,(int)((ulonglong)uVar12 >> 0x20),in_stack_0000000c);
            return;
          }
          do {
            pcVar10 = pcVar10 + -1;
          } while (*pcVar10 == '0');
          FUN_1002320c();
          return;
        }
      }
      else {
        pcVar8 = (char *)FUN_10025a90();
        in_stack_00000028 = in_stack_00000040;
        if ((0 < (int)in_stack_00000040) || (in_stack_00000098 < 3)) goto LAB_1002366c;
      }
    }
    if (in_stack_00000028 == (char *)0x0) {
      iStack00000018 = FUN_10025a90();
      iVar5 = FUN_100260a8(unaff_r10,iStack00000018);
      if (0 < iVar5) {
        *in_stack_0000000c = '1';
        FUN_10025a44();
        if (pcVar8 == (char *)0x0) {
          FUN_1002306c();
          return;
        }
        FUN_1002322c();
        return;
      }
    }
    FUN_10025a44();
    if (pcVar8 != (char *)0x0) {
      FUN_1002322c();
    }
    FUN_1002306c();
    pcVar10 = in_stack_0000000c;
LAB_10023b16:
    if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
       ((in_stack_00000014 & 0x7ff00000) != 0)) {
      in_stack_00000024 = in_stack_00000024 + 1;
      in_stack_00000030 = 1;
      unaff_r11 = unaff_r11 + 1;
    }
LAB_100235be:
    iVar5 = FUN_10025bdc(*(undefined4 *)
                          (*(int *)(iStack00000018 + 0x10) * 4 + iStack00000018 + 0x10));
    iVar5 = 0x20 - iVar5;
  } while( true );
LAB_10023d72:
  *pcVar11 = '9';
  FUN_100231fe((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),in_stack_0000000c);
  pcVar10 = pcVar6;
  pcVar6 = unaff_r10;
  pcVar11 = pcVar9;
LAB_10023d8c:
  if ((int)in_stack_00000024 < 1) goto LAB_10023784;
LAB_10023762:
  unaff_r10 = (char *)FUN_10025fb4();
  uVar12 = FUN_100260a8(unaff_r10,iStack00000018);
  if (((int)uVar12 < 1) && (((int)uVar12 != 0 || (-1 < (int)pcVar6 << 0x1f)))) goto LAB_10023784;
  if (pcVar6 != (char *)0x39) {
LAB_10023780:
    pcVar6 = (char *)(iVar5 + 0x31);
LAB_10023784:
    *pcVar11 = (char)pcVar6;
    FUN_1002320c();
    return;
  }
  pcVar6 = (char *)0x39;
  pcVar9 = pcVar8;
  pcVar8 = pcVar10;
  goto LAB_10023d72;
LAB_10023294:
  if (iVar5 == 0) {
LAB_10023a42:
    FUN_100232b4();
    return;
  }
  if (pcVar9 != (char *)0x0) {
    FUN_10023c1c();
  }
  unaff_r10 = (char *)FUN_10025ea8();
  iStack00000018 = FUN_10025ccc();
  if (in_stack_00000030 != 0) {
    FUN_10023bac();
  }
  pcVar10 = (char *)0x0;
  if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) && ((in_stack_00000014 & 0xfffff) == 0)
      ) && ((in_stack_00000014 & 0x7ff00000) != 0)) {
    in_stack_00000024 = pcVar11 + 1;
    iVar5 = 1;
    in_stack_0000002c = 1;
    unaff_r11 = unaff_r11 + 1;
    in_stack_00000030 = 1;
  }
  else {
    iVar5 = 1;
    in_stack_0000002c = 1;
    in_stack_00000024 = pcVar11;
  }
  goto LAB_1002311e;
}



/* FUN_100231da at 100231da */

void FUN_100231da(void)

{
  undefined4 uVar1;
  int iVar2;
  char *unaff_r5;
  int unaff_r7;
  undefined8 uVar3;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000018;
  
  uVar1 = FUN_10025fb4();
  uVar3 = FUN_100260a8(uVar1,in_stack_00000018);
  iVar2 = (int)uVar3;
  if ((0 < iVar2) || ((iVar2 == 0 && (unaff_r7 << 0x1f < 0)))) {
    FUN_100231fe(iVar2,(int)((ulonglong)uVar3 >> 0x20),in_stack_0000000c);
    return;
  }
  do {
    unaff_r5 = unaff_r5 + -1;
  } while (*unaff_r5 == '0');
  FUN_1002320c();
  return;
}



/* FUN_100231fe at 100231fe */

void FUN_100231fe(undefined4 param_1,undefined4 param_2,char *param_3)

{
  char *extraout_r2;
  int unaff_r4;
  char *unaff_r5;
  int unaff_r11;
  
  while( true ) {
    unaff_r5 = unaff_r5 + -1;
    if (*unaff_r5 != '9') break;
    if (unaff_r5 == param_3) {
      FUN_10023a04();
      param_3 = extraout_r2;
    }
  }
  *unaff_r5 = *unaff_r5 + '\x01';
  FUN_10025a44();
  if (unaff_r4 == 0) {
    FUN_1002306c();
    return;
  }
  if ((unaff_r11 != 0) && (unaff_r11 != unaff_r4)) {
    FUN_10025a44();
  }
  FUN_10025a44();
  FUN_1002306c();
  return;
}



/* FUN_1002320c at 1002320c */

void FUN_1002320c(void)

{
  int unaff_r4;
  int unaff_r11;
  
  FUN_10025a44();
  if (unaff_r4 == 0) {
    FUN_1002306c();
    return;
  }
  if ((unaff_r11 != 0) && (unaff_r11 != unaff_r4)) {
    FUN_10025a44();
  }
  FUN_10025a44();
  FUN_1002306c();
  return;
}



/* FUN_1002322c at 1002322c */

void FUN_1002322c(void)

{
  FUN_10025a44();
  FUN_1002306c();
  return;
}



/* FUN_1002329e at 1002329e */

/* WARNING: Removing unreachable block (ram,0x1002384e) */
/* WARNING: Removing unreachable block (ram,0x10023856) */
/* WARNING: Removing unreachable block (ram,0x10023858) */
/* WARNING: Removing unreachable block (ram,0x1002385e) */
/* WARNING: Removing unreachable block (ram,0x10023860) */
/* WARNING: Removing unreachable block (ram,0x10023184) */
/* WARNING: Removing unreachable block (ram,0x1002318a) */
/* WARNING: Removing unreachable block (ram,0x100231ae) */
/* WARNING: Removing unreachable block (ram,0x100231be) */
/* WARNING: Removing unreachable block (ram,0x100231cc) */
/* WARNING: Removing unreachable block (ram,0x100231d0) */
/* WARNING: Removing unreachable block (ram,0x100231f0) */
/* WARNING: Removing unreachable block (ram,0x1002357e) */
/* WARNING: Removing unreachable block (ram,0x10023584) */
/* WARNING: Removing unreachable block (ram,0x1002358e) */
/* WARNING: Removing unreachable block (ram,0x10023582) */
/* WARNING: Removing unreachable block (ram,0x100231f2) */
/* WARNING: Removing unreachable block (ram,0x1002319e) */

void FUN_1002329e(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  int extraout_r3;
  char *pcVar8;
  char *unaff_r4;
  char *pcVar9;
  char *unaff_r5;
  char *unaff_r6;
  char *unaff_r7;
  char *unaff_r11;
  undefined8 uVar10;
  char *in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int iStack00000018;
  char *pcStack00000024;
  char *in_stack_00000028;
  uint in_stack_00000030;
  int in_stack_00000034;
  char *in_stack_00000040;
  int in_stack_00000098;
  
code_r0x1002329e:
  if (unaff_r5 != (char *)0x0) {
    FUN_10023c1c();
  }
  pcVar1 = (char *)FUN_10025ea8();
  iStack00000018 = FUN_10025ccc();
  if (in_stack_00000030 != 0) {
    FUN_10023bac();
  }
  if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) && ((in_stack_00000014 & 0xfffff) == 0)
      ) && ((in_stack_00000014 & 0x7ff00000) != 0)) {
    pcStack00000024 = unaff_r7 + 1;
    iVar7 = 1;
    unaff_r11 = unaff_r11 + 1;
    in_stack_00000030 = 1;
  }
  else {
    iVar7 = 1;
    pcStack00000024 = unaff_r7;
  }
  do {
    uVar5 = (uint)(unaff_r11 + iVar7) & 0x1f;
    if (((uint)(unaff_r11 + iVar7) & 0x1f) == 0) {
      iVar7 = 0x1c;
LAB_1002313a:
      unaff_r6 = unaff_r6 + iVar7;
      pcStack00000024 = pcStack00000024 + iVar7;
      unaff_r11 = unaff_r11 + iVar7;
    }
    else {
      if (4 < (int)(0x20 - uVar5)) {
        iVar7 = 0x1c - uVar5;
        goto LAB_1002313a;
      }
      if (0x20 - uVar5 != 4) {
        iVar7 = 0x3c - uVar5;
        goto LAB_1002313a;
      }
    }
    if (0 < (int)pcStack00000024) {
      pcVar1 = (char *)FUN_10025fb4();
    }
    if (0 < (int)unaff_r11) {
      iStack00000018 = FUN_10025fb4();
    }
    if ((in_stack_00000034 != 0) && (iVar7 = FUN_100260a8(pcVar1,iStack00000018), iVar7 < 0)) {
      pcVar1 = (char *)FUN_10025a90();
      unaff_r4 = (char *)FUN_10025a90();
      in_stack_00000028 = in_stack_00000040;
    }
    if ((0 < (int)in_stack_00000028) || (in_stack_00000098 < 3)) break;
    if (in_stack_00000028 == (char *)0x0) {
      iStack00000018 = FUN_10025a90();
      iVar7 = FUN_100260a8(pcVar1,iStack00000018);
      if (0 < iVar7) {
        *in_stack_0000000c = '1';
        FUN_10025a44();
        if (unaff_r4 == (char *)0x0) {
          FUN_1002306c();
          return;
        }
        FUN_1002322c();
        return;
      }
    }
    FUN_10025a44();
    if (unaff_r4 != (char *)0x0) {
      FUN_1002322c();
    }
    FUN_1002306c();
    if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
       ((in_stack_00000014 & 0x7ff00000) != 0)) {
      pcStack00000024 = pcStack00000024 + 1;
      in_stack_00000030 = 1;
      unaff_r11 = unaff_r11 + 1;
    }
    iVar7 = FUN_10025bdc(*(undefined4 *)
                          (*(int *)(iStack00000018 + 0x10) * 4 + iStack00000018 + 0x10));
    iVar7 = 0x20 - iVar7;
    unaff_r6 = in_stack_0000000c;
  } while( true );
  if (0 < (int)unaff_r6) {
    unaff_r4 = (char *)FUN_10025fb4();
  }
  pcVar4 = unaff_r4;
  if (in_stack_00000030 != 0) {
    iVar7 = FUN_100259c0();
    if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded");
    }
    FUN_1001f4d4(iVar7 + 0xc,unaff_r4 + 0xc,(*(int *)(unaff_r4 + 0x10) + 2) * 4);
    pcVar4 = (char *)FUN_10025fb4();
  }
  in_stack_00000028 = in_stack_00000028 + (int)(in_stack_0000000c + -1);
  in_stack_00000030 = in_stack_00000010 & 1;
  pcVar8 = in_stack_0000000c;
LAB_100236a2:
  iVar7 = FUN_10022c2c(pcVar1,iStack00000018);
  pcVar6 = (char *)(iVar7 + 0x30);
  iVar2 = FUN_100260a8(pcVar1,unaff_r4);
  iVar3 = FUN_100260e4();
  pcVar9 = unaff_r4;
  if (*(int *)(iVar3 + 0xc) != 0) {
    uVar10 = FUN_10025a44();
    if (iVar2 < 0) goto LAB_10023762;
    if ((in_stack_00000010 & 1) == 0 && (iVar2 == 0 && in_stack_00000098 == 0)) goto LAB_10023762;
LAB_100237c2:
    unaff_r4 = pcVar4;
    if (pcVar6 != (char *)0x39) {
      *pcVar8 = (char)iVar7 + '1';
      FUN_1002320c();
      return;
    }
    goto LAB_10023d72;
  }
  pcStack00000024 = (char *)FUN_100260a8(pcVar1,iVar3);
  uVar10 = FUN_10025a44();
  if (pcStack00000024 == (char *)0x0 && in_stack_00000098 == 0) {
    if (in_stack_00000030 == 0) {
      unaff_r4 = pcVar4;
      if (pcVar6 == (char *)0x39) goto LAB_10023d72;
      if (iVar2 < 1) goto LAB_10023784;
      goto LAB_10023780;
    }
    if (iVar2 < 0) goto LAB_10023784;
  }
  else {
    if (iVar2 < 0) goto LAB_10023d8c;
    if ((iVar2 == 0 && in_stack_00000098 == 0) && in_stack_00000030 == 0) goto LAB_10023d8c;
    if (0 < (int)pcStack00000024) goto LAB_100237c2;
  }
  unaff_r5 = pcVar8 + 1;
  *pcVar8 = (char)pcVar6;
  if (pcVar8 != in_stack_00000028) {
    pcVar1 = (char *)FUN_10025a90();
    pcVar8 = unaff_r5;
    if (unaff_r4 == pcVar4) {
      unaff_r4 = (char *)FUN_10025a90();
      pcVar4 = unaff_r4;
    }
    else {
      unaff_r4 = (char *)FUN_10025a90();
      pcVar4 = (char *)FUN_10025a90();
    }
    goto LAB_100236a2;
  }
  do {
    pcVar4 = pcVar1;
    FUN_100231da();
    FUN_100233d4();
    *pcVar6 = '1';
    FUN_1002306c();
    *in_stack_0000000c = '1';
    FUN_1002320c();
    unaff_r5 = (char *)(extraout_r3 - (int)unaff_r5);
    if ((int)in_stack_00000028 < 0) {
      uVar10 = FUN_10025ccc();
      unaff_r7 = pcStack00000024;
      unaff_r11 = unaff_r4;
      pcStack00000024 = pcStack00000024 + -(int)in_stack_00000028;
    }
    else {
      unaff_r7 = pcStack00000024 + (int)in_stack_00000028;
      unaff_r11 = unaff_r4 + (int)in_stack_00000028;
      uVar10 = FUN_10025ccc();
      unaff_r4 = (char *)uVar10;
      if (pcStack00000024 == (char *)0x0) goto LAB_10023294;
    }
    unaff_r4 = (char *)uVar10;
    if ((int)unaff_r11 < 1) {
      if (iVar7 != 0) {
        FUN_1002329e();
        return;
      }
      goto LAB_10023a42;
    }
    pcVar8 = pcStack00000024;
    if ((int)unaff_r11 < (int)pcStack00000024) {
      pcVar8 = unaff_r11;
    }
    if (iVar7 != 0) {
      FUN_1002329e(unaff_r4,(int)((ulonglong)uVar10 >> 0x20),unaff_r11);
    }
    FUN_100232b4();
    pcVar1 = pcStack00000024 + -(int)pcVar8;
    pcVar6 = pcVar4;
    pcStack00000024 = unaff_r7 + -(int)pcVar8;
  } while( true );
LAB_10023d72:
  *pcVar8 = '9';
  FUN_100231fe((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),in_stack_0000000c);
  pcVar4 = pcVar6;
  pcVar6 = pcVar1;
  pcVar8 = pcVar9;
LAB_10023d8c:
  if ((int)pcStack00000024 < 1) goto LAB_10023784;
LAB_10023762:
  pcVar1 = (char *)FUN_10025fb4();
  uVar10 = FUN_100260a8(pcVar1,iStack00000018);
  if (((int)uVar10 < 1) && (((int)uVar10 != 0 || (-1 < (int)pcVar6 << 0x1f)))) goto LAB_10023784;
  if (pcVar6 != (char *)0x39) {
LAB_10023780:
    pcVar6 = (char *)(iVar7 + 0x31);
LAB_10023784:
    *pcVar8 = (char)pcVar6;
    FUN_1002320c();
    return;
  }
  pcVar6 = (char *)0x39;
  pcVar9 = unaff_r4;
  unaff_r4 = pcVar4;
  goto LAB_10023d72;
LAB_10023294:
  if (iVar7 == 0) {
LAB_10023a42:
    FUN_100232b4();
    return;
  }
  unaff_r6 = (char *)0x0;
  goto code_r0x1002329e;
}



/* FUN_100232a6 at 100232a6 */

/* WARNING: Removing unreachable block (ram,0x1002384e) */
/* WARNING: Removing unreachable block (ram,0x10023856) */
/* WARNING: Removing unreachable block (ram,0x10023858) */
/* WARNING: Removing unreachable block (ram,0x1002385e) */
/* WARNING: Removing unreachable block (ram,0x10023860) */
/* WARNING: Removing unreachable block (ram,0x10023184) */
/* WARNING: Removing unreachable block (ram,0x1002318a) */
/* WARNING: Removing unreachable block (ram,0x100231ae) */
/* WARNING: Removing unreachable block (ram,0x100231be) */
/* WARNING: Removing unreachable block (ram,0x100231cc) */
/* WARNING: Removing unreachable block (ram,0x100231d0) */
/* WARNING: Removing unreachable block (ram,0x100231f0) */
/* WARNING: Removing unreachable block (ram,0x1002357e) */
/* WARNING: Removing unreachable block (ram,0x10023584) */
/* WARNING: Removing unreachable block (ram,0x1002358e) */
/* WARNING: Removing unreachable block (ram,0x10023582) */
/* WARNING: Removing unreachable block (ram,0x100231f2) */
/* WARNING: Removing unreachable block (ram,0x1002319e) */

void FUN_100232a6(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  int extraout_r3;
  char *pcVar8;
  char *unaff_r4;
  char *pcVar9;
  char *unaff_r6;
  char *unaff_r7;
  char *unaff_r11;
  undefined8 uVar10;
  char *in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int iStack00000018;
  char *pcStack00000024;
  char *in_stack_00000028;
  uint in_stack_00000030;
  int in_stack_00000034;
  char *in_stack_00000040;
  int in_stack_00000098;
  
code_r0x100232a6:
  pcVar1 = (char *)FUN_10025ea8();
  iStack00000018 = FUN_10025ccc();
  if (in_stack_00000030 != 0) {
    FUN_10023bac();
  }
  if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) && ((in_stack_00000014 & 0xfffff) == 0)
      ) && ((in_stack_00000014 & 0x7ff00000) != 0)) {
    pcStack00000024 = unaff_r7 + 1;
    iVar7 = 1;
    unaff_r11 = unaff_r11 + 1;
    in_stack_00000030 = 1;
  }
  else {
    iVar7 = 1;
    pcStack00000024 = unaff_r7;
  }
  do {
    uVar5 = (uint)(unaff_r11 + iVar7) & 0x1f;
    if (((uint)(unaff_r11 + iVar7) & 0x1f) == 0) {
      iVar7 = 0x1c;
LAB_1002313a:
      unaff_r6 = unaff_r6 + iVar7;
      pcStack00000024 = pcStack00000024 + iVar7;
      unaff_r11 = unaff_r11 + iVar7;
    }
    else {
      if (4 < (int)(0x20 - uVar5)) {
        iVar7 = 0x1c - uVar5;
        goto LAB_1002313a;
      }
      if (0x20 - uVar5 != 4) {
        iVar7 = 0x3c - uVar5;
        goto LAB_1002313a;
      }
    }
    if (0 < (int)pcStack00000024) {
      pcVar1 = (char *)FUN_10025fb4();
    }
    if (0 < (int)unaff_r11) {
      iStack00000018 = FUN_10025fb4();
    }
    if ((in_stack_00000034 != 0) && (iVar7 = FUN_100260a8(pcVar1,iStack00000018), iVar7 < 0)) {
      pcVar1 = (char *)FUN_10025a90();
      unaff_r4 = (char *)FUN_10025a90();
      in_stack_00000028 = in_stack_00000040;
    }
    if ((0 < (int)in_stack_00000028) || (in_stack_00000098 < 3)) break;
    if (in_stack_00000028 == (char *)0x0) {
      iStack00000018 = FUN_10025a90();
      iVar7 = FUN_100260a8(pcVar1,iStack00000018);
      if (0 < iVar7) {
        *in_stack_0000000c = '1';
        FUN_10025a44();
        if (unaff_r4 == (char *)0x0) {
          FUN_1002306c();
          return;
        }
        FUN_1002322c();
        return;
      }
    }
    FUN_10025a44();
    if (unaff_r4 != (char *)0x0) {
      FUN_1002322c();
    }
    FUN_1002306c();
    if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
       ((in_stack_00000014 & 0x7ff00000) != 0)) {
      pcStack00000024 = pcStack00000024 + 1;
      in_stack_00000030 = 1;
      unaff_r11 = unaff_r11 + 1;
    }
    iVar7 = FUN_10025bdc(*(undefined4 *)
                          (*(int *)(iStack00000018 + 0x10) * 4 + iStack00000018 + 0x10));
    iVar7 = 0x20 - iVar7;
    unaff_r6 = in_stack_0000000c;
  } while( true );
  if (0 < (int)unaff_r6) {
    unaff_r4 = (char *)FUN_10025fb4();
  }
  pcVar4 = unaff_r4;
  if (in_stack_00000030 != 0) {
    iVar7 = FUN_100259c0();
    if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded");
    }
    FUN_1001f4d4(iVar7 + 0xc,unaff_r4 + 0xc,(*(int *)(unaff_r4 + 0x10) + 2) * 4);
    pcVar4 = (char *)FUN_10025fb4();
  }
  in_stack_00000028 = in_stack_00000028 + (int)(in_stack_0000000c + -1);
  in_stack_00000030 = in_stack_00000010 & 1;
  pcVar8 = in_stack_0000000c;
LAB_100236a2:
  iVar7 = FUN_10022c2c(pcVar1,iStack00000018);
  pcVar6 = (char *)(iVar7 + 0x30);
  iVar2 = FUN_100260a8(pcVar1,unaff_r4);
  iVar3 = FUN_100260e4();
  pcVar9 = unaff_r4;
  if (*(int *)(iVar3 + 0xc) != 0) {
    uVar10 = FUN_10025a44();
    if (iVar2 < 0) goto LAB_10023762;
    if ((in_stack_00000010 & 1) == 0 && (iVar2 == 0 && in_stack_00000098 == 0)) goto LAB_10023762;
LAB_100237c2:
    unaff_r4 = pcVar4;
    if (pcVar6 != (char *)0x39) {
      *pcVar8 = (char)iVar7 + '1';
      FUN_1002320c();
      return;
    }
    goto LAB_10023d72;
  }
  pcStack00000024 = (char *)FUN_100260a8(pcVar1,iVar3);
  uVar10 = FUN_10025a44();
  if (pcStack00000024 == (char *)0x0 && in_stack_00000098 == 0) {
    if (in_stack_00000030 == 0) {
      unaff_r4 = pcVar4;
      if (pcVar6 == (char *)0x39) goto LAB_10023d72;
      if (iVar2 < 1) goto LAB_10023784;
      goto LAB_10023780;
    }
    if (iVar2 < 0) goto LAB_10023784;
  }
  else {
    if (iVar2 < 0) goto LAB_10023d8c;
    if ((iVar2 == 0 && in_stack_00000098 == 0) && in_stack_00000030 == 0) goto LAB_10023d8c;
    if (0 < (int)pcStack00000024) goto LAB_100237c2;
  }
  pcVar9 = pcVar8 + 1;
  *pcVar8 = (char)pcVar6;
  if (pcVar8 != in_stack_00000028) {
    pcVar1 = (char *)FUN_10025a90();
    pcVar8 = pcVar9;
    if (unaff_r4 == pcVar4) {
      unaff_r4 = (char *)FUN_10025a90();
      pcVar4 = unaff_r4;
    }
    else {
      unaff_r4 = (char *)FUN_10025a90();
      pcVar4 = (char *)FUN_10025a90();
    }
    goto LAB_100236a2;
  }
  do {
    pcVar4 = pcVar1;
    FUN_100231da();
    FUN_100233d4();
    *pcVar6 = '1';
    FUN_1002306c();
    *in_stack_0000000c = '1';
    FUN_1002320c();
    pcVar9 = (char *)(extraout_r3 - (int)pcVar9);
    if ((int)in_stack_00000028 < 0) {
      uVar10 = FUN_10025ccc();
      unaff_r7 = pcStack00000024;
      unaff_r11 = unaff_r4;
      pcStack00000024 = pcStack00000024 + -(int)in_stack_00000028;
    }
    else {
      unaff_r7 = pcStack00000024 + (int)in_stack_00000028;
      unaff_r11 = unaff_r4 + (int)in_stack_00000028;
      uVar10 = FUN_10025ccc();
      unaff_r4 = (char *)uVar10;
      if (pcStack00000024 == (char *)0x0) goto LAB_10023294;
    }
    unaff_r4 = (char *)uVar10;
    if ((int)unaff_r11 < 1) {
      if (iVar7 != 0) {
        FUN_1002329e();
        return;
      }
      goto LAB_10023a42;
    }
    pcVar8 = pcStack00000024;
    if ((int)unaff_r11 < (int)pcStack00000024) {
      pcVar8 = unaff_r11;
    }
    if (iVar7 != 0) {
      FUN_1002329e(unaff_r4,(int)((ulonglong)uVar10 >> 0x20),unaff_r11);
    }
    FUN_100232b4();
    pcVar1 = pcStack00000024 + -(int)pcVar8;
    pcVar6 = pcVar4;
    pcStack00000024 = unaff_r7 + -(int)pcVar8;
  } while( true );
LAB_10023d72:
  *pcVar8 = '9';
  FUN_100231fe((int)uVar10,(int)((ulonglong)uVar10 >> 0x20),in_stack_0000000c);
  pcVar4 = pcVar6;
  pcVar6 = pcVar1;
  pcVar8 = pcVar9;
LAB_10023d8c:
  if ((int)pcStack00000024 < 1) goto LAB_10023784;
LAB_10023762:
  pcVar1 = (char *)FUN_10025fb4();
  uVar10 = FUN_100260a8(pcVar1,iStack00000018);
  if (((int)uVar10 < 1) && (((int)uVar10 != 0 || (-1 < (int)pcVar6 << 0x1f)))) goto LAB_10023784;
  if (pcVar6 != (char *)0x39) {
LAB_10023780:
    pcVar6 = (char *)(iVar7 + 0x31);
LAB_10023784:
    *pcVar8 = (char)pcVar6;
    FUN_1002320c();
    return;
  }
  pcVar6 = (char *)0x39;
  pcVar9 = unaff_r4;
  unaff_r4 = pcVar4;
  goto LAB_10023d72;
LAB_10023294:
  if (iVar7 == 0) {
LAB_10023a42:
    FUN_100232b4();
    return;
  }
  unaff_r6 = (char *)0x0;
  if (pcVar9 != (char *)0x0) {
    FUN_10023c1c();
  }
  goto code_r0x100232a6;
}



/* FUN_100232b4 at 100232b4 */

/* WARNING: Removing unreachable block (ram,0x1002384e) */
/* WARNING: Removing unreachable block (ram,0x10023856) */
/* WARNING: Removing unreachable block (ram,0x10023858) */
/* WARNING: Removing unreachable block (ram,0x1002385e) */
/* WARNING: Removing unreachable block (ram,0x10023860) */
/* WARNING: Removing unreachable block (ram,0x10023184) */
/* WARNING: Removing unreachable block (ram,0x1002318a) */
/* WARNING: Removing unreachable block (ram,0x100231ae) */
/* WARNING: Removing unreachable block (ram,0x100231be) */
/* WARNING: Removing unreachable block (ram,0x100231cc) */
/* WARNING: Removing unreachable block (ram,0x100231d0) */
/* WARNING: Removing unreachable block (ram,0x100231f0) */
/* WARNING: Removing unreachable block (ram,0x1002357e) */
/* WARNING: Removing unreachable block (ram,0x10023584) */
/* WARNING: Removing unreachable block (ram,0x1002358e) */
/* WARNING: Removing unreachable block (ram,0x10023582) */
/* WARNING: Removing unreachable block (ram,0x100231f2) */
/* WARNING: Removing unreachable block (ram,0x1002319e) */

void FUN_100232b4(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  int extraout_r3;
  char *pcVar7;
  char *unaff_r4;
  char *pcVar8;
  char *unaff_r6;
  char *unaff_r7;
  char *unaff_r10;
  char *unaff_r11;
  undefined8 uVar9;
  char *in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int iStack00000018;
  char *in_stack_00000024;
  char *in_stack_00000028;
  uint in_stack_00000030;
  int in_stack_00000034;
  char *in_stack_00000040;
  int in_stack_00000098;
  
code_r0x100232b4:
  iStack00000018 = FUN_10025ccc();
  if (in_stack_00000030 != 0) {
    FUN_10023bac();
  }
  if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) && ((in_stack_00000014 & 0xfffff) == 0)
      ) && ((in_stack_00000014 & 0x7ff00000) != 0)) {
    in_stack_00000024 = unaff_r7 + 1;
    iVar6 = 1;
    unaff_r11 = unaff_r11 + 1;
    in_stack_00000030 = 1;
  }
  else {
    iVar6 = 1;
  }
  do {
    uVar4 = (uint)(unaff_r11 + iVar6) & 0x1f;
    if (((uint)(unaff_r11 + iVar6) & 0x1f) == 0) {
      iVar6 = 0x1c;
LAB_1002313a:
      unaff_r6 = unaff_r6 + iVar6;
      in_stack_00000024 = in_stack_00000024 + iVar6;
      unaff_r11 = unaff_r11 + iVar6;
    }
    else {
      if (4 < (int)(0x20 - uVar4)) {
        iVar6 = 0x1c - uVar4;
        goto LAB_1002313a;
      }
      if (0x20 - uVar4 != 4) {
        iVar6 = 0x3c - uVar4;
        goto LAB_1002313a;
      }
    }
    if (0 < (int)in_stack_00000024) {
      unaff_r10 = (char *)FUN_10025fb4();
    }
    if (0 < (int)unaff_r11) {
      iStack00000018 = FUN_10025fb4();
    }
    if ((in_stack_00000034 != 0) && (iVar6 = FUN_100260a8(unaff_r10,iStack00000018), iVar6 < 0)) {
      unaff_r10 = (char *)FUN_10025a90();
      unaff_r4 = (char *)FUN_10025a90();
      in_stack_00000028 = in_stack_00000040;
    }
    if ((0 < (int)in_stack_00000028) || (in_stack_00000098 < 3)) break;
    if (in_stack_00000028 == (char *)0x0) {
      iStack00000018 = FUN_10025a90();
      iVar6 = FUN_100260a8(unaff_r10,iStack00000018);
      if (0 < iVar6) {
        *in_stack_0000000c = '1';
        FUN_10025a44();
        if (unaff_r4 == (char *)0x0) {
          FUN_1002306c();
          return;
        }
        FUN_1002322c();
        return;
      }
    }
    FUN_10025a44();
    if (unaff_r4 != (char *)0x0) {
      FUN_1002322c();
    }
    FUN_1002306c();
    if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
       ((in_stack_00000014 & 0x7ff00000) != 0)) {
      in_stack_00000024 = in_stack_00000024 + 1;
      in_stack_00000030 = 1;
      unaff_r11 = unaff_r11 + 1;
    }
    iVar6 = FUN_10025bdc(*(undefined4 *)
                          (*(int *)(iStack00000018 + 0x10) * 4 + iStack00000018 + 0x10));
    iVar6 = 0x20 - iVar6;
    unaff_r6 = in_stack_0000000c;
  } while( true );
  if (0 < (int)unaff_r6) {
    unaff_r4 = (char *)FUN_10025fb4();
  }
  pcVar3 = unaff_r4;
  if (in_stack_00000030 != 0) {
    iVar6 = FUN_100259c0();
    if (iVar6 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded");
    }
    FUN_1001f4d4(iVar6 + 0xc,unaff_r4 + 0xc,(*(int *)(unaff_r4 + 0x10) + 2) * 4);
    pcVar3 = (char *)FUN_10025fb4();
  }
  in_stack_00000028 = in_stack_00000028 + (int)(in_stack_0000000c + -1);
  in_stack_00000030 = in_stack_00000010 & 1;
  pcVar7 = in_stack_0000000c;
LAB_100236a2:
  iVar6 = FUN_10022c2c(unaff_r10,iStack00000018);
  pcVar5 = (char *)(iVar6 + 0x30);
  iVar1 = FUN_100260a8(unaff_r10,unaff_r4);
  iVar2 = FUN_100260e4();
  pcVar8 = unaff_r4;
  if (*(int *)(iVar2 + 0xc) != 0) {
    uVar9 = FUN_10025a44();
    if (iVar1 < 0) goto LAB_10023762;
    if ((in_stack_00000010 & 1) == 0 && (iVar1 == 0 && in_stack_00000098 == 0)) goto LAB_10023762;
LAB_100237c2:
    unaff_r4 = pcVar3;
    if (pcVar5 != (char *)0x39) {
      *pcVar7 = (char)iVar6 + '1';
      FUN_1002320c();
      return;
    }
    goto LAB_10023d72;
  }
  in_stack_00000024 = (char *)FUN_100260a8(unaff_r10,iVar2);
  uVar9 = FUN_10025a44();
  if (in_stack_00000024 == (char *)0x0 && in_stack_00000098 == 0) {
    if (in_stack_00000030 == 0) {
      unaff_r4 = pcVar3;
      if (pcVar5 == (char *)0x39) goto LAB_10023d72;
      if (iVar1 < 1) goto LAB_10023784;
      goto LAB_10023780;
    }
    if (iVar1 < 0) goto LAB_10023784;
  }
  else {
    if (iVar1 < 0) goto LAB_10023d8c;
    if ((iVar1 == 0 && in_stack_00000098 == 0) && in_stack_00000030 == 0) goto LAB_10023d8c;
    if (0 < (int)in_stack_00000024) goto LAB_100237c2;
  }
  pcVar8 = pcVar7 + 1;
  *pcVar7 = (char)pcVar5;
  if (pcVar7 != in_stack_00000028) {
    unaff_r10 = (char *)FUN_10025a90();
    pcVar7 = pcVar8;
    if (unaff_r4 == pcVar3) {
      unaff_r4 = (char *)FUN_10025a90();
      pcVar3 = unaff_r4;
    }
    else {
      unaff_r4 = (char *)FUN_10025a90();
      pcVar3 = (char *)FUN_10025a90();
    }
    goto LAB_100236a2;
  }
  do {
    pcVar3 = unaff_r10;
    FUN_100231da();
    FUN_100233d4();
    *pcVar5 = '1';
    FUN_1002306c();
    *in_stack_0000000c = '1';
    FUN_1002320c();
    pcVar8 = (char *)(extraout_r3 - (int)pcVar8);
    if ((int)in_stack_00000028 < 0) {
      uVar9 = FUN_10025ccc();
      unaff_r7 = in_stack_00000024;
      unaff_r11 = unaff_r4;
      in_stack_00000024 = in_stack_00000024 + -(int)in_stack_00000028;
    }
    else {
      unaff_r7 = in_stack_00000024 + (int)in_stack_00000028;
      unaff_r11 = unaff_r4 + (int)in_stack_00000028;
      uVar9 = FUN_10025ccc();
      unaff_r4 = (char *)uVar9;
      if (in_stack_00000024 == (char *)0x0) goto LAB_10023294;
    }
    unaff_r4 = (char *)uVar9;
    if ((int)unaff_r11 < 1) {
      if (iVar6 != 0) {
        FUN_1002329e();
        return;
      }
      goto LAB_10023a42;
    }
    pcVar7 = in_stack_00000024;
    if ((int)unaff_r11 < (int)in_stack_00000024) {
      pcVar7 = unaff_r11;
    }
    if (iVar6 != 0) {
      FUN_1002329e(unaff_r4,(int)((ulonglong)uVar9 >> 0x20),unaff_r11);
    }
    FUN_100232b4();
    unaff_r10 = in_stack_00000024 + -(int)pcVar7;
    pcVar5 = pcVar3;
    in_stack_00000024 = unaff_r7 + -(int)pcVar7;
  } while( true );
LAB_10023d72:
  *pcVar7 = '9';
  FUN_100231fe((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),in_stack_0000000c);
  pcVar3 = pcVar5;
  pcVar5 = unaff_r10;
  pcVar7 = pcVar8;
LAB_10023d8c:
  if ((int)in_stack_00000024 < 1) goto LAB_10023784;
LAB_10023762:
  unaff_r10 = (char *)FUN_10025fb4();
  uVar9 = FUN_100260a8(unaff_r10,iStack00000018);
  if (((int)uVar9 < 1) && (((int)uVar9 != 0 || (-1 < (int)pcVar5 << 0x1f)))) goto LAB_10023784;
  if (pcVar5 != (char *)0x39) {
LAB_10023780:
    pcVar5 = (char *)(iVar6 + 0x31);
LAB_10023784:
    *pcVar7 = (char)pcVar5;
    FUN_1002320c();
    return;
  }
  pcVar5 = (char *)0x39;
  pcVar8 = unaff_r4;
  unaff_r4 = pcVar3;
  goto LAB_10023d72;
LAB_10023294:
  if (iVar6 == 0) {
LAB_10023a42:
    FUN_100232b4();
    return;
  }
  unaff_r6 = (char *)0x0;
  if (pcVar8 != (char *)0x0) {
    FUN_10023c1c();
  }
  unaff_r10 = (char *)FUN_10025ea8();
  in_stack_00000024 = unaff_r7;
  goto code_r0x100232b4;
}



/* FUN_100233d4 at 100233d4 */

/* WARNING: Removing unreachable block (ram,0x1002384e) */
/* WARNING: Removing unreachable block (ram,0x10023856) */
/* WARNING: Removing unreachable block (ram,0x10023858) */
/* WARNING: Removing unreachable block (ram,0x1002385e) */
/* WARNING: Removing unreachable block (ram,0x10023860) */
/* WARNING: Removing unreachable block (ram,0x10023184) */
/* WARNING: Removing unreachable block (ram,0x1002318a) */
/* WARNING: Removing unreachable block (ram,0x100231ae) */
/* WARNING: Removing unreachable block (ram,0x100231be) */
/* WARNING: Removing unreachable block (ram,0x100231cc) */
/* WARNING: Removing unreachable block (ram,0x100231d0) */
/* WARNING: Removing unreachable block (ram,0x100231f0) */
/* WARNING: Removing unreachable block (ram,0x1002357e) */
/* WARNING: Removing unreachable block (ram,0x10023584) */
/* WARNING: Removing unreachable block (ram,0x1002358e) */
/* WARNING: Removing unreachable block (ram,0x10023582) */
/* WARNING: Removing unreachable block (ram,0x100231f2) */
/* WARNING: Removing unreachable block (ram,0x1002319e) */

void FUN_100233d4(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int extraout_r1;
  int extraout_r3;
  undefined4 uVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *unaff_r8;
  char *unaff_r10;
  char *unaff_r11;
  undefined8 uVar12;
  undefined8 uVar13;
  undefined8 uVar14;
  ulonglong uVar15;
  char *in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  int in_stack_00000020;
  char *in_stack_00000024;
  char *in_stack_00000028;
  int in_stack_0000002c;
  uint in_stack_00000030;
  int in_stack_00000034;
  char *in_stack_00000038;
  undefined4 in_stack_0000003c;
  char *in_stack_00000040;
  char *pcStack00000044;
  int in_stack_00000048;
  int iStack00000054;
  int in_stack_0000006c;
  int in_stack_00000098;
  int *in_stack_000000a0;
  undefined4 *in_stack_000000a8;
  
  uVar14 = CONCAT44(in_stack_0000003c,in_stack_00000038);
  if ((in_stack_00000034 == 0) ||
     (iVar2 = FUN_1001ea3c(in_stack_00000038,in_stack_0000003c,0,0x3ff00000), iVar2 == 0)) {
    uVar12 = FUN_1001ea84();
    uVar12 = FUN_1001e9a6((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),in_stack_00000038,
                          in_stack_0000003c);
    uVar12 = FUN_1001e958((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0,0x401c0000);
    iVar2 = (int)((ulonglong)uVar12 >> 0x20);
    uVar3 = (undefined4)uVar12;
    iVar8 = iVar2 + -0x3400000;
    iStack00000054 = in_stack_00000020;
    pcStack00000044 = in_stack_00000028;
    if (in_stack_00000028 == (char *)0x0) {
      uVar14 = FUN_1001e946(in_stack_00000038,in_stack_0000003c,0,0x40140000);
      uVar5 = (undefined4)((ulonglong)uVar14 >> 0x20);
      iVar8 = FUN_1001ea58((int)uVar14,uVar5,uVar3,iVar8);
      if (iVar8 == 0) {
        iVar2 = FUN_1001ea3c((int)uVar14,uVar5,uVar3,iVar2 + 0x7cc00000);
        if (iVar2 == 0) {
          FUN_10022ff6();
          return;
        }
        FUN_10025a44();
        FUN_1002306c();
        return;
      }
      *in_stack_0000000c = '1';
      FUN_10025a44();
      FUN_10025a44();
      in_stack_0000000c[1] = '\0';
      *in_stack_000000a0 = in_stack_00000020 + 2;
      if (in_stack_000000a8 == (undefined4 *)0x0) {
        FUN_10022e06();
        return;
      }
      *in_stack_000000a8 = in_stack_0000000c + 1;
      FUN_10022e06();
      return;
    }
  }
  else {
    if (in_stack_00000028 == (char *)0x0) {
      uVar14 = FUN_1001ea84();
      uVar14 = FUN_1001e9a6((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),in_stack_00000038,
                            in_stack_0000003c);
      FUN_1001e958((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0x401c0000);
      pcVar11 = (char *)(extraout_r1 + -0x3400000);
      FUN_1002341a();
      pcVar6 = (char *)0x0;
      uVar15 = FUN_100235a6();
      goto LAB_10023dfa;
    }
    if ((int)in_stack_00000040 < 1) {
      FUN_10022ff6();
    }
    iStack00000054 = in_stack_00000020 + -1;
    uVar14 = FUN_1001e9a6(in_stack_00000038,in_stack_0000003c,0,0x40240000);
    uVar12 = FUN_1001ea84(unaff_r8 + 1);
    uVar12 = FUN_1001e9a6((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar14,
                          (int)((ulonglong)uVar14 >> 0x20));
    uVar12 = FUN_1001e958((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),0,0x401c0000);
    uVar3 = (undefined4)uVar12;
    iVar8 = (int)((ulonglong)uVar12 >> 0x20) + -0x3400000;
    pcStack00000044 = in_stack_00000040;
  }
  in_stack_0000003c = (undefined4)((ulonglong)uVar14 >> 0x20);
  in_stack_00000038 = (char *)uVar14;
  uVar5 = *(undefined4 *)(&DAT_1002b35c + (int)(pcStack00000044 + -1) * 8);
  pcVar11 = *(char **)(&DAT_1002b358 + (int)(pcStack00000044 + -1) * 8);
  cVar1 = FUN_1001eab4(in_stack_00000038,in_stack_0000003c);
  uVar14 = FUN_1001ea84();
  uVar14 = FUN_1001e946(in_stack_00000038,in_stack_0000003c,(int)uVar14,
                        (int)((ulonglong)uVar14 >> 0x20));
  pcVar9 = in_stack_0000000c + 1;
  if (in_stack_00000048 != 0) {
    uVar12 = FUN_1001e96a(0,0x3fe00000,pcVar11,uVar5);
    uVar12 = FUN_1001e946((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),uVar3,iVar8);
    *in_stack_0000000c = cVar1 + '0';
    iVar2 = FUN_1001ea58((int)uVar12,(int)((ulonglong)uVar12 >> 0x20),(int)uVar14,
                         (int)((ulonglong)uVar14 >> 0x20));
    in_stack_00000038 = pcVar9;
    if (iVar2 == 0) {
      iVar2 = 0;
      do {
        uVar3 = (undefined4)((ulonglong)uVar12 >> 0x20);
        pcVar7 = (char *)((ulonglong)uVar14 >> 0x20);
        uVar13 = FUN_1001e946(0,0x3ff00000,(int)uVar14,pcVar7);
        iVar8 = FUN_1001ea3c((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),(int)uVar12,uVar3);
        pcVar10 = pcVar9;
        pcVar6 = pcVar9;
        if (iVar8 != 0) goto LAB_100239ec;
        iVar2 = iVar2 + 1;
        in_stack_00000038 = unaff_r10;
        if ((int)pcStack00000044 <= iVar2) goto LAB_10023e1a;
        uVar12 = FUN_1001e9a6((int)uVar12,uVar3,0,0x40240000);
        uVar14 = FUN_1001e9a6((int)uVar14,pcVar7,0,0x40240000);
        cVar1 = FUN_1001eab4();
        uVar13 = FUN_1001ea84();
        uVar14 = FUN_1001e946((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(int)uVar13,
                              (int)((ulonglong)uVar13 >> 0x20));
        in_stack_0000000c[iVar2] = cVar1 + '0';
        pcVar9 = pcVar9 + 1;
        iVar8 = FUN_1001ea3c((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(int)uVar12,
                             (int)((ulonglong)uVar12 >> 0x20));
        in_stack_00000038 = unaff_r10;
        pcVar11 = unaff_r11;
      } while (iVar8 == 0);
    }
    in_stack_00000020 = iStack00000054 + 1;
    FUN_1002306c();
    unaff_r11 = pcVar11;
LAB_10023e1a:
    if ((-1 < in_stack_0000006c) && (in_stack_00000020 < 0xf)) {
      FUN_1002300a();
    }
    pcVar7 = in_stack_00000028 + -1;
    iVar2 = in_stack_0000002c;
    if ((int)pcVar7 <= in_stack_0000002c) goto LAB_10023a14;
    FUN_10025ccc();
    if (in_stack_00000024 == (char *)0x0) {
      FUN_100232a6();
    }
    pcVar11 = in_stack_00000024;
    if ((int)(unaff_r11 + (int)in_stack_00000028) < (int)in_stack_00000024) {
      pcVar11 = unaff_r11 + (int)in_stack_00000028;
    }
    pcVar11 = in_stack_00000024 + -(int)pcVar11;
    FUN_100232a6();
LAB_10023e8c:
    FUN_100230e6();
    FUN_100233d4();
    pcVar11[4] = '\0';
    pcVar11[5] = '\0';
    pcVar11[6] = '\0';
    pcVar11[7] = '\0';
    FUN_10022fd4();
                    /* WARNING: Subroutine does not return */
    FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0xef,0,"REENT malloc succeeded");
  }
  uVar12 = FUN_1001e9a6(pcVar11,uVar5,uVar3,iVar8);
  uVar3 = (undefined4)((ulonglong)uVar12 >> 0x20);
  *in_stack_0000000c = cVar1 + '0';
  pcVar11 = pcStack00000044 + (int)in_stack_0000000c;
  pcVar10 = pcVar9;
  if (pcStack00000044 != (char *)0x1) {
    pcVar11 = pcVar9;
    do {
      uVar14 = FUN_1001e9a6((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0x40240000);
      cVar1 = FUN_1001eab4();
      uVar13 = FUN_1001ea84();
      uVar14 = FUN_1001e946((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),(int)uVar13,
                            (int)((ulonglong)uVar13 >> 0x20));
      *pcVar11 = cVar1 + '0';
      pcVar11 = pcVar11 + 1;
    } while (pcStack00000044 + (int)in_stack_0000000c != pcVar11);
    pcVar10 = in_stack_0000000c + (int)pcStack00000044;
  }
  pcVar7 = (char *)((ulonglong)uVar14 >> 0x20);
  uVar5 = (undefined4)uVar14;
  uVar14 = FUN_1001e958((int)uVar12,uVar3,0,0x3fe00000);
  iVar2 = FUN_1001ea3c((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),uVar5,pcVar7);
  pcVar6 = unaff_r11;
  if (iVar2 == 0) {
    uVar14 = FUN_1001e946(0,0x3fe00000,(int)uVar12,uVar3);
    iVar2 = FUN_1001ea58((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),uVar5,pcVar7);
    if (iVar2 != 0) {
      do {
        pcVar10 = pcVar10 + -1;
      } while (*pcVar10 == '0');
      uVar12 = FUN_1002306c();
      uVar14 = CONCAT44((int)((ulonglong)uVar12 >> 0x20),uVar5);
      uVar3 = (undefined4)uVar12;
      pcVar11 = unaff_r10;
      goto LAB_10023d1e;
    }
    if ((in_stack_0000006c < 0) || (0xe < in_stack_00000020)) goto LAB_10023e8c;
    in_stack_00000014 = *(uint *)(&DAT_1002b35c + in_stack_00000020 * 8);
    in_stack_00000010 = *(uint *)(&DAT_1002b358 + in_stack_00000020 * 8);
    FUN_1001e96a(in_stack_00000018,in_stack_0000001c,in_stack_00000010,in_stack_00000014);
    iVar2 = FUN_1001eab4();
    uVar14 = FUN_1001ea84();
    uVar14 = FUN_1001e9a6((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),in_stack_00000010,
                          in_stack_00000014);
    uVar14 = FUN_1001e946(in_stack_00000018,in_stack_0000001c,(int)uVar14,
                          (int)((ulonglong)uVar14 >> 0x20));
    *in_stack_0000000c = (char)iVar2 + '0';
    if (in_stack_00000028 != (char *)0x1) {
      unaff_r11 = in_stack_0000000c + -1;
      pcVar11 = (char *)0x1;
      do {
        uVar14 = FUN_1001e9a6((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),0,0x40240000);
        uVar5 = (undefined4)((ulonglong)uVar14 >> 0x20);
        uVar3 = (undefined4)uVar14;
        iVar2 = FUN_1001ea2c(uVar3,uVar5,0,0);
        if (iVar2 != 0) {
          FUN_1002306c();
          return;
        }
        FUN_1001e96a(uVar3,uVar5,in_stack_00000010,in_stack_00000014);
        iVar2 = FUN_1001eab4();
        uVar14 = FUN_1001ea84();
        uVar14 = FUN_1001e9a6((int)uVar14,(int)((ulonglong)uVar14 >> 0x20),in_stack_00000010,
                              in_stack_00000014);
        uVar14 = FUN_1001e946(uVar3,uVar5,(int)uVar14,(int)((ulonglong)uVar14 >> 0x20));
        pcVar11 = pcVar11 + 1;
        unaff_r11[(int)pcVar11] = (char)iVar2 + '0';
        pcVar9 = pcVar9 + 1;
      } while (in_stack_00000028 != pcVar11);
    }
    uVar3 = (undefined4)((ulonglong)uVar14 >> 0x20);
    uVar14 = FUN_1001e958((int)uVar14,uVar3,(int)uVar14,uVar3);
    pcVar7 = (char *)((ulonglong)uVar14 >> 0x20);
    iVar8 = FUN_1001ea58((int)uVar14,pcVar7,in_stack_00000010,in_stack_00000014);
    pcVar10 = pcVar9;
    pcVar6 = unaff_r11;
    if ((iVar8 == 0) &&
       ((iVar8 = FUN_1001ea2c((int)uVar14,pcVar7,in_stack_00000010,in_stack_00000014), iVar8 == 0 ||
        (-1 < iVar2 << 0x1f)))) {
      FUN_1002306c();
      FUN_100235a6();
      return;
    }
  }
LAB_100239ec:
  do {
    pcVar11 = pcVar10 + -1;
    if (*pcVar11 != '9') {
      cVar1 = *pcVar11 + '\x01';
      in_stack_00000038 = unaff_r10;
      unaff_r11 = pcVar6;
      goto LAB_100239fa;
    }
    pcVar10 = pcVar11;
  } while (pcVar11 != in_stack_0000000c);
LAB_10023d68:
  cVar1 = '1';
  in_stack_00000038 = unaff_r10;
  unaff_r11 = pcVar6;
LAB_100239fa:
  *pcVar11 = cVar1;
  FUN_1002306c();
  *in_stack_0000000c = '1';
  FUN_1002320c();
  iVar2 = extraout_r3;
LAB_10023a14:
  pcVar7 = (char *)(iVar2 - (int)pcVar7);
  if ((int)in_stack_00000028 < 0) {
    uVar14 = FUN_10025ccc();
    pcVar10 = in_stack_00000024;
    in_stack_00000024 = in_stack_00000024 + -(int)in_stack_00000028;
  }
  else {
    pcVar10 = in_stack_00000024 + (int)in_stack_00000028;
    unaff_r11 = unaff_r11 + (int)in_stack_00000028;
    uVar14 = FUN_10025ccc();
    pcVar6 = (char *)uVar14;
    if (in_stack_00000024 == (char *)0x0) {
      if (in_stack_0000002c != 0) {
        pcVar11 = (char *)0x0;
        if (pcVar7 != (char *)0x0) {
          FUN_10023c1c();
        }
        unaff_r10 = (char *)FUN_10025ea8();
        in_stack_00000018 = FUN_10025ccc();
        if (in_stack_00000030 != 0) {
          FUN_10023bac();
        }
        if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) &&
            ((in_stack_00000014 & 0xfffff) == 0)) && ((in_stack_00000014 & 0x7ff00000) != 0)) {
          in_stack_00000024 = pcVar10 + 1;
          iVar2 = 1;
          unaff_r11 = unaff_r11 + 1;
          in_stack_00000030 = 1;
        }
        else {
          iVar2 = 1;
          in_stack_00000024 = pcVar10;
        }
        do {
          uVar4 = (uint)(unaff_r11 + iVar2) & 0x1f;
          if (((uint)(unaff_r11 + iVar2) & 0x1f) == 0) {
            iVar2 = 0x1c;
LAB_1002313a:
            pcVar11 = pcVar11 + iVar2;
            in_stack_00000024 = in_stack_00000024 + iVar2;
            unaff_r11 = unaff_r11 + iVar2;
          }
          else {
            if (4 < (int)(0x20 - uVar4)) {
              iVar2 = 0x1c - uVar4;
              goto LAB_1002313a;
            }
            if (0x20 - uVar4 != 4) {
              iVar2 = 0x3c - uVar4;
              goto LAB_1002313a;
            }
          }
          if (0 < (int)in_stack_00000024) {
            unaff_r10 = (char *)FUN_10025fb4();
          }
          if (0 < (int)unaff_r11) {
            in_stack_00000018 = FUN_10025fb4();
          }
          if ((in_stack_00000034 != 0) &&
             (iVar2 = FUN_100260a8(unaff_r10,in_stack_00000018), iVar2 < 0)) {
            unaff_r10 = (char *)FUN_10025a90();
            pcVar6 = (char *)FUN_10025a90();
            in_stack_00000028 = in_stack_00000040;
          }
          if ((0 < (int)in_stack_00000028) || (in_stack_00000098 < 3)) goto LAB_1002366c;
          if (in_stack_00000028 == (char *)0x0) {
            in_stack_00000018 = FUN_10025a90();
            iVar2 = FUN_100260a8(unaff_r10,in_stack_00000018);
            if (0 < iVar2) {
              *in_stack_0000000c = '1';
              FUN_10025a44();
              if (pcVar6 == (char *)0x0) {
                FUN_1002306c();
                return;
              }
              FUN_1002322c();
              return;
            }
          }
          FUN_10025a44();
          if (pcVar6 != (char *)0x0) {
            FUN_1002322c();
          }
          FUN_1002306c();
          if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
             ((in_stack_00000014 & 0x7ff00000) != 0)) {
            in_stack_00000024 = in_stack_00000024 + 1;
            in_stack_00000030 = 1;
            unaff_r11 = unaff_r11 + 1;
          }
          iVar2 = FUN_10025bdc(*(undefined4 *)
                                (*(int *)(in_stack_00000018 + 0x10) * 4 + in_stack_00000018 + 0x10))
          ;
          iVar2 = 0x20 - iVar2;
          pcVar11 = in_stack_0000000c;
        } while( true );
      }
      goto LAB_10023a42;
    }
  }
  uVar3 = (undefined4)uVar14;
  pcVar11 = in_stack_00000038;
  if ((int)unaff_r11 < 1) {
    if (in_stack_0000002c != 0) {
      FUN_1002329e();
      return;
    }
LAB_10023a42:
    FUN_100232b4();
    return;
  }
LAB_10023d1e:
  pcVar6 = (char *)uVar14;
  pcVar9 = in_stack_00000024;
  if ((int)unaff_r11 < (int)in_stack_00000024) {
    pcVar9 = unaff_r11;
  }
  unaff_r10 = in_stack_00000024 + -(int)pcVar9;
  if (in_stack_0000002c != 0) {
    FUN_1002329e(uVar3,(int)((ulonglong)uVar14 >> 0x20),unaff_r11);
  }
  FUN_100232b4();
  in_stack_00000024 = pcVar10 + -(int)pcVar9;
  goto LAB_10023d44;
LAB_1002366c:
  if (0 < (int)pcVar11) {
    pcVar6 = (char *)FUN_10025fb4();
  }
  unaff_r8 = pcVar6;
  if (in_stack_00000030 != 0) {
    iVar2 = FUN_100259c0();
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded");
    }
    FUN_1001f4d4(iVar2 + 0xc,pcVar6 + 0xc,(*(int *)(pcVar6 + 0x10) + 2) * 4);
    unaff_r8 = (char *)FUN_10025fb4();
  }
  in_stack_00000028 = in_stack_00000028 + (int)(in_stack_0000000c + -1);
  in_stack_00000030 = in_stack_00000010 & 1;
  unaff_r11 = in_stack_0000000c;
LAB_100236a2:
  in_stack_0000002c = FUN_10022c2c(unaff_r10,in_stack_00000018);
  pcVar11 = (char *)(in_stack_0000002c + 0x30);
  iVar2 = FUN_100260a8(unaff_r10,pcVar6);
  iVar8 = FUN_100260e4();
  pcVar9 = pcVar6;
  if (*(int *)(iVar8 + 0xc) != 0) {
    uVar15 = FUN_10025a44();
    if (iVar2 < 0) goto LAB_10023762;
    if ((in_stack_00000010 & 1) == 0 && (iVar2 == 0 && in_stack_00000098 == 0)) goto LAB_10023762;
LAB_100237c2:
    pcVar6 = unaff_r8;
    if (pcVar11 != (char *)0x39) {
      *unaff_r11 = (char)in_stack_0000002c + '1';
      FUN_1002320c();
      return;
    }
    goto LAB_10023d72;
  }
  in_stack_00000024 = (char *)FUN_100260a8(unaff_r10,iVar8);
  uVar15 = FUN_10025a44();
  if (in_stack_00000024 == (char *)0x0 && in_stack_00000098 == 0) {
    if (in_stack_00000030 == 0) {
      pcVar6 = unaff_r8;
      if (pcVar11 == (char *)0x39) goto LAB_10023d72;
      if (iVar2 < 1) goto LAB_10023784;
      goto LAB_10023780;
    }
    if (iVar2 < 0) goto LAB_10023784;
  }
  else {
    if (iVar2 < 0) goto LAB_10023d8c;
    if ((iVar2 == 0 && in_stack_00000098 == 0) && in_stack_00000030 == 0) goto LAB_10023d8c;
    if (0 < (int)in_stack_00000024) goto LAB_100237c2;
  }
  pcVar7 = unaff_r11 + 1;
  *unaff_r11 = (char)pcVar11;
  if (unaff_r11 != in_stack_00000028) {
    unaff_r10 = (char *)FUN_10025a90();
    unaff_r11 = pcVar7;
    if (pcVar6 == unaff_r8) {
      pcVar6 = (char *)FUN_10025a90();
      unaff_r8 = pcVar6;
    }
    else {
      pcVar6 = (char *)FUN_10025a90();
      unaff_r8 = (char *)FUN_10025a90();
    }
    goto LAB_100236a2;
  }
LAB_10023d44:
  FUN_100231da();
  FUN_100233d4();
  goto LAB_10023d68;
LAB_10023d72:
  *unaff_r11 = '9';
  FUN_100231fe((int)uVar15,(int)(uVar15 >> 0x20),in_stack_0000000c);
  unaff_r8 = pcVar11;
  pcVar11 = unaff_r10;
  unaff_r11 = pcVar9;
LAB_10023d8c:
  if ((int)in_stack_00000024 < 1) goto LAB_10023784;
LAB_10023762:
  unaff_r10 = (char *)FUN_10025fb4();
  uVar15 = FUN_100260a8(unaff_r10,in_stack_00000018);
  if ((int)uVar15 < 1) {
LAB_10023dfa:
    if (((int)uVar15 != 0) || (-1 < (int)pcVar11 << 0x1f)) goto LAB_10023784;
    uVar15 = uVar15 & 0xffffffff00000000;
  }
  if (pcVar11 != (char *)0x39) {
LAB_10023780:
    pcVar11 = (char *)(in_stack_0000002c + 0x31);
LAB_10023784:
    *unaff_r11 = (char)pcVar11;
    FUN_1002320c();
    return;
  }
  pcVar11 = (char *)0x39;
  pcVar9 = pcVar6;
  pcVar6 = unaff_r8;
  goto LAB_10023d72;
}



/* FUN_1002341a at 1002341a */

void FUN_1002341a(void)

{
  int iVar1;
  undefined8 uVar2;
  undefined1 *in_stack_0000000c;
  int in_stack_00000020;
  undefined4 in_stack_00000038;
  undefined4 in_stack_0000003c;
  int *in_stack_000000a0;
  undefined4 *in_stack_000000a8;
  
  uVar2 = FUN_1001e946(in_stack_00000038,in_stack_0000003c,0,0x40140000);
  iVar1 = FUN_1001ea58();
  if (iVar1 == 0) {
    iVar1 = FUN_1001ea3c((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
    if (iVar1 == 0) {
      FUN_10022ff6();
      return;
    }
    FUN_10025a44();
    FUN_1002306c();
    return;
  }
  *in_stack_0000000c = 0x31;
  FUN_10025a44();
  FUN_10025a44();
  in_stack_0000000c[1] = 0;
  *in_stack_000000a0 = in_stack_00000020 + 2;
  if (in_stack_000000a8 == (undefined4 *)0x0) {
    FUN_10022e06();
    return;
  }
  *in_stack_000000a8 = in_stack_0000000c + 1;
  FUN_10022e06();
  return;
}



/* FUN_100235a6 at 100235a6 */

void FUN_100235a6(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  char *pcVar7;
  int extraout_r3;
  char *pcVar8;
  char *unaff_r4;
  char *pcVar9;
  char *unaff_r6;
  char *pcVar10;
  char *unaff_r10;
  char *unaff_r11;
  undefined8 uVar11;
  char *in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int iStack00000018;
  char *in_stack_00000024;
  char *in_stack_00000028;
  int in_stack_0000002c;
  uint uStack00000030;
  int in_stack_00000034;
  char *in_stack_00000040;
  int in_stack_00000098;
  
  iStack00000018 = FUN_10025ea8();
  uStack00000030 = 0;
  if (1 < in_stack_00000098) goto LAB_100235be;
LAB_10023b16:
  if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
     ((in_stack_00000014 & 0x7ff00000) != 0)) {
    in_stack_00000024 = in_stack_00000024 + 1;
    uStack00000030 = 1;
    unaff_r11 = unaff_r11 + 1;
  }
LAB_100235be:
  iVar2 = FUN_10025bdc(*(undefined4 *)(*(int *)(iStack00000018 + 0x10) * 4 + iStack00000018 + 0x10))
  ;
  iVar2 = 0x20 - iVar2;
LAB_1002311e:
  uVar6 = (uint)(unaff_r11 + iVar2) & 0x1f;
  if (((uint)(unaff_r11 + iVar2) & 0x1f) == 0) {
    iVar2 = 0x1c;
LAB_1002313a:
    unaff_r6 = unaff_r6 + iVar2;
    in_stack_00000024 = in_stack_00000024 + iVar2;
    unaff_r11 = unaff_r11 + iVar2;
  }
  else {
    if (4 < (int)(0x20 - uVar6)) {
      iVar2 = 0x1c - uVar6;
      goto LAB_1002313a;
    }
    if (0x20 - uVar6 != 4) {
      iVar2 = 0x3c - uVar6;
      goto LAB_1002313a;
    }
  }
  if (0 < (int)in_stack_00000024) {
    unaff_r10 = (char *)FUN_10025fb4();
  }
  if (0 < (int)unaff_r11) {
    iStack00000018 = FUN_10025fb4();
  }
  if ((in_stack_00000034 == 0) || (iVar2 = FUN_100260a8(unaff_r10,iStack00000018), -1 < iVar2)) {
    if (((int)in_stack_00000028 < 1) && (2 < in_stack_00000098)) goto LAB_100237e6;
    if (in_stack_0000002c != 0) goto LAB_1002366c;
  }
  else {
    unaff_r10 = (char *)FUN_10025a90();
    if (in_stack_0000002c != 0) {
      unaff_r4 = (char *)FUN_10025a90();
      in_stack_00000028 = in_stack_00000040;
      if ((0 < (int)in_stack_00000040) || (in_stack_00000098 < 3)) {
LAB_1002366c:
        if (0 < (int)unaff_r6) {
          unaff_r4 = (char *)FUN_10025fb4();
        }
        pcVar5 = unaff_r4;
        if (uStack00000030 != 0) {
          iVar2 = FUN_100259c0();
          if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded"
                        );
          }
          FUN_1001f4d4(iVar2 + 0xc,unaff_r4 + 0xc,(*(int *)(unaff_r4 + 0x10) + 2) * 4);
          pcVar5 = (char *)FUN_10025fb4();
        }
        in_stack_00000028 = in_stack_00000028 + (int)(in_stack_0000000c + -1);
        uStack00000030 = in_stack_00000010 & 1;
        pcVar10 = in_stack_0000000c;
LAB_100236a2:
        iVar2 = FUN_10022c2c(unaff_r10,iStack00000018);
        pcVar7 = (char *)(iVar2 + 0x30);
        iVar3 = FUN_100260a8(unaff_r10,unaff_r4);
        iVar4 = FUN_100260e4();
        pcVar9 = unaff_r4;
        if (*(int *)(iVar4 + 0xc) != 0) {
          uVar11 = FUN_10025a44();
          if (iVar3 < 0) goto LAB_10023762;
          if ((in_stack_00000010 & 1) == 0 && (iVar3 == 0 && in_stack_00000098 == 0))
          goto LAB_10023762;
LAB_100237c2:
          unaff_r4 = pcVar5;
          if (pcVar7 != (char *)0x39) {
            *pcVar10 = (char)iVar2 + '1';
            FUN_1002320c();
            return;
          }
          goto LAB_10023d72;
        }
        in_stack_00000024 = (char *)FUN_100260a8(unaff_r10,iVar4);
        uVar11 = FUN_10025a44();
        if (in_stack_00000024 == (char *)0x0 && in_stack_00000098 == 0) {
          if (uStack00000030 == 0) {
            unaff_r4 = pcVar5;
            if (pcVar7 == (char *)0x39) goto LAB_10023d72;
            if (0 < iVar3) goto LAB_10023780;
            goto LAB_10023784;
          }
          if (iVar3 < 0) goto LAB_10023784;
        }
        else {
          if (iVar3 < 0) goto LAB_10023d8c;
          if ((iVar3 == 0 && in_stack_00000098 == 0) && uStack00000030 == 0) goto LAB_10023d8c;
          if (0 < (int)in_stack_00000024) goto LAB_100237c2;
        }
        pcVar9 = pcVar10 + 1;
        *pcVar10 = (char)pcVar7;
        if (pcVar10 != in_stack_00000028) {
          unaff_r10 = (char *)FUN_10025a90();
          pcVar10 = pcVar9;
          if (unaff_r4 == pcVar5) {
            unaff_r4 = (char *)FUN_10025a90();
            pcVar5 = unaff_r4;
          }
          else {
            unaff_r4 = (char *)FUN_10025a90();
            pcVar5 = (char *)FUN_10025a90();
          }
          goto LAB_100236a2;
        }
        do {
          pcVar5 = unaff_r10;
          FUN_100231da();
          FUN_100233d4();
          *pcVar7 = '1';
          FUN_1002306c();
          *in_stack_0000000c = '1';
          FUN_1002320c();
          pcVar9 = (char *)(extraout_r3 - (int)pcVar9);
          if ((int)in_stack_00000028 < 0) {
            uVar11 = FUN_10025ccc();
            pcVar10 = in_stack_00000024;
            unaff_r11 = unaff_r4;
            in_stack_00000024 = in_stack_00000024 + -(int)in_stack_00000028;
          }
          else {
            pcVar10 = in_stack_00000024 + (int)in_stack_00000028;
            unaff_r11 = unaff_r4 + (int)in_stack_00000028;
            uVar11 = FUN_10025ccc();
            unaff_r4 = (char *)uVar11;
            if (in_stack_00000024 == (char *)0x0) goto LAB_10023294;
          }
          unaff_r4 = (char *)uVar11;
          if ((int)unaff_r11 < 1) {
            if (iVar2 != 0) {
              FUN_1002329e();
              return;
            }
            goto LAB_10023a42;
          }
          pcVar8 = in_stack_00000024;
          if ((int)unaff_r11 < (int)in_stack_00000024) {
            pcVar8 = unaff_r11;
          }
          if (iVar2 != 0) {
            FUN_1002329e(unaff_r4,(int)((ulonglong)uVar11 >> 0x20),unaff_r11);
          }
          FUN_100232b4();
          unaff_r10 = in_stack_00000024 + -(int)pcVar8;
          pcVar7 = pcVar5;
          in_stack_00000024 = pcVar10 + -(int)pcVar8;
        } while( true );
      }
      goto LAB_100237e6;
    }
    in_stack_00000028 = in_stack_00000040;
    if (((int)in_stack_00000040 < 1) && (2 < in_stack_00000098)) goto LAB_100237e6;
  }
  iVar2 = 1;
  while( true ) {
    iVar3 = FUN_10022c2c(unaff_r10,iStack00000018);
    in_stack_0000000c[iVar2 + -1] = (char)iVar3 + '0';
    if ((int)in_stack_00000028 <= iVar2) break;
    unaff_r10 = (char *)FUN_10025a90();
    iVar2 = iVar2 + 1;
  }
  pcVar5 = (char *)0x0;
  if (0 < (int)in_stack_00000028) {
    pcVar5 = in_stack_00000028 + -1;
  }
  pcVar5 = pcVar5 + (int)(in_stack_0000000c + 1);
  uVar1 = FUN_10025fb4();
  uVar11 = FUN_100260a8(uVar1,iStack00000018);
  iVar2 = (int)uVar11;
  if ((0 < iVar2) || ((iVar2 == 0 && (iVar3 << 0x1f < 0)))) {
    FUN_100231fe(iVar2,(int)((ulonglong)uVar11 >> 0x20),in_stack_0000000c);
    return;
  }
  do {
    pcVar5 = pcVar5 + -1;
  } while (*pcVar5 == '0');
  FUN_1002320c();
  return;
LAB_10023d72:
  *pcVar10 = '9';
  FUN_100231fe((int)uVar11,(int)((ulonglong)uVar11 >> 0x20),in_stack_0000000c);
  pcVar5 = pcVar7;
  pcVar7 = unaff_r10;
  pcVar10 = pcVar9;
LAB_10023d8c:
  if ((int)in_stack_00000024 < 1) goto LAB_10023784;
LAB_10023762:
  unaff_r10 = (char *)FUN_10025fb4();
  uVar11 = FUN_100260a8(unaff_r10,iStack00000018);
  if (((int)uVar11 < 1) && (((int)uVar11 != 0 || (-1 < (int)pcVar7 << 0x1f)))) goto LAB_10023784;
  if (pcVar7 != (char *)0x39) {
LAB_10023780:
    pcVar7 = (char *)(iVar2 + 0x31);
LAB_10023784:
    *pcVar10 = (char)pcVar7;
    FUN_1002320c();
    return;
  }
  pcVar7 = (char *)0x39;
  pcVar9 = unaff_r4;
  unaff_r4 = pcVar5;
  goto LAB_10023d72;
LAB_10023294:
  if (iVar2 == 0) {
LAB_10023a42:
    FUN_100232b4();
    return;
  }
  unaff_r6 = (char *)0x0;
  if (pcVar9 != (char *)0x0) {
    FUN_10023c1c();
  }
  unaff_r10 = (char *)FUN_10025ea8();
  iStack00000018 = FUN_10025ccc();
  if (uStack00000030 != 0) {
    FUN_10023bac();
  }
  if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) && ((in_stack_00000014 & 0xfffff) == 0)
      ) && ((in_stack_00000014 & 0x7ff00000) != 0)) {
    in_stack_00000024 = pcVar10 + 1;
    iVar2 = 1;
    in_stack_0000002c = 1;
    unaff_r11 = unaff_r11 + 1;
    uStack00000030 = 1;
  }
  else {
    iVar2 = 1;
    in_stack_0000002c = 1;
    in_stack_00000024 = pcVar10;
  }
  goto LAB_1002311e;
LAB_100237e6:
  if (in_stack_00000028 == (char *)0x0) {
    iStack00000018 = FUN_10025a90();
    iVar2 = FUN_100260a8(unaff_r10,iStack00000018);
    if (0 < iVar2) {
      *in_stack_0000000c = '1';
      FUN_10025a44();
      if (unaff_r4 == (char *)0x0) {
        FUN_1002306c();
        return;
      }
      FUN_1002322c();
      return;
    }
  }
  FUN_10025a44();
  if (unaff_r4 != (char *)0x0) {
    FUN_1002322c();
  }
  FUN_1002306c();
  unaff_r6 = in_stack_0000000c;
  goto LAB_10023b16;
}



/* FUN_10023a04 at 10023a04 */

/* WARNING: Removing unreachable block (ram,0x1002384e) */
/* WARNING: Removing unreachable block (ram,0x10023856) */
/* WARNING: Removing unreachable block (ram,0x10023858) */
/* WARNING: Removing unreachable block (ram,0x1002385e) */
/* WARNING: Removing unreachable block (ram,0x10023860) */
/* WARNING: Removing unreachable block (ram,0x10023184) */
/* WARNING: Removing unreachable block (ram,0x1002318a) */
/* WARNING: Removing unreachable block (ram,0x100231ae) */
/* WARNING: Removing unreachable block (ram,0x100231be) */
/* WARNING: Removing unreachable block (ram,0x100231cc) */
/* WARNING: Removing unreachable block (ram,0x100231d0) */
/* WARNING: Removing unreachable block (ram,0x100231f0) */
/* WARNING: Removing unreachable block (ram,0x1002357e) */
/* WARNING: Removing unreachable block (ram,0x10023584) */
/* WARNING: Removing unreachable block (ram,0x1002358e) */
/* WARNING: Removing unreachable block (ram,0x10023582) */
/* WARNING: Removing unreachable block (ram,0x100231f2) */
/* WARNING: Removing unreachable block (ram,0x1002319e) */

void FUN_10023a04(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int extraout_r3;
  char *pcVar5;
  char *unaff_r5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *unaff_r10;
  char *unaff_r11;
  undefined8 uVar9;
  char *in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int iStack00000018;
  char *in_stack_00000024;
  char *in_stack_00000028;
  int in_stack_0000002c;
  uint in_stack_00000030;
  int in_stack_00000034;
  char *in_stack_00000040;
  int in_stack_00000098;
  
code_r0x10023a04:
  *in_stack_0000000c = '1';
  FUN_1002320c();
  unaff_r5 = (char *)(extraout_r3 - (int)unaff_r5);
  if ((int)in_stack_00000028 < 0) {
    uVar9 = FUN_10025ccc();
    pcVar8 = in_stack_00000024;
    in_stack_00000024 = in_stack_00000024 + -(int)in_stack_00000028;
  }
  else {
    pcVar8 = in_stack_00000024 + (int)in_stack_00000028;
    unaff_r11 = unaff_r11 + (int)in_stack_00000028;
    uVar9 = FUN_10025ccc();
    pcVar1 = (char *)uVar9;
    if (in_stack_00000024 == (char *)0x0) {
      if (in_stack_0000002c != 0) {
        pcVar6 = (char *)0x0;
        if (unaff_r5 != (char *)0x0) {
          FUN_10023c1c();
        }
        pcVar7 = (char *)FUN_10025ea8();
        iStack00000018 = FUN_10025ccc();
        if (in_stack_00000030 != 0) {
          FUN_10023bac();
        }
        if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) &&
            ((in_stack_00000014 & 0xfffff) == 0)) && ((in_stack_00000014 & 0x7ff00000) != 0)) {
          in_stack_00000024 = pcVar8 + 1;
          iVar4 = 1;
          unaff_r11 = unaff_r11 + 1;
          in_stack_00000030 = 1;
        }
        else {
          iVar4 = 1;
          in_stack_00000024 = pcVar8;
        }
        do {
          uVar3 = (uint)(unaff_r11 + iVar4) & 0x1f;
          if (((uint)(unaff_r11 + iVar4) & 0x1f) == 0) {
            iVar4 = 0x1c;
LAB_1002313a:
            pcVar6 = pcVar6 + iVar4;
            in_stack_00000024 = in_stack_00000024 + iVar4;
            unaff_r11 = unaff_r11 + iVar4;
          }
          else {
            if (4 < (int)(0x20 - uVar3)) {
              iVar4 = 0x1c - uVar3;
              goto LAB_1002313a;
            }
            if (0x20 - uVar3 != 4) {
              iVar4 = 0x3c - uVar3;
              goto LAB_1002313a;
            }
          }
          if (0 < (int)in_stack_00000024) {
            pcVar7 = (char *)FUN_10025fb4();
          }
          if (0 < (int)unaff_r11) {
            iStack00000018 = FUN_10025fb4();
          }
          if ((in_stack_00000034 != 0) && (iVar4 = FUN_100260a8(pcVar7,iStack00000018), iVar4 < 0))
          {
            pcVar7 = (char *)FUN_10025a90();
            pcVar1 = (char *)FUN_10025a90();
            in_stack_00000028 = in_stack_00000040;
          }
          if ((0 < (int)in_stack_00000028) || (in_stack_00000098 < 3)) goto LAB_1002366c;
          if (in_stack_00000028 == (char *)0x0) {
            iStack00000018 = FUN_10025a90();
            iVar4 = FUN_100260a8(pcVar7,iStack00000018);
            if (0 < iVar4) {
              *in_stack_0000000c = '1';
              FUN_10025a44();
              if (pcVar1 == (char *)0x0) {
                FUN_1002306c();
                return;
              }
              FUN_1002322c();
              return;
            }
          }
          FUN_10025a44();
          if (pcVar1 != (char *)0x0) {
            FUN_1002322c();
          }
          FUN_1002306c();
          if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
             ((in_stack_00000014 & 0x7ff00000) != 0)) {
            in_stack_00000024 = in_stack_00000024 + 1;
            in_stack_00000030 = 1;
            unaff_r11 = unaff_r11 + 1;
          }
          iVar4 = FUN_10025bdc(*(undefined4 *)
                                (*(int *)(iStack00000018 + 0x10) * 4 + iStack00000018 + 0x10));
          iVar4 = 0x20 - iVar4;
          pcVar6 = in_stack_0000000c;
        } while( true );
      }
      goto LAB_10023a42;
    }
  }
  pcVar1 = (char *)uVar9;
  if ((int)unaff_r11 < 1) {
    if (in_stack_0000002c != 0) {
      FUN_1002329e();
      return;
    }
LAB_10023a42:
    FUN_100232b4();
    return;
  }
  pcVar6 = in_stack_00000024;
  if ((int)unaff_r11 < (int)in_stack_00000024) {
    pcVar6 = unaff_r11;
  }
  pcVar7 = in_stack_00000024 + -(int)pcVar6;
  if (in_stack_0000002c != 0) {
    FUN_1002329e(pcVar1,(int)((ulonglong)uVar9 >> 0x20),unaff_r11);
  }
  FUN_100232b4();
  in_stack_00000024 = pcVar8 + -(int)pcVar6;
  goto LAB_100239fa;
LAB_1002366c:
  if (0 < (int)pcVar6) {
    pcVar1 = (char *)FUN_10025fb4();
  }
  pcVar8 = pcVar1;
  if (in_stack_00000030 != 0) {
    iVar4 = FUN_100259c0();
    if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded");
    }
    FUN_1001f4d4(iVar4 + 0xc,pcVar1 + 0xc,(*(int *)(pcVar1 + 0x10) + 2) * 4);
    pcVar8 = (char *)FUN_10025fb4();
  }
  in_stack_00000028 = in_stack_00000028 + (int)(in_stack_0000000c + -1);
  in_stack_00000030 = in_stack_00000010 & 1;
  pcVar6 = in_stack_0000000c;
LAB_100236a2:
  in_stack_0000002c = FUN_10022c2c(pcVar7,iStack00000018);
  unaff_r10 = (char *)(in_stack_0000002c + 0x30);
  iVar4 = FUN_100260a8(pcVar7,pcVar1);
  iVar2 = FUN_100260e4();
  pcVar5 = pcVar1;
  if (*(int *)(iVar2 + 0xc) != 0) {
    uVar9 = FUN_10025a44();
    if (iVar4 < 0) goto LAB_10023762;
    if ((in_stack_00000010 & 1) == 0 && (iVar4 == 0 && in_stack_00000098 == 0)) goto LAB_10023762;
LAB_100237c2:
    pcVar1 = pcVar8;
    if (unaff_r10 != (char *)0x39) {
      *pcVar6 = (char)in_stack_0000002c + '1';
      FUN_1002320c();
      return;
    }
    goto LAB_10023d72;
  }
  in_stack_00000024 = (char *)FUN_100260a8(pcVar7,iVar2);
  uVar9 = FUN_10025a44();
  if (in_stack_00000024 == (char *)0x0 && in_stack_00000098 == 0) {
    if (in_stack_00000030 == 0) {
      pcVar1 = pcVar8;
      if (unaff_r10 == (char *)0x39) goto LAB_10023d72;
      if (iVar4 < 1) goto LAB_10023784;
      goto LAB_10023780;
    }
    if (iVar4 < 0) goto LAB_10023784;
  }
  else {
    if (iVar4 < 0) goto LAB_10023d8c;
    if ((iVar4 == 0 && in_stack_00000098 == 0) && in_stack_00000030 == 0) goto LAB_10023d8c;
    if (0 < (int)in_stack_00000024) goto LAB_100237c2;
  }
  unaff_r5 = pcVar6 + 1;
  *pcVar6 = (char)unaff_r10;
  if (pcVar6 != in_stack_00000028) {
    pcVar7 = (char *)FUN_10025a90();
    pcVar6 = unaff_r5;
    if (pcVar1 == pcVar8) {
      pcVar1 = (char *)FUN_10025a90();
      pcVar8 = pcVar1;
    }
    else {
      pcVar1 = (char *)FUN_10025a90();
      pcVar8 = (char *)FUN_10025a90();
    }
    goto LAB_100236a2;
  }
LAB_100239fa:
  FUN_100231da();
  FUN_100233d4();
  *unaff_r10 = '1';
  FUN_1002306c();
  unaff_r10 = pcVar7;
  unaff_r11 = pcVar1;
  goto code_r0x10023a04;
LAB_10023d72:
  *pcVar6 = '9';
  FUN_100231fe((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),in_stack_0000000c);
  pcVar8 = unaff_r10;
  unaff_r10 = pcVar7;
  pcVar6 = pcVar5;
LAB_10023d8c:
  if ((int)in_stack_00000024 < 1) goto LAB_10023784;
LAB_10023762:
  pcVar7 = (char *)FUN_10025fb4();
  uVar9 = FUN_100260a8(pcVar7,iStack00000018);
  if (((int)uVar9 < 1) && (((int)uVar9 != 0 || (-1 < (int)unaff_r10 << 0x1f)))) goto LAB_10023784;
  if (unaff_r10 != (char *)0x39) {
LAB_10023780:
    unaff_r10 = (char *)(in_stack_0000002c + 0x31);
LAB_10023784:
    *pcVar6 = (char)unaff_r10;
    FUN_1002320c();
    return;
  }
  unaff_r10 = (char *)0x39;
  pcVar5 = pcVar1;
  pcVar1 = pcVar8;
  goto LAB_10023d72;
}



/* FUN_10023a48 at 10023a48 */

void FUN_10023a48(void)

{
  int iVar1;
  int unaff_r6;
  int unaff_r9;
  undefined4 uStack00000048;
  int in_stack_0000009c;
  
  uStack00000048 = 0;
  while( true ) {
    if (0 < in_stack_0000009c) {
      FUN_10022fb8();
    }
    *(undefined4 *)(unaff_r6 + 4) = 0;
    iVar1 = FUN_100259c0();
    if (iVar1 == 0) break;
    **(int **)(unaff_r9 + 0x1c) = iVar1;
    in_stack_0000009c = 1;
    FUN_10022ff0();
    uStack00000048 = 1;
  }
  FUN_10023dc4();
  return;
}



/* FUN_10023a86 at 10023a86 */

void FUN_10023a86(void)

{
  int iVar1;
  int unaff_r6;
  int unaff_r9;
  undefined4 uStack00000048;
  int in_stack_0000009c;
  
  while( true ) {
    uStack00000048 = 1;
    if (0 < in_stack_0000009c) {
      FUN_10022fb8();
    }
    *(undefined4 *)(unaff_r6 + 4) = 0;
    iVar1 = FUN_100259c0();
    if (iVar1 == 0) break;
    **(int **)(unaff_r9 + 0x1c) = iVar1;
    in_stack_0000009c = 1;
    FUN_10022ff0();
  }
  FUN_10023dc4();
  return;
}



/* FUN_10023a88 at 10023a88 */

void FUN_10023a88(void)

{
  int iVar1;
  int unaff_r6;
  int unaff_r9;
  undefined4 uStack00000048;
  int in_stack_0000009c;
  
  while( true ) {
    uStack00000048 = 1;
    if (0 < in_stack_0000009c) {
      FUN_10022fb8();
    }
    *(undefined4 *)(unaff_r6 + 4) = 0;
    iVar1 = FUN_100259c0();
    if (iVar1 == 0) break;
    **(int **)(unaff_r9 + 0x1c) = iVar1;
    in_stack_0000009c = 1;
    FUN_10022ff0();
  }
  FUN_10023dc4();
  return;
}



/* FUN_10023a8e at 10023a8e */

/* WARNING: Removing unreachable block (ram,0x1002384e) */
/* WARNING: Removing unreachable block (ram,0x10023856) */
/* WARNING: Removing unreachable block (ram,0x10023858) */
/* WARNING: Removing unreachable block (ram,0x1002385e) */
/* WARNING: Removing unreachable block (ram,0x10023860) */
/* WARNING: Removing unreachable block (ram,0x10023184) */
/* WARNING: Removing unreachable block (ram,0x1002318a) */
/* WARNING: Removing unreachable block (ram,0x100231ae) */
/* WARNING: Removing unreachable block (ram,0x100231be) */
/* WARNING: Removing unreachable block (ram,0x100231cc) */
/* WARNING: Removing unreachable block (ram,0x100231d0) */
/* WARNING: Removing unreachable block (ram,0x100231f0) */
/* WARNING: Removing unreachable block (ram,0x1002357e) */
/* WARNING: Removing unreachable block (ram,0x10023584) */
/* WARNING: Removing unreachable block (ram,0x1002358e) */
/* WARNING: Removing unreachable block (ram,0x10023582) */
/* WARNING: Removing unreachable block (ram,0x100231f2) */
/* WARNING: Removing unreachable block (ram,0x1002319e) */

void FUN_10023a8e(void)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int extraout_r3;
  char *unaff_r5;
  undefined4 *puVar7;
  char *pcVar8;
  int unaff_r6;
  char *pcVar9;
  char *pcVar10;
  char *unaff_r7;
  char *unaff_r10;
  char *pcVar11;
  undefined4 *puVar12;
  undefined8 uVar13;
  char *in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int in_stack_00000018;
  undefined4 in_stack_0000001c;
  uint in_stack_00000020;
  char *pcStack00000024;
  char *in_stack_00000028;
  int in_stack_0000002c;
  uint uStack00000030;
  int iStack00000034;
  undefined4 uStack00000038;
  undefined4 uStack0000003c;
  char *in_stack_00000040;
  int in_stack_00000098;
  
  pcStack00000024 = (char *)(1 - (int)unaff_r7);
  uStack00000030 = in_stack_00000020;
  iStack00000034 = 0;
  FUN_10022f0a();
  if (in_stack_00000020 != 0) {
    iVar6 = (-in_stack_00000020 & 0xf) * 8;
    uVar13 = FUN_1001e9a6(in_stack_00000018,in_stack_0000001c,*(undefined4 *)(&DAT_1002b358 + iVar6)
                          ,*(undefined4 *)(&DAT_1002b35c + iVar6));
    uVar4 = (int)-in_stack_00000020 >> 4;
    if (uVar4 == 0) {
      FUN_100233d4();
      *(undefined4 *)(unaff_r6 + 4) = 0;
      FUN_10022fd4();
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0xef,0,"REENT malloc succeeded")
      ;
    }
    puVar7 = &DAT_1002b330;
    do {
      while( true ) {
        uStack0000003c = (undefined4)((ulonglong)uVar13 >> 0x20);
        uStack00000038 = (undefined4)uVar13;
        uVar1 = uVar4 & 1;
        uVar4 = (int)uVar4 >> 1;
        if (uVar1 != 0) break;
        puVar7 = puVar7 + 2;
      }
      uVar5 = *puVar7;
      puVar12 = puVar7 + 1;
      puVar7 = puVar7 + 2;
      uVar13 = FUN_1001e9a6(uStack00000038,uStack0000003c,uVar5,*puVar12);
    } while (uVar4 != 0);
    FUN_100233d4();
    return;
  }
  pcVar11 = (char *)0x0;
LAB_100239fa:
  FUN_100233d4();
  *unaff_r7 = '1';
  FUN_1002306c();
  *in_stack_0000000c = '1';
  FUN_1002320c();
  pcVar8 = pcStack00000024;
  unaff_r5 = (char *)(extraout_r3 - (int)unaff_r5);
  if ((int)in_stack_00000028 < 0) {
    pcVar2 = pcStack00000024 + -(int)in_stack_00000028;
    uVar13 = FUN_10025ccc();
    pcVar10 = pcVar8;
    pcStack00000024 = pcVar2;
  }
  else {
    pcVar10 = pcStack00000024 + (int)in_stack_00000028;
    pcVar11 = pcVar11 + (int)in_stack_00000028;
    uVar13 = FUN_10025ccc();
    pcVar2 = (char *)uVar13;
    if (pcVar8 == (char *)0x0) {
      if (in_stack_0000002c != 0) {
        pcVar8 = (char *)0x0;
        if (unaff_r5 != (char *)0x0) {
          FUN_10023c1c();
        }
        pcVar9 = (char *)FUN_10025ea8();
        pcStack00000024 = pcVar10;
        in_stack_00000018 = FUN_10025ccc();
        if (uStack00000030 != 0) {
          FUN_10023bac();
        }
        if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) &&
            ((in_stack_00000014 & 0xfffff) == 0)) && ((in_stack_00000014 & 0x7ff00000) != 0)) {
          pcStack00000024 = pcVar10 + 1;
          iVar6 = 1;
          pcVar11 = pcVar11 + 1;
          uStack00000030 = 1;
        }
        else {
          iVar6 = 1;
        }
        do {
          uVar4 = (uint)(pcVar11 + iVar6) & 0x1f;
          if (((uint)(pcVar11 + iVar6) & 0x1f) == 0) {
            iVar6 = 0x1c;
LAB_1002313a:
            pcVar8 = pcVar8 + iVar6;
            pcStack00000024 = pcStack00000024 + iVar6;
            pcVar11 = pcVar11 + iVar6;
          }
          else {
            if (4 < (int)(0x20 - uVar4)) {
              iVar6 = 0x1c - uVar4;
              goto LAB_1002313a;
            }
            if (0x20 - uVar4 != 4) {
              iVar6 = 0x3c - uVar4;
              goto LAB_1002313a;
            }
          }
          if (0 < (int)pcStack00000024) {
            pcVar9 = (char *)FUN_10025fb4();
          }
          if (0 < (int)pcVar11) {
            in_stack_00000018 = FUN_10025fb4();
          }
          if ((iStack00000034 != 0) && (iVar6 = FUN_100260a8(pcVar9,in_stack_00000018), iVar6 < 0))
          {
            pcVar9 = (char *)FUN_10025a90();
            pcVar2 = (char *)FUN_10025a90();
            in_stack_00000028 = in_stack_00000040;
          }
          if ((0 < (int)in_stack_00000028) || (in_stack_00000098 < 3)) goto LAB_1002366c;
          if (in_stack_00000028 == (char *)0x0) {
            in_stack_00000018 = FUN_10025a90();
            iVar6 = FUN_100260a8(pcVar9,in_stack_00000018);
            if (0 < iVar6) {
              *in_stack_0000000c = '1';
              FUN_10025a44();
              if (pcVar2 == (char *)0x0) {
                FUN_1002306c();
                return;
              }
              FUN_1002322c();
              return;
            }
          }
          FUN_10025a44();
          if (pcVar2 != (char *)0x0) {
            FUN_1002322c();
          }
          FUN_1002306c();
          if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
             ((in_stack_00000014 & 0x7ff00000) != 0)) {
            pcStack00000024 = pcStack00000024 + 1;
            uStack00000030 = 1;
            pcVar11 = pcVar11 + 1;
          }
          iVar6 = FUN_10025bdc(*(undefined4 *)
                                (*(int *)(in_stack_00000018 + 0x10) * 4 + in_stack_00000018 + 0x10))
          ;
          iVar6 = 0x20 - iVar6;
          pcVar8 = in_stack_0000000c;
        } while( true );
      }
      goto LAB_10023a42;
    }
  }
  pcVar2 = (char *)uVar13;
  if ((int)pcVar11 < 1) {
    if (in_stack_0000002c != 0) {
      FUN_1002329e();
      return;
    }
LAB_10023a42:
    pcStack00000024 = pcVar10;
    FUN_100232b4();
    return;
  }
  pcVar8 = pcStack00000024;
  if ((int)pcVar11 < (int)pcStack00000024) {
    pcVar8 = pcVar11;
  }
  pcVar9 = pcStack00000024 + -(int)pcVar8;
  if (in_stack_0000002c != 0) {
    FUN_1002329e(pcVar2,(int)((ulonglong)uVar13 >> 0x20),pcVar11);
  }
  pcStack00000024 = pcVar10 + -(int)pcVar8;
  FUN_100232b4();
  unaff_r7 = unaff_r10;
  goto LAB_10023d44;
LAB_1002366c:
  if (0 < (int)pcVar8) {
    pcVar2 = (char *)FUN_10025fb4();
  }
  pcVar11 = pcVar2;
  if (uStack00000030 != 0) {
    iVar6 = FUN_100259c0();
    if (iVar6 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded");
    }
    FUN_1001f4d4(iVar6 + 0xc,pcVar2 + 0xc,(*(int *)(pcVar2 + 0x10) + 2) * 4);
    pcVar11 = (char *)FUN_10025fb4();
  }
  in_stack_00000028 = in_stack_00000028 + (int)(in_stack_0000000c + -1);
  uStack00000030 = in_stack_00000010 & 1;
  pcVar8 = in_stack_0000000c;
LAB_100236a2:
  in_stack_0000002c = FUN_10022c2c(pcVar9,in_stack_00000018);
  unaff_r7 = (char *)(in_stack_0000002c + 0x30);
  iVar6 = FUN_100260a8(pcVar9,pcVar2);
  iVar3 = FUN_100260e4();
  pcVar10 = pcVar2;
  if (*(int *)(iVar3 + 0xc) != 0) {
    uVar13 = FUN_10025a44();
    if (iVar6 < 0) goto LAB_10023762;
    if ((in_stack_00000010 & 1) == 0 && (iVar6 == 0 && in_stack_00000098 == 0)) goto LAB_10023762;
LAB_100237c2:
    pcVar2 = pcVar11;
    if (unaff_r7 != (char *)0x39) {
      *pcVar8 = (char)in_stack_0000002c + '1';
      FUN_1002320c();
      return;
    }
    goto LAB_10023d72;
  }
  pcStack00000024 = (char *)FUN_100260a8(pcVar9,iVar3);
  uVar13 = FUN_10025a44();
  if (pcStack00000024 == (char *)0x0 && in_stack_00000098 == 0) {
    if (uStack00000030 == 0) {
      pcVar2 = pcVar11;
      if (unaff_r7 == (char *)0x39) goto LAB_10023d72;
      if (iVar6 < 1) goto LAB_10023784;
      goto LAB_10023780;
    }
    if (iVar6 < 0) goto LAB_10023784;
  }
  else {
    if (iVar6 < 0) goto LAB_10023d8c;
    if ((iVar6 == 0 && in_stack_00000098 == 0) && uStack00000030 == 0) goto LAB_10023d8c;
    if (0 < (int)pcStack00000024) goto LAB_100237c2;
  }
  unaff_r5 = pcVar8 + 1;
  *pcVar8 = (char)unaff_r7;
  if (pcVar8 != in_stack_00000028) {
    pcVar9 = (char *)FUN_10025a90();
    pcVar8 = unaff_r5;
    if (pcVar2 == pcVar11) {
      pcVar2 = (char *)FUN_10025a90();
      pcVar11 = pcVar2;
    }
    else {
      pcVar2 = (char *)FUN_10025a90();
      pcVar11 = (char *)FUN_10025a90();
    }
    goto LAB_100236a2;
  }
LAB_10023d44:
  FUN_100231da();
  unaff_r10 = pcVar9;
  pcVar11 = pcVar2;
  goto LAB_100239fa;
LAB_10023d72:
  *pcVar8 = '9';
  FUN_100231fe((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),in_stack_0000000c);
  pcVar11 = unaff_r7;
  unaff_r7 = pcVar9;
  pcVar8 = pcVar10;
LAB_10023d8c:
  if ((int)pcStack00000024 < 1) goto LAB_10023784;
LAB_10023762:
  pcVar9 = (char *)FUN_10025fb4();
  uVar13 = FUN_100260a8(pcVar9,in_stack_00000018);
  if (((int)uVar13 < 1) && (((int)uVar13 != 0 || (-1 < (int)unaff_r7 << 0x1f)))) goto LAB_10023784;
  if (unaff_r7 != (char *)0x39) {
LAB_10023780:
    unaff_r7 = (char *)(in_stack_0000002c + 0x31);
LAB_10023784:
    *pcVar8 = (char)unaff_r7;
    FUN_1002320c();
    return;
  }
  unaff_r7 = (char *)0x39;
  pcVar10 = pcVar2;
  pcVar2 = pcVar11;
  goto LAB_10023d72;
}



/* FUN_10023bac at 10023bac */

void FUN_10023bac(void)

{
  undefined4 uStack0000002c;
  
  uStack0000002c = 1;
  FUN_100235a6();
  return;
}



/* FUN_10023bb2 at 10023bb2 */

/* WARNING: Removing unreachable block (ram,0x1002384e) */
/* WARNING: Removing unreachable block (ram,0x10023856) */
/* WARNING: Removing unreachable block (ram,0x10023858) */
/* WARNING: Removing unreachable block (ram,0x1002385e) */
/* WARNING: Removing unreachable block (ram,0x10023860) */
/* WARNING: Removing unreachable block (ram,0x10023184) */
/* WARNING: Removing unreachable block (ram,0x1002318a) */
/* WARNING: Removing unreachable block (ram,0x100231ae) */
/* WARNING: Removing unreachable block (ram,0x100231be) */
/* WARNING: Removing unreachable block (ram,0x100231cc) */
/* WARNING: Removing unreachable block (ram,0x100231d0) */
/* WARNING: Removing unreachable block (ram,0x100231f0) */
/* WARNING: Removing unreachable block (ram,0x1002357e) */
/* WARNING: Removing unreachable block (ram,0x10023584) */
/* WARNING: Removing unreachable block (ram,0x1002358e) */
/* WARNING: Removing unreachable block (ram,0x10023582) */
/* WARNING: Removing unreachable block (ram,0x100231f2) */
/* WARNING: Removing unreachable block (ram,0x1002319e) */

void FUN_10023bb2(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  char cVar7;
  int extraout_r3;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  char *unaff_r10;
  char *pcVar12;
  char *unaff_r11;
  undefined8 uVar13;
  char *in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  char *in_stack_00000018;
  undefined4 in_stack_0000001c;
  char *in_stack_00000024;
  char *in_stack_00000028;
  int in_stack_0000002c;
  uint in_stack_00000030;
  int in_stack_00000034;
  char *pcStack00000038;
  char *in_stack_00000040;
  int in_stack_00000098;
  
  pcStack00000038 = in_stack_0000000c + 1;
  FUN_1001e96a(in_stack_00000018,in_stack_0000001c,in_stack_00000010,in_stack_00000014);
  iVar3 = FUN_1001eab4();
  uVar13 = FUN_1001ea84();
  uVar13 = FUN_1001e9a6((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),in_stack_00000010,
                        in_stack_00000014);
  uVar13 = FUN_1001e946(in_stack_00000018,in_stack_0000001c,(int)uVar13,
                        (int)((ulonglong)uVar13 >> 0x20));
  *in_stack_0000000c = (char)iVar3 + '0';
  pcVar11 = pcStack00000038;
  if (in_stack_00000028 != (char *)0x1) {
    unaff_r11 = in_stack_0000000c + -1;
    pcVar10 = (char *)0x1;
    do {
      uVar13 = FUN_1001e9a6((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),0,0x40240000);
      uVar5 = (undefined4)((ulonglong)uVar13 >> 0x20);
      uVar6 = (undefined4)uVar13;
      iVar3 = FUN_1001ea2c(uVar6,uVar5,0,0);
      if (iVar3 != 0) {
        FUN_1002306c();
        return;
      }
      FUN_1001e96a(uVar6,uVar5,in_stack_00000010,in_stack_00000014);
      iVar3 = FUN_1001eab4();
      uVar13 = FUN_1001ea84();
      uVar13 = FUN_1001e9a6((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),in_stack_00000010,
                            in_stack_00000014);
      uVar13 = FUN_1001e946(uVar6,uVar5,(int)uVar13,(int)((ulonglong)uVar13 >> 0x20));
      pcVar10 = pcVar10 + 1;
      unaff_r11[(int)pcVar10] = (char)iVar3 + '0';
      pcVar11 = pcVar11 + 1;
    } while (in_stack_00000028 != pcVar10);
  }
  uVar6 = (undefined4)((ulonglong)uVar13 >> 0x20);
  uVar13 = FUN_1001e958((int)uVar13,uVar6,(int)uVar13,uVar6);
  pcVar10 = (char *)((ulonglong)uVar13 >> 0x20);
  iVar2 = FUN_1001ea58((int)uVar13,pcVar10,in_stack_00000010,in_stack_00000014);
  if ((iVar2 == 0) &&
     ((iVar2 = FUN_1001ea2c((int)uVar13,pcVar10,in_stack_00000010,in_stack_00000014), iVar2 == 0 ||
      (-1 < iVar3 << 0x1f)))) {
    FUN_1002306c();
    FUN_100235a6();
    return;
  }
  do {
    pcVar11 = pcVar11 + -1;
    if (*pcVar11 != '9') {
      cVar7 = *pcVar11 + '\x01';
      pcVar1 = unaff_r10;
      pcVar12 = unaff_r11;
      goto LAB_100239fa;
    }
  } while (pcVar11 != in_stack_0000000c);
LAB_10023d68:
  cVar7 = '1';
  pcVar1 = unaff_r10;
  pcVar12 = unaff_r11;
LAB_100239fa:
  *pcVar11 = cVar7;
  FUN_1002306c();
  *in_stack_0000000c = '1';
  FUN_1002320c();
  pcVar10 = (char *)(extraout_r3 - (int)pcVar10);
  if ((int)in_stack_00000028 < 0) {
    uVar13 = FUN_10025ccc();
    pcVar9 = in_stack_00000024;
    in_stack_00000024 = in_stack_00000024 + -(int)in_stack_00000028;
  }
  else {
    pcVar9 = in_stack_00000024 + (int)in_stack_00000028;
    pcVar12 = pcVar12 + (int)in_stack_00000028;
    uVar13 = FUN_10025ccc();
    unaff_r11 = (char *)uVar13;
    if (in_stack_00000024 == (char *)0x0) {
      if (in_stack_0000002c != 0) {
        pcVar11 = (char *)0x0;
        if (pcVar10 != (char *)0x0) {
          FUN_10023c1c();
        }
        unaff_r10 = (char *)FUN_10025ea8();
        in_stack_00000018 = (char *)FUN_10025ccc();
        if (in_stack_00000030 != 0) {
          FUN_10023bac();
        }
        if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) &&
            ((in_stack_00000014 & 0xfffff) == 0)) && ((in_stack_00000014 & 0x7ff00000) != 0)) {
          in_stack_00000024 = pcVar9 + 1;
          iVar3 = 1;
          pcVar12 = pcVar12 + 1;
          in_stack_00000030 = 1;
        }
        else {
          iVar3 = 1;
          in_stack_00000024 = pcVar9;
        }
        do {
          uVar4 = (uint)(pcVar12 + iVar3) & 0x1f;
          if (((uint)(pcVar12 + iVar3) & 0x1f) == 0) {
            iVar3 = 0x1c;
LAB_1002313a:
            pcVar11 = pcVar11 + iVar3;
            in_stack_00000024 = in_stack_00000024 + iVar3;
            pcVar12 = pcVar12 + iVar3;
          }
          else {
            if (4 < (int)(0x20 - uVar4)) {
              iVar3 = 0x1c - uVar4;
              goto LAB_1002313a;
            }
            if (0x20 - uVar4 != 4) {
              iVar3 = 0x3c - uVar4;
              goto LAB_1002313a;
            }
          }
          if (0 < (int)in_stack_00000024) {
            unaff_r10 = (char *)FUN_10025fb4();
          }
          if (0 < (int)pcVar12) {
            in_stack_00000018 = (char *)FUN_10025fb4();
          }
          if ((in_stack_00000034 != 0) &&
             (iVar3 = FUN_100260a8(unaff_r10,in_stack_00000018), iVar3 < 0)) {
            unaff_r10 = (char *)FUN_10025a90();
            unaff_r11 = (char *)FUN_10025a90();
            in_stack_00000028 = in_stack_00000040;
          }
          if ((0 < (int)in_stack_00000028) || (in_stack_00000098 < 3)) goto LAB_1002366c;
          if (in_stack_00000028 == (char *)0x0) {
            in_stack_00000018 = (char *)FUN_10025a90();
            iVar3 = FUN_100260a8(unaff_r10,in_stack_00000018);
            if (0 < iVar3) {
              *in_stack_0000000c = '1';
              FUN_10025a44();
              if (unaff_r11 == (char *)0x0) {
                FUN_1002306c();
                return;
              }
              FUN_1002322c();
              return;
            }
          }
          FUN_10025a44();
          if (unaff_r11 != (char *)0x0) {
            FUN_1002322c();
          }
          FUN_1002306c();
          if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
             ((in_stack_00000014 & 0x7ff00000) != 0)) {
            in_stack_00000024 = in_stack_00000024 + 1;
            in_stack_00000030 = 1;
            pcVar12 = pcVar12 + 1;
          }
          iVar3 = FUN_10025bdc(*(undefined4 *)
                                (in_stack_00000018 + *(int *)(in_stack_00000018 + 0x10) * 4 + 0x10))
          ;
          iVar3 = 0x20 - iVar3;
          pcVar11 = in_stack_0000000c;
        } while( true );
      }
      goto LAB_10023a42;
    }
  }
  unaff_r11 = (char *)uVar13;
  if ((int)pcVar12 < 1) {
    if (in_stack_0000002c != 0) {
      FUN_1002329e();
      return;
    }
LAB_10023a42:
    FUN_100232b4();
    return;
  }
  pcVar8 = in_stack_00000024;
  if ((int)pcVar12 < (int)in_stack_00000024) {
    pcVar8 = pcVar12;
  }
  unaff_r10 = in_stack_00000024 + -(int)pcVar8;
  if (in_stack_0000002c != 0) {
    FUN_1002329e(unaff_r11,(int)((ulonglong)uVar13 >> 0x20),pcVar12);
  }
  FUN_100232b4();
  pcVar11 = pcVar1;
  in_stack_00000024 = pcVar9 + -(int)pcVar8;
  goto LAB_10023d44;
LAB_1002366c:
  if (0 < (int)pcVar11) {
    unaff_r11 = (char *)FUN_10025fb4();
  }
  pcVar1 = unaff_r11;
  if (in_stack_00000030 != 0) {
    iVar3 = FUN_100259c0();
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded");
    }
    FUN_1001f4d4(iVar3 + 0xc,unaff_r11 + 0xc,(*(int *)(unaff_r11 + 0x10) + 2) * 4);
    pcVar1 = (char *)FUN_10025fb4();
  }
  in_stack_00000028 = in_stack_00000028 + (int)(in_stack_0000000c + -1);
  in_stack_00000030 = in_stack_00000010 & 1;
  pcVar12 = in_stack_0000000c;
LAB_100236a2:
  in_stack_0000002c = FUN_10022c2c(unaff_r10,in_stack_00000018);
  pcVar11 = (char *)(in_stack_0000002c + 0x30);
  iVar3 = FUN_100260a8(unaff_r10,unaff_r11);
  iVar2 = FUN_100260e4();
  pcVar10 = unaff_r11;
  if (*(int *)(iVar2 + 0xc) != 0) {
    uVar13 = FUN_10025a44();
    if (iVar3 < 0) goto LAB_10023762;
    if ((in_stack_00000010 & 1) == 0 && (iVar3 == 0 && in_stack_00000098 == 0)) goto LAB_10023762;
LAB_100237c2:
    unaff_r11 = pcVar1;
    if (pcVar11 != (char *)0x39) {
      *pcVar12 = (char)in_stack_0000002c + '1';
      FUN_1002320c();
      return;
    }
    goto LAB_10023d72;
  }
  in_stack_00000024 = (char *)FUN_100260a8(unaff_r10,iVar2);
  uVar13 = FUN_10025a44();
  if (in_stack_00000024 == (char *)0x0 && in_stack_00000098 == 0) {
    if (in_stack_00000030 == 0) {
      unaff_r11 = pcVar1;
      if (pcVar11 == (char *)0x39) goto LAB_10023d72;
      if (iVar3 < 1) goto LAB_10023784;
      goto LAB_10023780;
    }
    if (iVar3 < 0) goto LAB_10023784;
  }
  else {
    if (iVar3 < 0) goto LAB_10023d8c;
    if ((iVar3 == 0 && in_stack_00000098 == 0) && in_stack_00000030 == 0) goto LAB_10023d8c;
    if (0 < (int)in_stack_00000024) goto LAB_100237c2;
  }
  pcVar10 = pcVar12 + 1;
  *pcVar12 = (char)pcVar11;
  if (pcVar12 != in_stack_00000028) {
    unaff_r10 = (char *)FUN_10025a90();
    pcVar12 = pcVar10;
    if (unaff_r11 == pcVar1) {
      unaff_r11 = (char *)FUN_10025a90();
      pcVar1 = unaff_r11;
    }
    else {
      unaff_r11 = (char *)FUN_10025a90();
      pcVar1 = (char *)FUN_10025a90();
    }
    goto LAB_100236a2;
  }
LAB_10023d44:
  FUN_100231da();
  pcStack00000038 = in_stack_00000018;
  FUN_100233d4();
  goto LAB_10023d68;
LAB_10023d72:
  *pcVar12 = '9';
  FUN_100231fe((int)uVar13,(int)((ulonglong)uVar13 >> 0x20),in_stack_0000000c);
  pcVar1 = pcVar11;
  pcVar11 = unaff_r10;
  pcVar12 = pcVar10;
LAB_10023d8c:
  if ((int)in_stack_00000024 < 1) goto LAB_10023784;
LAB_10023762:
  unaff_r10 = (char *)FUN_10025fb4();
  uVar13 = FUN_100260a8(unaff_r10,in_stack_00000018);
  if (((int)uVar13 < 1) && (((int)uVar13 != 0 || (-1 < (int)pcVar11 << 0x1f)))) goto LAB_10023784;
  if (pcVar11 != (char *)0x39) {
LAB_10023780:
    pcVar11 = (char *)(in_stack_0000002c + 0x31);
LAB_10023784:
    *pcVar12 = (char)pcVar11;
    FUN_1002320c();
    return;
  }
  pcVar11 = (char *)0x39;
  pcVar10 = unaff_r11;
  unaff_r11 = pcVar1;
  goto LAB_10023d72;
}



/* FUN_10023c1c at 10023c1c */

/* WARNING: Removing unreachable block (ram,0x1002384e) */
/* WARNING: Removing unreachable block (ram,0x10023856) */
/* WARNING: Removing unreachable block (ram,0x10023858) */
/* WARNING: Removing unreachable block (ram,0x1002385e) */
/* WARNING: Removing unreachable block (ram,0x10023860) */
/* WARNING: Removing unreachable block (ram,0x10023184) */
/* WARNING: Removing unreachable block (ram,0x1002318a) */
/* WARNING: Removing unreachable block (ram,0x100231ae) */
/* WARNING: Removing unreachable block (ram,0x100231be) */
/* WARNING: Removing unreachable block (ram,0x100231cc) */
/* WARNING: Removing unreachable block (ram,0x100231d0) */
/* WARNING: Removing unreachable block (ram,0x100231f0) */
/* WARNING: Removing unreachable block (ram,0x1002357e) */
/* WARNING: Removing unreachable block (ram,0x10023584) */
/* WARNING: Removing unreachable block (ram,0x1002358e) */
/* WARNING: Removing unreachable block (ram,0x10023582) */
/* WARNING: Removing unreachable block (ram,0x100231f2) */
/* WARNING: Removing unreachable block (ram,0x1002319e) */

void FUN_10023c1c(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  int extraout_r3;
  uint *puVar10;
  char *pcVar11;
  char *unaff_r5;
  char unaff_r6;
  char *pcVar12;
  char *unaff_r7;
  char *pcVar13;
  char *pcVar14;
  char *unaff_r11;
  undefined8 uVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  char *in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int iStack00000018;
  undefined4 in_stack_0000001c;
  int in_stack_00000020;
  char *in_stack_00000028;
  int in_stack_0000002c;
  uint in_stack_00000030;
  int in_stack_00000034;
  char *in_stack_00000038;
  char *in_stack_00000040;
  int in_stack_00000044;
  int in_stack_00000050;
  undefined4 in_stack_00000058;
  undefined4 in_stack_0000005c;
  undefined4 in_stack_00000060;
  undefined4 in_stack_00000064;
  int in_stack_0000006c;
  int in_stack_00000098;
  
  uVar5 = FUN_10025ea8();
  pcVar6 = (char *)FUN_10025cf8();
  FUN_10025a44();
  in_stack_0000002c = in_stack_0000002c - (int)unaff_r5;
  if (in_stack_0000002c == 0) {
    FUN_100232b4();
  }
  FUN_100232a6();
  uVar15 = FUN_1001e9a6(in_stack_00000058,in_stack_0000005c,in_stack_00000060,in_stack_00000064);
  uVar9 = (undefined4)((ulonglong)uVar15 >> 0x20);
  *in_stack_0000000c = unaff_r6;
  pcVar12 = in_stack_0000000c + in_stack_00000044;
  pcVar13 = unaff_r7;
  if (in_stack_00000044 != 1) {
    pcVar12 = unaff_r7;
    do {
      uVar16 = FUN_1001e9a6(uVar5,unaff_r5,0,0x40240000);
      cVar1 = FUN_1001eab4();
      uVar17 = FUN_1001ea84();
      uVar16 = FUN_1001e946((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),(int)uVar17,
                            (int)((ulonglong)uVar17 >> 0x20));
      unaff_r5 = (char *)((ulonglong)uVar16 >> 0x20);
      uVar5 = (undefined4)uVar16;
      *pcVar12 = cVar1 + '0';
      pcVar12 = pcVar12 + 1;
    } while (in_stack_0000000c + in_stack_00000044 != pcVar12);
    pcVar13 = in_stack_00000038 + in_stack_00000044 + -1;
  }
  uVar16 = FUN_1001e958((int)uVar15,uVar9,0,0x3fe00000);
  iVar7 = FUN_1001ea3c((int)uVar16,(int)((ulonglong)uVar16 >> 0x20),uVar5,unaff_r5);
  if (iVar7 == 0) {
    uVar15 = FUN_1001e946(0,0x3fe00000,(int)uVar15,uVar9);
    iVar7 = FUN_1001ea58((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),uVar5,unaff_r5);
    if (iVar7 != 0) {
      do {
        pcVar13 = pcVar13 + -1;
      } while (*pcVar13 == '0');
      uVar16 = FUN_1002306c();
      uVar15 = CONCAT44((int)((ulonglong)uVar16 >> 0x20),uVar5);
      uVar5 = (undefined4)uVar16;
      pcVar12 = pcVar6;
      goto LAB_10023d1e;
    }
    if ((in_stack_0000006c < 0) || (0xe < in_stack_00000020)) {
      FUN_100230e6();
      FUN_100233d4();
      pcVar12[4] = '\0';
      pcVar12[5] = '\0';
      pcVar12[6] = '\0';
      pcVar12[7] = '\0';
      FUN_10022fd4();
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0xef,0,"REENT malloc succeeded")
      ;
    }
    puVar10 = (uint *)(in_stack_00000020 * 8 + in_stack_00000050);
    in_stack_00000014 = puVar10[1];
    in_stack_00000010 = *puVar10;
    FUN_1001e96a(pcVar6,in_stack_0000001c,in_stack_00000010,in_stack_00000014);
    iVar7 = FUN_1001eab4();
    uVar15 = FUN_1001ea84();
    uVar15 = FUN_1001e9a6((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),in_stack_00000010,
                          in_stack_00000014);
    uVar15 = FUN_1001e946(pcVar6,in_stack_0000001c,(int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
    *in_stack_0000000c = (char)iVar7 + '0';
    if (in_stack_00000028 != (char *)0x1) {
      unaff_r11 = in_stack_0000000c + -1;
      pcVar12 = (char *)0x1;
      do {
        uVar15 = FUN_1001e9a6((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),0,0x40240000);
        uVar9 = (undefined4)((ulonglong)uVar15 >> 0x20);
        uVar5 = (undefined4)uVar15;
        iVar7 = FUN_1001ea2c(uVar5,uVar9,0,0);
        if (iVar7 != 0) {
          FUN_1002306c();
          return;
        }
        FUN_1001e96a(uVar5,uVar9,in_stack_00000010,in_stack_00000014);
        iVar7 = FUN_1001eab4();
        uVar15 = FUN_1001ea84();
        uVar15 = FUN_1001e9a6((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),in_stack_00000010,
                              in_stack_00000014);
        uVar15 = FUN_1001e946(uVar5,uVar9,(int)uVar15,(int)((ulonglong)uVar15 >> 0x20));
        pcVar12 = pcVar12 + 1;
        unaff_r11[(int)pcVar12] = (char)iVar7 + '0';
        in_stack_00000038 = in_stack_00000038 + 1;
      } while (in_stack_00000028 != pcVar12);
    }
    uVar5 = (undefined4)((ulonglong)uVar15 >> 0x20);
    uVar15 = FUN_1001e958((int)uVar15,uVar5,(int)uVar15,uVar5);
    unaff_r5 = (char *)((ulonglong)uVar15 >> 0x20);
    iVar3 = FUN_1001ea58((int)uVar15,unaff_r5,in_stack_00000010,in_stack_00000014);
    pcVar13 = in_stack_00000038;
    if ((iVar3 == 0) &&
       ((iVar3 = FUN_1001ea2c((int)uVar15,unaff_r5,in_stack_00000010,in_stack_00000014), iVar3 == 0
        || (-1 < iVar7 << 0x1f)))) {
      FUN_1002306c();
      FUN_100235a6();
      return;
    }
  }
  do {
    pcVar12 = pcVar13 + -1;
    if (*pcVar12 != '9') {
      cVar1 = *pcVar12 + '\x01';
      goto LAB_100239fa;
    }
    pcVar13 = pcVar12;
  } while (pcVar12 != in_stack_0000000c);
LAB_10023d68:
  cVar1 = '1';
LAB_100239fa:
  *pcVar12 = cVar1;
  FUN_1002306c();
  *in_stack_0000000c = '1';
  FUN_1002320c();
  unaff_r5 = (char *)(extraout_r3 - (int)unaff_r5);
  if ((int)in_stack_00000028 < 0) {
    uVar15 = FUN_10025ccc();
    pcVar13 = unaff_r7;
    unaff_r7 = unaff_r7 + -(int)in_stack_00000028;
  }
  else {
    pcVar13 = unaff_r7 + (int)in_stack_00000028;
    unaff_r11 = unaff_r11 + (int)in_stack_00000028;
    uVar15 = FUN_10025ccc();
    pcVar2 = (char *)uVar15;
    if (unaff_r7 == (char *)0x0) {
      if (in_stack_0000002c != 0) {
        pcVar12 = (char *)0x0;
        if (unaff_r5 != (char *)0x0) {
          FUN_10023c1c();
        }
        pcVar6 = (char *)FUN_10025ea8();
        iStack00000018 = FUN_10025ccc();
        if (in_stack_00000030 != 0) {
          FUN_10023bac();
        }
        if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) &&
            ((in_stack_00000014 & 0xfffff) == 0)) && ((in_stack_00000014 & 0x7ff00000) != 0)) {
          pcVar13 = pcVar13 + 1;
          iVar7 = 1;
          unaff_r11 = unaff_r11 + 1;
          in_stack_00000030 = 1;
        }
        else {
          iVar7 = 1;
        }
        do {
          uVar8 = (uint)(unaff_r11 + iVar7) & 0x1f;
          if (((uint)(unaff_r11 + iVar7) & 0x1f) == 0) {
            iVar7 = 0x1c;
LAB_1002313a:
            pcVar12 = pcVar12 + iVar7;
            pcVar13 = pcVar13 + iVar7;
            unaff_r11 = unaff_r11 + iVar7;
          }
          else {
            if (4 < (int)(0x20 - uVar8)) {
              iVar7 = 0x1c - uVar8;
              goto LAB_1002313a;
            }
            if (0x20 - uVar8 != 4) {
              iVar7 = 0x3c - uVar8;
              goto LAB_1002313a;
            }
          }
          if (0 < (int)pcVar13) {
            pcVar6 = (char *)FUN_10025fb4();
          }
          if (0 < (int)unaff_r11) {
            iStack00000018 = FUN_10025fb4();
          }
          if ((in_stack_00000034 != 0) && (iVar7 = FUN_100260a8(pcVar6,iStack00000018), iVar7 < 0))
          {
            pcVar6 = (char *)FUN_10025a90();
            pcVar2 = (char *)FUN_10025a90();
            in_stack_00000028 = in_stack_00000040;
          }
          if ((0 < (int)in_stack_00000028) || (in_stack_00000098 < 3)) goto LAB_1002366c;
          if (in_stack_00000028 == (char *)0x0) {
            iStack00000018 = FUN_10025a90();
            iVar7 = FUN_100260a8(pcVar6,iStack00000018);
            if (0 < iVar7) {
              *in_stack_0000000c = '1';
              FUN_10025a44();
              if (pcVar2 == (char *)0x0) {
                FUN_1002306c();
                return;
              }
              FUN_1002322c();
              return;
            }
          }
          FUN_10025a44();
          if (pcVar2 != (char *)0x0) {
            FUN_1002322c();
          }
          FUN_1002306c();
          if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
             ((in_stack_00000014 & 0x7ff00000) != 0)) {
            pcVar13 = pcVar13 + 1;
            in_stack_00000030 = 1;
            unaff_r11 = unaff_r11 + 1;
          }
          iVar7 = FUN_10025bdc(*(undefined4 *)
                                (*(int *)(iStack00000018 + 0x10) * 4 + iStack00000018 + 0x10));
          iVar7 = 0x20 - iVar7;
          pcVar12 = in_stack_0000000c;
        } while( true );
      }
      goto LAB_10023a42;
    }
  }
  uVar5 = (undefined4)uVar15;
  pcVar12 = pcVar6;
  if ((int)unaff_r11 < 1) {
    if (in_stack_0000002c != 0) {
      FUN_1002329e();
      return;
    }
LAB_10023a42:
    FUN_100232b4();
    return;
  }
LAB_10023d1e:
  pcVar2 = (char *)uVar15;
  pcVar6 = unaff_r7;
  if ((int)unaff_r11 < (int)unaff_r7) {
    pcVar6 = unaff_r11;
  }
  pcVar13 = pcVar13 + -(int)pcVar6;
  pcVar6 = unaff_r7 + -(int)pcVar6;
  if (in_stack_0000002c != 0) {
    FUN_1002329e(uVar5,(int)((ulonglong)uVar15 >> 0x20),unaff_r11);
  }
  FUN_100232b4();
  goto LAB_10023d44;
LAB_1002366c:
  if (0 < (int)pcVar12) {
    pcVar2 = (char *)FUN_10025fb4();
  }
  pcVar4 = pcVar2;
  if (in_stack_00000030 != 0) {
    iVar7 = FUN_100259c0();
    if (iVar7 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded");
    }
    FUN_1001f4d4(iVar7 + 0xc,pcVar2 + 0xc,(*(int *)(pcVar2 + 0x10) + 2) * 4);
    pcVar4 = (char *)FUN_10025fb4();
  }
  in_stack_00000028 = in_stack_00000028 + (int)(in_stack_0000000c + -1);
  in_stack_00000030 = in_stack_00000010 & 1;
  pcVar14 = in_stack_0000000c;
LAB_100236a2:
  in_stack_0000002c = FUN_10022c2c(pcVar6,iStack00000018);
  pcVar12 = (char *)(in_stack_0000002c + 0x30);
  iVar7 = FUN_100260a8(pcVar6,pcVar2);
  iVar3 = FUN_100260e4();
  pcVar11 = pcVar2;
  if (*(int *)(iVar3 + 0xc) != 0) {
    uVar15 = FUN_10025a44();
    if (iVar7 < 0) goto LAB_10023762;
    if ((in_stack_00000010 & 1) == 0 && (iVar7 == 0 && in_stack_00000098 == 0)) goto LAB_10023762;
LAB_100237c2:
    pcVar2 = pcVar4;
    if (pcVar12 != (char *)0x39) {
      *pcVar14 = (char)in_stack_0000002c + '1';
      FUN_1002320c();
      return;
    }
    goto LAB_10023d72;
  }
  pcVar13 = (char *)FUN_100260a8(pcVar6,iVar3);
  uVar15 = FUN_10025a44();
  if (pcVar13 == (char *)0x0 && in_stack_00000098 == 0) {
    if (in_stack_00000030 == 0) {
      pcVar2 = pcVar4;
      if (pcVar12 == (char *)0x39) goto LAB_10023d72;
      if (iVar7 < 1) goto LAB_10023784;
      goto LAB_10023780;
    }
    if (iVar7 < 0) goto LAB_10023784;
  }
  else {
    if (iVar7 < 0) goto LAB_10023d8c;
    if ((iVar7 == 0 && in_stack_00000098 == 0) && in_stack_00000030 == 0) goto LAB_10023d8c;
    if (0 < (int)pcVar13) goto LAB_100237c2;
  }
  unaff_r5 = pcVar14 + 1;
  *pcVar14 = (char)pcVar12;
  if (pcVar14 != in_stack_00000028) {
    pcVar6 = (char *)FUN_10025a90();
    pcVar14 = unaff_r5;
    if (pcVar2 == pcVar4) {
      pcVar2 = (char *)FUN_10025a90();
      pcVar4 = pcVar2;
    }
    else {
      pcVar2 = (char *)FUN_10025a90();
      pcVar4 = (char *)FUN_10025a90();
    }
    goto LAB_100236a2;
  }
LAB_10023d44:
  FUN_100231da();
  FUN_100233d4();
  unaff_r11 = pcVar2;
  unaff_r7 = pcVar13;
  goto LAB_10023d68;
LAB_10023d72:
  *pcVar14 = '9';
  FUN_100231fe((int)uVar15,(int)((ulonglong)uVar15 >> 0x20),in_stack_0000000c);
  pcVar4 = pcVar12;
  pcVar12 = pcVar6;
  pcVar14 = pcVar11;
LAB_10023d8c:
  if ((int)pcVar13 < 1) goto LAB_10023784;
LAB_10023762:
  pcVar6 = (char *)FUN_10025fb4();
  uVar15 = FUN_100260a8(pcVar6,iStack00000018);
  if (((int)uVar15 < 1) && (((int)uVar15 != 0 || (-1 < (int)pcVar12 << 0x1f)))) goto LAB_10023784;
  if (pcVar12 != (char *)0x39) {
LAB_10023780:
    pcVar12 = (char *)(in_stack_0000002c + 0x31);
LAB_10023784:
    *pcVar14 = (char)pcVar12;
    FUN_1002320c();
    return;
  }
  pcVar12 = (char *)0x39;
  pcVar11 = pcVar2;
  pcVar2 = pcVar4;
  goto LAB_10023d72;
}



/* FUN_10023d9c at 10023d9c */

void FUN_10023d9c(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *unaff_r7;
  int unaff_r8;
  undefined1 *unaff_r10;
  undefined1 *puVar5;
  undefined1 *unaff_r11;
  undefined8 uVar6;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000018;
  undefined1 *in_stack_00000024;
  int iStack0000002c;
  
  iStack0000002c = 0;
  uVar6 = FUN_100235a6();
  puVar1 = (undefined1 *)0x0;
  puVar2 = unaff_r10;
  puVar3 = in_stack_00000024;
  puVar5 = unaff_r11;
  if (unaff_r10 == (undefined1 *)0x39) {
    while( true ) {
      unaff_r10 = puVar3;
      puVar4 = puVar2;
      unaff_r11 = puVar1;
      *puVar5 = 0x39;
      FUN_100231fe((int)uVar6,(int)((ulonglong)uVar6 >> 0x20),in_stack_0000000c);
      if ((int)in_stack_00000024 < 1) break;
      puVar3 = (undefined1 *)FUN_10025fb4();
      uVar6 = FUN_100260a8(puVar3,in_stack_00000018);
      if (((int)uVar6 < 1) && (((int)uVar6 != 0 || (-1 < (int)unaff_r10 << 0x1f)))) break;
      if (unaff_r10 != (undefined1 *)0x39) goto LAB_10023780;
      puVar1 = unaff_r7;
      puVar2 = (undefined1 *)0x39;
      unaff_r7 = puVar4;
      puVar5 = unaff_r11;
    }
  }
  else if (0 < unaff_r8) {
LAB_10023780:
    unaff_r10 = (undefined1 *)(iStack0000002c + 0x31);
  }
  *unaff_r11 = (char)unaff_r10;
  FUN_1002320c();
  return;
}



/* FUN_10023dc4 at 10023dc4 */

void FUN_10023dc4(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x1af,0,"Balloc succeeded");
}



/* FUN_10023df2 at 10023df2 */

void FUN_10023df2(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  int unaff_r7;
  undefined1 *unaff_r8;
  int unaff_r10;
  undefined1 *puVar4;
  undefined1 *unaff_r11;
  ulonglong uVar5;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000018;
  int in_stack_00000024;
  int in_stack_0000002c;
  
  puVar2 = (undefined1 *)0x0;
  uVar5 = FUN_100235a6();
  while (((int)uVar5 == 0 && (unaff_r7 << 0x1f < 0))) {
    uVar5 = uVar5 & 0xffffffff00000000;
    puVar1 = puVar2;
    iVar3 = unaff_r7;
    puVar4 = unaff_r11;
    do {
      unaff_r7 = unaff_r10;
      puVar2 = unaff_r8;
      unaff_r11 = puVar1;
      if (iVar3 != 0x39) {
        unaff_r7 = in_stack_0000002c + 0x31;
        unaff_r11 = puVar4;
        goto LAB_10023784;
      }
      *puVar4 = 0x39;
      FUN_100231fe((int)uVar5,(int)(uVar5 >> 0x20),in_stack_0000000c);
      if (in_stack_00000024 < 1) goto LAB_10023784;
      unaff_r10 = FUN_10025fb4();
      uVar5 = FUN_100260a8(unaff_r10,in_stack_00000018);
      unaff_r8 = (undefined1 *)0x39;
      puVar1 = puVar2;
      iVar3 = unaff_r7;
      puVar4 = unaff_r11;
    } while (0 < (int)uVar5);
  }
LAB_10023784:
  *unaff_r11 = (char)unaff_r7;
  FUN_1002320c();
  return;
}



/* FUN_10023e32 at 10023e32 */

/* WARNING: Removing unreachable block (ram,0x1002384e) */
/* WARNING: Removing unreachable block (ram,0x10023856) */
/* WARNING: Removing unreachable block (ram,0x10023858) */
/* WARNING: Removing unreachable block (ram,0x1002385e) */
/* WARNING: Removing unreachable block (ram,0x10023860) */
/* WARNING: Removing unreachable block (ram,0x10023184) */
/* WARNING: Removing unreachable block (ram,0x1002318a) */
/* WARNING: Removing unreachable block (ram,0x100231ae) */
/* WARNING: Removing unreachable block (ram,0x100231be) */
/* WARNING: Removing unreachable block (ram,0x100231cc) */
/* WARNING: Removing unreachable block (ram,0x100231d0) */
/* WARNING: Removing unreachable block (ram,0x100231f0) */
/* WARNING: Removing unreachable block (ram,0x1002357e) */
/* WARNING: Removing unreachable block (ram,0x10023584) */
/* WARNING: Removing unreachable block (ram,0x1002358e) */
/* WARNING: Removing unreachable block (ram,0x10023582) */
/* WARNING: Removing unreachable block (ram,0x100231f2) */
/* WARNING: Removing unreachable block (ram,0x1002319e) */

void FUN_10023e32(void)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int extraout_r3;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  char *unaff_r10;
  char *unaff_r11;
  undefined8 uVar9;
  char *in_stack_0000000c;
  uint in_stack_00000010;
  uint in_stack_00000014;
  int iStack00000018;
  char *in_stack_00000024;
  char *in_stack_00000028;
  int in_stack_0000002c;
  uint in_stack_00000030;
  int in_stack_00000034;
  char *in_stack_00000040;
  int in_stack_00000098;
  
  pcVar5 = in_stack_00000028 + -1;
  iVar4 = in_stack_0000002c;
  if (in_stack_0000002c < (int)pcVar5) {
    FUN_10025ccc();
    if (in_stack_00000024 == (char *)0x0) {
      FUN_100232a6();
    }
    pcVar5 = in_stack_00000024;
    if ((int)(unaff_r11 + (int)in_stack_00000028) < (int)in_stack_00000024) {
      pcVar5 = unaff_r11 + (int)in_stack_00000028;
    }
    FUN_100232a6();
    FUN_100230e6();
    FUN_100233d4();
    in_stack_00000024 = in_stack_00000024 + (4 - (int)pcVar5);
    in_stack_00000024[0] = '\0';
    in_stack_00000024[1] = '\0';
    in_stack_00000024[2] = '\0';
    in_stack_00000024[3] = '\0';
    FUN_10022fd4();
                    /* WARNING: Subroutine does not return */
    FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0xef,0,"REENT malloc succeeded");
  }
LAB_10023a14:
  pcVar5 = (char *)(iVar4 - (int)pcVar5);
  if ((int)in_stack_00000028 < 0) {
    uVar9 = FUN_10025ccc();
    pcVar8 = in_stack_00000024;
    in_stack_00000024 = in_stack_00000024 + -(int)in_stack_00000028;
  }
  else {
    pcVar8 = in_stack_00000024 + (int)in_stack_00000028;
    unaff_r11 = unaff_r11 + (int)in_stack_00000028;
    uVar9 = FUN_10025ccc();
    pcVar1 = (char *)uVar9;
    if (in_stack_00000024 == (char *)0x0) {
      if (in_stack_0000002c != 0) {
        pcVar6 = (char *)0x0;
        if (pcVar5 != (char *)0x0) {
          FUN_10023c1c();
        }
        pcVar7 = (char *)FUN_10025ea8();
        iStack00000018 = FUN_10025ccc();
        if (in_stack_00000030 != 0) {
          FUN_10023bac();
        }
        if ((((in_stack_00000098 < 2) && (in_stack_00000010 == 0)) &&
            ((in_stack_00000014 & 0xfffff) == 0)) && ((in_stack_00000014 & 0x7ff00000) != 0)) {
          in_stack_00000024 = pcVar8 + 1;
          iVar4 = 1;
          unaff_r11 = unaff_r11 + 1;
          in_stack_00000030 = 1;
        }
        else {
          iVar4 = 1;
          in_stack_00000024 = pcVar8;
        }
        do {
          uVar3 = (uint)(unaff_r11 + iVar4) & 0x1f;
          if (((uint)(unaff_r11 + iVar4) & 0x1f) == 0) {
            iVar4 = 0x1c;
LAB_1002313a:
            pcVar6 = pcVar6 + iVar4;
            in_stack_00000024 = in_stack_00000024 + iVar4;
            unaff_r11 = unaff_r11 + iVar4;
          }
          else {
            if (4 < (int)(0x20 - uVar3)) {
              iVar4 = 0x1c - uVar3;
              goto LAB_1002313a;
            }
            if (0x20 - uVar3 != 4) {
              iVar4 = 0x3c - uVar3;
              goto LAB_1002313a;
            }
          }
          if (0 < (int)in_stack_00000024) {
            pcVar7 = (char *)FUN_10025fb4();
          }
          if (0 < (int)unaff_r11) {
            iStack00000018 = FUN_10025fb4();
          }
          if ((in_stack_00000034 != 0) && (iVar4 = FUN_100260a8(pcVar7,iStack00000018), iVar4 < 0))
          {
            pcVar7 = (char *)FUN_10025a90();
            pcVar1 = (char *)FUN_10025a90();
            in_stack_00000028 = in_stack_00000040;
          }
          if ((0 < (int)in_stack_00000028) || (in_stack_00000098 < 3)) goto LAB_1002366c;
          if (in_stack_00000028 == (char *)0x0) {
            iStack00000018 = FUN_10025a90();
            iVar4 = FUN_100260a8(pcVar7,iStack00000018);
            if (0 < iVar4) {
              *in_stack_0000000c = '1';
              FUN_10025a44();
              if (pcVar1 == (char *)0x0) {
                FUN_1002306c();
                return;
              }
              FUN_1002322c();
              return;
            }
          }
          FUN_10025a44();
          if (pcVar1 != (char *)0x0) {
            FUN_1002322c();
          }
          FUN_1002306c();
          if (((in_stack_00000010 == 0) && ((in_stack_00000014 & 0xfffff) == 0)) &&
             ((in_stack_00000014 & 0x7ff00000) != 0)) {
            in_stack_00000024 = in_stack_00000024 + 1;
            in_stack_00000030 = 1;
            unaff_r11 = unaff_r11 + 1;
          }
          iVar4 = FUN_10025bdc(*(undefined4 *)
                                (*(int *)(iStack00000018 + 0x10) * 4 + iStack00000018 + 0x10));
          iVar4 = 0x20 - iVar4;
          pcVar6 = in_stack_0000000c;
        } while( true );
      }
      goto LAB_10023a42;
    }
  }
  pcVar1 = (char *)uVar9;
  if ((int)unaff_r11 < 1) {
    if (in_stack_0000002c != 0) {
      FUN_1002329e();
      return;
    }
LAB_10023a42:
    FUN_100232b4();
    return;
  }
  pcVar6 = in_stack_00000024;
  if ((int)unaff_r11 < (int)in_stack_00000024) {
    pcVar6 = unaff_r11;
  }
  pcVar7 = in_stack_00000024 + -(int)pcVar6;
  if (in_stack_0000002c != 0) {
    FUN_1002329e(pcVar1,(int)((ulonglong)uVar9 >> 0x20),unaff_r11);
  }
  FUN_100232b4();
  in_stack_00000024 = pcVar8 + -(int)pcVar6;
  goto LAB_100239fa;
LAB_1002366c:
  if (0 < (int)pcVar6) {
    pcVar1 = (char *)FUN_10025fb4();
  }
  pcVar8 = pcVar1;
  if (in_stack_00000030 != 0) {
    iVar4 = FUN_100259c0();
    if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0x2ef,0,"Balloc succeeded");
    }
    FUN_1001f4d4(iVar4 + 0xc,pcVar1 + 0xc,(*(int *)(pcVar1 + 0x10) + 2) * 4);
    pcVar8 = (char *)FUN_10025fb4();
  }
  in_stack_00000028 = in_stack_00000028 + (int)(in_stack_0000000c + -1);
  in_stack_00000030 = in_stack_00000010 & 1;
  pcVar6 = in_stack_0000000c;
LAB_100236a2:
  in_stack_0000002c = FUN_10022c2c(pcVar7,iStack00000018);
  unaff_r10 = (char *)(in_stack_0000002c + 0x30);
  iVar4 = FUN_100260a8(pcVar7,pcVar1);
  iVar2 = FUN_100260e4();
  pcVar5 = pcVar1;
  if (*(int *)(iVar2 + 0xc) != 0) {
    uVar9 = FUN_10025a44();
    if (iVar4 < 0) goto LAB_10023762;
    if ((in_stack_00000010 & 1) == 0 && (iVar4 == 0 && in_stack_00000098 == 0)) goto LAB_10023762;
LAB_100237c2:
    pcVar1 = pcVar8;
    if (unaff_r10 != (char *)0x39) {
      *pcVar6 = (char)in_stack_0000002c + '1';
      FUN_1002320c();
      return;
    }
    goto LAB_10023d72;
  }
  in_stack_00000024 = (char *)FUN_100260a8(pcVar7,iVar2);
  uVar9 = FUN_10025a44();
  if (in_stack_00000024 == (char *)0x0 && in_stack_00000098 == 0) {
    if (in_stack_00000030 == 0) {
      pcVar1 = pcVar8;
      if (unaff_r10 == (char *)0x39) goto LAB_10023d72;
      if (iVar4 < 1) goto LAB_10023784;
      goto LAB_10023780;
    }
    if (iVar4 < 0) goto LAB_10023784;
  }
  else {
    if (iVar4 < 0) goto LAB_10023d8c;
    if ((iVar4 == 0 && in_stack_00000098 == 0) && in_stack_00000030 == 0) goto LAB_10023d8c;
    if (0 < (int)in_stack_00000024) goto LAB_100237c2;
  }
  pcVar5 = pcVar6 + 1;
  *pcVar6 = (char)unaff_r10;
  if (pcVar6 != in_stack_00000028) {
    pcVar7 = (char *)FUN_10025a90();
    pcVar6 = pcVar5;
    if (pcVar1 == pcVar8) {
      pcVar1 = (char *)FUN_10025a90();
      pcVar8 = pcVar1;
    }
    else {
      pcVar1 = (char *)FUN_10025a90();
      pcVar8 = (char *)FUN_10025a90();
    }
    goto LAB_100236a2;
  }
LAB_100239fa:
  FUN_100231da();
  FUN_100233d4();
  *unaff_r10 = '1';
  FUN_1002306c();
  *in_stack_0000000c = '1';
  FUN_1002320c();
  iVar4 = extraout_r3;
  unaff_r10 = pcVar7;
  unaff_r11 = pcVar1;
  goto LAB_10023a14;
LAB_10023d72:
  *pcVar6 = '9';
  FUN_100231fe((int)uVar9,(int)((ulonglong)uVar9 >> 0x20),in_stack_0000000c);
  pcVar8 = unaff_r10;
  unaff_r10 = pcVar7;
  pcVar6 = pcVar5;
LAB_10023d8c:
  if ((int)in_stack_00000024 < 1) goto LAB_10023784;
LAB_10023762:
  pcVar7 = (char *)FUN_10025fb4();
  uVar9 = FUN_100260a8(pcVar7,iStack00000018);
  if (((int)uVar9 < 1) && (((int)uVar9 != 0 || (-1 < (int)unaff_r10 << 0x1f)))) goto LAB_10023784;
  if (unaff_r10 != (char *)0x39) {
LAB_10023780:
    unaff_r10 = (char *)(in_stack_0000002c + 0x31);
LAB_10023784:
    *pcVar6 = (char)unaff_r10;
    FUN_1002320c();
    return;
  }
  unaff_r10 = (char *)0x39;
  pcVar5 = pcVar1;
  pcVar1 = pcVar8;
  goto LAB_10023d72;
}



/* FUN_10023e9c at 10023e9c */

void FUN_10023e9c(void)

{
  int unaff_r6;
  
  *(undefined4 *)(unaff_r6 + 4) = 0;
  FUN_10022fd4();
                    /* WARNING: Subroutine does not return */
  FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0xef,0,"REENT malloc succeeded");
}



/* FUN_10023ea4 at 10023ea4 */

void FUN_10023ea4(void)

{
                    /* WARNING: Subroutine does not return */
  FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/dtoa.c",0xef,0,"REENT malloc succeeded");
}



/* FUN_10023ebc at 10023ebc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10023ebc(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 in_cr10;
  undefined8 uVar5;
  char *pcStack0000000c;
  
  pcStack0000000c = "Infinity";
  uVar5 = FUN_10022e06();
  iVar3 = (int)((ulonglong)uVar5 >> 0x20);
  iVar1 = (int)uVar5;
  coprocessor_storelong(0xc,in_cr10,iVar1);
  iVar2 = FUN_10024860(8,iVar3,iVar1 >> 0x20);
  FUN_10025050(iVar1);
  uVar4 = *(uint *)(_DAT_20000a00 + 4) & 0xfffffffc;
  iVar3 = FUN_1001e4d0(((uVar4 - 0x11) - iVar3) + iVar2,iVar2);
  iVar3 = iVar2 * (iVar3 + -1);
  if ((iVar2 <= iVar3) && (iVar2 = FUN_10026850(iVar1,0), iVar2 == _DAT_20000a00 + uVar4)) {
    iVar2 = FUN_10026850(iVar1,-iVar3);
    if (iVar2 != -1) {
      *(uint *)(_DAT_20000a00 + 4) = uVar4 - iVar3 | 1;
      _DAT_20001370 = _DAT_20001370 - iVar3;
      FUN_10025060(iVar1);
      return 1;
    }
    iVar2 = FUN_10026850(iVar1,0);
    if (0xf < iVar2 - _DAT_20000a00) {
      _DAT_20001370 = iVar2 - _DAT_200009f0;
      *(uint *)(_DAT_20000a00 + 4) = iVar2 - _DAT_20000a00 | 1;
    }
  }
  FUN_10025060(iVar1);
  return 0;
}



/* FUN_10023ee8 at 10023ee8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10023ee8(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = FUN_10024860(8);
  FUN_10025050(param_1);
  uVar3 = *(uint *)(_DAT_20000a00 + 4) & 0xfffffffc;
  iVar2 = FUN_1001e4d0(((uVar3 - 0x11) - param_2) + iVar1,iVar1);
  iVar2 = iVar1 * (iVar2 + -1);
  if ((iVar1 <= iVar2) && (iVar1 = FUN_10026850(param_1,0), iVar1 == _DAT_20000a00 + uVar3)) {
    iVar1 = FUN_10026850(param_1,-iVar2);
    if (iVar1 != -1) {
      *(uint *)(_DAT_20000a00 + 4) = uVar3 - iVar2 | 1;
      _DAT_20001370 = _DAT_20001370 - iVar2;
      FUN_10025060(param_1);
      return 1;
    }
    iVar1 = FUN_10026850(param_1,0);
    if (0xf < iVar1 - _DAT_20000a00) {
      _DAT_20001370 = iVar1 - _DAT_200009f0;
      *(uint *)(_DAT_20000a00 + 4) = iVar1 - _DAT_20000a00 | 1;
    }
  }
  FUN_10025060(param_1);
  return 0;
}



/* FUN_10023f9c at 10023f9c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10023f9c(undefined4 param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined1 *puVar8;
  uint *puVar9;
  int iVar10;
  
  if (param_2 == 0) {
    return;
  }
  FUN_10025050();
  puVar1 = (uint *)(param_2 + -8);
  uVar3 = *(uint *)(param_2 + -4);
  uVar4 = uVar3 & 0xfffffffe;
  puVar9 = (uint *)((int)puVar1 + uVar4);
  uVar2 = puVar9[1] & 0xfffffffc;
  if (_DAT_20000a00 == puVar9) {
    uVar4 = uVar4 + uVar2;
    if ((uVar3 & 1) == 0) {
      uVar2 = *puVar1;
      puVar1 = (uint *)((int)puVar1 - uVar2);
      uVar3 = puVar1[2];
      uVar4 = uVar4 + uVar2;
      uVar2 = puVar1[3];
      *(uint *)(uVar3 + 0xc) = uVar2;
      *(uint *)(uVar2 + 8) = uVar3;
    }
    puVar1[1] = uVar4 | 1;
    _DAT_20000a00 = puVar1;
    if (_DAT_200009f4 <= uVar4) {
      FUN_10023ee8(param_1,_DAT_2000136c);
    }
    goto LAB_1002403a;
  }
  puVar9[1] = uVar2;
  uVar5 = *(uint *)((int)puVar9 + uVar2 + 4) & 1;
  if ((uVar3 & 1) == 0) {
    uVar3 = *puVar1;
    puVar1 = (uint *)((int)puVar1 - uVar3);
    puVar6 = (undefined1 *)puVar1[2];
    uVar4 = uVar4 + uVar3;
    if (puVar6 == &DAT_20000a00) {
      if (uVar5 == 0) {
        uVar4 = uVar4 + uVar2;
        uVar2 = puVar9[2];
        uVar3 = puVar9[3];
        *(uint *)(uVar2 + 0xc) = uVar3;
        *(uint *)(uVar3 + 8) = uVar2;
        puVar1[1] = uVar4 | 1;
        *(uint *)((int)puVar1 + uVar4) = uVar4;
      }
      else {
        puVar1[1] = uVar4 | 1;
        *puVar9 = uVar4;
      }
      goto LAB_1002403a;
    }
    uVar3 = puVar1[3];
    *(uint *)(puVar6 + 0xc) = uVar3;
    *(undefined1 **)(uVar3 + 8) = puVar6;
    if (uVar5 == 0) goto LAB_10024050;
    puVar1[1] = uVar4 | 1;
    *puVar9 = uVar4;
  }
  else if (uVar5 == 0) {
LAB_10024050:
    uVar4 = uVar4 + uVar2;
    puVar6 = (undefined1 *)puVar9[2];
    if (puVar6 == &DAT_20000a00) {
      _DAT_20000a08 = puVar1;
      _DAT_20000a0c = puVar1;
      puVar1[1] = uVar4 | 1;
      puVar1[3] = (uint)&DAT_20000a00;
      puVar1[2] = (uint)&DAT_20000a00;
      *(uint *)((int)puVar1 + uVar4) = uVar4;
      goto LAB_1002403a;
    }
    uVar2 = puVar9[3];
    *(uint *)(puVar6 + 0xc) = uVar2;
    *(undefined1 **)(uVar2 + 8) = puVar6;
    puVar1[1] = uVar4 | 1;
    *(uint *)((int)puVar1 + uVar4) = uVar4;
  }
  else {
    *(uint *)(param_2 + -4) = uVar3 | 1;
    *puVar9 = uVar4;
  }
  if (uVar4 < 0x200) {
    _DAT_200009fc = 1 << (uVar4 >> 5 & 0xff) | _DAT_200009fc;
    uVar4 = uVar4 & 0xfffffff8;
    uVar2 = *(uint *)(&DAT_20000a00 + uVar4);
    puVar1[3] = uVar4 + 0x200009f8;
    puVar1[2] = uVar2;
    *(uint **)(&DAT_20000a00 + uVar4) = puVar1;
    *(uint **)(uVar2 + 0xc) = puVar1;
  }
  else {
    uVar2 = uVar4 >> 9;
    if (uVar2 < 5) {
      iVar10 = (uVar4 >> 6) + 0x38;
      iVar7 = ((uVar4 >> 6) + 0x39) * 8;
    }
    else if (uVar2 < 0x15) {
      iVar10 = uVar2 + 0x5b;
      iVar7 = (uVar2 + 0x5c) * 8;
    }
    else if (uVar2 < 0x55) {
      iVar10 = (uVar4 >> 0xc) + 0x6e;
      iVar7 = ((uVar4 >> 0xc) + 0x6f) * 8;
    }
    else if (uVar2 < 0x155) {
      iVar10 = (uVar4 >> 0xf) + 0x77;
      iVar7 = ((uVar4 >> 0xf) + 0x78) * 8;
    }
    else if (uVar2 < 0x555) {
      iVar10 = (uVar4 >> 0x12) + 0x7c;
      iVar7 = ((uVar4 >> 0x12) + 0x7d) * 8;
    }
    else {
      iVar10 = 0x7e;
      iVar7 = 0x3f8;
    }
    puVar6 = *(undefined1 **)(iVar7 + 0x200009f8);
    puVar8 = &DAT_200009f0 + iVar7;
    if (puVar8 == puVar6) {
      _DAT_200009fc = 1 << (iVar10 >> 2 & 0xffU) | _DAT_200009fc;
    }
    else {
      do {
        if ((*(uint *)(puVar6 + 4) & 0xfffffffc) <= uVar4) break;
        puVar6 = *(undefined1 **)(puVar6 + 8);
      } while (puVar8 != puVar6);
      puVar8 = *(undefined1 **)(puVar6 + 0xc);
    }
    puVar1[3] = (uint)puVar8;
    puVar1[2] = (uint)puVar6;
    *(uint **)(puVar8 + 8) = puVar1;
    *(uint **)(puVar6 + 0xc) = puVar1;
  }
LAB_1002403a:
  FUN_10025060(param_1);
  return;
}



/* FUN_1002418c at 1002418c */

uint FUN_1002418c(undefined4 *param_1,byte *param_2,undefined4 *param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined8 uVar11;
  
  if ((0x24 < param_4) || (param_4 == 1)) {
    puVar3 = (undefined4 *)FUN_100219bc();
    *puVar3 = 0x16;
    return 0;
  }
  pbVar6 = param_2;
  do {
    pbVar5 = pbVar6;
    uVar7 = (uint)*pbVar5;
    pbVar6 = pbVar5 + 1;
  } while (((&DAT_1002b1f5)[uVar7] & 8) != 0);
  if (uVar7 == 0x2d) {
    uVar7 = (uint)*pbVar6;
    uVar10 = 0x80000000;
    pbVar6 = pbVar5 + 2;
    bVar1 = true;
  }
  else if (uVar7 == 0x2b) {
    uVar7 = (uint)*pbVar6;
    pbVar6 = pbVar5 + 2;
    uVar10 = 0x7fffffff;
    bVar1 = false;
  }
  else {
    uVar10 = 0x7fffffff;
    bVar1 = false;
  }
  if (param_4 == 0) {
    if (uVar7 != 0x30) {
      param_4 = 10;
      uVar9 = 10;
      goto LAB_100241e2;
    }
    if ((*pbVar6 & 0xdf) != 0x58) {
      param_4 = 8;
      uVar9 = 8;
      goto LAB_100241e2;
    }
  }
  else {
    uVar9 = param_4;
    if (((param_4 != 0x10) || (uVar9 = 0x10, uVar7 != 0x30)) || ((*pbVar6 & 0xdf) != 0x58))
    goto LAB_100241e2;
  }
  uVar7 = (uint)pbVar6[1];
  param_4 = 0x10;
  pbVar6 = pbVar6 + 2;
  uVar9 = 0x10;
LAB_100241e2:
  uVar11 = FUN_1001e4d0(uVar10,uVar9);
  iVar4 = 0;
  uVar2 = 0;
  do {
    uVar8 = uVar7 - 0x30;
    if (9 < uVar8) {
      uVar8 = uVar7 - 0x41;
      if ((0x19 < uVar8) && (uVar8 = uVar7 - 0x61, 0x19 < uVar8)) break;
      uVar8 = uVar8 + 10;
    }
    if ((int)param_4 <= (int)uVar8) break;
    if (iVar4 != -1) {
      if (((uint)uVar11 < uVar2) ||
         (((uint)uVar11 == uVar2 && ((int)((ulonglong)uVar11 >> 0x20) < (int)uVar8)))) {
        iVar4 = -1;
      }
      else {
        iVar4 = 1;
        uVar2 = uVar8 + uVar9 * uVar2;
      }
    }
    uVar7 = (uint)*pbVar6;
    pbVar6 = pbVar6 + 1;
  } while( true );
  if (iVar4 == -1) {
    *param_1 = 0x22;
    uVar2 = uVar10;
    if (param_3 == (undefined4 *)0x0) {
      return uVar10;
    }
  }
  else {
    if (bVar1) {
      uVar2 = -uVar2;
    }
    if (param_3 == (undefined4 *)0x0) {
      return uVar2;
    }
    if (iVar4 == 0) goto LAB_1002426e;
  }
  param_2 = pbVar6 + -1;
LAB_1002426e:
  *param_3 = param_2;
  return uVar2;
}



/* FUN_100242e4 at 100242e4 */

void FUN_100242e4(void)

{
  FUN_1002418c();
  return;
}



/* FUN_100242ec at 100242ec */

void FUN_100242ec(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001c744();
  FUN_1002418c(uVar1,param_1,param_2,param_3);
  return;
}



/* FUN_10024304 at 10024304 */

void FUN_10024304(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001c744();
  FUN_1002418c(uVar1,param_1,param_2,param_3);
  return;
}



/* FUN_1002431c at 1002431c */

uint FUN_1002431c(undefined4 param_1,code *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = 0;
  do {
    iVar2 = param_3[2];
    iVar3 = param_3[1] + -1;
    if (-1 < iVar3) {
      do {
        if ((1 < *(ushort *)(iVar2 + 0xc)) && (*(short *)(iVar2 + 0xe) != -1)) {
          uVar1 = (*param_2)(param_1,iVar2);
          uVar4 = uVar4 | uVar1;
        }
        iVar2 = iVar2 + 0x70;
        bVar5 = iVar3 != 0;
        iVar3 = iVar3 + -1;
      } while (bVar5);
    }
    param_3 = (int *)*param_3;
  } while (param_3 != (int *)0x0);
  return uVar4;
}



/* FUN_10024360 at 10024360 */

int FUN_10024360(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  if (((uint)param_1 & 3) == 0) {
    puVar3 = param_1;
  }
  else {
    puVar2 = param_1;
    do {
      if ((char)*puVar2 == '\0') goto LAB_10024378;
      puVar2 = (uint *)((int)puVar2 + 1);
      puVar3 = puVar2;
    } while (((uint)puVar2 & 3) != 0);
  }
  uVar1 = *puVar3 + 0xfefefeff & ~*puVar3;
  while ((puVar2 = puVar3, (uVar1 & 0x80808080) == 0 &&
         (puVar2 = puVar3 + 1, (puVar3[1] + 0xfefefeff & ~puVar3[1] & 0x80808080) == 0))) {
    puVar2 = puVar3 + 2;
    puVar3 = puVar3 + 2;
    uVar1 = *puVar2 + 0xfefefeff & ~*puVar2;
  }
  for (; (char)*puVar2 != '\0'; puVar2 = (uint *)((int)puVar2 + 1)) {
  }
LAB_10024378:
  return (int)puVar2 - (int)param_1;
}



/* FUN_100243bc at 100243bc */

void FUN_100243bc(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001c744();
  FUN_10022670(uVar1,param_1);
  return;
}



/* FUN_100243cc at 100243cc */

void FUN_100243cc(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001c744();
  FUN_10023f9c(uVar1,param_1);
  return;
}



/* FUN_100243dc at 100243dc */

undefined4 FUN_100243dc(undefined4 param_1,uint *param_2,int *param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  byte bVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  uint *puVar12;
  undefined8 uVar13;
  int local_40;
  int local_3c;
  uint *local_38;
  int local_34;
  int local_30;
  
  uVar6 = param_2[2];
  if (uVar6 - 1 < 0x15d) {
    uVar5 = *param_2;
    local_30 = 0;
  }
  else {
    uVar5 = *param_2;
    local_30 = uVar6 - 0x15d;
    uVar6 = 0x15d;
    param_2[2] = 0x15d;
  }
  puVar12 = param_2 + 7;
  *param_2 = uVar5 | 0x780;
  iVar11 = 0;
  local_38 = (uint *)0x0;
  local_34 = 0;
  local_40 = 0;
  local_3c = 0;
  uVar5 = 0;
  puVar10 = puVar12;
LAB_10024430:
  bVar2 = *(byte *)*param_3;
  switch(bVar2) {
  case 0x2b:
  case 0x2d:
    if ((*param_2 & 0x80) != 0) {
      *param_2 = *param_2 & 0xffffff7f;
      goto LAB_10024530;
    }
    break;
  case 0x2e:
    if ((int)(*param_2 << 0x16) < 0) {
      *param_2 = *param_2 & 0xfffffd7f;
      local_3c = local_40;
      goto LAB_10024530;
    }
    break;
  case 0x30:
    if (-1 < (int)(*param_2 << 0x17)) goto LAB_1002451a;
    *param_2 = *param_2 & 0xffffff7f;
    local_40 = local_40 + 1;
    if (local_30 == 0) {
      uVar6 = param_2[2] - 1;
    }
    else {
      local_30 = local_30 + -1;
    }
    goto LAB_10024538;
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
LAB_1002451a:
    if (iVar11 + uVar5 == 0) {
      uVar5 = 0;
      *param_2 = *param_2 & 0xfffffe7f;
      iVar11 = 0;
      goto LAB_10024530;
    }
    break;
  case 0x41:
  case 0x61:
    if (iVar11 == 1) {
      iVar11 = 2;
      goto LAB_10024530;
    }
    break;
  case 0x45:
  case 0x65:
    uVar6 = *param_2;
    if ((uVar6 & 0x500) != 0x400) {
      if ((uVar6 & 0x400) == 0) break;
      if (local_40 == 0) goto LAB_1002466e;
    }
    if (-1 < (int)(uVar6 << 0x16)) {
      local_34 = local_40 - local_3c;
      local_38 = puVar10;
    }
    *param_2 = uVar6 & 0xfffff87f | 0x180;
    local_40 = 0;
    goto LAB_10024530;
  case 0x46:
  case 0x66:
    if (uVar5 == 2) {
      uVar5 = 3;
      goto LAB_10024530;
    }
    break;
  case 0x49:
  case 0x69:
    if (uVar5 != 0) {
      if ((uVar5 - 3 & 0xfd) != 0) break;
LAB_1002458c:
      uVar5 = uVar5 + 1 & 0xff;
      goto LAB_10024530;
    }
    if (local_40 != 0) {
      uVar6 = *param_2 & 0xfffffeff;
      *param_2 = uVar6;
      if (1 < iVar11 - 1U) goto LAB_100244b2;
      goto LAB_10024632;
    }
    if ((*param_2 & 0x700) != 0x700) {
LAB_1002466e:
      local_40 = 0;
      goto joined_r0x1002462e;
    }
    uVar5 = 1;
    *param_2 = *param_2 & 0xfffff87f;
    goto LAB_10024530;
  case 0x4e:
  case 0x6e:
    if (iVar11 == 0) {
      if ((local_40 != 0) || ((*param_2 & 0x700) != 0x700)) {
LAB_10024582:
        if ((uVar5 == 1) || (uVar5 == 4)) goto LAB_1002458c;
        break;
      }
      *param_2 = *param_2 & 0xfffff87f;
      iVar11 = 1;
    }
    else {
      if (iVar11 != 2) goto LAB_10024582;
      iVar11 = 3;
    }
LAB_10024530:
    *(byte *)puVar10 = bVar2;
    puVar10 = (uint *)((int)puVar10 + 1);
    uVar6 = param_2[2] - 1;
LAB_10024538:
    param_2[2] = uVar6;
    param_2[4] = param_2[4] + 1;
    iVar7 = param_3[1];
    param_3[1] = iVar7 + -1;
    if (iVar7 + -1 < 1) {
      iVar7 = (*(code *)param_2[0x60])(param_1,param_3);
      if (iVar7 != 0) break;
      uVar6 = param_2[2];
    }
    else {
      *param_3 = *param_3 + 1;
    }
    if (uVar6 == 0) goto joined_r0x1002455a;
    goto LAB_10024430;
  case 0x54:
  case 0x74:
    if (uVar5 == 6) {
      uVar5 = 7;
      goto LAB_10024530;
    }
    break;
  case 0x59:
  case 0x79:
    if (uVar5 == 7) {
      uVar5 = 8;
      goto LAB_10024530;
    }
  }
joined_r0x1002455a:
  if (local_40 != 0) {
    *param_2 = *param_2 & 0xfffffeff;
  }
joined_r0x1002462e:
  if (iVar11 - 1U < 2) {
LAB_10024632:
    if (puVar12 < puVar10) {
      do {
        puVar10 = (uint *)((int)puVar10 + -1);
        (*(code *)param_2[0x5f])(param_1,*(byte *)puVar10,param_3);
        param_2[4] = param_2[4] - 1;
      } while (puVar10 != puVar12);
    }
    return 1;
  }
  if (uVar5 - 1 < 7) {
    if (uVar5 < 3) {
      if (puVar10 <= puVar12) {
        return 1;
      }
      do {
        puVar10 = (uint *)((int)puVar10 + -1);
        (*(code *)param_2[0x5f])(param_1,*(byte *)puVar10,param_3);
        param_2[4] = param_2[4] - 1;
      } while (puVar10 != puVar12);
      return 1;
    }
    if (uVar5 != 3) {
      puVar9 = puVar10;
      do {
        puVar9 = (uint *)((int)puVar9 + -1);
        (*(code *)param_2[0x5f])(param_1,*(byte *)puVar9,param_3);
        param_2[4] = param_2[4] - 1;
      } while (((uint)((int)puVar9 + (uVar5 - (int)puVar10)) & 0xff) != 3);
      puVar10 = (uint *)((int)puVar10 + (-1 - (uVar5 - 4 & 0xff)));
    }
  }
  uVar6 = *param_2;
LAB_100244b2:
  if ((int)(uVar6 << 0x17) < 0) {
    if ((int)(uVar6 << 0x15) < 0) {
      if (puVar10 <= puVar12) {
        return 1;
      }
      do {
        puVar10 = (uint *)((int)puVar10 + -1);
        (*(code *)param_2[0x5f])(param_1,*(byte *)puVar10,param_3);
        param_2[4] = param_2[4] - 1;
      } while (puVar10 != puVar12);
      return 1;
    }
    puVar9 = (uint *)((int)puVar10 + -1);
    bVar2 = *(byte *)puVar9;
    param_2[4] = param_2[4] - 1;
    if ((bVar2 != 0x65) && (bVar2 != 0x45)) {
      (*(code *)param_2[0x5f])(param_1,bVar2,param_3);
      bVar2 = *(byte *)((int)puVar10 + -2);
      param_2[4] = param_2[4] - 1;
      puVar9 = (uint *)((int)puVar10 + -2);
    }
    puVar10 = puVar9;
    (*(code *)param_2[0x5f])(param_1,bVar2,param_3);
    uVar6 = *param_2;
  }
  if ((uVar6 & 0x10) != 0) {
    return 0;
  }
  *(byte *)puVar10 = (byte)uVar6 & 0x10;
  if ((*param_2 & 0x600) == 0x400) {
    if (local_3c == local_40) goto LAB_100246b2;
    local_3c = local_3c - local_40;
    local_38 = puVar10;
  }
  else {
    if (local_34 == 0) goto LAB_100246b2;
    local_3c = FUN_100242e4(param_1,(byte *)((int)local_38 + 1),0,10);
    local_3c = local_3c - local_34;
  }
  if ((uint *)((int)param_2 + 0x16f) <= local_38) {
    local_38 = (uint *)((int)param_2 + 0x16e);
  }
  FUN_1002597c(local_38,&DAT_1002ad90,local_3c);
LAB_100246b2:
  uVar13 = FUN_10020ccc(param_1,puVar12,0);
  uVar3 = (undefined4)((ulonglong)uVar13 >> 0x20);
  uVar1 = (undefined4)uVar13;
  puVar8 = (undefined4 *)*param_4;
  puVar4 = puVar8 + 1;
  if ((int)(*param_2 << 0x1e) < 0) {
    *param_4 = puVar4;
    *(undefined8 *)*puVar8 = uVar13;
  }
  else if ((int)(*param_2 << 0x1d) < 0) {
    *param_4 = puVar4;
    *(undefined8 *)*puVar8 = uVar13;
  }
  else {
    *param_4 = puVar4;
    puVar8 = (undefined4 *)*puVar8;
    iVar11 = FUN_1001ea62(uVar1,uVar3,uVar1,uVar3);
    if (iVar11 == 0) {
      uVar1 = FUN_1001eb84(uVar1,uVar3);
      *puVar8 = uVar1;
    }
    else {
      uVar1 = FUN_10025938("");
      *puVar8 = uVar1;
    }
  }
  param_2[3] = param_2[3] + 1;
  return 0;
}



/* FUN_10024838 at 10024838 */

void FUN_10024838(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar1 = FUN_1001c744();
  FUN_1002553c(uVar1,param_1,param_2,&uStack_8);
  return;
}



/* FUN_10024860 at 10024860 */

undefined4 FUN_10024860(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0x1000;
  if (param_1 != 8) {
    puVar1 = (undefined4 *)FUN_100219bc();
    *puVar1 = 0x16;
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



/* FUN_1002487c at 1002487c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_1002487c(undefined4 *param_1,int *param_2,uint param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint local_30;
  
  if (param_2 == (int *)0x0) {
    piVar2 = (int *)FUN_10022670(param_1,param_3);
    return piVar2;
  }
  FUN_10025050();
  piVar2 = param_2 + -2;
  uVar6 = param_2[-1];
  uVar3 = uVar6 & 0xfffffffc;
  if (param_3 + 0xb < 0x17) {
    uVar10 = 0x10;
  }
  else {
    uVar10 = param_3 + 0xb & 0xfffffff8;
    if ((int)uVar10 < 0) goto LAB_1002498e;
  }
  if (uVar10 < param_3) {
LAB_1002498e:
    *param_1 = 0xc;
    return (int *)0x0;
  }
  local_30 = uVar3;
  if ((int)uVar10 <= (int)uVar3) goto LAB_100249a0;
  iVar4 = (int)piVar2 + uVar3;
  uVar5 = *(uint *)(iVar4 + 4);
  if (_DAT_20000a00 == iVar4) {
    iVar4 = (uVar5 & 0xfffffffc) + uVar3;
    if ((int)(uVar10 + 0x10) <= iVar4) {
      _DAT_20000a00 = (int)piVar2 + uVar10;
      *(uint *)(_DAT_20000a00 + 4) = iVar4 - uVar10 | 1;
      param_2[-1] = param_2[-1] & 1U | uVar10;
      FUN_10025060(param_1);
      return param_2;
    }
    if (-1 < (int)(uVar6 << 0x1f)) {
      piVar1 = (int *)((int)piVar2 - *piVar2);
      uVar6 = piVar1[1] & 0xfffffffc;
      iVar4 = (uVar5 & 0xfffffffc) + uVar6 + uVar3;
      if ((int)(uVar10 + 0x10) <= iVar4) {
        iVar8 = piVar1[3];
        iVar9 = piVar1[2];
        *(int *)(iVar9 + 0xc) = iVar8;
        *(int *)(iVar8 + 8) = iVar9;
        uVar3 = uVar3 - 4;
        piVar2 = piVar1 + 2;
        if (uVar3 < 0x25) {
          piVar7 = piVar2;
          if (0x13 < uVar3) {
            piVar1[2] = *param_2;
            piVar1[3] = param_2[1];
            if (uVar3 < 0x1c) {
              param_2 = param_2 + 2;
              piVar7 = piVar1 + 4;
            }
            else {
              piVar1[4] = param_2[2];
              piVar1[5] = param_2[3];
              if (uVar3 == 0x24) {
                piVar1[6] = param_2[4];
                piVar7 = piVar1 + 8;
                piVar1[7] = param_2[5];
                param_2 = param_2 + 6;
              }
              else {
                param_2 = param_2 + 4;
                piVar7 = piVar1 + 6;
              }
            }
          }
          *piVar7 = *param_2;
          piVar7[1] = param_2[1];
          piVar7[2] = param_2[2];
        }
        else {
          FUN_10025130(piVar2,param_2);
        }
        _DAT_20000a00 = (int)piVar1 + uVar10;
        *(uint *)(_DAT_20000a00 + 4) = iVar4 - uVar10 | 1;
        piVar1[1] = piVar1[1] & 1U | uVar10;
        FUN_10025060(param_1);
        return piVar2;
      }
LAB_1002491a:
      local_30 = uVar6 + uVar3;
      if ((int)uVar10 <= (int)local_30) goto LAB_10024abc;
    }
  }
  else {
    if ((*(uint *)(iVar4 + (uVar5 & 0xfffffffe) + 4) & 1) == 0) {
      local_30 = (uVar5 & 0xfffffffc) + uVar3;
      if ((int)uVar10 <= (int)local_30) {
        iVar9 = *(int *)(iVar4 + 0xc);
        iVar4 = *(int *)(iVar4 + 8);
        *(int *)(iVar4 + 0xc) = iVar9;
        *(int *)(iVar9 + 8) = iVar4;
        goto LAB_100249a0;
      }
      if ((uVar6 & 1) != 0) goto LAB_10024924;
      piVar1 = (int *)((int)piVar2 - *piVar2);
      uVar6 = piVar1[1] & 0xfffffffc;
      local_30 = (uVar5 & 0xfffffffc) + uVar6 + uVar3;
      if ((int)local_30 < (int)uVar10) goto LAB_1002491a;
      iVar9 = *(int *)(iVar4 + 0xc);
      iVar4 = *(int *)(iVar4 + 8);
      *(int *)(iVar4 + 0xc) = iVar9;
      *(int *)(iVar9 + 8) = iVar4;
LAB_10024abc:
      piVar2 = piVar1;
      iVar9 = piVar2[3];
      iVar4 = piVar2[2];
      *(int *)(iVar4 + 0xc) = iVar9;
      *(int *)(iVar9 + 8) = iVar4;
      uVar3 = uVar3 - 4;
      piVar1 = piVar2 + 2;
      if (uVar3 < 0x25) {
        piVar7 = piVar1;
        if (0x13 < uVar3) {
          piVar2[2] = *param_2;
          piVar2[3] = param_2[1];
          if (uVar3 < 0x1c) {
            param_2 = param_2 + 2;
            piVar7 = piVar2 + 4;
          }
          else {
            piVar2[4] = param_2[2];
            piVar2[5] = param_2[3];
            if (uVar3 == 0x24) {
              piVar2[6] = param_2[4];
              piVar7 = piVar2 + 8;
              piVar2[7] = param_2[5];
              param_2 = param_2 + 6;
            }
            else {
              param_2 = param_2 + 4;
              piVar7 = piVar2 + 6;
            }
          }
        }
        *piVar7 = *param_2;
        piVar7[1] = param_2[1];
        piVar7[2] = param_2[2];
      }
      else {
        FUN_10025130(piVar1,param_2);
      }
      param_2 = piVar1;
      goto LAB_100249a0;
    }
    if ((uVar6 & 1) == 0) {
      piVar1 = (int *)((int)piVar2 - *piVar2);
      uVar6 = piVar1[1] & 0xfffffffc;
      goto LAB_1002491a;
    }
  }
LAB_10024924:
  piVar1 = (int *)FUN_10022670(param_1,param_3);
  if (piVar1 == (int *)0x0) {
    FUN_10025060(param_1);
    return (int *)0x0;
  }
  piVar7 = (int *)((param_2[-1] & 0xfffffffeU) + (int)piVar2);
  if (piVar7 != piVar1 + -2) {
    uVar3 = uVar3 - 4;
    if (uVar3 < 0x25) {
      piVar2 = param_2;
      piVar7 = piVar1;
      if (0x13 < uVar3) {
        *piVar1 = *param_2;
        piVar1[1] = param_2[1];
        if (uVar3 < 0x1c) {
          piVar2 = param_2 + 2;
          piVar7 = piVar1 + 2;
        }
        else {
          piVar1[2] = param_2[2];
          piVar1[3] = param_2[3];
          if (uVar3 == 0x24) {
            piVar2 = param_2 + 6;
            piVar1[4] = param_2[4];
            piVar7 = piVar1 + 6;
            piVar1[5] = param_2[5];
          }
          else {
            piVar2 = param_2 + 4;
            piVar7 = piVar1 + 4;
          }
        }
      }
      *piVar7 = *piVar2;
      piVar7[1] = piVar2[1];
      piVar7[2] = piVar2[2];
    }
    else {
      FUN_10025130(piVar1,param_2);
    }
    FUN_10023f9c(param_1,param_2);
    FUN_10025060(param_1);
    return piVar1;
  }
  local_30 = uVar3 + (piVar7[1] & 0xfffffffcU);
LAB_100249a0:
  if (local_30 - uVar10 < 0x10) {
    piVar2[1] = piVar2[1] & 1U | local_30;
    *(uint *)((int)piVar2 + local_30 + 4) = *(uint *)((int)piVar2 + local_30 + 4) | 1;
  }
  else {
    piVar2[1] = piVar2[1] & 1U | uVar10;
    *(uint *)((int)piVar2 + uVar10 + 4) = local_30 - uVar10 | 1;
    *(uint *)((int)piVar2 + local_30 + 4) = *(uint *)((int)piVar2 + local_30 + 4) | 1;
    FUN_10023f9c(param_1,(int)piVar2 + uVar10 + 8);
  }
  FUN_10025060(param_1);
  return param_2;
}



/* FUN_10024bcc at 10024bcc */

undefined4
FUN_10024bcc(undefined4 param_1,uint *param_2,uint *param_3,undefined4 param_4,code *param_5)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  uVar3 = param_2[4];
  if ((int)param_2[4] < (int)param_2[2]) {
    uVar3 = param_2[2];
  }
  *param_3 = uVar3;
  cVar1 = *(char *)((int)param_2 + 0x43);
  if (cVar1 != '\0') {
    *param_3 = uVar3 + 1;
  }
  uVar3 = *param_2;
  if ((int)(uVar3 << 0x1a) < 0) {
    uVar4 = *param_3;
    *param_3 = uVar4 + 2;
    uVar3 = *param_2;
    if (((uVar3 & 6) != 0) || (iVar6 = 0, (int)param_2[3] <= (int)(uVar4 + 2))) goto LAB_10024c2c;
LAB_10024cb2:
    do {
      iVar2 = (*param_5)(param_1,param_4,(int)param_2 + 0x19,1);
      if (iVar2 == -1) {
        return 0xffffffff;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(param_2[3] - *param_3));
    uVar3 = *param_2;
    cVar1 = *(char *)((int)param_2 + 0x43);
joined_r0x10024c36:
    uVar4 = (uint)(cVar1 != '\0');
    if ((int)(uVar3 << 0x1a) < 0) {
      *(undefined1 *)((int)param_2 + uVar4 + 0x43) = 0x30;
      iVar6 = uVar4 + 0x44;
      uVar4 = uVar4 + 2;
      *(undefined1 *)((int)param_2 + iVar6) = *(undefined1 *)((int)param_2 + 0x45);
    }
  }
  else {
    if ((uVar3 & 6) == 0) {
      iVar6 = 0;
      if ((int)*param_3 < (int)param_2[3]) goto LAB_10024cb2;
LAB_10024c2c:
      cVar1 = *(char *)((int)param_2 + 0x43);
      goto joined_r0x10024c36;
    }
    uVar4 = (uint)(cVar1 != '\0');
  }
  iVar6 = (*param_5)(param_1,param_4,(int)param_2 + 0x43,uVar4);
  if (iVar6 == -1) {
    return 0xffffffff;
  }
  uVar4 = param_2[2];
  uVar3 = param_2[4];
  if ((*param_2 & 6) == 4) {
    uVar5 = param_2[3] - *param_3;
    uVar7 = (int)~uVar5 >> 0x1f & uVar5;
    if ((int)uVar4 <= (int)uVar3) {
      if ((int)uVar5 < 1) {
        return 0;
      }
      goto LAB_10024c76;
    }
  }
  else {
    if ((int)uVar4 <= (int)uVar3) {
      return 0;
    }
    uVar7 = 0;
  }
  uVar7 = uVar7 + (uVar4 - uVar3);
LAB_10024c76:
  iVar6 = 0;
  do {
    iVar2 = (*param_5)(param_1,param_4,(int)param_2 + 0x1a,1);
    if (iVar2 == -1) {
      return 0xffffffff;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < (int)uVar7);
  return 0;
}



/* FUN_10024d10 at 10024d10 */

/* WARNING: Removing unreachable block (ram,0x10024f3a) */

uint FUN_10024d10(undefined4 param_1,uint *param_2,undefined4 param_3,code *param_4,int *param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  int extraout_r2;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  bool bVar11;
  undefined8 uVar12;
  char *local_3c;
  uint local_34;
  uint local_2c [2];
  
  pcVar10 = (char *)((int)param_2 + 0x43);
  cVar1 = (char)param_2[6];
  pcVar9 = pcVar10;
  if (cVar1 == '\0') goto LAB_10024d4e;
  switch(cVar1) {
  case 'S':
  case 's':
    puVar6 = (undefined4 *)*param_5;
    *param_5 = (int)(puVar6 + 1);
    pcVar9 = (char *)*puVar6;
    iVar2 = FUN_10026614(pcVar9,0,param_2[1]);
    if (iVar2 == 0) {
      uVar4 = param_2[1];
    }
    else {
      uVar4 = iVar2 - (int)pcVar9;
      param_2[1] = uVar4;
    }
    break;
  default:
    uVar4 = 1;
    pcVar9 = (char *)((int)param_2 + 0x42);
    *(char *)((int)param_2 + 0x42) = cVar1;
    break;
  case 'X':
    *(undefined1 *)((int)param_2 + 0x45) = 0x58;
    uVar4 = *param_2;
    local_3c = "0123456789ABCDEF";
    puVar5 = (uint *)*param_5;
    if (-1 < (int)(uVar4 << 0x18)) goto LAB_10024e6a;
    goto LAB_10024efa;
  case 'c':
    puVar6 = (undefined4 *)*param_5;
    *param_5 = (int)(puVar6 + 1);
    uVar4 = 1;
    pcVar9 = (char *)((int)param_2 + 0x42);
    *(char *)((int)param_2 + 0x42) = (char)*puVar6;
    break;
  case 'd':
  case 'i':
    uVar4 = *param_2;
    puVar5 = (uint *)*param_5;
    if ((int)(uVar4 << 0x18) < 0) {
LAB_10024f7c:
      *param_5 = (int)(puVar5 + 1);
      uVar7 = *puVar5;
LAB_10024f82:
      uVar8 = (int)uVar7 >> 0x1f;
    }
    else {
      if ((int)(uVar4 << 0x19) < 0) {
        *param_5 = (int)(puVar5 + 1);
        uVar7 = (uint)(short)*puVar5;
        goto LAB_10024f82;
      }
      if ((int)(uVar4 << 0x16) < 0) {
        uVar7 = *puVar5;
        *param_5 = (int)(puVar5 + 1);
        uVar7 = (uint)(char)uVar7;
        goto LAB_10024f82;
      }
      if (-1 < (int)(uVar4 << 0x14)) goto LAB_10024f7c;
      puVar5 = (uint *)((uint)((int)puVar5 + 7) & 0xfffffff8);
      *param_5 = (int)(puVar5 + 2);
      uVar8 = puVar5[1];
      uVar7 = *puVar5;
    }
    if (-1 < (int)uVar8) {
      local_3c = "0123456789ABCDEF";
      local_34 = 10;
      goto LAB_10024e98;
    }
    *(undefined1 *)((int)param_2 + 0x43) = 0x2d;
    param_2[2] = param_2[1];
    if (-1 < (int)param_2[1]) {
      *param_2 = uVar4 & 0xfffffffb;
    }
    bVar11 = uVar7 != 0;
    uVar7 = -uVar7;
    uVar8 = -(uint)bVar11 - uVar8;
    local_3c = "0123456789ABCDEF";
    local_34 = 10;
    goto LAB_10024f0c;
  case 'n':
    puVar6 = (undefined4 *)*param_5;
    uVar7 = *param_2;
    uVar4 = param_2[5];
    *param_5 = (int)(puVar6 + 1);
    if ((int)(uVar7 << 0x18) < 0) {
LAB_10024d4a:
      *(uint *)*puVar6 = uVar4;
    }
    else if ((int)(uVar7 << 0x19) < 0) {
      *(short *)*puVar6 = (short)uVar4;
    }
    else {
      if (-1 < (int)(uVar7 << 0x16)) goto LAB_10024d4a;
      *(char *)*puVar6 = (char)uVar4;
    }
LAB_10024d4e:
    param_2[4] = 0;
    goto LAB_10024d54;
  case 'o':
  case 'u':
    uVar4 = *param_2;
    puVar5 = (uint *)*param_5;
    if ((int)(uVar4 << 0x18) < 0) {
LAB_10024f96:
      uVar8 = 0;
      *param_5 = (int)(puVar5 + 1);
      uVar7 = *puVar5;
    }
    else if ((int)(uVar4 << 0x19) < 0) {
      uVar8 = 0;
      uVar7 = (uint)(ushort)*puVar5;
      *param_5 = (int)(puVar5 + 1);
    }
    else if ((int)(uVar4 << 0x16) < 0) {
      uVar8 = 0;
      uVar7 = (uint)(byte)*puVar5;
      *param_5 = (int)(puVar5 + 1);
    }
    else {
      if (-1 < (int)(uVar4 << 0x14)) goto LAB_10024f96;
      puVar5 = (uint *)((uint)((int)puVar5 + 7) & 0xfffffff8);
      uVar7 = *puVar5;
      uVar8 = puVar5[1];
      *param_5 = (int)(puVar5 + 2);
    }
    local_3c = "0123456789ABCDEF";
    if (cVar1 == 'o') {
      local_34 = 8;
    }
    else {
      local_34 = 10;
    }
    goto LAB_10024e92;
  case 'p':
    uVar4 = *param_2 | 0x20;
    *param_2 = uVar4;
    goto LAB_10024e5a;
  case 'x':
    uVar4 = *param_2;
LAB_10024e5a:
    *(undefined1 *)((int)param_2 + 0x45) = 0x78;
    local_3c = "0123456789abcdef";
    puVar5 = (uint *)*param_5;
    if ((int)(uVar4 << 0x18) < 0) {
LAB_10024efa:
      *param_5 = (int)(puVar5 + 1);
      uVar8 = 0;
      uVar7 = *puVar5;
    }
    else {
LAB_10024e6a:
      if ((int)(uVar4 << 0x19) < 0) {
        uVar8 = 0;
        uVar7 = (uint)(ushort)*puVar5;
        *param_5 = (int)(puVar5 + 1);
      }
      else if ((int)(uVar4 << 0x16) < 0) {
        uVar8 = 0;
        uVar7 = (uint)(byte)*puVar5;
        *param_5 = (int)(puVar5 + 1);
      }
      else {
        if (-1 < (int)(uVar4 << 0x14)) goto LAB_10024efa;
        puVar5 = (uint *)((uint)((int)puVar5 + 7) & 0xfffffff8);
        uVar7 = *puVar5;
        uVar8 = puVar5[1];
        *param_5 = (int)(puVar5 + 2);
      }
    }
    if ((int)(uVar4 << 0x1f) < 0) {
      *param_2 = uVar4 | 0x20;
    }
    if (uVar7 == 0 && uVar8 == 0) {
      *param_2 = *param_2 & 0xffffffdf;
    }
    local_34 = 0x10;
LAB_10024e92:
    *(undefined1 *)((int)param_2 + 0x43) = 0;
LAB_10024e98:
    uVar4 = param_2[1];
    param_2[2] = uVar4;
    if (((int)uVar4 < 0) || (*param_2 = *param_2 & 0xfffffffb, uVar7 != 0 || uVar8 != 0)) {
LAB_10024f0c:
      uVar12 = CONCAT44(uVar8,uVar7);
      do {
        do {
          iVar2 = (int)((ulonglong)uVar12 >> 0x20);
          uVar4 = (uint)uVar12;
          uVar12 = FUN_1001e54c(uVar4,iVar2,local_34,0);
          pcVar9 = pcVar9 + -1;
          *pcVar9 = local_3c[extraout_r2];
        } while (iVar2 != 0);
      } while (local_34 <= uVar4);
    }
    else if (uVar4 != 0) {
      pcVar9 = (char *)((int)param_2 + 0x42);
      *pcVar9 = *local_3c;
    }
    if (((local_34 == 8) && ((int)(*param_2 << 0x1f) < 0)) && ((int)param_2[1] <= (int)param_2[4]))
    {
      pcVar9 = pcVar9 + -1;
      *pcVar9 = '0';
    }
    param_2[4] = (int)pcVar10 - (int)pcVar9;
    goto LAB_10024d54;
  }
  param_2[4] = uVar4;
  *(undefined1 *)((int)param_2 + 0x43) = 0;
LAB_10024d54:
  iVar2 = FUN_10024bcc(param_1,param_2,local_2c,param_3,param_4);
  if ((iVar2 == -1) || (iVar2 = (*param_4)(param_1,param_3,pcVar9,param_2[4]), iVar2 == -1)) {
LAB_10024db2:
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = param_2[3];
    if (((int)(*param_2 << 0x1e) < 0) && ((int)local_2c[0] < (int)uVar4)) {
      iVar2 = 0;
      do {
        iVar3 = (*param_4)(param_1,param_3,(int)param_2 + 0x19,1);
        if (iVar3 == -1) goto LAB_10024db2;
        uVar4 = param_2[3];
        iVar2 = iVar2 + 1;
      } while (iVar2 < (int)(uVar4 - local_2c[0]));
    }
    if ((int)uVar4 < (int)local_2c[0]) {
      uVar4 = local_2c[0];
    }
  }
  return uVar4;
}



/* FUN_10025050 at 10025050 */

void FUN_10025050(void)

{
  FUN_100274fc(0x20001000);
  return;
}



/* FUN_10025060 at 10025060 */

void FUN_10025060(void)

{
  FUN_1002751c(0x20001000);
  return;
}



/* FUN_100250b4 at 100250b4 */

undefined1 FUN_100250b4(void)

{
  return DAT_20000f78;
}



/* FUN_10025110 at 10025110 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10025110(undefined4 param_1)

{
  FUN_10027148(param_1,0);
  if (_DAT_20001028 != (code *)0x0) {
    (*_DAT_20001028)();
  }
                    /* WARNING: Subroutine does not return */
  FUN_100275a6(param_1);
}



/* FUN_10025130 at 10025130 */

void FUN_10025130(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  uint uVar8;
  bool bVar9;
  
  if ((param_2 < param_1) && (param_1 < (undefined4 *)((int)param_2 + param_3))) {
    while (param_3 != 0) {
      param_3 = param_3 - 1;
      *(undefined1 *)((int)param_1 + param_3) = *(undefined1 *)((int)param_2 + param_3);
    }
    return;
  }
  if (param_3 < 0x10) {
    puVar1 = param_2;
    uVar3 = param_3;
    puVar5 = param_1;
  }
  else {
    if ((((uint)param_1 | (uint)param_2) & 3) != 0) goto LAB_10025164;
    uVar8 = param_3 - 0x10 & 0xfffffff0;
    puVar5 = (undefined4 *)((int)param_1 + uVar8) + 4;
    puVar1 = param_1;
    puVar2 = param_2;
    do {
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
      puVar7 = puVar2 + 3;
      puVar2 = puVar2 + 4;
      puVar1[3] = *puVar7;
      bVar9 = puVar1 != (undefined4 *)((int)param_1 + uVar8);
      puVar1 = puVar1 + 4;
    } while (bVar9);
    puVar1 = (undefined4 *)((int)param_2 + uVar8 + 0x10);
    uVar3 = param_3 & 0xf;
    if ((param_3 & 0xc) != 0) {
      uVar3 = uVar3 - 4 & 0xfffffffc;
      puVar2 = puVar1;
      do {
        uVar6 = *puVar2;
        puVar7 = (undefined4 *)((int)puVar2 + ((int)param_1 - (int)param_2));
        puVar2 = puVar2 + 1;
        *puVar7 = uVar6;
      } while (puVar2 != (undefined4 *)((int)param_2 + uVar3 + uVar8 + 0x14));
      iVar4 = uVar3 + 4;
      puVar1 = (undefined4 *)(iVar4 + (int)puVar1);
      puVar5 = (undefined4 *)(iVar4 + (int)puVar5);
      uVar3 = param_3 & 3;
    }
  }
  param_2 = puVar1;
  param_1 = puVar5;
  param_3 = uVar3;
  if (uVar3 == 0) {
    return;
  }
LAB_10025164:
  iVar4 = 0;
  do {
    *(undefined1 *)((int)param_1 + iVar4) = *(undefined1 *)((int)param_2 + iVar4);
    bVar9 = param_3 - 1 != iVar4;
    iVar4 = iVar4 + 1;
  } while (bVar9);
  return;
}



/* FUN_100251f4 at 100251f4 */

undefined4 FUN_100251f4(undefined4 *param_1,byte *param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  
  pbVar2 = (byte *)*param_1;
  do {
    bVar1 = *param_2;
    pbVar2 = pbVar2 + 1;
    if (bVar1 == 0) {
      *param_1 = pbVar2;
      return 1;
    }
    uVar3 = (uint)*pbVar2;
    if (uVar3 - 0x41 < 0x1a) {
      uVar3 = uVar3 + 0x20;
    }
    param_2 = param_2 + 1;
  } while (uVar3 == bVar1);
  return 0;
}



/* FUN_10025220 at 10025220 */

undefined4 FUN_10025220(int *param_1,uint *param_2,uint *param_3)

{
  byte bVar1;
  uint uVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  
  uVar2 = *param_2;
  puVar6 = param_3 + ((int)uVar2 >> 5);
  if ((uVar2 & 0x1f) == 0) {
    puVar12 = puVar6 + -1;
    puVar3 = puVar6;
  }
  else {
    puVar3 = puVar6 + 1;
    puVar12 = puVar6;
  }
  puVar3 = puVar3 + -1;
  *puVar3 = 0;
  iVar4 = *param_1;
  uVar10 = (uint)*(byte *)(iVar4 + 1);
  if (uVar10 != 0) {
    iVar7 = 0;
    iVar11 = 0;
    iVar13 = 0;
    puVar6 = puVar12;
    puVar9 = puVar12;
    do {
      while (bVar1 = (&DAT_1002af20)[uVar10], bVar1 == 0) {
        if (0x20 < uVar10) {
          if (uVar10 != 0x29) {
            return 4;
          }
          *param_1 = iVar4 + 2;
          goto LAB_100252ec;
        }
        if (iVar13 < iVar7) {
          if ((puVar9 < puVar6) && (iVar11 < 8)) {
            uVar10 = *puVar9;
            puVar5 = puVar9;
            do {
              uVar8 = puVar5[1] << ((8 - iVar11) * -4 + 0x20U & 0xff) | uVar10;
              uVar10 = puVar5[1] >> ((8 - iVar11) * 4 & 0xffU);
              *puVar5 = uVar8;
              puVar5[1] = uVar10;
              puVar5 = puVar5 + 1;
            } while (puVar5 < puVar6);
          }
          iVar11 = 8;
          if (param_3 < puVar9) {
            puVar6 = puVar9 + -1;
            iVar11 = 0;
            *puVar6 = 0;
            puVar9 = puVar6;
            iVar13 = iVar7;
          }
        }
LAB_100252b2:
        uVar10 = (uint)*(byte *)(iVar4 + 2);
        iVar4 = iVar4 + 1;
        if (uVar10 == 0) goto LAB_100252ec;
      }
      iVar11 = iVar11 + 1;
      iVar7 = iVar7 + 1;
      if (iVar11 < 9) {
        uVar10 = *puVar9 << 4;
      }
      else {
        if (puVar9 <= param_3) goto LAB_100252b2;
        puVar9 = puVar9 + -1;
        uVar10 = 0;
        iVar11 = 1;
        *puVar9 = 0;
      }
      *puVar9 = bVar1 & 0xf | uVar10;
      uVar10 = (uint)*(byte *)(iVar4 + 2);
      iVar4 = iVar4 + 1;
    } while (uVar10 != 0);
LAB_100252ec:
    if (iVar7 != 0) {
      if ((puVar9 < puVar6) && (iVar11 < 8)) {
        uVar10 = *puVar9;
        puVar5 = puVar9;
        do {
          uVar8 = puVar5[1] << ((8 - iVar11) * -4 + 0x20U & 0xff) | uVar10;
          uVar10 = puVar5[1] >> ((8 - iVar11) * 4 & 0xffU);
          *puVar5 = uVar8;
          puVar5[1] = uVar10;
          puVar5 = puVar5 + 1;
        } while (puVar5 < puVar6);
      }
      if (param_3 < puVar9) {
        puVar6 = param_3;
        puVar5 = puVar9;
        do {
          uVar2 = *puVar5;
          puVar5 = puVar5 + 1;
          *puVar6 = uVar2;
          puVar6 = puVar6 + 1;
        } while (puVar5 <= puVar12);
        uVar2 = 0;
        if ((int)puVar9 + 1U <= (int)puVar12 + 1U) {
          uVar2 = (int)puVar12 - (int)puVar9 & 0xfffffffc;
        }
        puVar6 = (uint *)((int)param_3 + uVar2 + 4);
        do {
          puVar9 = puVar6 + 1;
          *puVar6 = 0;
          puVar6 = puVar9;
        } while (puVar9 <= puVar12);
        uVar10 = *puVar3;
      }
      else {
        uVar10 = *puVar3;
        if ((uVar2 & 0x1f) != 0) {
          uVar10 = uVar10 & 0xffffffffU >> (0x20 - (uVar2 & 0x1f) & 0xff);
          *puVar3 = uVar10;
        }
      }
      while( true ) {
        if (uVar10 != 0) {
          return 5;
        }
        if (param_3 == puVar12) break;
        puVar12 = puVar12 + -1;
        uVar10 = *puVar12;
      }
      *param_3 = 1;
      return 5;
    }
  }
  return 4;
}



/* FUN_10025428 at 10025428 */

int FUN_10025428(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = param_3[2] + -1;
  param_3[2] = iVar1;
  if ((iVar1 < 0) && ((iVar1 < (int)param_3[6] || (param_2 == 10)))) {
    param_2 = FUN_10025854();
  }
  else {
    puVar2 = (undefined1 *)*param_3;
    *param_3 = puVar2 + 1;
    *puVar2 = (char)param_2;
  }
  return param_2;
}



/* FUN_10025450 at 10025450 */

undefined4 FUN_10025450(undefined4 param_1,int param_2,undefined4 *param_3,uint param_4)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (*(int *)(param_2 + 0x68) << 0x12 < 0) {
    if (param_4 >> 2 != 0) {
      puVar2 = param_3 + (param_4 >> 2);
      do {
        iVar1 = FUN_10026d00(param_1,*param_3,param_2);
        if (iVar1 == -1) {
          return 0xffffffff;
        }
        param_3 = param_3 + 1;
      } while (param_3 != puVar2);
    }
  }
  else {
    puVar2 = (undefined4 *)((int)param_3 + param_4);
    if (param_4 != 0) {
      do {
        iVar1 = FUN_10025428(param_1,*(undefined1 *)param_3,param_2);
        if (iVar1 == -1) {
          return 0xffffffff;
        }
        param_3 = (undefined4 *)((int)param_3 + 1);
      } while (param_3 != puVar2);
    }
  }
  return 0;
}



/* FUN_100254a8 at 100254a8 */

int FUN_100254a8(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar4 = param_3[2];
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  else {
    if (*(int *)(param_2 + 0x68) << 0x12 < 0) {
      piVar1 = (int *)*param_3;
      do {
        iVar2 = *piVar1;
        uVar3 = piVar1[1];
        uVar6 = uVar3 >> 2;
        if (uVar6 != 0) {
          uVar5 = 0;
          do {
            iVar4 = FUN_10026d00(param_1,*(undefined4 *)(iVar2 + uVar5 * 4),param_2);
            if (iVar4 == -1) goto LAB_100254f8;
            uVar5 = uVar5 + 1;
          } while (uVar6 != uVar5);
          iVar4 = param_3[2];
        }
        iVar4 = iVar4 - (uVar3 & 0xfffffffc);
        param_3[2] = iVar4;
        piVar1 = piVar1 + 2;
      } while (iVar4 != 0);
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_1002695c(param_1,param_2,param_3);
    }
LAB_100254f8:
    param_3[2] = 0;
  }
  param_3[1] = 0;
  return iVar4;
}



/* FUN_1002553c at 1002553c */

/* WARNING: Removing unreachable block (ram,0x100256b6) */

int FUN_1002553c(int param_1,int param_2,byte *param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  int *local_8c;
  uint local_88;
  int local_84;
  undefined4 local_80;
  int local_7c;
  int local_74;
  byte local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined1 uStack_45;
  undefined4 local_30;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x20) == 0)) {
    FUN_10021cfc();
  }
  iVar4 = (int)*(short *)(param_2 + 0xc);
  if ((-1 < *(int *)(param_2 + 0x68) << 0x1f) && (-1 < iVar4 << 0x16)) {
    FUN_100274fc(param_2 + 0x58);
    iVar4 = (int)*(short *)(param_2 + 0xc);
  }
  if (((-1 < iVar4 << 0x1c) || (*(int *)(param_2 + 0x10) == 0)) &&
     (iVar4 = FUN_10026d84(param_1,param_2), iVar4 != 0)) {
    if (*(int *)(param_2 + 0x68) << 0x1f < 0) {
      return -1;
    }
    if ((int)((uint)*(ushort *)(param_2 + 0xc) << 0x16) < 0) {
      return -1;
    }
    FUN_1002751c(param_2 + 0x58);
    return -1;
  }
  local_74 = 0;
  local_6f = 0x20;
  local_6e = 0x30;
  bVar3 = *param_3;
  local_8c = param_4;
  while (bVar3 != 0) {
    pbVar6 = param_3;
    do {
      if (bVar3 == 0x25) {
        iVar4 = (int)pbVar6 - (int)param_3;
        if (pbVar6 != param_3) goto LAB_1002573a;
        goto LAB_100255b8;
      }
      bVar3 = pbVar6[1];
      pbVar6 = pbVar6 + 1;
    } while (bVar3 != 0);
    iVar4 = (int)pbVar6 - (int)param_3;
    if (pbVar6 == param_3) break;
LAB_1002573a:
    iVar1 = FUN_10025450(param_1,param_2,param_3,iVar4);
    if (iVar1 == -1) break;
    local_74 = local_74 + iVar4;
LAB_100255b8:
    if (*pbVar6 == 0) break;
    local_88 = 0;
    local_84 = -1;
    local_80 = 0;
    local_7c = 0;
    uStack_45 = 0;
    local_30 = 0;
    pbVar6 = pbVar6 + 1;
    while( true ) {
      iVar4 = FUN_10026614("#-0+ ",*pbVar6,5);
      if (iVar4 == 0) break;
      local_88 = 1 << (iVar4 + 0xeffd5328U & 0xff) | local_88;
      pbVar6 = pbVar6 + 1;
    }
    if ((int)(local_88 << 0x1b) < 0) {
      uStack_45 = 0x20;
    }
    if ((int)(local_88 << 0x1c) < 0) {
      uStack_45 = 0x2b;
    }
    uVar5 = (uint)*pbVar6;
    if (uVar5 == 0x2a) {
      local_7c = *local_8c;
      if (local_7c < 0) {
        local_7c = -local_7c;
        local_88 = local_88 | 2;
      }
      uVar5 = (uint)pbVar6[1];
      pbVar6 = pbVar6 + 1;
      local_8c = local_8c + 1;
    }
    else {
      uVar2 = uVar5 - 0x30;
      if (uVar2 < 10) {
        do {
          local_7c = local_7c * 10 + uVar2;
          uVar5 = (uint)pbVar6[1];
          pbVar6 = pbVar6 + 1;
          uVar2 = uVar5 - 0x30;
        } while (uVar2 < 10);
      }
    }
    param_3 = pbVar6;
    if (uVar5 == 0x2e) {
      if (pbVar6[1] == 0x2a) {
        param_3 = pbVar6 + 2;
        local_84 = *local_8c;
        if (local_84 < 0) {
          local_84 = -1;
        }
        uVar5 = (uint)pbVar6[2];
        local_8c = local_8c + 1;
      }
      else {
        local_84 = 0;
        uVar5 = (uint)pbVar6[1];
        param_3 = pbVar6 + 1;
        uVar2 = uVar5 - 0x30;
        if (uVar2 < 10) {
          local_84 = 0;
          do {
            local_84 = local_84 * 10 + uVar2;
            uVar5 = (uint)param_3[1];
            param_3 = param_3 + 1;
            uVar2 = uVar5 - 0x30;
          } while (uVar2 < 10);
        }
      }
    }
    iVar4 = FUN_10026614(&DAT_1002ace0,uVar5,3);
    if (iVar4 != 0) {
      local_88 = local_88 | 0x40 << (iVar4 + 0xeffd5320U & 0xff);
      param_3 = param_3 + 1;
    }
    local_70 = *param_3;
    if (((local_88 & 0x80) != 0) && (local_70 == 0x6c)) {
      local_88 = local_88 & 0xffffff7f | 0x800;
      local_70 = param_3[1];
      param_3 = param_3 + 1;
    }
    if (((local_88 & 0x40) != 0) && (local_70 == 0x68)) {
      local_88 = local_88 & 0xffffffbf | 0x200;
      local_70 = param_3[1];
      param_3 = param_3 + 1;
    }
    if ((local_70 == 0x7a) || (local_70 == 0x74)) {
      local_70 = param_3[1];
      param_3 = param_3 + 1;
    }
    if (local_70 == 0x6a) {
      local_88 = local_88 | 0x800;
      local_70 = param_3[1];
      param_3 = param_3 + 1;
    }
    param_3 = param_3 + 1;
    iVar4 = FUN_10026614("efgEFG",local_70,6);
    if (iVar4 == 0) {
      iVar4 = FUN_10024d10(param_1,&local_88,param_2,0x10025451,&local_8c);
    }
    else {
      iVar4 = FUN_10022000(param_1,&local_88,param_2,0x10025451,&local_8c);
    }
    if (iVar4 == -1) break;
    local_74 = local_74 + iVar4;
    bVar3 = *param_3;
  }
  if (-1 < *(int *)(param_2 + 0x68) << 0x1f) {
    uVar5 = (uint)*(ushort *)(param_2 + 0xc);
    if ((int)(uVar5 << 0x16) < 0) goto LAB_100256ec;
    FUN_1002751c(param_2 + 0x58);
  }
  uVar5 = (uint)*(ushort *)(param_2 + 0xc);
LAB_100256ec:
  if ((int)(uVar5 << 0x19) < 0) {
    return -1;
  }
  return local_74;
}



/* FUN_10025854 at 10025854 */

uint FUN_10025854(int param_1,byte param_2,undefined4 *param_3,undefined4 param_4)

{
  ushort uVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x20) == 0)) {
    FUN_10021cfc();
  }
  param_3[2] = param_3[6];
  uVar1 = *(ushort *)(param_3 + 3);
  uVar2 = (uint)(short)uVar1;
  iVar4 = uVar2 << 0x1c;
  if (iVar4 < 0) {
    iVar5 = param_3[4];
    iVar4 = 0;
    if (iVar5 == 0) goto LAB_100258b2;
    if ((uVar2 & 0x2000) != 0) goto LAB_10025886;
LAB_100258d2:
    *(ushort *)(param_3 + 3) = uVar1 | 0x2000;
    param_3[0x1a] = param_3[0x1a] & 0xffffdfff;
    pbVar3 = (byte *)*param_3;
    iVar5 = (int)pbVar3 - iVar5;
    if (iVar5 < (int)param_3[5]) {
LAB_10025890:
      iVar5 = iVar5 + 1;
      goto LAB_10025892;
    }
  }
  else {
LAB_100258b2:
    iVar4 = FUN_10026d84(param_1,param_3,uVar2,iVar4,param_4);
    if (iVar4 != 0) {
      return 0xffffffff;
    }
    uVar1 = *(ushort *)(param_3 + 3);
    iVar5 = param_3[4];
    if ((uVar1 & 0x2000) == 0) goto LAB_100258d2;
LAB_10025886:
    pbVar3 = (byte *)*param_3;
    iVar5 = (int)pbVar3 - iVar5;
    if (iVar5 < (int)param_3[5]) goto LAB_10025890;
  }
  iVar4 = FUN_10027044(param_1,param_3);
  if (iVar4 != 0) {
    return 0xffffffff;
  }
  iVar5 = 1;
  pbVar3 = (byte *)*param_3;
LAB_10025892:
  uVar2 = (uint)param_2;
  param_3[2] = param_3[2] + -1;
  *param_3 = pbVar3 + 1;
  *pbVar3 = param_2;
  if (param_3[5] != iVar5) {
    if (-1 < (int)((uint)*(ushort *)(param_3 + 3) << 0x1f)) {
      return uVar2;
    }
    if (uVar2 != 10) {
      return uVar2;
    }
  }
  iVar4 = FUN_10027044(param_1,param_3);
  if (iVar4 == 0) {
    return uVar2;
  }
  return 0xffffffff;
}



/* FUN_1002592c at 1002592c */

undefined8 FUN_1002592c(void)

{
  return 0x7ff8000000000000;
}



/* FUN_10025938 at 10025938 */

undefined4 FUN_10025938(void)

{
  return 0x7fc00000;
}



/* FUN_1002597c at 1002597c */

void FUN_1002597c(undefined1 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 *local_88 [2];
  undefined4 local_80;
  undefined4 local_7c;
  undefined1 *local_78;
  undefined4 local_74;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  local_80 = 0x7fffffff;
  local_74 = 0x7fffffff;
  local_7c = 0xffff0208;
  local_88[0] = param_1;
  local_78 = param_1;
  uStack_8 = param_3;
  uStack_4 = param_4;
  uVar1 = FUN_1001c744();
  FUN_10021078(uVar1,local_88,param_2,&uStack_8);
  *local_88[0] = 0;
  return;
}



/* FUN_100259c0 at 100259c0 */

int FUN_100259c0(int param_1,uint param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(param_1 + 0x1c);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)FUN_1001c78c(0x10);
    *(undefined4 **)(param_1 + 0x1c) = puVar5;
    if (puVar5 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/mprec.c",0x6b,0,"REENT malloc succeeded"
                  );
    }
    puVar5[1] = 0;
    puVar5[2] = 0;
    *puVar5 = 0;
    puVar5[3] = 0;
LAB_100259fe:
    uVar2 = FUN_10021da4(param_1,4,0x21);
    iVar3 = *(int *)(param_1 + 0x1c);
    puVar5[3] = uVar2;
    iVar3 = *(int *)(iVar3 + 0xc);
    if (iVar3 != 0) goto LAB_100259d2;
LAB_10025a12:
    piVar1 = (int *)0x0;
  }
  else {
    iVar3 = puVar5[3];
    if (iVar3 == 0) goto LAB_100259fe;
LAB_100259d2:
    piVar4 = (int *)(iVar3 + param_2 * 4);
    piVar1 = (int *)*piVar4;
    if (piVar1 == (int *)0x0) {
      iVar3 = 1 << (param_2 & 0xff);
      piVar1 = (int *)FUN_10021da4(param_1,1,(iVar3 + 5) * 4);
      if (piVar1 == (int *)0x0) goto LAB_10025a12;
      *(uint *)((int)piVar1 + 4) = param_2;
      *(int *)((int)piVar1 + 8) = iVar3;
    }
    else {
      *piVar4 = *piVar1;
    }
    *(undefined4 *)((int)piVar1 + 0x10) = 0;
    *(undefined4 *)((int)piVar1 + 0xc) = 0;
  }
  return (int)piVar1;
}



/* FUN_10025a44 at 10025a44 */

void FUN_10025a44(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  
  if (*(int *)(param_1 + 0x1c) == 0) {
    puVar1 = (undefined4 *)FUN_1001c78c(0x10);
    *(undefined4 **)(param_1 + 0x1c) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/mprec.c",0x8f,0,"REENT malloc succeeded"
                  );
    }
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
  }
  if (param_2 != (int *)0x0) {
    piVar2 = (int *)(*(int *)(*(int *)(param_1 + 0x1c) + 0xc) + param_2[1] * 4);
    *param_2 = *piVar2;
    *piVar2 = (int)param_2;
  }
  return;
}



/* FUN_10025a90 at 10025a90 */

int FUN_10025a90(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar3 = 0;
  iVar5 = *(int *)(param_2 + 0x10);
  puVar2 = (uint *)(param_2 + 0x14);
  do {
    iVar3 = iVar3 + 1;
    uVar1 = param_3 * (*puVar2 & 0xffff) + param_4;
    uVar4 = param_3 * (*puVar2 >> 0x10) + (uVar1 >> 0x10);
    param_4 = uVar4 >> 0x10;
    *puVar2 = uVar4 * 0x10000 + (uVar1 & 0xffff);
    puVar2 = puVar2 + 1;
  } while (iVar3 < iVar5);
  iVar3 = param_2;
  if (param_4 != 0) {
    if (iVar5 < *(int *)(param_2 + 8)) {
      *(uint *)(param_2 + iVar5 * 4 + 0x14) = param_4;
      *(int *)(param_2 + 0x10) = iVar5 + 1;
    }
    else {
      iVar3 = FUN_100259c0(param_1,*(int *)(param_2 + 4) + 1);
      if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/mprec.c",0xba,0,"Balloc succeeded");
      }
      FUN_1001f4d4(iVar3 + 0xc,param_2 + 0xc,(*(int *)(param_2 + 0x10) + 2) * 4);
      FUN_10025a44(param_1,param_2);
      *(uint *)(iVar3 + iVar5 * 4 + 0x14) = param_4;
      *(int *)(iVar3 + 0x10) = iVar5 + 1;
    }
  }
  return iVar3;
}



/* FUN_10025b2c at 10025b2c */

int FUN_10025b2c(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  byte *pbVar5;
  
  iVar1 = FUN_1001e480(param_4 + 8,9);
  if (param_4 < 10) {
    iVar2 = 0;
  }
  else {
    iVar4 = 1;
    iVar2 = 0;
    do {
      iVar4 = iVar4 * 2;
      iVar2 = iVar2 + 1;
    } while (iVar4 < iVar1);
  }
  iVar1 = FUN_100259c0(param_1,iVar2);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/mprec.c",0xd3,0,"Balloc succeeded");
  }
  *(undefined4 *)(iVar1 + 0x14) = param_5;
  *(undefined4 *)(iVar1 + 0x10) = 1;
  if (param_3 < 10) {
    param_3 = 9;
    pbVar3 = (byte *)(param_2 + 10);
  }
  else {
    pbVar3 = (byte *)(param_2 + 9);
    do {
      iVar1 = FUN_10025a90(param_1,iVar1,10,*pbVar3 - 0x30);
      pbVar3 = pbVar3 + 1;
    } while (pbVar3 != (byte *)(param_2 + param_3));
    pbVar3 = (byte *)(param_2 + 9) + param_3 + -8;
  }
  if (param_3 < param_4) {
    pbVar5 = pbVar3 + (param_4 - param_3);
    do {
      iVar1 = FUN_10025a90(param_1,iVar1,10,*pbVar3 - 0x30);
      pbVar3 = pbVar3 + 1;
    } while (pbVar3 != pbVar5);
  }
  return iVar1;
}



/* FUN_10025bdc at 10025bdc */

int FUN_10025bdc(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  if (param_1 < 0x10000) {
    param_1 = param_1 << 0x10;
    iVar1 = 0x10;
  }
  if (param_1 < 0x1000000) {
    iVar1 = iVar1 + 8;
    param_1 = param_1 << 8;
  }
  if (param_1 < 0x10000000) {
    iVar1 = iVar1 + 4;
    uVar2 = param_1 << 4;
    if (0x3fffffff < uVar2) goto LAB_10025c1c;
    if ((int)(param_1 << 6) < 0) goto LAB_10025c36;
    if ((param_1 & 0x1000000) == 0) {
      return 0x20;
    }
  }
  else {
    if (0x3fffffff < param_1) {
      uVar2 = param_1;
LAB_10025c1c:
      return iVar1 - ((int)~uVar2 >> 0x1f);
    }
    if ((int)(param_1 << 2) < 0) {
LAB_10025c36:
      return iVar1 + 2;
    }
  }
  return iVar1 + 3;
}



/* FUN_10025c3c at 10025c3c */

int FUN_10025c3c(uint *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *param_1;
  if ((uVar2 & 7) != 0) {
    if ((int)(uVar2 << 0x1f) < 0) {
      return 0;
    }
    if ((int)(uVar2 << 0x1e) < 0) {
      *param_1 = uVar2 >> 1;
      return 1;
    }
    *param_1 = uVar2 >> 2;
    return 2;
  }
  if ((uVar2 & 0xffff) == 0) {
    uVar3 = uVar2 >> 0x10;
    iVar1 = 0x10;
    if ((uVar3 & 0xff) == 0) {
      iVar1 = 0x18;
      uVar3 = uVar2 >> 0x18;
    }
LAB_10025c68:
    if ((uVar3 & 0xf) != 0) goto joined_r0x10025c8c;
    iVar1 = iVar1 + 4;
    uVar2 = uVar3;
  }
  else {
    if ((uVar2 & 0xff) == 0) {
      iVar1 = 8;
      uVar3 = uVar2 >> 8;
      goto LAB_10025c68;
    }
    if ((uVar2 & 0xf) != 0) {
      *param_1 = uVar2 >> 3;
      return 3;
    }
    iVar1 = 4;
  }
  uVar3 = uVar2 >> 4;
joined_r0x10025c8c:
  if ((uVar3 & 3) == 0) {
    if ((int)(uVar3 << 0x1d) < 0) {
      iVar1 = iVar1 + 2;
      *param_1 = uVar3 >> 2;
    }
    else if (uVar3 >> 3 == 0) {
      iVar1 = 0x20;
    }
    else {
      iVar1 = iVar1 + 3;
      *param_1 = uVar3 >> 3;
    }
  }
  else {
    if (-1 < (int)(uVar3 << 0x1f)) {
      iVar1 = iVar1 + 1;
      uVar3 = uVar3 >> 1;
    }
    *param_1 = uVar3;
  }
  return iVar1;
}



/* FUN_10025ccc at 10025ccc */

void FUN_10025ccc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_100259c0(param_1,1);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/mprec.c",0x145,0,"Balloc succeeded");
  }
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  *(undefined4 *)(iVar1 + 0x10) = 1;
  return;
}



/* FUN_10025cf8 at 10025cf8 */

int FUN_10025cf8(undefined4 param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  uint *puVar12;
  uint uVar13;
  uint *puVar14;
  uint *puVar15;
  int iVar16;
  uint uVar17;
  uint *puVar18;
  
  iVar4 = *(int *)(param_2 + 0x10);
  iVar10 = *(int *)(param_3 + 0x10);
  iVar11 = iVar10;
  iVar16 = param_3;
  if (iVar10 <= iVar4) {
    iVar11 = iVar4;
    iVar4 = iVar10;
    iVar16 = param_2;
    param_2 = param_3;
  }
  iVar10 = *(int *)(iVar16 + 4);
  iVar8 = iVar11 + iVar4;
  if (*(int *)(iVar16 + 8) < iVar8) {
    iVar10 = iVar10 + 1;
  }
  iVar10 = FUN_100259c0(param_1,iVar10);
  if (iVar10 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/mprec.c",0x162,0,"Balloc succeeded");
  }
  puVar18 = (uint *)(iVar10 + 0x14);
  puVar7 = puVar18 + iVar8;
  for (puVar2 = puVar18; puVar2 < puVar7; puVar2 = puVar2 + 1) {
    *puVar2 = 0;
  }
  puVar5 = (uint *)(iVar16 + 0x14);
  puVar2 = (uint *)(param_2 + 0x14);
  puVar15 = puVar2 + iVar4;
  puVar12 = puVar5 + iVar11;
  if (puVar2 < puVar15) {
    uVar17 = 0;
    if ((uint *)(iVar16 + 0x15) <= puVar12) {
      uVar17 = (int)puVar12 + (-0x15 - iVar16) & 0xfffffffc;
    }
    do {
      while( true ) {
        uVar9 = *puVar2;
        if ((uVar9 & 0xffff) == 0) break;
        uVar13 = 0;
        puVar1 = puVar18;
        puVar14 = puVar5;
        do {
          uVar6 = *puVar14;
          puVar14 = puVar14 + 1;
          uVar3 = (uVar9 & 0xffff) * (uVar6 & 0xffff) + (*puVar1 & 0xffff) + uVar13;
          uVar6 = (uVar9 & 0xffff) * (uVar6 >> 0x10) + (*puVar1 >> 0x10) + (uVar3 >> 0x10);
          uVar13 = uVar6 >> 0x10;
          *puVar1 = uVar6 * 0x10000 | uVar3 & 0xffff;
          puVar1 = puVar1 + 1;
        } while (puVar14 < puVar12);
        *(uint *)((int)puVar18 + uVar17 + 4) = uVar13;
        uVar9 = *puVar2 >> 0x10;
        if (uVar9 == 0) goto LAB_10025d98;
LAB_10025dfe:
        uVar3 = *puVar18;
        uVar6 = 0;
        uVar13 = uVar3;
        puVar1 = puVar18;
        puVar14 = puVar5;
        do {
          uVar6 = uVar9 * (ushort)*puVar14 + uVar6 + (uVar3 >> 0x10);
          *puVar1 = uVar13 & 0xffff | uVar6 * 0x10000;
          uVar13 = *puVar14;
          puVar14 = puVar14 + 1;
          uVar3 = puVar1[1];
          uVar13 = uVar9 * (uVar13 >> 0x10) + (uVar3 & 0xffff) + (uVar6 >> 0x10);
          uVar6 = uVar13 >> 0x10;
          puVar1 = puVar1 + 1;
        } while (puVar14 < puVar12);
        puVar2 = puVar2 + 1;
        *(uint *)((int)puVar18 + uVar17 + 4) = uVar13;
        puVar18 = puVar18 + 1;
        if (puVar15 <= puVar2) goto LAB_10025e5c;
      }
      uVar9 = uVar9 >> 0x10;
      if (uVar9 != 0) goto LAB_10025dfe;
LAB_10025d98:
      puVar2 = puVar2 + 1;
      puVar18 = puVar18 + 1;
    } while (puVar2 < puVar15);
  }
LAB_10025e5c:
  if (0 < iVar8) {
    do {
      puVar7 = puVar7 + -1;
      if (*puVar7 != 0) break;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  *(int *)(iVar10 + 0x10) = iVar8;
  return iVar10;
}



/* FUN_10025ea8 at 10025ea8 */

undefined4 FUN_10025ea8(int param_1,undefined4 param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  if ((param_3 & 3) != 0) {
    param_2 = FUN_10025a90(param_1,param_2,*(undefined4 *)(&DAT_1002b2f8 + ((param_3 & 3) - 1) * 4),
                           0);
  }
  if ((int)param_3 >> 2 == 0) {
    return param_2;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)FUN_1001c78c(0x10);
    *(undefined4 **)(param_1 + 0x1c) = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/mprec.c",0x1b3,0,
                   "REENT malloc succeeded");
    }
    puVar1[1] = 0;
    puVar1[2] = 0;
    *puVar1 = 0;
    puVar1[3] = 0;
  }
  else {
    puVar4 = (undefined4 *)puVar1[2];
    if (puVar4 != (undefined4 *)0x0) goto LAB_10025ed4;
  }
  puVar4 = (undefined4 *)FUN_100259c0(param_1,1);
  if (puVar4 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/mprec.c",0x145,0,"Balloc succeeded");
  }
  puVar4[5] = 0x271;
  puVar4[4] = 1;
  puVar1[2] = puVar4;
  *puVar4 = 0;
LAB_10025ed4:
  uVar3 = (int)param_3 >> 3;
  uVar5 = param_2;
  if (((int)param_3 >> 2 & 1U) != 0) goto LAB_10025ef8;
  do {
    puVar1 = (undefined4 *)*puVar4;
    if (puVar1 == (undefined4 *)0x0) goto LAB_10025f18;
    while( true ) {
      uVar2 = uVar3 & 1;
      uVar3 = (int)uVar3 >> 1;
      puVar4 = puVar1;
      uVar5 = param_2;
      if (uVar2 == 0) break;
LAB_10025ef8:
      param_2 = FUN_10025cf8(param_1,uVar5,puVar4);
      FUN_10025a44(param_1,uVar5);
      if (uVar3 == 0) {
        return param_2;
      }
      puVar1 = (undefined4 *)*puVar4;
      if (puVar1 == (undefined4 *)0x0) {
LAB_10025f18:
        puVar1 = (undefined4 *)FUN_10025cf8(param_1,puVar4,puVar4);
        *puVar4 = puVar1;
        *puVar1 = 0;
      }
    }
  } while( true );
}



/* FUN_10025fb4 at 10025fb4 */

int FUN_10025fb4(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint *puVar10;
  uint *local_2c;
  
  iVar2 = (int)param_3 >> 5;
  iVar3 = *(int *)(param_2 + 0x10) + iVar2;
  iVar8 = iVar3 + 1;
  iVar1 = *(int *)(param_2 + 4);
  for (iVar4 = *(int *)(param_2 + 8); iVar4 < iVar8; iVar4 = iVar4 * 2) {
    iVar1 = iVar1 + 1;
  }
  iVar4 = FUN_100259c0(param_1,iVar1);
  if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/mprec.c",0x1de,0,"Balloc succeeded");
  }
  local_2c = (uint *)(iVar4 + 0x14);
  if (0 < iVar2) {
    puVar5 = local_2c;
    do {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    } while (puVar5 != (uint *)(iVar4 + iVar2 * 4 + 0x14));
    local_2c = local_2c + iVar2;
  }
  puVar6 = (uint *)(param_2 + 0x14);
  puVar5 = puVar6 + *(int *)(param_2 + 0x10);
  if ((param_3 & 0x1f) == 0) {
    do {
      uVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      *local_2c = uVar9;
      local_2c = local_2c + 1;
    } while (puVar6 < puVar5);
  }
  else {
    uVar9 = 0;
    puVar10 = local_2c;
    do {
      *puVar10 = *puVar6 << (param_3 & 0x1f) | uVar9;
      puVar10 = puVar10 + 1;
      uVar9 = *puVar6;
      puVar6 = puVar6 + 1;
      uVar9 = uVar9 >> (0x20 - (param_3 & 0x1f) & 0xff);
    } while (puVar6 < puVar5);
    uVar7 = 0;
    if ((uint *)(param_2 + 0x15) <= puVar5) {
      uVar7 = (int)puVar5 + (-0x15 - param_2) & 0xfffffffc;
    }
    *(uint *)((int)local_2c + uVar7 + 4) = uVar9;
    if (uVar9 != 0) goto LAB_1002606c;
  }
  iVar8 = iVar3;
LAB_1002606c:
  *(int *)(iVar4 + 0x10) = iVar8;
  FUN_10025a44(param_1,param_2);
  return iVar4;
}



/* FUN_100260a8 at 100260a8 */

int FUN_100260a8(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = *(int *)(param_2 + 0x10);
  if (*(int *)(param_1 + 0x10) == iVar2) {
    puVar1 = (uint *)(param_1 + 0x14) + iVar2;
    puVar3 = (uint *)(param_2 + 0x14 + iVar2 * 4);
    do {
      puVar1 = puVar1 + -1;
      puVar3 = puVar3 + -1;
      if (*puVar1 != *puVar3) {
        return (-(uint)(*puVar3 <= *puVar1) & 2) - 1;
      }
    } while ((uint *)(param_1 + 0x14) < puVar1);
  }
  return *(int *)(param_1 + 0x10) - iVar2;
}



/* FUN_100260e4 at 100260e4 */

int FUN_100260e4(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  uint *puVar13;
  uint *puVar14;
  
  iVar3 = *(int *)(param_3 + 0x10);
  iVar11 = *(int *)(param_2 + 0x10) - iVar3;
  iVar9 = param_3;
  if (*(int *)(param_2 + 0x10) == iVar3) {
    puVar6 = (uint *)(param_2 + 0x14) + iVar3;
    puVar4 = (uint *)(param_3 + 0x14 + iVar3 * 4);
    do {
      puVar6 = puVar6 + -1;
      puVar4 = puVar4 + -1;
      if (*puVar6 != *puVar4) {
        if (*puVar6 < *puVar4) goto LAB_10026128;
        goto LAB_10026136;
      }
    } while ((uint *)(param_2 + 0x14) < puVar6);
    iVar3 = FUN_100259c0(param_1,0);
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/mprec.c",0x237,0,"Balloc succeeded");
    }
    *(undefined4 *)(iVar3 + 0x10) = 1;
    *(undefined4 *)(iVar3 + 0x14) = 0;
  }
  else {
    if (iVar11 < 0) {
LAB_10026128:
      iVar11 = 1;
      iVar9 = param_2;
      param_2 = param_3;
    }
    else {
      iVar11 = 0;
    }
LAB_10026136:
    iVar3 = FUN_100259c0(param_1,*(undefined4 *)(param_2 + 4));
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/mprec.c",0x245,0,"Balloc succeeded");
    }
    iVar5 = *(int *)(param_2 + 0x10);
    iVar7 = param_2 + 0x14;
    *(int *)(iVar3 + 0xc) = iVar11;
    puVar13 = (uint *)(iVar5 * 4 + iVar7);
    puVar4 = (uint *)(iVar9 + 0x14);
    puVar6 = puVar4 + *(int *)(iVar9 + 0x10);
    iVar12 = 0x14;
    iVar11 = 0;
    do {
      uVar1 = *puVar4;
      puVar4 = puVar4 + 1;
      uVar8 = ((*(uint *)(param_2 + iVar12) & 0xffff) - (uVar1 & 0xffff)) + iVar11;
      iVar2 = ((*(uint *)(param_2 + iVar12) >> 0x10) - (uVar1 >> 0x10)) + ((int)uVar8 >> 0x10);
      iVar11 = iVar2 >> 0x10;
      uVar1 = uVar8 & 0xffff | iVar2 * 0x10000;
      *(uint *)(iVar3 + iVar12) = uVar1;
      iVar12 = iVar12 + 4;
    } while (puVar4 < puVar6);
    uVar8 = 0;
    if ((uint *)(iVar9 + 0x15) <= puVar6) {
      uVar8 = (int)puVar6 + (-0x15 - iVar9) & 0xfffffffc;
    }
    puVar4 = (uint *)(uVar8 + iVar3 + 0x14);
    puVar10 = (uint *)(iVar7 + uVar8 + 4);
    puVar6 = puVar10;
    if (puVar10 < puVar13) {
      do {
        uVar1 = *puVar6;
        puVar14 = puVar6 + 1;
        uVar8 = uVar1 + iVar11;
        iVar9 = ((int)((uVar1 & 0xffff) + iVar11) >> 0x10) + (uVar1 >> 0x10);
        iVar11 = iVar9 >> 0x10;
        uVar1 = uVar8 & 0xffff | iVar9 * 0x10000;
        *(uint *)((int)puVar6 + ((iVar3 + 0x14) - iVar7)) = uVar1;
        puVar6 = puVar14;
      } while (puVar14 < puVar13);
      puVar4 = (uint *)((int)puVar4 + ((int)puVar13 + (-1 - (int)puVar10) & 0xfffffffcU) + 4);
    }
    while (uVar1 == 0) {
      puVar4 = puVar4 + -1;
      iVar5 = iVar5 + -1;
      uVar1 = *puVar4;
    }
    *(int *)(iVar3 + 0x10) = iVar5;
  }
  return iVar3;
}



/* FUN_1002628c at 1002628c */

undefined8 FUN_1002628c(undefined4 param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = (param_2 & 0x7ff00000) + 0xfcc00000;
  uVar2 = 0;
  if (iVar3 < 1) {
    uVar1 = -iVar3 >> 0x14;
    if ((int)uVar1 < 0x14) {
      iVar3 = 0x80000 >> (uVar1 & 0xff);
    }
    else {
      uVar2 = 1;
      if ((int)(uVar1 - 0x14) < 0x1f) {
        uVar2 = 0x80000000 >> (uVar1 - 0x14 & 0xff);
      }
      iVar3 = 0;
    }
  }
  return CONCAT44(iVar3,uVar2);
}



/* FUN_100262cc at 100262cc */

undefined8 FUN_100262cc(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  
  iVar5 = *(int *)(param_1 + 0x10);
  puVar7 = (uint *)(param_1 + 0x14);
  puVar3 = puVar7 + iVar5 + -1;
  uVar6 = *puVar3;
  iVar1 = FUN_10025bdc(uVar6);
  *param_2 = 0x20 - iVar1;
  if (iVar1 < 0xb) {
    uVar2 = uVar6 >> (0xbU - iVar1 & 0xff) | 0x3ff00000;
    uVar4 = 0;
    if (puVar7 < puVar3) {
      uVar4 = puVar7[iVar5 + -2] >> (0xbU - iVar1 & 0xff);
    }
    uVar4 = uVar6 << (iVar1 + 0x15U & 0xff) | uVar4;
  }
  else {
    uVar8 = iVar1 - 0xb;
    if (puVar7 < puVar3) {
      uVar4 = puVar7[iVar5 + -2];
      if (uVar8 != 0) {
        uVar2 = uVar6 << (uVar8 & 0xff) | uVar4 >> (0x20 - uVar8 & 0xff) | 0x3ff00000;
        uVar4 = uVar4 << (uVar8 & 0xff);
        if (puVar7 < puVar7 + iVar5 + -2) {
          uVar4 = uVar4 | puVar7[iVar5 + -3] >> (0x20 - uVar8 & 0xff);
        }
        goto LAB_1002634c;
      }
    }
    else {
      if (iVar1 != 0xb) {
        uVar2 = uVar6 << (uVar8 & 0xff) | 0x3ff00000;
        uVar4 = 0;
        goto LAB_1002634c;
      }
      uVar4 = 0;
    }
    uVar2 = uVar6 | 0x3ff00000;
  }
LAB_1002634c:
  return CONCAT44(uVar2,uVar4);
}



/* FUN_10026384 at 10026384 */

int FUN_10026384(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4,int *param_5,
                int *param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint local_20;
  uint local_1c [2];
  
  iVar1 = FUN_100259c0(param_1,1);
  if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_1001fbec("/workdir/repo/newlib/newlib/libc/stdlib/mprec.c",0x30f,0,"Balloc succeeded");
  }
  local_1c[0] = param_4 & 0xfffff;
  uVar6 = (param_4 & 0x7fffffff) >> 0x14;
  if (uVar6 != 0) {
    local_1c[0] = local_1c[0] | 0x100000;
  }
  if (param_3 == 0) {
    iVar2 = FUN_10025c3c(local_1c);
    iVar5 = 1;
    uVar3 = iVar2 + 0x20;
    *(uint *)(iVar1 + 0x14) = local_1c[0];
    *(undefined4 *)(iVar1 + 0x10) = 1;
  }
  else {
    local_20 = param_3;
    uVar3 = FUN_10025c3c(&local_20);
    uVar4 = local_20;
    if (uVar3 != 0) {
      uVar4 = local_1c[0] << (0x20 - uVar3 & 0xff);
      local_1c[0] = local_1c[0] >> (uVar3 & 0xff);
      uVar4 = local_20 | uVar4;
    }
    *(uint *)(iVar1 + 0x14) = uVar4;
    *(uint *)(iVar1 + 0x18) = local_1c[0];
    iVar5 = 2 - (uint)(local_1c[0] == 0);
    *(int *)(iVar1 + 0x10) = iVar5;
  }
  if (uVar6 == 0) {
    *param_5 = uVar3 - 0x432;
    iVar2 = FUN_10025bdc(*(undefined4 *)(iVar1 + iVar5 * 4 + 0x10));
    iVar2 = iVar5 * 0x20 - iVar2;
  }
  else {
    *param_5 = (uVar6 - 0x433) + uVar3;
    iVar2 = 0x35 - uVar3;
  }
  *param_6 = iVar2;
  return iVar1;
}



/* FUN_10026448 at 10026448 */

void FUN_10026448(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  int local_28;
  int local_24 [2];
  
  uVar4 = FUN_100262cc(param_1,&local_28);
  iVar3 = (int)((ulonglong)uVar4 >> 0x20);
  uVar5 = FUN_100262cc(param_2,local_24);
  iVar2 = (int)((ulonglong)uVar5 >> 0x20);
  iVar1 = (local_28 - local_24[0]) + (*(int *)(param_1 + 0x10) - *(int *)(param_2 + 0x10)) * 0x20;
  if (iVar1 < 1) {
    iVar2 = iVar2 + iVar1 * -0x100000;
  }
  else {
    iVar3 = iVar1 * 0x100000 + iVar3;
  }
  FUN_1001e96a((int)uVar4,iVar3,(int)uVar5,iVar2,(int)uVar5,iVar2);
  return;
}



/* FUN_100264e4 at 100264e4 */

void FUN_100264e4(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  puVar2 = (undefined4 *)(param_3 + 0x14);
  puVar1 = puVar2 + *(int *)(param_3 + 0x10);
  puVar3 = param_1 + (param_2 + -1 >> 5) + 1;
  if (puVar2 < puVar1) {
    puVar4 = param_1;
    do {
      uVar5 = *puVar2;
      puVar2 = puVar2 + 1;
      *puVar4 = uVar5;
      puVar4 = puVar4 + 1;
    } while (puVar2 < puVar1);
    param_1 = (undefined4 *)((int)param_1 + ((int)puVar1 + (-0x15 - param_3) & 0xfffffffcU) + 4);
  }
  for (; param_1 < puVar3; param_1 = param_1 + 1) {
    *param_1 = 0;
  }
  return;
}



/* FUN_10026524 at 10026524 */

undefined4 FUN_10026524(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  iVar2 = *(int *)(param_1 + 0x10);
  puVar4 = (uint *)(param_1 + 0x14);
  iVar1 = (int)param_2 >> 5;
  if (iVar2 < iVar1) {
    puVar3 = puVar4 + iVar2;
  }
  else {
    puVar3 = puVar4 + iVar1;
    if (((iVar1 < iVar2) && ((param_2 & 0x1f) != 0)) &&
       (*puVar3 != (*puVar3 >> (param_2 & 0x1f)) << (param_2 & 0x1f))) {
      return 1;
    }
  }
  do {
    if (puVar3 <= puVar4) {
      return 0;
    }
    puVar3 = puVar3 + -1;
  } while (*puVar3 == 0);
  return 1;
}



/* FUN_10026614 at 10026614 */

uint * FUN_10026614(uint *param_1,byte param_2,byte *param_3)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  if (((uint)param_1 & 3) == 0) {
LAB_10026646:
    if ((byte *)0x3 < param_3) {
      do {
        uVar3 = *param_1 ^ (uint)param_2 * 0x1010101;
        if ((uVar3 + 0xfefefeff & ~uVar3 & 0x80808080) != 0) goto LAB_10026672;
        param_3 = param_3 + -4;
        param_1 = param_1 + 1;
      } while ((byte *)0x3 < param_3);
    }
    if (param_3 != (byte *)0x0) {
LAB_10026672:
      puVar2 = (uint *)((int)param_1 + (int)param_3);
      do {
        if ((byte)*param_1 == param_2) {
          return param_1;
        }
        param_1 = (uint *)((int)param_1 + 1);
      } while (param_1 != puVar2);
    }
  }
  else {
    puVar2 = param_1;
    while (puVar2 != (uint *)((int)param_1 + (int)param_3)) {
      if ((byte)*puVar2 == param_2) {
        return puVar2;
      }
      puVar1 = (uint *)((int)puVar2 + 1);
      if (((uint)puVar1 & 3) == 0) {
        param_3 = (byte *)((int)param_1 + (int)(param_3 + (-1 - (int)puVar2)));
        param_1 = puVar1;
        goto LAB_10026646;
      }
      puVar2 = puVar1;
    }
  }
  return (uint *)0x0;
}



/* FUN_10026704 at 10026704 */

undefined4 FUN_10026704(undefined4 *param_1,uint param_2)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 *puVar3;
  
  if (param_2 < 0x20) {
    if (param_1[0xf] != 0) {
      puVar3 = (undefined4 *)(param_1[0xf] + param_2 * 4);
      pcVar2 = (code *)*puVar3;
      if (pcVar2 != (code *)0x0) {
        if (pcVar2 != (code *)0x1) {
          if (pcVar2 == (code *)0xffffffff) {
            *param_1 = 0x16;
            return 1;
          }
          *puVar3 = 0;
          (*pcVar2)(param_2);
        }
        return 0;
      }
    }
    uVar1 = FUN_10027270(param_1);
    uVar1 = FUN_10027248(param_1,uVar1,param_2);
  }
  else {
    *param_1 = 0x16;
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* FUN_100267b4 at 100267b4 */

void FUN_100267b4(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_1001c744();
  FUN_10026704(uVar1,param_1);
  return;
}



/* FUN_100267c4 at 100267c4 */

undefined4 FUN_100267c4(uint param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)FUN_1001c744();
  if (param_1 < 0x20) {
    puVar2 = (undefined4 *)puVar1[0xf];
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)FUN_10022670(puVar1,0x80);
      puVar1[0xf] = puVar2;
      puVar1 = puVar2;
      if (puVar2 == (undefined4 *)0x0) goto LAB_100267e8;
      do {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
      } while (puVar2 + 0x20 != puVar1);
    }
    uVar3 = puVar2[param_1];
    puVar2[param_1] = param_2;
  }
  else {
    *puVar1 = 0x16;
LAB_100267e8:
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



/* FUN_10026850 at 10026850 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10026850(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  _DAT_200013a0 = 0;
  iVar1 = FUN_100275ac(param_2);
  if ((iVar1 == -1) && (_DAT_200013a0 != 0)) {
    *param_1 = _DAT_200013a0;
  }
  return;
}



/* FUN_10026874 at 10026874 */

undefined4 FUN_10026874(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_2 == 0) {
LAB_10026900:
    uVar2 = 0;
  }
  else {
    if ((param_1 != 0) && (*(int *)(param_1 + 0x20) == 0)) {
      FUN_10021cfc();
    }
    iVar4 = (int)*(short *)(param_2 + 0xc);
    uVar3 = *(uint *)(param_2 + 0x68);
    if ((uVar3 & 1) == 0) {
      iVar4 = iVar4 << 0x16;
      if (-1 < iVar4) {
        FUN_100274fc(param_2 + 0x58);
        uVar3 = 0xc;
        iVar4 = (int)*(short *)(param_2 + 0xc);
        if (iVar4 == 0) {
          if ((*(uint *)(param_2 + 0x68) & 1) == 0) {
            FUN_1002751c(param_2 + 0x58);
          }
          goto LAB_10026900;
        }
      }
    }
    else if (iVar4 == 0) goto LAB_10026900;
    uVar2 = FUN_10026f08(param_1,param_2,uVar3,iVar4,param_4);
    if ((*(code **)(param_2 + 0x30) == (code *)0x0) ||
       (iVar4 = (**(code **)(param_2 + 0x30))(param_1,*(undefined4 *)(param_2 + 0x20)), -1 < iVar4))
    {
      uVar1 = *(ushort *)(param_2 + 0xc);
    }
    else {
      uVar1 = *(ushort *)(param_2 + 0xc);
      uVar2 = 0xffffffff;
    }
    if ((int)((uint)uVar1 << 0x18) < 0) {
      FUN_10023f9c(param_1,*(undefined4 *)(param_2 + 0x10));
    }
    if (*(int *)(param_2 + 0x34) != 0) {
      if (*(int *)(param_2 + 0x34) != param_2 + 0x44) {
        FUN_10023f9c(param_1);
      }
      *(undefined4 *)(param_2 + 0x34) = 0;
    }
    if (*(int *)(param_2 + 0x48) != 0) {
      FUN_10023f9c(param_1);
      *(undefined4 *)(param_2 + 0x48) = 0;
    }
    FUN_10021d34();
    *(undefined2 *)(param_2 + 0xc) = 0;
    if (-1 < *(int *)(param_2 + 0x68) << 0x1f) {
      FUN_1002751c(param_2 + 0x58);
    }
    FUN_100274f8(param_2 + 0x58);
    FUN_10021d44();
  }
  return uVar2;
}



/* FUN_1002695c at 1002695c */

undefined4 FUN_1002695c(undefined4 *param_1,uint *param_2,undefined4 *param_3)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  ushort uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  int iVar12;
  int *piVar13;
  
  if (param_3[2] != 0) {
    uVar6 = (uint)(short)param_2[3];
    if (((int)(uVar6 << 0x1c) < 0) && (param_2[4] != 0)) {
      piVar11 = (int *)*param_3;
    }
    else {
      iVar12 = FUN_10026d84(param_1,param_2);
      if (iVar12 != 0) {
        return 0xffffffff;
      }
      uVar6 = (uint)(short)param_2[3];
      piVar11 = (int *)*param_3;
    }
    if ((int)(uVar6 << 0x1e) < 0) {
      iVar12 = 0;
      uVar6 = 0;
      do {
        while (uVar6 == 0) {
          iVar12 = *piVar11;
          puVar1 = (uint *)(piVar11 + 1);
          piVar11 = piVar11 + 2;
          uVar6 = *puVar1;
        }
        uVar7 = uVar6;
        if (0x7ffffc00 < uVar6) {
          uVar7 = 0x7ffffc00;
        }
        iVar3 = (*(code *)param_2[10])(param_1,param_2[8],iVar12,uVar7);
        if (iVar3 < 1) goto LAB_10026ac8;
        iVar8 = param_3[2];
        iVar12 = iVar12 + iVar3;
        uVar6 = uVar6 - iVar3;
        param_3[2] = iVar8 - iVar3;
      } while (iVar8 - iVar3 != 0);
    }
    else {
      if ((int)(uVar6 << 0x1f) < 0) {
LAB_10026b38:
        do {
          piVar13 = piVar11;
          uVar6 = piVar13[1];
          piVar11 = piVar13 + 2;
        } while (uVar6 == 0);
        iVar12 = *piVar13;
        do {
          iVar3 = FUN_10026614(iVar12,10,uVar6);
          if (iVar3 == 0) {
            uVar7 = uVar6 + 1;
          }
          else {
            uVar7 = (iVar3 + 1) - iVar12;
          }
          do {
            uVar9 = uVar6;
            if (uVar7 < uVar6) {
              uVar9 = uVar7;
            }
            uVar4 = *param_2;
            if ((param_2[4] < uVar4) && (uVar10 = param_2[5] + param_2[2], (int)uVar10 < (int)uVar9)
               ) {
              FUN_10025130(uVar4,iVar12,uVar10);
              *param_2 = *param_2 + uVar10;
              iVar3 = FUN_10027044(param_1,param_2);
              if (iVar3 != 0) goto LAB_10026ac8;
            }
            else if ((int)uVar9 < (int)param_2[5]) {
              FUN_10025130(uVar4,iVar12,uVar9);
              param_2[2] = param_2[2] - uVar9;
              *param_2 = *param_2 + uVar9;
              uVar10 = uVar9;
            }
            else {
              uVar10 = (*(code *)param_2[10])(param_1,param_2[8],iVar12);
              if ((int)uVar10 < 1) goto LAB_10026ac8;
            }
            bVar2 = true;
            uVar7 = uVar7 - uVar10;
            if (uVar7 == 0) {
              iVar3 = FUN_10027044(param_1,param_2);
              bVar2 = false;
              if (iVar3 != 0) goto LAB_10026ac8;
            }
            iVar3 = param_3[2];
            iVar12 = iVar12 + uVar10;
            uVar6 = uVar6 - uVar10;
            param_3[2] = iVar3 - uVar10;
            if (iVar3 - uVar10 == 0) {
              return 0;
            }
            if (uVar6 == 0) goto LAB_10026b38;
          } while (bVar2);
        } while( true );
      }
      iVar12 = 0;
      uVar7 = 0;
joined_r0x10026a00:
      while (uVar7 == 0) {
        iVar12 = *piVar11;
        puVar1 = (uint *)(piVar11 + 1);
        piVar11 = piVar11 + 2;
        uVar7 = *puVar1;
      }
      uVar4 = *param_2;
      uVar9 = param_2[2];
      if ((uVar6 & 0x200) == 0) {
        if ((param_2[4] < uVar4) || (uVar6 = param_2[5], uVar7 < uVar6)) {
          if (uVar7 < uVar9) {
            uVar9 = uVar7;
          }
          FUN_10025130(uVar4,iVar12,uVar9);
          uVar6 = param_2[2];
          param_2[2] = uVar6 - uVar9;
          *param_2 = *param_2 + uVar9;
          if (uVar6 - uVar9 == 0) {
            iVar3 = FUN_10027044(param_1,param_2);
            if (iVar3 == 0) {
              uVar4 = uVar7 - uVar9;
              uVar7 = uVar9;
              goto LAB_10026a92;
            }
LAB_10026ac8:
            uVar5 = (ushort)param_2[3];
LAB_10026acc:
            *(ushort *)(param_2 + 3) = uVar5 | 0x40;
            return 0xffffffff;
          }
        }
        else {
          uVar9 = uVar7;
          if (0x7fffffff < uVar7) {
            uVar9 = 0x7fffffff;
          }
          iVar3 = FUN_1001e480(uVar9,uVar6);
          uVar9 = (*(code *)param_2[10])(param_1,param_2[8],iVar12,iVar3 * uVar6);
          if ((int)uVar9 < 1) goto LAB_10026ac8;
        }
        uVar4 = uVar7 - uVar9;
        uVar7 = uVar9;
      }
      else {
        if (uVar7 < uVar9) {
          uVar9 = uVar7;
        }
        else if ((uVar6 & 0x480) != 0) {
          iVar3 = uVar4 - param_2[4];
          uVar9 = (int)(param_2[5] * 3) / 2;
          uVar4 = iVar3 + 1 + uVar7;
          if (uVar9 < uVar4) {
            uVar9 = uVar4;
          }
          if ((int)(uVar6 << 0x15) < 0) {
            uVar4 = FUN_10022670(param_1,uVar9);
            if (uVar4 == 0) {
              *param_1 = 0xc;
              uVar5 = (ushort)param_2[3];
              goto LAB_10026acc;
            }
            FUN_1001f4d4(uVar4,param_2[4],iVar3);
            *(ushort *)(param_2 + 3) = (ushort)param_2[3] & 0xfb7f | 0x80;
          }
          else {
            uVar4 = FUN_1002487c(param_1);
            if (uVar4 == 0) {
              FUN_10023f9c(param_1,param_2[4]);
              uVar5 = (ushort)param_2[3] & 0xff7f;
              *param_1 = 0xc;
              goto LAB_10026acc;
            }
          }
          param_2[4] = uVar4;
          uVar4 = uVar4 + iVar3;
          *param_2 = uVar4;
          param_2[5] = uVar9;
          param_2[2] = uVar9 - iVar3;
          uVar9 = uVar7;
        }
        FUN_10025130(uVar4,iVar12,uVar9);
        uVar4 = 0;
        param_2[2] = param_2[2] - uVar9;
        *param_2 = *param_2 + uVar9;
      }
LAB_10026a92:
      iVar3 = param_3[2];
      iVar12 = iVar12 + uVar7;
      param_3[2] = iVar3 - uVar7;
      if (iVar3 - uVar7 != 0) {
        uVar6 = (uint)(short)param_2[3];
        uVar7 = uVar4;
        goto joined_r0x10026a00;
      }
    }
  }
  return 0;
}



/* FUN_10026c44 at 10026c44 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10026c44(void)

{
  (*_DAT_20000f34)();
  return;
}



/* FUN_10026c88 at 10026c88 */

int FUN_10026c88(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  char *pcVar2;
  char local_1c [8];
  
  iVar1 = FUN_100250b4();
  if ((iVar1 == 1) && (param_2 - 1U < 0xff)) {
    local_1c[0] = (char)param_2;
  }
  else {
    iVar1 = FUN_10026e80(param_1,local_1c,param_2,param_3 + 0x18);
    if (iVar1 == -1) {
      *(ushort *)(param_3 + 3) = *(ushort *)(param_3 + 3) | 0x40;
      return -1;
    }
    if (iVar1 == 0) {
      return param_2;
    }
  }
  iVar1 = param_3[2] + -1;
  param_3[2] = iVar1;
  if ((iVar1 < 0) && ((iVar1 < param_3[6] || (local_1c[0] == '\n')))) {
    iVar1 = FUN_10025854(param_1,local_1c[0],param_3);
    if (iVar1 == -1) {
      return -1;
    }
  }
  else {
    pcVar2 = (char *)*param_3;
    *param_3 = (int)(pcVar2 + 1);
    *pcVar2 = local_1c[0];
  }
  return param_2;
}



/* FUN_10026d00 at 10026d00 */

undefined4 FUN_10026d00(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = (uint)*(short *)(param_3 + 0xc);
  if ((-1 < *(int *)(param_3 + 0x68) << 0x1f) && (-1 < (int)(uVar2 << 0x16))) {
    FUN_100274fc(param_3 + 0x58);
    uVar2 = (uint)*(short *)(param_3 + 0xc);
  }
  if ((uVar2 & 0x2000) == 0) {
    *(ushort *)(param_3 + 0xc) = (ushort)uVar2 | 0x2000;
    *(uint *)(param_3 + 0x68) = *(uint *)(param_3 + 0x68) | 0x2000;
  }
  uVar1 = FUN_10026c88(param_1,param_2,param_3);
  if ((-1 < *(int *)(param_3 + 0x68) << 0x1f) &&
     (-1 < (int)((uint)*(ushort *)(param_3 + 0xc) << 0x16))) {
    FUN_1002751c(param_3 + 0x58);
  }
  return uVar1;
}



/* FUN_10026d84 at 10026d84 */

undefined4 FUN_10026d84(undefined4 *param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  iVar2 = FUN_1001c744();
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x20) == 0)) {
    FUN_10021cfc();
  }
  uVar1 = *(ushort *)(param_2 + 3);
  uVar5 = (uint)(short)uVar1;
  if ((int)(uVar5 << 0x1c) < 0) {
    iVar2 = param_2[4];
joined_r0x10026dd0:
    if (iVar2 == 0) {
      if ((uVar5 & 0x280) == 0x200) {
        if ((int)(uVar5 << 0x1f) < 0) {
          param_2[2] = 0;
          param_2[6] = -param_2[5];
        }
        else {
          if (-1 < (int)(uVar5 << 0x1e)) {
            iVar4 = param_2[5];
            iVar2 = 0;
            goto LAB_10026e5e;
          }
          param_2[2] = 0;
        }
      }
      else {
        FUN_10027278(param_1,param_2);
        uVar5 = (uint)(short)param_2[3];
        iVar2 = param_2[4];
        if ((int)(uVar5 << 0x1f) < 0) {
          param_2[2] = 0;
          param_2[6] = -param_2[5];
        }
        else {
          iVar4 = 0;
          if (-1 < (int)(uVar5 << 0x1e)) {
            iVar4 = param_2[5];
          }
LAB_10026e5e:
          param_2[2] = iVar4;
        }
        if (iVar2 != 0) goto LAB_10026dba;
      }
      if ((int)(uVar5 << 0x18) < 0) {
        *(ushort *)(param_2 + 3) = (ushort)uVar5 | 0x40;
        goto LAB_10026e7a;
      }
    }
    else if ((uVar5 & 1) == 0) {
      if ((int)(uVar5 << 0x1e) < 0) {
        param_2[2] = uVar5 & 1;
      }
      else {
        param_2[2] = param_2[5];
      }
    }
    else {
      param_2[2] = 0;
      param_2[6] = -param_2[5];
    }
LAB_10026dba:
    uVar3 = 0;
  }
  else {
    if ((int)(uVar5 << 0x1b) < 0) {
      if ((int)(uVar5 << 0x1d) < 0) {
        if ((int *)param_2[0xd] != (int *)0x0) {
          if ((int *)param_2[0xd] != param_2 + 0x11) {
            FUN_10023f9c(param_1);
            uVar5 = (uint)(short)param_2[3];
          }
          param_2[0xd] = 0;
        }
        uVar5 = uVar5 & 0xffffffdb;
        param_2[1] = 0;
        iVar2 = param_2[4];
        *param_2 = iVar2;
      }
      else {
        iVar2 = param_2[4];
      }
      uVar5 = uVar5 | 8;
      *(short *)(param_2 + 3) = (short)uVar5;
      goto joined_r0x10026dd0;
    }
    *param_1 = 9;
    *(ushort *)(param_2 + 3) = uVar1 | 0x40;
LAB_10026e7a:
    uVar3 = 0xffffffff;
  }
  return uVar3;
}



/* FUN_10026e80 at 10026e80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10026e80(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined1 auStack_1c [12];
  
  if (param_2 == 0) {
    iVar1 = (*_DAT_20000f30)(param_1,auStack_1c,0,param_4);
  }
  else {
    iVar1 = (*_DAT_20000f30)(param_1);
  }
  if (iVar1 == -1) {
    *param_4 = 0;
    *param_1 = 0x8a;
  }
  return;
}



/* FUN_10026ebc at 10026ebc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10026ebc(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 auStack_24 [12];
  
  puVar1 = (undefined4 *)FUN_1001c744();
  if (param_1 == 0) {
    iVar2 = (*_DAT_20000f30)(puVar1,auStack_24,0,param_3);
  }
  else {
    iVar2 = (*_DAT_20000f30)(puVar1,param_1,param_2);
  }
  if (iVar2 == -1) {
    *param_3 = 0;
    *puVar1 = 0x8a;
  }
  return;
}



/* FUN_10026f08 at 10026f08 */

undefined4 FUN_10026f08(uint *param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  
  uVar6 = (uint)(short)param_2[3];
  if ((int)(uVar6 << 0x1c) < 0) {
    iVar2 = param_2[4];
    if (iVar2 == 0) {
      return 0;
    }
    iVar5 = 0;
    iVar8 = *param_2 - iVar2;
    *param_2 = iVar2;
    if ((uVar6 & 3) == 0) {
      iVar5 = param_2[5];
    }
    param_2[2] = iVar5;
    while( true ) {
      if (iVar8 < 1) {
        return 0;
      }
      iVar5 = (*(code *)param_2[10])(param_1,param_2[8],iVar2,iVar8);
      if (iVar5 < 1) break;
      iVar2 = iVar2 + iVar5;
      iVar8 = iVar8 - iVar5;
    }
LAB_10026fec:
    uVar1 = *(ushort *)(param_2 + 3);
LAB_10026ff4:
    *(ushort *)(param_2 + 3) = uVar1 | 0x40;
    return 0xffffffff;
  }
  uVar3 = uVar6 | 0x800;
  *(short *)(param_2 + 3) = (short)uVar3;
  if ((param_2[1] < 1) && (param_2[0x10] < 1)) {
    return 0;
  }
  pcVar7 = (code *)param_2[0xb];
  if (pcVar7 == (code *)0x0) {
    return 0;
  }
  uVar9 = *param_1;
  *param_1 = 0;
  if ((int)(uVar6 << 0x13) < 0) {
    iVar2 = param_2[0x15];
  }
  else {
    iVar2 = (*pcVar7)(param_1,param_2[8],0,1);
    if ((iVar2 == -1) && (uVar6 = *param_1, uVar6 != 0)) {
      if ((uVar6 == 0x1d) || (uVar6 == 0x16)) {
        *param_1 = uVar9;
        return 0;
      }
      goto LAB_10026fec;
    }
    uVar3 = (uint)(short)param_2[3];
    pcVar7 = (code *)param_2[0xb];
  }
  if (((int)(uVar3 << 0x1d) < 0) && (iVar2 = iVar2 - param_2[1], param_2[0xd] != 0)) {
    iVar2 = iVar2 - param_2[0x10];
  }
  iVar2 = (*pcVar7)(param_1,param_2[8],iVar2,0);
  uVar1 = *(ushort *)(param_2 + 3);
  if (iVar2 == -1) {
    uVar6 = *param_1;
    if ((0x1d < uVar6) || (-1 < (int)((0x20400001U >> (uVar6 & 0xff)) << 0x1f))) goto LAB_10026ff4;
    *(ushort *)(param_2 + 3) = uVar1 & 0xf7ff;
    param_2[1] = 0;
    *param_2 = param_2[4];
    if ((-1 < (int)(short)uVar1 << 0x13) || (uVar6 != 0)) goto LAB_10026f94;
  }
  else {
    *(ushort *)(param_2 + 3) = uVar1 & 0xf7ff;
    param_2[1] = 0;
    *param_2 = param_2[4];
    if (-1 < (int)(short)uVar1 << 0x13) goto LAB_10026f94;
  }
  param_2[0x15] = iVar2;
LAB_10026f94:
  piVar4 = (int *)param_2[0xd];
  *param_1 = uVar9;
  if (piVar4 != (int *)0x0) {
    if (piVar4 != param_2 + 0x11) {
      FUN_10023f9c(param_1);
    }
    param_2[0xd] = 0;
  }
  return 0;
}



/* FUN_10027044 at 10027044 */

undefined4 FUN_10027044(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_2 + 0x10) != 0) {
    if ((param_1 != 0) && (*(int *)(param_1 + 0x20) == 0)) {
      FUN_10021cfc();
    }
    if (*(short *)(param_2 + 0xc) != 0) {
      if ((-1 < *(int *)(param_2 + 0x68) << 0x1f) && (-1 < (int)*(short *)(param_2 + 0xc) << 0x16))
      {
        FUN_100274fc(param_2 + 0x58);
      }
      uVar1 = FUN_10026f08(param_1,param_2);
      if (*(int *)(param_2 + 0x68) << 0x1f < 0) {
        return uVar1;
      }
      if ((int)((uint)*(ushort *)(param_2 + 0xc) << 0x16) < 0) {
        return uVar1;
      }
      FUN_1002751c(param_2 + 0x58);
      return uVar1;
    }
  }
  return 0;
}



/* FUN_100270d0 at 100270d0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100270d0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  _DAT_200013a0 = 0;
  iVar1 = FUN_100275a0(param_2,param_3,param_4);
  if ((iVar1 == -1) && (_DAT_200013a0 != 0)) {
    *param_1 = _DAT_200013a0;
  }
  return;
}



/* FUN_100270f8 at 100270f8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100270f8(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  _DAT_200013a0 = 0;
  iVar1 = FUN_10027540(param_2);
  if ((iVar1 == -1) && (_DAT_200013a0 != 0)) {
    *param_1 = _DAT_200013a0;
  }
  return;
}



/* FUN_10027148 at 10027148 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10027148(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  bool bVar11;
  
  FUN_100274fc(_DAT_20000fbc);
  if (_DAT_200013a4 != 0) {
LAB_1002716e:
    iVar1 = _DAT_200013a4;
    iVar5 = *(int *)(_DAT_200013a4 + 0x88);
    uVar7 = *(int *)(_DAT_200013a4 + 4) - 1;
    if (-1 < (int)uVar7) {
      iVar8 = (*(int *)(_DAT_200013a4 + 4) + 0x1f) * 4;
      piVar10 = (int *)(iVar5 + iVar8);
      puVar9 = (undefined4 *)(_DAT_200013a4 + iVar8 + -0x78);
      do {
        if (param_2 != 0) {
          if (iVar5 == 0) goto LAB_10027234;
          while (*piVar10 != param_2) {
            piVar10 = piVar10 + -1;
            puVar9 = puVar9 + -1;
            bVar11 = uVar7 == 0;
            uVar7 = uVar7 - 1;
            if (bVar11) goto LAB_100271a2;
          }
        }
        pcVar3 = (code *)*puVar9;
        if (*(int *)(iVar1 + 4) - 1U == uVar7) {
          *(uint *)(iVar1 + 4) = uVar7;
        }
        else {
          *puVar9 = 0;
        }
        if (pcVar3 != (code *)0x0) {
          iVar8 = *(int *)(iVar1 + 4);
          if ((iVar5 == 0) || (uVar6 = 1 << (uVar7 & 0xff), (*(uint *)(iVar5 + 0x100) & uVar6) == 0)
             ) {
            (*pcVar3)();
            iVar4 = *(int *)(iVar1 + 4);
          }
          else {
            uVar2 = *(undefined4 *)(iVar5 + uVar7 * 4);
            if ((*(uint *)(iVar5 + 0x104) & uVar6) == 0) {
              (*pcVar3)(param_1,uVar2);
            }
            else {
              (*pcVar3)(uVar2);
            }
            iVar4 = *(int *)(iVar1 + 4);
          }
          if ((iVar4 != iVar8) || (_DAT_200013a4 != iVar1)) goto LAB_10027226;
        }
        piVar10 = piVar10 + -1;
        puVar9 = puVar9 + -1;
        bVar11 = uVar7 == 0;
        uVar7 = uVar7 - 1;
        if (bVar11) break;
      } while( true );
    }
  }
LAB_100271a2:
  FUN_1002751c(_DAT_20000fbc);
  return;
LAB_10027234:
  do {
    bVar11 = uVar7 != 0;
    uVar7 = uVar7 - 1;
  } while (bVar11);
  goto LAB_100271a2;
LAB_10027226:
  if (_DAT_200013a4 == 0) goto LAB_100271a2;
  goto LAB_1002716e;
}



/* FUN_10027248 at 10027248 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_10027248(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  _DAT_200013a0 = 0;
  iVar1 = FUN_10027580(param_2,param_3);
  if ((iVar1 == -1) && (_DAT_200013a0 != 0)) {
    *param_1 = _DAT_200013a0;
  }
  return;
}



/* FUN_10027270 at 10027270 */

void FUN_10027270(void)

{
  FUN_10027560();
  return;
}



/* FUN_10027278 at 10027278 */

void FUN_10027278(undefined4 param_1,int *param_2)

{
  int iVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  undefined1 auStack_68 [4];
  uint local_64;
  
  uVar4 = (uint)(short)param_2[3];
  if ((int)(uVar4 << 0x1e) < 0) {
LAB_10027288:
    *param_2 = (int)param_2 + 0x47;
    param_2[4] = (int)param_2 + 0x47;
    param_2[5] = 1;
  }
  else {
    if (*(short *)((int)param_2 + 0xe) < 0) {
LAB_10027300:
      iVar5 = (-(uint)((uVar4 & 0x80) == 0) & 0x3c0) + 0x40;
      iVar1 = FUN_10022670(param_1,iVar5);
      uVar3 = *(ushort *)(param_2 + 3);
      if (iVar1 == 0) {
LAB_10027334:
        if ((int)(short)uVar3 << 0x16 < 0) {
          return;
        }
        *(ushort *)(param_2 + 3) = uVar3 & 0xfffc | 2;
        goto LAB_10027288;
      }
      uVar3 = uVar3 | 0x80;
      uVar2 = 0;
      *param_2 = iVar1;
      param_2[4] = iVar1;
      param_2[5] = iVar5;
    }
    else {
      iVar1 = FUN_100273a4(param_1,(int)*(short *)((int)param_2 + 0xe),auStack_68);
      if (iVar1 < 0) {
        uVar4 = (uint)(short)param_2[3];
        goto LAB_10027300;
      }
      iVar1 = FUN_10022670(param_1,0x400);
      uVar3 = *(ushort *)(param_2 + 3);
      if (iVar1 == 0) goto LAB_10027334;
      uVar3 = uVar3 | 0x80;
      param_2[5] = 0x400;
      *(ushort *)(param_2 + 3) = uVar3;
      *param_2 = iVar1;
      param_2[4] = iVar1;
      if ((local_64 & 0xf000) == 0x2000) {
        iVar1 = FUN_1002741c(param_1,(int)*(short *)((int)param_2 + 0xe));
        uVar3 = *(ushort *)(param_2 + 3);
        if (iVar1 == 0) goto LAB_10027344;
        uVar3 = uVar3 & 0xfffc | 1;
        uVar2 = 0x800;
      }
      else {
LAB_10027344:
        uVar2 = 0x800;
      }
    }
    *(ushort *)(param_2 + 3) = uVar3 | uVar2;
  }
  return;
}



/* FUN_100273a4 at 100273a4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100273a4(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  _DAT_200013a0 = 0;
  iVar1 = FUN_10027550(param_2,param_3);
  if ((iVar1 == -1) && (_DAT_200013a0 != 0)) {
    *param_1 = _DAT_200013a0;
  }
  return;
}



/* FUN_100273cc at 100273cc */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100273cc(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  _DAT_200013a0 = 0;
  iVar1 = FUN_10027590(param_2,param_3,param_4);
  if ((iVar1 == -1) && (_DAT_200013a0 != 0)) {
    *param_1 = _DAT_200013a0;
  }
  return;
}



/* FUN_100273f4 at 100273f4 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_100273f4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  _DAT_200013a0 = 0;
  iVar1 = FUN_1002753c(param_2,param_3,param_4);
  if ((iVar1 == -1) && (_DAT_200013a0 != 0)) {
    *param_1 = _DAT_200013a0;
  }
  return;
}



/* FUN_1002741c at 1002741c */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002741c(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  _DAT_200013a0 = 0;
  iVar1 = FUN_10027570(param_2);
  if ((iVar1 == -1) && (_DAT_200013a0 != 0)) {
    *param_1 = _DAT_200013a0;
  }
  return;
}



/* FUN_10027440 at 10027440 */

undefined4 FUN_10027440(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (param_1 == 0x20001020) {
    puVar2 = (undefined4 *)&DAT_20001764;
  }
  else if (param_1 == 0x20001018) {
    puVar2 = (undefined4 *)&DAT_20001760;
  }
  else if (param_1 == 0x20001010) {
    puVar2 = (undefined4 *)&DAT_20001754;
  }
  else if (param_1 == 0x20001000) {
    puVar2 = (undefined4 *)&DAT_2000175c;
  }
  else {
    if (param_1 != 0x20000ff8) {
      uVar1 = FUN_1001cc9c(param_1,1);
      return uVar1;
    }
    puVar2 = (undefined4 *)&DAT_20001758;
  }
  return *puVar2;
}



/* FUN_100274a8 at 100274a8 */

void FUN_100274a8(int param_1)

{
  if (DAT_20003b2a == '\0') {
    FUN_1001d296();
  }
  else if ((((param_1 != 0x20001020) && (param_1 != 0x20001018)) && (param_1 != 0x20001010)) &&
          ((param_1 != 0x20001000 && (param_1 != 0x20000ff8)))) {
    FUN_1001cc9c(param_1,1);
  }
  return;
}



/* FUN_100274f8 at 100274f8 */

void FUN_100274f8(void)

{
  return;
}



/* FUN_100274fc at 100274fc */

void FUN_100274fc(void)

{
  if (DAT_20003b2a == '\0') {
    FUN_10027678();
  }
  else {
    FUN_10027440();
  }
  return;
}



/* FUN_1002751c at 1002751c */

void FUN_1002751c(void)

{
  if (DAT_20003b2a == '\0') {
    FUN_10027728();
  }
  else {
    FUN_10027440();
  }
  return;
}



/* FUN_1002753c at 1002753c */

undefined4 FUN_1002753c(void)

{
  return 0;
}



/* FUN_10027540 at 10027540 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10027540(void)

{
  _DAT_200013a0 = 0x58;
  return 0xffffffff;
}



/* FUN_10027550 at 10027550 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10027550(void)

{
  _DAT_200013a0 = 0x58;
  return 0xffffffff;
}



/* FUN_10027560 at 10027560 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10027560(void)

{
  _DAT_200013a0 = 0x58;
  return 0xffffffff;
}



/* FUN_10027570 at 10027570 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10027570(void)

{
  _DAT_200013a0 = 0x58;
  return 0;
}



/* FUN_10027580 at 10027580 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10027580(void)

{
  _DAT_200013a0 = 0x58;
  return 0xffffffff;
}



/* FUN_10027590 at 10027590 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10027590(void)

{
  _DAT_200013a0 = 0x58;
  return 0xffffffff;
}



/* FUN_100275a0 at 100275a0 */

undefined4 FUN_100275a0(void)

{
  return 0xffffffff;
}



/* FUN_100275a6 at 100275a6 */

void FUN_100275a6(void)

{
  do {
    software_bkpt(0);
  } while( true );
}



/* FUN_100275ac at 100275ac */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_100275ac(int param_1)

{
  uint uVar1;
  
  if (_DAT_20002818 == 0) {
    _DAT_20002818 = 0x200041f4;
  }
  if (_DAT_20002818 + param_1 < 0x20040001) {
    uVar1 = _DAT_20002818;
    _DAT_20002818 = _DAT_20002818 + param_1;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}



/* FUN_100275d8 at 100275d8 */

void FUN_100275d8(void)

{
  bool bVar1;
  uint uVar2;
  undefined **ppuVar3;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = getCurrentExceptionNumber();
    uVar2 = uVar2 & 0x1ff;
  }
  if (uVar2 != 0) {
    software_bkpt(0);
  }
  FUN_1001f614();
  for (ppuVar3 = &PTR_FUN_100031e8_1_10027784; ppuVar3 < "Doboz"; ppuVar3 = ppuVar3 + 1) {
    (*(code *)*ppuVar3)();
  }
  return;
}



/* FUN_10027608 at 10027608 */

void FUN_10027608(undefined4 param_1)

{
  (*(code *)&LAB_200005dc)(param_1);
  return;
}



/* FUN_10027618 at 10027618 */

void FUN_10027618(undefined4 param_1)

{
  (*(code *)&LAB_20000428)(param_1);
  return;
}



/* FUN_10027628 at 10027628 */

void FUN_10027628(undefined4 param_1)

{
  (*(code *)&LAB_2000072c)(param_1);
  return;
}



/* FUN_10027638 at 10027638 */

void FUN_10027638(undefined4 param_1)

{
  (*(code *)&LAB_20000730)(param_1);
  return;
}



/* FUN_10027648 at 10027648 */

void FUN_10027648(undefined4 param_1)

{
  (*(code *)&LAB_20000568)(param_1);
  return;
}



/* FUN_10027658 at 10027658 */

void FUN_10027658(undefined4 param_1)

{
  (*(code *)&LAB_20000700)(param_1);
  return;
}



/* FUN_10027668 at 10027668 */

void FUN_10027668(undefined4 param_1)

{
  (*(code *)&LAB_2000072c)(param_1);
  return;
}



/* FUN_10027678 at 10027678 */

void FUN_10027678(undefined4 param_1)

{
  (*(code *)&LAB_20000302)(param_1);
  return;
}



/* FUN_10027688 at 10027688 */

void FUN_10027688(undefined4 param_1)

{
  (*(code *)&LAB_20000352)(param_1);
  return;
}



/* FUN_10027698 at 10027698 */

void FUN_10027698(undefined4 param_1)

{
  (*(code *)&LAB_200004f0)(param_1);
  return;
}



/* FUN_100276a8 at 100276a8 */

void FUN_100276a8(undefined4 param_1)

{
  (*(code *)&LAB_200003ec)(param_1);
  return;
}



/* FUN_100276b8 at 100276b8 */

void FUN_100276b8(undefined4 param_1)

{
  (*(code *)&LAB_20000680)(param_1);
  return;
}



/* FUN_100276c8 at 100276c8 */

void FUN_100276c8(undefined4 param_1)

{
  (*(code *)&LAB_20000280)(param_1);
  return;
}



/* FUN_100276d8 at 100276d8 */

void FUN_100276d8(undefined4 param_1)

{
  (*(code *)&LAB_200000c0)(param_1);
  return;
}



/* FUN_100276e8 at 100276e8 */

void FUN_100276e8(undefined4 param_1)

{
  (*(code *)&LAB_200006ec)(param_1);
  return;
}



/* FUN_100276f8 at 100276f8 */

void FUN_100276f8(undefined4 param_1)

{
  (*(code *)&LAB_200006c4)(param_1);
  return;
}



/* FUN_10027708 at 10027708 */

void FUN_10027708(undefined4 param_1)

{
  (*(code *)&LAB_200006d8)(param_1);
  return;
}



/* FUN_10027718 at 10027718 */

void FUN_10027718(undefined4 param_1)

{
  (*(code *)&LAB_20000714)(param_1);
  return;
}



/* FUN_10027728 at 10027728 */

void FUN_10027728(undefined4 param_1)

{
  (*(code *)&LAB_20000450)(param_1);
  return;
}



/* FUN_10027738 at 10027738 */

void FUN_10027738(undefined4 param_1)

{
  (*(code *)&LAB_200002c0)(param_1);
  return;
}



/* FUN_1002b420 at 1002b420 */

/* WARNING: Function: __gnu_thumb1_case_uqi replaced with injection: switch8_r0 */
/* WARNING (jumptable): Removing unreachable block (ram,0x1002b430) */
/* WARNING: Removing unreachable block (ram,0x1002b430) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_1002b420(undefined1 *param_1,undefined4 param_2)

{
  undefined1 uVar2;
  undefined1 uVar1;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 auStack_22 [2];
  undefined4 local_20;
  
  iVar3 = _DAT_20002414;
  switch(param_1[1]) {
  case 2:
    DAT_20003b30 = DAT_20003b30 & 0xfc;
    DAT_20003b31 = 0;
    goto LAB_1002b450;
  case 3:
    for (uVar6 = 0; uVar5 = (uint)DAT_20003b2d, uVar6 <= uVar5 + 5; uVar6 = uVar6 + 1 & 0xff) {
      if (uVar6 < uVar5) {
        puVar4 = (undefined *)(_DAT_20001770 + uVar6 * 0x20);
        if (puVar4 != (undefined *)0x0) goto LAB_1002b564;
      }
      else {
        puVar4 = &DAT_1002ab08 + (uVar6 - uVar5) * 0x20;
LAB_1002b564:
        if (*(code **)(puVar4 + 0x1c) != (code *)0x0) {
          (**(code **)(puVar4 + 0x1c))(*param_1,*(undefined4 *)(param_1 + 4));
        }
      }
    }
    if ((int)((uint)DAT_20003b30 << 0x1d) < 0) {
      DAT_20003b30 = DAT_20003b30 & 0xfb;
      FUN_1002bb08(auStack_22,0,10);
      iVar3 = _DAT_20002414;
      local_24 = *param_1;
      local_23 = 5;
      iVar7 = _DAT_20002414 + 0x14;
      FUN_1002bab8(iVar7);
      iVar3 = FUN_1002bb58(iVar3,&local_24);
      FUN_1002baf8(iVar7);
      if (iVar3 != 0) {
        FUN_1002bb38(local_24,local_23,param_2);
      }
    }
    if (-1 < (int)((uint)DAT_20003b33 << 0x1f)) {
      return;
    }
    FUN_1002bb08(auStack_22,0,10);
    iVar3 = _DAT_20002414;
    local_24 = *param_1;
    local_23 = 3;
    local_20 = *(undefined4 *)(param_1 + 4);
    iVar7 = _DAT_20002414 + 0x14;
    FUN_1002bab8(iVar7);
    iVar3 = FUN_1002bb58(iVar3,&local_24);
    FUN_1002baf8(iVar7);
    if (iVar3 == 0) {
      return;
    }
    uVar1 = local_24;
    uVar2 = local_23;
    goto LAB_1002b554;
  case 4:
    if (-1 < (int)((uint)DAT_20003b30 << 0x1f)) {
      return;
    }
    DAT_20003b30 = DAT_20003b30 | 4;
    break;
  case 5:
    if (-1 < (int)((uint)DAT_20003b30 << 0x1f)) {
      return;
    }
LAB_1002b450:
    DAT_20003b30 = DAT_20003b30 & 0xfb;
    break;
  case 6:
    DAT_20003c44 = DAT_20003c44 + '\x01';
  }
  iVar7 = _DAT_20002414 + 0x14;
  FUN_1002bab8(iVar7);
  iVar3 = FUN_1002bb58(iVar3,param_1);
  FUN_1002baf8(iVar7);
  if (iVar3 != 0) {
    uVar1 = *param_1;
    uVar2 = param_1[1];
LAB_1002b554:
    FUN_1002bb38(uVar1,uVar2,param_2);
  }
  return;
}



/* FUN_1002b7b0 at 1002b7b0 */

void FUN_1002b7b0(undefined4 *param_1)

{
  bool bVar1;
  uint uVar2;
  char cVar3;
  
  uVar2 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar2 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  do {
  } while (*(int *)*param_1 == 0);
  DataMemoryBarrier(0x1f);
  cVar3 = *(char *)((int)param_1 + 5) + -1;
  *(char *)((int)param_1 + 5) = cVar3;
  if (cVar3 == '\0') {
    *(undefined1 *)(param_1 + 1) = 0xff;
    DataMemoryBarrier(0x1f);
    *(undefined4 *)*param_1 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar2 & 1) == 1);
    }
  }
  else {
    DataMemoryBarrier(0x1f);
    *(undefined4 *)*param_1 = 0;
    bVar1 = (bool)isCurrentModePrivileged();
    if (bVar1) {
      enableIRQinterrupts((uVar2 & 1) == 1);
    }
  }
  return;
}



/* __gnu_thumb1_case_sqi at 1002ba24 */

/* WARNING: This is an inlined function */

void __gnu_thumb1_case_sqi(void)

{
  return;
}



/* __gnu_thumb1_case_uqi at 1002ba38 */

/* WARNING: This is an inlined function */

void __gnu_thumb1_case_uqi(void)

{
  return;
}



/* __gnu_thumb1_case_shi at 1002ba4c */

/* WARNING: This is an inlined function */

undefined8 __gnu_thumb1_case_shi(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}



/* __gnu_thumb1_case_uhi at 1002ba60 */

/* WARNING: This is an inlined function */

undefined8 __gnu_thumb1_case_uhi(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}



/* __gnu_thumb1_case_si at 1002ba74 */

/* WARNING: This is an inlined function */

undefined8 __gnu_thumb1_case_si(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}



/* FUN_1002bab8 at 1002bab8 */

void FUN_1002bab8(undefined4 param_1)

{
  FUN_1001a804(param_1);
  return;
}



/* FUN_1002baf8 at 1002baf8 */

void FUN_1002baf8(undefined4 param_1)

{
  FUN_1001a7f4(param_1);
  return;
}



/* FUN_1002bb08 at 1002bb08 */

void FUN_1002bb08(undefined4 param_1)

{
  FUN_1001f4c8(param_1);
  return;
}



/* FUN_1002bb38 at 1002bb38 */

void FUN_1002bb38(undefined4 param_1)

{
  (*(code *)&LAB_1001a8a4)(param_1);
  return;
}



/* FUN_1002bb58 at 1002bb58 */

void FUN_1002bb58(undefined4 param_1)

{
  FUN_1001a5fc(param_1);
  return;
}


