using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class BotaoHudEsfigmo : MonoBehaviour {

    public bool flag = false;
    public Button botao;

    public GameObject esfigmomanometro;

    // Use this for initialization
    void Start()
    {
        botao.GetComponent<Button>().onClick.AddListener(() => onButtonClick());
    }

    // Update is called once per frame
    void Update()
    {
        
    }
    public void onButtonClick()
    {
        flag = !flag;
        esfigmomanometro.GetComponent<Esfigmomanometro>().flag = flag;

    }
}
