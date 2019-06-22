using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Alphalevel : MonoBehaviour {

    public KeyCode increaseAlpha;
    public KeyCode decreaseAlpha;
    public float alphalevel = .5f;

    // Use this for initialization
    void Start () {
       
	}
	
	// Update is called once per frame
	void Update () {

        if (Input.GetKeyDown(increaseAlpha))
            alphalevel += .5f;
        if (Input.GetKeyDown(decreaseAlpha))
            alphalevel -= .5f;

        GetComponent<SpriteRenderer>().color = new Color(1, 1, 1, alphalevel);
    }
}
