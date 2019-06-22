using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BotaoScript : MonoBehaviour {

    public GameObject janela;

    public int flag = 0;
    // Use this for initialization
    void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {

        
    }
    void OnMouseEnter()
    {


    }
    void OnMouseExit()
    {

    }
    void OnMouseDown()
    {
        janela.SetActive(true);

    }
}
