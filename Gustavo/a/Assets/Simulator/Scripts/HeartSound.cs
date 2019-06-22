using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HeartSound : MonoBehaviour {


    public Behaviour sound;

    public Behaviour halo;

    public GameObject estetoscopio;
    public GameObject botao;
    public bool flag2;
    // Use this for initialization
    void Start()
    {
        sound = (Behaviour)gameObject.GetComponent("AudioSource");
        halo = (Behaviour)gameObject.GetComponent("Halo");

    }

    // Update is called once per frame
    void Update()
    {
        flag2 = estetoscopio.GetComponent<Estetoscopio>().flag;
    }
    void OnMouseDown()
    {
        if (flag2)
        {
            halo.enabled = true;
            sound.enabled = true;
        }
    }
    void OnMouseUp()
    {
        halo.enabled = false;
        sound.enabled = false;

    }
}
