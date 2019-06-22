using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class BotaoHudSeringa : MonoBehaviour {

    public bool flag = false;
    public Button botao;

    public GameObject PainelRemedio;

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
        //seringa.GetComponent<Seringa>().flag = flag;
        if (!flag)
        {
            PainelRemedio.SetActive(false);
        }
        else
        {
            PainelRemedio.SetActive(true);
        }
    }
}
