using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CamManager : MonoBehaviour {
    //public Camera[] cams;
    public GameObject[] cams;
    public GameObject cursor;
	// Use this for initialization
	void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
        if (Input.GetKeyDown(KeyCode.Alpha1))
        {
            cams[0].SetActive(true);
            cursor.SetActive(true);
            cams[1].SetActive(false);
        }
        if (Input.GetKeyDown(KeyCode.Alpha2))
        {
            cams[0].SetActive(false);
            cams[1].SetActive(true);
            cursor.SetActive(false);
        }
    }
}
