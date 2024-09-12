#include <stdio.h>
#include "eleicao.h"
#include "eleitor.h"
#include "candidato.h"

tEleicao InicializaEleicao() {

    tEleicao eleicao;
    tCandidato candidato;
    int qtd_candidatos=0, p=0, g=0;

    eleicao.totalPresidentes = 0;
    eleicao.totalGovernadores = 0;
    eleicao.votosBrancosPresidente = 0;
    eleicao.votosNulosPresidente = 0;
    eleicao.votosBrancosGovernador = 0;
    eleicao.votosNulosGovernador = 0;
    eleicao.totalEleitores = 0;

    scanf ("%d", &qtd_candidatos);
    for (int cont=0; cont < qtd_candidatos; cont++) {
        candidato = LeCandidato();
        if (ObtemCargo(candidato) == 'P') {
            eleicao.totalPresidentes++;
            eleicao.presidentes[p] = candidato;
            p++;
        }
        else if (ObtemCargo(candidato) == 'G') {
            eleicao.totalGovernadores++;
            eleicao.governadores[g] = candidato;
            g++;
        }
    }

    return eleicao;
}

/**
 * @brief Realiza uma eleição.
 * Nessa função, é lido a quantidade de eleitores e os eleitores são lidos e armazenados.
 * @param eleicao Eleição a ser realizada.
 * @return Eleição com os resultados da votação.
 */
tEleicao RealizaEleicao(tEleicao eleicao) {

    tEleitor eleitor;
    int votoP=-1, votoG=-1;

    scanf ("%d", &eleicao.totalEleitores);
    for (int cont=0; cont < eleicao.totalEleitores; cont++) {
        eleicao.eleitores[cont] = LeEleitor();
        votoP = ObtemVotoPresidente(eleicao.eleitores[cont]);
        votoG = ObtemVotoGovernador(eleicao.eleitores[cont]);
        for (int i=0; i<eleicao.totalPresidentes; i++) {
            if (VerificaIdCandidato(eleicao.presidentes[i], votoP)) {
                eleicao.presidentes[i] = IncrementaVotoCandidato(eleicao.presidentes[i]);
                break;
            }
            if (i == eleicao.totalPresidentes-1) {
                if (votoP == 0) {
                    eleicao.votosBrancosPresidente++;
                }
                else {
                    eleicao.votosNulosPresidente++;
                }
            }
        }
        for (int i=0; i<eleicao.totalGovernadores; i++) {
            if (VerificaIdCandidato(eleicao.governadores[i], votoG)) {
                eleicao.governadores[i] = IncrementaVotoCandidato(eleicao.governadores[i]);
                break;
            }
            if (i == eleicao.totalGovernadores-1) {
                if (votoG == 0) {
                    eleicao.votosBrancosGovernador++;
                }
                else {
                    eleicao.votosNulosGovernador++;
                }
            }
        }
    }

    return eleicao;
}

/**
 * @brief Imprime o resultado da eleição na tela a partir da aparucao dos votos.
 * @param eleicao Eleição a ser impressa.
 */
void ImprimeResultadoEleicao(tEleicao eleicao) {

    int maiorP=0, maiorG=0, auxP=0, auxG=0, empateP=0, empateG=0;

    if (eleicao.totalEleitores > 10 || eleicao.totalGovernadores > 3 || eleicao.totalPresidentes > 3) {
        printf ("ELEICAO ANULADA\n");
        exit(1);
    }

    for (int i=0; i<eleicao.totalEleitores; i++) {
        for (int j=i+1; j<eleicao.totalEleitores; j++) {
            if (EhMesmoEleitor(eleicao.eleitores[i], eleicao.eleitores[j])) {
                printf ("ELEICAO ANULADA\n");
                exit(1);
            }
        }
    }

    for (int i=0; i<eleicao.totalPresidentes; i++) {
        if (eleicao.presidentes[i].votos > maiorP) {
            maiorP = eleicao.presidentes[i].votos;
            auxP = i;
        }
    }

    for (int i=0; i<eleicao.totalPresidentes; i++) {
        if (eleicao.presidentes[i].votos == maiorP) {
            if (EhMesmoCandidato(eleicao.presidentes[i], eleicao.presidentes[auxP]) == 0) {
                empateP = 1;
            }
        }
    }

    for (int i=0; i<eleicao.totalGovernadores; i++) {
        if (eleicao.governadores[i].votos > maiorG) {
            maiorG = eleicao.governadores[i].votos;
            auxG = i;
        }
    }

    for (int i=0; i<eleicao.totalGovernadores; i++) {
        if (eleicao.governadores[i].votos == maiorG) {
            if (EhMesmoCandidato(eleicao.governadores[i], eleicao.governadores[auxG]) == 0) {
                empateG = 1;
            }
        }
    }

    printf("- PRESIDENTE ELEITO: ");

    if (empateP) {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else if (maiorP < (eleicao.votosBrancosPresidente + eleicao.votosNulosPresidente)) {
        printf("SEM DECISAO\n");
    }
    else {
        float porcentagem = 0;
        porcentagem = CalculaPercentualVotos(eleicao.presidentes[auxP], eleicao.totalEleitores);
        ImprimeCandidato(eleicao.presidentes[auxP], porcentagem);
    }

    printf("- GOVERNADOR ELEITO: ");

    if (empateG) {
        printf("EMPATE. SERA NECESSARIO UMA NOVA VOTACAO\n");
    }
    else if (maiorG < (eleicao.votosBrancosGovernador + eleicao.votosNulosGovernador)) {
        printf("SEM DECISAO\n");
    }
    else {
        float porcentagem = 0;
        porcentagem = CalculaPercentualVotos(eleicao.governadores[auxG], eleicao.totalEleitores);
        ImprimeCandidato(eleicao.governadores[auxG], porcentagem);
    }

    int tnulo, tbranco;
    tnulo = eleicao.votosNulosGovernador + eleicao.votosNulosPresidente;
    tbranco = eleicao.votosBrancosGovernador + eleicao.votosBrancosPresidente;
    printf("- NULOS E BRANCOS: %d, %d", tnulo, tbranco);
}