#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/xmlmemory.h>
#include <iconv.h>

int main(int argc,char **argv)
{
    xmlDocPtr doc;
    xmlNodePtr curNode;
    xmlChar *szKey;
    char *szDocName;

    szDocName=argv[1];
    doc = xmlReadFile(szDocName,"GB2312",XML_PARSE_RECOVER);
    if(NULL == doc)
    {
        fprintf(stderr,"Document not parsed sucessfully!\n");
        exit(-1);
    }

    curNode = xmlDocGetRootElement(doc);   
    if(NULL == curNode)
    {
        fprintf(stderr,"Empty document!\n");   
        xmlFreeDoc(doc);
        exit(-1);
    }

    if(xmlStrcmp(curNode->name,BAD_CAST"config"))
    {
        fprintf(stderr,"Document of the wrong type,root node != config");
        xmlFreeDoc(doc);
    }

    curNode = curNode->xmlChildrenNode;
    xmlNodePtr propNodePtr = curNode;
   
    while(curNode != NULL)
    {
        if (!(xmlStrcmp(curNode->name,(const xmlChar *)"address")))
        {
            szKey = xmlNodeGetContent(curNode);
            printf("%s\n",szKey);
            xmlFree(szKey);
        }
        curNode = curNode->next;
    }
    xmlFreeDoc(doc);
    return 0;
}
