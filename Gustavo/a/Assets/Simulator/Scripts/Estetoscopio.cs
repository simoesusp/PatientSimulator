using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Estetoscopio : MonoBehaviour {


    public Behaviour halo;
    public bool flag ;
    public int aux = 0;
    void Start()
    {

        halo = (Behaviour)gameObject.GetComponent("Halo");

    }

    // Update is called once per frame
    void Update()
    {

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
        aux = 2;
            flag = !flag;
        aux = 1;
        
    }
    private void OnMouseOver()
    {
        //if(input.getmousebuttondown(0)){
        //    flag = 1;
        //    if (flag == 1)
        //    {
        //        flag = 0;
        //    }
        //}
        
    }

}
