using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class BotaoHudEstetoscopio : MonoBehaviour {

    public bool flag = false;
    public Button botao;

    public GameObject estetoscopio;

    // Use this for initialization
    void Start () {
        
    }
	
	// Update is called once per frame
	void Update () {
        botao.GetComponent<Button>().onClick.AddListener(() => onButtonClick());
    }
    public void onButtonClick() {
        flag = !flag;
        estetoscopio.GetComponent<Estetoscopio>().flag = flag;

    }
}
