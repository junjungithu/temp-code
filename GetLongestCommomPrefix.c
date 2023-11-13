#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define CHAR8 char
#define UINTN int
#define UINT32 int
#define CONST const
#define STATIC static
#define MAX_CMD_LINE 256


CHAR8* LongestCommonPrefix (
  CONST UINTN StrsLen,
  CHAR8** Strs
)
{
  UINT32 MinLen = 1000000;
  STATIC CHAR8 Res[5001] = "";
  UINT32 Len = 0;
  UINT32 Flag = 0;
  UINT32 i = 0;
  UINT32 j = 0;
  CHAR8 ch = 0;

  if(StrsLen < 1) return Res;
  for (i = 0; i < StrsLen; i++)
  {
    Len = strlen(Strs[i]);
    MinLen = Len < MinLen ? Len : MinLen;
  }

  for (i = 0; i < MinLen; i++)
  {
    ch = Strs[0][i];

    for (j = 1; j < StrsLen; j++)
    {
      if (Strs[j][i] != ch)
      {
        Flag = 1;
        break;
      }
    }

    if (Flag)
    {
      break;
    }

    Res[i] = ch;
  }

  Res[i] = 0x00;
  return Res;
}

CHAR8* GetPrefix(UINT32 StrsLen, CHAR8** Strs)
{
    STATIC CHAR8 res[1024] = "";
    CHAR8 *pre = *Strs;
    UINT32 pre_i = 0;
    UINT32 i = 0, j = 0, len = 0;

    if(StrsLen < 1) return res;

    if(Strs == NULL) return res;

    for (i = 0; i< StrsLen; i++) {
        if ( NULL == *(Strs + i)) return res;
        
        printf("Strs[%d] = %s\n", i, *(Strs + i));
    }

    printf("pre = %s\n", pre);
    
    len = strlen(pre);
    if(pre == NULL || len < 1) return res;

printf("len = %d\n", len);
printf("pre[pre_%d] = %c\n", pre_i, pre[pre_i]);
    while(pre[pre_i] != '\0')
    {
        printf("pre[pre_%d] = %s\n", pre_i, pre[pre_i]);
        for(i = 1; Strs[i][pre_i] != '\0' && i < StrsLen; i++)
        {
            if(Strs[i][pre_i] != pre[pre_i])
            {
                res[pre_i] = '\0';
printf("res = %s\n", res);
                return res;
            }
        }
        if(Strs[i][pre_i] == '\0') break;
        
        res[pre_i] = pre[pre_i];
        printf("res[pre_%d] = %c\n", pre_i, res[pre_i]);
        pre_i++;
    }

printf("pre[pre_%d] = %s\n", pre_i, pre[pre_i]);
    res[pre_i] = '\0';
    printf("res = %s\n", res);
    return res;
}

int main(int Argc, char ** Argv)
{
    char av[3][32] = {"getopt", "getoptlong", "getoptlonglong"};
    int ac = 3;
    //char *commonprefix  = LongestCommonPrefix(Argc-1, (Argv + 1));
    char* commonprefix = GetPrefix(ac, av);

    printf("commonprefix = %s\n", commonprefix);
    return 0;
}