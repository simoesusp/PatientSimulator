using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Body : MonoBehaviour {

    bool Hidebody;

	// Use this for initialization
	void Start () {
        Hidebody = false;
	}
	
	// Update is called once per frame
	void Update () {
        if (Input.GetKeyDown("h") && !Hidebody)
        {

            Hidebody = true;
        }
        if (Input.GetKeyDown("h") && Hidebody)
        {
            Hidebody = false;
        }
    }
}
