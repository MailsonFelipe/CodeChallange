package com.example.searchonalist;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.EditText;
import android.widget.Toast;
import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    public EditText edit;
    public List frutas = new ArrayList();

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public int diferencaTamanho(String palavraA, String palavraB){
        return Math.abs((palavraA).length() - (palavraB).length());
    }

    //Metodo que verifica se uma palavra contem erro de digitacao (typo)
    public boolean verificaTypo(String palavraA, String palavraB){
        int diferencas = 0, indicePalavraA, indicePalavraB;

        if(diferencaTamanho(palavraA, palavraB) > 1){
            return false;
        }

        indicePalavraA = indicePalavraB = 0;

        while(palavraA.length() > indicePalavraA  && palavraB.length() > indicePalavraB) {
            if (palavraA.charAt(indicePalavraA) != palavraB.charAt(indicePalavraB)) {
                if (diferencas != 0) {
                    return false;
                }

                if (palavraA.length() > palavraB.length()) {
                    indicePalavraA++;

                } else if (palavraB.length() > palavraA.length()) {
                    indicePalavraB++;
                } else {
                    indicePalavraA++;
                    indicePalavraB++;
                }

                diferencas++;
            }else{
                indicePalavraA++;
                indicePalavraB++;
            }
        }

        return true;
    }

   // Metodo que checa permutacao parcial (misspelling)
    public boolean checaPermutacaoParcial(String palavraA, String palavraB){
        int letrasTrocadas = 0, i;

        if(palavraA.charAt(0) != palavraB.charAt(0) || palavraA.length() != palavraB.length())
        {
            return false;
        }

        for(i=1; i<palavraB.length(); i++)
        {
            if(palavraB.charAt(i) != palavraA.charAt(i))
            {
                letrasTrocadas++;
            }
        }

        if(palavraB.length() > 3)
        {
            if(letrasTrocadas < palavraB.length()*(2.0/3.0)) //se 2/3 dos caracteres mudaram de posicao
            {
                return true;
            }
        }else{
		if(letrasTrocadas) // Se a palavra for menor do que 3 e houver letras trocadas
		{
			return true;
		}else{
			return false;
		}
        }

        return false;
    }

    public boolean verificaSeTypo(List lista, String entrada){ // metodo que procura um match entre a string de entrada e uma fruta
        String auxFruta;
        for(int i=0; i<lista.size(); i++)
        {
            auxFruta = frutas.get(i).toString();
            if(verificaTypo(auxFruta, entrada)){
                return true;
            }
        }

        return false;
    }

    public void onDisplay(View v) {
            frutas.add("abacate");
            frutas.add("abacaxi");
            frutas.add("açaí");
            frutas.add("acerola");
            frutas.add("amora");
            frutas.add("banana");
            frutas.add("biribá");
            frutas.add("cacau");
            frutas.add("cajá");
            frutas.add("caqui");
            frutas.add("carambola");
            frutas.add("cereja");
            frutas.add("cidra");
            frutas.add("cupuaçu");
            frutas.add("figo");
            frutas.add("framboesa");
            frutas.add("goiaba");
            frutas.add("groselha");
            frutas.add("ingá");
            frutas.add("jabuticaba");
            frutas.add("jaca");
            frutas.add("jambo");
            frutas.add("jenipapo");
            frutas.add("kiwi");
            frutas.add("laranja");
            frutas.add("limão");
            frutas.add("maçã");
            frutas.add("mamão");
            frutas.add("manga");
            frutas.add("maracujá");
            frutas.add("melancia");
            frutas.add("melão");
            frutas.add("morango");
            frutas.add("pequi");
            frutas.add("pera");
            frutas.add("pêssego");
            frutas.add("pitanga");
            frutas.add("pupunha");
            frutas.add("romã");
            frutas.add("siriguela");
            frutas.add("tâmara");
            frutas.add("tamarindo");
            frutas.add("tangerina");
            frutas.add("tucumã");
            frutas.add("uva");

        EditText edit = (EditText) findViewById(R.id.idInputBusca);
        String entrada = edit.getText().toString().toLowerCase();
        String auxFruta;


        if(entrada.isEmpty()){ //se a string de entrada for vazia
            Toast toast = Toast.makeText(MainActivity.this, "Por favor, insira uma palavra", Toast.LENGTH_LONG);
            toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
            toast.show();

        }else{//se a string de entrada nao for vazia

            if(verificaSeTypo(frutas, entrada)){ // se entrar no "if", trata-se de typo
                for(int i=0; i<frutas.size(); i++){

                    auxFruta = frutas.get(i).toString();

                    if(verificaTypo(auxFruta, entrada)){
                        Toast toast = Toast.makeText(MainActivity.this, "Você escolheu '"+auxFruta+"'", Toast.LENGTH_SHORT);
                        toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
                        toast.show();
                    }
                }
            }else{ //se entrar no "else", trata-se de misspelling
                for(int i=0; i<frutas.size(); i++){

                    auxFruta = frutas.get(i).toString();

                    if(checaPermutacaoParcial(auxFruta, entrada)){
                        Toast toast = Toast.makeText(MainActivity.this, "Você escolheu '"+auxFruta+"'", Toast.LENGTH_SHORT);
                        toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
                        toast.show();
                    }else{
                        Toast toast = Toast.makeText(MainActivity.this, "Fruta não encontrada", Toast.LENGTH_SHORT);
                        toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
                        toast.show();
                    }
                }
            }
        }
    }
}

