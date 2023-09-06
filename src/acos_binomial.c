#include "acos_binomial.h"

/// 0000555555555470 <+0>:     endbr64
/// 0x0000555555555474 <+4>:     mov    $0x1d,%r8d
/// 0x000055555555547a <+10>:    movaps %xmm0,%xmm2
/// 0x000055555555547d <+13>:    cmp    %r8d,%edi
/// 0x0000555555555480 <+16>:    cmovle %edi,%r8d
/// 0x0000555555555484 <+20>:    test   %edi,%edi
/// 0x0000555555555486 <+22>:    jle    0x5555555554e1 <acos_binomial+113>
/// 0x0000555555555488 <+24>:    mov    $0x3,%esi
/// 0x000055555555548d <+29>:    mov    $0x1,%ecx
/// 0x0000555555555492 <+34>:    mov    $0x2,%eax
/// 0x0000555555555497 <+39>:    mov    $0x1,%edx
/// 0x000055555555549c <+44>:    nopl   0x0(%rax)
/// 0x00005555555554a0 <+48>:    movaps %xmm0,%xmm1
/// 0x00005555555554a3 <+51>:    imul   %esi,%eax
/// 0x00005555555554a6 <+54>:    pxor   %xmm3,%xmm3
/// 0x00005555555554aa <+58>:    add    $0x1,%ecx
/// 0x00005555555554ad <+61>:    mulss  %xmm0,%xmm1
/// 0x00005555555554b1 <+65>:    lea    0x2(%rdx),%edi
/// 0x00005555555554b4 <+68>:    add    $0x2,%esi
/// 0x00005555555554b7 <+71>:    cvtsi2ss %eax,%xmm3
/// 0x00005555555554bb <+75>:    mulss  %xmm1,%xmm0
/// 0x00005555555554bf <+79>:    pxor   %xmm1,%xmm1
/// 0x00005555555554c3 <+83>:    cvtsi2ss %edx,%xmm1
/// 0x00005555555554c7 <+87>:    imul   %edi,%edx
/// 0x00005555555554ca <+90>:    lea    0x2(%rax),%edi
/// 0x00005555555554cd <+93>:    imul   %edi,%eax
/// 0x00005555555554d0 <+96>:    mulss  %xmm0,%xmm1
/// 0x00005555555554d4 <+100>:   divss  %xmm3,%xmm1
/// 0x00005555555554d8 <+104>:   addss  %xmm1,%xmm2
/// 0x00005555555554dc <+108>:   cmp    %ecx,%r8d
/// 0x00005555555554df <+111>:   jge    0x5555555554a0 <acos_binomial+48>
/// 0x00005555555554e1 <+113>:   movsd  0xb1f(%rip),%xmm0        # 0x555555556008
/// 0x00005555555554e9 <+121>:   cvtss2sd %xmm2,%xmm2
/// 0x00005555555554ed <+125>:   subsd  %xmm2,%xmm0
/// 0x00005555555554f1 <+129>:   cvtsd2ss %xmm0,%xmm0
/// 0x00005555555554f5 <+133>:   ret
float acos_binomial(float x, int rounds)
{
  float a = x;
  float z = x;
  int n = 1;
  int d = 2;
  rounds = (rounds > 29) ? 29 : rounds;
  for (int i = 1; i <= rounds; i++) {
    d *= ((i << 1) + 1);
    z *= z * z;
    a += (float)(n * z) / (float)(d);
    n *= n + 2;
    d *= d + 2;
  }
  return M_PI_2 - a;
}
