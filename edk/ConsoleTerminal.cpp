#include "ConsoleTerminal.h"

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
#pragma message "            Inside ConsoleTerminal.cpp"
#endif

#if defined (__linux__) || defined(__APPLE__)
//https://stackoverflow.com/questions/1513734/problem-with-kbhitand-getch-for-linux?answertab=trending#tab-top
struct termios oldTermios;
int edkTTYraw(edk::int32 fd){
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
    struct termios newtermios;
    if(tcgetattr(fd, &oldTermios) < 0){
        return(-1);
    }
    newtermios = oldTermios;

    newtermios.c_lflag &= ~(ECHO
                            | ICANON
                            | IEXTEN
                            //| ISIG //remove this SIG because it remove the SIG
                            );
    /* OK, why IEXTEN? If IEXTEN is on, the DISCARD character
       is recognized and is not passed to the process. This
       character causes output to be suspended until another
       DISCARD is received. The DSUSP character for job control,
       the LNEXT character that removes any special meaning of
       the following character, the REPRINT character, and some
       others are also in this category.
    */

    newtermios.c_iflag &= ~(BRKINT
                            | ICRNL
                            | INPCK
                            | ISTRIP
                            | IXON
                            );
    /* If an input character arrives with the wrong parity, then INPCK
       is checked. If this flag is set, then IGNPAR is checked
       to see if input bytes with parity errors should be ignored.
       If it shouldn't be ignored, then PARMRK determines what
       character sequence the process will actually see.

       When we turn off IXON, the start and stop characters can be read.
    */

    newtermios.c_cflag &= ~(CSIZE
                            | PARENB
                            );
    /* CSIZE is a mask that determines the number of bits per byte.
       PARENB enables parity checking on input and parity generation
       on output.
    */

    newtermios.c_cflag |= CS8;
    /* Set 8 bits per character. */

    //newtermios.c_oflag &= ~(OPOST);
    /* This includes things like expanding tabs to spaces. */

    newtermios.c_cc[VMIN] = 1;
    newtermios.c_cc[VTIME] = 0;

    /* You tell me why TCSAFLUSH. */
    if(tcsetattr(fd, TCSAFLUSH, &newtermios) < 0){
        return(-1);
    }
    return(0);
}

int edkTTYreset(edk::int32 fd)
{
    if(tcsetattr(fd, TCSAFLUSH, &oldTermios) < 0){
        return(-1);
    }

    return(0);
}

int edkGetch(void)
{
    struct termios old, _new;
    int ch;
    tcgetattr(0, &old);
    _new = old;
    _new.c_lflag &= ~ICANON;
    _new.c_lflag &= ~ECHO;
    tcsetattr(0, TCSANOW, &_new);
    ch = getchar();
    tcsetattr(0, TCSANOW, &old);
    return ch;
}

int edkKbhit(void){
    struct termios oldt, _newt;
    edk::int32 ch;
    edk::int32 oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    _newt = oldt;
    _newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &_newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF)
    {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}
#endif
#if defined(WIN32) || defined(WIN64)
#if defined(_MSC_VER)
int edkGetch(void){return _getch();}
int edkKbhit(void){return _kbhit();}
#else
int edkGetch(void){return getch();}
int edkKbhit(void){return kbhit();}
#endif
#endif

edk::char8* readFromTheConsole(edk::uint32 i){
    //Eu sei que os professores dizem NUNCA use isso mas se eu nao usasse eu
    //nao sei o que ei iria faser
inicio:
    //primeiro ele le a tecla do teclado e ve se e equal a enter 13
    edk::uchar8 c=edkGetch();
    edk::uchar8 c2=0u,c3=0u,c4=0u;
    edk::uint8 size=1u;

    //2: c2 -> df
    //3: e0 -> ea : ed - ef
    //4: f0 - f3 - f4

    //test if need getch another character
    if(c>=0xc2 && c<=0xdf){
        //read one more
        c2=edkGetch();
        size=2u;
    }
    else if((c>= 0xe0 && c<=0xea)
            || c==0xed
            || c==0xef
            ){
        //read two more
        c2=edkGetch();
        c3=edkGetch();
        size=3u;
    }
    else if(c==0xf0 || c==0xf3 || c==0xf4){
        //read tree more
        c2=edkGetch();
        c3=edkGetch();
        c4=edkGetch();
        size=4u;
    }

    //printf(" %u recebido",(edk::uint8)c);
    //Aqui ele pergunta se o edk::char8 e equal a o backspace
    if(c==8||c==127){
        if(i==0){
            //Se o i for equal a 0 ele nao pode retornar entao ele volta pro inicio do goto
            goto inicio;
        }
        //Se for equal entao ele apaga o caracter e le ele denovo;
        printf("%c %c",8,8);
        return NULL;
    }
    //depois ele gera o ponteiro para a string na memoria
    edk::char8* string;
    if(c==13||c==10){
        //Acabou a recursividade e portanto ele cria a string e retorna ela
        string = (edk::char8*)malloc(sizeof(edk::char8) * (i+1)); //Ele cria ela uma vez maior para adicionar o
        //caracter de parada
        string[i]='\0';
        //string[i]=c;
        return string;
    }
    else{
        //Senao ele countinua a recursividade recebendo a string como parametro
        switch(size){
        case 4u:
            printf("%c",c);
            printf("%c",c2);
            printf("%c",c3);
            printf("%c",c4);
            break;
        case 3u:
            printf("%c",c);
            printf("%c",c2);
            printf("%c",c3);
            break;
        case 2u:
            printf("%c",c);
            printf("%c",c2);
            break;
        case 1u:
            printf("%c",c);
            break;
        }

        string=readFromTheConsole(i+size);
        //Aqui ele pegunta se a string existe
        if(string){
            //se sim ele atribui o caracter desta etapa para a string


            switch(size){
            case 4u:
                string[i+3u]=c4;
                string[i+2u]=c3;
                string[i+1u]=c2;
                string[i]=c;
                break;
            case 3u:
                string[i+2u]=c3;
                string[i+1u]=c2;
                string[i]=c;
                break;
            case 2u:
                string[i+1u]=c2;
                string[i]=c;
                break;
            case 1u:
                string[i]=c;
                break;
            }

            //no final ele retorna a string
            return string;
        }
        else{
            //Senao entao ele countinua lendo
            goto inicio;
        }
    }
}

edk::char8* readFromTheConsoleNoPrint(edk::uint32 i){
    //Eu sei que os professores dizem NUNCA use isso mas se eu nao usasse eu
    //nao sei o que ei iria faser
inicio:
    //primeiro ele le a tecla do teclado e ve se e equal a enter 13
    edk::uchar8 c=edkGetch();
    edk::uchar8 c2=0u,c3=0u,c4=0u;
    edk::uint8 size=1u;

    //2: c2 -> df
    //3: e0 -> ea : ed - ef
    //4: f0 - f3 - f4

    //test if need getch another character
    if(c>=0xc2 && c<=0xdf){
        //read one more
        c2=edkGetch();
        size=2u;
    }
    else if((c>= 0xe0 && c<=0xea)
            || c==0xed
            || c==0xef
            ){
        //read two more
        c2=edkGetch();
        c3=edkGetch();
        size=3u;
    }
    else if(c==0xf0 || c==0xf3 || c==0xf4){
        //read tree more
        c2=edkGetch();
        c3=edkGetch();
        c4=edkGetch();
        size=4u;
    }

    //printf(" %u recebido",(edk::uint8)c);
    //Aqui ele pergunta se o edk::char8 e equal a o backspace
    if(c==8||c==127){
        if(i==0){
            //Se o i for equal a 0 ele nao pode retornar entao ele volta pro inicio do goto
            goto inicio;
        }
        //Se for equal entao ele apaga o caracter e le ele denovo;
        printf("%c %c",8,8);
        return NULL;
    }
    //depois ele gera o ponteiro para a string na memoria
    edk::char8* string;
    if(c==13||c==10){
        //Acabou a recursividade e portanto ele cria a string e retorna ela
        string = (edk::char8*)malloc(sizeof(edk::char8) * (i+1)); //Ele cria ela uma vez maior para adicionar o
        //caracter de parada
        string[i]='\0';
        //string[i]=c;
        return string;
    }
    else{
        string=readFromTheConsoleNoPrint(i+size);
        //Aqui ele pegunta se a string existe
        if(string){
            //se sim ele atribui o caracter desta etapa para a string


            switch(size){
            case 4u:
                string[i+3u]=c4;
                string[i+2u]=c3;
                string[i+1u]=c2;
                string[i]=c;
                break;
            case 3u:
                string[i+2u]=c3;
                string[i+1u]=c2;
                string[i]=c;
                break;
            case 2u:
                string[i+1u]=c2;
                string[i]=c;
                break;
            case 1u:
                string[i]=c;
                break;
            }

            //no final ele retorna a string
            return string;
        }
        else{
            //Senao entao ele countinua lendo
            goto inicio;
        }
    }
}

edk::char8* readPasswordFromTheConsole(edk::uint32 i){
    //Eu sei que os professores dizem NUNCA use isso mas se eu nao usasse eu
    //nao sei o que ei iria faser
inicio:
    //primeiro ele le a tecla do teclado e ve se e equal a enter 13
    edk::uchar8 c=edkGetch();
    edk::uchar8 c2=0u,c3=0u,c4=0u;
    edk::uint8 size=1u;

    //2: c2 -> df
    //3: e0 -> ea : ed - ef
    //4: f0 - f3 - f4

    //test if need getch another character
    if(c>=0xc2 && c<=0xdf){
        //read one more
        c2=edkGetch();
        size=2u;
    }
    else if((c>= 0xe0 && c<=0xea)
            || c==0xed
            || c==0xef
            ){
        //read two more
        c2=edkGetch();
        c3=edkGetch();
        size=3u;
    }
    else if(c==0xf0 || c==0xf3 || c==0xf4){
        //read tree more
        c2=edkGetch();
        c3=edkGetch();
        c4=edkGetch();
        size=4u;
    }

    //printf(" %u recebido",(edk::uint8)c);
    //Aqui ele pergunta se o edk::char8 e equal a o backspace
    if(c==8||c==127){
        if(i==0){
            //Se o i for equal a 0 ele nao pode retornar entao ele volta pro inicio do goto
            goto inicio;
        }
        //Se for equal entao ele apaga o caracter e le ele denovo;
        printf("%c %c",8,8);
        return NULL;
    }
    //depois ele gera o ponteiro para a string na memoria
    edk::char8* string;
    if(c==13||c==10){
        //Acabou a recursividade e portanto ele cria a string e retorna ela
        string = (edk::char8*)malloc(sizeof(edk::char8) * (i+1)); //Ele cria ela uma vez maior para adicionar o
        //caracter de parada
        string[i]='\0';
        //string[i]=c;
        return string;
    }
    else{
        //Senao ele countinua a recursividade recebendo a string como parametro
        printf("*");

        string=readPasswordFromTheConsole(i+size);
        //Aqui ele pegunta se a string existe
        if(string){
            //se sim ele atribui o caracter desta etapa para a string


            switch(size){
            case 4u:
                string[i+3u]=c4;
                string[i+2u]=c3;
                string[i+1u]=c2;
                string[i]=c;
                break;
            case 3u:
                string[i+2u]=c3;
                string[i+1u]=c2;
                string[i]=c;
                break;
            case 2u:
                string[i+1u]=c2;
                string[i]=c;
                break;
            case 1u:
                string[i]=c;
                break;
            }

            //no final ele retorna a string
            return string;
        }
        else{
            //Senao entao ele countinua lendo
            goto inicio;
        }
    }
}

edk::TTY::TTY(){
    this->haveInit=false;
    //init the terminal
    this->initTerminal();
}
edk::TTY::~TTY(){
    //reset the terminal if it was initiated
    this->resetTerminal();
}

bool edk::TTY::initTerminal(){
    if(!this->haveInit){
#if defined (__linux__) || defined(__APPLE__)
        //set the ttyRaw
        if(edkTTYraw(0) < 0){
            return false;
        }
#endif
        this->haveInit=true;
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
        this->haveInit=false;
    }
    return false;
}

//TTY to construct and destruct
edk::TTY edk::ConsoleTerminal::tty;

edk::ConsoleTerminal::ConsoleTerminal(){
    //
}
edk::ConsoleTerminal::~ConsoleTerminal(){
    //
}

void edk::ConsoleTerminal::push(){
    printf("\n\033[?47h");fflush(stdout);
}

void edk::ConsoleTerminal::pop(){
    printf("\033[?47l");fflush(stdout);
}

void edk::ConsoleTerminal::gotoXY(edk::uint32 x,edk::uint32 y){
    //cleat console using a operatin system command
#if defined(WIN32) || defined(WIN64)//Windows
    system("cls");
#elif defined(__linux__) || defined(__APPLE__) //Linux //MacOS
    printf("\033[%d;%dH",y,x);fflush(stdout);
#endif
}

edk::vec2ui32 edk::ConsoleTerminal::getPosition(){
    edk::vec2ui32 ret;
    edk::char8 buf[30]={0};
    edk::int32 i, pow;
    edk::char8 ch;
    struct termios term, restore;

    tcgetattr(0, &term);
    tcgetattr(0, &restore);
    term.c_lflag &= ~(ICANON|ECHO);
    tcsetattr(0, TCSANOW, &term);

    write(1, "\033[6n", 4);

    for(i = 0, ch = 0; ch != 'R'; i++ ){
        if( !read(0, &ch, 1) ){
            return ret;
        }
        buf[i] = ch;
    }

    if(i < 2){
        return ret;
    }

    for(i -= 2, pow = 1; buf[i] != ';'; i--, pow *= 10){
        ret.x = + ( buf[i] - '0' ) * pow;
    }

    for(i-- , pow = 1; buf[i] != '['; i--, pow *= 10){
        ret.y = ( buf[i] - '0' ) * pow;
    }
    tcsetattr(0, TCSANOW, &restore);

    return ret;
}

edk::size2ui32 edk::ConsoleTerminal::getWidth(){
    return edk::ConsoleTerminal::getSize().width;
}
edk::size2ui32 edk::ConsoleTerminal::getHeight(){
    return edk::ConsoleTerminal::getSize().height;
}

bool edk::ConsoleTerminal::keyPressed(){
    if(edkKbhit()){
        return true;
    }
    return false;
}

edk::char8  edk::ConsoleTerminal::readKey(){
    return edkGetch();
}

edk::char8* edk::ConsoleTerminal::readString(){
    return readFromTheConsole(0u);
}

edk::char8* edk::ConsoleTerminal::readStringNoPrint(){
    return readFromTheConsoleNoPrint(0u);
}

edk::char8* edk::ConsoleTerminal::readPassword(){
    return readPasswordFromTheConsole(0u);
}

void edk::ConsoleTerminal::clear(){
    //cleat console using a operatin system command
#if defined(WIN32) || defined(WIN64)//Windows
    system("cls");
#elif defined(__linux__) || defined(__APPLE__) //Linux //MacOS
    //printf("\033");fflush(stdout);
    printf("\033[H\033[J");fflush(stdout);
#endif
}

//return the console size
edk::size2ui32 edk::ConsoleTerminal::getSize(){
    edk::size2ui32 ret(0u,0u);
#if _WIN32 || _WIN64
#else
    struct winsize w;
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    ret.width = w.ws_row;
    ret.height = w.ws_col;
#endif
    return ret;
}
