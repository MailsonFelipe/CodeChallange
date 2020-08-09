package com.example.teladeemail;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.view.Gravity;
import android.widget.Toast;
import androidx.annotation.Nullable;
import java.util.ArrayList;

public class ServicoExcluiMsgRepetidas extends Service {

    private int flag = 0;
    public Toast toast;
    public ArrayList<String> respostaMsgs = new ArrayList<>();

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {

        if(flag == 0) {
            toast = Toast.makeText(ServicoExcluiMsgRepetidas.this, "Serviço iniciado", Toast.LENGTH_LONG);
            toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
            toast.show();
            flag = 1;
        }

        respostaMsgs = intent.getStringArrayListExtra("MensagensEntrada");

        // Trecho que exclui mensagens repetidas
        for(int i = 0; i < respostaMsgs.size(); i++){

            for(int j=i+1; j < respostaMsgs.size(); j++){

                if(respostaMsgs.get(i).toLowerCase().equals(respostaMsgs.get(j).toLowerCase())){
                    respostaMsgs.remove(j);

                    toast = Toast.makeText(ServicoExcluiMsgRepetidas.this, "Mensagem "+respostaMsgs.get(j)+" excluída.", Toast.LENGTH_LONG);
                    toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
                    toast.show();
                }
            }
        }

        return START_STICKY;
    }

    @Override
    public void onDestroy() {
        Toast toast = Toast.makeText(ServicoExcluiMsgRepetidas.this, "Serviço interrompido", Toast.LENGTH_LONG);
        toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
        toast.show();
        super.onDestroy();
    }
}
