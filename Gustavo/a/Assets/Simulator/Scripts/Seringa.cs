using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Seringa : MonoBehaviour
{
    public GameObject PainelRemedio;
    public Behaviour halo;
    public GameObject botaoclose;
    public GameObject cursor;
    public GameObject fps;

    public bool flag = false;
    // Use this for initialization
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
        
        if (flag)
        {
            fps.GetComponent<UnityStandardAssets.Characters.FirstPerson.FirstPersonController>().enabled = true;
            Cursor.lockState = CursorLockMode.Locked;
            Cursor.visible = (false);
            cursor.SetActive(true);

            PainelRemedio.SetActive(false);
            flag = false;


        }
        else
        {
            fps.GetComponent<UnityStandardAssets.Characters.FirstPerson.FirstPersonController>().enabled = false;
            Cursor.lockState = CursorLockMode.None;
            Cursor.visible = (true);
            cursor.SetActive(false);

            PainelRemedio.SetActive(true);
            flag = true;

            
        }
        
    }
}
