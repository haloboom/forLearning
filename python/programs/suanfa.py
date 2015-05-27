def turnOff_lastest(x):
    return (x&(x-1))
def turnOn_lastest(x):
    return (x|(x+1))
def turnOff_All_lastByteArry(x):
    return (x&(x+1))
def turnOn_All_lastByteArry(x):
    return (x|(x-1))
def turnOff_rightest1_othersOn(x):
    return ((~x)|(x-1))
def turnOn_rightest0_othersOff(x):
    return (~x&(x+1))
def turnOff_All_lastByteArry_othersOn(x):
    return (~x|(x+1))
def holdByteArry_rightest1_othersOff(x):
    return (x&(-x))
def turnOn_All_rightest1_leftByteArryOff(x):
    return (x^(x-1))
def turnOn_All_rightest0_leftByteArryOff(x):
    return (x^(x+1))
def turnOff_Continue1(x):
    return (((x&-x)+x)&x)
dict_fun={
        1:turnOff_lastest,
        2:turnOn_lastest,
        3:turnOff_All_lastByteArry,
        4:turnOn_All_lastByteArry,
        5:turnOff_rightest1_othersOn,
        6:turnOn_rightest0_othersOff,
        7:turnOff_All_lastByteArry_othersOn,
        8:holdByteArry_rightest1_othersOff,
        9:turnOn_All_rightest1_leftByteArryOff,
        10:turnOn_All_rightest0_leftByteArryOff,
        11:turnOff_Continue1
        }
if __name__=="__main__":
    print '*-----------------------------------------*'
    print '*             Program Menu:               *'
    print '*  1:turnOff_lastest                      *'
    print '*  2:turnOn_lastest                       *'
    print '*  3:turnOff_All_lastByteArry             *'
    print '*  4:turnOn_All_lastByteArry              *'
    print '*  5:turnOff_rightest1_othersOn           *'
    print '*  6:turnOn_rightest0_othersOff           *'
    print '*  7:turnOff_All_lastByteArry_othersOn    *'
    print '*  8:holdByteArry_rightest1_othersOff     *'
    print '*  9:turnOn_All_rightest1_leftByteArryOff *'
    print '* 10:turnOn_All_rightest0_leftByteArryOff *'
    print '* 11:turnOff_Continue1                    *'
    print '*-----------------------------------------*'
    choose=input("Enter Your Choose:")
    x=input("Then Enter x Value:")
    print ("The Program Return Value:%r"%bin(dict_fun[choose](x)))


