package com.example.peralessandroidserver;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.speech.RecognitionListener;
import android.speech.RecognizerIntent;
import android.speech.SpeechRecognizer;

import java.util.ArrayList;
import android.util.Log;

import org.java_websocket.WebSocket;
import org.java_websocket.handshake.ClientHandshake;
import org.java_websocket.server.WebSocketServer;

import java.net.InetSocketAddress;


public class MainActivity extends AppCompatActivity {

    WebSocket client;
    public  SpeechRecognizer speechRecognizer;
    public Intent speechRecognizerIntent;
    public  WebSocketServer websSocketServer;
    String TAG = "MainActivity";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        speechRecognizer = SpeechRecognizer.createSpeechRecognizer(this);
        speechRecognizerIntent = new Intent(RecognizerIntent.ACTION_RECOGNIZE_SPEECH);
        websSocketServer = new WebSocketServer(new InetSocketAddress(3000)) {

            @Override
            public void onOpen(WebSocket conn, ClientHandshake handshake) {
                client = conn;
                Log.e(TAG, "Connection open");
            }

            @Override
            public void onClose(WebSocket conn, int code, String reason, boolean remote) {
                Log.i(TAG, conn + "Client disconnected");
            }
            @Override
            public void onMessage(WebSocket conn, String message) {

                Log.i(TAG, "message recieved: " + ": " + message);

                if(message.equals("a")) {
                    Log.d(TAG,  "Start Recognizing");
                    findViewById(R.id.txt).post(new Runnable() {
                        @Override
                        public void run() {
                            speechRecognizer.startListening(speechRecognizerIntent);
                        }
                    });

                }
                else if(message.equals("b")) {
                    findViewById(R.id.txt).post(new Runnable() {
                        @Override
                        public void run() {
                            speechRecognizer.stopListening();
                        }
                    });
                }
            }

            @Override
            public void onError(WebSocket conn, Exception ex) {
                Log.e(TAG, ex.toString());
            }
            @Override
            public void onStart()
            {
                Log.d(TAG, "Server started!");
                setConnectionLostTimeout(0);
            }
        };
        speechRecognizer.setRecognitionListener(new RecognitionListener() {
            @Override
            public void onReadyForSpeech(Bundle bundle) {

            }

            @Override
            public void onBeginningOfSpeech() {

            }

            @Override
            public void onRmsChanged(float v) {

            }

            @Override
            public void onBufferReceived(byte[] bytes) {

            }

            @Override
            public void onEndOfSpeech() {

            }

            @Override
            public void onError(int i) {

            }

            @Override
            public void onResults(Bundle bundle) {
                ArrayList<String> data = bundle.getStringArrayList(speechRecognizer.RESULTS_RECOGNITION);
                Log.d(TAG, data.get(0));
                client.send(data.get(0));
            }

            @Override
            public void onPartialResults(Bundle bundle) {

            }

            @Override
            public void onEvent(int i, Bundle bundle) {

            }
        });
        websSocketServer.start();
    }
}