using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;


public class Botaoprefab : MonoBehaviour {

    public Button BotaoAbrir;
    public Button BotaoFechar;
    public Text Nome;
    public Text Nome1;

    public Image iconImage;

    private void Start()
    {



    }

    ////public Text priceText;


    ////private Item item;
    ////private ShopScrollList scrollList;


    //// Use this for initialization
    //void Start()
    //{
    ////    buttonComponent.onClick.AddListener(HandleClick);
    //}

    //public void Setup(Item currentItem, ShopScrollList currentScrollList)
    //{
    //    item = currentItem;
    //    nameLabel.text = item.itemName;
    //    iconImage.sprite = item.icon;
    //    priceText.text = item.price.ToString();
    //    scrollList = currentScrollList;

    //}

    //public void HandleClick()
    //{
    //    scrollList.TryTransferItemToOtherShop(item);
    //}
}
