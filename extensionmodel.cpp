﻿#include <QFileInfo>

#include "extensionmodel.h"


ExtensionModel::ExtensionModel(QObject * /*parent*/)
	: QAbstractTableModel()
{
}

ExtensionModel::~ExtensionModel()
{
}

int ExtensionModel::rowCount(const QModelIndex & /*parent*/) const
{
	return m_values.count();
}

int ExtensionModel::columnCount(const QModelIndex & /*parent*/) const
{
	return 2;
}

QVariant ExtensionModel::data(const QModelIndex & index, int role) const
{
	if (!index.isValid())
		return QVariant();
	
	if (role == Qt::DisplayRole)
	{
		QFileInfo fi(m_values.at(index.row()));
		return QVariant(index.column() == 0 ? fi.fileName() : fi.filePath());
	}
	return QVariant();
}

Qt::ItemFlags ExtensionModel::flags(const QModelIndex & /*index*/) const
{
	return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant ExtensionModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
         return QVariant();

	if (orientation == Qt::Horizontal)
		return section == 0 ? tr("Extension") : tr("Path");
	else
		return QString("%1").arg(section + 1);
}

void ExtensionModel::setExtensions(const QStringList & l)
{
	m_values = l;
	reset();
}
