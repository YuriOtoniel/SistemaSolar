#include <GL/freeglut.h>
#include "textura.h"
#include <cmath>
#include <stdlib.h>
#include <time.h>
/*
-------------------------------------------------------------------
              CARACTERISTICAS DESSE SISTEMA SOLAR
-------------------------------------------------------------------
    As velocidades de rotação e translação dos planetas estabelcem
a relação de proporção em relação ao real, bem como os tamanhos das
órbitas e dos planetas em si, salvo o caso de Mercurio, Venus e a Terra
que por serem pequenos foram aumentados em uma escala de 10x em relação
aos demais planetas e sol. Todos os valores utilizados para medida
de extensão foram utilizados em unidades astronômicas (UA).

As imagens de tecturas foram retiradas do site:
http://planetpixelemporium.com/planets.html sobre os direitos de
Copyright (c) por James Hastings-Trew.
-------------------------------------------------------------------
                        COMANDOS DE TECLADO
-------------------------------------------------------------------
    TECLA       |                   Comando                       |

    " - "       |   Diminui a velocidade de rotação e translação  |
    " + "       |   Aumenta a velocidade de rotação e translação  |
      UP        |   Aumenta o zoom                                |
     Down       |   Diminui o Zoom                                |
     LEFT       |   Rotaciona a camera para a esquerda            |
    RIGHT       |   Rotaciona a camera para a Direita             |
    " w "       |   Move a camera para Frente                     |
    " a "       |   Move a camera para a esqueda                  |
    " s "       |   Move a Camera para trás                       |
    " d "       |   Move a camera para Direita                    |
-------------------------------------------------------------------
OBS: Por manter a proporção, os planetas mais distantes demoram um pouco
para ser localizados, desta forma, todos foram alinhados no inicio
da execução para que seja mais facil encontrá-los.
-------------------------------------------------------------------
*/

float divisorRaioTranslacao = 1; //Aumente esse valor para diminuir a distancia de translação
                                 // dos planetas Jupiter, Saturno, Urano, Neturno.


//Paramentros de quantidade de poligonos das esferas
int slices = 50;
int stacks = 20;

//Parametros de execução
float angulo=0;
float fov  = 45.0f;
float near1 = 0.001f;
float far1 = 100.0f;

//Posição inicial da camera
float eyeX = 0.0f;
float eyeY = 0.0f;
float eyeZ = 0.50f;

//Angulos de rotação da camera
float anguloCamera = 0.0f;
float angZ = cos(anguloCamera*M_PI/180);
float angX =sin(anguloCamera*M_PI/180);

float velocidade = 1; //Ajusta a velocidade de rotação e translação, pode ser alterado pelas setas Esq. e Dir.

void desenhaSol()
{
    //Setando os valores da escala e tamanho
    float escalaRot = 0.037037037f ;
    float anguloEixo = 7.25f;
    float raio= 0.004645788f;


    //float mat_emission[] = {1.0f, 0.0f, 0.0f, 0.0};
    //glLightfv(GL_LIGHT1, GL_EMISSION, mat_emission);

    glLoadIdentity();

    gluLookAt(eyeX, eyeY, eyeZ, -far1*angX, 0, -far1*angZ, 0,1,0);

    glRotatef(anguloEixo, 1.0f, 0.0f, 0.0f); //Ajuste do angulo do eixo de rotação (x)
    glRotatef(angulo*escalaRot, 0.0f, 1.0f, 0.0f);  //Rotação referente ao movimento de rotação do sol (y)
    glRotatef(-90, 1.0f, 0.0f, 0.0f); //Deixando o sol alinhado em y

    //desenhando
    GLUquadricObj * esfera= gluNewQuadric();

    //habilitando a textura
    glEnable(GL_TEXTURE_2D);

    //Selecionando a textura do
    glBindTexture(GL_TEXTURE_2D, texels[0]);

    //mapeando a textura na esfera
    gluQuadricTexture(esfera, true);

    //Renderizando
    gluSphere(esfera, raio, slices, stacks);
}
void desenhaMercurio()
{
    //Setando os valores da escala e tamanho
    float escalaTrans = 0.011494253f;
    float raioTranslacao = 0.387104440f;
    float escalaRot = 0.016949153f ;
    float anguloEixo = 0.1f;
    float raio= 0.000016308f*100;

    glLoadIdentity();

    gluLookAt(eyeX, eyeY, eyeZ, -far1*angX, 0, -far1*angZ, 0,1,0);


    //glTranslatef(0.0f, 0.0f, deslocamentoSol);
    glRotatef(angulo*escalaTrans, 0.0f, 1.0f, 0.0f); //Rotação referente ao movimento de translação
    glTranslatef(0.0f, 0.0f, -raioTranslacao); //Aplicando o raio de tranlação
    glRotatef(anguloEixo, 1.0f, 0.0f, 0.0f); //Ajuste do angulo do eixo de rotação (x)
    glRotatef(angulo*escalaRot, 0.0f, 1.0f, 0.0f);  //Rotação referente ao movimento de rotação do planeta (y)
    glRotatef(-90, 1.0f, 0.0f, 0.0f); //Deixando o planeta alinhado em y

    //desenhando o planeta
    GLUquadricObj * esfera= gluNewQuadric();

    //habilitando a textura
    glEnable(GL_TEXTURE_2D);

    //Selecionando a textura do Planeta
    glBindTexture(GL_TEXTURE_2D, texels[1]);

    //mapeando a textura na esfera
    gluQuadricTexture(esfera, true);

    //Renderizando
    gluSphere(esfera, raio, slices, stacks);
}

void desenhaVenus()
{
    //Setando os valores da escala e tamanho
    float escalaTrans = 0.004444444f;
    float raioTranslacao = 0.723272327f;
    float escalaRot = -0.004115226f ;  //Negativo pois o movimento é retrogrado
    float anguloEixo = 177.0f;
    float raio= 0.000040454*10;

    glLoadIdentity();

    gluLookAt(eyeX, eyeY, eyeZ, -far1*angX, 0, -far1*angZ, 0,1,0);


    //glTranslatef(0.0f, 0.0f, deslocamentoSol);
    glRotatef(angulo*escalaTrans, 0.0f, 1.0f, 0.0f); //Rotação referente ao movimento de translação
    glTranslatef(0.0f, 0.0f, -raioTranslacao); //Aplicando o raio de tranlação
    glRotatef(anguloEixo, 1.0f, 0.0f, 0.0f); //Ajuste do angulo do eixo de rotação (x)
    glRotatef(angulo*escalaRot, 0.0f, 1.0f, 0.0f);  //Rotação referente ao movimento de rotação do planeta (y)
    glRotatef(-90, 1.0f, 0.0f, 0.0f); //Deixando o planeta alinhado em y

    //desenhando o planeta
    GLUquadricObj * esfera= gluNewQuadric();

    //habilitando a textura
    glEnable(GL_TEXTURE_2D);

    //Selecionando a textura do Planeta
    glBindTexture(GL_TEXTURE_2D, texels[2]);

    //mapeando a textura na esfera
    gluQuadricTexture(esfera, true);

    //Renderizando
    gluSphere(esfera, raio, slices, stacks);
}

void desenhaTerra()
{
    //Setando os valores da escala e tamanho
    float escalaTransTerra = 0.002739726f;
    float raioTranslacaoTerra = 1.000014233f;
    float escalaRotTerra = 1.0f ;
    float anguloEixoTerra = 23.5f;
    float raioTerra= 0.000042634965f*10;

    glLoadIdentity();


    gluLookAt(eyeX, eyeY, eyeZ, -far1*angX, 0, -far1*angZ, 0,1,0);

    //glTranslatef(0.0f, 0.0f, deslocamentoSol);
    glRotatef(angulo*escalaTransTerra, 0.0f, 1.0f, 0.0f); //Rotação referente ao movimento de translação
    glTranslatef(0.0f, 0.0f, -raioTranslacaoTerra); //Aplicando o raio de tranlação
    glRotatef(anguloEixoTerra, 1.0f, 0.0f, 0.0f); //Ajuste do angulo do eixo de rotação (x)
    glRotatef(angulo*escalaRotTerra, 0.0f, 1.0f, 0.0f);  //Rotação referente ao movimento de rotação do planeta (y)
    glRotatef(-90, 1.0f, 0.0f, 0.0f); //Deixando o planeta alinhado em y

    //desenhando o planeta
    GLUquadricObj * esfera= gluNewQuadric();

    //habilitando a textura
    glEnable(GL_TEXTURE_2D);

    //Selecionando a textura do Planeta
    glBindTexture(GL_TEXTURE_2D, texels[3]);

    //mapeando a textura na esfera
    gluQuadricTexture(esfera, true);

    //Renderizando
    gluSphere(esfera, raioTerra, slices, stacks);
}

void desenhaMarte()
{
    //Setando os valores da escala e tamanho
    float escalaTrans = 0.001455604f;
    float raioTranslacao = 1.523684789f;
    float escalaRot = 0.974949221f;
    float anguloEixo = 25.0f;
    float raio= 0.000022709f;

    glLoadIdentity();

    gluLookAt(eyeX, eyeY, eyeZ, -far1*angX, 0, -far1*angZ, 0,1,0);

    //glTranslatef(0.0f, 0.0f, deslocamentoSol);
    glRotatef(angulo*escalaTrans, 0.0f, 1.0f, 0.0f); //Rotação referente ao movimento de translação
    glTranslatef(0.0f, 0.0f, -raioTranslacao); //Aplicando o raio de tranlação
    glRotatef(anguloEixo, 1.0f, 0.0f, 0.0f); //Ajuste do angulo do eixo de rotação (x)
    glRotatef(angulo*escalaRot, 0.0f, 1.0f, 0.0f);  //Rotação referente ao movimento de rotação do planeta (y)
    glRotatef(-90, 1.0f, 0.0f, 0.0f); //Deixando o planeta alinhado em y

    //desenhando o planeta
    GLUquadricObj * esfera= gluNewQuadric();

    //habilitando a textura
    glEnable(GL_TEXTURE_2D);

    //Selecionando a textura do Planeta
    glBindTexture(GL_TEXTURE_2D, texels[4]);

    //mapeando a textura na esfera
    gluQuadricTexture(esfera, true);

    //Renderizando
    gluSphere(esfera, raio, slices, stacks);
}

void desenhaJupiter()
{
    //Setando os valores da escala e tamanho
    float escalaTrans = 0.000228311f;
    float raioTranslacao = 5.202814695f/divisorRaioTranslacao;
    float escalaRot = 2.420168067f;
    float anguloEixo = 2.0f;
    float raio= 0.000477895f;

    glLoadIdentity();

    gluLookAt(eyeX, eyeY, eyeZ, -far1*angX, 0, -far1*angZ, 0,1,0);

    //glTranslatef(0.0f, 0.0f, deslocamentoSol);
    glRotatef(angulo*escalaTrans, 0.0f, 1.0f, 0.0f); //Rotação referente ao movimento de translação
    glTranslatef(0.0f, 0.0f, -raioTranslacao); //Aplicando o raio de tranlação
    glRotatef(anguloEixo, 1.0f, 0.0f, 0.0f); //Ajuste do angulo do eixo de rotação (x)
    glRotatef(angulo*escalaRot, 0.0f, 1.0f, 0.0f);  //Rotação referente ao movimento de rotação do planeta (y)
    glRotatef(-90, 1.0f, 0.0f, 0.0f); //Deixando o planeta alinhado em y

    //desenhando o planeta
    GLUquadricObj * esfera= gluNewQuadric();

    //habilitando a textura
    glEnable(GL_TEXTURE_2D);

    //Selecionando a textura do Planeta
    glBindTexture(GL_TEXTURE_2D, texels[5]);

    //mapeando a textura na esfera
    gluQuadricTexture(esfera, true);

    //Renderizando
    gluSphere(esfera, raio, slices, stacks);
}

void desenhaSaturno()
{
    //Setando os valores da escala e tamanho
    float escalaTrans= 0.000091324f;
    float raioTranslacao = 9.554948833f/divisorRaioTranslacao;
    float escalaRot = 2.345276873f;
    float anguloEixo = 27.0f;
    float raio= 0.000402867f;

    glLoadIdentity();

    gluLookAt(eyeX, eyeY, eyeZ, -far1*angX, 0, -far1*angZ, 0,1,0);

    glRotatef(angulo*escalaTrans, 0.0f, 1.0f, 0.0f); //Rotação referente ao movimento de translação
    glTranslatef(0.0f, 0.0f, -raioTranslacao); //Aplicando o raio de tranlação
    glRotatef(anguloEixo, 1.0f, 0.0f, 0.0f); //Ajuste do angulo do eixo de rotação (x)
    glRotatef(-angulo*escalaRot, 0.0f, 1.0f, 0.0f);  //Rotação referente ao movimento de rotação do planeta (y)
    glRotatef(-90, 1.0f, 0.0f, 0.0f); //Deixando o planeta alinhado em y

    //desenhando o planeta
    GLUquadricObj * esfera= gluNewQuadric();

    //habilitando a textura
    glEnable(GL_TEXTURE_2D);

    //Selecionando a textura do Planeta
    glBindTexture(GL_TEXTURE_2D, texels[6]);

    //mapeando a textura na esfera
    gluQuadricTexture(esfera, true);

    //Renderizando
    gluSphere(esfera, raio, slices, stacks);

    //Desabilitando a textura

    //---------------------------ANEL-------------------------------
    //Criando as transformações geométricas para acompanhar o mov. de translação
    glLoadIdentity();

    gluLookAt(eyeX, eyeY, eyeZ, -far1*angX, 0, -far1*angZ, 0,1,0);


    glRotatef(angulo*escalaTrans, 0.0f, 1.0f, 0.0f); //Rotação referente ao movimento de translação
    glTranslatef(0.0f, 0.0f, -raioTranslacao); //Aplicando o raio de tranlação
    glRotatef(anguloEixo, 1.0f, 0.0f, 0.0f); //Ajuste do angulo do eixo de rotação (x)
    glRotatef(angulo*escalaRot/10, 0.0f, 1.0f, 0.0f);  //Rotação referente ao movimento de rotação do planeta (y)
    glRotatef(-90, 1.0f, 0.0f, 0.0f); //Deixando o planeta alinhado em y

    //Criando o Objeto
    GLUquadricObj * anel= gluNewQuadric();
    //Habilitando a textura
    glEnable(GL_TEXTURE_2D);
    //Carregando a textura
    glBindTexture(GL_TEXTURE_2D, texels[9]);
    //Aplicando a Textura
    gluQuadricTexture(anel, true);
    //Desenhando o anel texturizado
    gluDisk(anel, raio*1.5f, raio*2.5f, 50, 100);
    //Desabilitando a textura
    glDisable(GL_TEXTURE_2D);
}

void desenhaUrano()
{
    //Setando os valores da escala e tamanho
    float escalaTrans= 0.000016604f;
    float raioTranslacao = 19.191382782f /divisorRaioTranslacao;
    float escalaRot = 1.411764706f;
    float anguloEixo = 98.0f;
    float raio= 0.000170851f;

    glLoadIdentity();

    gluLookAt(eyeX, eyeY, eyeZ, -far1*angX, 0, -far1*angZ, 0,1,0);


    glRotatef(angulo*escalaTrans, 0.0f, 1.0f, 0.0f); //Rotação referente ao movimento de translação
    glTranslatef(0.0f, 0.0f, -raioTranslacao); //Aplicando o raio de tranlação
    glRotatef(anguloEixo, 1.0f, 0.0f, 0.0f); //Ajuste do angulo do eixo de rotação (x)
    glRotatef(-angulo*escalaRot, 0.0f, 1.0f, 0.0f);  //Rotação referente ao movimento de rotação do planeta (y)
    glRotatef(-90, 1.0f, 0.0f, 0.0f); //Deixando o planeta alinhado em y

    //desenhando o planeta
    GLUquadricObj * esfera= gluNewQuadric();

    //habilitando a textura
    glEnable(GL_TEXTURE_2D);

    //Selecionando a textura do Planeta
    glBindTexture(GL_TEXTURE_2D, texels[7]);

    //mapeando a textura na esfera
    gluQuadricTexture(esfera, true);

    //Renderizando
    gluSphere(esfera, raio, slices, stacks);

    //Desabilitando a textura

    //---------------------------ANEL-------------------------------
    //Criando as transformações geométricas para acompanhar o mov. de translação
    glLoadIdentity();

    gluLookAt(eyeX, eyeY, eyeZ, -far1*angX, 0, -far1*angZ, 0,1,0);


    //glTranslatef(0.0f, 0.0f, -50);
    glRotatef(angulo*escalaTrans, 0.0f, 1.0f, 0.0f); //Rotação referente ao movimento de translação
    glTranslatef(0.0f, 0.0f, -raioTranslacao); //Aplicando o raio de tranlação
    glRotatef(anguloEixo, 1.0f, 0.0f, 0.0f); //Ajuste do angulo do eixo de rotação (x)
    glRotatef(angulo*escalaRot/10, 0.0f, 1.0f, 0.0f);  //Rotação referente ao movimento de rotação do planeta (y)
    glRotatef(-90, 1.0f, 0.0f, 0.0f); //Deixando o planeta alinhado em y

    //Criando o Objeto
    GLUquadricObj * anel= gluNewQuadric();
    //Habilitando a textura
    glEnable(GL_TEXTURE_2D);
    //Carregando a textura
    glBindTexture(GL_TEXTURE_2D, texels[10]);
    //Aplicando a Textura
    gluQuadricTexture(anel, true);
    //Desenhando o anel texturizado
    gluDisk(anel, raio*1.5f, raio*1.8f, 50, 100);
    //Desabilitando a textura
    glDisable(GL_TEXTURE_2D);

}

void desenhaNetuno()
{
    //Setando os valores da escala e tamanho
    float escalaTrans = 0.000016706f;
    float raioTranslacao = 30.109385775f /divisorRaioTranslacao;
    float escalaRot = 1.500000000f;
    float anguloEixo = 30.0f;
    float raio= 0.000165571f;

    glLoadIdentity();

    gluLookAt(eyeX, eyeY, eyeZ, -far1*angX, 0, -far1*angZ, 0,1,0);

    glRotatef(angulo*escalaTrans, 0.0f, 1.0f, 0.0f); //Rotação referente ao movimento de translação
    glTranslatef(0.0f, 0.0f, -raioTranslacao); //Aplicando o raio de tranlação
    glRotatef(anguloEixo, 1.0f, 0.0f, 0.0f); //Ajuste do angulo do eixo de rotação (x)
    glRotatef(angulo*escalaRot, 0.0f, 1.0f, 0.0f);  //Rotação referente ao movimento de rotação do planeta (y)
    glRotatef(-90, 1.0f, 0.0f, 0.0f); //Deixando o planeta alinhado em y

    //desenhando o planeta
    GLUquadricObj * esfera= gluNewQuadric();

    //habilitando a textura
    glEnable(GL_TEXTURE_2D);

    //Selecionando a textura do Planeta
    glBindTexture(GL_TEXTURE_2D, texels[8]);

    //mapeando a textura na esfera
    gluQuadricTexture(esfera, true);

    //Renderizando
    gluSphere(esfera, raio, slices, stacks);
}

void desenha()
{

    //Iluminação
    glLoadIdentity();
    float posLuz[] = {0.0f, 0.0f, 0.0f, 1.0f};
    float luzDif[] = {1.0f, 1.0f, 1.0f, 1.0f};
    float posSpot[] = {0.0f, 0.0f, 0.0f, 1.0f};
    glLightfv(GL_LIGHT0, GL_POSITION, posLuz);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDif);
    glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, posSpot);
    glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 180.0f);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0); //Fundo preto

    //Atualizando o angulo de rotação da camera
    angZ = cos(anguloCamera*M_PI/180);
    angX =sin(anguloCamera*M_PI/180);

    //Chamando o desenho dos planetas
    desenhaSol();
    desenhaMercurio();
    desenhaVenus();
    desenhaTerra();
    desenhaMarte();
    desenhaJupiter();
    desenhaSaturno();
    desenhaUrano();
    desenhaNetuno();

    glutSwapBuffers();

}

void timer(int t)
{
    angulo+= velocidade;
    glutPostRedisplay();
    glutTimerFunc(60, timer, 0);

}

//Função que utiliza das teclas especiais do teclado (setas)
void tecladoEspecial(int tecla, int x, int y)
{
    //Zoom Out
    if(tecla == GLUT_KEY_DOWN && fov < 180){
        //Escolhe o passo de zoom
        if (fov > 0.5)
            fov+=0.5;
        else if (fov <=0.5)
            fov+=0.05;
	}

    //Zoom In
	if(tecla == GLUT_KEY_UP && fov >0){
        if (fov > 0.5)
            fov-=0.5;
        else if (fov <=0.5) //passo menor de zoom para angulos pequenos
            fov-=0.05;
	}

	//Rotação para a esquerda
    if(tecla == GLUT_KEY_LEFT){
        anguloCamera++;
        //Ajustando valores entre 0 e 360
        if(anguloCamera >= 360){
            anguloCamera = anguloCamera -360;  //volta no sentido anti-horario
        }
        else if (anguloCamera <= -360){
            anguloCamera = anguloCamera +360;  //volta no sentido horário
        }
    }
    //Rotação para a Direita
	if(tecla == GLUT_KEY_RIGHT){
        anguloCamera--;
        //Ajustando valores entre 0 e 360
        if(anguloCamera >= 360){
            anguloCamera = anguloCamera -360;  //volta no sentido anti-horario
        }
        else if (anguloCamera <= -360){
            anguloCamera = anguloCamera +360;  //volta no sentido horário
        }
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, 600./600., near1, far1);
	glMatrixMode(GL_MODELVIEW);
}

void teclado(unsigned char tecla, int x, int y)
{
    //Verificação da translação da camera para o primeiro quadrante ( -45 < angulo < 45 )
    if ((anguloCamera >= -45 && anguloCamera < 45)|| (anguloCamera < -315)){  //Primeiro Quadrante
        if(tecla == 'a'){
            if (eyeX < 5)
                eyeX-=0.001f;
            else
                eyeX-=0.015;
        }
        if(tecla == 'd'){
            if (eyeX < 5)
                eyeX+=0.001f;
            else
                eyeX+=0.015;
        }
        if(tecla == 'w'){
            if (eyeZ < 2)
                eyeZ-=0.01f;
            else if (eyeZ <8)
                eyeZ--;
            else if (eyeZ >= 8)
                eyeZ-=3;
        }
        if(tecla == 's'){
            if (eyeZ < 2)
                eyeZ+=0.01f;
            else if (eyeZ < 8)
                eyeZ++;
            else if (eyeZ >= 8)
                eyeZ+=3;

        }
    }

    //Verificação da translação da camera para o Segundo quadrante ( 45 < angulo < 135 )
    else if ((anguloCamera >= 45 && anguloCamera < 135) || (anguloCamera < -225 && anguloCamera >= -315)){  //Segundo Quadrante
        if(tecla == 'a'){
            if (eyeZ < 5)
                eyeZ+=0.001f;
            else
                eyeZ+=0.015;
        }
        if(tecla == 'd'){
            if (eyeZ < 5)
                eyeZ-=0.001f;
            else
                eyeZ-=0.015;
        }
        if(tecla == 'w'){
            if (eyeX < 2)
                eyeX-=0.01f;
            else if (eyeX <8)
                eyeX--;
            else if (eyeX >= 8)
                eyeX-=3;
        }
        if(tecla == 's'){
            if (eyeX < 2)
                eyeX+=0.01f;
            else if (eyeX < 8)
                eyeX++;
            else if (eyeX >= 8)
                eyeX+=3;
        }
    }

    //Verificação da translação da camera para o Terceiro quadrante ( 135 < angulo < 225 )
    else if ((anguloCamera >= 135 && anguloCamera < 225) || (anguloCamera < -135 && anguloCamera >= -225)){  //Terceiro Quadrante
        if(tecla == 'a'){
            if (eyeX < 5)
                eyeX+=0.001f;
            else
                eyeX+=0.015;
        }
        if(tecla == 'd'){
            if (eyeX < 5)
                eyeX-=0.001f;
            else
                eyeX-=0.015;
        }
        if(tecla == 'w'){
            if (eyeZ < 2)
                eyeZ+=0.01f;
            else if (eyeX <8)
                eyeZ++;
            else if (eyeX >= 8)
                eyeX+=3;
        }
        if(tecla == 's'){
            if (eyeZ < 2)
                eyeZ-=0.01f;
            else if (eyeZ < 8)
                eyeX--;
            else if (eyeZ >= 8)
                eyeX-=3;
        }
    }

    //Verificação da translação da camera para o Quarto quadrante ( 225 < angulo < 315 )
    else if ((anguloCamera >= 225 && anguloCamera < 315) || (anguloCamera < -45 && anguloCamera >= -135)){  //Quarto Quadrante
        if(tecla == 'a'){
            if (eyeZ < 5)
                eyeZ-=0.001f;
            else
                eyeZ-=0.015;
        }
        if(tecla == 'd'){
            if (eyeZ < 5)
                eyeZ+=0.001f;
            else
                eyeZ+=0.015;
        }
        if(tecla == 'w'){
            if (eyeX < 2)
                eyeX+=0.01f;
            else if (eyeX <8)
                eyeX++;
            else if (eyeX >= 8)
                eyeX+=3;
        }
        if(tecla == 's'){
            if (eyeX < 2)
                eyeX-=0.01f;
            else if (eyeX < 8)
                eyeX--;
            else if (eyeX >= 8)
                eyeX-=3;
        }
    }

    if(tecla == '+' && velocidade < 5)
        velocidade+=0.5;

    if(tecla == '-' && velocidade > -3)  //neste caso, pode-se pausar a simulação quando v = 0
        velocidade -= 0.5;
	if(tecla == 'c')
		eyeY+=0.01f;
	if(tecla == 'x')
		eyeY-=0.01f;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fov, 600./600., near1, far1);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char * argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Sistema Solar");
    glutDisplayFunc(desenha);
    glutTimerFunc(0, timer, 0);

    //Carregando as texturas
    glGenTextures(11, texels);

    //Texturas dos astros
    LoadBitmap("Texturas/sunmap.bmp");
    LoadBitmap("Texturas/mercurymap.bmp");
    LoadBitmap("Texturas/venusmap.bmp");
    LoadBitmap("Texturas/earthmap.bmp");
    LoadBitmap("Texturas/marsmap.bmp");
    LoadBitmap("Texturas/jupitermap.bmp");
    LoadBitmap("Texturas/saturnmap.bmp");
    LoadBitmap("Texturas/uranusmap.bmp");
    LoadBitmap("Texturas/neptunemap.bmp");
    //Texturas dos Anéis
    LoadBitmap("Texturas/saturnringcolor.bmp");
    LoadBitmap("Texturas/uranusringcolour.bmp");

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);

    glutKeyboardFunc(teclado); // configurar uma função de callback do teclado.
    glutSpecialFunc(tecladoEspecial); //Função de callback para teclas especiais do teclado
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f, 600./600., 0.001f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glutMainLoop();
    return 0;

}
