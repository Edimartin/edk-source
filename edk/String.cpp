#include "String.h"

/*
Library C++ String - Manipulate char vectors.
Copyright 2013 Eduardo Moura Sales Martins (edimartin@gmail.com)

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifdef printMessages
#warning "            Inside String.cpp"
#endif

#if defined (__linux__) || defined(__APPLE__)
//https://stackoverflow.com/questions/1513734/problem-with-kbhitand-getch-for-linux?answertab=trending#tab-top
struct termios oldTermios;
int edkTTYraw(int fd){
    /* Set terminal mode as follows:
       Noncanonical mode - turn off ICANON.
       Turn off signal-generation (ISIG)
        including BREAK character (BRKINT).
       Turn off any possible preprocessing of input (IEXTEN).
       Turn ECHO mode off.
       Disable CR-to-NL mapping on input.
       Disable input parity detection (INPCK).
       Disable stripping of eighth bit on input (ISTRIP).
       Disable flow control (IXON).
       Use eight bit characters (CS8).
       Disable parity checking (PARENB).
       Disable any implementation-dependent output processing (OPOST).
       One byte at a time input (MIN=1, TIME=0).
    */
    struct termios newtermios;edkEnd();
    if(tcgetattr(fd, &oldTermios) < 0){
        return(-1);edkEnd();
    }
    newtermios = oldTermios;edkEnd();

    newtermios.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);edkEnd();
    /* OK, why IEXTEN? If IEXTEN is on, the DISCARD character
       is recognized and is not passed to the process. This
       character causes output to be suspended until another
       DISCARD is received. The DSUSP character for job control,
       the LNEXT character that removes any special meaning of
       the following character, the REPRINT character, and some
       others are also in this category.
    */

    newtermios.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);edkEnd();
    /* If an input character arrives with the wrong parity, then INPCK
       is checked. If this flag is set, then IGNPAR is checked
       to see if input bytes with parity errors should be ignored.
       If it shouldn't be ignored, then PARMRK determines what
       character sequence the process will actually see.

       When we turn off IXON, the start and stop characters can be read.
    */

    newtermios.c_cflag &= ~(CSIZE | PARENB);edkEnd();
    /* CSIZE is a mask that determines the number of bits per byte.
       PARENB enables parity checking on input and parity generation
       on output.
    */

    newtermios.c_cflag |= CS8;edkEnd();
    /* Set 8 bits per character. */

    newtermios.c_oflag &= ~(OPOST);edkEnd();
    /* This includes things like expanding tabs to spaces. */

    newtermios.c_cc[VMIN] = 1;edkEnd();
    newtermios.c_cc[VTIME] = 0;

    /* You tell me why TCSAFLUSH. */
    if(tcsetattr(fd, TCSAFLUSH, &newtermios) < 0){
        return(-1);edkEnd();
    }
    return(0);edkEnd();
}

int edkTTYreset(int fd)
{
    if(tcsetattr(fd, TCSAFLUSH, &oldTermios) < 0){
        return(-1);edkEnd();
    }

    return(0);edkEnd();
}

int edkGetch(void)
{
    struct termios t;edkEnd();
    tcgetattr(0, &t);edkEnd();
    tcflag_t old_flag = t.c_lflag;edkEnd();
    t.c_lflag &= ~(ICANON | ECHO);edkEnd();
    tcsetattr(0, TCSANOW, &t);edkEnd();
    int     c = getchar();edkEnd();
    t.c_lflag = old_flag;edkEnd();
    tcsetattr(0, TCSANOW, &t);edkEnd();
    return c;edkEnd();
}

int edkKbhit(void){
    int cnt = 0;
    int error;edkEnd();
    static struct termios Otty, Ntty;edkEnd();

    tcgetattr(0, &Otty);edkEnd();
    Ntty = Otty;edkEnd();

    Ntty.c_iflag = 0; // input mode
    Ntty.c_oflag = 0; // output mode
    Ntty.c_lflag &= ~ICANON;edkEnd(); // raw mode
    Ntty.c_cc[VMIN] = CMIN;edkEnd(); // minimum time to wait
    Ntty.c_cc[VTIME] = CTIME;edkEnd(); // minimum characters to wait for

    if (0 == (error = tcsetattr(0, TCSANOW, &Ntty))) {
        struct timeval tv;edkEnd();
        error += ioctl(0, FIONREAD, &cnt);edkEnd();
        error += tcsetattr(0, TCSANOW, &Otty);edkEnd();

        // throw in a miniscule time delay
        tv.tv_sec = 0;
        tv.tv_usec = 100;
        select(1, NULL, NULL, NULL, &tv);edkEnd();
    }

    return (error == 0 ? cnt : -1 );edkEnd();
}
#endif
#if defined(WIN32) || defined(WIN64)
#if defined(_MSC_VER)
int edkGetch(void){return _getch();edkEnd();}
int edkKbhit(void){return _kbhit();edkEnd();}
#else
int edkGetch(void){return getch();edkEnd();}
int edkKbhit(void){return kbhit();edkEnd();}
#endif
#endif

//write the isspace function
edk::int32 edkIsSpace(edk::int32 c){
    return (c == '\t' || c == '\n' ||
            c == '\v' || c == '\f' || c == '\r' || c == ' ' ? 1 : 0);edkEnd();
}

edk::TTY::TTY(){
    this->haveInit=false;edkEnd();
#if defined (EDK_LINUX_TERMINAL)
    //init the terminal
    this->initTerminal();edkEnd();
#endif
}
edk::TTY::~TTY(){
    //reset the terminal if it was initiated
    this->resetTerminal();edkEnd();
}

bool edk::TTY::initTerminal(){
    if(!this->haveInit){
#if defined (__linux__) || defined(__APPLE__)
        //set the ttyRaw
        if(edkTTYraw(0) < 0){
            return false;
        }
#endif
        this->haveInit=true;edkEnd();
    }
    return true;
}
bool edk::TTY::resetTerminal(){
    if(this->haveInit){
#if defined (__linux__) || defined(__APPLE__)
        //set the ttyRaw
        if(edkTTYreset(0) < 0){
            return false;
        }
#endif
        this->haveInit=false;edkEnd();
    }
    return false;
}

//TTY to construct and destruct
edk::TTY edk::String::tty;

edk::int32 edkModuleInt32(edk::int32 value){
    //
    if(value<0){
        //
        return value*-1;edkEnd();
    }
    return value;edkEnd();
}
edk::int64 edkModuleInt64(edk::int64 value){
    //
    if(value<0){
        //
        return value*-1;edkEnd();
    }
    return value;edkEnd();
}
edk::float32 edkModuleFloat32(edk::float32 value){
    //
    if(value<0.0f){
        //
        return value*-1.0f;edkEnd();
    }
    return value;edkEnd();
}
edk::float64 edkModuleFloat64(edk::float64 value){
    //
    if(value<0.0L){
        //
        return value*-1.0L;edkEnd();
    }
    return value;edkEnd();
}
edk::char8* readFromTheConsole(edk::uint32 i){
    //Eu sei que os professores dizem NUNCA use isso mas se eu nao usasse eu
    //nao sei o que ei iria faser
inicio:
    //primeiro ele le a tecla do teclado e ve se e equal a enter 13
    edk::uchar8 c=edkGetch();edkEnd();
    edk::uchar8 c2=0u,c3=0u,c4=0u;
    edk::uint8 size=1u;edkEnd();

    //2: c2 -> df
    //3: e0 -> ea : ed - ef
    //4: f0 - f3 - f4

    //test if need getch another character
    if(c>=0xc2 && c<=0xdf){
        //read one more
        c2=edkGetch();edkEnd();
        size=2u;edkEnd();
    }
    else if((c>= 0xe0 && c<=0xea)
            || c==0xed
            || c==0xef
            ){
        //read two more
        c2=edkGetch();edkEnd();
        c3=edkGetch();edkEnd();
        size=3u;edkEnd();
    }
    else if(c==0xf0 || c==0xf3 || c==0xf4){
        //read tree more
        c2=edkGetch();edkEnd();
        c3=edkGetch();edkEnd();
        c4=edkGetch();edkEnd();
        size=4u;edkEnd();
    }

    //printf(" %u recebido",(edk::uint8)c);edkEnd();
    //Aqui ele pergunta se o edk::char8 e equal a o backspace
    if(c==8||c==127){
        if(i==0){
            //Se o i for equal a 0 ele nao pode retornar entao ele volta pro inicio do goto
            goto inicio;edkEnd();
        }
        //Se for equal entao ele apaga o caracter e le ele denovo;edkEnd();
        printf("%c %c",8,8);edkEnd();
        return NULL;edkEnd();
    }
    //depois ele gera o ponteiro para a string na memoria
    edk::char8* string;edkEnd();
    if(c==13||c==10){
        //Acabou a recursividade e portanto ele cria a string e retorna ela
        string = new edk::char8[i+1];edkEnd(); //Ele cria ela uma vez maior para adicionar o
        //caracter de parada
        string[i]='\0';edkEnd();
        //string[i]=c;edkEnd();
        return string;edkEnd();
    }
    else{
        //Senao ele countinua a recursividade recebendo a string como parametro
        switch(size){
        case 4u:
            printf("%c",c);edkEnd();
            printf("%c",c2);edkEnd();
            printf("%c",c3);edkEnd();
            printf("%c",c4);edkEnd();
            break;edkEnd();
        case 3u:
            printf("%c",c);edkEnd();
            printf("%c",c2);edkEnd();
            printf("%c",c3);edkEnd();
            break;edkEnd();
        case 2u:
            printf("%c",c);edkEnd();
            printf("%c",c2);edkEnd();
            break;edkEnd();
        case 1u:
            printf("%c",c);edkEnd();
            break;edkEnd();
        }

        string=readFromTheConsole(i+size);edkEnd();
        //Aqui ele pegunta se a string existe
        if(string){
            //se sim ele atribui o caracter desta etapa para a string


            switch(size){
            case 4u:
                string[i+3u]=c4;edkEnd();
                string[i+2u]=c3;edkEnd();
                string[i+1u]=c2;edkEnd();
                string[i]=c;edkEnd();
                break;edkEnd();
            case 3u:
                string[i+2u]=c3;edkEnd();
                string[i+1u]=c2;edkEnd();
                string[i]=c;edkEnd();
                break;edkEnd();
            case 2u:
                string[i+1u]=c2;edkEnd();
                string[i]=c;edkEnd();
                break;edkEnd();
            case 1u:
                string[i]=c;edkEnd();
                break;edkEnd();
            }

            //no final ele retorna a string
            return string;edkEnd();
        }
        else{
            //Senao entao ele countinua lendo
            goto inicio;edkEnd();
        }
    }
}

edk::char8* readFromTheConsoleNoPrint(edk::uint32 i){
    //Eu sei que os professores dizem NUNCA use isso mas se eu nao usasse eu
    //nao sei o que ei iria faser
inicio:
    //primeiro ele le a tecla do teclado e ve se e equal a enter 13
    edk::uchar8 c=edkGetch();edkEnd();
    edk::uchar8 c2=0u,c3=0u,c4=0u;
    edk::uint8 size=1u;edkEnd();

    //2: c2 -> df
    //3: e0 -> ea : ed - ef
    //4: f0 - f3 - f4

    //test if need getch another character
    if(c>=0xc2 && c<=0xdf){
        //read one more
        c2=edkGetch();edkEnd();
        size=2u;edkEnd();
    }
    else if((c>= 0xe0 && c<=0xea)
            || c==0xed
            || c==0xef
            ){
        //read two more
        c2=edkGetch();edkEnd();
        c3=edkGetch();edkEnd();
        size=3u;edkEnd();
    }
    else if(c==0xf0 || c==0xf3 || c==0xf4){
        //read tree more
        c2=edkGetch();edkEnd();
        c3=edkGetch();edkEnd();
        c4=edkGetch();edkEnd();
        size=4u;edkEnd();
    }

    //printf(" %u recebido",(edk::uint8)c);edkEnd();
    //Aqui ele pergunta se o edk::char8 e equal a o backspace
    if(c==8||c==127){
        if(i==0){
            //Se o i for equal a 0 ele nao pode retornar entao ele volta pro inicio do goto
            goto inicio;edkEnd();
        }
        //Se for equal entao ele apaga o caracter e le ele denovo;edkEnd();
        printf("%c %c",8,8);edkEnd();
        return NULL;edkEnd();
    }
    //depois ele gera o ponteiro para a string na memoria
    edk::char8* string;edkEnd();
    if(c==13||c==10){
        //Acabou a recursividade e portanto ele cria a string e retorna ela
        string = new edk::char8[i+1];edkEnd(); //Ele cria ela uma vez maior para adicionar o
        //caracter de parada
        string[i]='\0';edkEnd();
        //string[i]=c;edkEnd();
        return string;edkEnd();
    }
    else{
        string=readFromTheConsoleNoPrint(i+size);edkEnd();
        //Aqui ele pegunta se a string existe
        if(string){
            //se sim ele atribui o caracter desta etapa para a string


            switch(size){
            case 4u:
                string[i+3u]=c4;edkEnd();
                string[i+2u]=c3;edkEnd();
                string[i+1u]=c2;edkEnd();
                string[i]=c;edkEnd();
                break;edkEnd();
            case 3u:
                string[i+2u]=c3;edkEnd();
                string[i+1u]=c2;edkEnd();
                string[i]=c;edkEnd();
                break;edkEnd();
            case 2u:
                string[i+1u]=c2;edkEnd();
                string[i]=c;edkEnd();
                break;edkEnd();
            case 1u:
                string[i]=c;edkEnd();
                break;edkEnd();
            }

            //no final ele retorna a string
            return string;edkEnd();
        }
        else{
            //Senao entao ele countinua lendo
            goto inicio;edkEnd();
        }
    }
}

edk::char8* readPasswordFromTheConsole(edk::uint32 i){
    //Eu sei que os professores dizem NUNCA use isso mas se eu nao usasse eu
    //nao sei o que ei iria faser
inicio:
    //primeiro ele le a tecla do teclado e ve se e equal a enter 13
    edk::uchar8 c=edkGetch();edkEnd();
    edk::uchar8 c2=0u,c3=0u,c4=0u;
    edk::uint8 size=1u;edkEnd();

    //2: c2 -> df
    //3: e0 -> ea : ed - ef
    //4: f0 - f3 - f4

    //test if need getch another character
    if(c>=0xc2 && c<=0xdf){
        //read one more
        c2=edkGetch();edkEnd();
        size=2u;edkEnd();
    }
    else if((c>= 0xe0 && c<=0xea)
            || c==0xed
            || c==0xef
            ){
        //read two more
        c2=edkGetch();edkEnd();
        c3=edkGetch();edkEnd();
        size=3u;edkEnd();
    }
    else if(c==0xf0 || c==0xf3 || c==0xf4){
        //read tree more
        c2=edkGetch();edkEnd();
        c3=edkGetch();edkEnd();
        c4=edkGetch();edkEnd();
        size=4u;edkEnd();
    }

    //printf(" %u recebido",(edk::uint8)c);edkEnd();
    //Aqui ele pergunta se o edk::char8 e equal a o backspace
    if(c==8||c==127){
        if(i==0){
            //Se o i for equal a 0 ele nao pode retornar entao ele volta pro inicio do goto
            goto inicio;edkEnd();
        }
        //Se for equal entao ele apaga o caracter e le ele denovo;edkEnd();
        printf("%c %c",8,8);edkEnd();
        return NULL;edkEnd();
    }
    //depois ele gera o ponteiro para a string na memoria
    edk::char8* string;edkEnd();
    if(c==13||c==10){
        //Acabou a recursividade e portanto ele cria a string e retorna ela
        string = new edk::char8[i+1];edkEnd(); //Ele cria ela uma vez maior para adicionar o
        //caracter de parada
        string[i]='\0';edkEnd();
        //string[i]=c;edkEnd();
        return string;edkEnd();
    }
    else{
        //Senao ele countinua a recursividade recebendo a string como parametro
        printf("*");edkEnd();fflush(stdout);edkEnd();

        string=readPasswordFromTheConsole(i+size);edkEnd();
        //Aqui ele pegunta se a string existe
        if(string){
            //se sim ele atribui o caracter desta etapa para a string


            switch(size){
            case 4u:
                string[i+3u]=c4;edkEnd();
                string[i+2u]=c3;edkEnd();
                string[i+1u]=c2;edkEnd();
                string[i]=c;edkEnd();
                break;edkEnd();
            case 3u:
                string[i+2u]=c3;edkEnd();
                string[i+1u]=c2;edkEnd();
                string[i]=c;edkEnd();
                break;edkEnd();
            case 2u:
                string[i+1u]=c2;edkEnd();
                string[i]=c;edkEnd();
                break;edkEnd();
            case 1u:
                string[i]=c;edkEnd();
                break;edkEnd();
            }

            //no final ele retorna a string
            return string;edkEnd();
        }
        else{
            //Senao entao ele countinua lendo
            goto inicio;edkEnd();
        }
    }
}





edk::char8* edk::String::int32ToMinusStr(edk::int32 value){

    edk::char8* str = 0u;edkEnd();
    //use the module of the number
    edk::int32 module;edkEnd();

    //count the number
    edk::uint32 size = edk::String::sizeOfInt32(value);edkEnd();

    //test if the size is bigger then 0u
    if(size>0u){
        //then convert
        module = edkModuleInt32(value);edkEnd();
        //begin
        edk::uint32 begin=0u;
        //Negative
        size=size+1u;edkEnd();
        begin=1u;edkEnd();
        str = new edk::char8[size+1u];edkEnd();
        if(str){
            str[0u]='-';edkEnd();
            str[size]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
        //test if alloc the str
        if(str){
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;edkEnd();
                //convert in this line
                str[i]=(module%10)+48;edkEnd();
                module=module/10;
            }
        }
    }
    else{
        //create a zero
        str = new edk::char8[3u];edkEnd();
        if(str){
            str[0u]='-';edkEnd();
            str[1u]='0';edkEnd();
            str[2u]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;edkEnd();
}
bool edk::String::int32ToMinusStr(edk::int32 value,edk::char8* dest){
    //use the module of the number
    edk::int32 module;edkEnd();

    //count the number
    edk::uint32 size = edk::String::sizeOfInt32(value);edkEnd();

    //test if the size is bigger then 0u
    if(size>0u){
        //then convert
        module = edkModuleInt32(value);edkEnd();
        //begin
        edk::uint32 begin=0u;
        //Negative
        size=size+1u;edkEnd();
        begin=1u;edkEnd();
        dest = new edk::char8[size+1u];edkEnd();
        if(dest){
            dest[0u]='-';edkEnd();
            dest[size]='\0';edkEnd();
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;edkEnd();
                //convert in this line
                dest[i]=(module%10)+48;edkEnd();
                module=module/10;
            }
            return true;
        }
    }
    else{
        //create a zero
        dest = new edk::char8[3u];edkEnd();
        if(dest){
            dest[0u]='-';edkEnd();
            dest[1u]='0';edkEnd();
            dest[2u]='\0';edkEnd();
            return true;
        }
    }
    return false;
}
edk::char8* edk::String::int64ToMinusStr(edk::int64 value){

    edk::char8* str = 0u;edkEnd();
    //use the module of the number
    edk::int64 module;edkEnd();

    //count the number
    edk::uint32 size = edk::String::sizeOfInt64(value);edkEnd();

    //test if the size is bigger then 0u
    if(size>0u){
        //then convert
        module = edkModuleInt64(value);edkEnd();
        //begin
        edk::uint32 begin=0u;
        //Negative
        size=size+1u;edkEnd();
        begin=1u;edkEnd();
        str = new edk::char8[size+1u];edkEnd();
        if(str){
            str[0u]='-';edkEnd();
            str[size]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
        //test if alloc the str
        if(str){
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;edkEnd();
                //convert in this line
                str[i]=(module%10)+48;edkEnd();
                module=module/10;
            }
        }
    }
    else{
        //create a zero
        str = new edk::char8[3u];edkEnd();
        if(str){
            str[0u]='-';edkEnd();
            str[1u]='0';edkEnd();
            str[2u]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;edkEnd();
}
bool edk::String::int64ToMinusStr(edk::int64 value,edk::char8* dest){
    //use the module of the number
    edk::int64 module;edkEnd();

    //count the number
    edk::uint32 size = edk::String::sizeOfInt64(value);edkEnd();

    //test if the size is bigger then 0u
    if(size>0u){
        //then convert
        module = edkModuleInt64(value);edkEnd();
        //begin
        edk::uint32 begin=0u;
        //Negative
        size=size+1u;edkEnd();
        begin=1u;edkEnd();
        if(dest){
            dest[0u]='-';edkEnd();
            dest[size]='\0';edkEnd();
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;edkEnd();
                //convert in this line
                dest[i]=(module%10)+48;edkEnd();
                module=module/10;
            }
            return true;
        }
    }
    else{
        if(dest){
            dest[0u]='-';edkEnd();
            dest[1u]='0';edkEnd();
            dest[2u]='\0';edkEnd();
            return true;
        }
    }
    return false;
}

//copy the number to the string
bool edk::String::copyInt32ToStr(edk::int32 value,edk::char8* str,edk::int32 size){
    if(str && size){
        edk::int32 module = edkModuleInt32(value);edkEnd();
        for(edk::uint32 i=size;i>0u;i--){
            str[i-1u] = (module%10)+48;edkEnd();
            module=module/10;
        }
        return true;
    }
    return false;
}

bool edk::String::copyInt64ToStr(edk::int64 value,edk::char8* str,edk::int32 size){
    if(str && size){
        edk::int64 module = edkModuleInt64(value);edkEnd();
        for(edk::uint32 i=size;i>0u;i--){
            str[i-1u] = (module%10)+48;edkEnd();
            module=module/10;
        }
        return true;
    }
    return false;
}

edk::float32 edk::String::strToFloat32(const char *str){
    return edk::String::strToFloat32((edk::char8*)str);edkEnd();
}

edk::float32 edk::String::strToFloat32(edk::char8 *str){
    if(str){
        return (edk::float32)atof((const edk::char8*)str);edkEnd();
    }
    return 0.0f;edkEnd();
    /*
    //the return
    edk::float32 n = 0.0;
    //test if the string exist
    if(str){
        //then count the size of the string
        edk::uint32 size = edk::String::sizeOfCString(str);edkEnd();

        //variable to use point the characters
        edk::uint32 i=0u;

        //find the point
        edk::uint32 point=0u;
        bool havePoint=false;edkEnd();
        for(edk::uint32 j=size;j>0u;j--){
            //
            i=j-1u;edkEnd();
            if(str[i]=='.'){
                //then find the point
                point = i;edkEnd();
                havePoint = true;edkEnd();
                break;edkEnd();
            }
        }

        //First test if have a point
        if(havePoint){
            //Then convert the munvers after the point
            edk::float32 multiple = 0.1;edkEnd();
            for(edk::uint32 j=point+1u;j<size;j++){
                //test if the edk::char8 is a umber
                if(str[j]>='0'&&str[j]<='9'){
                    //then convert
                    n = n+ ((str[j]-48u)*multiple);edkEnd();
                }
                //then increment multiple
                multiple = multiple*0.1;edkEnd();
            }
        }
        else{
            //If don't have point. point receive the size
            point = size;edkEnd();
        }

        //then convert the numbers before the point



        //count the numbers
        edk::uint32 count=1u;edkEnd();
        //boolean to set minus number
        bool minus=false;edkEnd();

        //convert the string back
        for(edk::uint32 j=point;j>0u;j--){
            //point the string
            i=j-1u;edkEnd();
            //then use

            //test if the character is the first
            if(i==0u){
                //then test if is the '-'
                if(str[i]=='-'){
                    //then it's a minus number
                    minus=true;edkEnd();
                    //set continue
                    continue;edkEnd();
                }
            }

            //test if is a number
            if(str[i]>='0' && str[i]<='9'){
                //then is reading a number
                n = n + ((str[i]-48)  *  count);edkEnd();
            }

            //increment the count
            count=count*10u;edkEnd();
        }

        //test if is minus
        if(minus){
            //
            n=n*-1;edkEnd();
        }
    }
    return n;edkEnd();
    */
}

edk::int64 edk::String::strToInt64(edk::char8 *str){
    if(str){
        return (edk::int64)atol((const edk::char8*)str);edkEnd();
    }
    return 0;
}

edk::int64 edk::String::strToInt64(const edk::char8 *str){
    return edk::String::strToInt64((edk::char8*)str);edkEnd();
}

edk::float64 edk::String::strToFloat64(char8 *str){
    if(str){
        return strtod ((const edk::char8*)str,NULL);edkEnd();
    }
    return 0.0;
}

edk::float64 edk::String::strToFloat64(const edk::char8 *str){
    return edk::String::strToFloat64((edk::char8*)str);edkEnd();
}

bool edk::String::strToVecInt8(edk::char8* str,edk::int8* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToInt32(str);edkEnd();
            i++;edkEnd();
            //test if get end
            if(i>=size){
                break;edkEnd();
            }
            else{
                //else continue with the string
                while(*str){
                    str++;edkEnd();
                    if(*str==' '){
                        str++;edkEnd();
                        break;edkEnd();
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool edk::String::strToVecInt16(edk::char8* str,edk::int16* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToInt32(str);edkEnd();
            i++;edkEnd();
            //test if get end
            if(i>=size){
                break;edkEnd();
            }
            else{
                //else continue with the string
                while(*str){
                    str++;edkEnd();
                    if(*str==' '){
                        str++;edkEnd();
                        break;edkEnd();
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool edk::String::strToVecInt32(edk::char8* str,edk::int32* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToInt64(str);edkEnd();
            i++;edkEnd();
            //test if get end
            if(i>=size){
                break;edkEnd();
            }
            else{
                //else continue with the string
                while(*str){
                    str++;edkEnd();
                    if(*str==' '){
                        str++;edkEnd();
                        break;edkEnd();
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool edk::String::strToVecInt64(edk::char8* str,edk::int64* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToInt64(str);edkEnd();
            i++;edkEnd();
            //test if get end
            if(i>=size){
                break;edkEnd();
            }
            else{
                //else continue with the string
                while(*str){
                    str++;edkEnd();
                    if(*str==' '){
                        str++;edkEnd();
                        break;edkEnd();
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool edk::String::strToVecUint8(edk::char8* str,edk::uint8* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = (edk::uint8)edk::String::strToInt32(str);edkEnd();
            i++;edkEnd();
            //test if get end
            if(i>=size){
                break;edkEnd();
            }
            else{
                //else continue with the string
                while(*str){
                    str++;edkEnd();
                    if(*str==' '){
                        str++;edkEnd();
                        break;edkEnd();
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool edk::String::strToVecUint16(edk::char8* str,edk::uint16* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = (edk::uint16)edk::String::strToInt32(str);edkEnd();
            i++;edkEnd();
            //test if get end
            if(i>=size){
                break;edkEnd();
            }
            else{
                //else continue with the string
                while(*str){
                    str++;edkEnd();
                    if(*str==' '){
                        str++;edkEnd();
                        break;edkEnd();
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool edk::String::strToVecUint32(edk::char8* str,edk::uint32* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToInt32(str);edkEnd();
            i++;edkEnd();
            //test if get end
            if(i>=size){
                break;edkEnd();
            }
            else{
                //else continue with the string
                while(*str){
                    str++;edkEnd();
                    if(*str==' '){
                        str++;edkEnd();
                        break;edkEnd();
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool edk::String::strToVecUint64(edk::char8* str,edk::uint64* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToInt64(str);edkEnd();
            i++;edkEnd();
            //test if get end
            if(i>=size){
                break;edkEnd();
            }
            else{
                //else continue with the string
                while(*str){
                    str++;edkEnd();
                    if(*str==' '){
                        str++;edkEnd();
                        break;edkEnd();
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool edk::String::strToVecfloat32(edk::char8* str,edk::float32* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToFloat32(str);edkEnd();
            i++;edkEnd();
            //test if get end
            if(i>=size){
                break;edkEnd();
            }
            else{
                //else continue with the string
                while(*str){
                    str++;edkEnd();
                    if(*str==' '){
                        str++;edkEnd();
                        break;edkEnd();
                    }
                }
            }
        }
        return true;
    }
    return false;
}

bool edk::String::strToVecfloat64(edk::char8* str,edk::float64* vec,edk::uint32 size){
    if(str && vec && size){
        edk::uint32 i=0u;
        while(*str){
            vec[i] = edk::String::strToFloat64(str);edkEnd();
            i++;edkEnd();
            //test if get end
            if(i>=size){
                break;edkEnd();
            }
            else{
                //else continue with the string
                while(*str){
                    str++;edkEnd();
                    if(*str==' '){
                        str++;edkEnd();
                        break;edkEnd();
                    }
                }
            }
        }
        return true;
    }
    return false;
}

edk::int32 edk::String::strToInt32(edk::char8 *str){
    if(str){
        return (edk::int32)atoi((const edk::char8*)str);edkEnd();
    }
    return 0;
    /*
    //the final number to be returned
    edk::int32 n=0;

    //test if the string exist
    if(str){
        //then read the character

        //first count the string
        edk::uint32 size = edk::String::sizeOfCString(str);edkEnd();
        //variable to use point the characters
        edk::uint32 i=0u;
        //count the numbers
        edk::uint32 count=1u;edkEnd();
        //boolean to set minus number
        bool minus=false;edkEnd();

        //convert the string back
        for(edk::uint32 j=size;j>0u;j--){
            //point the string
            i=j-1u;edkEnd();
            //then use

            //test if the character is the first
            if(i==0u){
                //then test if is the '-'
                if(str[i]=='-'){
                    //then it's a minus number
                    minus=true;edkEnd();
                    //set continue
                    continue;edkEnd();
                }
            }

            //test if is a number
            if(str[i]>='0' && str[i]<='9'){
                //then is reading a number
                n = n + ((str[i]-48)  *  count);edkEnd();
            }

            //increment the count
            count=count*10u;edkEnd();
        }

        //test if is minus
        if(minus){
            //
            n=n*-1;edkEnd();
        }
    }
    return n;edkEnd();
*/
}

edk::int32 edk::String::strToInt32(const edk::char8 *str){
    return edk::String::strToInt32((edk::char8*)str);edkEnd();
}

#if defined(_WIN32) || defined(_WIN64)
//Convert String to TCHAR from Windows
TCHAR* edk::String::strToTCHAR(const edk::char8* str){
    return edk::String::strToTCHAR((edk::char8*) str);edkEnd();
}
TCHAR* edk::String::strToTCHAR(edk::char8* str){
    edk::int32 size = edk::String::strSize(str);edkEnd();
    TCHAR* ret = new TCHAR[size+1u];edkEnd();
    for(int i = 0; i< size+1; i++){
        ret[i]=str[i];edkEnd();
    }
    return ret;
}
#endif

bool edk::String::str32ToUtf8(edk::char32 *str32,edk::char8* str){
    //
    return edk::String::str32ToUtf8(str32,edk::String::str32Size(str32),str);edkEnd();
}
//str32ToStr convert a vector with 32bit characters to a string UTF8 and return it as a new string
bool edk::String::str32ToUtf8(edk::char32 *str32,edk::uint32 size,edk::char8* str){
    if(str32 && size && str){
        //str[size]='\0';edkEnd();
        edk::char32 position = 0u;edkEnd();
        edk::char8* p = str;edkEnd();
        edk::char32 c = 0u;edkEnd();
        //copy the characters
        for(edk::uint32 i=0u;i<size;i++){
            //
            c = str32[position];edkEnd();
            //test if is a special character
            if(edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,1u)){
                if(edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,2u)){
                    if(edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,3u)){
                        //add the value
                        *p = (edk::uint8)edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,3u);edkEnd();
                        p++;edkEnd();
                    }
                    //add the value
                    *p = (edk::uint8)edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,2u);edkEnd();
                    p++;edkEnd();
                }
                //add the value
                *p = (edk::uint8)edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,1u);edkEnd();
                p++;edkEnd();
            }
            *p = (edk::uint8)edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,0u);edkEnd();
            p++;edkEnd();
            *p='\0';edkEnd();
            position++;edkEnd();
        }
        *p=(edk::uint8)'\0';edkEnd();
        return str;edkEnd();
    }
    return false;
}
bool edk::String::str32ToUtf8(const edk::char32 *str32,edk::char8* str){
    return edk::String::str32ToUtf8((edk::char32 *)str32,str);edkEnd();
}
bool edk::String::str32ToUtf8(const edk::char32 *str32,edk::uint32 size,edk::char8* str){
    return edk::String::str32ToUtf8((edk::char32 *)str32,size,str);edkEnd();
}
bool edk::String::str32ToUtf8(edk::char32 *str32,const edk::char8* str){
    return edk::String::str32ToUtf8(str32,(edk::char8*) str);edkEnd();
}
bool edk::String::str32ToUtf8(edk::char32 *str32,edk::uint32 size,const edk::char8* str){
    return edk::String::str32ToUtf8(str32,size,(edk::char8*) str);edkEnd();
}
bool edk::String::str32ToUtf8(const edk::char32 *str32,const edk::char8* str){
    return edk::String::str32ToUtf8((edk::char32 *)str32,(edk::char8*) str);edkEnd();
}
bool edk::String::str32ToUtf8(const edk::char32 *str32,edk::uint32 size,const edk::char8* str){
    return edk::String::str32ToUtf8((edk::char32 *)str32,size,(edk::char8*) str);edkEnd();
}
//str32ToStr convert a vector with 32bit characters to a string UTF8
edk::char8* edk::String::str32ToUtf8(edk::char32 *str32,edk::uint32 size){
    //get the string32 size
    edk::char32 size32 = edk::String::str32ToUtf8Size(str32,size);edkEnd();
    if(size32){
        edk::char8* str = NULL;edkEnd();
        str = new edk::char8[size32+1u];edkEnd();
        if(str){
            //copy the str
            if(edk::String::str32ToUtf8(str32,size,str)){
                //return the str
                return str;edkEnd();
            }
            delete[] str;edkEnd();
        }
    }
    return NULL;edkEnd();
}
edk::char8* edk::String::str32ToUtf8(const edk::char32 *str32,edk::uint32 size){
    return edk::String::str32ToUtf8((edk::char32 *)str32,size);edkEnd();
}
edk::char8* edk::String::str32ToUtf8(edk::char32 *str32){
    return edk::String::str32ToUtf8(str32,edk::String::str32Size(str32));edkEnd();
}
edk::char8* edk::String::str32ToUtf8(const edk::char32 *str32){
    return edk::String::str32ToUtf8((edk::char32 *)str32,edk::String::str32Size(str32));edkEnd();
}
//return the size of characters using 32 bits per character
edk::uint32 edk::String::str32Size(edk::char32 *str){
    //test the str
    edk::uint32 ret = 0u;edkEnd();
    if(str){
        while(*str){
            str++;edkEnd();
            ret++;edkEnd();
        }
    }
    return ret;
}
edk::uint32 edk::String::str32Size(const edk::char32 *str){
    return edk::String::str32Size((edk::char32*) str);edkEnd();
}
//return the size of a vector with 32bit charaters
edk::uint32 edk::String::str32ToUtf8Size(edk::char32 *str32,edk::uint32 size){
    //test the str and the size
    if(str32 && size){
        //test the bit to test if it's an 8 16 or 32 bits string
        edk::char32 ret = size;edkEnd();
        edk::char32 c=0u;
        for(edk::uint32 i = 0u;i<size;i++){
            //get the 32 bits character
            c = str32[i];edkEnd();
            if(edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,1u)){
                ret++;edkEnd();
                if(edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,2u)){
                    ret++;edkEnd();
                    if(edk::BinaryConverter::getByteLittleEndian((edk::uint32)c,3u)){
                        ret++;edkEnd();
                    }
                }
            }
        }
        return ret;
    }
    return 0u;edkEnd();
}
edk::uint32 edk::String::str32ToUtf8Size(const edk::char32 *str32,edk::uint32 size){
    return edk::String::str32ToUtf8Size((edk::char32 *)str32,size);edkEnd();
}
//convert utf8 to ascii
bool edk::String::utf8ToStr(edk::char8 *utf8,edk::uint32 size,edk::char8 *str){
    if(utf8 && size && str){
        //convert the string
        for(edk::uint32 i=0u;i<size;i++){
            switch(utf8[i]){
            case (edk::char8)0xe2:
                i++;edkEnd();
                switch(utf8[i]){
                case (edk::char8)0x80:
                    i++;edkEnd();
                    switch(utf8[i]){
                    case (edk::char8)0x9a:
                        //82 00 e2 80 9a - 000 226 128 154
                        *str = (edk::char8)0x82;edkEnd();
                        break;edkEnd();
                    case (edk::char8)0x9e:
                        //84 00 e2 80 9e - 000 226 128 158
                        *str = (edk::char8)0x84;edkEnd();
                        break;edkEnd();
                    case (edk::char8)0xa6:
                        //85 00 e2 80 a6 - 000 226 128 166
                        *str = (edk::char8)0x85;edkEnd();
                        break;edkEnd();
                    case (edk::char8)0xa0:
                        //86 00 e2 80 a0 - 000 226 128 160
                        *str = (edk::char8)0x86;edkEnd();
                        break;edkEnd();
                    case (edk::char8)0xa1:
                        //87 00 e2 80 a1 - 000 226 128 161
                        *str = (edk::char8)0x87;edkEnd();
                        break;edkEnd();
                    case (edk::char8)0xb0:
                        //89 00 e2 80 b0 - 000 226 128 176
                        *str = (edk::char8)0x89;edkEnd();
                        break;edkEnd();
                    case (edk::char8)0xb9:
                        //8b 00 e2 80 b9 - 000 226 128 185
                        *str = (edk::char8)0x8b;edkEnd();
                        break;edkEnd();
                    case (edk::char8)0x98:
                        //91 00 e2 80 98 - 000 226 128 152
                        *str = (edk::char8)0x91;edkEnd();
                        break;edkEnd();
                    case (edk::char8)0x99:
                        //92 00 e2 80 99 - 000 226 128 153
                        *str = (edk::char8)0x92;edkEnd();
                        break;edkEnd();
                    case (edk::char8)0x9c:
                        //93 00 e2 80 9c - 000 226 128 156
                        *str = (edk::char8)0x9c;edkEnd();
                        break;edkEnd();
                    case (edk::char8)0x9d:
                        //94 00 e2 80 9d - 000 226 128 157
                        *str = (edk::char8)0x9d;edkEnd();
                        break;edkEnd();
                    case (edk::char8)0xa2:
                        //95 00 e2 80 a2 - 000 226 128 162
                        *str = (edk::char8)0xa2;edkEnd();
                        break;edkEnd();
                    case (edk::char8)0x93:
                        //96 00 e2 80 93 - 000 226 128 147
                        *str = (edk::char8)0x93;edkEnd();
                        break;edkEnd();
                    case (edk::char8)0x94:
                        //97 00 e2 80 94 - 000 226 128 148
                        *str = (edk::char8)0x94;edkEnd();
                        break;edkEnd();
                    case (edk::char8)0xba:
                        //9b 00 e2 80 ba - 000 226 128 186
                        *str = (edk::char8)0xba;edkEnd();
                        break;edkEnd();
                    default:
                        *str = '*';edkEnd();
                        break;edkEnd();
                    }
                    i++;edkEnd();
                    break;edkEnd();
                case (edk::char8)0x82:
                    //80 00 e2 82 ac - 000 226 130 172
                    i++;edkEnd();
                    if(utf8[i] == (edk::char8)0xac){
                        *str = 0x80;
                    }
                    else{
                        *str = '*';edkEnd();
                    }
                    i++;edkEnd();
                    break;edkEnd();
                case (edk::char8)0x84:
                    //99 00 e2 84 a2 - 000 226 132 162
                    i++;edkEnd();
                    if(utf8[i] == (edk::char8)0xa2){
                        *str = 0x99;edkEnd();
                    }
                    else{
                        *str = '*';edkEnd();
                    }
                    i++;edkEnd();
                    break;edkEnd();
                }
                break;edkEnd();
            case (edk::char8)0xc2:
                //a1 00 00 c2 a1 - 000 000 194 161
                //a2 00 00 c2 a2 - 000 000 194 162
                //a3 00 00 c2 a3 - 000 000 194 163
                //a4 00 00 c2 a4 - 000 000 194 164
                //a5 00 00 c2 a5 - 000 000 194 165
                //a6 00 00 c2 a6 - 000 000 194 166
                //a7 00 00 c2 a7 - 000 000 194 167
                //a8 00 00 c2 a8 - 000 000 194 168
                //a9 00 00 c2 a9 - 000 000 194 169
                //aa 00 00 c2 aa - 000 000 194 170
                //ab 00 00 c2 ab - 000 000 194 171
                //ac 00 00 c2 ac - 000 000 194 172
                //ae 00 00 c2 ae - 000 000 194 174
                //af 00 00 c2 af - 000 000 194 175
                //b0 00 00 c2 b0 - 000 000 194 176
                //b1 00 00 c2 b1 - 000 000 194 177
                //b2 00 00 c2 b2 - 000 000 194 178
                //b3 00 00 c2 b3 - 000 000 194 179
                //b4 00 00 c2 b4 - 000 000 194 180
                //b5 00 00 c2 b5 - 000 000 194 181
                //b6 00 00 c2 b6 - 000 000 194 182
                //b7 00 00 c2 b7 - 000 000 194 183
                //b8 00 00 c2 b8 - 000 000 194 184
                //b9 00 00 c2 b9 - 000 000 194 185
                //ba 00 00 c2 ba - 000 000 194 186
                //bb 00 00 c2 bb - 000 000 194 187
                //bc 00 00 c2 bc - 000 000 194 188
                //bd 00 00 c2 bd - 000 000 194 189
                //be 00 00 c2 be - 000 000 194 190
                //bf 00 00 c2 bf - 000 000 194 191
                i++;edkEnd();
                *str = utf8[i];edkEnd();
                break;edkEnd();
            case (edk::char8)0xc3:
                //c0 00 00 c3 80 - 000 000 195 128
                //c1 00 00 c3 81 - 000 000 195 129
                //c2 00 00 c3 82 - 000 000 195 130
                //c3 00 00 c3 83 - 000 000 195 131
                //c4 00 00 c3 84 - 000 000 195 132
                //c5 00 00 c3 85 - 000 000 195 133
                //c6 00 00 c3 86 - 000 000 195 134
                //c7 00 00 c3 87 - 000 000 195 135
                //c8 00 00 c3 88 - 000 000 195 136
                //c9 00 00 c3 89 - 000 000 195 137
                //ca 00 00 c3 8a - 000 000 195 138
                //cb 00 00 c3 8b - 000 000 195 139
                //cc 00 00 c3 8c - 000 000 195 140
                //cd 00 00 c3 8d - 000 000 195 141
                //ce 00 00 c3 8e - 000 000 195 142
                //cf 00 00 c3 8f - 000 000 195 143
                //d0 00 00 c3 90 - 000 000 195 144
                //d1 00 00 c3 91 - 000 000 195 145
                //d2 00 00 c3 92 - 000 000 195 146
                //d3 00 00 c3 93 - 000 000 195 147
                //d4 00 00 c3 94 - 000 000 195 148
                //d5 00 00 c3 95 - 000 000 195 149
                //d6 00 00 c3 96 - 000 000 195 150
                //d7 00 00 c3 97 - 000 000 195 151
                //d8 00 00 c3 98 - 000 000 195 152
                //d9 00 00 c3 99 - 000 000 195 153
                //da 00 00 c3 9a - 000 000 195 154
                //db 00 00 c3 9b - 000 000 195 155
                //dc 00 00 c3 9c - 000 000 195 156
                //dd 00 00 c3 9d - 000 000 195 157
                //de 00 00 c3 9e - 000 000 195 158
                //df 00 00 c3 9f - 000 000 195 159
                //e0 00 00 c3 a0 - 000 000 195 160
                //e1 00 00 c3 a1 - 000 000 195 161
                //e2 00 00 c3 a2 - 000 000 195 162
                //e3 00 00 c3 a3 - 000 000 195 163
                //e4 00 00 c3 a4 - 000 000 195 164
                //e5 00 00 c3 a5 - 000 000 195 165
                //e6 00 00 c3 a6 - 000 000 195 166
                //e7 00 00 c3 a7 - 000 000 195 167
                //e8 00 00 c3 a8 - 000 000 195 168
                //e9 00 00 c3 a9 - 000 000 195 169
                //ea 00 00 c3 aa - 000 000 195 170
                //eb 00 00 c3 ab - 000 000 195 171
                //ec 00 00 c3 ac - 000 000 195 172
                //ed 00 00 c3 ad - 000 000 195 173
                //ee 00 00 c3 ae - 000 000 195 174
                //ef 00 00 c3 af - 000 000 195 175
                //f0 00 00 c3 b0 - 000 000 195 176
                //f1 00 00 c3 b1 - 000 000 195 177
                //f2 00 00 c3 b2 - 000 000 195 178
                //f3 00 00 c3 b3 - 000 000 195 179
                //f4 00 00 c3 b4 - 000 000 195 180
                //f5 00 00 c3 b5 - 000 000 195 181
                //f6 00 00 c3 b6 - 000 000 195 182
                //f7 00 00 c3 b7 - 000 000 195 183
                //f8 00 00 c3 b8 - 000 000 195 184
                //f9 00 00 c3 b9 - 000 000 195 185
                //fa 00 00 c3 ba - 000 000 195 186
                //fb 00 00 c3 bb - 000 000 195 187
                //fc 00 00 c3 bc - 000 000 195 188
                //fd 00 00 c3 bd - 000 000 195 189
                //fe 00 00 c3 be - 000 000 195 190
                //ff 00 00 c3 bf - 000 000 195 191
                i++;edkEnd();
                *str = utf8[i] + 0x43;edkEnd();
                break;edkEnd();
            case (edk::char8)0xc5:
                i++;edkEnd();
                switch(utf8[i]){
                case (edk::char8)0xa0:
                    //8a 00 00 c5 a0 - 000 000 197 160
                    *str = 0x8a;edkEnd();
                    break;edkEnd();
                case (edk::char8)0x92:
                    //8c 00 00 c5 92 - 000 000 197 146
                    *str = 0x8c;edkEnd();
                    break;edkEnd();
                case (edk::char8)0xbd:
                    //8e 00 00 c5 bd - 000 000 197 189
                    *str = 0x8e;edkEnd();
                    break;edkEnd();
                case (edk::char8)0xa1:
                    //9a 00 00 c5 a1 - 000 000 197 161
                    *str = 0xa1;edkEnd();
                    break;edkEnd();
                case (edk::char8)0x93:
                    //9c 00 00 c5 93 - 000 000 197 147
                    *str = 0x93;edkEnd();
                    break;edkEnd();
                case (edk::char8)0xbe:
                    //9e 00 00 c5 be - 000 000 197 190
                    *str = 0xbe;edkEnd();
                    break;edkEnd();
                case (edk::char8)0xb8:
                    //9f 00 00 c5 b8 - 000 000 197 184
                    *str = 0xb8;edkEnd();
                    break;edkEnd();
                default:
                    *str = '*';edkEnd();
                    break;edkEnd();
                }
                i++;edkEnd();
                break;edkEnd();
            case (edk::char8)0xc6:
                i++;edkEnd();
                //83 00 00 c6 92 - 000 000 198 146
                if(utf8[i] == (edk::char8)0x92){
                    //
                    *str = (edk::char8)0x83;edkEnd();
                }
                i++;edkEnd();
                break;edkEnd();
            case (edk::char8)0xcb:
                i++;edkEnd();
                switch(utf8[i]){
                case (edk::char8)0x86:
                    //88 00 00 cb 86 - 000 000 203 134
                    *str = 0x88;edkEnd();
                    break;edkEnd();
                case (edk::char8)0x9c:
                    //98 00 00 cb 9c - 000 000 203 156
                    *str = 0x98;edkEnd();
                    break;edkEnd();
                default:
                    *str = '*';edkEnd();
                    break;edkEnd();
                }
                i++;edkEnd();
                break;edkEnd();
            default:
                *str = utf8[i];edkEnd();
                break;edkEnd();
            }
            str++;edkEnd();
        }
        *str = 0u;edkEnd();
        return true;
    }
    return false;
}
bool edk::String::utf8ToStr(const edk::char8 *utf8,edk::uint32 size,edk::char8 *str){
    return edk::String::utf8ToStr((edk::char8 *)utf8,size,str);edkEnd();
}
edk::char8* edk::String::utf8ToStr(edk::char8 *utf8,edk::uint32 size){
    edk::char8* ret = NULL;edkEnd();
    if(size){
        //get the utf8 size
        edk::uint32 sizeUtf = edk::String::utf8Size(utf8);edkEnd();
        if(sizeUtf){
            //create a string
            ret = new edk::char8[sizeUtf+1u];edkEnd();
            if(ret){
                if(!edk::String::utf8ToStr(utf8,size,ret)){
                    delete[] ret;edkEnd();
                    ret=NULL;edkEnd();
                }
            }
        }
    }
    return ret;
}
edk::char8* edk::String::utf8ToStr(const edk::char8 *utf8,edk::uint32 size){
    return edk::String::utf8ToStr((edk::char8 *)utf8,size);edkEnd();
}
edk::char8* edk::String::utf8ToStr(edk::char8 *utf8){
    return edk::String::utf8ToStr(utf8,edk::String::utf8Size(utf8));edkEnd();
}
edk::char8* edk::String::utf8ToStr(const edk::char8 *utf8){
    return edk::String::utf8ToStr((edk::char8 *)utf8);edkEnd();
}
//return the size of a utf8 string
edk::uint32 edk::String::utf8Size(edk::char8 *utf8){
    edk::uint32 ret=0u;
    if(utf8){
        //convert the string
        while(*utf8){
            switch(*utf8){
            case (edk::char8)0xe2:
                utf8++;edkEnd();
                if(*utf8){
                    switch(*utf8){
                    case (edk::char8)0x80:
                        utf8++;edkEnd();
                        if(*utf8){
                            ret++;edkEnd();
                        }
                        else{
                            return ret;
                        }
                        break;edkEnd();
                    case (edk::char8)0x82:
                        utf8++;edkEnd();
                        if(*utf8){
                            ret++;edkEnd();
                        }
                        else{
                            return ret;
                        }
                        break;edkEnd();
                    case (edk::char8)0x84:
                        utf8++;edkEnd();
                        if(*utf8){
                            ret++;edkEnd();
                        }
                        else{
                            return ret;
                        }
                        break;edkEnd();
                    }
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc2:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc3:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc5:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc6:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xcb:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            default:
                ret++;edkEnd();
                break;edkEnd();
            }
            utf8++;edkEnd();
        }
    }
    return ret;
}
edk::uint32 edk::String::utf8Size(const edk::char8 *utf8){
    return edk::String::utf8Size((edk::char8 *)utf8);edkEnd();
}
edk::uint32 edk::String::utf8WordSize(edk::char8 *utf8){
    edk::uint32 ret=0u;
    if(utf8){
        //convert the string
        while(*utf8){
            //test the character
            if(*utf8==' ' || *utf8=='\n' || *utf8==10){
                break;edkEnd();
            }
            switch(*utf8){
            case (edk::char8)0xe2:
                utf8++;edkEnd();
                if(*utf8){
                    switch(*utf8){
                    case (edk::char8)0x80:
                        utf8++;edkEnd();
                        if(*utf8){
                            ret++;edkEnd();
                        }
                        else{
                            return ret;
                        }
                        break;edkEnd();
                    case (edk::char8)0x82:
                        utf8++;edkEnd();
                        if(*utf8){
                            ret++;edkEnd();
                        }
                        else{
                            return ret;
                        }
                        break;edkEnd();
                    case (edk::char8)0x84:
                        utf8++;edkEnd();
                        if(*utf8){
                            ret++;edkEnd();
                        }
                        else{
                            return ret;
                        }
                        break;edkEnd();
                    }
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc2:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc3:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc5:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc6:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xcb:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            default:
                ret++;edkEnd();
                break;edkEnd();
            }
            utf8++;edkEnd();
        }
    }
    return ret;
}
edk::uint32 edk::String::utf8WordSize(const edk::char8 *utf8){
    return edk::String::utf8WordSize((edk::char8*) utf8);edkEnd();
}
edk::uint32 edk::String::utf8WordSize(edk::char8 *utf8,edk::uint32* jump){
    edk::uint32 ret=0u;
    if(utf8 && jump){
        edk::char8* str = utf8;edkEnd();
        //convert the string
        while(*utf8){
            //test the character
            if(*utf8==' ' || *utf8=='\n' || *utf8==10){
                break;edkEnd();
            }
            switch(*utf8){
            case (edk::char8)0xe2:
                utf8++;edkEnd();
                if(*utf8){
                    switch(*utf8){
                    case (edk::char8)0x80:
                        utf8++;edkEnd();
                        if(*utf8){
                            ret++;edkEnd();
                        }
                        else{
                            return ret;
                        }
                        break;edkEnd();
                    case (edk::char8)0x82:
                        utf8++;edkEnd();
                        if(*utf8){
                            ret++;edkEnd();
                        }
                        else{
                            return ret;
                        }
                        break;edkEnd();
                    case (edk::char8)0x84:
                        utf8++;edkEnd();
                        if(*utf8){
                            ret++;edkEnd();
                        }
                        else{
                            return ret;
                        }
                        break;edkEnd();
                    }
                }
                else return ret;
                break;edkEnd();
            case (edk::char8)0xc2:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc3:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc5:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc6:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xcb:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            default:
                ret++;edkEnd();
                break;edkEnd();
            }
            utf8++;edkEnd();
        }
        *jump = utf8-str;edkEnd();
    }
    return ret;
}
edk::uint32 edk::String::utf8WordSize(const edk::char8 *utf8,edk::uint32* jump){
    return edk::String::utf8WordSize((edk::char8*) utf8,jump);edkEnd();
}
edk::uint32 edk::String::utf8WordSize(edk::char8 *utf8,edk::uint32 limit,edk::uint32* jump){
    edk::uint32 ret=0u;
    if(utf8 && jump){
        edk::char8* str = utf8;edkEnd();
        //convert the string
        while(*utf8){
            //test the character
            if(*utf8==' ' || *utf8=='\n' || *utf8==10){
                break;edkEnd();
            }
            switch(*utf8){
            case (edk::char8)0xe2:
                utf8++;edkEnd();
                if(*utf8){
                    switch(*utf8){
                    case (edk::char8)0x80:
                        utf8++;edkEnd();
                        if(*utf8){
                            ret++;edkEnd();
                        }
                        else{
                            return ret;
                        }
                        break;edkEnd();
                    case (edk::char8)0x82:
                        utf8++;edkEnd();
                        if(*utf8){
                            ret++;edkEnd();
                        }
                        else{
                            return ret;
                        }
                        break;edkEnd();
                    case (edk::char8)0x84:
                        utf8++;edkEnd();
                        if(*utf8){
                            ret++;edkEnd();
                        }
                        else{
                            return ret;
                        }
                        break;edkEnd();
                    }
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc2:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc3:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc5:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xc6:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            case (edk::char8)0xcb:
                utf8++;edkEnd();
                if(*utf8){
                    ret++;edkEnd();
                }
                else{
                    return ret;
                }
                break;edkEnd();
            default:
                ret++;edkEnd();
                break;edkEnd();
            }
            utf8++;edkEnd();
            if(ret>=limit){
                break;edkEnd();
            }
        }
        *jump = utf8-str;edkEnd();
    }
    return ret;
}
edk::uint32 edk::String::utf8WordSize(const edk::char8 *utf8,edk::uint32 limit,edk::uint32* jump){
    return edk::String::utf8WordSize((edk::char8*) utf8,limit,jump);edkEnd();
}
edk::uint32 edk::String::utf8LineCount(edk::char8 *utf8,edk::uint32 limit){
    edk::uint32 ret = 0u;edkEnd();
    if(utf8 && limit){
        edk::uint32 word=0u;
        edk::uint32 myJump=0u;
        //count the characte size in the line
        edk::uint32 size = 0u;edkEnd();
        bool newLine = false;edkEnd();
        ret++;edkEnd();
        bool firstLine=false;edkEnd();
        while(*utf8){
            //test if the size extend the limit
            if(size+1u>=limit || *utf8 == '\n' || *utf8 == 10
                    ||
                    newLine
                    ){
                if(*utf8==' '){
                    if(utf8[1u]!=' ' && utf8[1u]!=10 && utf8[1u]!='\n'){
                        utf8++;edkEnd();
                    }
                }
                if(*utf8=='\n' || *utf8==10){
                    utf8++;edkEnd();
                }
                if(firstLine){
                    ret++;edkEnd();
                }
                size=0u;
                newLine = false;edkEnd();
                firstLine=true;edkEnd();
                continue;edkEnd();
            }

            word = edk::String::utf8WordSize(utf8,&myJump);edkEnd();
            if(word){
                //if the next word does't fit in the line it will return the last size
                if(size+word>limit){
                    if(!size){
                        word = edk::String::utf8WordSize(utf8,limit,&myJump);edkEnd();
                    }
                    else{
                        //new line
                        newLine = true;edkEnd();
                        continue;edkEnd();
                    }
                }
                size+=word;edkEnd();
                //go to the space
                utf8+=myJump;edkEnd();
            }
            else{
                size++;edkEnd();
                utf8++;edkEnd();
            }
        }
        if(size){
            ret++;edkEnd();
        }
    }
    return ret;
}
edk::uint32 edk::String::utf8LineCount(const edk::char8 *utf8,edk::uint32 limit){
    return edk::String::utf8LineCount((edk::char8*) utf8,limit);edkEnd();
}
edk::uint32 edk::String::utf8LineSize(edk::char8* utf8,edk::uint32 limit){
    edk::uint32 size = 0u;edkEnd();
    if(utf8 && limit){
        edk::uint32 word=0u;
        edk::uint32 myJump=0u;
        while(*utf8){
            //test if the size extend the limit
            if(size+1u>=limit || *utf8 == '\n' || *utf8 == 10){
                break;edkEnd();
            }

            word = edk::String::utf8WordSize(utf8,&myJump);edkEnd();
            if(word){
                //if the next word does't fit in the line it will return the last size
                if(size+word>limit){
                    break;edkEnd();
                }
                size+=word;edkEnd();
                //go to the space
                utf8+=myJump;edkEnd();
            }
            else{
                size++;edkEnd();
                utf8++;edkEnd();
            }
        }
    }
    return size;edkEnd();
}
edk::uint32 edk::String::utf8LineSize(const edk::char8 *utf8,edk::uint32 limit){
    return edk::String::utf8LineSize((edk::char8*)utf8,limit);edkEnd();
}
edk::uint32 edk::String::utf8LineSize(edk::char8 *utf8,edk::uint32 limit,edk::uint32* jump){
    edk::uint32 size = 0u;edkEnd();
    if(utf8 && limit && jump){
        edk::uint32 word=0u;
        edk::uint32 myJump=0u;
        *jump=0u;
        while(*utf8){
            //test if the size extend the limit
            if(size+1u>=limit || *utf8 == '\n' || *utf8 == 10){
                break;edkEnd();
            }

            word = edk::String::utf8WordSize(utf8,&myJump);edkEnd();
            if(word){
                //if the next word does't fit in the line it will return the last size
                if(size+word>limit){
                    break;edkEnd();
                }
                size+=word;edkEnd();
                *jump+=myJump;edkEnd();
                //go to the jump
                utf8+=myJump;edkEnd();
            }
            else{
                size++;edkEnd();
                utf8++;edkEnd();
                *jump+=1u;edkEnd();
            }
        }
    }
    return size;edkEnd();
}
edk::uint32 edk::String::utf8LineSize(const edk::char8 *utf8,edk::uint32 limit,edk::uint32* jump){
    return edk::String::utf8LineSize((edk::char8*) utf8,limit,jump);edkEnd();
}
//return the position of a string where the line starts
edk::char8* edk::String::utf8LinePosition(edk::char8 *utf8,edk::uint32 limit,edk::uint32 linePosition){
    edk::char8* ret = NULL;edkEnd();
    if(utf8 && limit){
        edk::uint32 word=0u;
        edk::uint32 myJump=0u;
        //count the lines until the line position
        edk::uint32 count=0u;
        //count the characte size in the line
        edk::uint32 size = 0u;edkEnd();
        bool newLine = false;edkEnd();
        ret = utf8;edkEnd();
        while(*utf8){
            //test if the size extend the limit
            if(size+1u>=limit || *utf8 == '\n' || *utf8 == 10
                    ||
                    newLine
                    ){
                if(*utf8==' '){
                    if(utf8[1u]!=' ' && utf8[1u]!=10 && utf8[1u]!='\n'){
                        utf8++;edkEnd();
                    }
                }
                if(*utf8=='\n' || *utf8==10){
                    utf8++;edkEnd();
                }
                if(count>=linePosition){
                    break;edkEnd();
                }
                count++;edkEnd();
                size=0u;
                ret = utf8;edkEnd();
                newLine = false;edkEnd();
                if(count>=linePosition){
                    break;edkEnd();
                }
                continue;edkEnd();
            }

            word = edk::String::utf8WordSize(utf8,&myJump);edkEnd();
            if(word){
                //if the next word does't fit in the line it will return the last size
                if(size+word>limit){
                    if(!size){
                        word = edk::String::utf8WordSize(utf8,limit,&myJump);edkEnd();
                    }
                    else{
                        //new line
                        newLine = true;edkEnd();
                        continue;edkEnd();
                    }
                }
                size+=word;edkEnd();
                //go to the space
                utf8+=myJump;edkEnd();
            }
            else{
                size++;edkEnd();
                utf8++;edkEnd();
            }
        }
    }
    return ret;
}
edk::char8* edk::String::utf8LinePosition(const edk::char8 *utf8,edk::uint32 limit,edk::uint32 linePosition){
    return edk::String::utf8LinePosition((edk::char8*) utf8,limit,linePosition);edkEnd();
}
//get the size of utf8 bytes in a character
edk::uint8 edk::String::utf8Bytes(edk::char8 *utf8){
    edk::uint32 ret=0u;
    if(utf8){
        ret++;edkEnd();
        switch(*utf8){
        case (edk::char8)0xe2:
            utf8++;edkEnd();
            if(*utf8){
                switch(*utf8){
                case (edk::char8)0x80:
                    utf8++;edkEnd();
                    if(*utf8){
                        ret++;edkEnd();
                    }
                    else{
                        return ret;
                    }
                    break;edkEnd();
                case (edk::char8)0x82:
                    utf8++;edkEnd();
                    if(*utf8){
                        ret++;edkEnd();
                    }
                    else{
                        return ret;
                    }
                    break;edkEnd();
                case (edk::char8)0x84:
                    utf8++;edkEnd();
                    if(*utf8){
                        ret++;edkEnd();
                    }
                    else{
                        return ret;
                    }
                    break;edkEnd();
                }
            }
            else{
                return ret;
            }
            break;edkEnd();
        case (edk::char8)0xc2:
            utf8++;edkEnd();
            if(*utf8){
                ret++;edkEnd();
            }
            else{
                return ret;
            }
            break;edkEnd();
        case (edk::char8)0xc3:
            utf8++;edkEnd();
            if(*utf8){
                ret++;edkEnd();
            }
            else{
                return ret;
            }
            break;edkEnd();
        case (edk::char8)0xc5:
            utf8++;edkEnd();
            if(*utf8){
                ret++;edkEnd();
            }
            else{
                return ret;
            }
            break;edkEnd();
        case (edk::char8)0xc6:
            utf8++;edkEnd();
            if(*utf8){
                ret++;edkEnd();
            }
            else{
                return ret;
            }
            break;edkEnd();
        case (edk::char8)0xcb:
            utf8++;edkEnd();
            if(*utf8){
                ret++;edkEnd();
            }
            else{
                return ret;
            }
            break;edkEnd();
        }
    }
    return ret;
}
edk::uint8 edk::String::utf8Bytes(const edk::char8 *utf8){
    return edk::String::utf8Bytes((edk::char8 *)utf8);edkEnd();
}
//convert a utf8 character to uint32
edk::uint32 edk::String::utf8ToUint32(edk::char8 *utf8){
    edk::uint32 ret = 0u;edkEnd();
    edk::uint8 size = edk::String::utf8Bytes(utf8);edkEnd();
    switch(size){
    case 1u:
        ret = edk::BinaryConverter::joinBytesLittleEndian(0u,0u,0u,utf8[0u]);edkEnd();
        break;edkEnd();
    case 2u:
        ret = edk::BinaryConverter::joinBytesLittleEndian(0u,0u,utf8[0u],utf8[1u]);edkEnd();
        break;edkEnd();
    case 3u:
        ret = edk::BinaryConverter::joinBytesLittleEndian(0u,utf8[0u],utf8[1u],utf8[2u]);edkEnd();
        break;edkEnd();
    case 4u:
    default:
        if(size){
            ret = edk::BinaryConverter::joinBytesLittleEndian(utf8[0u],utf8[1u],utf8[2u],utf8[3u]);edkEnd();
        }
    }
    return ret;
}
edk::uint32 edk::String::utf8ToUint32(const edk::char8 *utf8){
    return edk::String::utf8ToUint32((edk::char8 *)utf8);edkEnd();
}

//ASCII to UTF8
bool edk::String::asciiToUtf8(edk::char8* src,edk::char8* dest){
    if(src && dest){
        edk::uchar8 c;edkEnd();
        //
        while(*src){
            c = *src;edkEnd();
            switch(c){
            case 0xC3:
                *dest = c;edkEnd();
                //test if have the C2
                if(src[1u]){
                    c = src[2u];edkEnd();
                    if(c == 0xC2){
                        //if have the c2. Then convert the character
                        src++;edkEnd();
                        c = *src;edkEnd();
                        *dest = c | 0x40;
                    }
                }
                break;edkEnd();
            case 0xC2:
                src++;edkEnd();
                *dest = *src;edkEnd();
                break;edkEnd();
            default:
                *dest = c;edkEnd();
                break;edkEnd();
            }
            src++;edkEnd();
            dest++;edkEnd();
        }
        *dest='\0';edkEnd();
        return true;
    }
    return false;
}
bool edk::String::asciiToUtf8(const edk::char8* src,edk::char8* dest){
    return edk::String::asciiToUtf8((edk::char8*) src,dest);edkEnd();
}
edk::char8* edk::String::asciiToUtf8(edk::char8* src){
    edk::char8* ret=NULL;edkEnd();
    //get the size of the string
    edk::uint32 size = edk::String::asciiToUtf8Size(src);edkEnd();
    if(size){
        //create the string
        ret = new edk::char8[size+1u];edkEnd();
        if(ret){
            //convert the ascii to utf8
            if(edk::String::asciiToUtf8(src,ret)){
                return ret;
            }
            delete[] ret;edkEnd();
        }
    }
    return NULL;edkEnd();
}
edk::char8* edk::String::asciiToUtf8(const edk::char8* src){
    return edk::String::asciiToUtf8((edk::char8*) src);edkEnd();
}
//ASCII to UTF8 Size
edk::uint32 edk::String::asciiToUtf8Size(edk::char8* src){
    edk::uint32 ret=0u;
    if(src){
        edk::uchar8 c;edkEnd();
        while(*src){
            c = *src;edkEnd();
            switch(c){
            case 0xC3:
                src++;edkEnd();
                //ret++;edkEnd();
                break;edkEnd();
            case 0xC2:
                src++;edkEnd();
                //ret++;edkEnd();
                break;edkEnd();
            }
            src++;edkEnd();
            ret++;edkEnd();
        }
    }
    return ret;
}
edk::uint32 edk::String::asciiToUtf8Size(const edk::char8* src){
    return edk::String::asciiToUtf8Size((edk::char8*) src);edkEnd();
}

//UTF8 to ASCII
bool edk::String::utf8ToAscii(edk::char8* src,edk::char8* dest){
    if(src && dest){
        edk::uchar8 c;edkEnd();
        while(*src){
            c = *src;edkEnd();
            //test if need getch another character
            if(c>=0xc2 && c<=0xdf){
                //read one more
                *dest=0xC3;edkEnd();
                dest++;edkEnd();
                *dest=c & 0xbf;edkEnd();

                dest++;edkEnd();
                *dest=0xC2;edkEnd();
                dest++;edkEnd();
                src++;edkEnd();
                *dest=*src;edkEnd();
            }
            else if((c>= 0xe0 && c<=0xea)
                    || c==0xed
                    || c==0xef
                    ){
                //read two more
                *dest=0xC3;edkEnd();
                dest++;edkEnd();
                *dest=c & 0xbf;edkEnd();

                dest++;edkEnd();
                *dest=0xC2;edkEnd();
                dest++;edkEnd();
                src++;edkEnd();
                *dest=*src;edkEnd();

                dest++;edkEnd();
                *dest=0xC2;edkEnd();
                dest++;edkEnd();
                src++;edkEnd();
                *dest=*src;edkEnd();
            }
            else if(c==0xf0 || c==0xf3 || c==0xf4){
                //read tree more
                *dest=0xC3;edkEnd();
                dest++;edkEnd();
                *dest=c & 0xbf;edkEnd();

                dest++;edkEnd();
                *dest=0xC2;edkEnd();
                dest++;edkEnd();
                src++;edkEnd();
                *dest=*src;edkEnd();

                dest++;edkEnd();
                *dest=0xC2;edkEnd();
                dest++;edkEnd();
                src++;edkEnd();
                *dest=*src;edkEnd();

                dest++;edkEnd();
                *dest=0xC2;edkEnd();
                dest++;edkEnd();
                src++;edkEnd();
                *dest=*src;edkEnd();
            }
            else{
                *dest=c;edkEnd();
            }
            src++;edkEnd();
            dest++;edkEnd();
        }
        *dest='\0';edkEnd();
        return true;
    }
    return false;
}
bool edk::String::utf8ToAscii(const edk::char8* src,edk::char8* dest){
    return edk::String::utf8ToAscii((edk::char8*) src,dest);edkEnd();
}
edk::char8* edk::String::utf8ToAscii(edk::char8* src){
    edk::char8* ret=NULL;edkEnd();
    //get the size of the string
    edk::uint32 size = edk::String::utf8ToAsciiSize(src);edkEnd();
    if(size){
        //create the string
        ret = new edk::char8[size+1u];edkEnd();
        if(ret){
            //convert the ascii to utf8
            if(edk::String::utf8ToAscii(src,ret)){
                return ret;
            }
            delete[] ret;edkEnd();
        }
    }
    return NULL;edkEnd();
}
edk::char8* edk::String::utf8ToAscii(const edk::char8* src){
    return edk::String::utf8ToAscii((edk::char8*) src);edkEnd();
}
//UTF8 to ASCII size
edk::uint32 edk::String::utf8ToAsciiSize(edk::char8* src){
    edk::uint32 size=0u;
    if(src){
        edk::uchar8 c;edkEnd();
        while(*src){
            c = *src;edkEnd();
            //test if need getch another character
            if(c>=0xc2 && c<=0xdf){
                //read one more
                size+=3u;edkEnd();
                src++;edkEnd();
            }
            else if((c>= 0xe0 && c<=0xea)
                    || c==0xed
                    || c==0xef
                    ){
                //read two more
                size+=5u;edkEnd();
                src+=2u;edkEnd();
            }
            else if(c==0xf0 || c==0xf3 || c==0xf4){
                //read tree more
                size+=7u;edkEnd();
                src+=3u;edkEnd();
            }
            src++;edkEnd();
            size++;edkEnd();
        }
    }
    return size;edkEnd();
}
edk::uint32 edk::String::utf8ToAsciiSize(const edk::char8* src){
    return edk::String::utf8ToAsciiSize((edk::char8*) src);edkEnd();
}

edk::uint32 edk::String::int32ToStrSize(edk::int32 value){
    return edk::String::sizeOfInt32(value);edkEnd();
}

edk::uint32 edk::String::int64ToStrSize(edk::int64 value){
    return edk::String::sizeOfInt64(value);edkEnd();
}

edk::char8* edk::String::int32ToStr(edk::int32 value){
    edk::char8* str = 0u;edkEnd();

    //count the number
    edk::uint32 size = edk::String::sizeOfInt32(value);edkEnd();

    //test if the size is bigger then 0u
    if(size>0u){
        //begin
        edk::uint32 begin=0u;
        if(value>=0){
            //Positive
            str = new edk::char8[size+1u];edkEnd();
            if(str){
                str[size]='\0';edkEnd();
            }
            else{
                //else set NULL
                str=0u;
            }
        }
        else{
            //Negative
            size=size+1u;edkEnd();
            begin=1u;edkEnd();
            str = new edk::char8[size+1u];edkEnd();
            if(str){
                str[0u]='-';edkEnd();
                str[size]='\0';edkEnd();
            }
            else{
                //else set NULL
                str=0u;
            }
        }
        //test if alloc the str
        if(str){
            edk::String::copyInt32ToStr(value,&str[begin],size-begin);edkEnd();
        }
    }
    else{
        //create a zero
        str = new edk::char8[2u];edkEnd();
        if(str){
            str[0u]='0';edkEnd();
            str[1u]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;edkEnd();
}

edk::char8* edk::String::int32ToStr(edk::int32 value,edk::uint32 digits){
    edk::char8* str = 0u;edkEnd();

    //count the number
    edk::uint32 size = edk::String::sizeOfInt32(value);edkEnd();

    //test if the size is bigger then 0u
    if(size>0u){
        if(size>digits){
            size=digits;edkEnd();
        }
        //begin
        edk::uint32 begin=0u;
        if(value>=0){
            //Positive
            str = new edk::char8[size+1u];edkEnd();
            if(str){
                str[size]='\0';edkEnd();
            }
            else{
                //else set NULL
                str=0u;
            }
        }
        else{
            //Negative
            size=size+1u;edkEnd();
            begin=1u;edkEnd();
            str = new edk::char8[size+1u];edkEnd();
            if(str){
                str[0u]='-';edkEnd();
                str[size]='\0';edkEnd();
            }
            else{
                //else set NULL
                str=0u;
            }
        }
        //test if alloc the str
        if(str){
            edk::String::copyInt32ToStr(value,&str[begin],size-begin);edkEnd();
        }
    }
    else{
        //create a zero
        str = new edk::char8[2u];edkEnd();
        if(str){
            str[0u]='0';edkEnd();
            str[1u]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;edkEnd();
}

edk::char8* edk::String::int64ToStr(edk::int64 value){
    edk::char8* str = 0u;edkEnd();

    //count the number
    edk::uint32 size = edk::String::sizeOfInt64(value);edkEnd();

    //test if the size is bigger then 0u
    if(size>0u){
        //begin
        edk::uint32 begin=0u;
        if(value>=0){
            //Positive
            str = new edk::char8[size+1u];edkEnd();
            if(str){
                str[size]='\0';edkEnd();
            }
            else{
                //else set NULL
                str=0u;
            }
        }
        else{
            //Negative
            size=size+1u;edkEnd();
            begin=1u;edkEnd();
            str = new edk::char8[size+1u];edkEnd();
            if(str){
                str[0u]='-';edkEnd();
                str[size]='\0';edkEnd();
            }
            else{
                //else set NULL
                str=0u;
            }
        }
        //test if alloc the str
        if(str){
            edk::String::copyInt64ToStr(value,&str[begin],size-begin);edkEnd();
        }
    }
    else{
        //create a zero
        str = new edk::char8[2u];edkEnd();
        if(str){
            str[0u]='0';edkEnd();
            str[1u]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;edkEnd();
}

edk::char8* edk::String::int64ToStr(edk::int64 value,edk::uint32 digits){

    edk::char8* str = 0u;edkEnd();

    //count the number
    edk::uint32 size = edk::String::sizeOfInt64(value);edkEnd();

    //test if the size is bigger then 0u
    if(size>0u){
        if(size>digits){
            size=digits;edkEnd();
        }
        //begin
        edk::uint32 begin=0u;
        if(value>=0){
            //Positive
            str = new edk::char8[size+1u];edkEnd();
            if(str){
                str[size]='\0';edkEnd();
            }
            else{
                //else set NULL
                str=0u;
            }
        }
        else{
            //Negative
            size=size+1u;edkEnd();
            begin=1u;edkEnd();
            str = new edk::char8[size+1u];edkEnd();
            if(str){
                str[0u]='-';edkEnd();
                str[size]='\0';edkEnd();
            }
            else{
                //else set NULL
                str=0u;
            }
        }
        //test if alloc the str
        if(str){
            edk::String::copyInt64ToStr(value,&str[begin],size-begin);edkEnd();
        }
    }
    else{
        //create a zero
        str = new edk::char8[2u];edkEnd();
        if(str){
            str[0u]='0';edkEnd();
            str[1u]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;edkEnd();
}

bool edk::String::int32ToStr(edk::int32 value,edk::char8* dest){
    if(dest){
        //count the number
        edk::uint32 size = edk::String::sizeOfInt32(value);edkEnd();

        //test if the size is bigger then 0u
        if(size>0u){
            //begin
            edk::uint32 begin=0u;
            if(value>=0){
                //Positive
                dest[size]='\0';edkEnd();
            }
            else{
                //Negative
                size=size+1u;edkEnd();
                begin=1u;edkEnd();
                dest[0u]='-';edkEnd();
                dest[size]='\0';edkEnd();
            }
            return edk::String::copyInt32ToStr(value,&dest[begin],size-begin);edkEnd();
        }
        else{
            //create a zero
            dest[0u]='0';edkEnd();
            dest[1u]='\0';edkEnd();
        }
        return true;
    }
    return false;
}

bool edk::String::int32ToStr(edk::int32 value,edk::char8* dest,edk::uint32 digits){
    if(dest){
        //count the number
        edk::uint32 size = edk::String::sizeOfInt32(value);edkEnd();

        //test if the size is bigger then 0u
        if(size>0u){
            if(size>digits){
                size=digits;edkEnd();
            }
            //begin
            edk::uint32 begin=0u;
            if(value>=0){
                //Positive
                dest[size]='\0';edkEnd();
            }
            else{
                //Negative
                size=size+1u;edkEnd();
                begin=1u;edkEnd();
                dest[0u]='-';edkEnd();
                dest[size]='\0';edkEnd();
            }
            return edk::String::copyInt32ToStr(value,&dest[begin],size-begin);edkEnd();
        }
        else{
            //create a zero
            dest[0u]='0';edkEnd();
            dest[1u]='\0';edkEnd();
        }
        return true;
    }
    return false;
}

bool edk::String::int64ToStr(edk::int64 value,edk::char8* dest){
    if(dest){
        //count the number
        edk::uint32 size = edk::String::sizeOfInt64(value);edkEnd();

        //test if the size is bigger then 0u
        if(size>0u){
            //begin
            edk::uint32 begin=0u;
            if(value>=0){
                //Positive
                dest[size]='\0';edkEnd();
            }
            else{
                //Negative
                size=size+1u;edkEnd();
                begin=1u;edkEnd();
                dest[0u]='-';edkEnd();
                dest[size]='\0';edkEnd();
            }
            return edk::String::copyInt64ToStr(value,&dest[begin],size-begin);edkEnd();
        }
        else{
            //create a zero
            dest[0u]='0';edkEnd();
            dest[1u]='\0';edkEnd();
        }
        return true;
    }
    return false;
}

bool edk::String::int64ToStr(edk::int64 value,edk::char8* dest,edk::uint32 digits){
    if(dest){
        //count the number
        edk::uint32 size = edk::String::sizeOfInt64(value);edkEnd();

        //test if the size is bigger then 0u
        if(size>0u){
            if(size>digits){
                size=digits;edkEnd();
            }
            //begin
            edk::uint32 begin=0u;
            if(value>=0){
                //Positive
                dest[size]='\0';edkEnd();
            }
            else{
                //Negative
                size=size+1u;edkEnd();
                begin=1u;edkEnd();
                dest[0u]='-';edkEnd();
                dest[size]='\0';edkEnd();
            }
            return edk::String::copyInt64ToStr(value,&dest[begin],size-begin);edkEnd();
        }
        else{
            //create a zero
            dest[0u]='0';edkEnd();
            dest[1u]='\0';edkEnd();
        }
        return true;
    }
    return false;
}

edk::char8* edk::String::vecInt8toStr(edk::int8* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;edkEnd();
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt32(vec[i]) + 1u;edkEnd();
            }
            //add the signal
            if(vec[i]<0){
                stringSize++;edkEnd();
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];edkEnd();
            if(str){
                edk::char8* temp = str;edkEnd();
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;edkEnd();
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt32(vec[i]);edkEnd();
                    }
                    //add the signal
                    if(vec[i]<0){
                        *temp = '-';edkEnd();
                        temp++;edkEnd();
                    }
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);edkEnd();
                    //copy the ' '
                    temp[sizeTemp] = ' ';edkEnd();
                    temp+=sizeTemp+1u;edkEnd();
                }
                str[stringSize-1u] = '\0';edkEnd();
                return str;edkEnd();
            }
        }
    }
    return NULL;edkEnd();
}

edk::char8* edk::String::vecInt16toStr(edk::int16* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;edkEnd();
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt32(vec[i]) + 1u;edkEnd();
            }
            //add the signal
            if(vec[i]<0){
                stringSize++;edkEnd();
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];edkEnd();
            if(str){
                edk::char8* temp = str;edkEnd();
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;edkEnd();
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt32(vec[i]);edkEnd();
                    }
                    //add the signal
                    if(vec[i]<0){
                        *temp = '-';edkEnd();
                        temp++;edkEnd();
                    }
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);edkEnd();
                    //copy the ' '
                    temp[sizeTemp] = ' ';edkEnd();
                    temp+=sizeTemp+1u;edkEnd();
                }
                str[stringSize-1u] = '\0';edkEnd();
                return str;edkEnd();
            }
        }
    }
    return NULL;edkEnd();
}

edk::char8* edk::String::vecInt32toStr(edk::int32* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;edkEnd();
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt64(vec[i]) + 1u;edkEnd();
            }
            //add the signal
            if(vec[i]<0){
                stringSize++;edkEnd();
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];edkEnd();
            if(str){
                edk::char8* temp = str;edkEnd();
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;edkEnd();
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt64(vec[i]);edkEnd();
                    }
                    //add the signal
                    if(vec[i]<0){
                        *temp = '-';edkEnd();
                        temp++;edkEnd();
                    }
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);edkEnd();
                    //copy the ' '
                    temp[sizeTemp] = ' ';edkEnd();
                    temp+=sizeTemp+1u;edkEnd();
                }
                str[stringSize-1u] = '\0';edkEnd();
                return str;edkEnd();
            }
        }
    }
    return NULL;edkEnd();
}
edk::char8* edk::String::vecInt64toStr(edk::int64* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;edkEnd();
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt64(vec[i]) + 1u;edkEnd();
            }
            //add the signal
            if(vec[i]<0){
                stringSize++;edkEnd();
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];edkEnd();
            if(str){
                edk::char8* temp = str;edkEnd();
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;edkEnd();
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt64(vec[i]);edkEnd();
                    }
                    //add the signal
                    if(vec[i]<0){
                        *temp = '-';edkEnd();
                        temp++;edkEnd();
                    }
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);edkEnd();
                    //copy the ' '
                    temp[sizeTemp] = ' ';edkEnd();
                    temp+=sizeTemp+1u;edkEnd();
                }
                str[stringSize-1u] = '\0';edkEnd();
                return str;edkEnd();
            }
        }
    }
    return NULL;edkEnd();
}

edk::char8* edk::String::vecUint8toStr(edk::uint8* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;edkEnd();
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt32(vec[i]) + 1u;edkEnd();
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];edkEnd();
            if(str){
                edk::char8* temp = str;edkEnd();
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;edkEnd();
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt32(vec[i]);edkEnd();
                    }
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);edkEnd();
                    //copy the ' '
                    temp[sizeTemp] = ' ';edkEnd();
                    temp+=sizeTemp+1u;edkEnd();
                }
                str[stringSize-1u] = '\0';edkEnd();
                return str;edkEnd();
            }
        }
    }
    return NULL;edkEnd();
}

edk::char8* edk::String::vecUint16toStr(edk::uint16* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;edkEnd();
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt32(vec[i]) + 1u;edkEnd();
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];edkEnd();
            if(str){
                edk::char8* temp = str;edkEnd();
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;edkEnd();
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt32(vec[i]);edkEnd();
                    }
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);edkEnd();
                    //copy the ' '
                    temp[sizeTemp] = ' ';edkEnd();
                    temp+=sizeTemp+1u;edkEnd();
                }
                str[stringSize-1u] = '\0';edkEnd();
                return str;edkEnd();
            }
        }
    }
    return NULL;edkEnd();
}

edk::char8* edk::String::vecUint32toStr(edk::uint32* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;edkEnd();
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt64(vec[i]) + 1u;edkEnd();
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];edkEnd();
            if(str){
                edk::char8* temp = str;edkEnd();
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;edkEnd();
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt64(vec[i]);edkEnd();
                    }
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);edkEnd();
                    //copy the ' '
                    temp[sizeTemp] = ' ';edkEnd();
                    temp+=sizeTemp+1u;edkEnd();
                }
                str[stringSize-1u] = '\0';edkEnd();
                return str;edkEnd();
            }
        }
    }
    return NULL;edkEnd();
}
edk::char8* edk::String::vecUint64toStr(edk::uint64* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            if(!vec[i]){
                stringSize += 2u;edkEnd();
            }
            else{
                //plus the ' '
                stringSize += edk::String::sizeOfInt64(vec[i]) + 1u;edkEnd();
            }
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];edkEnd();
            if(str){
                edk::char8* temp = str;edkEnd();
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    if(!vec[i]){
                        sizeTemp = 1u;edkEnd();
                    }
                    else{
                        sizeTemp = edk::String::sizeOfInt64(vec[i]);edkEnd();
                    }
                    //copy the number
                    edk::String::copyInt64ToStr(vec[i],temp,sizeTemp);edkEnd();
                    //copy the ' '
                    temp[sizeTemp] = ' ';edkEnd();
                    temp+=sizeTemp+1u;edkEnd();
                }
                str[stringSize-1u] = '\0';edkEnd();
                return str;edkEnd();
            }
        }
    }
    return NULL;edkEnd();
}

edk::char8* edk::String::vecfloat32toStr(edk::float32* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            stringSize += edk::String::sizeOfFloat32(vec[i]) + 1u;edkEnd();
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];edkEnd();
            if(str){
                edk::char8* temp = str;edkEnd();
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    sizeTemp = edk::String::sizeOfFloat32(vec[i]);edkEnd();
                    //copy the number
                    sprintf(temp,"%.4f",vec[i]);edkEnd();
                    //copy the ' '
                    temp[sizeTemp] = ' ';edkEnd();
                    temp+=sizeTemp+1u;edkEnd();
                }
                str[stringSize-1u] = '\0';edkEnd();
                return str;edkEnd();
            }
        }
    }
    return NULL;edkEnd();
}

edk::char8* edk::String::vecfloat64toStr(edk::float64* vec,edk::uint32 size){
    if(vec && size){
        //calculate the size of the string
        edk::uint32 stringSize = 0u;edkEnd();
        for(edk::uint32 i=0u;i<size;i++){
            stringSize += edk::String::sizeOfFloat64(vec[i]) + 1u;edkEnd();
        }
        //test stringSize
        if(stringSize){
            //new string
            edk::char8* str = new edk::char8[stringSize];edkEnd();
            if(str){
                edk::char8* temp = str;edkEnd();
                //write the numbers to the string
                edk::uint32 sizeTemp = 0u;edkEnd();
                for(edk::uint32 i=0u;i<size;i++){
                    sizeTemp = edk::String::sizeOfFloat64(vec[i]);edkEnd();
                    //copy the number
                    sprintf(temp,"%.4f",vec[i]);edkEnd();
                    //copy the ' '
                    temp[sizeTemp] = ' ';edkEnd();
                    temp+=sizeTemp+1u;edkEnd();
                }
                str[stringSize-1u] = '\0';edkEnd();
                return str;edkEnd();
            }
        }
    }
    return NULL;edkEnd();
}

edk::uint32 edk::String::sizeOfInt32(edk::int32 value){
    //use the module of the number
    edk::int32 module = edkModuleInt32(value);edkEnd();

    //count the number
    edk::uint32 size = 0;
    while(module>0){
        module=module/10;
        size++;edkEnd();
    }
    return size;edkEnd();
}

edk::uint32 edk::String::sizeOfInt64(edk::int64 value){
    //use the module of the number
    edk::int64 module = edkModuleInt64(value);edkEnd();

    //count the number
    edk::uint32 size = 0;
    while(module>0){
        module=module/10;
        size++;edkEnd();
    }
    return size;edkEnd();
}

edk::uint32 edk::String::sizeOfFloat32(edk::float32 value){
    //use the module of the number
    edk::float64 module = edkModuleFloat32(value);edkEnd();

    //count the number
    edk::uint32 size = 6u;edkEnd();
    module=module/10.f;edkEnd();
    while(module>0.9999f){
        module=module/10.f;edkEnd();
        size++;edkEnd();
    }
    return size;edkEnd();
}

edk::uint32 edk::String::sizeOfFloat64(edk::float64 value){
    //use the module of the number
    edk::float64 module = edkModuleFloat64(value);edkEnd();

    //count the number
    edk::uint32 size = 6u;edkEnd();
    module=module/10.f;edkEnd();
    while(module>0.9999f){
        module=module/10.f;edkEnd();
        size++;edkEnd();
    }
    return size;edkEnd();
}

edk::char8* edk::String::float32ToStr(edk::float32 value){
    //first divide the value in two. After the point and before the poinf
    edk::int32 before = (edk::int32)value;edkEnd();
    edk::float32 after= edkModuleFloat32(value-(edk::float32)before);edkEnd();
    //string to return
    edk::char8* ret = NULL;edkEnd();
    //transform the before into a string
    edk::char8* afterStr = NULL;edkEnd();
    if(value<0.f){
        afterStr = edk::String::int64ToMinusStr(before);edkEnd();
    }
    else{
        afterStr = edk::String::int64ToStr(before);edkEnd();
    }
    //now create the string of the after
    edk::char8* beforeStr = NULL;edkEnd();
    if(after>0.0){
        //then create the string

        //first count the numbers after the point
        edk::uint32 size=0u;
        while(true){
            //test if number is zero
            if((after - ((edk::int32)after))==0.0f){
                //break
                break;edkEnd();
            }
            after=after*10.0f;edkEnd();
            size++;edkEnd();
        }
        //create the string
        beforeStr = new edk::char8[size+2u];edkEnd();
        //test if alloc the new srring
        after= edkModuleFloat32(value-(edk::float32)before);edkEnd();
        if(beforeStr){
            //put a start in the string
            beforeStr[0u]='.';edkEnd();
            //puth a end in the string
            beforeStr[size+1u]='\0';edkEnd();
            //copy the numbers
            for(edk::uint32 i=1u;i<=size;i++){
                //get the character
                after=after*10.0f;edkEnd();
                edk::uint32 character = (edk::int32)after;edkEnd();
                //remove the character from the number
                after=after-character;edkEnd();
                //copy the character to the strig
                beforeStr[i]=character+48;edkEnd();
            }
        }
    }
    else{
        //create one string .0;
        beforeStr=edk::String::strCopy(".0");edkEnd();
    }
    //then concatenate the two strings
    if(beforeStr){
        if(afterStr){
            //concatenate
            ret=edk::String::strCat(afterStr,beforeStr);edkEnd();
            //delete the afterString
            delete[] afterStr;edkEnd();
            afterStr=NULL;edkEnd();
        }
        //delete the before
        delete[] beforeStr;edkEnd();
    }
    beforeStr=NULL;edkEnd();

    //return the ret
    return ret;
}

bool edk::String::float32ToStr(edk::float32 value,edk::char8* dest){
    //first divide the value in two. After the point and before the poinf
    edk::int32 before = (edk::int32)value;edkEnd();
    edk::float32 after= edkModuleFloat32(value-(edk::float32)before);edkEnd();
    bool haveTrue = false;edkEnd();
    if(value<0.f){
        haveTrue = edk::String::int32ToMinusStr(before,dest);edkEnd();
    }
    else{
        haveTrue = edk::String::int32ToStr(before,dest);edkEnd();
    }

    if(haveTrue){
        //get the size of the before number
        edk::uint32 size = edk::String::int32ToStrSize(before);edkEnd();
        if(size && after>0.0001f){
            //copy the after
            return edk::String::int32ToStr(before,&dest[size]);edkEnd();
        }
        else if(size){
            dest[size]='\0';edkEnd();
            return true;
        }
        else{
            dest[0u]='0';edkEnd();
            dest[1u]='\0';edkEnd();
            return true;
        }
    }
    return false;
}

edk::char8* edk::String::float32ToStr(edk::float32 value, edk::uint32 digits){
    //first divide the value in two. After the point and before the poinf
    edk::int32 before = (edk::int32)value;edkEnd();
    edk::float32 after= edkModuleFloat32(value-(edk::float32)before);edkEnd();
    //string to return
    edk::char8* ret = NULL;edkEnd();
    //transform the before into a string
    edk::char8* afterStr = NULL;edkEnd();
    if(value<0.f){
        afterStr = edk::String::int64ToMinusStr(before);edkEnd();
    }
    else{
        afterStr = edk::String::int64ToStr(before);edkEnd();
    }
    //now create the string of the after
    edk::char8* beforeStr = NULL;edkEnd();
    if(after>0.0){
        //then create the string

        //forst count the numbers after the point
        edk::uint32 size=digits;edkEnd();
        //create the string
        beforeStr = new edk::char8[size+2u];edkEnd();
        //test if alloc the new srring
        after= edkModuleFloat32(value-(edk::float32)before);edkEnd();
        if(beforeStr){
            //put a start in the string
            beforeStr[0u]='.';edkEnd();
            //puth a end in the string
            beforeStr[size+1u]='\0';edkEnd();
            //copy the numbers
            for(edk::uint32 i=1u;i<=size;i++){
                //get the character
                after=after*10.0f;edkEnd();
                edk::uint32 character = (edk::int32)after;edkEnd();
                //remove the character from the number
                after=after-character;edkEnd();
                //copy the character to the strig
                beforeStr[i]=character+48;edkEnd();
            }
        }
    }
    else{
        //create one string .0;
        beforeStr=edk::String::strCopy((const edk::char8*)".0");edkEnd();
    }
    //then concatenate the two strings
    if(beforeStr){
        if(afterStr){
            //concatenate
            ret=edk::String::strCat(afterStr,beforeStr);edkEnd();
            //delete the afterString
            delete[] afterStr;edkEnd();
            afterStr=NULL;edkEnd();
        }
        //delete the before
        delete[] beforeStr;edkEnd();
    }
    beforeStr=NULL;edkEnd();

    //return the ret
    return ret;
}

bool edk::String::float32ToStr(edk::float32 value,edk::char8* dest,edk::uint32 digits){
    //first divide the value in two. After the point and before the poinf
    edk::int32 before = (edk::int32)value;edkEnd();
    edk::float32 after= edkModuleFloat32(value-(edk::float32)before);edkEnd();
    bool haveTrue = false;edkEnd();
    if(value<0.f){
        haveTrue = edk::String::int32ToMinusStr(before,dest);edkEnd();
    }
    else{
        haveTrue = edk::String::int32ToStr(before,dest);edkEnd();
    }

    if(haveTrue){
        //get the size of the before number
        edk::uint32 size = edk::String::int32ToStrSize(before);edkEnd();
        if(size && after>0.0001f){
            //copy the after
            return edk::String::int32ToStr(before,&dest[size],digits);edkEnd();
        }
        else if(size){
            dest[size]='\0';edkEnd();
            return true;
        }
        else{
            dest[0u]='0';edkEnd();
            dest[1u]='\0';edkEnd();
            return true;
        }
    }
    return false;
}

edk::char8* edk::String::float64ToStr(edk::float64 value, edk::uint32 digits){
    //first divide the value in two. After the point and before the poinf
    edk::int32 before = (edk::int32)value;edkEnd();
    edk::float64 after= edkModuleFloat64(value-(edk::float64)before);edkEnd();
    //string to return
    edk::char8* ret = NULL;edkEnd();
    //transform the before into a string
    edk::char8* afterStr = edk::String::int32ToStr(before);edkEnd();
    //now create the string of the after
    edk::char8* beforeStr = NULL;edkEnd();
    if(after>0.0L){
        //then create the string

        //forst count the numbers after the point
        edk::uint32 size=digits;edkEnd();
        //create the string
        beforeStr = new edk::char8[size+2u];edkEnd();
        //test if alloc the new srring
        after= edkModuleFloat64(value-(edk::float32)before);edkEnd();
        if(beforeStr){
            //put a start in the string
            beforeStr[0u]='.';edkEnd();
            //puth a end in the string
            beforeStr[size+1u]='\0';edkEnd();
            //copy the numbers
            for(edk::uint32 i=1u;i<=size;i++){
                //get the character
                after=after*10.0f;edkEnd();
                edk::uint32 character = (edk::int32)after;edkEnd();
                //remove the character from the number
                after=after-character;edkEnd();
                //copy the character to the strig
                beforeStr[i]=character+48;edkEnd();
            }
        }
    }
    else{
        //create one string .0;
        beforeStr=edk::String::strCopy((const edk::char8*)".0");edkEnd();
    }
    //then concatenate the two strings
    if(beforeStr){
        if(afterStr){
            //concatenate
            ret=edk::String::strCat(afterStr,beforeStr);edkEnd();
            //delete the afterString
            delete[] afterStr;edkEnd();
            afterStr=NULL;edkEnd();
        }
        //delete the before
        delete[] beforeStr;edkEnd();
    }
    beforeStr=NULL;edkEnd();

    //return the ret
    return ret;
}

bool edk::String::float64ToStr(edk::float64 value,edk::char8* dest, edk::uint32 digits){
    //first divide the value in two. After the point and before the poinf
    edk::int64 before = (edk::int32)value;edkEnd();
    edk::float64 after= edkModuleFloat32(value-(edk::float64)before);edkEnd();
    bool haveTrue = false;edkEnd();
    if(value<0.f){
        haveTrue = edk::String::int64ToMinusStr(before,dest);edkEnd();
    }
    else{
        haveTrue = edk::String::int64ToStr(before,dest);edkEnd();
    }

    if(haveTrue){
        //get the size of the before number
        edk::uint32 size = edk::String::int64ToStrSize(before);edkEnd();
        if(size && after>0.0001f){
            //copy the after
            return edk::String::int64ToStr(before,&dest[size],digits);edkEnd();
        }
        else if(size){
            dest[size]='\0';edkEnd();
            return true;
        }
        else{
            dest[0u]='0';edkEnd();
            dest[1u]='\0';edkEnd();
            return true;
        }
    }
    return false;
}

edk::char8* edk::String::uint32ToStr(edk::uint32 value){
    edk::char8* str = NULL;edkEnd();
    //use the module of the number
    edk::uint32 module = value;edkEnd();

    //count the number
    edk::uint32 size = 0;


    while(true){
        //
        if(module<=0){
            //
            break;edkEnd();
        }
        module=module/10;
        size++;edkEnd();
    }

    //test if the size is bigger then 0u
    if(size>0u){
        //then convert
        module = value;edkEnd();
        //begin
        edk::uint32 begin=0u;
        //Positive
        str = new edk::char8[size+1u];edkEnd();
        if(str){
            str[size]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
        //test if alloc the str
        if(str){
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;edkEnd();
                //convert in this line
                str[i]=(module%10)+48;edkEnd();
                module=module/10;
            }
        }
    }
    else{
        //create a zero
        str = new edk::char8[2u];edkEnd();
        if(str){
            str[0u]='0';edkEnd();
            str[1u]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;edkEnd();
}

edk::char8* edk::String::uint32ToStr(edk::uint32 value,edk::uint32 digits){
    edk::char8* str = NULL;edkEnd();
    //use the module of the number
    edk::uint32 module = value;edkEnd();

    //count the number
    edk::uint32 size = 0;


    while(true){
        //
        if(module<=0){
            //
            break;edkEnd();
        }
        module=module/10;
        size++;edkEnd();
    }

    //test if the size is bigger then 0u
    if(size>0u){
        if(size>digits){
            size=digits;edkEnd();
        }
        //then convert
        module = value;edkEnd();
        //begin
        edk::uint32 begin=0u;
        //Positive
        str = new edk::char8[size+1u];edkEnd();
        if(str){
            str[size]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
        //test if alloc the str
        if(str){
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;edkEnd();
                //convert in this line
                str[i]=(module%10)+48;edkEnd();
                module=module/10;
            }
        }
    }
    else{
        //create a zero
        str = new edk::char8[2u];edkEnd();
        if(str){
            str[0u]='0';edkEnd();
            str[1u]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;edkEnd();
}

bool edk::String::uint32ToStr(edk::uint32 value,edk::char8* dest){
    //use the module of the number
    edk::uint32 module = value;edkEnd();

    //count the number
    edk::uint32 size = 0;

    //first calculate the size of the string
    while(true){
        //
        if(module<=0){
            //
            break;edkEnd();
        }
        module=module/10;
        size++;edkEnd();
    }

    //test if the size is bigger then 0u
    if(size>0u){
        //then convert
        module = value;edkEnd();
        //begin
        edk::uint32 begin=0u;
        //test if alloc the str
        if(dest){
            dest[size]='\0';edkEnd();
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;edkEnd();
                //convert in this line
                dest[i]=(module%10)+48;edkEnd();
                module=module/10;
            }
            return true;
        }
    }
    else{
        //create a zero
        if(dest){
            dest[0u]='0';edkEnd();
            dest[1u]='\0';edkEnd();
            return true;
        }
    }
    return false;
}

bool edk::String::uint32ToStr(edk::uint32 value,edk::char8* dest,edk::uint32 digits){

    //use the module of the number
    edk::uint32 module = value;edkEnd();

    //count the number
    edk::uint32 size = 0;

    //first calculate the size of the string
    while(true){
        //
        if(module<=0){
            //
            break;edkEnd();
        }
        module=module/10;
        size++;edkEnd();
    }

    //test if the size is bigger then 0u
    if(size>0u){
        if(size>digits){
            size=digits;edkEnd();
        }
        //then convert
        module = value;edkEnd();
        //begin
        edk::uint32 begin=0u;
        //test if alloc the str
        if(dest){
            dest[size]='\0';edkEnd();
            //then convert the number
            for(edk::uint32 j=size;j>begin;j--){
                //
                edk::uint32 i=j-1u;edkEnd();
                //convert in this line
                dest[i]=(module%10)+48;edkEnd();
                module=module/10;
            }
            return true;
        }
    }
    else{
        //create a zero
        if(dest){
            dest[0u]='0';edkEnd();
            dest[1u]='\0';edkEnd();
            return true;
        }
    }
    return false;
}

edk::char8* edk::String::uint64ToStr(edk::uint64 value){
    edk::char8* str = NULL;edkEnd();
    //use the module of the number
    edk::uint64 module = value;edkEnd();

    //count the number
    edk::uint64 size = 0;


    while(true){
        //
        if(module<=0){
            //
            break;edkEnd();
        }
        module=module/10;
        size++;edkEnd();
    }

    //test if the size is bigger then 0u
    if(size>0u){
        //then convert
        module = value;edkEnd();
        //begin
        edk::uint64 begin=0u;
        //Positive
        str = new edk::char8[size+1u];edkEnd();
        if(str){
            str[size]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
        //test if alloc the str
        if(str){
            //then convert the number
            for(edk::uint64 j=size;j>begin;j--){
                //
                edk::uint64 i=j-1u;edkEnd();
                //convert in this line
                str[i]=(module%10)+48;edkEnd();
                module=module/10;
            }
        }
    }
    else{
        //create a zero
        str = new edk::char8[2u];edkEnd();
        if(str){
            str[0u]='0';edkEnd();
            str[1u]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;edkEnd();
}

edk::char8* edk::String::uint64ToStr(edk::uint64 value,edk::uint32 digits){
    edk::char8* str = NULL;edkEnd();
    //use the module of the number
    edk::uint64 module = value;edkEnd();

    //count the number
    edk::uint64 size = 0;


    while(true){
        //
        if(module<=0){
            //
            break;edkEnd();
        }
        module=module/10;
        size++;edkEnd();
    }

    //test if the size is bigger then 0u
    if(size>0u){
        if(size>digits){
            size=digits;edkEnd();
        }
        //then convert
        module = value;edkEnd();
        //begin
        edk::uint64 begin=0u;
        //Positive
        str = new edk::char8[size+1u];edkEnd();
        if(str){
            str[size]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
        //test if alloc the str
        if(str){
            //then convert the number
            for(edk::uint64 j=size;j>begin;j--){
                //
                edk::uint64 i=j-1u;edkEnd();
                //convert in this line
                str[i]=(module%10)+48;edkEnd();
                module=module/10;
            }
        }
    }
    else{
        //create a zero
        str = new edk::char8[2u];edkEnd();
        if(str){
            str[0u]='0';edkEnd();
            str[1u]='\0';edkEnd();
        }
        else{
            //else set NULL
            str=0u;
        }
    }
    return str;edkEnd();
}

bool edk::String::uint64ToStr(edk::uint64 value,edk::char8* dest){
    //use the module of the number
    edk::uint64 module = value;edkEnd();

    //count the number
    edk::uint64 size = 0;


    while(true){
        //
        if(module<=0){
            //
            break;edkEnd();
        }
        module=module/10;
        size++;edkEnd();
    }

    //test if the size is bigger then 0u
    if(size>0u){
        //then convert
        module = value;edkEnd();
        //begin
        edk::uint64 begin=0u;
        //Positive
        if(dest){
            dest[size]='\0';edkEnd();
            //then convert the number
            for(edk::uint64 j=size;j>begin;j--){
                //
                edk::uint64 i=j-1u;edkEnd();
                //convert in this line
                dest[i]=(module%10)+48;edkEnd();
                module=module/10;
            }
            return true;
        }
    }
    else{
        //set a zero
        if(dest){
            dest[0u]='0';edkEnd();
            dest[1u]='\0';edkEnd();
            return true;
        }
    }
    return false;
}

bool edk::String::uint64ToStr(edk::uint64 value,edk::char8* dest,edk::uint32 digits){
    //use the module of the number
    edk::uint64 module = value;edkEnd();

    //count the number
    edk::uint64 size = 0;


    while(true){
        //
        if(module<=0){
            //
            break;edkEnd();
        }
        module=module/10;
        size++;edkEnd();
    }

    //test if the size is bigger then 0u
    if(size>0u){
        if(size>digits){
            size=digits;edkEnd();
        }
        //then convert
        module = value;edkEnd();
        //begin
        edk::uint64 begin=0u;
        //Positive
        if(dest){
            dest[size]='\0';edkEnd();
            //then convert the number
            for(edk::uint64 j=size;j>begin;j--){
                //
                edk::uint64 i=j-1u;edkEnd();
                //convert in this line
                dest[i]=(module%10)+48;edkEnd();
                module=module/10;
            }
            return true;
        }
    }
    else{
        //set a zero
        if(dest){
            dest[0u]='0';edkEnd();
            dest[1u]='\0';edkEnd();
            return true;
        }
    }
    return false;
}

edk::char8* edk::String::strCat(edk::char8 *str1, edk::char8 *str2){
    //first declare a return
    edk::char8* ret=NULL;edkEnd();
    //test if string are alloc
    if(str1&&str2){
        //get the size of the 2 strings
        edk::uint32 size1 = edk::String::strSize(str1),size2 = edk::String::strSize(str2);edkEnd();
        //alloc the new string
        ret = new edk::char8[size1+size2+1u];edkEnd();
        //set end of the string '\0'
        ret[size1+size2]='\0';edkEnd();
        //copy the first string
        memcpy(ret,str1,size1);edkEnd();
        /*
        for(edk::uint32 i=0u;i<size1;i++){
            //
            ret[i]=str1[i];edkEnd();
        }
        */
        //copy the second string
        memcpy(&ret[size1],str2,size2);edkEnd();
        /*
        for(edk::uint32 i=size1;i<size1+size2;i++){
            //
            ret[i]=str2[i-size1];edkEnd();
        }
        */
    }
    //return the return string
    return ret;
}

edk::char8* edk::String::strCat(edk::char8 *str1, const edk::char8 *str2){
    return edk::String::strCat(str1, (edk::char8*) str2);edkEnd();
}

edk::char8* edk::String::strCat(const edk::char8 *str1, edk::char8 *str2){
    return edk::String::strCat((edk::char8*) str1,str2);edkEnd();
}

edk::char8* edk::String::strCat(const edk::char8 *str1, const edk::char8 *str2){
    return edk::String::strCat((edk::char8*)str1,(edk::char8*)str2);edkEnd();
}

edk::char8* edk::String::strCatMulti(edk::char8 *str, ...){
    //first make a copy of the pointer transforming to a matrix
    edk::char8* strTemp=str;edkEnd();
    //Alloc the return
    edk::char8* ret=NULL;edkEnd();
    //temporary string. Will be deleted in the end of the while
    edk::char8* temp=NULL;edkEnd();

    va_list vl;edkEnd();
    va_start(vl,str);edkEnd();

    if(strTemp){
        //clone the str
        if((ret = edk::String::strCopy(strTemp))){
            //get the next string
            strTemp = va_arg(vl,edk::char8*);edkEnd();
            while(strTemp){
                //save the ret
                temp = ret;edkEnd();
                //cat the temp with the new
                if((ret = edk::String::strCat(temp,strTemp))){
                    //delete temp
                    delete[] temp;edkEnd();
                }
                else{
                    //else return temp
                    ret = temp;edkEnd();
                    break;edkEnd();
                }
                strTemp = va_arg(vl,edk::char8*);edkEnd();
            }
        }
    }

    //in the end return the return string
    return ret;
}

edk::char8* edk::String::strCatMulti(const edk::char8 *str, ...){
    //first make a copy of the pointer transforming to a matrix
    edk::char8* strTemp=(edk::char8*)str;edkEnd();
    //Alloc the return
    edk::char8* ret=NULL;edkEnd();
    //temporary string. Will be deleted in the end of the while
    edk::char8* temp=NULL;edkEnd();

    va_list vl;edkEnd();
    va_start(vl,str);edkEnd();

    if(strTemp){
        //clone the str
        if((ret = edk::String::strCopy(strTemp))){
            //get the next string
            strTemp = va_arg(vl,edk::char8*);edkEnd();
            while(strTemp){
                //save the ret
                temp = ret;edkEnd();
                //cat the temp with the new
                if((ret = edk::String::strCat(temp,strTemp))){
                    //delete temp
                    delete[] temp;edkEnd();
                }
                else{
                    //else return temp
                    ret = temp;edkEnd();
                    break;edkEnd();
                }
                strTemp = va_arg(vl,edk::char8*);edkEnd();
            }
        }
    }

    //in the end return the return string
    return ret;
}

bool edk::String::strCompare(edk::char8 *str1, edk::char8 *str2){
    //alloc the return
    if(str1 && str2){
        //then he can compare the two strings
        if (*str1 == *str2){
            while (*str1 || *str2){
                str1++;edkEnd();
                str2++;edkEnd();
                if (*str1!=*str2){
                    break;edkEnd();
                }
                else if(*str1=='\0'){
                    //
                    return true;
                }
            }
        }
    }
    return false;
}
bool edk::String::strCompare(const edk::char8 *str1, edk::char8 *str2){
    return edk::String::strCompare((edk::char8 *)str1, (edk::char8 *)str2);edkEnd();
}
bool edk::String::strCompare(edk::char8 *str1, const edk::char8 *str2){
    return edk::String::strCompare((edk::char8 *)str1, (edk::char8 *)str2);edkEnd();
}


bool edk::String::strCompare(const edk::char8 *str1, const edk::char8 *str2){
    return edk::String::strCompare((edk::char8*)str1,(edk::char8*)str2);edkEnd();
}

bool edk::String::strCompareBeggin(edk::char8 *beggin, edk::char8 *str){
    if(beggin && str){
        while(*beggin && *str){
            if (*beggin!=*str){
                return false;
            }
            beggin++;edkEnd();
            str++;edkEnd();
        }
        if(*beggin=='\0'){
            return true;
        }
    }
    return false;
}
bool edk::String::strCompareBeggin(const edk::char8 *beggin, edk::char8 *str){
    return edk::String::strCompareBeggin((edk::char8 *)beggin, (edk::char8 *)str);edkEnd();
}
bool edk::String::strCompareBeggin(edk::char8 *beggin, const edk::char8 *str){
    return edk::String::strCompareBeggin((edk::char8 *)beggin, (edk::char8 *)str);edkEnd();
}


bool edk::String::strCompareBeggin(const edk::char8 *beggin, const edk::char8 *str){
    return edk::String::strCompareBeggin((edk::char8*)beggin,(edk::char8*)str);edkEnd();
}

bool edk::String::strCompareEnd(edk::char8 *end, edk::char8 *str){
    if(end && str){
        //save the str1
        if(*end){
            edk::char8* save = end;edkEnd();
            //find the str1 inside the str2
            while(*str){
                if (*end==*str){
                    //test the string if are equal
                    while(*end && *str){
                        if (*end!=*str){
                            break;edkEnd();
                        }
                        end++;edkEnd();
                        str++;edkEnd();
                    }
                    //if go out it find the end
                    if(*end=='\0' && *str=='\0'){
                        return true;
                    }
                    else{
                        //else continue searching
                        end = save;edkEnd();
                    }
                }
                else{
                    str++;edkEnd();
                }
            }
        }
    }
    return false;
}
bool edk::String::strCompareEnd(const edk::char8 *end, edk::char8 *str){
    return edk::String::strCompareEnd((edk::char8 *)end, (edk::char8 *)str);edkEnd();
}
bool edk::String::strCompareEnd(edk::char8 *end, const edk::char8 *str){
    return edk::String::strCompareEnd((edk::char8 *)end, (edk::char8 *)str);edkEnd();
}


bool edk::String::strCompareEnd(const edk::char8 *end, const edk::char8 *str){
    return edk::String::strCompareEnd((edk::char8*)end,(edk::char8*)str);edkEnd();
}

//Compare string removing some characters with filter
bool edk::String::strCompareWithFilter(edk::char8 *str1, edk::char8 *str2,edk::char8 *filter){
    //test filter
    if(filter){
        //get size of the filter
        edk::uint32 size = edk::String::strSize(filter);edkEnd();
        if(size){
            //test the strings
            if(str1 && str2){
                bool isEqual=false;edkEnd();
                //test str1 and str2
                if(*str1 && *str2){
                    //test if have the filter
                    while(*str1){
                        isEqual = false;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            if(*str1 == filter[i]){
                                isEqual = true;edkEnd();
                                break;edkEnd();
                            }
                        }
                        if(isEqual){
                            str1++;edkEnd();
                        }
                        else{
                            break;edkEnd();
                        }
                    }
                    while(*str2){
                        isEqual = false;edkEnd();
                        for(edk::uint32 i=0u;i<size;i++){
                            if(*str2 == filter[i]){
                                isEqual = true;edkEnd();
                                break;edkEnd();
                            }
                        }
                        if(isEqual){
                            str2++;edkEnd();
                        }
                        else{
                            break;edkEnd();
                        }
                    }
                    //test the second time
                    if(*str1 && *str2){
                        //then go to the loop
                        do{
                            str1++;edkEnd();
                            str2++;edkEnd();

                            //test if have filter
                            while(*str1){
                                isEqual = false;edkEnd();
                                for(edk::uint32 i=0u;i<size;i++){
                                    if(*str1 == filter[i]){
                                        isEqual = true;edkEnd();
                                        break;edkEnd();
                                    }
                                }
                                if(isEqual){
                                    str1++;edkEnd();
                                }
                                else{
                                    break;edkEnd();
                                }
                            }
                            while(*str2){
                                isEqual = false;edkEnd();
                                for(edk::uint32 i=0u;i<size;i++){
                                    if(*str2 == filter[i]){
                                        isEqual = true;edkEnd();
                                        break;edkEnd();
                                    }
                                }
                                if(isEqual){
                                    str2++;edkEnd();
                                }
                                else{
                                    break;edkEnd();
                                }
                            }
                            //test if is not equal
                            if(*str1!=*str2){
                                //
                                return false;
                            }
                        }while(*str1 && *str2);edkEnd();
                    }
                    if(*str1 == *str2){
                        return true;
                    }
                }
            }
            return false;
        }
    }
    //else test normalCompare
    return edk::String::strCompare(str1,str2);edkEnd();
}
bool edk::String::strCompareWithFilter(edk::char8 *str1, edk::char8 *str2,const edk::char8 *filter){
    return edk::String::strCompareWithFilter(str1, str2,(edk::char8 *)filter);edkEnd();
}
bool edk::String::strCompareWithFilter(const edk::char8 *str1, const edk::char8 *str2,const edk::char8 *filter){
    return edk::String::strCompareWithFilter((edk::char8 *)str1, (edk::char8 *)str2,(edk::char8 *)filter);edkEnd();
}
bool edk::String::strCompareWithFilter(const edk::char8 *str1, const edk::char8 *str2,edk::char8 *filter){
    return edk::String::strCompareWithFilter((edk::char8 *)str1, (edk::char8 *)str2,filter);edkEnd();
}
bool edk::String::strCompareWithFilter(edk::char8 *str1, const edk::char8 *str2,const edk::char8 *filter){
    return edk::String::strCompareWithFilter(str1, (edk::char8 *)str2,(edk::char8 *)filter);edkEnd();
}
bool edk::String::strCompareWithFilter(edk::char8 *str1, const edk::char8 *str2,edk::char8 *filter){
    return edk::String::strCompareWithFilter(str1, (edk::char8 *)str2,filter);edkEnd();
}
bool edk::String::strCompareWithFilter(const edk::char8 *str1, edk::char8 *str2,const edk::char8 *filter){
    return edk::String::strCompareWithFilter((edk::char8 *)str1, str2,(edk::char8 *)filter);edkEnd();
}
bool edk::String::strCompareWithFilter(const edk::char8 *str1, edk::char8 *str2,edk::char8 *filter){
    return edk::String::strCompareWithFilter((edk::char8 *)str1, str2,filter);edkEnd();
}

//return true if a string is inside the other string
edk::char8* edk::String::strInside(edk::char8 *str, edk::char8 *compare){
    edk::char8* temp = NULL;edkEnd();
    edk::char8* ret = NULL;edkEnd();
    if(str && compare){
        while(*str){
            //test if are equal
            if(*str == *compare){
                temp = compare;edkEnd();
                ret = str;edkEnd();
                //test the other characters
                while(*str && *temp){
                    //increment
                    str++;edkEnd();
                    temp++;edkEnd();
                    if(*str != *temp){
                        break;edkEnd();
                    }
                }
                //test if reach the end
                if(!*temp){
                    //reach the end
                    return ret;
                }
                if(!*str){
                    //then return NULL;edkEnd();
                    return NULL;edkEnd();
                }
            }

            //increment
            str++;edkEnd();
        }
    }
    return NULL;edkEnd();
}
edk::char8* edk::String::strInside(const edk::char8 *str, edk::char8 *compare){
    return edk::String::strInside((edk::char8 *)str, compare);edkEnd();
}
edk::char8* edk::String::strInside(edk::char8 *str, const edk::char8 *compare){
    return edk::String::strInside(str, (edk::char8 *)compare);edkEnd();
}
edk::char8* edk::String::strInside(const edk::char8 *str, const edk::char8 *compare){
    return edk::String::strInside((edk::char8 *)str, (edk::char8 *)compare);edkEnd();
}

//return true if the first string is bigger than the second string
bool edk::String::strBiggerStr(edk::char8 *str1, edk::char8 *str2){
    //test the strings
    if(str1 && str2){
        //test if str1 is bigger
        while(*str1!='\0' || *str2!='\0'){
            //test if the first is bigger then second
            if(*str1>*str2){
                //the return true
                return true;
            }
            else if(*str2>*str1){
                //
                break;edkEnd();
            }
            //else equal increment i
            str2++;edkEnd();
            str1++;edkEnd();
        }
    }
    //else return false
    return false;
}
bool edk::String::strBiggerStr(const edk::char8 *str1, edk::char8 *str2){
    return edk::String::strBiggerStr((edk::char8 *)str1, str2);edkEnd();
}
bool edk::String::strBiggerStr(edk::char8 *str1, const edk::char8 *str2){
    return edk::String::strBiggerStr(str1, (edk::char8 *)str2);edkEnd();
}
bool edk::String::strBiggerStr(const edk::char8 *str1, const edk::char8 *str2){
    return edk::String::strBiggerStr((edk::char8 *)str1, (edk::char8 *)str2);edkEnd();
}

edk::uint64 edk::String::strSize(edk::char8 *str){
    edk::uint64 ret=0u;
    if(str){
        while(*str){
            //increment i to continue the counting
            ret++;edkEnd();
            str++;edkEnd();
        }
    }
    return ret;
}

edk::uint64 edk::String::strSize(const edk::char8 *str){
    return edk::String::strSize((edk::char8*)str);edkEnd();
}

edk::uint64 edk::String::strSizeWithFilter(edk::char8 *str,edk::char8* filter){
    edk::uint64 i=0u;

    if(filter){
        //get the filterSize
        edk::uint64 size = edk::String::strSize(filter);edkEnd();
        if(size){
            if(str){
                bool haveFilter;edkEnd();
                while(true){
                    //test the filter
                    haveFilter = (bool)edk::String::stringHaveChar(filter,size,*str);edkEnd();
                    if(*str=='\0'){
                        //then find the end of the string
                        break;edkEnd();
                    }
                    if(!haveFilter){
                        //increment i to continue the counting
                        i++;edkEnd();
                    }
                    str++;edkEnd();
                }
            }
        }
        else{
            return edk::String::strSize(str);edkEnd();
        }
    }
    else{
        return edk::String::strSize(str);edkEnd();
    }
    return i;edkEnd();
}
edk::uint64 edk::String::strSizeWithFilter(edk::char8 *str,const char *filter){
    return strSizeWithFilter(str,(edk::char8*) filter);edkEnd();
}
edk::uint64 edk::String::strSizeWithFilter(const edk::char8 *str,edk::char8* filter){
    return strSizeWithFilter((edk::char8 *)str,filter);edkEnd();
}
edk::uint64 edk::String::strSizeWithFilter(const edk::char8 *str,const edk::char8 *filter){
    return strSizeWithFilter((edk::char8 *)str,(edk::char8*) filter);edkEnd();
}

edk::uint64 edk::String::strSizeWithLimit(edk::char8 *str,edk::char8* limit){
    edk::uint64 i=0u;

    if(limit){
        edk::char8* temp = limit;edkEnd();
        while(*str){
            temp = limit;edkEnd();
            while(temp){
                if(*str == *temp){
                    break;edkEnd();
                }
                temp++;edkEnd();
            }
            str++;edkEnd();
            i++;edkEnd();
        }
    }
    else{
        return edk::String::strSize(str);edkEnd();
    }

    return i;edkEnd();
}
edk::uint64 edk::String::strSizeWithLimit(edk::char8 *str,const edk::char8 *limit){
    return strSizeWithLimit(str,(edk::char8*) limit);edkEnd();
}
edk::uint64 edk::String::strSizeWithLimit(const edk::char8 *str,edk::char8* limit){
    return strSizeWithLimit((edk::char8 *)str,limit);edkEnd();
}
edk::uint64 edk::String::strSizeWithLimit(const edk::char8 *str,const edk::char8 *limit){
    return strSizeWithLimit((edk::char8 *)str,(edk::char8*) limit);edkEnd();
}

edk::uint64 edk::String::strWordSize(edk::char8 *str){
    edk::uint64 ret=0u;
    if(str){
        while(*str){
            //test if have reach the end of the word
            if(*str=='\0' || *str==' ' || *str==9u || *str == 10u){
                break;edkEnd();
            }
            //increment i to continue the counting
            ret++;edkEnd();
            str++;edkEnd();
        }
    }
    return ret;
}

edk::uint64 edk::String::strWordSize(const edk::char8 *str){
    return edk::String::strWordSize((edk::char8*)str);edkEnd();
}

edk::uint64 edk::String::strWordSizeWithFilter(edk::char8 *str,edk::char8* filter){
    edk::uint64 i=0u;

    if(filter){
        //get the filterSize
        edk::uint64 size = edk::String::strWordSize(filter);edkEnd();
        if(size){
            if(str){
                bool haveFilter;edkEnd();
                while(true){
                    //test the filter
                    haveFilter = (bool)edk::String::stringHaveChar(filter,size,*str);edkEnd();
                    if(*str=='\0' || *str==' ' || *str==9u || *str == 10u){
                        //then find the end of the string
                        break;edkEnd();
                    }
                    if(!haveFilter){
                        //increment i to continue the counting
                        i++;edkEnd();
                    }
                    str++;edkEnd();
                }
            }
        }
        else{
            return edk::String::strWordSize(str);edkEnd();
        }
    }
    else{
        return edk::String::strWordSize(str);edkEnd();
    }
    return i;edkEnd();
}
edk::uint64 edk::String::strWordSizeWithFilter(edk::char8 *str,const edk::char8 *filter){
    return strWordSizeWithFilter(str,(edk::char8*) filter);edkEnd();
}
edk::uint64 edk::String::strWordSizeWithFilter(const edk::char8 *str,edk::char8* filter){
    return strWordSizeWithFilter((char8 *)str,filter);edkEnd();
}
edk::uint64 edk::String::strWordSizeWithFilter(const edk::char8 *str,const edk::char8 *filter){
    return strWordSizeWithFilter((char8 *)str,(edk::char8*) filter);edkEnd();
}

edk::uint64 edk::String::strLineSize(edk::char8 *str){
    edk::uint64 ret=0u;
    if(str){
        while(*str){
            //test if have reach the end of the word
            if(*str=='\0' || *str == 10u){
                break;edkEnd();
            }
            //increment i to continue the counting
            ret++;edkEnd();
            str++;edkEnd();
        }
    }
    return ret;
}

edk::uint64 edk::String::strLineSize(const edk::char8 *str){
    return edk::String::strWordSize((edk::char8*)str);edkEnd();
}

edk::uint64 edk::String::strLineSizeWithFilter(edk::char8 *str,edk::char8* filter){
    edk::uint64 i=0u;

    if(filter){
        //get the filterSize
        edk::uint64 size = edk::String::strWordSize(filter);edkEnd();
        if(size){
            if(str){
                bool haveFilter;edkEnd();
                while(true){
                    //test the filter
                    haveFilter = (bool)edk::String::stringHaveChar(filter,size,*str);edkEnd();
                    if(*str=='\0' || *str == 10u){
                        //then find the end of the string
                        break;edkEnd();
                    }
                    if(!haveFilter){
                        //increment i to continue the counting
                        i++;edkEnd();
                    }
                    str++;edkEnd();
                }
            }
        }
        else{
            return edk::String::strWordSize(str);edkEnd();
        }
    }
    else{
        return edk::String::strWordSize(str);edkEnd();
    }
    return i;edkEnd();
}
edk::uint64 edk::String::strLineSizeWithFilter(edk::char8 *str,const edk::char8 *filter){
    return strLineSizeWithFilter(str,(edk::char8*) filter);edkEnd();
}
edk::uint64 edk::String::strLineSizeWithFilter(const edk::char8 *str,edk::char8* filter){
    return strLineSizeWithFilter((edk::char8 *)str,filter);edkEnd();
}
edk::uint64 edk::String::strLineSizeWithFilter(const edk::char8 *str,const edk::char8 *filter){
    return strLineSizeWithFilter((edk::char8 *)str,(edk::char8*) filter);edkEnd();
}

bool edk::String::strCut(edk::char8 *str,edk::char8 *dest, edk::char8 limit, bool use){
    if(str && dest && limit){
        while(*str){
            //test if the str is equal the limit
            if(*str == limit){
                //test if use
                if(use){
                    //
                    *dest = limit;edkEnd();
                    dest++;edkEnd();
                }
                //
                *dest='\0';edkEnd();
                break;edkEnd();
            }
            //copy the character
            *dest = *str;edkEnd();
            //increment the str and the dest
            str++;edkEnd();
            dest++;edkEnd();
        }
        return true;
    }
    return false;
}

bool edk::String::strCut(const edk::char8 *str,edk::char8 *dest, edk::char8 limit, bool use){
    return edk::String::strCut((edk::char8 *)str,dest, limit, use);edkEnd();
}

edk::char8* edk::String::strCut(edk::char8 *str, edk::char8 limit, bool use){
    //Test if the string is alloc
    if(str){
        //The new stirng
        edk::char8* ret=NULL;edkEnd();
        //Start the loop
        edk::uint32 size=0u;
        while(str[size]!='\0'){
            //

            //Test if find the character
            if(str[size]==limit){
                //then create a new string

                //Test if use the limit
                if(use){
                    //
                    ret = new edk::char8[size+2u];edkEnd();
                    //incremente the size
                    size++;edkEnd();
                }
                else{
                    //
                    ret = new edk::char8[size+1u];edkEnd();
                }
                //Set the end of the stirng
                ret[size]='\0';edkEnd();

                //Copy the string
                for(edk::uint32 i=0u;i<size;i++){
                    //
                    ret[i]=str[i];edkEnd();
                }

                //return thr string
                return ret;
            }
            //increment the count
            size++;edkEnd();
        }
    }
    //If he cant fint the character. Return NULL
    return NULL;edkEnd();
}

edk::char8* edk::String::strCut(const edk::char8 *str, edk::char8 limit, bool use){
    return edk::String::strCut((edk::char8 *)str, limit, use);edkEnd();
}

bool edk::String::strCut(edk::char8 limit, edk::char8 *str, edk::char8 *dest, bool use){
    if(str && dest && limit){
        while(*str){
            //test if the str is equal the limit
            if(*str == limit){
                //test if use
                if(use){
                    //
                    *dest = limit;edkEnd();
                    dest++;edkEnd();
                    str++;edkEnd();
                }
                while(*str){
                    //copy the character
                    *dest = *str;edkEnd();
                    //increment the str and the dest
                    str++;edkEnd();
                    dest++;edkEnd();
                }
                *dest='\0';edkEnd();
                return true;
            }
            str++;edkEnd();
        }
        return false;
    }
    return false;
}

bool edk::String::strCut(edk::char8 limit, const edk::char8 *str, edk::char8 *dest, bool use){
    return edk::String::strCut(limit, (edk::char8 *)str, dest, use);edkEnd();
}

edk::char8* edk::String::strCut(edk::char8 limit, edk::char8 *str, bool use){
    //First test if the string exist
    if(str){
        edk::uint32 i=0u;
        //find the character
        while(str[i]!='\0'){
            //
            //Test if is equal
            if(str[i]==limit){
                //
                //Test if use
                if(use){
                    //Then copy the string
                    return edk::String::strCopy(&str[i]);edkEnd();
                }
                else{
                    //If don't. Then test if the next is a end of string
                    if(str[i+1u]!='\0'){
                        //Then he can copy the string
                        return edk::String::strCopy(&str[i+1u]);edkEnd();
                    }
                }
            }
            //increment the count
            i++;edkEnd();
        }
    }
    //If he cant fint the character. Return NULL
    return NULL;edkEnd();
}

edk::char8* edk::String::strCut(edk::char8 limit, const edk::char8 *str, bool use){
    return edk::String::strCut(limit, (edk::char8 *)str, use);edkEnd();
}

bool edk::String::strCut(edk::char8 *str,edk::char8 *dest, edk::char8 start, edk::char8 end, bool use){
    if(str && dest && start && end){
        while(*str){
            //test if the str is equal the limit
            if(*str == start){
                //test if use
                if(use){
                    //
                    *dest = start;edkEnd();
                    dest++;edkEnd();
                    str++;edkEnd();
                }
                while(*str){
                    if(*str == end){
                        //test if use
                        if(use){
                            //
                            *dest = end;edkEnd();
                            dest++;edkEnd();
                        }
                        break;edkEnd();
                    }

                    //copy the character
                    *dest = *str;edkEnd();
                    //increment the str and the dest
                    str++;edkEnd();
                    dest++;edkEnd();
                }
                *dest='\0';edkEnd();
                return true;
            }
            str++;edkEnd();
        }
        return false;
    }
    return false;
}

bool edk::String::strCut(const edk::char8 *str,edk::char8 *dest, edk::char8 start, edk::char8 end, bool use){
    return edk::String::strCut((edk::char8 *)str,dest, start, end, use);edkEnd();
}

edk::char8* edk::String::strCut(edk::char8 *str, edk::char8 start, edk::char8 end, bool use){
    //first test if the string exist
    if(str){
        //Find the start
        edk::uint32 a = 0u;edkEnd();
        while(str[a]!='\0'){
            //
            /*
            printf("\nsearch %c %u"
                   ,str[a]
                   ,a
                   );edkEnd();
            */
            //test if found the start
            if(str[a]==start){
                //
                //printf(" Found START");edkEnd();

                //search the end
                edk::uint32 b = a+1u;edkEnd();
                while(str[b]!='\0'){
                    //
                    /*
                    printf("\nsearch %c %u"
                           ,str[b]
                           ,b
                           );edkEnd();
                    */
                    //test if found the end
                    if(str[b]==end){
                        //
                        /*
                        printf(" Fount END b-a+1u == %u"
                               ,b-(a+1u)+1u
                               );edkEnd();
                        */
                        edk::uint32 size = b - a;edkEnd();
                        if(use){
                            str = &str[a];edkEnd();
                            size = b - a +2u;edkEnd();
                        }
                        else{
                            str = &str[a+1u];edkEnd();
                        }
                        if(size){
                            size--;edkEnd();
                            if(size){
                                //Create the stirng
                                edk::char8* ret = new edk::char8[size+1u];edkEnd();
                                //set the end of the string
                                if(ret){
                                    //
                                    ret[size]='\0';edkEnd();
                                    //Then can copy the string
                                    for(edk::uint32 i=0u;i<size;i++){
                                        //copy the string
                                        if(*str){
                                            ret[i]=*str;edkEnd();
                                        }
                                        else{
                                            ret[i]='\0';edkEnd();
                                            break;edkEnd();
                                        }
                                        str++;edkEnd();
                                    }
                                    //return the ret
                                    return ret;
                                }
                                else{
                                    //
                                    ret=NULL;edkEnd();
                                }
                            }
                        }
                        //break
                        break;edkEnd();
                    }
                    //increment the b count
                    b++;edkEnd();
                }

                //then break;edkEnd();
                break;edkEnd();
            }

            //increment a count
            a++;edkEnd();
        }
    }
    return NULL;edkEnd();
}

edk::char8* edk::String::strCut(const edk::char8 *str, edk::char8 start, edk::char8 end, bool use){
    return edk::String::strCut((edk::char8 *)str, start, end, use);edkEnd();
}

bool edk::String::strInvert(edk::char8 *str){
    //first count the string
    edk::uint32 size=edk::String::strSize(str);edkEnd();
    //test if the string have characters
    if(size){
        size--;edkEnd();
        //copyTheString

        if(str){
            //invert the string
            edk::char8 temp=0u;
            for(edk::uint32 i=0u;i<=(size/2u);i++){
                //invert the character
                temp = str[i];edkEnd();
                str[i]=str[size-i];edkEnd();
                str[size-i]=temp;edkEnd();
            }
            return true;
        }
    }
    return false;
}

bool edk::String::strInvert(const edk::char8 *str){
    return edk::String::strInvert((edk::char8*)str);edkEnd();
}

edk::uint64 edk::String::stringHaveChar(edk::char8 *str,edk::char8 value){
    if(str){
        edk::uint64 count=0u;
        while(*str){
            if(*str==value){
                count++;edkEnd();
                return count;edkEnd();
            }
            count++;edkEnd();
            str++;edkEnd();
        }
    }
    return 0u;edkEnd();
}

edk::uint64 edk::String::stringHaveChar(const edk::char8 *str,edk::char8 value){
    return edk::String::stringHaveChar((edk::char8 *)str,value);edkEnd();
}

edk::uint64 edk::String::stringHaveChar(edk::char8 *str,edk::uint64 size,edk::char8 value){
    if(str){
        edk::uint32 count=0u;
        for(edk::uint64 i=0u;i<size;i++){
            if(str[i]==value){
                count++;edkEnd();
                return count;edkEnd();
            }
            count++;edkEnd();
        }
    }
    return 0u;edkEnd();
}
edk::uint64 edk::String::stringHaveChar(const edk::char8 *str,edk::uint64 size,edk::char8 value){
    return edk::String::stringHaveChar((edk::char8 *)str,size,value);edkEnd();
}

bool edk::String::consoleKeyPressed(){
    if(edkKbhit()){
        //
        return true;
    }
    return false;
}

edk::char8 edk::String::consoleReadKey(){
    return edkGetch();edkEnd();
}

edk::char8* edk::String::consoleReadString(){
    return readFromTheConsole(0u);edkEnd();
}

edk::char8* edk::String::consoleReadStringNoPrint(){
    return readFromTheConsoleNoPrint(0u);edkEnd();
}

edk::char8* edk::String::consoleReadPassword(){
    return readPasswordFromTheConsole(0u);edkEnd();
}

void edk::String::consoleClear(){
    //cleat console using a operatin system command
#if defined(WIN32) || defined(WIN64)//Windows
    system("cls");edkEnd();
#elif defined(__linux__) || defined(__APPLE__) //Linux //MacOS
    printf("\033c");edkEnd();fflush(stdout);edkEnd();
#endif
}

//return the console size
edk::size2ui32 edk::String::consoleGetSize(){
    edk::size2ui32 ret(0u,0u);edkEnd();
#if _WIN32 || _WIN64
#else
    struct winsize w;edkEnd();
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);edkEnd();
    ret.width = w.ws_row;edkEnd();
    ret.height = w.ws_col;edkEnd();
#endif
    return ret;
}

edk::char8* edk::String::strCopy(edk::char8 *str){
    edk::char8* strRet=NULL;edkEnd();

    //count the string
    edk::uint32 size = edk::String::strSize(str);edkEnd();
    if(size>0u){
        //alloc the string
        strRet = new edk::char8[size+1u];edkEnd();
        //test if alloc de string
        if(strRet){
            strRet[size]='\0';edkEnd();
            //copy the string
            memcpy(strRet,str,size);edkEnd();
        }
        else{
            //
            strRet=0u;
        }
    }
    return strRet;edkEnd();
}

edk::char8* edk::String::strCopy(const edk::char8 *str){
    return edk::String::strCopy((edk::char8*)str);edkEnd();
}

edk::char8* edk::String::strCopyLine(edk::char8 *str){
    edk::char8* strRet=NULL;edkEnd();

    //count the string
    edk::uint32 size = edk::String::strLineSize(str);edkEnd();
    if(size>0u){
        //alloc the string
        strRet = new edk::char8[size+1u];edkEnd();
        //test if alloc de string
        if(strRet){
            strRet[size]='\0';edkEnd();
            //copy the string
            memcpy(strRet,str,size);edkEnd();
        }
        else{
            //
            strRet=0u;
        }
    }
    return strRet;edkEnd();
}

edk::char8* edk::String::strCopyLine(const edk::char8 *str){
    return edk::String::strCopyLine((edk::char8*)str);edkEnd();
}

edk::char8* edk::String::strCopyWord(edk::char8 *str){
    edk::char8* strRet=NULL;edkEnd();

    //count the string
    edk::uint32 size = edk::String::strWordSize(str);edkEnd();
    if(size>0u){
        //alloc the string
        strRet = new edk::char8[size+1u];edkEnd();
        //test if alloc de string
        if(strRet){
            strRet[size]='\0';edkEnd();
            //copy the string
            memcpy(strRet,str,size);edkEnd();
        }
        else{
            //
            strRet=0u;
        }
    }
    return strRet;edkEnd();
}

edk::char8* edk::String::strCopyWord(const edk::char8 *str){
    return edk::String::strCopyWord((edk::char8*)str);edkEnd();
}

//remove a filter from string
edk::char8* edk::String::strCopyWithFilter(edk::char8 *str,edk::char8 *filter){
    edk::char8* strRet=NULL;edkEnd();

    if(filter){
        //count the string
        edk::uint32 sizeFilter = edk::String::strSize(filter);edkEnd();
        if(sizeFilter){
            if(str){
                edk::uint32 sizeWith = edk::String::strSizeWithFilter(str,filter);edkEnd();
                edk::uint32 size = edk::String::strSize(str);edkEnd();
                if(sizeWith>0u){
                    //alloc the string
                    strRet = new edk::char8[sizeWith+1u];edkEnd();
                    //test if alloc de string
                    if(strRet){
                        strRet[sizeWith]='\0';edkEnd();
                        //copy the string
                        edk::uint32 j=0u;
                        for(edk::uint32 i=0u;i<size;i++){
                            if(!edk::String::stringHaveChar(filter,sizeFilter,str[i])){
                                //the copy the character not with the filter
                                strRet[j] = str[i];edkEnd();
                                j++;edkEnd();
                                if(j>=sizeWith){
                                    break;edkEnd();
                                }
                            }
                        }
                    }
                    else{
                        //
                        strRet=0u;
                    }
                }
            }
        }
        else{
            return edk::String::strCopy(str);edkEnd();
        }
    }
    else{
        return edk::String::strCopy(str);edkEnd();
    }
    return strRet;edkEnd();
}
edk::char8* edk::String::strCopyWithFilter(const edk::char8 *str,edk::char8 *filter){
    return strCopyWithFilter((edk::char8 *)str,filter);edkEnd();
}
edk::char8* edk::String::strCopyWithFilter(char8 *str,const edk::char8 *filter){
    return strCopyWithFilter(str,(edk::char8 *)filter);edkEnd();
}
edk::char8* edk::String::strCopyWithFilter(const edk::char8 *str,const edk::char8 *filter){
    return strCopyWithFilter((edk::char8 *)str,(edk::char8 *)filter);edkEnd();
}

edk::char8* edk::String::clipboardRead(){
    //variavel do clipboard
    edk::char8* str=NULL;edkEnd();

    //Codigo windows 32
#if defined(_WIN32) || defined(_WIN64)//Windows
    //abre o clipboard
    HANDLE clip;edkEnd();
    if(OpenClipboard(NULL)){
        //carrega o texto
        clip = GetClipboardData(CF_TEXT);edkEnd();

        if(clip){
            //Copia o clip
            str=strCopy((edk::char8*)clip);edkEnd();
            //NAO DELETAR O CLIP
        }

        //fecha o clipboard
        CloseClipboard();edkEnd();
    }

#elif defined(__linux__) || defined(__APPLE__)
    //codigo em linux
#endif
    //fim codigo windows 64

    return str;edkEnd();
}

bool edk::String::clipboardWrite(edk::char8 *str){
    bool ret=false;edkEnd();

    //copia a string se a mesma for estatica
    edk::char8* temp = strCopy(str);edkEnd();

    //primeiro limpa o clipboard
    edk::String::clipboardClean();edkEnd();

    //Codigo windows 32
#if defined(_WIN32) || defined(_WIN64)
    //abre o clipboard
    if(OpenClipboard(NULL)){
        //Escreve o texto
        if(temp){
            //pode escrever o texto
            if(SetClipboardData(CF_TEXT,(HANDLE)temp)){
                //
                ret=true;edkEnd();
            }
        }
        //fecha o clipboard
        CloseClipboard();edkEnd();
    }
    //fim codigo windows 64

#elif defined(__linux__)
    //codigo em linux


#endif


    //no final ele deleta a temp
    if(temp){
        //
        delete[] temp;edkEnd();
    }

    //retorna o resultado
    return ret;
}

bool edk::String::clipboardWrite(const edk::char8 *str){
    return edk::String::clipboardWrite((edk::char8*)str);edkEnd();
}

bool edk::String::clipboardClean(){
    //variavel de retorno
    bool ret=false;edkEnd();

    //Codigo windows 32
#if defined(_WIN32) || defined(_WIN64)
    //abre o clipboard
    if(OpenClipboard(NULL)){
        //Limpa o buffer
        if(EmptyClipboard()){
            //
            ret=true;edkEnd();
        }

        //fecha o clipboard
        CloseClipboard();edkEnd();
    }
    //fim codigo windows 64

#elif __linux__
    //codigo em linux

#endif

    //senao retorna false
    return ret;
}



//filter string accent's
edk::char8 edk::String::filterAccent(const edk::char8* str){
    return edk::String::filterAccent((edk::char8*) str);edkEnd();
}
edk::char8 edk::String::filterAccent(edk::char8* str){
    //
    if(str){
        if((edk::uint8)*str==195u){
            str++;edkEnd();
            switch((edk::uint8)*str){
            case 128u:
                //printf("\nCrase A");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 129u:
                //printf("\nAcento A");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 130u:
                //printf("\nChapeu A");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 131u:
                //printf("\nTio A");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 132u:
                //printf("\nTrema A");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 135u:
                //printf("\nCedilha Maiusculo");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 136u:
                //printf("\nCrase E");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 137u:
                //printf("\nAcento E");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 138u:
                //printf("\nChapeu E");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 139u:
                //printf("\nTrema E");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 140u:
                //printf("\nCrase I");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 141u:
                //printf("\nAcento I");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 142u:
                //printf("\nChapeu I");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 143u:
                //printf("\nTrema I");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 145u:
                //printf("\nTio N");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 146u:
                //printf("\nCrase O");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 147u:
                //printf("\nAcento O");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 148u:
                //printf("\nChapeu O");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 149u:
                //printf("\nTio O");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 150u:
                //printf("\nTrema O");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 153u:
                //printf("\nCrase U");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 154u:
                //printf("\nAcento U");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 155u:
                //printf("\nChapeu U");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 156u:
                //printf("\nTrema U");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 157u:
                //printf("\nAcento Y");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 160u:
                //printf("\nCrase a");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 161u:
                //printf("\nAcento a");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 162u:
                //printf("\nChapeu a");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 163u:
                //printf("\nTio a");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 164u:
                //printf("\nTrema a");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 167u:
                //printf("\nCedilha Minusculo");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 168u:
                //printf("\nCrase e");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 169u:
                //printf("\nAcento e");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 170u:
                //printf("\nChapeu e");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 171u:
                //printf("\nTrema e");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 172u:
                //printf("\nCrase i");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 173u:
                //printf("\nAcento i");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 174u:
                //printf("\nChapeu i");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 175u:
                //printf("\ntrema i");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 177u:
                //printf("\nTio n");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 178u:
                //printf("\nCrase o");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 179u:
                //printf("\nAcento o");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 180u:
                //printf("\nChapeu o");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 181u:
                //printf("\nTio o");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 182u:
                //printf("\nTrema o");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 185u:
                //printf("\nCrase u");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 186u:
                //printf("\nAcento u");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 187u:
                //printf("\nChapeu u");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 188u:
                //printf("\nTrema u");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 189u:
                //printf("\nAcento y");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            }
            str--;edkEnd();
        }
        else if((edk::uint8)*str==225u){
            str++;edkEnd();
            if((edk::uint8)*str==186u){
                str++;edkEnd();
                if((edk::uint8)*str==189u){
                    //printf("\nTio e");edkEnd();
                    return 32u;edkEnd();
                }
                str--;edkEnd();
            }
            str--;edkEnd();
        }
        else if((edk::uint8)*str==226u){
            str++;edkEnd();
            if((edk::uint8)*str==128u){
                str++;edkEnd();
                if((edk::uint8)*str==148u){
                    //printf("\n");edkEnd();
                    return 45u;edkEnd();
                }
                else if((edk::uint8)*str==152u){
                    //printf("\nAbrir aspas simples");edkEnd();
                    return '\'';edkEnd();
                }
                else if((edk::uint8)*str==153u){
                    //printf("\nFechar aspas simples");edkEnd();
                    return '\'';edkEnd();
                }
                else if((edk::uint8)*str==156u){
                    //printf("\nAbrir aspas");edkEnd();
                    return '\"';edkEnd();
                }
                else if((edk::uint8)*str==157u){
                    //printf("\nFechar aspas");edkEnd();
                    return '\"';edkEnd();
                }
                str--;edkEnd();
            }
            str--;edkEnd();
        }
        else if((edk::uint8)*str==196u){
            str++;edkEnd();
            if((edk::uint8)*str==169u){
                //printf("\nTio i");edkEnd();
                return 32u;edkEnd();
            }
            str--;edkEnd();
        }
        else if((edk::uint8)*str==197u){
            str++;edkEnd();
            if((edk::uint8)*str==169u){
                //printf("\nTio u");edkEnd();
                return 32u;edkEnd();
            }
            str--;edkEnd();
        }
        return (edk::uchar8)*str;edkEnd();
    }
    return 0u;edkEnd();
}
edk::char8 edk::String::filterAccent(const edk::char8* str,edk::uint8* jump){
    return edk::String::filterAccent((edk::char8*) str,jump);edkEnd();
}
edk::char8 edk::String::filterAccent(edk::char8* str,edk::uint8* jump){

    if(str && jump){
        *jump=1u;edkEnd();
        if((edk::uint8)*str==195u){
            *jump+=1u;edkEnd();
            str++;edkEnd();
            switch((edk::uint8)*str){
            case 128u:
                //printf("\nCrase A");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 129u:
                //printf("\nAcento A");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 130u:
                //printf("\nChapeu A");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 131u:
                //printf("\nTio A");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 132u:
                //printf("\nTrema A");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 135u:
                //printf("\nCedilha Maiusculo");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 136u:
                //printf("\nCrase E");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 137u:
                //printf("\nAcento E");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 138u:
                //printf("\nChapeu E");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 139u:
                //printf("\nTrema E");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 140u:
                //printf("\nCrase I");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 141u:
                //printf("\nAcento I");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 142u:
                //printf("\nChapeu I");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 143u:
                //printf("\nTrema I");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 145u:
                //printf("\nTio N");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 146u:
                //printf("\nCrase O");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 147u:
                //printf("\nAcento O");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 148u:
                //printf("\nChapeu O");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 149u:
                //printf("\nTio O");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 150u:
                //printf("\nTrema O");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 153u:
                //printf("\nCrase U");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 154u:
                //printf("\nAcento U");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 155u:
                //printf("\nChapeu U");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 156u:
                //printf("\nTrema U");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 157u:
                //printf("\nAcento Y");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 160u:
                //printf("\nCrase a");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 161u:
                //printf("\nAcento a");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 162u:
                //printf("\nChapeu a");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 163u:
                //printf("\nTio a");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 164u:
                //printf("\nTrema a");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 167u:
                //printf("\nCedilha Minusculo");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 168u:
                //printf("\nCrase e");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 169u:
                //printf("\nAcento e");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 170u:
                //printf("\nChapeu e");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 171u:
                //printf("\nTrema e");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 172u:
                //printf("\nCrase i");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 173u:
                //printf("\nAcento i");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 174u:
                //printf("\nChapeu i");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 175u:
                //printf("\ntrema i");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 177u:
                //printf("\nTio n");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 178u:
                //printf("\nCrase o");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 179u:
                //printf("\nAcento o");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 180u:
                //printf("\nChapeu o");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 181u:
                //printf("\nTio o");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 182u:
                //printf("\nTrema o");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 185u:
                //printf("\nCrase u");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 186u:
                //printf("\nAcento u");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 187u:
                //printf("\nChapeu u");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 188u:
                //printf("\nTrema u");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            case 189u:
                //printf("\nAcento y");edkEnd();fflush(stdout);edkEnd();
                return ((edk::uchar8)*str) + 64u;edkEnd();
            default:
                *jump-=1u;edkEnd();
                str--;edkEnd();
            }
        }
        else if((edk::uint8)*str==225u){
            *jump+=1u;edkEnd();
            str++;edkEnd();
            if((edk::uint8)*str==186u){
                *jump+=1u;edkEnd();
                str++;edkEnd();
                if((edk::uint8)*str==189u){
                    //printf("\nTio e");edkEnd();
                    return 32u;edkEnd();
                }
                *jump-=1u;edkEnd();
                str--;edkEnd();
            }
            *jump-=1u;edkEnd();
            str--;edkEnd();
        }
        else if((edk::uint8)*str==226u){
            *jump+=1u;edkEnd();
            str++;edkEnd();
            if((edk::uint8)*str==128u){
                *jump+=1u;edkEnd();
                str++;edkEnd();
                if((edk::uint8)*str==148u){
                    //printf("\n");edkEnd();
                    return 45u;edkEnd();
                }
                else if((edk::uint8)*str==152u){
                    //printf("\nAbrir aspas simples");edkEnd();
                    return '\'';edkEnd();
                }
                else if((edk::uint8)*str==153u){
                    //printf("\nFechar aspas simples");edkEnd();
                    return '\'';edkEnd();
                }
                else if((edk::uint8)*str==156u){
                    //printf("\nAbrir aspas");edkEnd();
                    return '\"';edkEnd();
                }
                else if((edk::uint8)*str==157u){
                    //printf("\nFechar aspas");edkEnd();
                    return '\"';edkEnd();
                }
                *jump-=1u;edkEnd();
                str--;edkEnd();
            }
            *jump-=1u;edkEnd();
            str--;edkEnd();
        }
        else if((edk::uint8)*str==196u){
            *jump+=1u;edkEnd();
            str++;edkEnd();
            if((edk::uint8)*str==169u){
                //printf("\nTio i");edkEnd();
                return 32u;edkEnd();
            }
            *jump-=1u;edkEnd();
            str--;edkEnd();
        }
        else if((edk::uint8)*str==197u){
            *jump+=1u;edkEnd();
            str++;edkEnd();
            if((edk::uint8)*str==169u){
                //printf("\nTio u");edkEnd();
                return 32u;edkEnd();
            }
            *jump-=1u;edkEnd();
            str--;edkEnd();
        }
        return (edk::uchar8)*str;edkEnd();
    }
    return 0u;edkEnd();
}
edk::uint32 edk::String::strSizeFilterAccent(const edk::char8* str){
    return edk::String::strSizeFilterAccent((edk::char8*) str);edkEnd();
}
edk::uint32 edk::String::strSizeFilterAccent(edk::char8* str){
    edk::uint32 ret = 0u;edkEnd();
    edk::uint8 jump=0u;
    if(str){
        while(*str){
            jump=0u;
            //filter the character
            edk::String::filterAccent(str,&jump);edkEnd();
            //increment the ret
            ret++;edkEnd();
            //jump the string
            str+=jump;edkEnd();
        }
    }
    return ret;
}
//copy with filter
edk::char8* edk::String::strCopyFilterAccent(const edk::char8* str){
    return edk::String::strCopyFilterAccent((edk::char8*) str);edkEnd();
}
edk::char8* edk::String::strCopyFilterAccent(edk::char8* str){
    if(str){
        //get the size of the string
        edk::uint32 size = edk::String::strSizeFilterAccent(str);edkEnd();
        if(size){
            //create the new string
            edk::char8* ret = new edk::char8[size+1u];edkEnd();
            if(ret){
                ret[size] = '\0';edkEnd();
                edk::uint8 jump=0u;
                //copy the character with filter
                for(edk::uint32 i=0u;i<size;i++){
                    jump=0u;
                    ret[i] = edk::String::filterAccent(str,&jump);edkEnd();
                    //jump string
                    str+=jump;edkEnd();
                }
                return ret;
            }
        }
    }
    return NULL;edkEnd();
}

//return the file name from a string
edk::char8* edk::String::strFileName(edk::char8* str){
    edk::char8* ret = NULL;edkEnd();
    if(str){
        //create a pointer to read the string
        edk::char8* temp = str;edkEnd();
        //go to the end of the string
        while(*temp){
            temp++;edkEnd();
        }
        edk::uint32 size = 0u;edkEnd();
        //go back counting the size of the string
        while(*temp!='/' && *temp!='\\' && temp!=str){
            temp--;edkEnd();
            size++;edkEnd();
        }
        if(*temp=='/' || *temp=='\\'){
            temp++;edkEnd();
            if(size)
                size--;edkEnd();
        }
        if(size){
            //create a new string with the size
            ret = new edk::char8[size+1u];edkEnd();
            if(ret){
                //set the string end
                ret[size]='\0';edkEnd();
                //copy the name of the file to the return
                for(edk::uint32 i = 0u;i<size;i++){
                    ret[i] = temp[i];edkEnd();
                }
            }
        }
    }
    return ret;
}
edk::char8* edk::String::strFileName(const edk::char8* str){
    return edk::String::strFileName((edk::char8*) str);edkEnd();
}
bool edk::String::strFileName(edk::char8* str,edk::char8* dest){
    bool ret=false;edkEnd();
    if(str && dest){
        //create a pointer to read the string
        edk::char8* temp = str;edkEnd();
        //go to the end of the string
        while(*temp){
            temp++;edkEnd();
        }
        if(temp!=str){
            ret=true;edkEnd();
        }
        //go back
        while(*temp=='/' && *temp=='\\' && temp!=str){
            temp--;edkEnd();
        }
        if(*temp!='/' || *temp!='\\'){
            temp++;edkEnd();
        }
        //copy the string from the temp
        while(*temp){
            *dest = *temp;edkEnd();
            temp++;edkEnd();
            dest++;edkEnd();
        }
        //at the end set the dest end
        *dest=0u;
        return ret;
    }
    return ret;
}
bool edk::String::strFileName(const edk::char8* str,edk::char8* dest){
    return edk::String::strFileName((edk::char8*) str,dest);edkEnd();
}
//return the folder name from a string
edk::char8* edk::String::strFolderName(edk::char8* str){
    edk::char8* ret = NULL;edkEnd();
    if(str){
        edk::uint32 i=0u;
        edk::uint32 lastFolder=0u;
        bool haveLast=false;edkEnd();
        //create a pointer to read the string
        edk::char8* temp = str;edkEnd();
        //go to the last '/' or '\\'
        while(*temp){
            if(*temp=='/' || *temp=='\\'){
                //find a folder
                lastFolder = i;edkEnd();
                haveLast=true;edkEnd();
            }
            temp++;edkEnd();
            i++;edkEnd();
        }

        //test if have the last folder
        if(lastFolder){
            lastFolder++;edkEnd();
            //create a new string with the size of the last folder
            ret = new edk::char8[lastFolder+1u];edkEnd();
            if(ret){
                ret[lastFolder]='\0';edkEnd();
                for(edk::uint32 j=0u;j<lastFolder;j++){
                    ret[j]=str[j];edkEnd();
                }
            }
        }
        else{
            if(haveLast){
                //create a new string for use "./"
                ret = new edk::char8[2u];edkEnd();
                if(ret){
                    ret[0u]='/';edkEnd();
                    ret[1u]='\0';edkEnd();
                }
            }
            else{
                //create a new string for use "./"
                ret = new edk::char8[3u];edkEnd();
                if(ret){
                    ret[0u]='.';edkEnd();
                    ret[1u]='/';edkEnd();
                    ret[2u]='\0';edkEnd();
                }
            }
        }
    }
    return ret;
}
edk::char8* edk::String::strFolderName(const edk::char8* str){
    return edk::String::strFolderName((edk::char8*) str);edkEnd();
}
bool edk::String::strFolderName(edk::char8* str,edk::char8* dest){
    if(str && dest){
        edk::uint32 i=0u;
        edk::uint32 lastFolder=0u;
        bool haveLast=false;edkEnd();
        //create a pointer to read the string
        edk::char8* temp = str;edkEnd();
        //go to the last '/' or '\\'
        while(*temp){
            if(*temp=='/' || *temp=='\\'){
                //find a folder
                lastFolder = i;edkEnd();
                haveLast=true;edkEnd();
            }
            temp++;edkEnd();
            i++;edkEnd();
        }

        //test if have the last folder
        if(lastFolder){
            lastFolder++;edkEnd();
            //create a new string with the size of the last folder
            dest[lastFolder]='\0';edkEnd();
            for(edk::uint32 j=0u;j<lastFolder;j++){
                dest[j]=str[j];edkEnd();
            }
            return true;
        }
        else{
            if(haveLast){
                //create a new string for use "./"
                dest[0u]='/';edkEnd();
                dest[1u]='\0';edkEnd();
                return true;
            }
            else{
                //create a new string for use "./"
                dest[0u]='.';edkEnd();
                dest[1u]='/';edkEnd();
                dest[2u]='\0';edkEnd();
                return true;
            }
        }
    }
    return false;
}
bool edk::String::strFolderName(const edk::char8* str,edk::char8* dest){
    return edk::String::strFolderName((edk::char8*) str,(edk::char8*) dest);edkEnd();
}

//BASE64
const edk::char8 b64chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int b64invs[] = { 62, -1, -1, -1, 63, 52, 53, 54, 55, 56, 57, 58,
                  59, 60, 61, -1, -1, -1, -1, -1, -1, -1, 0, 1, 2, 3, 4, 5,
                  6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                  21, 22, 23, 24, 25, -1, -1, -1, -1, -1, -1, 26, 27, 28,
                  29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42,
                  43, 44, 45, 46, 47, 48, 49, 50, 51 };
//encode
//return the encode result size
edk::uint64 edk::String::base64EncodeSize(edk::uint64 size){
    edk::uint64 ret;edkEnd();

    ret = size;edkEnd();
    if (size % 3 != 0){
        ret += 3 - (size % 3);edkEnd();
    }
    ret /= 3;edkEnd();
    ret *= 4;edkEnd();

    return ret;
}
//convert the vector to base64 receiving the pre alloc string
bool edk::String::base64Encode(edk::uint8* vec,edk::uint64 size,edk::char8* dest){
    if(vec && size){
        edk::uint64  elen;edkEnd();
        edk::uint64  i;edkEnd();
        edk::uint64  j;edkEnd();
        edk::uint64  v;edkEnd();

        elen = edk::String::base64EncodeSize(size);edkEnd();
        dest[elen] = '\0';edkEnd();

        for (i=0, j=0; i<size; i+=3, j+=4) {
            v = vec[i];edkEnd();
            v = i+1 < size ? v << 8 | vec[i+1] : v << 8;edkEnd();
            v = i+2 < size ? v << 8 | vec[i+2] : v << 8;edkEnd();

            dest[j]   = b64chars[(v >> 18) & 0x3F];edkEnd();
            dest[j+1] = b64chars[(v >> 12) & 0x3F];edkEnd();
            if (i+1 < size) {
                dest[j+2] = b64chars[(v >> 6) & 0x3F];edkEnd();
            } else {
                dest[j+2] = '=';edkEnd();
            }
            if (i+2 < size) {
                dest[j+3] = b64chars[v & 0x3F];edkEnd();
            } else {
                dest[j+3] = '=';edkEnd();
            }
        }

        return true;
    }
    return false;
}
bool edk::String::base64Encode(edk::char8* str,edk::uint64 size,edk::char8* dest){
    return edk::String::base64Encode((edk::uint8*) str,size,dest);edkEnd();
}
bool edk::String::base64Encode(const edk::char8* str,edk::uint64 size,edk::char8* dest){
    return edk::String::base64Encode((edk::uint8*) str,size,dest);edkEnd();
}
//convert the vector to base64 new string
edk::char8* edk::String::base64Encode(edk::uint8* vec,edk::uint64 size){
    edk::char8   *out;edkEnd();
    edk::uint64  elen;edkEnd();

    if (vec == NULL || size == 0)
        return NULL;edkEnd();

    elen = edk::String::base64EncodeSize(size);edkEnd();
    out  = (edk::char8*)malloc(elen+1);edkEnd();
    out[elen] = '\0';edkEnd();

    edk::String::base64Encode(vec,size,out);edkEnd();

    return out;edkEnd();
}
edk::char8* edk::String::base64Encode(edk::char8* str,edk::uint64 size){
    return edk::String::base64Encode((edk::uint8*) str,size);edkEnd();
}
edk::char8* edk::String::base64Encode(const edk::char8* str,edk::uint64 size){
    return edk::String::base64Encode((edk::uint8*) str,size);edkEnd();
}
//decode
//convert a base64 to a pre alloc vector
edk::uint64 edk::String::base64DecodeSize(edk::char8* str){
    edk::uint64 len;edkEnd();
    edk::uint64 ret;edkEnd();
    edk::uint64 i;edkEnd();

    if (str == NULL)
        return 0;

    len = edk::String::strSize(str);edkEnd();
    ret = len / 4 * 3;edkEnd();

    for (i=len; i-->0; ) {
        if (str[i] == '=') {
            ret--;edkEnd();
        } else {
            break;edkEnd();
        }
    }

    return ret;
}
bool edk::String::base64Decode(edk::char8* str,edk::uint8* dest){
    edk::uint64 len;edkEnd();
    edk::uint64 i;edkEnd();
    edk::uint64 j;edkEnd();
    int    v;edkEnd();

    if (str == NULL || dest == NULL)
        return false;

    len = edk::String::strSize(str);edkEnd();
    /*
    if (size < edk::String::base64DecodeSize(str) || len % 4 != 0)
        return false;
    */

    for (i=0; i<len; i++){
        //test if it's a valid character
        if((str[i] < '0' && str[i] > '9') &&
                (str[i] < 'A' && str[i] > 'Z') &&
                (str[i] < 'a' && str[i] > 'z') &&
                (str[i] != '+' || str[i] != '/' || str[i] != '=')
                ){
            return false;
        }
    }

    for (i=0, j=0; i<len; i+=4, j+=3) {
        v = b64invs[str[i]-43];edkEnd();
        v = (v << 6) | b64invs[str[i+1]-43];edkEnd();
        v = str[i+2]=='=' ? v << 6 : (v << 6) | b64invs[str[i+2]-43];edkEnd();
        v = str[i+3]=='=' ? v << 6 : (v << 6) | b64invs[str[i+3]-43];edkEnd();

        dest[j] = (v >> 16) & 0xFF;edkEnd();
        if (str[i+2] != '=')
            dest[j+1] = (v >> 8) & 0xFF;edkEnd();
        if (str[i+3] != '=')
            dest[j+2] = v & 0xFF;edkEnd();
    }
    return true;
}
bool edk::String::base64Decode(const edk::char8* str,edk::uint8* dest){
    return edk::String::base64Decode((edk::char8*) str,dest);edkEnd();
}

//convert the uri to utf8 to be used by http servers
edk::uint64 edk::String::uriUnescapeSize(edk::char8* str){
    edk::uint64  ret = 0u;edkEnd();
    //test the string
    if(str){
        // Skip inital non encoded character
        while (*str && !edkIsSpace((edk::int32)(*str)) && (*str != '%')){
            str++;edkEnd();
            ret++;edkEnd();
        }

        while (*str && !edkIsSpace((edk::int32)(*str))) {
            if (*str == '+'){
                ret++;edkEnd();
            }
            else if ((*str == '%') && str[1] && str[2]) {
                str++;edkEnd();
                str++;edkEnd();
                ret++;edkEnd();
            } else{
                ret++;edkEnd();
            }
            str++;edkEnd();
        }
    }
    return ret;
}
edk::uint64 edk::String::uriUnescapeSize(const edk::char8* str){
    return edk::String::uriUnescapeSize((edk::char8*) str);edkEnd();
}
bool edk::String::uriUnescape(edk::char8* str,edk::char8* dest){
    if(str && dest){
        edk::char8 chr = 0;

        // Skip inital non encoded character
        while (*str && !edkIsSpace((edk::int32)(*str)) && (*str != '%')){
            *dest = *str;edkEnd();
            str++;edkEnd();
            dest++;edkEnd();
        }

        while (*str && !edkIsSpace((edk::int32)(*str))) {
            if (*str == '+'){
                chr = ' ';edkEnd();
            }
            else if ((*str == '%') && str[1] && str[2]) {
                str++;edkEnd();
                chr = ((*str & 0x0F) + 9 * (*str > '9')) * 16;edkEnd();
                str++;edkEnd();
                chr += ((*str & 0x0F) + 9 * (*str > '9'));edkEnd();
            } else{
                chr = *str;edkEnd();
            }
            *dest = chr;edkEnd();
            dest++;edkEnd();
            str++;edkEnd();
        }
        *dest = '\0';edkEnd();
        return true;
    }
    return false;
}
bool edk::String::uriUnescape(const edk::char8* str,edk::char8* dest){
    return uriUnescape((edk::char8*) str,dest);edkEnd();
}
bool edk::String::uriUnescape(edk::char8* str,const edk::char8* dest){
    return uriUnescape(str,(edk::char8*) dest);edkEnd();
}
bool edk::String::uriUnescape(const edk::char8* str,const edk::char8* dest){
    return uriUnescape((edk::char8*) str,(edk::char8*) dest);edkEnd();
}
edk::char8* edk::String::uriUnescape(edk::char8* str){
    //create the new string to ret
    edk::uint64 size = edk::String::uriUnescapeSize(str);edkEnd();
    if(size){
        edk::char8* ret = new edk::char8[size+1u];edkEnd();
        if(ret){
            ret[size]='\0';edkEnd();
            if(edk::String::uriUnescape(str,ret)){
                return ret;
            }
            delete[] ret;edkEnd();
        }
    }
    return NULL;edkEnd();
}
edk::char8* edk::String::uriUnescape(const edk::char8* str){
    return edk::String::uriUnescape((edk::char8*) str);edkEnd();
}
