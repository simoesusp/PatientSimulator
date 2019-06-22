using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class PainelRemédios : MonoBehaviour {

    CSVReader reader;
   
    public GameObject botaoprefab;
    public Transform botaocontainer;
    public GameObject RemedioEspec;
    public Transform canvas;
    public GameObject panel;
    public GameObject Pacienteparametros;

    //public int flag = 0;
    

    IEnumerator Start()
    {
        //List<Remedio> lista = GetComponent<CSVReader>().remedios;
        reader = GetComponent<CSVReader>();
        yield return new WaitForEndOfFrame();

        foreach (Remedio r in reader.remedios)
        {



    GameObject go = Instantiate(botaoprefab) as GameObject;
            go.transform.SetParent(botaocontainer.transform,false);


            //print(r.nome);
            GameObject botao1 = go.transform.GetChild(0).gameObject;
            GameObject botao2 = go.transform.GetChild(1).gameObject;

            botao1.GetComponentInChildren<Text>().text = r.nome;
            botao2.GetComponentInChildren<Text>().text = r.nome;
            //print(filho1);
            //print(filho2);

            botao1.GetComponent<Button>().onClick.AddListener(() => onButtonClick(r));
            botao2.GetComponent<Button>().onClick.AddListener(() => onButtonClickDestroy());
         }
    }



    public void onButtonClick(Remedio r)
    {
        Destroy(panel);
        Pacienteparametros.SetActive(true);
        Pacienteparametros.GetComponent<CanvasGroup>().alpha = 0f; //this makes everything transparent
        Pacienteparametros.GetComponent<CanvasGroup>().blocksRaycasts = false; //this prevents the UI element to receive input events
        //Pacienteparametros.GetComponent<Renderer>().enabled = false;

        panel = Instantiate(RemedioEspec) as GameObject;
        panel.transform.SetParent(canvas.transform, false);
        panel.SetActive(true);
        panel.GetComponent<RemedioSpecs>().remedio = r;
        //Pacienteparametros.SetActive(false);



    }
    public void onButtonClickDestroy()
    {
        Destroy(panel);
    }
    // Use this for initialization

    // Update is called once per frame
    void Update () {
		
	}
}
