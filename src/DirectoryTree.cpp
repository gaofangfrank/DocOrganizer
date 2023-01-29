#include "DirectoryTree.h"

using namespace organizer;

// Document type================================================================
Document::Document(const QString &Url) : Url(Url), Local(false) {}

Document::Document(const QString &Url, const QString &FileName)
    : Url(Url), FileName(FileName), Local(true) {}

bool Document::isLocal() const { return Local; }

// Tree node definitions========================================================
DirTreeNode::DirTreeNode(const QString &Name) : Name(Name), Parent(nullptr) {}

DirTreeNode::~DirTreeNode() {
  for (auto *I : Items.values())
    delete I;
}

void DirTreeNode::addLinkDocument(const QString &Name, const QString &Url) {
  Items[Name] = new Document(Url);
}

void DirTreeNode::addLocalDocument(const QString &Name, const QString &Url,
                                   const QString &FileName) {
  Items[Name] = new Document(Url, FileName);
}

void DirTreeNode::addChild(DirTreeNode *Child) { Children.insert(Child); }

DirTreeNode *DirTreeNode::get(DirectoryTree &DT, const QString &Name) {
  auto *RetVal = new DirTreeNode(Name);
  DT.Nodes.insert(RetVal);
  return RetVal;
}

// Tree class definition =======================================================
DirectoryTree::DirectoryTree() : Root(nullptr) {}

DirectoryTree::DirectoryTree(const QString &FileName) {
  // TODO: construct tree from file
  (void)FileName;
}

DirectoryTree::~DirectoryTree() {
  for (auto *N : Nodes)
    delete N;
}

void DirectoryTree::toFile(const QString &FileName) {
  // TODO: serialize tree into file.
  (void)FileName;
}
