using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BotaoScriptfechar : MonoBehaviour {

    public GameObject janela;
    public GameObject panel;

	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
		
	}

    void OnMouseDown()
    {
        janela.SetActive(false);
        Destroy(panel);
    }

}
