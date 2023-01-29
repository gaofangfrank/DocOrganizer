#pragma once
#include <QMap>
#include <QSet>
#include <Qstring>

namespace organizer {

class Document {
public:
  Document(const QString &Url);
  Document(const QString &Url, const QString &FileName);
  bool isLocal() const;
  bool makeLocal(const QString &FileName);

private:
  QString Url;
  QString FileName;
  bool Local;
};

class DirectoryTree;

// The dir tree node represents a directory/folder, and may contain other nodes
// and/or individual documents.
class DirTreeNode {
  friend DirectoryTree;

public:
  // Allocates a node and returns the pointer to it. This is so that the memory
  // can be managed by the tree structure itself, instead of having to manually
  // delete nodes, risking memory leaks.
  static DirTreeNode *get(DirectoryTree &DT, const QString &Name);
  DirTreeNode() = delete;
  ~DirTreeNode();
  void addChild(DirTreeNode *Child);
  void addLinkDocument(const QString &Name, const QString &Url);
  void addLocalDocument(const QString &Name, const QString &Url,
                        const QString &FileName);

private:
  DirTreeNode(const QString &Name);

  QString Name;
  DirTreeNode *Parent;
  QMap<QString, Document *> Items;
  QSet<DirTreeNode *> Children;
};

class DirectoryTree {
  friend DirTreeNode;

public:
  DirectoryTree();
  DirectoryTree(const QString &FileName);
  ~DirectoryTree();
  void toFile(const QString &FileName);

private:
  DirTreeNode *Root;
  QSet<DirTreeNode *> Nodes;
};

} // namespace organizer
