using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Esfigmomanometro : MonoBehaviour {

    public Behaviour halo;

    public GameObject Bracadeira;
    public GameObject Tela;


    public bool flag = false;
    void Start()
    {

        halo = (Behaviour)gameObject.GetComponent("Halo");

    }

    // Update is called once per frame
    void Update()
    {
        if(!flag)
        {
            Bracadeira.SetActive(false);
            Tela.SetActive(false);
        }
        if (flag)
        {
            Bracadeira.SetActive(true);
            Tela.SetActive(true);

        }
    }
    void OnMouseEnter()
    {
        halo.enabled = true;

    }
    void OnMouseExit()
    {
        halo.enabled = false;
    }
    void OnMouseDown()
    {
        flag = !flag;

    }
    private void OnMouseOver()
    {

    }
}
