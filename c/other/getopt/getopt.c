#include<stdio.h>
#include<unistd.h>
int main(int argc,char **argv)
{
  short c;                     /*选项字符 */
  char *opt_arg;            /*选项参数字串 */

  while((c = getopt(argc, argv, "ngl:")) != -1)
  {
    switch(c)
    {
      case 'n':
        printf("option is n.\n");
        break;

      case 'g':
        printf("option is g.\n");
        break;

      case 'l':
        opt_arg = optarg;
        printf("the other option is %s\n", optarg);
        short n=0,flag=1,key=0;
        while(*(opt_arg+n++));
        n--;
        while(--n>=0)
        {
          printf("key:%d,flag:%d,n:%d\n",key,flag,n);
          key+=flag*(opt_arg[n]-'0');
          flag*=10;
        }
        printf("key:%d\n",key);
        while(key--) printf("Yes!\t");
        printf("\n");
        break;
    }
  }
  return 0;
}
